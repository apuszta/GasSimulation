cmake_minimum_required(VERSION 3.9)
project(GasSimulation)

file(GLOB_RECURSE SOURCES src/*.cpp)

SET("OpenCV_DIR" "/home/adrian/Third-Party/OpenCV/opencv-3.3.1/built")
find_package(OpenCV REQUIRED)

SET("Eigen_DIR" "/home/adrian/Third-Party/Eigen/eigen")
find_package(Eigen3 REQUIRED NO_MODULE)

SET("CImg_DIR" "/home/adrian/Third-Party/CImg")
#find_package(CImg REQUIRED)

SET("CppOnnector_DIR" "/home/adrian/projects/C++Onnector/C++Onnector/inc")

SET(GCC_LINKAGE_FLAGS "-lpthread -lX11 -W -Wall -g -DENABLE_CPPO_SAFETY -DCPPO_NO_FLAG_WARNINGS")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_LINKAGE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_CXX_FLAGS}")

include_directories(${CImg_DIR})
include_directories(${CppOnnector_DIR})
add_executable(GasSimulation ${SOURCES} main.cpp)
target_link_libraries(GasSimulation ${OpenCV_LIBS} Eigen3::Eigen)
