# COP1220 Programming in C

Standalone C programs covering input and output, conditions, loops, functions, arrays, strings, structures, and file input.

| Assignments | Topics |
| --- | --- |
| [1-1](assignment%201-1.c) and [1-2](assignment%201-2.c) | Console input and output. |
| [2-1](assignment%202-1.c) | Message length validation. |
| [2-2](assignment%202-2.c) and [3-2](assignment%203-2.c) | Hurricane classification. |
| [2-3](assignment%202-3.c) and [3-1](assignment%203-1.c) | Perfect numbers. |
| [2-4](assignment%202-4.c), [4-1](assignment%204-1.c), and [7-1](assignment%207-1.c) | Sales totals using variables, arrays, and structures. |
| [4-2](assignment%204-2.c) | Temperature trends and averages. |
| [6-1](assignment%206-1.c) and [6-2](assignment%206-2.c) | Pig Latin and Caesar cipher. |
| [8-1](assignment%208-1.c) | Home Sales v4.0 with file input. |

The [pseudocode](pseudocode/) folder contains program outlines.

## Compile and run

Requires a C compiler. Each `.c` file is a separate program:

```sh
cc "assignment 6-2.c" -o caesar
./caesar
```

`assignment 8-1.c` requires `salesdata.txt` in the working directory; the input file is not included.
