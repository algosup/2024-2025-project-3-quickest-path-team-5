# Coding Conventions

<details>
    <summary>Table of contents</summary>

- [Coding Conventions](#coding-conventions)
  - [C](#c)
    - [Naming Conventions (C)](#naming-conventions-c)
      - [1. Variable Names (C)](#1-variable-names-c)
      - [2. Constant Names (C)](#2-constant-names-c)
      - [3. Function Names (C)](#3-function-names-c)
      - [4. Struct and Enum Names (C)](#4-struct-and-enum-names-c)
    - [Code Structure and Formatting (C)](#code-structure-and-formatting-c)
      - [1. Indentation (C)](#1-indentation-c)
      - [2. Line Length (C)](#2-line-length-c)
    - [Code Comments (C)](#code-comments-c)
      - [1. Single-Line Comments (C)](#1-single-line-comments-c)
      - [2. Multi-Line Comments (C)](#2-multi-line-comments-c)
      - [3. Documenting Function Parameters and Return Values (C)](#3-documenting-function-parameters-and-return-values-c)
      - [4. Documenting Pointer Parameters (C)](#4-documenting-pointer-parameters-c)
      - [5. Documenting Complex Parameters and Structures (C)](#5-documenting-complex-parameters-and-structures-c)
      - [6. Documenting Return Types (C)](#6-documenting-return-types-c)
    - [Function Design (C)](#function-design-c)
      - [1. Single Responsibility (C)](#1-single-responsibility-c)
      - [2. Function Length (C)](#2-function-length-c)
    - [Error Handling (C)](#error-handling-c)
      - [1. Return Codes (C)](#1-return-codes-c)
    - [Memory Management (C)](#memory-management-c)
      - [1. Free Allocated Memory (C)](#1-free-allocated-memory-c)
    - [File Organization (C)](#file-organization-c)
      - [1. Header Files (C)](#1-header-files-c)
    - [Preprocessor Directives (C)](#preprocessor-directives-c)
      - [1. Include Guards (C)](#1-include-guards-c)
  - [C++](#c-1)
    - [Naming Conventions (C++)](#naming-conventions-c-1)
      - [1. Variables (C++)](#1-variables-c)
      - [2. Constants (C++)](#2-constants-c)
      - [3. Classes (C++)](#3-classes-c)
      - [4. Functions (C++)](#4-functions-c)
    - [Code Formatting (C++)](#code-formatting-c)
      - [1. Indentation (C++)](#1-indentation-c-1)
      - [2. Line Length (C++)](#2-line-length-c-1)
      - [3. Braces (C++)](#3-braces-c)
    - [Comments (C++)](#comments-c)
      - [1. Single-Line Comments (C++)](#1-single-line-comments-c-1)
      - [2. Multi-Line Comments (C++)](#2-multi-line-comments-c-1)
      - [3. Documenting Function Parameters and Return Values (C++)](#3-documenting-function-parameters-and-return-values-c-1)
      - [4. Documenting Classes and Methods (C++)](#4-documenting-classes-and-methods-c)
      - [5. Documenting Pointer and Reference Parameters (C++)](#5-documenting-pointer-and-reference-parameters-c)
      - [6. Documenting Templates and Overloaded Functions (C++)](#6-documenting-templates-and-overloaded-functions-c)
      - [7. Documenting Complex Functions (C++)](#7-documenting-complex-functions-c)
    - [Error Handling (C++)](#error-handling-c-1)
      - [1. Use Exceptions (C++)](#1-use-exceptions-c)
      - [2. Avoid Catch-All Blocks (C++)](#2-avoid-catch-all-blocks-c)
    - [Code Structure (C++)](#code-structure-c)
      - [1. Single Responsibility Principle (C++)](#1-single-responsibility-principle-c)
      - [2. Avoid Magic Numbers (C++)](#2-avoid-magic-numbers-c)
    - [Memory Management (C++)](#memory-management-c-1)
      - [1. Use Smart Pointers (C++)](#1-use-smart-pointers-c)
      - [2. Avoid Memory Leaks (C++)](#2-avoid-memory-leaks-c)
    - [Use of Standard Library (C++)](#use-of-standard-library-c)
      - [1. Prefer STL Containers (C++)](#1-prefer-stl-containers-c)
      - [2. Avoid Reimplementing Algorithms (C++)](#2-avoid-reimplementing-algorithms-c)
    - [Object-Oriented Design (C++)](#object-oriented-design-c)
      - [1. Use Access Modifiers (C++)](#1-use-access-modifiers-c)

</details>

## C

### Naming Conventions (C)

#### 1. Variable Names (C)

>[!TIP]
>
>- `Good Practice:` Use descriptive and meaningful names with snake_case for clarity.
>
>```c
>int total_items;
>float item_price;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Avoid single-character or ambiguous names.
>
>```c
>int x;
>float p;
>```

#### 2. Constant Names (C)

>[!TIP]
>
>- `Good Practice:` Use uppercase letters with underscores (UPPER_SNAKE_CASE).
>
>```c
>#define MAX_BUFFER_SIZE 1024
>```

<br>

>[!CAUTION]
.
>
>- `Bad Practice:` Avoid using lowercase or non-descriptive names.
>
>```c
>#define maxBuffer 1024
>```

#### 3. Function Names (C)

>[!TIP]
>
>- `Good Practice:` Use descriptive names with camelCase consistently.
>
>```c
>int calculate_sum(int a, int b);
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Avoid cryptic or overly generic names.
>
>```c
>int doStuff(int a, int b);
>```

#### 4. Struct and Enum Names (C)

>[!TIP]
>
>- `Good Practice:` Use PascalCase for struct and enum names.
>
>```c
>typedef struct Person {
>    char name[50];
>    int age;
>} Person;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Avoid lowercase or overly long names.
>
>```c
>typedef struct person {
>    char name[50];
>    int age;
>} person_struct_type_long;
>```

### Code Structure and Formatting (C)

#### 1. Indentation (C)

>[!TIP]
>
>- `Good Practice:` Use consistent indentation, such as 4 spaces per level.
>
>```c
>if (x > 0) {
>    printf("Positive number\n");
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Mixing spaces and tabs, or inconsistent levels of indentation.
>
>```c
>if (x > 0) {
>printf("Positive number\n");
>  }
>```

#### 2. Line Length (C)

>[!TIP]
>
>- `Good Practice:` Keep lines under 80 characters.
>
>```c
>if (x > 0) {
>    printf("This is a positive number.\n");
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Write overly long lines that reduce readability.
>
>```c
>if (x > 0) { printf("This is a positive number. Really, it's positive, not negative.\n"); }
>```

### Code Comments (C)

#### 1. Single-Line Comments (C)

>[!TIP]
>
>- `Good Practice:` Use // for short, clear comments.
>
>```c
>// Calculate the sum of two numbers
>int sum = a + b;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Avoid irrelevant or excessive comments.
>
>```c
>// This is a comment that doesn't say anything meaningful
>int sum = a + b; // adding numbers
>```

#### 2. Multi-Line Comments (C)

>[!TIP]
>
>- `Good Practice:` Use /**/ for detailed explanations.
>
>```c
>/*
> * Function: calculate_sum
> * \brief Adds two numbers and returns the result.
> * \param a The first integer.
> * \param b The second integer.
> * \return The sum of a and b.
> */
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use excessive comments or forget to update outdated comments.
>
>```c
>/*
> * This function calculates a product (outdated comment, incorrect).
> */
>int calculate_sum(int a, int b) {
>    return a + b; // Actually adds, not multiplies.
>}
>```

#### 3. Documenting Function Parameters and Return Values (C)

>[!TIP]
>
>- `Good Practice:` Use Doxygen's \param and \return tags for precise descriptions.
>
>```c
>/*
> * \brief Adds two integers and returns the result.
> * 
> * This function takes two integers as input, calculates their sum, and returns the result.
> *
> * \param a The first integer to be added.
> * \param b The second integer to be added.
> * \return The sum of the two integers as an integer.
> */
>int add_numbers(int a, int b) {
>    return a + b;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Vague or incomplete descriptions of parameters and return types.
>
>```c
>/*
> * Adds two numbers.
> * \param a First number.
> * \param b Second number.
> * \return The result.
> */
>int add_numbers(int a, int b) {
>    return a + b; 
>}
>```

#### 4. Documenting Pointer Parameters (C)

>[!TIP]
>
>- `Good Practice:` Clearly indicate the purpose of pointers.
>
>```c
>/*
> * \brief Updates the value of an integer through a pointer.
> *
> * This function takes a pointer to an integer and updates its value to a specified number.
> *
> * \param[out] ptr A pointer to an integer that will be updated.
> * \param value The new value to set.
> * \return Void.
> */
>void update_value(int *ptr, int value) {
>    if (ptr != NULL) {
>        *ptr = value;
>    }
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Failing to specify the purpose of the pointer.
>
>```c
>/*
> * Updates a value.
> * \param ptr A pointer to something.
> * \param value The new value.
> */
>void update_value(int *ptr, int value) {
>    if (ptr != NULL) {
>        *ptr = value;
>    }
>}
>```

#### 5. Documenting Complex Parameters and Structures (C)

>[!TIP]
>
>- `Good Practice:` Provide details about the structure fields.
>
>```c
>/*
> * \brief Initializes a 2D point with the specified coordinates.
> *
> * \param[out] point A pointer to a Point structure to be initialized.
> * \param x The x-coordinate of the point.
> * \param y The y-coordinate of the point.
> * \return Void.
> */
>struct Point {
>    int x; /**< The x-coordinate */
>    int y; /**< The y-coordinate */
>};
>
>void init_point(struct Point *point, int x, int y) {
>    if (point != NULL) {
>        point->x = x;
>        point->y = y;
>    }
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Leaving out details of the structure or failing to document it altogether.
>
>```c
>/*
> * Initializes a point.
> * \param point Pointer to a Point structure.
> * \param x X-coordinate.
> * \param y Y-coordinate.
> */
>struct Point {
>    int x;
>    int y;
>};
>
>void init_point(struct Point *point, int x, int y) {
>    if (point != NULL) {
>        point->x = x;
>        point->y = y;
>    }
>}
>```

#### 6. Documenting Return Types (C)

>[!TIP]
>
>- `Good Practice:` Explicitly describe the return value.
>
>```c
>/*
> * \brief Divides two integers and returns the quotient.
> *
> * \param numerator The numerator of the division.
> * \param denominator The denominator of the division.
> * \return The quotient of the division. If the denominator is zero, returns INT_MAX.
> */
>int divide(int numerator, int denominator) {
>    if (denominator == 0) {
>        return INT_MAX; // Avoid division by zero.
>    }
>    return numerator / denominator;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Avoiding edge cases or leaving the return value unexplained.
>
>```c
>/*
> * Divides two numbers.
> * \param numerator The numerator.
> * \param denominator The denominator.
> * \return The result.
> */
>int divide(int numerator, int denominator) {
>    if (denominator == 0) {
>        return INT_MAX; // Avoid division by zero.
>    }
>    return numerator / denominator;
>}
>```

### Function Design (C)

#### 1. Single Responsibility (C)

>[!TIP]
>
>- `Good Practice:` Each function should perform one task.
>
>```c
>void print_message();
>int calculate_sum(int a, int b);
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Multi-purpose functions.
>
>```c
>void do_all_the_things(int a, int b) {
>    printf("Hello, World!\n");
>    int sum = a + b;
>    printf("Sum: %d\n", sum);
>}
>```

#### 2. Function Length (C)

>[!TIP]
>
>- `Good Practice:` Keep functions short and focused.
>
>```c
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Excessively long functions.
>
>```c
>int calculate_sum_and_print_message_and_log(int a, int b) {
>    printf("Calculating...\n");
>    int sum = a + b;
>    printf("Sum is %d\n", sum);
>    return sum;
>}
>```

### Error Handling (C)

#### 1. Return Codes (C)

>[!TIP]
>
>- `Good Practice:` Return error codes or meaningful values.
>
>```c
>int open_file(const char *filename) {
>    if (!filename) {
>        return -1; // Error: null filename
>    }
>    // Open file logic...
>    return 0; // Success
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Arbitrary return values.
>
>```c
>int open_file(const char *filename) {
>    // No error handling
>    // Assume success always
>    return 1; // Arbitrary
>}
>```

### Memory Management (C)

#### 1. Free Allocated Memory (C)

>[!TIP]
>
>- `Good Practice:` Free memory after use.
>
>```c
>char *buffer = malloc(1024);
>// Use the buffer...
>free(buffer);
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Forget to free memory or double-free.
>
>```c
>char *buffer = malloc(1024);
>// Forgot to free memory (memory leak).
>```

### File Organization (C)

#### 1. Header Files (C)

>[!TIP]
>
>- `Good Practice:` Separate declarations in .h files and definitions in .c files.
>
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

<br>

>[!CAUTION]
>
>- `Bad Practice:` Place all code in a single file.
>
>```c
>// utils.c
>int calculate_sum(int a, int b) {
>    return a + b;
>}
>```

### Preprocessor Directives (C)

#### 1. Include Guards (C)

>[!TIP]
>
>- `Good Practice:` Use include guards or #pragma once in header files.
>
>```c
>#ifndef HEADER_FILE_H
>#define HEADER_FILE_H
>
>// Declarations...
>
>#endif // HEADER_FILE_H
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Missing include guards, leading to duplicate inclusion errors.
>
>```c
>// Missing guards
>// Leads to redefinition errors if included multiple times.
>```

## C++

### Naming Conventions (C++)

#### 1. Variables (C++)

>[!TIP]
>
>- `Good Practice:` Use camelCase for variables and descriptive names.
>
>```cpp
>int employeeCount = 10;
>float accountBalance = 1000.5;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use single letters or unclear abbreviations.
>
>```cpp
>int x = 10;
>float ab = 1000.5;
>```

#### 2. Constants (C++)

>[!TIP]
>
>- `Good Practice:` Use UPPER_SNAKE_CASE for constants.
>
>```cpp
>const int MAX_USERS = 100;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use lowercase or misleading names.
>
>```cpp
>const int maxusers = 100;
>```
>
#### 3. Classes (C++)

>[!TIP]
>
>- `Good Practice:` Use PascalCase for class names.
>
>```cpp
>class EmployeeDatabase {
>    // ...
>};
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use lowercase or non-descriptive names.
>
>```cpp
>class employeedatabase {
>    // ...
>};
>```
>

#### 4. Functions (C++)

>[!TIP]
>
>- `Good Practice:` Use camelCase and start with a verb.
>
>```cpp
>void calculateSalary() {
>    // ...
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use non-descriptive or vague names.
>
>```cpp
>void calc() {
>    // ...
>}
>```

### Code Formatting (C++)

#### 1. Indentation (C++)

>[!TIP]
>
>- `Good Practice:` Use consistent indentation (2 or 4 spaces).
>
>```cpp
>void printMessage() {
>    std::cout << "Hello, World!" << std::endl;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use inconsistent or mixed tabs and spaces.
>
>```cpp
>void printMessage() {
> std::cout << "Hello, World!" << std::endl;
>}
>```

#### 2. Line Length (C++)

>[!TIP]
>
>- `Good Practice:` Limit lines to 80-100 characters.
>
>```cpp
>std::cout << "This is a short and readable line." << std::endl;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Write overly long lines.
>
>```cpp
>std::cout << "This line is excessively long and will make the code hard to read in smaller editors or screens." << std::endl;
>```

#### 3. Braces (C++)

>[!TIP]
>
>- `Good Practice:` Place braces on new lines (Allman style) or same line (K&R style), consistently.
>
>```cpp
>if (x > 0) {
>    std::cout << "Positive" << std::endl;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Mix brace styles.
>
>```cpp
>if (x > 0)
>{
>    std::cout << "Positive" << std::endl; }
>```
>
### Comments (C++)

#### 1. Single-Line Comments (C++)

>[!TIP]
>
> - `Good Practice:` Use `//` for short, clear comments.
>
>```cpp
>// Calculate the sum of two numbers
>int sum = a + b;
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Irrelevant or excessive comments.
>
>```cpp
>// This is a comment that doesn't say anything meaningful
>int sum = a + b; // adding numbers
>```

#### 2. Multi-Line Comments (C++)

>[!TIP]
>
> - `Good Practice:` Use `/**/` for detailed explanations or blocks of comments.
>
>```cpp
>/*
> * Function: calculateSum
> * Purpose: Adds two numbers and returns the result.
> */
>int calculateSum(int a, int b) {
>    return a + b;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Excessive or outdated comments.
>
>```cpp
>/*
> * This function calculates a product (outdated comment, incorrect).
> */
>int calculateSum(int a, int b) {
>    return a + b; // Adds, not multiplies.
>}
>```

#### 3. Documenting Function Parameters and Return Values (C++)

>[!TIP]
>
> - `Good Practice:` Use \param and \return to describe inputs and outputs.
>
>```cpp
>/*
> * \brief Adds two integers and returns the result.
> *
> * This function takes two integers as input, calculates their sum, and returns the result.
> *
> * \param a The first integer to be added.
> * \param b The second integer to be added.
> * \return The sum of the two integers as an integer.
> */
>int addNumbers(int a, int b) {
>    return a + b;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Vague or incomplete descriptions.
>
>```cpp
>/*
> * Adds two numbers.
> * \param a First number.
> * \param b Second number.
> * \return The result.
> */
>int addNumbers(int a, int b) {
>    return a + b; 
>}
>```

#### 4. Documenting Classes and Methods (C++)

>[!TIP]
>
> - `Good Practice:` Always document class purposes and public methods.
>
>```cpp
>/*
> * \class Calculator
> * \brief A utility class for performing basic arithmetic operations.
> *
> * This class provides methods to perform addition, subtraction, multiplication, and division.
> */
>class Calculator {
>public:
>    /*
>     * \brief Adds two numbers.
>     * \param a The first operand.
>     * \param b The second operand.
>     * \return The sum of a and b.
>     */
>    int add(int a, int b) {
>        return a + b;
>    }
>};
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Leaving class or method documentation incomplete.
>
>```cpp
>/*
> * Calculator class.
> */
>class Calculator {
>public:
>    /*
>     * Adds two numbers.
>     */
>    int add(int a, int b) {
>        return a + b;
>    }
>};
>```

#### 5. Documenting Pointer and Reference Parameters (C++)

>[!TIP]
>
> - `Good Practice:` Clearly indicate the purpose of pointers and references.
>
>```cpp
>/*
> * \brief Updates the value of an integer through a pointer.
> *
> * This function takes a pointer to an integer and updates its value to the specified number.
> *
> * \param[out] ptr A pointer to an integer that will be updated.
> * \param value The new value to set.
>/ * \return Void.
> */
>void updateValue(int *ptr, int value) {
>    if (ptr != nullptr) {
>        *ptr = value;
>    }
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Ambiguous descriptions of pointer or reference usage.
>
>```cpp
>/*
> * Updates a value.
> * \param ptr Pointer to a variable.
> * \param value New value.
> */
>void updateValue(int *ptr, int value) {
>    if (ptr != nullptr) {
>        *ptr = value;
>    }
>}
>```

#### 6. Documenting Templates and Overloaded Functions (C++)

>[!TIP]
>
> - `Good Practice:` Use detailed comments for template parameters.
>
>```cpp
>/*
> * \brief Swaps two values.
> *
> * A generic function to swap the values of two variables.
> *
> * \tparam T The type of the variables to swap.
> * \param a A reference to the first variable.
> * \param b A reference to the second variable.
> */
>template <typename T>
>void swapValues(T &a, T &b) {
>    T temp = a;
>    a = b;
>    b = temp;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Omitting documentation for template parameters.
>
>```cpp
>/*
> * Swaps two values.
> */
>template <typename T>
>void swapValues(T &a, T &b) {
>    T temp = a;
>    a = b;
>    b = temp;
>}
>```

#### 7. Documenting Complex Functions (C++)

>[!TIP]
>
> - `Good Practice:` Provide comprehensive descriptions for algorithms and expected behavior.
>
>```cpp
>/*
> * \brief Finds the greatest common divisor (GCD) of two numbers.
> *
> * This function uses the Euclidean algorithm to calculate the GCD of two integers.
> *
> * \param a The first integer.
> * \param b The second integer.
> * \return The greatest common divisor of a and b.
> *
> * \details
> * The function repeatedly replaces the larger number by its remainder when divided
> * by the smaller number, until one of them becomes zero. The non-zero number at this
> * point is the GCD.
> */
>int findGCD(int a, int b) {
>    while (b != 0) {
>        int temp = b;
>        b = a % b;
>        a = temp;
>    }
>    return a;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Skipping algorithm details or leaving parts undocumented.
>
>```cpp
>/*
> * Finds the GCD.
> * \param a A number.
> * \param b Another number.
> * \return The result.
> */
>int findGCD(int a, int b) {
>    while (b != 0) {
>        int temp = b;
>        b = a % b;
>        a = temp;
>    }
>    return a;
>}
>```

### Error Handling (C++)

#### 1. Use Exceptions (C++)

>[!TIP]
>
>- `Good Practice:` Use exceptions for error handling.
>
>```cpp
>try {
>    openFile("data.txt");
>} catch (const std::exception& e) {
>    std::cerr << "Error: " << e.what() << std::endl;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use return codes or ignore errors.
>
>```cpp
>if (!openFile("data.txt")) {
>    std::cerr << "Error opening file" << std::endl;
>}
>```
>
#### 2. Avoid Catch-All Blocks (C++)

>[!TIP]
>
>- `Good Practice:` Catch specific exceptions.
>
>```cpp
>catch (const std::ios_base::failure& e) {
>    std::cerr << "IO Error: " << e.what() << std::endl;
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use general catch blocks excessively.
>
>```cpp
>catch (...) {
>    std::cerr << "Unknown Error" << std::endl;
>}
>```
>
### Code Structure (C++)

#### 1. Single Responsibility Principle (C++)

>[!TIP]
>
>- `Good Practice:` Each function/class should have one responsibility.
>
>```cpp
>class Employee {
>    void updateSalary();
>    void updateTitle();
>};
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Overload functions/classes with multiple tasks.
>
>```cpp
>class Employee {
>    void updateSalaryAndTitle();
>};
>```
>
#### 2. Avoid Magic Numbers (C++)

>[!TIP]
>
>- `Good Practice:` Use named constants instead of literals.
>
>```cpp
>const int MAX_USERS = 100;
>if (userCount > MAX_USERS) {
>    // ...
>}
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use hard-coded numbers.
>
>```cpp
>if (userCount > 100) {
>    // ...
>}
>```
>
### Memory Management (C++)

#### 1. Use Smart Pointers (C++)

>[!TIP]
>
>- `Good Practice:` Use std::unique_ptr or std::shared_ptr.
>
>```cpp
>std::unique_ptr<int> ptr = std::make_unique<int>(10);
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Use raw pointers unnecessarily.
>
>```cpp
>int* ptr = new int(10);
>delete ptr;
>```
>
#### 2. Avoid Memory Leaks (C++)

>[!TIP]
>
>- `Good Practice:` Free allocated memory properly.
>
>```cpp
>{
>    std::unique_ptr<int> ptr = std::make_unique<int>(10);
>} // Memory automatically freed
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Forget to deallocate memory.
>
>```cpp
>int* ptr = new int(10);
>// Forgot to delete ptr!
>```
>
### Use of Standard Library (C++)

#### 1. Prefer STL Containers (C++)

>[!TIP]
>
>- `Good Practice:` Use std::vector, std::map, etc., instead of raw arrays or custom data structures.
>
>```cpp
>std::vector<int> numbers = {1, 2, 3};
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Reimplement standard data structures.
>
>```cpp
>int numbers[] = {1, 2, 3};
>```
>
#### 2. Avoid Reimplementing Algorithms (C++)

>[!TIP]
>
>- `Good Practice:` Use std::sort, std::find, etc.
>
>```cpp
>std::sort(numbers.begin(), numbers.end());
>```

<br>

>[!CAUTION]
>
>- `Bad Practice:` Write your own implementation for common algorithms.
>
>```cpp
>for (int i = 0; i < n - 1; i++) {
>    for (int j = 0; j < n - i - 1; j++) {
>        if (arr[j] > arr[j + 1]) {
>            std::swap(arr[j], arr[j + 1]);
>        }
>    }
>}
>```
>
### Object-Oriented Design (C++)

#### 1. Use Access Modifiers (C++)

>[!TIP]
>
>- `Good Practice:` Encapsulate data using private and expose through public functions.
>
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

<br>

>[!CAUTION]
>
>- `Bad Practice:` Expose internal data directly.
>
>```cpp
>class Employee {
>public:
>    double salary;
>};
>```
