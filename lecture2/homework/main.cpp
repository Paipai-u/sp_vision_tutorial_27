#include "io/camera.hpp"
#include "tasks/yolo.hpp"
#include "opencv2/opencv.hpp"
#include "tools/img_tools.hpp"

int main()
{
    // 初始化相机、yolo类
    Camera camera;
    auto_aim::YOLO yolo("./configs/yolo.yaml");
    
    
     while (1) {
        cv::Mat img;
        // 调用相机读取图像
        if (!camera.read(img))
        {
            break;//未找到图像则不处理
        }

        // 调用yolo识别装甲板
        auto armors=yolo.detect(img);

        //画图
        for(const auto & armor : armors)//一张图中可能有多个装甲板
        {
            tools::draw_points(img,armor.points,cv::Scalar(0, 255, 0));
        }

        // 显示图像
        cv::resize(img, img , cv::Size(640, 480));
        cv::imshow("img", img);
        if (cv::waitKey(0) == 'q') {
             break;
         }
     }

    return 0;
}