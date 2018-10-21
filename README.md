# Binary Search Tree

## Introduction

As requested by our professor at the subject Basic Data Structure 2 ([EDB2](https://sigaa.ufrn.br/sigaa/public/departamento/componentes.jsf)), at Federal University of Rio Grande do Norte ([UFRN](https://ufrn.com.br)), we shall implement a binary search tree, which is described [here](https://en.wikipedia.org/wiki/Binary_search_tree). Not only that, we must also add some useful methods, besides the standards ones, which are:
+ `nthElement()` - Returns the nth element of a tree (indexing by 1) from in-order visitation method.
+ `position()` - Returns the element of a given position (relative to in-order method & indexed by 1).
+ `median()` - Returns the element that has the median of the tree.
+ `isFull()` - Returns a `boolean` value telling if the binary tree is a full tree.
+ `isComplete()` - Returns a `boolean` value telling if the binary tree is a complete tree.
+ `toString()` - Returns a string containing the visitation sequence by level.

## Instructions
By default, this program will recieve two files:
+ Keys file
A file that will generate the initial tree, all separated by spaces, i.e.:
```
12 30 50 10 11 5 30 90
```

+ Commands file
A file containing commands, one on each line, some of them needs args, you can put them by a single space, i.e.:
```
CHEIA
ENESIMO 10
INSIRA 22
IMPRIMA
```

### Supported commands
In this version, we will support the following commands:
+ `ENESIMO N` - Will return the nth element on the in-order representation of the binary search tree.
+ `POSICAO N` - Will return the position that the element is on a in-order representation of the binary search tree.
+ `MEDIANA`- Will return the median of an in-order representation of a binary search tree.
+ `CHEIA` - Will tell if the tree is a full tree (All empty nodes are on the `last` level).
+ `COMPLETA` - Will tell if the tree is a complete tree (All empty nodes are on the `last` or `last-1` levels).
+ `IMPRIMA` - Will return the binary search tree represented by level.
+ `REMOVA N` - Will remove key `N` from the binary search tree.
+ `INSIRA N` - Will insert key `N` into the binary search tree.



## TODO

- [x] Node Struct
- [ ] Bst methods
- [x] Main.cpp organization
- [x] Makefile/CmakeLists
- [x] InputFile reading
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
