# Library for interfacing with Obj-C on MacOS in pure C

## Building
```
$ cd prac
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cmake --install .
```
The last step is optional - it will install the headers into `/usr/local/include/NSObjects/` and will install the library file to `/usr/local/lib/libobjc.a`

To use the library, just include `<NSObjects/NSBase.h>`
