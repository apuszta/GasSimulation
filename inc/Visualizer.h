#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "DrawableObject.h"

#include <CImg.h>
#include <cpponnector/lib/cpponnector-header-only.hpp>

#include <vector>

/**
** 
**/
template<size_t N>
class Visualizer : public cpponnector::LoopingThread{
	protected:
		const int displayWidth;
		const int displayHeight;
		const int refreshTimeMs;
		std::vector<const DrawableObject<N>*> objects;
		cimg_library::CImgDisplay display;
		cimg_library::CImg<float> visualizer;
		cimg_library::CImgList<unsigned char> colors;
	public:
		Visualizer(const int width, const int height, const int rtms = 30);
		~Visualizer();

		void registerObject(const DrawableObject<N>*);
	protected:
		virtual void displayObjects() = 0;
		void loopCore() override;
};

#endif
