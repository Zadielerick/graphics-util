#ifndef _SURFACE_INTERFACE_HPP_
#define _SURFACE_INTERFACE_HPP_

class SurfaceInterface {
	protected:
		unsigned int width;
		unsigned int height;

	public:
		SurfaceInterface(unsigned int width, unsigned int height){
			this->width = width;
			this->height = height;
		};
		virtual bool initialize_graphics() = 0;
		virtual void swap_buffers() = 0;
		virtual bool terminate_graphics() = 0;
};

#endif /*  _SURFACE_INTERFACE_HPP_ */
