#include "../inc/Visualizer.h"

using namespace cimg_library;
using namespace std;

template<size_t Dim>
Visualizer<Dim>::Visualizer(const int width, const int height, const int rtms):
	displayWidth(width),
	displayHeight(height),
	refreshTimeMs(rtms),
	display(width,height,"Scene",3,false,false)
{
	visualizer = CImg<float>(width,height,1,3)
		.fill(230,230,255)
	;
}

template<size_t Dim>
Visualizer<Dim>::~Visualizer(){
	// Intentionally NOOP
}

template<size_t Dim>
void Visualizer<Dim>::registerObject(const DrawableObject<Dim>* obj){
	objects.emplace_back(obj);
}

template<size_t Dim>
void Visualizer<Dim>::loopCore(){
	if(!this->display.is_closed()){
		displayObjects();
		this_thread::sleep_for(chrono::milliseconds(refreshTimeMs));
	}else{
		stopLoop();
	}
}
