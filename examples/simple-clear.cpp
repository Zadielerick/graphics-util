#include <iostream>
#include "SurfaceInterface.cpp"

int simple_clear(SurfaceInterface& surface ) {
	int status = 0;

	status = surface.initialize_graphics();
	if (!status){
		std::cout << "Error in graphics intialization: " << status << std::endl;
		return status;
	}

	/* Render solid color to framebuffer */
	glClearColor(0.85f, 0.1f, 0.30f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	surface.swap_buffers();



	return status;
}
