#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
// Ascii list - High to low value
std::string asciiScale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

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

/**
 * Prints out the ascii art line by line using value based processing
 */
void valuePrint(Mat image, int scale) {
    // Read image line by line (scale x scale sized blocks)
    // Then print out each line
    for (int i = 0; i < image.rows; i+=scale) {
        std::string text = "";
        for (int j = 0; j < image.cols; j+=scale) {
            int pixel = avgValue(image, i, j, scale);
            // Get the pixel based on the ascii scale
            text += asciiScale[ceil((asciiScale.length() - 1) * pixel /255)];
            text += asciiScale[ceil((asciiScale.length() - 1) * pixel /255)];
        }

        std::cout << text << std::endl;
    }
    return;
}

/**
 * Takes a brightness value and converts it to an ascii character based on the following high to low scale:
 * $@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. 
 */
char valueToChar(int value) {
    return asciiScale[ceil((asciiScale.length() - 1) * value /255)];
}

void edgeProcessing(Mat image, int scale) {
    Mat edgeImg;
    GaussianBlur(image, edgeImg, Size(3,3), 0);
    Mat edgeX, edgeY;
    // Get the edge function data
    Sobel(edgeImg, edgeX, CV_32F, 1, 0, 3);
    Sobel(edgeImg, edgeY, CV_32F, 0, 1, 3);
    // create the polar coordinates for the edge function data (magArray == magnintude, angleArray == angle)
    Mat magArray, angleArray;
    cartToPolar(edgeX, edgeY, magArray, angleArray, true); // NOTE: the last true makes it degree based, not radians (0-360)
    // Get the total average magnitude
    Scalar avgMag = mean(magArray);
    float magThreshold = avgMag[0] * 1.5; // NOTE: Adjust as needed for results
    
    for (int i = 0; i < image.rows; i+=scale) {
        std::string text = "";
        for (int j = 0; j < image.cols; j+=scale) {
            Rect block(i, j, scale, scale);
            Mat magRect = magArray(block);
            Mat angRect = angleArray(block);

            float meanMag = mean(magRect)[0];
            float meanAng = mean(angRect)[0];
            // If magnatude is greater than the threshhold, do edge process
            if (meanMag >= magThreshold) {

            }
            // else do value based
            else {
                text += valueToChar(avgValue(image, i, j, scale)); //NOTE: may have to do twice for aspect reasons?
            }
        }
    }

}


int main(int argc, char* argv[]) {
    if (argc <= 1 || argc >= 5) {
        std::cout << "Usage: toAscii [Processing Type] [Image file] [Pixel Scale] OR toAscii -h" << std::endl;
        return 0;
    }
    
    else {
        std::string callOption = argv[1];
        if (callOption == "-h" || callOption == "-H") {
            std::cout << "\ntoAscii: A program to convert an image file to Ascii Art." << std::endl;
            std::cout << "Usage: toAscii [Proccessing Type] [Image file] [Pixel Scale]" << std::endl;
            std::cout << "\nWhere:\n[Processing Type] == Either -v OR -e. -v uses Value (brightness) based processing, and -e uses edge based processing" << std::endl;
            std::cout << "  Value based processing is low-fidelity but low-intensity. Edge based is higher fidelity but more resource intensive" << std::endl;
            std::cout << "[Image File Path] == The path to your Image" << std::endl;
            std::cout << "[Pixel Scale] == The square amount of pixels to convert to 1 ascii char" << std::endl;
            std::cout << "  (IE scale = 2 means 2x2 pixels converted to 1 Ascii char)" << std::endl;
            return 0;
        }
        else if (argc <= 3) {
            std::cout << "Usage: toAscii [Processing Type] [Image file] [Pixel Scale] OR toAscii -h" << std::endl;
            return 0;
        }
        int scale = atoi(argv[3]);
        Mat img = imread(argv[2]);
        // empty image handling
        if (img.empty()) {
            std::cout << "ERROR: Problem opening file. Check path and try again." << std::endl;
            return 1;
        }
        Mat grayScale;
        cvtColor(img, grayScale, COLOR_BGR2GRAY);
        
        // Enhance contrast using histogram equalization
        if (callOption == "-v" || callOption == "-V") {
            equalizeHist(grayScale, grayScale);
            valuePrint(grayScale, scale);
        }
        else if (callOption == "-e" || callOption == "-E") {
            //TODO: edgeProcessing();
        }
        else {
            std::cout << "ERROR: Unknown processing option. Use ToAscii -h for help." << std::endl;
            return 1;
        }

    } 
    return 0;
}