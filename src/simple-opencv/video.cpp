#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
    VideoCapture cap;
    cap.open(0);
    if(!cap.isOpened()) {
       return -1;
    }

    namedWindow("Video",1);
    for(;;) {
        Mat frame;
        cap >> frame;

        imshow("Video", frame);


        if(waitKey(30) >= 0) {
            break;
        }

    }

    return EXIT_SUCCESS;
}

