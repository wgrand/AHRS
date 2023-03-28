#include <iostream>
#include <string>

#include "AHRS.h"

using namespace std;

class AHRS {
   
public:

   static const float gain = 0.995;
   static const float gyro_bias = 0.02;

   static Quaternion Update(Quaternion q_prior, Vector gyr, Vector acc, Vector mag, float dt, string frame) {

      Quaternion q;

      // compute predicted quaternion
      Quaternion q_omega = AttitudePropagation(q_prior, gyr, dt);

      // compute update quaternion
      Quaternion q_am = AM_Estimation(acc, mag, frame);

      // fuse predicted and updated quaternions
      Quaternion sum_q = q_omega + q_am;
      
      float len_q = sum_q.Length();
      if (len_q < sqrt(2)) {
         q = q_omega*AHRS::gain - q_am*(1 - AHRS::gain); // if the components oppose each other, then they may add up to less than sqrt(2)
      } else { 
         q = q_omega*AHRS::gain + q_am*(1 - AHRS::gain);
      }

      q.Normalize();

      return q;

   }

private:

   static Quaternion AttitudePropagation(Quaternion q_prior, Vector omega, float dt) {
      Quaternion q_omega = {1, -0.5*dt*omega.x, -0.5*dt*omega.y, -0.5*dt*omega.z };
      Quaternion q = q_omega*q_prior;
      q.Normalize();
      return q;
   }
   static Quaternion AM_Estimation(Vector acc, Vector mag, string frame) {
      Mat3x3 R = RotationMatrix(acc, mag, frame);
      Quaternion q = Quaternion(R);
      return q;
   }

};
