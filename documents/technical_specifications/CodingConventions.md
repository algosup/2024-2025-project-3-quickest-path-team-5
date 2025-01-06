# Coding Conventions

<details>
    <summary>Table of contents</summary>

- [Coding Conventions](#coding-conventions)
  - [Zig](#zig)
    - [Whitespace](#whitespace)
    - [Names](#names)
    - [Avoid Redundant Names in Fully-Qualified Namespaces](#avoid-redundant-names-in-fully-qualified-namespaces)
    - [Comments](#comments)
  - [C++](#c)
    - [Naming Conventions](#naming-conventions)
      - [1. Variables](#1-variables)
      - [2. Constants](#2-constants)
      - [3. Classes](#3-classes)
      - [4. Functions](#4-functions)
    - [Code Formatting](#code-formatting)
      - [1. Indentation](#1-indentation)
      - [2. Line Length](#2-line-length)
      - [3. Braces](#3-braces)
    - [Comments](#comments-1)
      - [1. Descriptive Comments](#1-descriptive-comments)
      - [2. Inline Comments](#2-inline-comments)
    - [Error Handling](#error-handling)
      - [1. Use Exceptions](#1-use-exceptions)
      - [2. Avoid Catch-All Blocks](#2-avoid-catch-all-blocks)
    - [Code Structure](#code-structure)
      - [1. Single Responsibility Principle](#1-single-responsibility-principle)
      - [2. Avoid Magic Numbers](#2-avoid-magic-numbers)
    - [Memory Management](#memory-management)
      - [1. Use Smart Pointers](#1-use-smart-pointers)
      - [2. Avoid Memory Leaks](#2-avoid-memory-leaks)
    - [Use of Standard Library](#use-of-standard-library)
      - [1. Prefer STL Containers](#1-prefer-stl-containers)
      - [2. Avoid Reimplementing Algorithms](#2-avoid-reimplementing-algorithms)
    - [Object-Oriented Design](#object-oriented-design)
      - [1. Use Access Modifiers](#1-use-access-modifiers)


</details>

## Zig

Avoid these words in type names:

- Value
- Data
- Context
- Manager
- utils, misc, or somebody's initials

> [!NOTE]  
> *Temptation to use "utilities", "miscellaneous", or somebody's initials is a failure to categorize, or more commonly, overcategorization.*

### Whitespace

- 4 space indentation
- Open braces on same line, unless you need to wrap.
- If a list of things is longer than 2, put each item on its own line and exercise the ability to put an extra comma at the end.
- Line length: aim for 100; use common sense.

>[!TIP]
>Good
>```zig
>const std = @import("std");
>
>fn myFunction(){
>     std.debug.print("Hello World");
> }
>```

>[!CAUTION]
>Bad
>```zig
>const std = @import("std");
>
> fn myFunction
> (
>   )
>    {
>     std.debug.print
>   ("Hello World"
>);
> }
>```

### Names

Roughly speaking: `camelCaseFunctionName`, `PascalCaseTypeName`, `snake_case_variable_name`.

>[!TIP]
>Good
>```zig
>const std = @import("std");
>
>var variable_name = "Hello ";
>
>const StructName = struct {
>    field1: i32,
>    field2: 20,
>    field3: "World!"
>};
>const StructAlias = StructName;
>
>fn functionName(param_name: TypeName) void {
>    std.debug.print("Hello World!");
>}
>const functionAlias = functionName;
>```

>[!CAUTION]
>Bad
>```zig
>const std = @import("std");
>
>var variableName = "Hello ";
>
>const StructName = struct {
>    field1: i32,
>    field2: 20,
>    field3: "World!"
>};
>const struct_alias = StructName;
>
>fn FunctionName(param_name: Typename) void {
>    std.debug.print("Hello World!");
>}
>const functionAlias = FunctionName;
>```

### Avoid Redundant Names in Fully-Qualified Namespaces

Every declaration is assigned a **fully qualified namespace** by the compiler, creating a tree structure. Choose names based on the fully-qualified namespace, and avoid redundant name segments.

>[!TIP]
>Good
>```zig
> const std = @import("std");
>
>pub const json = struct {
>    pub const Value = union(enum) {
>        number: f64,
>        boolean: bool,
>    };
>};
>
>pub fn main() void {
>    std.debug.print("{s}\n", .{@typeName(json.Value)});
>}
>```

>[!CAUTION]
>Bad
>```zig
> const std = @import("std");
>
>pub const json = struct {
>    pub const JsonValue = union(enum) {
>        number: f64,
>        boolean: bool,
>    };
>};
>
>pub fn main() void {
>    std.debug.print("{s}\n", .{@typeName(json.JsonValue)});
>}
>```


### Comments

| Type              | Syntax | Purpose                                                               | Scope                              | Included in Docs |
| ----------------- | ------ | --------------------------------------------------------------------- | ---------------------------------- | ---------------- |
| Normal Comment    | `//`   | For regular, internal comments not meant for documentation.           | Local (line or inline).            | ❌                |
| Doc Comment       | `///`  | Documents a specific item (function, struct, variable, etc.).         | The item it precedes.              | ✅                |
| Scope Doc Comment | `//!`  | Documents the entire file, module, or enclosing scope (e.g., struct). | The file or the surrounding scope. | ✅                |

>[!TIP]
>Good
>```zig
>//! This module provides math utilities for basic arithmetic operations.
>//! It is designed to demonstrate the use of comments in Zig.
>
>const std = @import("std");
>
>/// This function adds two integers.
>/// It takes two `i32` values as input and returns their sum.
>/// Example:
>/// ```zig
>/// const result = add(3, 5); // result == 8
>/// ```
>pub fn add(a: i32, b: i32) i32 {
>    return a + b; // Inline comment explaining the return statement.
>}
>
>/// This function multiplies two integers.
>/// Example:
>/// ```zig
>/// const result = multiply(3, 5); // result == 15
>/// ```
>pub fn multiply(a: i32, b: i32) i32 {
>    // This multiplication doesn't handle overflow.
>    return a * b;
>}
>
>// This constant defines the maximum value for an example operation.
>// It's not directly relevant to public API documentation.
>const MAX_VALUE = 100;
>
>pub fn main() void {
>    // Print the result of addition and multiplication.
>    std.debug.print("3 + 5 = {}\n", .{add(3, 5)});
>    std.debug.print("3 * 5 = {}\n", .{multiply(3, 5)});
>}
>```

>[!CAUTION]
>Bad
>```zig
>// This module provides math utilities for basic arithmetic operations.
>// It is designed to demonstrate the use of comments in Zig.
>
>const std = @import("std");
>
>//! This function adds two integers.
>//! It takes two `i32` values as input and returns their sum.
>//! Example:
>//! ```zig
>//! const result = add(3, 5); // result == 8
>//! ```
>pub fn add(a: i32, b: i32) i32 {
>    return a + b; // Inline comment explaining the return statement.
>}
>
>// This function multiplies two integers.
>// Example:
>// ```zig
>// const result = multiply(3, 5); // result == 15
>// ```
>pub fn multiply(a: i32, b: i32) i32 {
>    //! This multiplication doesn't handle overflow.
>    return a * b;
>}
>
>// This constant defines the maximum value for an example operation.
>// It's not directly relevant to public API documentation.
>const MAX_VALUE = 100;
>
>pub fn main() void {
>    // Print the result of addition and multiplication.
>    std.debug.print("3 + 5 = {}\n", .{add(3, 5)});
>    std.debug.print("3 * 5 = {}\n", .{multiply(3, 5)});
>}
>```


## C++

### Naming Conventions
#### 1. Variables
- Good Practice: Use camelCase for variables and descriptive names.
- Bad Practice: Use single letters or unclear abbreviations.

>[!TIP]
>Good
>```cpp
>int employeeCount = 10;
>float accountBalance = 1000.5;
>```

>[!CAUTION]
>Bad
>```cpp
>int x = 10;
>float ab = 1000.5;
>```

#### 2. Constants
- Good Practice: Use UPPER_SNAKE_CASE for constants.
- Bad Practice: Use lowercase or misleading names.

>[!TIP]
>Good
>```cpp
>const int MAX_USERS = 100;
>```

>[!CAUTION]
>Bad
>```cpp
>const int maxusers = 100;
>```
#### 3. Classes
- Good Practice: Use PascalCase for class names.
- Bad Practice: Use lowercase or non-descriptive names.

>[!TIP]
>Good
>```cpp
>class EmployeeDatabase {
>    // ...
>};
>```

>[!CAUTION]
>Bad
>```cpp
>class employeedatabase {
>    // ...
>};
>```
#### 4. Functions
- Good Practice: Use camelCase and start with a verb.
- Bad Practice: Use non-descriptive or vague names.

>[!TIP]
>Good
>```cpp
>void calculateSalary() {
>    // ...
>}
>```

>[!CAUTION]
>Bad
>```cpp
>void calc() {
>    // ...
>}
>```


### Code Formatting
#### 1. Indentation
- Good Practice: Use consistent indentation (2 or 4 spaces).
- Bad Practice: Use inconsistent or mixed tabs and spaces.

>[!TIP]
>Good
>```cpp
>void printMessage() {
>    std::cout << "Hello, World!" << std::endl;
>}
>```

>[!CAUTION]
>Bad
>```cpp
>void printMessage() {
> std::cout << "Hello, World!" << std::endl;
>}
>```

#### 2. Line Length
- Good Practice: Limit lines to 80-100 characters.
- Bad Practice: Write overly long lines.

>[!TIP]
>Good
>```cpp
>std::cout << "This is a short and readable line." << std::endl;
>```

>[!CAUTION]
>Bad
>```cpp
>std::cout << "This line is excessively long and will make the code hard to read in smaller editors or screens." << std::endl;
>```

#### 3. Braces
- Good Practice: Place braces on new lines (Allman style) or same line (K&R style), consistently.
- Bad Practice: Mix brace styles.

>[!TIP]
>Good
>```cpp
>if (x > 0) {
>    std::cout << "Positive" << std::endl;
>}
>```

>[!CAUTION]
>Bad
>```cpp
>if (x > 0)
>{
>    std::cout << "Positive" << std::endl; }
>```
### Comments
#### 1. Descriptive Comments
- Good Practice: Use comments to explain why, not what.
- Bad Practice: Write obvious or outdated comments.

>[!TIP]
>Good
>```cpp
>// This function calculates the employee's salary based on hourly rate and hours worked.
>double calculateSalary(double hourlyRate, int hoursWorked) {
>    return hourlyRate * hoursWorked;
>}
>```

>[!CAUTION]
>Bad
>```cpp
>// This function calculates salary
>double calculateSalary(double hourlyRate, int hoursWorked) {
>    return hourlyRate * hoursWorked;
>}
>```
#### 2. Inline Comments
- Good Practice: Use inline comments sparingly.
- Bad Practice: Overuse inline comments or write non-descriptive ones.

>[!TIP]
>Good
>```cpp
>x = y + z; // Combine y and z
>```

>[!CAUTION]
>Bad
>```cpp
>x = y + z; // Add numbers
>```
### Error Handling
#### 1. Use Exceptions
- Good Practice: Use exceptions for error handling.
- Bad Practice: Use return codes or ignore errors.

>[!TIP]
>Good
>```cpp
>try {
>    openFile("data.txt");
>} catch (const std::exception& e) {
>    std::cerr << "Error: " << e.what() << std::endl;
>}
>```

>[!CAUTION]
>Bad
>```cpp
>if (!openFile("data.txt")) {
>    std::cerr << "Error opening file" << std::endl;
>}
>```
#### 2. Avoid Catch-All Blocks
- Good Practice: Catch specific exceptions.
- Bad Practice: Use general catch blocks excessively.

>[!TIP]
>Good
>```cpp
>catch (const std::ios_base::failure& e) {
>    std::cerr << "IO Error: " << e.what() << std::endl;
>}
>```

>[!CAUTION]
>Bad
>```cpp
>catch (...) {
>    std::cerr << "Unknown Error" << std::endl;
>}
>```
### Code Structure
#### 1. Single Responsibility Principle
- Good Practice: Each function/class should have one responsibility.
- Bad Practice: Overload functions/classes with multiple tasks.

>[!TIP]
>Good
>```cpp
>class Employee {
>    void updateSalary();
>    void updateTitle();
>};
>```

>[!CAUTION]
>Bad
>```cpp
>class Employee {
>    void updateSalaryAndTitle();
>};
>```
#### 2. Avoid Magic Numbers
- Good Practice: Use named constants instead of literals.
- Bad Practice: Use hard-coded numbers.

>[!TIP]
>Good
>```cpp
>const int MAX_USERS = 100;
>if (userCount > MAX_USERS) {
>    // ...
>}
>```

>[!CAUTION]
>Bad
>```cpp
>if (userCount > 100) {
>    // ...
>}
>```
### Memory Management
#### 1. Use Smart Pointers
- Good Practice: Use std::unique_ptr or std::shared_ptr.
- Bad Practice: Use raw pointers unnecessarily.

>[!TIP]
>Good
>```cpp
>std::unique_ptr<int> ptr = std::make_unique<int>(10);
>```

>[!CAUTION]
>Bad
>```cpp
>int* ptr = new int(10);
>delete ptr;
>```
#### 2. Avoid Memory Leaks
- Good Practice: Free allocated memory properly.
- Bad Practice: Forget to deallocate memory.

>[!TIP]
>Good
>```cpp
>{
>    std::unique_ptr<int> ptr = std::make_unique<int>(10);
>} // Memory automatically freed
>```

>[!CAUTION]
>Bad
>```cpp
>int* ptr = new int(10);
>// Forgot to delete ptr!
>```
### Use of Standard Library
#### 1. Prefer STL Containers
- Good Practice: Use std::vector, std::map, etc., instead of raw arrays or custom data structures.
- Bad Practice: Reimplement standard data structures.

>[!TIP]
>Good
>```cpp
>std::vector<int> numbers = {1, 2, 3};
>```

>[!CAUTION]
>Bad
>```cpp
>int numbers[] = {1, 2, 3};
>```
#### 2. Avoid Reimplementing Algorithms
- Good Practice: Use std::sort, std::find, etc.
- Bad Practice: Write your own implementation for common algorithms.

>[!TIP]
>Good
>```cpp
>std::sort(numbers.begin(), numbers.end());
>```

>[!CAUTION]
>Bad
>```cpp
>for (int i = 0; i < n - 1; i++) {
>    for (int j = 0; j < n - i - 1; j++) {
>        if (arr[j] > arr[j + 1]) {
>            std::swap(arr[j], arr[j + 1]);
>        }
>    }
>}
>```
### Object-Oriented Design
#### 1. Use Access Modifiers
- Good Practice: Encapsulate data using private and expose through public functions.
- Bad Practice: Expose internal data directly.

>[!TIP]
>Good
>```cpp
>class Employee {
>private:
>    double salary;
>
>public:
>    void setSalary(double s) { salary = s; }
>    double getSalary() const { return salary; }
>};
>```

>[!CAUTION]
>Bad
>```cpp
>class Employee {
>public:
>    double salary;
>};
>```