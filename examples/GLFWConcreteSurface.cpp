#ifndef _GLFW_CONCRETE_SURFACE_HPP_
#define _GLFW_CONCRETE_SURFACE_HPP_

#include "SurfaceInterface.hpp"

class GLFWConcreteSurface : public SurfaceInterface {
	public:
		GLFWConcreteSurface(unsigned int width, unsigned int height)
		: SurfaceInterface(width, height) {

		};

		bool initialize_graphics() {
			return true;
		};

		void swap_buffers() {
		};

		bool terminate_graphics() {
			return true;
		};
};

SurfaceInterface* create_surface(){
	SurfaceInterface *surface = dynamic_cast<SurfaceInterface*>(new GLFWConcreteSurface(1920,1080));
    return surface;
}

void destroy_surface(SurfaceInterface* surface)
{
    delete surface;
}

#endif /*  _GLFW_CONCRETE_SURFACE_HPP_ */
