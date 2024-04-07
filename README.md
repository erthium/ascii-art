# ASCII Art

Image to ASCII converter with C++ and SFML. 

Main idea is to be able accept any kind of 2D array that holds pixel data and give a similar output, and be able to save the output as an image or video.

## License

This project is licensed under the [GNU GPL-3.0](https://github.com/ErtyumPX/ascii-art/blob/main/LICENSE) license.

Feel free to use the source code. Referring to the repository would be very much appreciated.

## Setup

Project is currently compiled with `GNU G++ 13.2.1`.

The only third-party dependency is `SFML2`. Used version of SFML in project is `2.6.1`.

SFML was selected because of it's ease of use for text rendering with sizes being all agjusted in pixels.

For compiling and linking rules `GNU Make 4.4.1` was used. After downloading dependencies, make sure to change the include paths inside the Makefile.

```
# change the paths for '-I' 
CC := g++
CFLAGS := -Wall -std=c++11 -I/usr/include/SDL2           # here
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
...
```

After fulfilling dependencies, download or clone the project and use Makefile to easily compile:

```
> make run
```

Since SFML is a cross-platform media library, output should work on Windows, MacOS and Linux.

## General Structure

### Directory Structure and Files

- `src/` directory contains the source code
  - `src/main.cpp` is the entry point of the program
  - `src/converter.hpp` contains the declarations of the core converter class
  - `src/converter.cpp` contains the implementation of core methods
- `stable/` directory contains the stable output
  - `stable/ascii.art` is the executable

### How It Goes

Will be updated soon.
