cmake_minimum_required(VERSION 3.16)
project(HelloCv)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgcodecs opencv_highgui opencv_imgproc opencv_calib3d opencv_features2d)

add_executable(HelloCv main.cpp)

target_link_libraries(HelloCv ${OpenCV_LIBS})
