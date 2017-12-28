#include "../inc/Box.h"

Box::Box(
	const double xmin,
	const double ymin,
	const double zmin,
	const double xmax,
	const double ymax,
	const double zmax
):
	xmin(xmin),
	xmax(xmax),
	ymin(ymin),
	ymax(ymax),
	zmin(zmin),
	zmax(zmax)
{
	// Intentionally NOOP
}

Box::~Box(){
	// Intentionally NOOP
}

void Box::draw(cimg_library::CImg<unsigned char>& image) const{
	unsigned char yellow[] = {255,215,0};
	unsigned char black[] = {0,0,0};
	image.draw_rectangle(
		(int)this->xmin,
		(int)this->ymin,
		(int)this->xmax,
		(int)this->ymax,
		yellow,
		1.0,
		0xFFFFFFFF
	);
}
