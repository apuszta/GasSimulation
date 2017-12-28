#include "inc/Dummy.h"
#include "inc/Particle.h"
#include "inc/Box.h"

#include <iostream>

using namespace std;
using namespace cimg_library;

int main(){
// 	cout << "I'm working!" << endl;
// 	Dummy dummy;
// 	dummy.doSomething();
// 	dummy.foo();

	Particle p(1,5,-1);
	cout << "particle weight: " << p.getWeight() << endl;

	// display 2 yellow rectangles
	Box b1(10,10,0,100,200,0);
	Box b2(40,50,0,170,250,0);
	CImg<unsigned char> img(600,600,1,3);
	img.fill(0);
	CImgDisplay disp(600,600,"Test display",0,false, false);

	b1.draw(img);
	b2.draw(img);

	disp.display(img);

	while(!disp.is_closed()){
		disp.wait(50);
	}
	return 0;
}
