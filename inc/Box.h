#ifndef BOX_H
#define BOX_H

#include "DrawableObject.h"

/**
** @brief 
**/
template<size_t Dim>
class Box : public DrawableObject<Dim>{
	private:
		double xmin;
		double xmax;
		double ymin;
		double ymax;
		double zmin;
		double zmax;
	public:
		Box(
			const double xmin,
			const double ymin,
			const double zmin,
			const double xmax,
			const double ymax,
			const double zmax
		);
		~Box();

// 		double getWeight() const;
// 		double getRadius() const;
// 		double getCharge() const;

		void draw2D(cimg_library::CImg<float>&) const override;
		void draw3D(cimg_library::CImg<float>&,cimg_library::CImgList<float>&) const override;
};

#endif
