#ifndef _GLFW_CONCRETE_SURFACE_HPP_
#define _GLFW_CONCRETE_SURFACE_HPP_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "SurfaceInterface.hpp"

class GLFWConcreteSurface : public SurfaceInterface {
	public:
		GLFWConcreteSurface(unsigned int width, unsigned int height)
		: SurfaceInterface(width, height) {

		};

		bool initialize_graphics() {
            bool res;
            GLenum glewStatus;

            res = glfwInit();
            /* GLFW_TRUE = 1 if successful, GLFW_FALSE = 0 if not */
            if(!res){
                std::cout << "Error initializing GLFW..." << std::endl;
                return -1;
            }

            glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_SAMPLES, 4);

            GLFWwindow* window;
            window = glfwCreateWindow(width, height, "Title", NULL, NULL);

            if (window == NULL){
                std::cout << "GLFW failed to create window..." << std::endl;
            }

            glfwMakeContextCurrent(window);
            res = glewInit();
            if (GLEW

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
