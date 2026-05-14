# Img-to-Ascii
C++ Program used to convert an image to an ASCII representation of said image.

## Environment Setup

### Fedora Linux
1. Install the required dependencies:
   ```bash
   sudo dnf install gcc-c++ cmake opencv-devel opencv
   ```
2. Clone or download the repository
3. Build the project:
   ```bash
   make
   ```
4. Run the program:
   ```bash
   ./toAscii -h
   ```

### Windows
1. Install the required dependencies:
   - **C++ Compiler**: Install [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) with C++ development tools, or use MinGW-w64
   - **OpenCV**: 
     - Download from [opencv.org](https://opencv.org/releases/)
     - Build from source or use precompiled binaries
     - Set OpenCV path in your build configuration
   - **CMake**: Install from [cmake.org](https://cmake.org/download/) (optional, for easier builds)

2. Clone or download the repository

3. Build the project:
   - Using Visual Studio: Open the project and build with the OpenCV include/lib paths configured
   - Using MinGW: Compile with appropriate OpenCV linker flags
   ```bash
   g++ -o toAscii toAscii.cpp `pkg-config --cflags --libs opencv4`
   ```

4. Run the program:
   ```bash
   toAscii.exe -h
   ```

## Usage
Currently a command line program while I implement more changes. Makefile is created for a linux based distribution\
`./toAscii -h` - Used to show help in console\
`./toAscii [FileName] [Scale]` - Normal usecase.
### Arguments
`[Filename]` - The path to the image file to be converted\
`[Scale]` - The square size of pixels to convert to 1 ascii character. For example, if a scale of 2 is chosen, then the image value will be calculated in 2x2 squares of pixels, so 4 pixels will be con[...]

## Limitations
Currently best used for high contrast images with a dark background. This is due to the use of value based calculations, so it's simply checking the brightness of each pixel set and assigning an Ascii[...]
