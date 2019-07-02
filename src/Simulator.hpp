#ifndef Simulator_hpp
#define Simulator_hpp

#include <cmath>
#include <vector>
#include <iostream>
#include "cuda_runtime.h"
#include "Eigen/Dense"
#include "Math.hpp"
#include "Body.hpp"
#include "Constants.hpp"

namespace Celestia {
	class Simulator {
	public:
		std::vector <Celestia::Body> bodies;
		double T;
		double dt;

		Simulator(std::vector <Celestia::Body> bodies, double T, double dt);

		double gravitional_force (const Body& body1, const Body& body2);
		void move (std::vector <Celestia::Body> body);
		void run ();
	};
}

#endif /* Simulator.hpp */
