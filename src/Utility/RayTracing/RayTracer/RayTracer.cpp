#include <RayTracing/RayTracer.h>

using namespace RayTracing;
using namespace glm;

rgb RayTracer::Trace(const Hitable::CPtr & scene, Ray::Ptr & ray, size_t depth) {
	if (depth == 0)
		return rgb(1.0001f / 255.0f);

	auto hitRst = scene->RayIn(ray);
	if (hitRst.hit) {
		if (hitRst.material == NULL)
			return rgb(1, 0, 1);

		if (hitRst.material->Scatter(hitRst.record))
			return RayTracer::Trace(scene, ray, depth - 1);
		else
			return ray->GetColor();
	}
	else
		return rgb(1.0001f / 255.0f);
}