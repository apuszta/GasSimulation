#include "../../inc/drawables/DrawableObject.h"

template<>
void DrawableObject<2>::draw(
	cimg_library::CImg<float>& image,
	cimg_library::CImgList<float>& /*primitives*/
) const{
	this->draw2D(image);
}

template<>
void DrawableObject<3>::draw(
	cimg_library::CImg<float>& imagePoints,
	cimg_library::CImgList<float>& primitives
) const{
	this->draw3D(imagePoints, primitives);
}
