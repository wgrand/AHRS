#include "QuatRot.h"

Vector QuatRot(Vector p, Quaternion q) {

   // convert p into a quaternion
   Quaternion p2 = {0, p.x, p.y, p.z};

   // create the quaternion conjugate
   Quaternion q_conj = {q.w, -q.x, -q.y, -q.z};

   // rotate the vector by the quaternion
   Quaternion p_ = quat_mult(q_conj, quat_mult(p2, q));

   // eliminate the scalar part of the quaternion to get the vector
   Vector result = {p_.x, p_.y, p_.z};
   
   return result;

};