#ifndef BOX_H
#define BOX_H

#include "DrawableObject.h"

/**
** @brief 
**/
class Box : public DrawableObject{
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

		void draw(cimg_library::CImg<unsigned char>&) const override;
};

#endif
