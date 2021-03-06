/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef VEC2_H_8BJJJ5TN
#define VEC2_H_8BJJJ5TN

#include <string>
#include <cmath>
#include <utils/algorithm.h>

/* QUESTION kaspars: Move to some common header file maybe? */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/// A two-dimensional vector.
class vec2 {
public:
  /// Default constructor doesn't initialize anything.
  vec2() {}
  vec2(float x, float y) : x(x), y(y) {}
  
  vec2 operator - () const {return vec2(-x, -y); }


  vec2 &operator *= (const vec2 &rhs) {x *= rhs.x; y *= rhs.y; return *this; }
  vec2 &operator *= (float scalar) {x *= scalar; y *= scalar; return *this; }
  vec2 &operator /= (float scalar) {x /= scalar; y /= scalar; return *this; }
  
  template<typename OtherT>
  vec2 operator * (const OtherT &rhs) const {return vec2(*this) *= rhs; }
  vec2 operator / (float scalar) {return vec2(*this) /= scalar; }
  vec2 &operator += (const vec2 &rh) {x += rh.x; y += rh.y; return *this; }
  vec2 &operator -= (const vec2 &rh) {x -= rh.x; y -= rh.y; return *this; }
  vec2 operator + (const vec2 &rh) const {return vec2(*this) += rh; }
  vec2 operator - (const vec2 &rh) const {return vec2(*this) -= rh; }
  
  /// Textual representation of a vector for easy outputting
  operator std::string() const;
  
  static vec2 Zero();
  static vec2 Identity();
  static vec2 FromDegrees(double degrees);
  
  float x;
  float y;
};

inline float dot(const vec2 &v1, const vec2 &v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

inline vec2 closest_point(const vec2 &start, const vec2 &end, const vec2 &pos) {
  vec2 ap = pos - start;
  vec2 ab = end - start;
  float ab2 = dot(ab, ab);
  float apab = dot(ap, ab);
  float t = apab / ab2;

  return ab * clamp(t, 0.0f, 1.0f) + start;
}

inline double degrees(const vec2 &v) {
  return atan2(v.y, v.x) / M_PI * 180.0;
}

inline float length(const vec2 &v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

inline vec2 normalized(const vec2 &v) {
  vec2 nv = v;
  float mag = length(nv);
  if (mag > 0.0f) {
    nv.x /= mag;
    nv.y /= mag;
  }
  
  return nv;
}

// TODO: research if it's possible to autogenerate x, y, z etc names over
// elements[3]

#endif /* end of include guard: VEC2_H_8BJJJ5TN */
