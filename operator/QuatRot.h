#include <iostream>
#include <string>

#include "QuatMult.h"
#include "../model/Vector.h"

using namespace std;

/// @brief Rotate `Vector` by `Quaternion`.
/// @param p `Vector` to be rotated.
/// @param q `Quaternion` that describes the rotation.
/// @return Rotated `Vector`.

Vector QuatRot(Vector p, Quaternion q);