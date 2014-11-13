#include <math.h>
#include <GL/glut.h>
#include "rayDirectionalLight.h"
#include "rayScene.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////

Point3D RayDirectionalLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    Point3D diffusePT = iInfo.material->diffuse;
    double dotProd = iInfo.normal.dot(-direction.unit());
    if (dotProd > 0) {
        diffusePT[0] = dotProd * diffusePT[0];
        diffusePT[1] = dotProd * diffusePT[1];
        diffusePT[2] = dotProd * diffusePT[2];
        return diffusePT;
    } else {
        return Point3D(0, 0, 0);
    }
}

Point3D RayDirectionalLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    Point3D p = (cameraPosition - iInfo.iCoordinate).unit();
    Point3D reflection = (iInfo.normal.unit() * (iInfo.normal.unit().dot(-direction.unit()))*2 + direction.unit()).unit();
    double cos = p.dot(reflection);
    if (cos > 0) {
        double spec = pow(cos, iInfo.material->specularFallOff);
        Point3D specPT = (iInfo.material->specular*spec)*color;
        return specPT;
    } else {
        return Point3D();
    }
}

int RayDirectionalLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
    Ray3D r = Ray3D();
    r.direction = -direction.unit();
    r.position = iInfo.iCoordinate + direction * RAYEPS;

    RayIntersectionInfo t = RayIntersectionInfo();
    if(shape->intersect(r, t, -1) >= 0) {
        isectCount++;
        return 1;
    }
    return 0;
}


Point3D RayDirectionalLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
    Ray3D r = Ray3D();
    r.direction = -direction.unit();
    r.position = iInfo.iCoordinate;
    RayIntersectionInfo t = RayIntersectionInfo();

    double dist = shape->intersect(r,t,-1);
    if (dist > 0) {
        if (t.material->transparent.p[0] < cLimit.p[0] || t.material->transparent.p[1] < cLimit.p[1] || t.material->transparent.p[2] < cLimit.p[2]) {
            return Point3D(1,1,1);
        }
        return t.material->transparent;
    } else {
        return Point3D(1,1,1); }
}

//////////////////
// OpenGL stuff //
//////////////////
void RayDirectionalLight::drawOpenGL(int index){
    float position[] = {-direction[0], -direction[1], -direction[2], 0};
	float specular[] = {color[0], color[1], color[2]};
	float diffuse[] = {color[0], color[1], color[2]};

	glLightfv(GL_LIGHT0+index,GL_POSITION, position);
	glLightfv(GL_LIGHT0+index, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glEnable(GL_LIGHT0+index);
}
