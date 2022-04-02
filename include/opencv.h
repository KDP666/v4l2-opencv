#ifndef CV_H
#define CV_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

class Opencv{
    public:
        Opencv(unsigned char*, int width, int height);
        ~Opencv();
        void image_write(void);
        void rgb2gray(void);

    private:
        Mat image; 

};

#endif
