# Img-to-Ascii
C++ Program used to convert an image to an ASCII representation of said image.

## Usage
Currently a command line program while I implement more changes. Makefile is created for a linux based distribution\
`./toAscii -h` - Used to show help in console\
`./toAscii [FileName] [Scale]` - Normal usecase.
### Arguments
`[Filename]` - The path to the image file to be converted\
`[Scale]` - The square size of pixels to convert to 1 ascii character. For example, if a scale of 2 is chosen, then the image value will be calculated in 2x2 squares of pixels, so 4 pixels will be converted to 1 ascii character.

## Limitations
Currently best used for high contrast images with a dark background. This is due to the use of value based calculations, so it's simply checking the brightness of each pixel set and assigning an Ascii character to each one based on that. Thus, very bright images will struggle to be converted in a visually pleasing way. I plan on implementing shape based conversion eventually, though that is a project in of itself.
