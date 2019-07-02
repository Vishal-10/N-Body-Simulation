#include "Simulator.hpp"
#include <iostream>

double Celestia::Simulator::gravitional_force (const Body& body1, const Body& body2) {
	double force =  Constants::Gravity * body1.mass * body2.mass / Math::sq_distance (body1.position, body2.position);
	return force;
}

void Celestia::Simulator::run (std::vector <Celestia::Body> bodies) {
	for (double t = 0; t < T; t += dt) {
		for (auto it = bodies.begin() ; it != bodies.end() ; ++it)
		{
			for (auto that = bodies.begin() ; that != bodies.end() ; ++that) {
				if (it->position != that->position) {
					auto temp = Math::delta (it->position, that->position);
					auto unit = Math::unit (temp);
					double force = gravitional_force (*it, *that);

					it->acceleration = Math::scalar (force / it->mass, unit);

					temp = Math::delta (that->position, it->position);
					unit = Math::unit (temp);

					that->acceleration = Math::scalar (force / that->mass, unit);

					Math::integrate (it->position, it->velocity, it->acceleration, dt);
					Math::integrate (that->position, that->velocity, that->acceleration, dt);
				}
			}
			std::cout << it->to_string() << std::endl;
		}
	}
}