#include <cmath>

struct Quaternion { 
   float w, x, y, z;

   // Normalize the quaternion
   void Normalize() {
      const float length = Length();
      w /= length;
      x /= length;
      y /= length;
      z /= length;
   }

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
      return { w*q.w - x*q.x - y*q.y - z*q.z,
               w*q.x + x*q.w - y*q.z + z*q.y,
               w*q.y + x*q.z + y*q.w - z*q.x,
               w*q.z - x*q.y + y*q.x + z*q.w};
   //    return { w*q.w - x*q.x - y*q.y - z*q.z,
   //             w*q.x + x*q.w + y*q.z - z*q.y,
   //             w*q.y - x*q.z + y*q.w + z*q.x,
   //             w*q.z + x*q.y - y*q.x + z*q.w};
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
