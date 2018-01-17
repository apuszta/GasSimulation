#include "inc/Dummy.h"
#include "inc/Particle.h"
#include "inc/Box.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace cimg_library;

int main(){
	/*
	* 2D section
	*/
	Particle<2> particle2d(1,5,-1);
	particle2d.setPos(Eigen::Vector3d(50,120,0));
	cout << "particle weight: " << particle2d.getWeight() << endl;

	// display 2 yellow rectangles
	Box<2> b1(10,10,10,100,200,30);
	Box<2> b2(40,50,30,170,250,150);

	CImg<float> img(600,600,1,3);
	img.fill(0);
	CImgDisplay disp(600,600,"Test display",0,false, false);

	CImgList<float> primitives2d;
	b1.draw(img,primitives2d);
	b2.draw(img,primitives2d);
	particle2d.draw(img,primitives2d);

	img.display(disp);

	/*
	* 3D section
	*/
	Particle<3> particle3d(1,10,1);
	particle3d.setPos(Eigen::Vector3d(80,40,60));
	Box<3> box1(-100,-100,-100,100,100,100);
// 	Box<3> box2(40,50,30,170,250,150);
	CImg<float> scPoints;
	CImgList<float> scPrimitives;
	box1.draw(scPoints,scPrimitives);
// 	box2.draw(scPoints,scPrimitives);
	particle3d.draw(scPoints,scPrimitives);
	const CImg<unsigned char> visu = CImg<unsigned char>(3,512,512,1).fill(230,230,255).permute_axes("yzcx");
	visu.display_object3d("scene",scPoints,scPrimitives);

	while(!disp.is_closed()){
		disp.wait(50);
	}
	return 0;
}
