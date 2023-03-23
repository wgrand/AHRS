#include <iostream>
#include <string>
#include <vector>

#include "Quaternion.h"

using namespace std;

/// @brief Performs `Quaternion` multiplication.
/// @param p `Quaternion`
/// @param q `Quaternion`
/// @return `Quaternion`
Quaternion quat_mult(Quaternion p, Quaternion q);