
<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/ft_printfe.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# ft_printf
printf is a 42 school project whose goal is to recode the libc function printf.
## How to use
- Clone the repository
- Run `make` to compile the library
- Include the header file `ft_printf.h` in your project
- Compile your project with the library `libftprintf.a`

## Mandatory part
- [x] The function must be named ft_printf.
- [x] The function must be prototyped as follows: `int ft_printf(const char *, ...);`
- [x] The function must not do the buffer management like the real printf.
- [x] Manage the following conversions: `cspdiuxX%`

## Supported conversions

<table>
  <tr><td><kbd>&nbsp;%c&nbsp;</td><td>Prints a single character.</td></tr>
    <tr><td><kbd>&nbsp;%s&nbsp;</td><td>Prints a string of characters.</td></tr>
    <tr><td><kbd>&nbsp;%p&nbsp;</td><td>Prints a pointer's address.</td></tr>
    <tr><td><kbd>&nbsp;%d&nbsp;&nbsp;%i&nbsp;</td><td>Prints a signed decimal integer.</td></tr>
    <tr><td><kbd>&nbsp;%u&nbsp;</td><td>Prints an unsigned decimal integer.</td></tr>
    <tr><td><kbd>&nbsp;%x&nbsp;</td><td>Prints a number in hexadecimal (lowercase).</td></tr>
    <tr><td><kbd>&nbsp;%X&nbsp;</td><td>Prints a number in hexadecimal (uppercase).</td></tr>
    <tr><td><kbd>&nbsp;%&nbsp;</td><td>Prints a percent sign.</td></tr>
</table>

## Example
```bash
cc name_file.c libftprintf.a -o name_program #the name_program executable
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, World!");
    return (0);
}
```
