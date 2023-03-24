#include "QuaternionFromMatrix.h"

/// @brief Get Unit Quaternion from a rotation matrix
/// @param rotation_matrix 
/// @return Quaternion identity (1,0,0,0) if input is identity matrix
Quaternion QuaternionFromMatrix(Mat3x3 rotation_matrix) { 

   Mat3x3 R = rotation_matrix;

   //  http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
    
   //  Chiaverini: http://www.iri.upc.edu/files/scidoc/2083-A-Survey-on-the-Computation-of-Quaternions-from-Rotation-Matrices.pdf
   //  w = 0.5*sqrt(trace(R) + 1);
   //  x = 0.5*sign(R(3,2)-R(2,3))*sqrt(clip(R(1,1)-R(2,2)-R(3,3), [-1, 1])+1);
   //  y = 0.5*sign(R(1,3)-R(3,1))*sqrt(clip(R(2,2)-R(3,3)-R(1,1), [-1, 1])+1);
   //  z = 0.5*sign(R(2,1)-R(1,2))*sqrt(clip(R(3,3)-R(1,1)-R(2,2), [-1, 1])+1);

   //  The following comes from p. 6-7 from https://www.plymouth.ac.uk/uploads/production/document/path/8/8594/Terzakis_et_al_2012__A_Recipe_on_the_Parameterization_of_Rotation_Matrices...MIDAS.SME.2012.TR.004.pdf
   float T = R[0][0] + R[1][1] + R[2][2];
   float s, w, x, y, z;

   if (T > 0) {

      s = 0.5/sqrt(T + 1);
      w = 0.25/s;
      x = (R[2][1] - R[1][2])*s;
      y = (R[0][2] - R[2][0])*s;
      z = (R[1][0] - R[0][1])*s;

   } else {

      if (R[0][0] > R[1][1] && R[0][0] > R[2][2]) {
        s = 2*sqrt(1 + R[0][0] - R[1][1] - R[2][2]);
        w = (R[2][1] - R[1][2])/s;
        x = 0.25*s;
        y = (R[0][1] + R[1][0])/s;
        z = (R[0][2] + R[2][0])/s;
      } else if (R[1][1] > R[2][2]) {
        s = 2*sqrt(1 + R[1][1] - R[0][0] - R[2][2]);
        w = (R[0][2] - R[2][0])/s;
        x = (R[0][1] + R[1][0])/s;
        y = 0.25*s;
        z = (R[1][2] + R[2][1] )/s;
      } else {
        s = 2*sqrt(1 + R[2][2] - R[0][0] - R[1][1]);
        w = (R[1][0] - R[0][1])/s;
        x = (R[0][2] + R[2][0])/s;
        y = (R[1][2] + R[2][1])/s;
        z = 0.25*s;
      }

   }

   float norm_q = w*w + x*x + y*y + z*z;
   Quaternion q = {w/norm_q, x/norm_q, y/norm_q, z/norm_q };

   return q;

};