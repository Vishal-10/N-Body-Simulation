#include "Simulator.hpp"
#include <fstream>

Celestia::Simulator::Simulator (int argc, char **argv) {
	graphic.init (argc, argv, bodies);
}

void Celestia::Simulator::simulate (std::vector <Celestia::Body> bodies, double T, double dt) {
	Simulator::bodies = bodies;
	Simulator::T = T;
	Simulator::dt = dt;
}

double Celestia::Simulator::gravitional_force (const Body& body1, const Body& body2) {
	double force =  Constants::Gravity * body1.mass * body2.mass / Math::sq_distance (body1.position, body2.position);
	return force;
}

__global__
void Celestia::Simulator::move (std::vector <Celestia::Body> bodies) {
	std::ofstream out;
	out.open("/home/adwait/Projects/n-body/out");
	for (double t = 0; t < T; t += dt) {
		for (auto it = bodies.begin() ; it != bodies.end() ; ++it)
		{
			it->reset();
			for (auto that = bodies.begin() ; that != bodies.end() ; ++that) {
				if (it != that) {
					auto temp = Math::delta (it->position, that->position);
					auto unit = Math::unit (temp);
					std::cout << "pos: \n" << it->position << std::endl;
					std::cout << "temp: \n" << temp << std::endl;
//					std::cout << "unit: \n" << unit << std::endl;
//					std::cout << "posi: \n" << it->position << std::endl;
//					std::cout << "post: \n" << that->position << std::endl;
					double force = gravitional_force (*it, *that);
//					std::cout << "Force: " << force << std::endl;

					it->acceleration += 1 / it->mass * Math::scalar (force, unit);
				}
			}
			//std::cout << "accel: \n" << it->acceleration << std::endl;
			Math::integrate (it->position, it->velocity, it->acceleration, dt);

			graphic.update();
//			std::cout << it->to_string() << std::endl;
			out << it->to_string() << std::endl;
		}
	}
}

void Celestia::Simulator::run () {
	graphic.create();
	move (bodies);
}