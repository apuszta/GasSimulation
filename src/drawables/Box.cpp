#include "../../inc/drawables/Box.h"

template<size_t Dim>
Box<Dim>::Box(
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

template<size_t Dim>
Box<Dim>::Box(const Box<Dim>& other) :
	xmin(other.xmin),
	xmax(other.xmax),
	ymin(other.ymin),
	ymax(other.ymax),
	zmin(other.zmin),
	zmax(other.zmax)
{
	// Intentionally NOOP
}

template<size_t Dim>
Box<Dim>::~Box(){
	// Intentionally NOOP
}

template<size_t Dim>
double Box<Dim>::getXMin() const{
	return xmin;
}

template<size_t Dim>
double Box<Dim>::getXMax() const{
	return xmax;
}

template<size_t Dim>
double Box<Dim>::getYMin() const{
	return ymin;
}

template<size_t Dim>
double Box<Dim>::getYMax() const{
	return ymax;
}

template<size_t Dim>
double Box<Dim>::getZMin() const{
	return zmin;
}

template<size_t Dim>
double Box<Dim>::getZMax() const{
	return zmax;
}

template<size_t Dim>
void Box<Dim>::draw2D(cimg_library::CImg<float>& image) const{
	unsigned char yellow[] = {255,215,0};
// 	unsigned char black[] = {0,0,0};
	image.draw_rectangle(
		this->xmin,
		this->ymin,
		this->xmax,
		this->ymax,
		yellow,
		1.0,
		0xFFFFFFFF
	);
}

template<size_t Dim>
void Box<Dim>::draw3D(
	cimg_library::CImg<float>& scenePoints,
	cimg_library::CImgList<float>& scenePrimitives
) const{
// 	unsigned char yellow[] = {255,215,0};
// 	unsigned char black[] = {0,0,0};
	cimg_library::CImg<float> points(
		3,8,1,1,
		xmin,ymin,zmin,
		xmax,ymin,zmin,
		xmin,ymin,zmax,
		xmin,ymax,zmin,
		xmax,ymax,zmin,
		xmax,ymin,zmax,
		xmin,ymax,zmax,
		xmax,ymax,zmax
	);
	points.permute_axes("yxzc");
	cimg_library::CImgList<float> primitives(
		12,2,1,1,1,
		0,1,
		0,2,
		0,3,
		1,4,
		3,4,
		4,7,
		1,5,
		2,5,
		5,7,
		2,6,
		3,6,
		6,7
	);
	scenePoints.append_object3d(scenePrimitives,points,primitives);
}
