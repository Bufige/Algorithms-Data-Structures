# 1. Introduction
All projects or exercises about the classes: programming languages 1&amp;2 and data structures 1&amp;2.



# 2. List of every algorithm or data structure i have done so far


- [x] Queue
- [x] Stack
- [x] Array
- [x] Common sorting algorithms such as : bubble sort, seletion sort, insertion sort, quick sort and merge sort.
- [x] Common searching algorithms such as: linear search and binary search.


# 3. Makefile/Compiling:


Will check if the setup is configured, if not, it will make a new setup by calling "make dir" and compile. it calls "make all" internally.

```
make
```

will make all the working directories. You can do this manually or it will do automatically if you use make.
```
make dir
```

will make clean the working directory, will delete all the files contained in bin and docs.
```
make clean
```

will  make the documentation for the current project.
```
make doxy
```

will call make clean and make dir.
```
make fresh
```