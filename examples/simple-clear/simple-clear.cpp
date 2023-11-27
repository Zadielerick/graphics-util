#include <iostream>
#include "SurfaceInterface.hpp"
#include "GLES3/gl32.h"
#include "GLES3/gl3ext.h"

/* Function prototypes for surface management provided by concrete classes */
SurfaceInterface* create_surface(void);
void destroy_surface(SurfaceInterface*);

int main() {
	int status = 0;
    SurfaceInterface* surface = create_surface();

	status = surface->initialize_graphics();
	if (!status){
		std::cout << "Error in graphics intialization: " << status << std::endl;
		return status;
	}

	/* Render solid color to framebuffer */
	glClearColor(0.85f, 0.1f, 0.30f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

    /* Swap framebuffers to move on to next frame */
	surface->swap_buffers();

	return status;
}
