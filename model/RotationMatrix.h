#include <iostream>
#include <cmath>
#include <string>

#include "model/Vector.h"
#include "model/Quaternion.h"
#include "model/Mat3x3.h"

using namespace std;

Mat3x3 RotationMatrix(Vector acc, Vector mag, string frame);