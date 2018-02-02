#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "DrawableObjectBase.h"

#include <CImg.h>

/**
** @brief Templated base class for drawable objects.
** @param N the dimension of the object
**/
template<size_t N>
class DrawableObject : public DrawableObjectBase{
	static_assert(
		N==2 || N==3,
		"Object dimension can be either 2 or 3."
	);
	public:
		/**
		** Calls draw2D() or draw3D(), depending on the template parameter.
		**/
		void draw(
			cimg_library::CImg<float>& imagePoints,
			cimg_library::CImgList<float>& primitives
		) const;
};

#endif
