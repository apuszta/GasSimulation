#include "../../inc/drawables/Particle.h"
#include "../../inc/drawables/Box.h"
#include "../interactions/InteractionCalculator.cpp"

template class InteractionCalculator<Box<2>,Particle<2>>;
template class InteractionCalculator<Particle<2>,Particle<2>>;
