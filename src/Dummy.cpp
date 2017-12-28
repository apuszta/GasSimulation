#include "../inc/Dummy.h"

#include <CImg.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// #include <Eigen/Core>

#include <iostream>

using namespace std;
// using namespace Eigen;

Dummy::Dummy(){

}

void Dummy::doSomething(){
	cout << "I'm doing something." << endl;
	cv::Mat mat = cv::Mat(1000,1000,CV_8UC1);
	cv::randu(mat, cv::Scalar::all(0), cv::Scalar::all(255));
	cv::imshow("matrix",mat);
	cv::waitKey(0);
	cout << "key pressed" << endl;
}

void Dummy::foo(){
// 	Vector2d a(5.0, 4.0);
// 	Vector2d b(8.0, 1.0);
// 	cout << (a+b) << endl;
}
