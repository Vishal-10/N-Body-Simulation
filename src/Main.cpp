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

	Vector3d x, y;
	x << 1, 0, 0;
	y << 0, 1, 0;

	Celestia::Math math;
	std::vector <Celestia::Body> body;

	Vector3d xunit = math.unit (x);
	Vector3d yunit = math.unit (y);

 	std::vector <double> input1 = {1, 1, 1, 0, 0, 0, 0, 0};
	std::vector <double> input2 = {1, 1, -1, 0, 0, 0, 0, 0};

	body.push_back(Celestia::Body());
	body[0].create (input1);
	body.push_back(Celestia::Body());
	body[1].create (input2);
/*
	cout << "Testing Math" << endl;
	cout << "Vector x:\n" << x << endl;
	cout << "Vector y:\n" << y << endl;
	cout << "Mag of x: " << math.magnitude (x) << endl;
	cout << "Mag of y: " << math.magnitude (y) << endl;
	cout << "X Unit vector:\n" << xunit << endl;
	cout << "Y Unit vector:\n" << yunit << endl;
	cout << "Mag of X unit: " << math.magnitude (xunit) << endl;
	cout << "Mag of Y unit: " << math.magnitude (yunit) << endl;
	cout << "Distance between x y: " << math.distance (x, y) << endl;
	cout << "Dot product: " << math.dot (x, y) << endl;
	cout << "Cross product:\n" << math.cross (x, y) << endl;
	cout << "X -> Y:\n" << math.delta (x, y) << endl;
	cout << "Y -> X:\n" << math.delta (y, x) << endl;

	cout << "~~~~~~~~~~~~~~~~" << endl;

	cout << "Testing Constants" << endl;
	cout << "Constant G = " << Celestia::Constants::Gravity << endl;
	cout << "Constant e = " << Celestia::Constants::Elasticity << endl;

	cout << "~~~~~~~~~~~~~~~~" << endl;

	cout << "Testing Body" << endl;
	for (int i = 0; i < 2; i++) {
		cout << "Body " << i <<" to string: " << body[i].to_string() << endl;
		cout << "Body " << i <<" Acceleration:\n" << body[i].acceleration << endl;
		cout << "Vector Body "<< " i " <<":\n" << body[i].position << endl;
	}
*/
	Celestia::Simulator sim;
	cout << "Testing Simulator" << endl;
	sim.run (body);

	return 0;
}

