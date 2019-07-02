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
	std::vector <Celestia::Body> body;

 	std::vector <double> input1 = {1, 0, 0, 0, 0.5, 0};
	std::vector <double> input2 = {-1, 0, 0, 0, -0.5, 0};

	body.push_back(Celestia::Body());
	body[0].default_create (input1);
	body.push_back(Celestia::Body());
	body[1].default_create (input2);

	Celestia::Simulator sim;
	cout << "Testing Simulator" << endl;
	sim.run (body);
	cout << "Run End" << endl;

	return 0;
}

