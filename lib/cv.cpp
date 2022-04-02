#include "opencv.h"

Opencv::Opencv(unsigned char* char_mat, int w, int h){
    Mat yuv(h, w ,CV_8UC2,char_mat);
    cvtColor(yuv, image, COLOR_YUV2BGR_YUYV);
}

Opencv::~Opencv(){

}

void Opencv::image_write(){
    imwrite("test.jpg",image);
}

void Opencv::rgb2gray(){
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imwrite("test.jpg",gray);
}
