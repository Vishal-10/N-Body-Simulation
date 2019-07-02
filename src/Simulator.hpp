#ifndef Simulator_hpp
#define Simulator_hpp

#include <cmath>
#include <vector>
#include "Eigen/Dense"
#include "Math.hpp"
#include "Body.hpp"
#include "Constants.hpp"

namespace Celestia {
	class Simulator {
	public:
		double T;
		double dt;

		Simulator(): T(10), dt(0.001) {}

		double gravitional_force (const Body& body1, const Body& body2);
		void run (std::vector <Celestia::Body> body);
	};
}

#endif /* Simulator.hpp */
