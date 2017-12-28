#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <CImg.h>

class DrawableObject{
	public:
		virtual void draw(
			cimg_library::CImg<unsigned char>& image
		) const = 0;
};

#endif
