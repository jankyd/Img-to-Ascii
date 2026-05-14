# Img-to-Ascii
C++ Program used to convert an image to an ASCII representation of said image.

## Environment Setup

### Linux
1. Install the required dependencies:
   ```bash
   sudo dnf/apt install gcc-c++ cmake opencv-devel opencv
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

## Usage
Currently a command line program while I implement more changes. Makefile is created for a linux based distribution\
`./toAscii -h` - Used to show help in console\
`./toAscii [Process method] [FileName] [Scale]` - Normal usecase.
### Arguments
`[Process method]` - A choice between edge-based processing and pure value-based processing.\
   - `-e` - Edge based
   - `-v` - Value based
<!-- -->
`[Filename]` - The path to the image file to be converted\
`[Scale]` - The square size of pixels to convert to 1 ascii character. For example, if a scale of 2 is chosen, then the image value will be calculated in 2x2 squares of pixels, so 4 pixels will be converted to 1 ascii character.

## Limitations
Struggles with high-fidelity images. Best used for high contrast 
