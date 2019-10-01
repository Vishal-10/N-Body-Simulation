#ifndef Graphics_hpp
#define Graphics_hpp

#include "cuda.h"
#include "cuda_runtime.h"
#include "Body.hpp"
#include <GL/glut.h>

namespace Celestia {
	class Graphics {
		std::vector <Celestia::Body> bodies;
		int height;
		int width;
	public:
		Graphics (int h = 600, int w = 800);

		void init (int argc, char **argv, std::vector <Celestia::Body> bodies);
		void create ();
		void draw ();
		void display ();
		void update ();
	};
}

#endif /* Graphics.hpp */