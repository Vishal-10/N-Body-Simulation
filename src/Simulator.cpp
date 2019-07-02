#include "Simulator.hpp"
#include <iostream>

double Celestia::Simulator::gravitional_force (const Body& body1, const Body& body2) {
	double force =  Constants::Gravity * body1.mass * body2.mass / Math::sq_distance (body1.position, body2.position);
	return force;
}

void Celestia::Simulator::set_acceleration (Body& body1, Body& body2) {
	auto temp = Math::delta (body1.position, body2.position);
	auto unit = Math::unit (temp);
	double force = gravitional_force (body1, body2);
	body1.acceleration = Math::scalar (force / body1.mass, unit);
	temp = Math::delta (body2.position, body1.position);
	unit = Math::unit (temp);
	body2.acceleration = Math::scalar (force / body2.mass, unit);
}

void Celestia::Simulator::move (Body& body1, Body& body2) {
	set_acceleration (body1, body2);
	Math::integrate (body1.position, body1.velocity, body1.acceleration, dt);
	Math::integrate (body2.position, body2.velocity, body2.acceleration, dt);
}

void Celestia::Simulator::run (std::vector <Celestia::Body> bodies) {
	for (double t = 0; t < T; t += dt) {
		for (auto it = bodies.begin() ; it != bodies.end() ; ++it)
		{
			for (auto that = bodies.begin() ; that != bodies.end() ; ++that) {
				if (it->position != that->position)
					move (*it, *that);
			}
			std::cout << it->to_string() << std::endl;
		}
	}
}