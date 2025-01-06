const std = @import("std");

const Link = struct {
    node: *Node,
    time: c_ulong,
};

const Node = struct {
    id: c_ulong,
    links: []Link,
};

const NodeList = struct {
    root_node: *Node,
};

pub fn isFileRWExist(fn_dir: std.fs.Dir, fn_file_name: []u8) bool {
    fn_dir.access(fn_file_name, .{ .mode = .read_write }) catch |err| switch (err) {
        error.FileNotFound => return false,
        error.PermissionDenied => return false,
        else => {
            std.debug.print("Unexpected error: {}\n", .{err});
            return false;
        },
    };

    return true;
}

pub fn readFile(file_path: []const u8) !void {
    // pub fn readFile(file_path: []const u8) !*NodeList {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const file = try std.fs.cwd().openFile(file_path, .{});
    defer file.close();

    var line_buffer = std.io.bufferedReader(file.reader());
    const reader = line_buffer.reader();

    var line = std.ArrayList(u8).init(allocator);
    defer line.deinit();

    const writer = line.writer();
    var line_nb: usize = 0;
    while (reader.streamUntilDelimiter(writer, '\n', null)) {
        // Clear the line so we can reuse it.
        defer line.clearRetainingCapacity();
        line_nb += 1;

        std.debug.print("{d}--{s}\n", .{ line_nb, line.items });
    } else |err| switch (err) {
        error.EndOfStream => { // end of file
            if (line.items.len > 0) {
                line_nb += 1;
                std.debug.print("{d}--{s}\n", .{ line_nb, line.items });
            }
        },
        else => return err, // Propagate error
    }

    std.debug.print("Total lines: {d}\n", .{line_nb});
}
pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    var file_path: [256]u8 = undefined; // Replace with your file path
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const alloc = arena.allocator();

    std.log.info("You are in: {s}\n", .{
        try std.fs.cwd().realpathAlloc(alloc, "."),
    });
    // Ask file path
    std.debug.print("Enter the file path: ", .{});

    if (try stdin.readUntilDelimiterOrEof(file_path[0..], '\n')) |user_input| {
        std.debug.print("You entered: {s}\n", .{user_input});
    } else {
        return;
    }

    // Check that file path is not empty
    if (file_path.len == 0) {
        std.debug.print("File path cannot be empty.\n", .{});
        return;
    }

    if(!isFileRWExist(std.fs.cwd(), &file_path)) {
        std.debug.print("File does not exist or cannot be accessed.\n", .{});
        return;
    }

    try readFile(&file_path);
}
