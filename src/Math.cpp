#include "Math.hpp"

Celestia::Math::Math () {}

double Celestia::Math::distance (Vector3d vec1, Vector3d vec2) {
	Vector3d difference = vec1 - vec2;
	return difference.dot (difference);
}

double Celestia::Math::magnitude (Vector3d vec) {
	return vec.dot (vec);
}

Vector3d Celestia::Math::cross (Vector3d vec1, Vector3d vec2) {
	return vec1.cross (vec2);
}

double Celestia::Math::dot (Vector3d vec1, Vector3d vec2) {
	return vec1.dot (vec2);
}
