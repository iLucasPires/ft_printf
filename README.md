# ft_printf
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)

## Introduction

Ft_printf is a 42 school project. The printf function is a very useful function in C. It is used to print formatted data to the standard output. The function is very similar to the printf function in the C standard library. The goal of this project is to recode the printf function.

## How to use
- Clone the repository
- Run `make` to compile the library
- Include the header file `ft_printf.h` in your project
- Compile your project with the library `libftprintf.a`
## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, World!");
    return (0);
}
```
## Supported conversions
- [x] `%c` : Character
- [x] `%s` : String
- [x] `%p` : Pointer
- [x] `%d` : Decimal
- [x] `%i` : Integer
- [x] `%u` : Unsigned integer
- [x] `%x` : Hexadecimal (lowercase)
- [x] `%X` : Hexadecimal (uppercase)
- [x] `%%` : Percent sign

## Supported flags
- [ ] `-` : Left align
- [ ] `0` : Zero padding
- [ ] `.` : Precision
- [ ] `*` : Width
