#ifndef QUATERNION_H
#define QUATERNION_H
#include <cmath>

#include "Mat3x3.h"

struct Quaternion { 

   float w, x, y, z;

   Quaternion(float w = 1.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f) : w(w), x(x), y(y), z(z) {}

   // Constructor that takes a rotation matrix
   Quaternion(Mat3x3 rotation_matrix) {

      Mat3x3 R = rotation_matrix;

      //  The following comes from p. 6-7 from https://www.plymouth.ac.uk/uploads/production/document/path/8/8594/Terzakis_et_al_2012__A_Recipe_on_the_Parameterization_of_Rotation_Matrices...MIDAS.SME.2012.TR.004.pdf
      float T = R[0][0] + R[1][1] + R[2][2];
      float s;

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

      Normalize();

   }

   // Normalize the quaternion
   void Normalize() {
      const float length = Length();
      w /= length;
      x /= length;
      y /= length;
      z /= length;
   }

   // Return the conjugate of the quaternion
   Quaternion Conjugate() {
      return {w, -x, -y, -z};
   }

   // Return the length of the quaternion
   float Length() { 
      return std::sqrt(w*w + x*x + y*y + z*z);
   }

   Quaternion operator+(const Quaternion &q) const {
      return {w + q.w, x + q.x, y + q.y, z + q.z};
   }
   Quaternion operator-(const Quaternion& q) const {
      return {w - q.w, x - q.x, y - q.y, z - q.z};
   }
   
   Quaternion operator*(const Quaternion& q) const {
   // this gives correct result: https://www.mathworks.com/help/aerotbx/ug/quatmultiply.html?w.mathworks.com#mw_beba0414-8a76-47e8-9a3b-696cfdd1610f
   // this identical to computing rotation using rotation matrix; it matches time complexity, but rotation matrix is O(N) space complexity
      return { w*q.w - x*q.x - y*q.y - z*q.z,
               w*q.x + x*q.w - y*q.z + z*q.y,
               w*q.y + x*q.z + y*q.w - z*q.x,
               w*q.z - x*q.y + y*q.x + z*q.w };
   // Hamilton product: https://en.wikipedia.org/wiki/Quaternion#Hamilton_product               
   //    return { w*q.w - x*q.x - y*q.y - z*q.z,
   //             w*q.x + x*q.w + y*q.z - z*q.y,
   //             w*q.y - x*q.z + y*q.w + z*q.x,
   //             w*q.z + x*q.y - y*q.x + z*q.w };
   }

   Quaternion operator*(float s) const {
      return {w*s, x*s, y*s, z*s};
   }

   Quaternion operator/(float s) const {
      return {w/s, x/s, y/s, z/s};
   }

   void operator+=(const Quaternion& q) {
      w += q.w; x += q.x; y += q.y; z += q.z;
   }
   void operator-=(const Quaternion& q) {
      w -= q.w; x -= q.x; y -= q.y; z -= q.z;
   }
   bool operator==(const Quaternion& q) const {
      return (w == q.w) && (x == q.x) && (y == q.y) && (z == q.z);
   }
   bool operator!=(const Quaternion& q) const {
      return (w != q.w) || (x != q.x) || (y != q.y) || (z != q.z);
   }

};
#endif