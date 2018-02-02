#ifndef INTERACTION_CALCULATOR_BASE_H
#define INTERACTION_CALCULATOR_BASE_H

#include "../Interactor.h"

/**
** @brief 
** @author Puszta "puszta" Adrián 
**/
class InteractionCalculatorBase{
	public:
		/**
		** Provides a method to let the interactors interact.
		**/
		virtual void interact(Interactor*,Interactor*) = 0;
};

#endif
