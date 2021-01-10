# ft_printf

```C
int ft_printf(const char *, ...);
```

1) getting number of args by reading the string
2) Testing if it equals to the number of given arguments
3) 



## Convertions :

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

## Flags :
| Type character |
| --- |
| `-` |
| `0` |
| `.` |
| `*` |
