#include "../../inc/interactions/InteractionCalculator.h"

template<class ObjectType1,class ObjectType2>
void InteractionCalculator<ObjectType1,ObjectType2>::interact(
	DrawableObjectBase* obj1,
	DrawableObjectBase* obj2
){
	this->interact(
		static_cast<ObjectType1>(obj1),
		static_cast<ObjectType2>(obj2)
	);
}
