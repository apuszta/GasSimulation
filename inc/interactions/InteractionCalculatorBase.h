#ifndef INTERACTION_CALCULATOR_BASE_H
#define INTERACTION_CALCULATOR_BASE_H

#include "../drawables/DrawableObjectBase.h"

class InteractionCalculatorBase{
	public:
		virtual void interact(DrawableObjectBase*,DrawableObjectBase*) = 0;
};

#endif
