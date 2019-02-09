#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
    const int thickness = 3;
    VideoCapture cap;
    cap.open(0);
    if(!cap.isOpened()) {
       return -1;
    }

    namedWindow("Color Video", WINDOW_AUTOSIZE);
    namedWindow("Grayscale Video", WINDOW_AUTOSIZE);

    for(;;) {
        Mat frame;
        Mat grayscale;

        cap >> frame;

        line(frame, Point(0,0), Point(frame.cols, frame.rows), Scalar(255,0,0), thickness);
        line(frame, Point(0,frame.rows), Point(frame.cols, 0), Scalar(255,0,0), thickness);

        cvtColor(frame, grayscale, COLOR_RGB2GRAY);

        imshow("Color Video", frame);
        imshow("Grayscale Video", grayscale);

        if(waitKey(30) >= 0) {
            break;
        }

    }

    cap.release();
    return EXIT_SUCCESS;
}

