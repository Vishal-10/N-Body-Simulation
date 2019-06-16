#ifndef Math_hpp
#define Math_hpp

#include <cmath>
#include <vector>
#include "Eigen/Core"
#include "Body.hpp"

using Eigen::Vector3d;

namespace Celestia {
	class Math {
	public:
		Math ();

		double distance (Vector3d vec1, Vector3d vec2);
		double magnitude (Vector3d vec);
	};
}

#endif /* Math.hpp */
