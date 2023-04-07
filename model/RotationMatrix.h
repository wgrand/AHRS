#include <iostream>
#include <cmath>
#include <string>

#include "../RefFrame.h"
#include "Vector.h"
#include "Quaternion.h"
#include "Mat3x3.h"

using std::string;

Mat3x3 RotationMatrix(Vector acc, Vector mag, RefFrame frame);