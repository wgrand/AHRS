#include "RotationMatrix.h"

Mat3x3 RotationMatrix(Vector a, Vector m, RefFrame frame = NED) {

   // acceleration
   a.Normalize();
   Vector A = a;
   
   Vector H = {0, 0, 0};
   Vector M = {0, 0, 0};

   // external magnetic field
   Vector E = m;

   // rotation matrix
   Mat3x3 R;

   if (frame == NED) { 

      // H = A x E (y-axis)
      // east = down(acc) x north(mag)
      H = A^E;
      H.Normalize();

      // M = H x A (x-axis)
      // north = east x down(acc)
      // isolate the magnetic field in the horizontal plane and eliminate the z-axis component
      M = H^A;

      R = { M.x, M.y, M.z,
            H.x, H.y, H.z,
            A.x, A.y, A.z };

   } else {

      // X axis
      // H = A x E
      // east = down(acc) x north(mag)
      H = A^E;
      H.Normalize();

      // Y axis
      // M = H x A
      // north = east x down(acc)
      // isolate the magnetic field in the horizontal plane and eliminate the z-axis component
      M = H^A;

      R = { H.x, H.y, H.z,
            M.x, M.y, M.z,
           -A.x, -A.y, -A.z };

   }

   return R;

};