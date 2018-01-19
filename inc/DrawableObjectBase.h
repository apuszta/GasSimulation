#ifndef DRAWABLE_OBJECT_BASE_H
#define DRAWABLE_OBJECT_BASE_H

#include <CImg.h>

class DrawableObjectBase{
	public:
		/**
		** Calls draw2D() or draw3D(), depending on the template parameter.
		**/
		virtual void draw(
			cimg_library::CImg<float>& imagePoints,
			cimg_library::CImgList<float>& primitives
		) const = 0;

		/**
		** 
		**/
		virtual void step(const float dt);
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
