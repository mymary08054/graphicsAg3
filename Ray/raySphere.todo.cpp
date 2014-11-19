#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySphere.h"

#include <stdio.h>
#include <algorithm>

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RaySphere::intersect(Ray3D ray, RayIntersectionInfo& iInfo, double mx) {
        Point3D cent = this->center;
        double rad = this->radius;

        Point3D dir = ray.direction;
        Point3D w0 = ray.position;
        //equations taken from in class notes
        double A = dir.dot(dir);
        double B = 2 * dir.dot(w0 - cent);
        double C = ((w0 - cent).dot(w0 - cent)) - (rad * rad);
        double disc = (B * B) - (4 * A * C);
        if (disc < 0) {
                return -1;
        }
        double D = sqrt(disc);
        //intersections?
        double q1 = (-B - D) / (2 * A);
        double q2 = (-B + D) / (2 * A);

        //no intersection
        if (q1 < 0 && q2 < 0) {
            return -1;
        }
        if (q1 > 0 && q2 > 0) {
            double q3 = std::min(q1, q2);
            if ((mx < 0) || (q3 < mx)) {
                Point3D P = ray(q3);

                Point3D N = P - cent;
                N /= (N.length());

                if (N.dot(dir) < 0) {
                        iInfo.iCoordinate = P;
                        iInfo.material = material;
                        iInfo.normal = N;
                        iInfo.texCoordinate = Point2D();
                        return q3;

                } else
                        return -1;
            }
        }
        if (q2 > 0) {
            if ((mx < 0) || (q2 < mx)) {
                Point3D P = ray(q2);

                Point3D N = P - cent;
                N /= (N.length());

                if (N.dot(dir) < 0) {
                        iInfo.iCoordinate = P;
                        iInfo.material = material;
                        iInfo.normal = N;
                        iInfo.texCoordinate = Point2D();
                        return q2;
                } else
                        return -1;

            } else
                    return -1;
        }
        
        if (q1 > 0) {
            if ((mx < 0) || (q1 < mx)) {
                Point3D P = ray(q1);

                Point3D N = P - cent;
                N /= (N.length());

                if (N.dot(dir) < 0) {
                        iInfo.iCoordinate = P;
                        iInfo.material = material;
                        iInfo.normal = N;
                        iInfo.texCoordinate = Point2D();
                        return q1;
                } else
                        return -1;

            } else
                    return -1;
        }

        return -1;
}
BoundingBox3D RaySphere::setBoundingBox(void) {
        Point3D list[2];
        list[0] = this->center + Point3D(this->radius, this->radius, this->radius);

        list[1] = this->center - Point3D(this->radius, this->radius, this->radius);
        bBox = BoundingBox3D(list, 2);
        return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
#define SPHERE_SUBDIVISIONS 360
int RaySphere::drawOpenGL(int materialIndex) {
    int mat = material->index;
	if (mat != materialIndex)
		material->drawOpenGL();

	glTranslatef(-center[0], -center[1], -center[2]);	

	GLUquadricObj* quadObj = gluNewQuadric();
	gluSphere(quadObj, radius, SPHERE_SUBDIVISIONS, SPHERE_SUBDIVISIONS);
	
	return mat;
}
