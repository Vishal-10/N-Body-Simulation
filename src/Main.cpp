#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Body.hpp"
#include "Constants.hpp"
#include "Graphics.hpp"
#include "Math.hpp"
#include "Simulator.hpp"

using std::cout;
using std::endl;

int main (int argc, char **argv) {
	cout << argc << endl;
	cout << argv[0] << endl;

	Celestia::Math math;
	std::vector <Celestia::Body> bodies;

	std::vector <double> input1 = {0.5, 0, 0, 0, 0.5, 0};
	std::vector <double> input2 = {-0.5, 0, 0, 0, -0.5, 0};

	bodies.push_back(Celestia::Body());
	bodies[0].default_create (input1);
	bodies.push_back(Celestia::Body());
	bodies[1].default_create (input2);

	Celestia::Simulator sim (argc, argv);
	sim.simulate (bodies, 10, 0.0001);
	cout << "Testing Simulator: Run begins" << endl;
	sim.run ();
	cout << "Run End" << endl;

	return 0;
}
