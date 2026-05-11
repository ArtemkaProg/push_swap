*This activity has been created as part of the 42 curriculum by avalchuk.*

# ft_printf

## Description

ft_printf is a custom re-implementation of the standard C `printf` function. The goal is to understand how variadic functions work, how format strings are parsed, and how different data types are converted to their string representations.

The function handles the following conversion specifiers:

- `%c` — prints a single character
- `%s` — prints a string (`NULL` is handled as `(null)`)
- `%p` — prints a pointer address in hexadecimal format with `0x` prefix (`NULL` is printed as `(nil)`)
- `%d` / `%i` — prints a signed decimal integer
- `%u` — prints an unsigned decimal integer
- `%x` — prints an unsigned integer in lowercase hexadecimal
- `%X` — prints an unsigned integer in uppercase hexadecimal
- `%%` — prints a literal percent sign

The function returns the total number of characters printed, matching the behavior of the standard `printf`.

## Instructions

### Compilation

```bash
make
```

This will compile the library `libftprintf.a`.

To use it in your own project:

```bash
gcc main.c -L. -lftprintf -o program
```

### Cleanup

```bash
make clean    # removes object files
make fclean   # removes object files and the library
make re       # recompiles from scratch
```

### Running

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 21);
    return (0);
}
```

## Algorithm and data structure choices

### Format string parsing

The format string is iterated character by character. When a `%` is encountered, the next character is read as a conversion specifier and passed to a `dispatch` function that uses a `switch` statement to call the appropriate handler. This approach keeps the main loop simple and makes it easy to add new specifiers.

### Variadic arguments

The standard `stdarg.h` macros (`va_list`, `va_start`, `va_arg`, `va_end`) are used to access the variable arguments. Each handler receives a pointer to the `va_list` so the argument pointer advances correctly across handler calls.

### Integer to hex conversion (`convert_base`)

Hexadecimal conversion is done by repeatedly dividing the number by 16 and indexing into a base string `"0123456789abcdef"`. The length is computed first with `get_hex_len`, memory is allocated, and the string is filled right to left. This avoids any secondary buffer or reversal step.

For `%x` and `%X`, the argument is treated as `unsigned int` (32-bit, max 8 hex digits). For `%p`, the argument is cast to `unsigned long` to handle 64-bit pointer values correctly.

Uppercase conversion for `%X` is done by a separate pass over the result string, shifting lowercase `a`–`f` by subtracting 32.

### Return value

Every handler function returns the number of characters it printed. The main loop accumulates this count in a `total` variable, which `ft_printf` returns at the end.

### Memory management

`convert_base` allocates a string with `malloc`. Each handler that calls it is responsible for freeing the result after printing. No memory is leaked between calls.

## Resources

- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C — cppreference](https://en.cppreference.com/w/c/variadic)
- [stdarg.h — how va_list works](https://en.cppreference.com/w/c/variadic/va_arg)
- [42 ft_printf subject (PDF)](https://cdn.intra.42.fr/pdf/pdf/156780/en.subject.pdf)

### AI usage

Claude (claude.ai) was used during this project for:

- Debugging specific bugs (missing `break` in `switch`, uninitialized pointers, double `malloc` without `free`)
- Understanding the difference between `%d` / `%i` and `%u`
- Understanding why `%p` requires `unsigned long` instead of `unsigned int`
- Writing and iterating on test cases to compare `ft_printf` output and return values against the standard `printf`
- Advice on code structure (splitting handlers into separate functions, returning character counts)

All code was written and understood by the student. AI was used as a reference and debugging tool, not to generate final implementations.
