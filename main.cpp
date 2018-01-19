#include "inc/Particle.h"
#include "inc/Box.h"
#include "inc/Visualizer2D.h"
#include "inc/Visualizer3D.h"

#include <iostream>
#include <vector>
#include <random>
#include <memory>

using namespace std;
using namespace cimg_library;

int main(){
	const size_t dimension = 3;

	const int displayWidth = 1000;
	const int displayHeight = 1000;
	const int maxParticles = 100;
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<> posDistribution(50.0, 350.0);
	std::uniform_real_distribution<> velDistribution(-1.0, 1.0);

	shared_ptr<Visualizer<dimension>> visualizer = make_shared<Visualizer3D>(
		displayWidth,
		displayHeight,
		30
	);

	vector<Particle<dimension>*> particles;
	for(int i = 0; i < maxParticles; ++i){
		Particle<dimension>* particle = new Particle<dimension>(1,10,1);
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
	Box<dimension>* box = new Box<dimension>(0,0,0,400,400,400);
	visualizer->registerObject(box);

	visualizer->start();

	while(true){
		for(int i = 0; i < maxParticles; ++i){
			particles[i]->step(0.003);
		}
	}

	visualizer->join();

	return 0;
}
