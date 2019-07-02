#include "Simulator.hpp"

Celestia::Simulator::Simulator (std::vector <Celestia::Body> bodies, double T, double dt) {
	Celestia::Simulator::bodies = bodies;
	Celestia::Simulator::T = T;
	Celestia::Simulator::dt = dt;
}

double Celestia::Simulator::gravitional_force (const Body& body1, const Body& body2) {
	double force =  Constants::Gravity * body1.mass * body2.mass / Math::sq_distance (body1.position, body2.position);
	return force;
}

__global__
void Celestia::Simulator::move (std::vector <Celestia::Body> bodies) {
	for (double t = 0; t < T; t += dt) {
		for (auto it = bodies.begin() ; it != bodies.end() ; ++it)
		{
			for (auto that = bodies.begin() ; that != bodies.end() ; ++that) {
				if (it->position != that->position) {
					it->reset();
					auto temp = Math::delta (it->position, that->position);
					auto unit = Math::unit (temp);
					double force = gravitional_force (*it, *that);

					it->acceleration += Math::scalar (force / it->mass, unit);

					Math::integrate (it->position, it->velocity, it->acceleration, dt);
				}
			}
			std::cout << it->to_string() << std::endl;
		}
	}
}

void Celestia::Simulator::run () {
	move (bodies);
}
