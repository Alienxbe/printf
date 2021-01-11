# ft_printf

```C
int ft_printf(const char *, ...);
```

## Conversion Specification

Usage : 
> %[[flags](#flags-directives)][[width](#width-specification)][[.precision](#precision-specification)][type](#type-conversion-specifier)


### Type conversion specifier

| Format specifier | Suitable type | Output format |
| --- | --- | --- |
| `c` | `char` | Single-bytes charcater. | 
| `p` | `Pointer type` | Address in hexadecimal digits. |
| `d` | `int` | Signed decimal integer. |
| `i` | `int` | Signed decimal integer. | 
| `u` | `unsigned int` | Unsigned decimal integer. |
| `x` | `unsigned int` | Unsigned hexadecimal integers (using "`abcdef`"). |
| `X` | `unsigned int` | Unsigned hexadecimal integers (using "`ABCDEF`"). |
| `%` | `NONE` | Display the `%` character |

### Flags directives
| Flag | Description |
| --- | --- |
| `-` | Left justify |
| `0` | Pad with leading `0` |

### Width specification

### Precision specification

## Sources

+ [Microsoft documentation](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions)

## Licenses & copyright

© Ykman Martin, School 19
