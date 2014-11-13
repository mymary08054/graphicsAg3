#include <stdlib.h>
#include <math.h>

#include <SVD/SVDFit.h>
#include <SVD/MatrixMNTC.h>

#include "geometry.h"


///////////////////////
// Ray-tracing stuff //
///////////////////////
double BoundingBox3D::intersect(const Ray3D& ray) const {
	Point3D position = ray.position;
	Point3D direction = ray.direction;
	Point3D min = p[0];
	Point3D max = p[1];
	Point3D minP;
	Point3D maxP;

	if (min[0] < position[0] && max[0] < position[0] && min[1] < position[1]
	                                                                      && position[1] < max[1] && min[2] < position[2]
	                                                                                                                   && position[2] < max[2]) {
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		float t1 = (min[i] - position[i]) / direction[i];
		float t2 = (max[i] - position[i]) / direction[i];
		if (t1 < t2) {
			minP[i] = t1;
			maxP[i] = t2;
		} else {
			minP[i] = t2;
			maxP[i] = t1;
		}
	}

	float intersect = -1.0f;
	
	for (int i = 0; i < 3; i++) {
		if (minP[i] < 0 && maxP[i] < 0)
			break;

		float minimumInt = (minP[i] > 0 ? minP[i] : maxP[i]);
		int d1 = (i + 1) % 3;
		int d2 = (i + 2) % 3;
		if (!(minP[d1] < minimumInt && minimumInt < maxP[d1]))
			continue;
		if (!(minP[d2] < minimumInt && minimumInt < maxP[d2]))
			continue;

		intersect = (0 < intersect && intersect < minimumInt) ? intersect : minimumInt;
	}
	
	return intersect;
}

/////////////////////
// Animation stuff //
/////////////////////
Matrix3D::Matrix3D(const Point3D& e){
	(*this)=Matrix3D();
}

Matrix3D::Matrix3D(const Quaternion& q){
	(*this)=Matrix3D();
}
Matrix3D Matrix3D::closestRotation(void) const {
	return (*this);
}
/* While these Exp and Log implementations are the direct implementations of the Taylor series, the Log
 * function tends to run into convergence issues so we use the other ones:*/
Matrix3D Matrix3D::Exp(const Matrix3D& m,int iter){
	return m;
}
