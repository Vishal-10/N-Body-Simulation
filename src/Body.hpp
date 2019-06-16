#include "Math.hpp"
#include <vector>
#include <array>

using Eigen::Vector3d;

namespace celestia {
	class body {
		Vector3d location;
		Vector3d velocity;
		float mass;

		public:
		body (float m, float p, float q, float r, float ux, float uy, float uz) {
			location = { p, q, r};
			velocity = { ux, uy, uz};
			mass = m;
		}

		Vector3d get_location () {
			return location;
		}

		Vector3d get_velocity () {
			return velocity;
		}

		float get_mass () {
			return mass;
		}

		void set_location (float p, float q, float r) {
			location = { p, q, r};
		}

		void set_velocity (float ux, float uy, float uz) {
			velocity = { ux, uy, uz };
		}
	};
}

