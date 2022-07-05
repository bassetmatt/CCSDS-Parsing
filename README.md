# CCSDS-Parsing
A small lib to parse CCSDS packages in C <br>

## Repo organisation
- Root folder: Basic files, license, this Readme, etc..
- `library/`: source files of the library.
- `include/`: headers for the library, maybe planning on making them exportable to `/usr/local/include` later.
- `doc/`: documentation for the library. HTML format, open it with any web browser. Style to work on.

## Build
For a common build, while in the root folder, make a build folder and go into it:
```bash
mkdir build && cd build
```
Initialise CMake
```bash
cmake .. 
```
And build the project
```bash
make ccsdsParse
```
The result shall be at `build/library/libccsdsParse.a`<br>
***Note***: *you must have* `make` *and* `cmake` *installed on your computer*.
