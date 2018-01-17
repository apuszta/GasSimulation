#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <CImg.h>

template<size_t N>
class DrawableObject{
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
	protected:
		/*
		* Draw the 2D version.
		*/
		virtual void draw2D(
			cimg_library::CImg<float>& image
		) const = 0;

		/*
		* Draw the 3D version.
		*/
		virtual void draw3D(
			cimg_library::CImg<float>& imagePoints,
			cimg_library::CImgList<float>& primitives
		) const = 0;
};

#endif
