
struct Vector { 
   float x, y, z;

   // Normalize the vector
   void Normalize() {
      const float length = Length();
      x /= length;
      y /= length;
      z /= length;
  }

   float Length() { 
      return std::sqrt(x*x + y*y + z*z);
   }

   Vector operator+(const Vector& v) const {
      return {x + v.x, y + v.y, z + v.z};
   }
   Vector operator-(const Vector& v) const {
      return {x - v.x, y - v.y, z - v.z};
   }
   
   // Multiplication by scalar operator (vector * scalar)
   Vector operator*(float s) const {
      return {x*s, y*s, z*s};
   }

   // Division by scalar operator (vector / scalar)
   Vector operator/(float s) const {
      return {x/s, y/s, z/s};
   }

   // Dot product operator (vector1 dot vector2)
   float operator*(const Vector& v) const {
      return x*v.x + y*v.y + z*v.z;
   }
   
   // Cross product operator (vector1 cross vector2)
   Vector operator^(const Vector& v) const {
      return {y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
   }
   
   void operator+=(const Vector& v) {
      x += v.x; y += v.y; z += v.z;
   }
   void operator-=(const Vector& v) {
      x -= v.x; y -= v.y; z -= v.z;
   }
   bool operator==(const Vector& v) const {
      return (x == v.x) && (y == v.y) && (z == v.z);
   }
   bool operator!=(const Vector& v) const {
      return (x != v.x) || (y != v.y) || (z != v.z);
   }

};