#include "inc/drawables/Particle.h"
#include "inc/drawables/Box.h"
#include "inc/Visualizer2D.h"
#include "inc/Visualizer3D.h"
#include "inc/ForceApplier.h"
#include "inc/interactions/CollisionCalculator.h"

#include <iostream>
#include <vector>
#include <random>
#include <memory>

using namespace std;
using namespace cimg_library;

int main(){
	const size_t dimension = 2;

	const int displayWidth = 500;
	const int displayHeight = 500;
	const int maxParticles = 4;
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<> posDistribution(100.0, 400.0);
	std::uniform_real_distribution<> velDistribution(-0.1, 0.1);

	shared_ptr<Visualizer<dimension>> visualizer = make_shared<Visualizer2D>(
		displayWidth,
		displayHeight,
		1
	);

	vector<Particle<dimension>*> particles;
	for(int i = 0; i < maxParticles; ++i){
		Particle<dimension>* particle = new Particle<dimension>(i+1,10,1);
		particle
			->setPos(
				Eigen::Vector3d(
					posDistribution(generator),
					posDistribution(generator),
					posDistribution(generator)
				)
			).setVel(
				Eigen::Vector3d(
					velDistribution(generator),
					velDistribution(generator),
					velDistribution(generator)
				)
			)
		;
		particles.emplace_back(particle);
		visualizer->registerObject(particle);
	}
	Box<dimension>* box = new Box<dimension>(50,50,50,450,450,450);
	visualizer->registerObject(box);

	CollisionCalculator<Box<2>,Particle<2>>* collisionCalculator =
		new CollisionCalculator<Box<2>,Particle<2>>()
	;
	auto forceApplier = make_shared<ForceApplier>(1.0);
	forceApplier->registerInteraction(collisionCalculator);
	forceApplier->registerObject(box);
	forceApplier->registerObject(particles[0]);
	forceApplier->registerObject(particles[1]);
	forceApplier->registerObject(particles[2]);
	forceApplier->registerObject(particles[3]);

	visualizer->start();
	forceApplier->start();

	forceApplier->join();
	visualizer->join();

	return 0;
}
