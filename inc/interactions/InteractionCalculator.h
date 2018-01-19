#ifndef INTERACTION_CALCULATOR_H
#define INTERACTION_CALCULATOR_H

#include "InteractionCalculatorBase.h"

template<class ObjectType1, class ObjectType2>
class InteractionCalculator : public InteractionCalculatorBase{
	public:
		void interact(DrawableObjectBase*,DrawableObjectBase*) override;
	protected:
		virtual void interact(ObjectType1*,ObjectType2*) = 0;
};

#endif
