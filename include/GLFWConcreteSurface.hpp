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

#endif /*  _GLFW_CONCRETE_SURFACE_HPP_ */
