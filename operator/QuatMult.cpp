#include "QuatMult.h"

Quaternion QuatMult(Quaternion p, Quaternion q) {

   float p0=p.w;
   float p1=p.x;
   float p2=p.y;
   float p3=p.z;
   float q0=q.w;
   float q1=q.x;
   float q2=q.y;
   float q3=q.z;

   // Hamilton product: https://en.wikipedia.org/wiki/Quaternion#Hamilton_product
   // q=[p0*q0-p1*q1-p2*q2-p3*q3;
   //    p0*q1+p1*q0+p2*q3-p3*q2;
   //    p0*q2-p1*q3+p2*q0+p3*q1;
   //    p0*q3+p1*q2-p2*q1+p3*q0];

   // this gives correct result: % https://www.mathworks.com/help/aerotbx/ug/quatmultiply.html?w.mathworks.com#mw_beba0414-8a76-47e8-9a3b-696cfdd1610f
   // this identical to computing rotation using rotation matrix; it matches time complexity, but rotation matrix is O(N) space complexity
   Quaternion result = { 
      p0*q0-p1*q1-p2*q2-p3*q3, 
      p0*q1+p1*q0-p2*q3+p3*q2, 
      p0*q2+p1*q3+p2*q0-p3*q1, 
      p0*q3-p1*q2+p2*q1+p3*q0 };

   return result;
};