#include "../inc/Visualizer3D.h"

using namespace cimg_library;
using namespace std;

Visualizer3D::Visualizer3D(const int width, const int height, const int refreshTime) :
	Visualizer(width,height,refreshTime)
{
	// Intentionally NOOP
}

void Visualizer3D::displayObjects(){
	CImg<float> scPoints;
	CImgList<float> scPrimitives;
	for_each(
		objects.cbegin(),
		objects.cend(),
		[this,&scPoints,&scPrimitives](const DrawableObject<3>* obj){
			obj->draw(scPoints,scPrimitives);
		}
	);
	CImgList<> opacities(scPrimitives.size(),CImg<>::vector(1.0f));

	visualizer.fill(230,230,255).draw_object3d(
		displayWidth/2.0,
		displayHeight/2.0,
		0.0,
		scPoints,
		scPrimitives,
		colors,
		opacities
	).display(display);
}
