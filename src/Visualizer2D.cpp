#include "../inc/Visualizer2D.h"

using namespace cimg_library;
using namespace std;

Visualizer2D::Visualizer2D(const int width, const int height, const int refreshTime) :
	Visualizer(width,height,refreshTime)
{
	// Intentionally NOOP
}

void Visualizer2D::displayObjects(){
	CImgList<float> scPrimitives;
	this->visualizer.fill(0);
	for_each(
		objects.cbegin(),
		objects.cend(),
		[this,&scPrimitives](const DrawableObject<2>* obj){
			obj->draw(this->visualizer,scPrimitives);
		}
	);
	this->visualizer.display(display);
}
