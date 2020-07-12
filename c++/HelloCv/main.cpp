#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "Hello, Opencv " << cv::getVersionString() << std::endl;

    cv::Mat img;
    img = cv::imread("../cat.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cout << "Image load failed!" << std::endl;
        exit(1);
    }

    cv::imwrite("../cat_gray.png", img);
    cv::namedWindow("image");
    cv::imshow("image", img);
    cv::waitKey();


    return 0;
}
