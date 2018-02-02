#include "../inc/ForceApplier.h"

#include <iostream>

using namespace std;

ForceApplier::ForceApplier(const float dt) : dt(dt){
	// Intentionally NOOP
}

void ForceApplier::registerInteraction(InteractionCalculatorBase* icb){
	this->interactions.emplace_back(icb);
}

void ForceApplier::registerObject(DrawableObjectBase* dob){
	this->objects.emplace_back(dob);
}

void ForceApplier::applyInteractions(){
	const auto& objectsSize = this->objects.size();
	for(auto i = decltype(objectsSize){0}; i < objectsSize; ++i){
		for(auto j = decltype(objectsSize){i+1}; j < objectsSize; ++j){
			for_each(
				this->interactions.begin(),
				this->interactions.end(),
				[i,j,this](InteractionCalculatorBase* icb)->void{
					icb->interact(this->objects[i],this->objects[j]);
				}
			);
		}
	}
}

void ForceApplier::stepObjects(const float dt){
	const auto& objectsSize = this->objects.size();
	for(auto i = decltype(objectsSize){0}; i < objectsSize; ++i){
		this->objects[i]->step(dt);
	}
}

void ForceApplier::loopCore(){
	applyInteractions();
	stepObjects(dt);
	this_thread::sleep_for(chrono::milliseconds(1));
}
