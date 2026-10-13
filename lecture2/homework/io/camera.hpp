#ifndef L2_CAMERA_HPP
#define L2_CAMERA_HPP

#include "hikrobot/include/MvCameraControl.h"
#include <opencv2/opencv.hpp>

//函数声明
class Camera
{
    public:
        Camera(); //构造函数
        ~Camera();//析构函数
        bool read(cv::Mat & img);   //read函数

    private:
        void* handle_=nullptr;
        bool grabbing_=false;
        bool open_=false;
    
};


#endif 