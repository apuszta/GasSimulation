#ifndef INTERACTION_CALCULATOR_H
#define INTERACTION_CALCULATOR_H

#include "InteractionCalculatorBase.h"

#include <type_traits>

/**
** @brief 
** @author Puszta "puszta" Adrián
**/
template<class ObjectType1, class ObjectType2>
class InteractionCalculator : public InteractionCalculatorBase{
	static_assert(
		std::is_base_of<Interactor,ObjectType1>::value,
		"ObjectType1 must be a subclass of Interactor."
	);
	static_assert(
		std::is_base_of<Interactor,ObjectType2>::value,
		"ObjectType2 must be a subclass of Interactor."
	);

	public:
		void interact(Interactor*,Interactor*) override;
	protected:
		virtual void interact(ObjectType1*,ObjectType2*) = 0;
};

#endif
