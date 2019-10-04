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

		static Vector3d delta (Vector3d vec1, Vector3d vec2);
		static double distance (Vector3d vec1, Vector3d vec2);
		static double sq_distance (Vector3d vec1, Vector3d vec2);
		static double magnitude (Vector3d vec);
		static double sq_magnitude (Vector3d vec);
		static Vector3d cross (Vector3d vec1, Vector3d vec2);
		static double dot (Vector3d vec1, Vector3d vec2);
		static Vector3d scalar (double scalar, Vector3d vec);
		static Vector3d unit (Vector3d vec);
		static void integrate (Vector3d& position,
							   Vector3d& velocity,
							   const Vector3d acceleration,
							   double dt);
	};
}

#endif /* Math.hpp */