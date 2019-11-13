#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void) {
    double alpha = 0.5;
    double beta;
    double input;

    Mat src1, src2, dst;

    cout << " Simple Linear Blender " << endl;
    cout << "-----------------------" << endl;
    cout << "* Enter alpha [0-1]: ";
    cin >> input;

    // We use the alpha provided by the user if it is between 0 and 1
    if (input >= 0 && input <= 1) { alpha = input; }

    src1 = imread("./eo.bmp", CV_LOAD_IMAGE_COLOR);
    src2 = imread("./ir.bmp", CV_LOAD_IMAGE_COLOR);

    if (src1.empty()) {
        cout << "Error loading src1" << endl;
        return -1;
    }
    if (src2.empty()) {
        cout << "Error loading src2" << endl;
        return -1;
    }

    beta = (1.0 - alpha);
    addWeighted(src1, alpha, src2, beta, 0.0, dst);

    imshow("Linear Blend", dst);
    imshow("EO", src1);
    imshow("IR", src2);
    waitKey(0);

    return 0;
}