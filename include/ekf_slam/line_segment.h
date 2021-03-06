#ifndef LINE_SEGMENT_H_
#define LINE_SEGMENT_H_

#include "ekf_slam/common.h"
namespace ekf_slam{
/**
 * line structure using polar representation
 * r = x * cos(alpha) + y * sin(alpha)
 * End point is two points that 
 */
class LineSegment{
public:
  double alpha_;
  double r_;
  int start_idx_;
  int end_idx_;
  LineSegment(const double& alpha=0, const double& r=0, const int& start_idx=-1, const int& end_idx=-1)
    :alpha_(alpha),r_(r),start_idx_(start_idx),end_idx_(end_idx){}
  
  //convert the LineSegment to Frame T, used to add mapping entry in Map class 
  //return if negative r occurs 
  bool convertToFrameT(const Vector3d& T);
  //return alpha and r as a vector, used in ekf
  Vector2d vector() const;
  //return alpha and r observed in pose T, used in ekf
  Vector2d vectorInFrameT(const Vector3d& T, bool& isNegative) const;
  
};
}
#endif