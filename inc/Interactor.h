#ifndef INTERACTOR_H
#define INTERACTOR_H

/**
** @brief Base class for all that can interact with others.
** @author Puszta "puszta" Adrián
**/
class Interactor{
	public:
		virtual ~Interactor() = default;

		/**
		** 
		**/
		virtual void step(const float dt);
};

#endif
