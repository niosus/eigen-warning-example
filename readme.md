# This illustrates a warning I get with Eigen

When building relatively simple code with `g++` I get a strange warning that I cannot decipher. The version of my GCC compiler:
```
g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Version of Eigen: 3.3.4
```c++
#define EIGEN_WORLD_VERSION 3
#define EIGEN_MAJOR_VERSION 3
#define EIGEN_MINOR_VERSION 4
```

### Build the code

A short way to reproduce the issue is to just build the code from the terminal:
```bash
cd eigen_example
g++ -I/usr/include/eigen3 -O3 example.cpp
```

Alternatively, build it with cmake:
```bash
cd eigen_example
mkdir build
cd build
cmake ..
make
```

### I am getting the following warning:

<details>
<summary>Verbose warning</summary>

```
[ 50%] Building CXX object CMakeFiles/example.dir/example.cpp.o
In file included from /usr/include/eigen3/Eigen/Core:349:0,
                 from /home/igor/Code/eigen_example/example.cpp:3:
In function ‘void* Eigen::internal::aligned_malloc(std::size_t)’,
    inlined from ‘void std::vector<_Tp, _Alloc>::_M_realloc_insert(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {float, float, float}; _Tp = Eigen::Matrix<float, 3, 1>; _Alloc = Eigen::aligned_allocator<Eigen::Matrix<float, 3, 1> >]’ at /usr/include/eigen3/Eigen/src/Core/util/Memory.h:742:76:
/usr/include/eigen3/Eigen/src/Core/util/Memory.h:159:12: warning: argument 1 value ‘18446744073709551612’ exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
     result = std::malloc(size);
     ~~~~~~~^~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/7/bits/std_abs.h:38:0,
                 from /usr/include/c++/7/cmath:47,
                 from /usr/include/c++/7/complex:44,
                 from /usr/include/eigen3/Eigen/Core:80,
                 from /home/igor/Code/eigen_example/example.cpp:3:
/usr/include/stdlib.h: In member function ‘void std::vector<_Tp, _Alloc>::_M_realloc_insert(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {float, float, float}; _Tp = Eigen::Matrix<float, 3, 1>; _Alloc = Eigen::aligned_allocator<Eigen::Matrix<float, 3, 1> >]’:
/usr/include/stdlib.h:539:14: note: in a call to allocation function ‘void* malloc(size_t)’ declared here
 extern void *malloc (size_t __size) __THROW __attribute_malloc__ __wur;
              ^~~~~~
In file included from /usr/include/eigen3/Eigen/Core:349:0,
                 from /home/igor/Code/eigen_example/example.cpp:3:
In function ‘void* Eigen::internal::aligned_malloc(std::size_t)’,
    inlined from ‘void std::vector<_Tp, _Alloc>::_M_realloc_insert(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {float, float, float}; _Tp = Eigen::Matrix<float, 3, 1>; _Alloc = Eigen::aligned_allocator<Eigen::Matrix<float, 3, 1> >]’ at /usr/include/eigen3/Eigen/src/Core/util/Memory.h:742:76:
/usr/include/eigen3/Eigen/src/Core/util/Memory.h:159:12: warning: argument 1 value ‘18446744073709551612’ exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
     result = std::malloc(size);
     ~~~~~~~^~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/7/bits/std_abs.h:38:0,
                 from /usr/include/c++/7/cmath:47,
                 from /usr/include/c++/7/complex:44,
                 from /usr/include/eigen3/Eigen/Core:80,
                 from /home/igor/Code/eigen_example/example.cpp:3:
/usr/include/stdlib.h: In member function ‘void std::vector<_Tp, _Alloc>::_M_realloc_insert(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {float, float, float}; _Tp = Eigen::Matrix<float, 3, 1>; _Alloc = Eigen::aligned_allocator<Eigen::Matrix<float, 3, 1> >]’:
/usr/include/stdlib.h:539:14: note: in a call to allocation function ‘void* malloc(size_t)’ declared here
 extern void *malloc (size_t __size) __THROW __attribute_malloc__ __wur;
              ^~~~~~
[100%] Linking CXX executable example
[100%] Built target example
```

</details>
