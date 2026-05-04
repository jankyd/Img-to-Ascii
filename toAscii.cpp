#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
// Ascii list - High to low value
std::string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

/**
 * Function to convert the average 'value' (brightness) of a
 * square group of pixels with side length of scale
 * @param image The image Mat struct
 * @param row, col The array index of the image to get the value of
 * @param scale The square amount of pixels to estimate (scale X scale)
 */
int avgValue(Mat image, int row, int col, int scale) {
    int sum = 0;
    int pixelCnt = 0;
    int r = row;
    int c = col;

    while (r <= row + scale && r < image.rows) {
        while (c  <= col + scale && c < image.cols) {
            sum +=(int)image.at<uchar>(r,c);
            pixelCnt++;
            c++;
        }
        r++;
    }
    return sum / pixelCnt;
}


int main(int argc, char* argv[]) {
    if (argc <= 1 || argc >= 4) {
        std::cout << "Usage: toAscii [Image file] [Pixel Scale] OR toAscii -h" << std::endl;
    }
    
    else {
        std::string fileName = argv[1];
        if (fileName == "-h" || fileName == "-H") {
            std::cout << "toAscii: A program to convert an image file to Ascii Art." << std::endl;
            std::cout << "Usage: toAscii [Image File Path] [Pixel Scale]" << std::endl;
            std::cout << "Where: \n[Image File Path] == The path to your Image" << std::endl;
            std::cout << "[Pixel Scale] == The square amount of pixels to convert to 1 ascii char" << std::endl;
            std::cout << "  (IE scale = 2 means 2x2 pixels converted to 1 Ascii char)" << std::endl;
            return 0;
        }
        int scale =atoi(argv[2]);
        Mat img = imread(fileName);
        // empty image handling
        if (img.empty()) {
            std::cout << "ERROR: Problem opening file. Check path and try again." << std::endl;
            return 1;
        }
        Mat grayScale;
        cvtColor(img, grayScale, COLOR_BGR2GRAY);
        



    } 
    return 0;
}