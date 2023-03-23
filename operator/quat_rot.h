#include <iostream>
#include <string>

#include "quat_mult.h"
#include "../model/Vector.h"

using namespace std;

/// @brief Rotate `Vector` by `Quaternion`.
/// @param p `Vector` to be rotated.
/// @param q `Quaternion` that describes the rotation.
/// @return Rotated `Vector`.

Vector quatRot(Vector p, Quaternion q);