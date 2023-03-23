#include "RotationMatrix.h"

Mat3x3 RotationMatrix(Vector a, Vector m, string frame = "NED") {

   // acceleration
   Vector A = a;
   
   float norm_a = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
   a.x = a.x/norm_a;
   a.y = a.y/norm_a;
   a.z = a.z/norm_a;

   Vector H = {0, 0, 0};
   Vector M = {0, 0, 0};

   // external magnetic field
   Vector E = m;

   // rotation matrix
   Mat3x3 R;

   if (frame == "NED") { 

      // H = A x E (y-axis)
      // east = down(acc) x north(mag)
      H.x = E.z*A.y - E.y*A.z;
      H.y = E.x*A.z - E.z*A.x;
      H.z = E.y*A.x - E.x*A.y;

      float norm_h = sqrt(H.x*H.x + H.y*H.y + H.z*H.z);
      H.x = H.x/norm_h;
      H.y = H.y/norm_h;
      H.z = H.z/norm_h;

      // M = H x A (x-axis)
      // north = east x down(acc)
      // isolate the magnetic field in the horizontal plane and eliminate the z-axis component
      M.x = A.z*H.y - A.y*H.z;
      M.y = A.x*H.z - A.z*H.x;
      M.z = A.y*H.x - A.x*H.y;

      R = { M.x, M.y, M.z,
            H.x, H.y, H.z,
            A.x, A.y, A.z };

   } else {

      // X axis
      // H = A x E
      // east = down(acc)s x north(mag)
      H.x = A.y*E.z - A.z*E.y;
      H.y = A.z*E.x - A.x*E.z;
      H.z = A.x*E.y - A.y*E.x;

      float norm_h = sqrt(H.x*H.x + H.y*H.y + H.z*H.z);
      H.x = H.x/norm_h;
      H.y = H.y/norm_h;
      H.z = H.z/norm_h;

      // Y axis
      // M = H x A
      // north = east x down(acc)
      // isolate the magnetic field in the horizontal plane and eliminate the z-axis component
      M.x = H.y*A.z - H.z*A.y;
      M.y = H.z*A.x - H.x*A.z;
      M.z = H.x*A.y - H.y*A.x;

      R = { H.x, H.y, H.z,
            M.x, M.y, M.z,
           -A.x, -A.y, -A.z };

   }

   return R;

};