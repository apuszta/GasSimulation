#include "../inc/Particle.h"

template<size_t Dim>
Particle<Dim>::Particle(
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

template<size_t Dim>
Particle<Dim>::~Particle(){
	// Intentionally NOOP
}

template<size_t Dim>
double Particle<Dim>::getWeight() const{
	return weight;
}

template<size_t Dim>
double Particle<Dim>::getRadius() const{
	return radius;
}

template<size_t Dim>
double Particle<Dim>::getCharge() const{
	return charge;
}

template<size_t Dim>
Eigen::Vector3d Particle<Dim>::getPos() const{
	return pos;
}

template<size_t Dim>
Eigen::Vector3d Particle<Dim>::getVel() const{
	return vel;
}

template<size_t Dim>
Particle<Dim>& Particle<Dim>::setPos(const Eigen::Vector3d p){
	this->pos = p;
	return *this;
}

template<size_t Dim>
Particle<Dim>& Particle<Dim>::setVel(const Eigen::Vector3d v){
	this->vel = v;
	return *this;
}

template<size_t Dim>
void Particle<Dim>::draw2D(cimg_library::CImg<float>& image) const{
	unsigned char green[] = {0,215,0};
	image.draw_circle(this->pos[0],this->pos[1],this->radius,green);
}

template<size_t Dim>
void Particle<Dim>::draw3D(
	cimg_library::CImg<float>& scenePoints,
	cimg_library::CImgList<float>& scenePrimitives
) const{
	cimg_library::CImgList<float> faces3d;
	const cimg_library::CImg<float> points3d = cimg_library::CImg<float>::sphere3d(
		faces3d,
		this->radius,
		4
	).shift_object3d(this->pos[0],this->pos[1],this->pos[2]);
	
	scenePoints.append_object3d(scenePrimitives,points3d,faces3d);
}
