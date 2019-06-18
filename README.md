# HPC | Source Code C
[![GitHub tag (latest SemVer)](https://img.shields.io/github/tag/lialkaas/hello-c.svg)](CHANGELOG.md)
![GitHub last commit](https://img.shields.io/github/last-commit/lialkaas/hello-c.svg)
[![GitHub](https://img.shields.io/github/license/lialkaas/hello-c.svg)](LICENSE.md)

>_"Oh say, can you C?"_

A storage of Source Code bits and pieces written in C for HPC.

## Description
Files are structured into directories, according to the level of complexity, origin and purpose.

- __primer/__ - examples and exercises from C Primer Plus (6th)
- __finance/__ - quantitative finance apps and models
- __math/__ - applied mathematics apps: number theory, linear algebra, complex nums, etc.
- __other/__ - all other stuff, that does not belong to any category


## Clone, Compile, Run
To make the source code executable, you need to compile it first. Source code follows C11 standard, make sure your compiler is up to date (or at least C99).

__Sympathetic advice__: inspect the source code before compiling and, god forbid, running it. Remember, C does not forgive mistakes. If it breaks your OS, it's not my fault. I warned you.

Clone repository
```bash
git clone https://github.com/lialkaas/hello-c.git
```

Navigate to the folder in Terminal
```bash
cd ~/hello-c
```

Compile Source code into executable. Likely, in UNIX system _cc_ stands for alias of installed compiler. If not, call the name of your compiler directly (e.g. gcc, clang, etc.)
```bash
cc filename.c -o filename.out
```

Note: some SC files have math function _pow()_, which sometimes fails to compile correctly. Append command with _-lm_ flag
```bash
cc filename.c -o filename.out -lm
```

Finally, run executable _*.out_ by calling it
```bash
./filename.out
```


## License and Copyright
Copyright (c) 2019 Oleksii Lialka

Licensed under the [MIT License](LICENSE.md).
