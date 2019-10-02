#include "Math.hpp"

Vector3d Celestia::Math::delta (Vector3d vec1, Vector3d vec2) {
	return vec2 - vec1;
}

double Celestia::Math::distance (Vector3d vec1, Vector3d vec2) {
	Vector3d difference = vec1 - vec2;
	return magnitude(difference);
}

double Celestia::Math::sq_distance (Vector3d vec1, Vector3d vec2) {
	Vector3d difference = vec1 - vec2;
	// |v| = sqrt(a^2 + b^2 + c^2)
	return difference.squaredNorm ();
}

double Celestia::Math::magnitude (Vector3d vec) {
	return vec.norm ();
}

Vector3d Celestia::Math::cross (Vector3d vec1, Vector3d vec2) {
	// v1 x v2  = (a2 * b3 – a3 * b2) * i + (a1 * b3 – a3 * b1) * j + (a1 * b1 – a2 * b1) * k
	return vec1.cross (vec2);
}

double Celestia::Math::dot (Vector3d vec1, Vector3d vec2) {
	// v1.v2 = (a1 * a2 + b1 * b2 + c1 * c2)
	return vec1.dot (vec2);
}

Vector3d Celestia::Math::scalar (double scalar, Vector3d vec) {
	return scalar * vec;
}

Vector3d Celestia::Math::unit (Vector3d vec) {
	// magnitude |v1| = sqrt(a^2 + b^2 + c^2)
	return vec/(magnitude (vec));
}

void Celestia::Math::integrate (Vector3d& position, Vector3d& velocity, const Vector3d acceleration, double dt) {
//	velocity += scalar (dt, acceleration);
//	position += (scalar (dt, velocity) + scalar ((dt * dt) / 2, acceleration));

//leap frog
	velocity += 1/2 * scalar (dt, acceleration);
	position += scalar (dt, velocity);
	velocity += 1/2 * scalar (dt, acceleration);
}