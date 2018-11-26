#ifndef _VOLUME_H_
#define _VOLUME_H_

#include <RayTracing/Hitable.h>

namespace RayTracing {
	class Volume : public Hitable{
		HITABLE_SETUP(Volume)
	public:
		Volume(const Hitable::CPtr & boundary = NULL, float density = 1.0f, const Material::CPtr & material = NULL);

		virtual HitRst RayIn(Ray::Ptr & ray) const;
		virtual const AABB GetBoundingBox() const { return boundary ? boundary->GetBoundingBox() : AABB::InValid; }
	private:
		const Hitable::CPtr boundary;
		const float density;
	};
}

#endif // !_VOLUME_H_