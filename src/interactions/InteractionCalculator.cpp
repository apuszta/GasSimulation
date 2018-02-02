#include "../../inc/interactions/InteractionCalculator.h"

template<class ObjectType1,class ObjectType2>
void InteractionCalculator<ObjectType1,ObjectType2>::interact(
	Interactor* obj1,
	Interactor* obj2
){
	auto obj1Cast = dynamic_cast<ObjectType1*>(obj1);
	auto obj2Cast = dynamic_cast<ObjectType2*>(obj2);
	if(obj1Cast != nullptr and obj2Cast != nullptr){
		this->interact(
			obj1Cast,
			obj2Cast
		);
	}
}
