# 🔢 Complete Number System Converter

A **console-based C application** for converting numbers between the four fundamental number systems:

- **Binary (Base 2)**
- **Decimal (Base 10)**
- **Octal (Base 8)**
- **Hexadecimal (Base 16)**

The project provides all **12 possible one-way conversions** between these number systems through an organized, menu-driven interface.

---

## 📌 Project Overview

The **Complete Number System Converter** is designed as a simple and user-friendly C programming project for learning and demonstrating:

- Number system conversion
- Functions in C
- `switch-case`
- Loops and conditional statements
- Arrays
- String handling
- Input validation
- Menu-driven programming
- Basic console UI design

Instead of using one large conversion block, the program separates the conversion tasks into individual functions, making the project easier to understand and maintain.

---

# ✨ Features

### 🔄 Complete Conversion Support

The application supports all 12 conversions:

| No. | From | To |
|---:|---|---|
| 1 | Binary | Decimal |
| 2 | Binary | Octal |
| 3 | Binary | Hexadecimal |
| 4 | Decimal | Binary |
| 5 | Decimal | Octal |
| 6 | Decimal | Hexadecimal |
| 7 | Octal | Binary |
| 8 | Octal | Decimal |
| 9 | Octal | Hexadecimal |
| 10 | Hexadecimal | Binary |
| 11 | Hexadecimal | Decimal |
| 12 | Hexadecimal | Octal |

---

## 🎨 Console Design

The program uses a structured console interface rather than displaying the conversion choices as an unorganized list.

### Main Design Elements

- Box-style menu
- Separate sections for Binary, Decimal, Octal and Hexadecimal
- Clearly numbered conversion options
- Conversion-specific title bars
- Dedicated result section
- Error messages
- Input information messages
- Continue/exit prompt
- Final goodbye screen

### Main Menu Structure

```text
======================================================================
                 COMPLETE NUMBER SYSTEM CONVERTER
                     Binary | Decimal | Octal | Hex
======================================================================

                         CONVERSION MENU
----------------------------------------------------------------------

  +---------------- BINARY CONVERSIONS ----------------+
  |  [ 1 ]  Binary      -> Decimal                      |
  |  [ 2 ]  Binary      -> Octal                        |
  |  [ 3 ]  Binary      -> Hexadecimal                  |
  +-----------------------------------------------------+

  +--------------- DECIMAL CONVERSIONS ----------------+
  |  [ 4 ]  Decimal     -> Binary                       |
  |  [ 5 ]  Decimal     -> Octal                        |
  |  [ 6 ]  Decimal     -> Hexadecimal                  |
  +-----------------------------------------------------+

  +----------------- OCTAL CONVERSIONS ----------------+
  |  [ 7 ]  Octal       -> Binary                       |
  |  [ 8 ]  Octal       -> Decimal                      |
  |  [ 9 ]  Octal       -> Hexadecimal                  |
  +-----------------------------------------------------+

  +------------ HEXADECIMAL CONVERSIONS ---------------+
  |  [10 ]  Hexadecimal -> Binary                       |
  |  [11 ]  Hexadecimal -> Decimal                      |
  |  [12 ]  Hexadecimal -> Octal                        |
  +-----------------------------------------------------+

  [ 0 ]  Exit Program
----------------------------------------------------------------------
```

---

# 🧩 Project Structure

The complete project currently contains:

```text
Number_System_Converter/
│
├── Number_System_Converter.c
└── README.md
```

### Main C File

`Number_System_Converter.c`

Contains:

- Main menu
- Input handling
- Validation
- Conversion functions
- Console UI functions
- Result display
- Exit screen

---

# ⚙️ Technologies Used

| Technology | Purpose |
|---|---|
| C | Main programming language |
| `stdio.h` | Input/output |
| `string.h` | String handling |
| `math.h` | Power calculations |
| `stdlib.h` | System functions |
| `switch-case` | Menu selection |
| Functions | Separate conversion modules |
| Arrays | Storing conversion remainders |

---

# 🏗️ Program Architecture

The application is divided into three main parts.

## 1. User Interface

Responsible for displaying:

- Project title
- Conversion menu
- Conversion headers
- Results
- Errors
- Continue/exit options

Important UI functions:

```c
title()
showMenu()
conversionTitle()
resultLine()
smallLine()
goodbye()
```

---

## 2. Input Validation

The program checks whether the entered value belongs to the selected number system.

### Binary Validation

Binary numbers can only contain:

```text
0
1
```

Validation function:

```c
isBinary()
```

Example:

```text
Input: 101101
Status: Valid

Input: 102101
Status: Invalid
```

---

### Octal Validation

Octal numbers can only contain:

```text
0 1 2 3 4 5 6 7
```

Validation function:

```c
isOctal()
```

Example:

```text
Input: 725
Status: Valid

Input: 728
Status: Invalid
```

---

### Hexadecimal Validation

Hexadecimal numbers can contain:

```text
0 - 9
A - F
a - f
```

Validation function:

```c
isHexadecimal()
```

Example:

```text
Input: 2AF
Status: Valid

Input: 2AG
Status: Invalid
```

---

# 🔄 Conversion Logic

The program uses mathematical number-system conversion techniques.

## Binary → Decimal

Each binary digit is multiplied by the corresponding power of 2.

Example:

```text
1011₂

= 1×2³ + 0×2² + 1×2¹ + 1×2⁰

= 8 + 0 + 2 + 1

= 11₁₀
```

---

## Decimal → Binary

The decimal number is repeatedly divided by 2.

The remainders are stored and then printed in reverse order.

```text
Decimal
   ↓
Divide by 2
   ↓
Store remainder
   ↓
Repeat
   ↓
Print remainders in reverse
   ↓
Binary
```

---

## Binary → Octal

The program first converts:

```text
Binary → Decimal
```

and then:

```text
Decimal → Octal
```

---

## Binary → Hexadecimal

The program first converts:

```text
Binary → Decimal
```

and then:

```text
Decimal → Hexadecimal
```

---

## Octal → Decimal

Each octal digit is multiplied by a power of 8.

Example:

```text
157₈

= 1×8² + 5×8¹ + 7×8⁰

= 64 + 40 + 7

= 111₁₀
```

---

## Hexadecimal → Decimal

Hexadecimal digits are converted using:

```text
A = 10
B = 11
C = 12
D = 13
E = 14
F = 15
```

Example:

```text
2A₁₆

= 2×16¹ + 10×16⁰

= 32 + 10

= 42₁₀
```

---

## Hexadecimal → Binary

Each hexadecimal digit directly represents four binary bits.

```text
Hex   Binary
----------------
0     0000
1     0001
2     0010
3     0011
4     0100
5     0101
6     0110
7     0111
8     1000
9     1001
A     1010
B     1011
C     1100
D     1101
E     1110
F     1111
```

Example:

```text
2AF₁₆

2 → 0010
A → 1010
F → 1111

Result:

001010101111₂
```

---

# 🧱 Function Organization

The project separates each conversion into its own function.

### Binary Functions

```c
Bin_to_Dec()
Bin_to_Oct()
Bin_to_Hex()
```

### Decimal Functions

```c
Dec_to_Bin()
Dec_to_Oct()
Dec_to_Hex()
```

### Octal Functions

```c
Oct_to_Bin()
Oct_to_Dec()
Oct_to_Hex()
```

### Hexadecimal Functions

```c
Hex_to_Bin()
Hex_to_Dec()
Hex_to_Oct()
```

This makes the program modular and easier to maintain.

---

# 🖥️ Example Usage

### Step 1 — Start the program

The application displays the project title and conversion menu.

### Step 2 — Select a conversion

For example:

```text
ENTER YOUR CHOICE: 1
```

### Step 3 — Enter the number

```text
BINARY -> DECIMAL

Enter Binary Number (0s & 1s): 101101
```

### Step 4 — View the result

```text
----------------------------------------------------------------------
  RESULT
  Equivalent Decimal Number : 45
----------------------------------------------------------------------
```

### Step 5 — Continue or exit

```text
Do you want to perform another conversion?
Enter 1 = YES    |    0 = NO
YOUR CHOICE:
```

---

# ⚠️ Error Handling

The program includes basic input validation.

### Invalid Binary

```text
[ ERROR ] 10201 is NOT a binary number.
[ INFO  ] Binary numbers contain only 0 and 1.
```

### Invalid Octal

```text
[ ERROR ] 789 is NOT an octal number.
[ INFO  ] Octal numbers contain digits from 0 to 7.
```

### Invalid Hexadecimal

```text
[ ERROR ] "12AG" is NOT a hexadecimal number.
[ INFO  ] Use digits 0-9 and letters A-F.
```

### Invalid Menu Choice

```text
[ ERROR ] Invalid menu choice.
[ INFO  ] Please select an option from 0 to 12.
```

---

# 🛠️ Requirements

You need a C compiler capable of compiling standard C code.

Recommended environments:

- Code::Blocks
- Dev-C++
- Visual Studio Code with a C compiler
- GCC / MinGW
- Other standard C development environments

---

# ▶️ How to Compile

## Using GCC

Open a terminal in the project directory and run:

```bash
gcc Number_System_Converter.c -o Number_System_Converter -lm
```

Then run:

### Windows

```bash
Number_System_Converter.exe
```

### Linux/macOS

```bash
./Number_System_Converter
```

> The `-lm` option links the mathematical library used by `pow()`.

---

# 🪟 Windows Console Note

The program uses:

```c
system("COLOR 0B");
```

to set the Windows console color.

Therefore, the intended visual appearance is optimized for the **Windows Command Prompt / Windows console**.

The conversion logic itself does not depend on the color setting.

---

# 📋 Supported Input

| Number System | Valid Characters |
|---|---|
| Binary | `0 - 1` |
| Decimal | `0 - 9` |
| Octal | `0 - 7` |
| Hexadecimal | `0 - 9`, `A - F`, `a - f` |

---

# 🔐 Input Safety Improvements

The program includes several practical input-handling improvements:

- Binary digit validation
- Octal digit validation
- Hexadecimal character validation
- Maximum input width for hexadecimal strings
- Invalid menu-choice handling
- Negative decimal number rejection
- Division/remainder based conversion handling
- Special handling for zero

For hexadecimal input, the program uses:

```c
scanf("%999s", hex);
```

instead of an unrestricted string input.

---

# 📁 Important Functions

| Function | Purpose |
|---|---|
| `title()` | Displays application title |
| `showMenu()` | Displays conversion menu |
| `conversionTitle()` | Displays selected conversion |
| `resultLine()` | Formats result section |
| `goodbye()` | Displays exit message |
| `isBinary()` | Validates binary input |
| `isOctal()` | Validates octal input |
| `isHexadecimal()` | Validates hexadecimal input |
| `Bin_to_Dec()` | Binary to decimal |
| `Bin_to_Oct()` | Binary to octal |
| `Bin_to_Hex()` | Binary to hexadecimal |
| `Dec_to_Bin()` | Decimal to binary |
| `Dec_to_Oct()` | Decimal to octal |
| `Dec_to_Hex()` | Decimal to hexadecimal |
| `Oct_to_Bin()` | Octal to binary |
| `Oct_to_Dec()` | Octal to decimal |
| `Oct_to_Hex()` | Octal to hexadecimal |
| `Hex_to_Bin()` | Hexadecimal to binary |
| `Hex_to_Dec()` | Hexadecimal to decimal |
| `Hex_to_Oct()` | Hexadecimal to octal |

---

# 🎯 Project Objectives

The main objectives of this project are:

1. To implement number-system conversion using C.
2. To understand different positional number systems.
3. To practice functions and modular programming.
4. To implement input validation.
5. To build a menu-driven console application.
6. To improve understanding of loops, arrays and conditional statements.
7. To create a cleaner and more user-friendly C console interface.

---

# 📚 Educational Concepts Demonstrated

This project demonstrates several fundamental C programming concepts:

### Variables and Data Types

```c
int
long int
char
```

### Conditional Statements

```c
if
else if
else
switch
```

### Loops

```c
while
for
```

### Functions

The program uses separate functions for each conversion.

### Arrays

Arrays are used for:

- Conversion remainders
- Hexadecimal strings

### Mathematical Operations

The program uses:

```c
%
/
*
pow()
```

for conversion calculations.

---

# 🚀 Possible Future Improvements

The current project focuses on integer number-system conversion. Possible future versions could add:

- Direct Binary ↔ Hexadecimal conversion without an intermediate decimal value
- Floating-point number conversion
- Negative number support
- Larger integer support
- Conversion history
- File-based conversion logs
- Graphical user interface
- More advanced input validation
- Cross-platform console styling
- Separate header/source files
- Automated test cases

---

# 📌 Limitations

The current version is primarily intended as an educational console application.

Some limitations include:

- It focuses on integer conversions.
- The conversion implementation uses `long int`, so the supported numeric range depends on the compiler/platform.
- Console color behavior is Windows-oriented.
- Extremely large values may exceed the available numeric range.
- It is not intended to be a production-grade arbitrary-precision calculator.

---

# 👨‍💻 Project Summary

**Complete Number System Converter** is a modular C console application that provides all 12 conversions between Binary, Decimal, Octal and Hexadecimal number systems.

The project combines mathematical conversion techniques with fundamental C programming concepts and a structured console interface.

It is suitable as a **C programming, structured programming, or number-system conversion academic project**.

---

## ⭐ Final Conversion Map

```text
                         +-------------+
                         |   BINARY    |
                         +-------------+
                         /      |      \
                        /       |       \
                       ↓        ↓        ↓
                  DECIMAL     OCTAL    HEXADECIMAL
                       ↑        ↑        ↑
                        \       |       /
                         \      |      /
                         +-------------+

             All 12 one-way conversions are supported.
```

---

## 📄 License

This project is intended for **educational and academic use**.

You may modify and extend the source code for learning and project purposes.
