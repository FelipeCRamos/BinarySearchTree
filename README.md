# Binary Search Tree

## Introduction

As requested by our professor at the subject Basic Data Structure 2 ([EDB2](https://sigaa.ufrn.br/sigaa/public/departamento/componentes.jsf)), at Federal University of Rio Grande do Norte ([UFRN](https://ufrn.com.br)), we shall implement a binary search tree, which is described [here](https://en.wikipedia.org/wiki/Binary_search_tree). Not only that, we must also add some useful methods, besides the standards ones, which are:
+ `nthElement()` - Returns the nth element of a tree (indexing by 1) from in-order visitation method.
+ `position()` - Returns the element of a given position (relative to in-order method & indexed by 1).
+ `median()` - Returns the element that has the median of the tree.
+ `isFull()` - Returns a `boolean` value telling if the binary tree is a full tree.
+ `isComplete()` - Returns a `boolean` value telling if the binary tree is a complete tree.
+ `toString()` - Returns a string containing the visitation sequence by level.

## TODO

- [x] Node Struct
- [ ] Bst methods
- [ ] Main.cpp organization
- [x] Makefile/CmakeLists
- [ ] InputFile reading
- [ ] Doxygen Documentation ***SuperLowPriority***

## Compilation

1. In order to compile, some dependencies are required:
+ `make`
+ `GCC` 
2. Clone the repository onto your computer and run on terminal:
```bash
make
```
3. Run the program with:
```bash
./bintree [data-file] [command-file]
# ex: ./bintree data/binary-tree.txt commands-set.txt
```

## Authorship

Programs developed by [_Daniel Guerra_](https://github.com/Codigos-de-Guerra)  and [_Felipe Ramos_](https://github.com/FelipeCRamos), on 2018.2

Licensed under **MIT License**
