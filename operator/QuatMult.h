#include <iostream>
#include <string>
#include <vector>

#include "../model/Quaternion.h"

using namespace std;

/// @brief Performs `Quaternion` multiplication.
/// @param p `Quaternion`
/// @param q `Quaternion`
/// @return `Quaternion`
Quaternion QuatMult(Quaternion p, Quaternion q);