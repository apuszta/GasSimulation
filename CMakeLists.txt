cmake_minimum_required(VERSION 3.9)
project(GasSimulation)

file(GLOB SOURCES src/*.cpp)

SET("OpenCV_DIR" "/home/adrian/Third-Party/OpenCV/opencv-3.3.1/built")
find_package(OpenCV REQUIRED)

SET("Eigen_DIR" "/home/adrian/Third-Party/Eigen/eigen")
find_package(Eigen3 REQUIRED NO_MODULE)

SET("CImg_DIR" "/home/adrian/Third-Party/CImg")
#find_package(CImg REQUIRED)

include_directories( ${CImg_DIR})
add_executable(GasSimulation ${SOURCES} main.cpp)
target_link_libraries(GasSimulation ${OpenCV_LIBS} Eigen3::Eigen)
