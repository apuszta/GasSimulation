#ifndef PARTICLE_H
#define PARTICLE_H

#include "DrawableObject.h"

/**
** @brief Particle class, holds all relevant information about it (weight,
** diameter, charge, etc.)
**/
class Particle : public DrawableObject{
	private:
		double weight;
		double radius;
		double charge;
	public:
		Particle(
			const double weight,
			const double radius,
			const double charge
		);
		~Particle();

		double getWeight() const;
		double getRadius() const;
		double getCharge() const;

		void draw(cimg_library::CImg<unsigned char>&) const override;
};

#endif
