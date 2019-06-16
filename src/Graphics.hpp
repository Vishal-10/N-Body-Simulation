#ifndef Graphics_hpp
#define Graphics_hpp

#include "cuda_runtime.h"
#include <GL/glut.h>

namespace Celestia {
	class Graphics {
	public:
		Graphics ();
		void draw ();
		void update ();
	};
}

#endif /* Graphics.hpp */
