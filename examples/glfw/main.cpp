#include "GLFWConcreteSurface.hpp"

extern int simple_clear(SurfaceInterface&);

int main(){

	GLFWConcreteSurface surface(1920,1080);

	simple_clear(surface);
	return 0;
}
