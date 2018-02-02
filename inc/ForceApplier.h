#ifndef FORCE_APPLIER_H
#define FORCE_APPLIER_H

#include "Interactor.h"
#include "interactions/InteractionCalculatorBase.h"

#include <cpponnector/lib/cpponnector-header-only.hpp>

#include <vector>

class ForceApplier : public cpponnector::LoopingThread{
	private:
		std::vector<InteractionCalculatorBase*> interactions;
		std::vector<Interactor*> objects;
		float dt;
	public:
		ForceApplier(const float dt);
		void registerInteraction(InteractionCalculatorBase*);
		void registerObject(Interactor*);
	protected:
		void loopCore() override;
		void applyInteractions();
		void stepObjects(const float dt);
};

#endif
