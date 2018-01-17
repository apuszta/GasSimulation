#ifndef PARTICLE_H
#define PARTICLE_H

// need to include it before X11 (CImg) to avoid macro collision
#include <Eigen/Core>

#include "DrawableObject.h"

/**
** @brief Particle class, holds all relevant information about it (weight,
** diameter, charge, etc.)
**/
template<size_t Dim>
class Particle : public DrawableObject<Dim>{
	private:
		double weight;
		double radius;
		double charge;
		Eigen::Vector3d pos;
		Eigen::Vector3d vel;
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
		Eigen::Vector3d getPos() const;
		Eigen::Vector3d getVel() const;
		Particle<Dim>& setPos(const Eigen::Vector3d);
		Particle<Dim>& setVel(const Eigen::Vector3d);

		void draw2D(cimg_library::CImg<float>&) const override;
		void draw3D(cimg_library::CImg<float>&,cimg_library::CImgList<float>&) const override;
};

#endif
