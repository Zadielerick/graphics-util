#ifndef _GBM_CONCRETE_SURFACE_HPP_
#define _GBM_CONCRETE_SURFACE_HPP_

#include "SurfaceInterface.hpp"

class GBMConcreteSurface : public SurfaceInterface {
	public:
		GBMConcreteSurface(unsigned int width, unsigned int height){
			super(width, height);
		}

		bool initialize_graphics {
			return false;
		}

		void swap_buffers {
			return;
		}

		bool terminate_graphics {
			return false;
		}
};

GBMConcreteSurface* create_surface(){
	GBMConcreteSurface *surface = new GBMConcreteSurface(1920,1080);
    return surface;
}

void destroy_surface(GBMConcreteSurface* surface)
{
    delete surface;
}

#endif /*  _GBM_CONCRETE_SURFACE_HPP_ */
