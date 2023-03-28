#include <iostream>
#include <cmath>
#include <string>

#include "Vector.h"
#include "Quaternion.h"
#include "Mat3x3.h"

using namespace std;

Mat3x3 RotationMatrix(Vector acc, Vector mag, string frame);