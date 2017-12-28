#include "../inc/Particle.h"

Particle::Particle(
	const double weight,
	const double radius,
	const double charge
):
	weight(weight),
	radius(radius),
	charge(charge)
{
	// Intentionally NOOP
}

Particle::~Particle(){
	// Intentionally NOOP
}

double Particle::getWeight() const{
	return weight;
}

double Particle::getRadius() const{
	return radius;
}

double Particle::getCharge() const{
	return charge;
}

void Particle::draw(cimg_library::CImg<unsigned char>& image) const{
	
}
