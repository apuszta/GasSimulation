#ifndef VISUALIZER_3D_H
#define VISUALIZER_3D_H

#include "Visualizer.h"

class Visualizer3D : public Visualizer<3>{
	public:
		Visualizer3D(const int width, const int height, const int rtms = 30);
	protected:
		void displayObjects() override;
};

#endif
