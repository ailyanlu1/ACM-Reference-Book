# ACM Reference Book Generator

## Overview
It generates a pdf file using Latex. `combine` is written in C++ and it is used to traverse recursively in the `src` folder containing multiple C++ files using Boost C++ libraries.

## Folder structure vs Latex structure
\- src
|
\-\-\- Graph                                 \section{Geometry}
&nbsp&nbsp&nbsp&nbsp|
&nbsp&nbsp&nbsp&nbsp\-\-\- Dijkstra.cpp          \subsection{Dijkstra}
&nbsp&nbsp&nbsp&nbsp\-\-\- Floyd.cpp          \subsection{Floyd}

## Requirements
- C++17
- Boost C++ Libraries
- xelatex

## Usage
To generate the reference book:
``` bash
make
```

To clean the directory:
``` bash
make clean
```
**Note**: It will delete the resulting pdf as well.