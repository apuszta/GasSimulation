#ifndef COLLISION_CALCULATOR_H
#define COLLISION_CALCULATOR_H

#include "InteractionCalculator.h"

/**
** @brief 
** @author Puszta "puszta" Adrián
**/
template<class ObjectType1, class ObjectType2>
class CollisionCalculator : public InteractionCalculator<ObjectType1,ObjectType2>{
	protected:
		void interact(ObjectType1*,ObjectType2*) override;
};

#endif
