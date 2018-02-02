#ifndef BILATERAL_INTERACTOR_H
#define BILATERAL_INTERACTOR_H

#include "Interactor.h"

/**
** @brief Base class for all that can interact with others, and the others can have meaningful impact on it.
** @author Puszta "puszta" Adrián
**/
class BilateralInteractor : public Interactor{
	public:
		virtual ~BilateralInteractor() = default;
};

#endif
