#include "Math.hpp"

Celestia::Math::Math () {}

Vector3d Celestia::Math::delta (Vector3d vec1, Vector3d vec2) {
	return vec2 - vec1;
}

double Celestia::Math::distance (Vector3d vec1, Vector3d vec2) {
	Vector3d difference = vec1 - vec2;
	return sqrt (difference.dot (difference));
}

double Celestia::Math::sq_distance (Vector3d vec1, Vector3d vec2) {
	Vector3d difference = vec1 - vec2;
	return difference.dot (difference);
}

double Celestia::Math::magnitude (Vector3d vec) {
	return sqrt (vec.dot (vec));
}

Vector3d Celestia::Math::cross (Vector3d vec1, Vector3d vec2) {
	return vec1.cross (vec2);
}

double Celestia::Math::dot (Vector3d vec1, Vector3d vec2) {
	return vec1.dot (vec2);
}

Vector3d Celestia::Math::scalar (double scalar, Vector3d vec) {
	return scalar*vec;
}

Vector3d Celestia::Math::unit (Vector3d vec) {
	return vec/(Celestia::Math::magnitude (vec));
}
