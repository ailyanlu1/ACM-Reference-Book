# ACM Reference Book Generator

## Overview
It generates a pdf file using Latex. `combine` is written in C++ and it is used to traverse recursively in the `src` folder containing multiple C++ files using Boost C++ libraries.

## Folder structure vs Latex structure
```
- src
   |
   |--- Graph                        \section{Graph}
          |--- Dijkstra.cpp          \subsection{Dijkstra}
          |--- Floyd.cpp             \subsection{Floyd}

   |--- Geometry                     \section{Geometry}
          |--- ConvexHull.cpp        \subsection{Convex Hull}


```
**Note**: When the filename has more than on captial letters, automatically add spaces when adding to latex file.

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
