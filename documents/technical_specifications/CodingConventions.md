# Coding Conventions

<details>
    <summary>Table of contents</summary>

- [Coding Conventions](#coding-conventions)
  - [C](#c)
    - [Naming Conventions](#naming-conventions)
      - [1. Variable Names](#1-variable-names)
      - [2. Constant Names](#2-constant-names)
      - [3. Function Names](#3-function-names)
      - [4. Struct and Enum Names](#4-struct-and-enum-names)
    - [Code Structure and Formatting](#code-structure-and-formatting)
      - [1. Indentation](#1-indentation)
      - [2. Line Length](#2-line-length)
    - [Code Comments](#code-comments)
      - [1. Single-Line Comments](#1-single-line-comments)
      - [2. Multi-Line Comments](#2-multi-line-comments)
    - [Function Design](#function-design)
      - [1. Single Responsibility](#1-single-responsibility)
      - [2. Function Length](#2-function-length)
    - [Error Handling](#error-handling)
      - [1. Return Codes](#1-return-codes)
    - [Memory Management](#memory-management)
      - [1. Free Allocated Memory](#1-free-allocated-memory)
    - [File Organization](#file-organization)
      - [1. Header Files](#1-header-files)
    - [Preprocessor Directives](#preprocessor-directives)
      - [1. Include Guards](#1-include-guards)
  - [C++](#c-1)
    - [Naming Conventions](#naming-conventions-1)
      - [1. Variables](#1-variables)
      - [2. Constants](#2-constants)
      - [3. Classes](#3-classes)
      - [4. Functions](#4-functions)
    - [Code Formatting](#code-formatting)
      - [1. Indentation](#1-indentation-1)
      - [2. Line Length](#2-line-length-1)
      - [3. Braces](#3-braces)
    - [Comments](#comments)
      - [1. Descriptive Comments](#1-descriptive-comments)
      - [2. Inline Comments](#2-inline-comments)
    - [Error Handling](#error-handling-1)
      - [1. Use Exceptions](#1-use-exceptions)
      - [2. Avoid Catch-All Blocks](#2-avoid-catch-all-blocks)
    - [Code Structure](#code-structure)
      - [1. Single Responsibility Principle](#1-single-responsibility-principle)
      - [2. Avoid Magic Numbers](#2-avoid-magic-numbers)
    - [Memory Management](#memory-management-1)
      - [1. Use Smart Pointers](#1-use-smart-pointers)
      - [2. Avoid Memory Leaks](#2-avoid-memory-leaks)
    - [Use of Standard Library](#use-of-standard-library)
      - [1. Prefer STL Containers](#1-prefer-stl-containers)
      - [2. Avoid Reimplementing Algorithms](#2-avoid-reimplementing-algorithms)
    - [Object-Oriented Design](#object-oriented-design)
      - [1. Use Access Modifiers](#1-use-access-modifiers)


</details>

## C

### Naming Conventions
#### 1. Variable Names

>[!TIP]
>- `Good Practice:` Use descriptive and meaningful names with snake_case for clarity.
>```c
>int total_items;
>float item_price;
>```

>[!CAUTION]
>- `Bad Practice:` Avoid single-character or ambiguous names.
>```c
>int x;
>float p;
>```

#### 2. Constant Names

>[!TIP]
>- `Good Practice:` Use uppercase letters with underscores (UPPER_SNAKE_CASE).
>```c
>#define MAX_BUFFER_SIZE 1024
>```

>[!CAUTION]
>- `Bad Practice:` Avoid using lowercase or non-descriptive names.
>```c
>#define maxBuffer 1024
>```

#### 3. Function Names

>[!TIP]
>- `Good Practice:` Use descriptive names with snake_case or camelCase consistently.
>```c
>int calculate_sum(int a, int b);
>```

>[!CAUTION]
>- `Bad Practice:` Avoid cryptic or overly generic names.
>```c
>int doStuff(int a, int b);
>```

#### 4. Struct and Enum Names

>[!TIP]
>- `Good Practice:` Use PascalCase or CamelCase for struct and enum names.
>```c
>typedef struct Person {
>    char name[50];
>    int age;
>} Person;
>```

>[!CAUTION]
>- `Bad Practice:` Avoid lowercase or overly long names.
>```c
>typedef struct person {
>    char name[50];
>    int age;
>} person_struct_type_long;
>```

### Code Structure and Formatting
#### 1. Indentation

>[!TIP]
>- `Good Practice:` Use consistent indentation, such as 4 spaces per level.
>```c
>if (x > 0) {
>    printf("Positive number\n");
>}
>```

>[!CAUTION]
>- `Bad Practice:` Mixing spaces and tabs, or inconsistent levels of indentation.
>```c
>if (x > 0) {
>printf("Positive number\n");
>  }
>```

#### 2. Line Length

>[!TIP]
>- `Good Practice:` Keep lines under 80 characters.
>```c
>if (x > 0) {
>    printf("This is a positive number.\n");
>}
>```

>[!CAUTION]
>- `Bad Practice:` Write overly long lines that reduce readability.
>```c
>if (x > 0) { printf("This is a positive number. Really, it's positive, not negative.\n"); }
>```

### Code Comments
#### 1. Single-Line Comments

>[!TIP]
>- `Good Practice:` Use // for short, clear comments.
>```c
>// Calculate the sum of two numbers
>int sum = a + b;
>```

>[!CAUTION]
>- `Bad Practice:` Avoid irrelevant or excessive comments.
>```c
>// This is a comment that doesn't say anything meaningful
>int sum = a + b; // adding numbers
>```

#### 2. Multi-Line Comments

>[!TIP]
>- `Good Practice:` Use /* */ for detailed explanations.
>```c
>// Calculate the sum of two numbers
>/*
> * Function: calculate_sum
> * Purpose: Adds two numbers and returns the result.
> */
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use excessive comments or forget to update outdated comments.
>```c
>/*
> * This function calculates a product (outdated comment, incorrect).
> */
>int calculate_sum(int a, int b) {
>    return a + b; // Adds, not multiplies.
>}
>```

### Function Design
#### 1. Single Responsibility

>[!TIP]
>- `Good Practice:` Each function should perform one task.
>```c
>void print_message();
>int calculate_sum(int a, int b);
>```

>[!CAUTION]
>- `Bad Practice:` Avoid multi-purpose functions.
>```c
>void do_all_the_things(int a, int b) {
>    printf("Hello, World!\n");
>    int sum = a + b;
>    printf("Sum: %d\n", sum);
>}
>```

#### 2. Function Length

>[!TIP]
>- `Good Practice:` Keep functions short and focused.
>```c
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Avoid excessively long functions.
>```c
>int calculate_sum_and_print_message_and_log(int a, int b) {
>    printf("Calculating...\n");
>    int sum = a + b;
>    printf("Sum is %d\n", sum);
>    return sum;
>}
>```

### Error Handling
#### 1. Return Codes

>[!TIP]
>- `Good Practice:` Return error codes or meaningful values.
>```c
>int open_file(const char *filename) {
>    if (!filename) {
>        return -1; // Error: null filename
>    }
>    // Open file logic...
>    return 0; // Success
>}
>```

>[!CAUTION]
>- `Bad Practice:` Avoid arbitrary return values.
>```c
>int open_file(const char *filename) {
>    // No error handling
>    // Assume success always
>    return 1; // Arbitrary
>}
>```

### Memory Management
#### 1. Free Allocated Memory

>[!TIP]
>- `Good Practice:` Free memory after use.
>```c
>char *buffer = malloc(1024);
>// Use the buffer...
>free(buffer);
>```

>[!CAUTION]
>- `Bad Practice:` Forget to free memory or double-free.
>```c
>char *buffer = malloc(1024);
>// Forgot to free memory (memory leak).
>```

### File Organization
#### 1. Header Files

>[!TIP]
>- `Good Practice:` Separate declarations in .h files and definitions in .c files.
>```c
>// utils.h
>#ifndef UTILS_H
>#define UTILS_H
>
>int calculate_sum(int a, int b);
>
>#endif
>
>// utils.c
>#include "utils.h"
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Place all code in a single file.
>```c
>// utils.c
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

### Preprocessor Directives
#### 1. Include Guards

>[!TIP]
>- `Good Practice:` Use include guards or #pragma once in header files.
>```c
>#ifndef HEADER_FILE_H
>#define HEADER_FILE_H
>
>// Declarations...
>
>#endif // HEADER_FILE_H
>```

>[!CAUTION]
>- `Bad Practice:` Missing include guards, leading to duplicate inclusion errors.
>```c
>// Missing guards
>// Leads to redefinition errors if included multiple times.
>```

## C++

### Naming Conventions
#### 1. Variables

>[!TIP]
>- `Good Practice:` Use camelCase for variables and descriptive names.
>```cpp
>int employeeCount = 10;
>float accountBalance = 1000.5;
>```

>[!CAUTION]
>- `Bad Practice:` Use single letters or unclear abbreviations.
>```cpp
>int x = 10;
>float ab = 1000.5;
>```

#### 2. Constants

>[!TIP]
>- `Good Practice:` Use UPPER_SNAKE_CASE for constants.
>```cpp
>const int MAX_USERS = 100;
>```

>[!CAUTION]
>- `Bad Practice:` Use lowercase or misleading names.
>```cpp
>const int maxusers = 100;
>```
#### 3. Classes

>[!TIP]
>- `Good Practice:` Use PascalCase for class names.
>```cpp
>class EmployeeDatabase {
>    // ...
>};
>```

>[!CAUTION]
>- `Bad Practice:` Use lowercase or non-descriptive names.
>```cpp
>class employeedatabase {
>    // ...
>};
>```
#### 4. Functions

>[!TIP]
>- `Good Practice:` Use camelCase and start with a verb.
>```cpp
>void calculateSalary() {
>    // ...
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use non-descriptive or vague names.
>```cpp
>void calc() {
>    // ...
>}
>```


### Code Formatting
#### 1. Indentation

>[!TIP]
>- `Good Practice:` Use consistent indentation (2 or 4 spaces).
>```cpp
>void printMessage() {
>    std::cout << "Hello, World!" << std::endl;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use inconsistent or mixed tabs and spaces.
>```cpp
>void printMessage() {
> std::cout << "Hello, World!" << std::endl;
>}
>```

#### 2. Line Length

>[!TIP]
>- `Good Practice:` Limit lines to 80-100 characters.
>```cpp
>std::cout << "This is a short and readable line." << std::endl;
>```

>[!CAUTION]
>- `Bad Practice:` Write overly long lines.
>```cpp
>std::cout << "This line is excessively long and will make the code hard to read in smaller editors or screens." << std::endl;
>```

#### 3. Braces

>[!TIP]
>- `Good Practice:` Place braces on new lines (Allman style) or same line (K&R style), consistently.
>```cpp
>if (x > 0) {
>    std::cout << "Positive" << std::endl;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Mix brace styles.
>```cpp
>if (x > 0)
>{
>    std::cout << "Positive" << std::endl; }
>```
### Comments
#### 1. Descriptive Comments

>[!TIP]
>- `Good Practice:` Use comments to explain why, not what.
>```cpp
>// This function calculates the employee's salary based on hourly rate and hours worked.
>double calculateSalary(double hourlyRate, int hoursWorked) {
>    return hourlyRate * hoursWorked;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Write obvious or outdated comments.
>```cpp
>// This function calculates salary
>double calculateSalary(double hourlyRate, int hoursWorked) {
>    return hourlyRate * hoursWorked;
>}
>```
#### 2. Inline Comments

>[!TIP]
>- `Good Practice:` Use inline comments sparingly.
>```cpp
>x = y + z; // Combine y and z
>```

>[!CAUTION]
>- `Bad Practice:` Overuse inline comments or write non-descriptive ones.
>```cpp
>x = y + z; // Add numbers
>```
### Error Handling
#### 1. Use Exceptions

>[!TIP]
>- `Good Practice:` Use exceptions for error handling.
>```cpp
>try {
>    openFile("data.txt");
>} catch (const std::exception& e) {
>    std::cerr << "Error: " << e.what() << std::endl;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use return codes or ignore errors.
>```cpp
>if (!openFile("data.txt")) {
>    std::cerr << "Error opening file" << std::endl;
>}
>```
#### 2. Avoid Catch-All Blocks

>[!TIP]
>- `Good Practice:` Catch specific exceptions.
>```cpp
>catch (const std::ios_base::failure& e) {
>    std::cerr << "IO Error: " << e.what() << std::endl;
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use general catch blocks excessively.
>```cpp
>catch (...) {
>    std::cerr << "Unknown Error" << std::endl;
>}
>```
### Code Structure
#### 1. Single Responsibility Principle

>[!TIP]
>- `Good Practice:` Each function/class should have one responsibility.
>```cpp
>class Employee {
>    void updateSalary();
>    void updateTitle();
>};
>```

>[!CAUTION]
>- `Bad Practice:` Overload functions/classes with multiple tasks.
>```cpp
>class Employee {
>    void updateSalaryAndTitle();
>};
>```
#### 2. Avoid Magic Numbers

>[!TIP]
>- `Good Practice:` Use named constants instead of literals.
>```cpp
>const int MAX_USERS = 100;
>if (userCount > MAX_USERS) {
>    // ...
>}
>```

>[!CAUTION]
>- `Bad Practice:` Use hard-coded numbers.
>```cpp
>if (userCount > 100) {
>    // ...
>}
>```
### Memory Management
#### 1. Use Smart Pointers

>[!TIP]
>- `Good Practice:` Use std::unique_ptr or std::shared_ptr.
>```cpp
>std::unique_ptr<int> ptr = std::make_unique<int>(10);
>```

>[!CAUTION]
>- `Bad Practice:` Use raw pointers unnecessarily.
>```cpp
>int* ptr = new int(10);
>delete ptr;
>```
#### 2. Avoid Memory Leaks

>[!TIP]
>- `Good Practice:` Free allocated memory properly.
>```cpp
>{
>    std::unique_ptr<int> ptr = std::make_unique<int>(10);
>} // Memory automatically freed
>```

>[!CAUTION]
>- `Bad Practice:` Forget to deallocate memory.
>```cpp
>int* ptr = new int(10);
>// Forgot to delete ptr!
>```
### Use of Standard Library
#### 1. Prefer STL Containers

>[!TIP]
>- `Good Practice:` Use std::vector, std::map, etc., instead of raw arrays or custom data structures.
>```cpp
>std::vector<int> numbers = {1, 2, 3};
>```

>[!CAUTION]
>- `Bad Practice:` Reimplement standard data structures.
>```cpp
>int numbers[] = {1, 2, 3};
>```
#### 2. Avoid Reimplementing Algorithms

>[!TIP]
>- `Good Practice:` Use std::sort, std::find, etc.
>```cpp
>std::sort(numbers.begin(), numbers.end());
>```

>[!CAUTION]
>- `Bad Practice:` Write your own implementation for common algorithms.
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

>[!TIP]
>- `Good Practice:` Encapsulate data using private and expose through public functions.
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
>- `Bad Practice:` Expose internal data directly.
>```cpp
>class Employee {
>public:
>    double salary;
>};
>```