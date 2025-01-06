const std = @import("std");

pub fn isFileRWExist( fn_dir:std.fs.Dir, fn_file_name:[] u8) bool {
    fn_dir.access(fn_file_name, .{.mode = .read_write}) catch |err| switch (err) {
        error.FileNotFound => return false,
        error.PermissionDenied => return false,
        else => {
            std.debug.print("Unexpected error: {}\n", .{err});
            return false;
        }
    };

    return true;
}

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();    
    var file_path: [256]u8 = undefined; // Replace with your file path

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

}
