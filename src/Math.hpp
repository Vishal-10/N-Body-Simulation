#ifndef Math_hpp
#define Math_hpp

#include <cmath>
#include <vector>
#include "Eigen/Dense"
#include "Body.hpp"

using Eigen::Vector3d;

namespace Celestia {
	class Math {
	public:
		Math ();

		Vector3d delta (Vector3d vec1, Vector3d vec2);
		double distance (Vector3d vec1, Vector3d vec2);
		double sq_distance (Vector3d vec1, Vector3d vec2);
		double magnitude (Vector3d vec);
		Vector3d cross (Vector3d vec1, Vector3d vec2);
		double dot (Vector3d vec1, Vector3d vec2);
		Vector3d scalar (double scalar, Vector3d vec);
		Vector3d unit (Vector3d);
	};
}

#endif /* Math.hpp */
