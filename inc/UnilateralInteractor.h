#ifndef UNILATERAL_INTERACTOR_H
#define UNILATERAL_INTERACTOR_H

#include "Interactor.h"

/**
** @brief Base class for all that can interact with others, but the others have no meaningful impact on it.
** @author Puszta "puszta" Adrián
**/
class UnilateralInteractor : public Interactor{
	public:
		virtual ~UnilateralInteractor() = default;
};

#endif
