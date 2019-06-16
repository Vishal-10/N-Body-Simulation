#ifndef Body_h
#define Body_h

#include "Math.hpp"
#include <array>

using Eigen::Vector3d;

namespace Celestia {
	class Body {
	public:
		double mass;
		double radius;
		Vector3d position;
		Vector3d velocity;
		Vector3d acceleration;

		Body ():mass (0),radius (0),position (0,0,0),velocity (0,0,0) {}

		void operator= (const Body& body) {
			mass = body.mass;
			radius = body.radius;
			position = body.position;
			velocity = body.velocity;
			acceleration = body.acceleration;
		}

		void create (const std::vector<double> &inp) {
			mass = inp[0];
			radius = inp[1];
			position << inp[2], inp[3], inp[4];
			velocity << inp[5], inp[6], inp[7];
		}

		void reset () {
			acceleration << 0, 0, 0;
		}

		std::string to_string () const {
			std::stringstream iostr;
			iostr << mass << " " << radius << " " << position[0]
			<< " " << position[1] << " " << position[2] << " "
			<< velocity[0] << " " << velocity[1] << " " << velocity[2];
			return iostr.str ();
		}
	};
}
#endif /* Body.hpp */
