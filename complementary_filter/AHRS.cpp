#include "AHRS.h"

using namespace std;

class AHRS {

private:

   Quaternion AttitudePropagation(Quaternion q_prior, Vector omega, float dt) {
      Quaternion q_omega = {1, -0.5*dt*omega.x, -0.5*dt*omega.y, -0.5*dt*omega.z};
      Quaternion q = q_omega*q_prior;
      q.Normalize();
      return q;
   }
   Quaternion AM_Estimation(Vector acc, Vector mag, string frame) {
      const Mat3x3 R = RotationMatrix(acc, mag, frame);
      return Quaternion(R);
   }

public:

   float gain = 0.995;
   float gyro_bias = 0.02;

   AHRS() { }

   Quaternion Update(Quaternion q_prior, Vector acc, Vector gyr, Vector mag, float dt, string frame) {

      Quaternion q;

      // Compute predicted quaternion
      Quaternion q_omega = AttitudePropagation(q_prior, gyr, dt);

      // Compute update quaternion
      Quaternion q_am = AM_Estimation(acc, mag, frame);

      // Fuse predicted and updated quaternions
      Quaternion sum_q = q_omega + q_am;
      if (sum_q.Length() < sqrt(2)) {
         q = q_omega*gain - q_am*(1 - gain); // If the components oppose each other, then they may add up to less than sqrt(2)
      } else { 
         q = q_omega*gain + q_am*(1 - gain);
      }

      q.Normalize();

      return q;

   }

};
