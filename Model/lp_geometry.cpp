#include "lp_geometry.h"

LP_GeometryImpl::LP_GeometryImpl(LP_Object parent) : LP_ObjectImpl(parent)
  ,mGLInitialized(false)
  ,mBBmin({std::numeric_limits<float>::max(),
          std::numeric_limits<float>::max(),
          std::numeric_limits<float>::max()})
  ,mBBmax({-std::numeric_limits<float>::max(),
          -std::numeric_limits<float>::max(),
          -std::numeric_limits<float>::max()})
{

}

void LP_GeometryImpl::BoundingBox(QVector3D &bbmin, QVector3D &bbmax)
{
    bbmin = mBBmin;
    bbmax = mBBmax;
}

void LP_GeometryImpl::SetBoundingBox(const QVector3D &min, const QVector3D &max)
{
    mBBmin = min;
    mBBmax = max;
}

LP_GeometryImpl::~LP_GeometryImpl()
{

}
