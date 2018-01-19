#ifndef VISUALIZER_2D_H
#define VISUALIZER_2D_H

#include "Visualizer.h"

class Visualizer2D : public Visualizer<2>{
	public:
		Visualizer2D(const int width, const int height, const int rtms = 30);
	protected:
		void displayObjects() override;
};

#endif
