#include "Simulator.hpp"
#include <iostream>

double Celestia::Simulator::gravitional_force (const Body& body1, const Body& body2) {
	double force =  Constants::Gravity * body1.mass * body2.mass / Math::sq_distance (body1.position, body2.position);
	std::cout << "Force = " << force << std::endl;
	return force;
}

void Celestia::Simulator::set_acceleration (Body& body1, Body& body2) {
	Vector3d temp = Celestia::Math::delta (body2.position, body1.position);
	auto unit = Math::unit (temp);
	double force = Celestia::Simulator::gravitional_force (body1, body2);
	body1.acceleration = Math::scalar (force / body1.mass, unit);
	temp = -1 * temp;
	unit = Math::unit (temp);
	body2.acceleration = Math::scalar (force / body2.mass, unit);
}

void Celestia::Simulator::move (Body& body1, Body& body2) {
	Celestia::Simulator::set_acceleration (body1, body2);
	Celestia::Math::integrate (body1.position, body1.velocity, body1.acceleration, Celestia::Simulator::dt);
	Celestia::Math::integrate (body2.position, body2.velocity, body2.acceleration, Celestia::Simulator::dt);
}