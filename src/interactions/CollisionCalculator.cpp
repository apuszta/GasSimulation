#include "../../inc/drawables/Particle.h"
#include "../../inc/interactions/CollisionCalculator.h"
#include "../../inc/drawables/Box.h"

#include <iostream>

template<>
void CollisionCalculator<Box<2>,Particle<2>>::interact(Box<2>* box, Particle<2>* particle){
	const auto& position = particle->getPos();
	const auto& radius = particle->getRadius();
	auto vel = particle->getVel();
	if(position[0] < (box->getXMin() + radius) and vel[0] < 0){
		vel[0] *= -1.0;
		particle->setVel(vel);
	}else if(position[0] > (box->getXMax() - radius) and vel[0] > 0){
		vel[0] *= -1.0;
		particle->setVel(vel);
	}else if(position[1] < (box->getYMin() + radius) and vel[1] < 0){
		vel[1] *= -1.0;
		particle->setVel(vel);
	}else if(position[1] > (box->getYMax() - radius) and vel[1] > 0){
		vel[1] *= -1.0;
		particle->setVel(vel);
	}
}

// template<>
// void CollisionCalculator<Particle<2>,Box<2>>::interact(Particle<2>* particle, Box<2>* box){
// 	CollisionCalculator<Box<2>,Particle<2>>::interact(box, particle);
// }

template<>
void CollisionCalculator<Particle<2>,Particle<2>>::interact(Particle<2>* particleA, Particle<2>* particleB){
	const auto& positionA = particleA->getPos();
	const auto& radiusA = particleA->getRadius();
	const auto& positionB = particleB->getPos();
	const auto& radiusB = particleB->getRadius();

	
}
