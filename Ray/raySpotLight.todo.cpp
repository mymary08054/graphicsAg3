#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySpotLight.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////

Point3D RaySpotLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    //declare variables
    Point3D diffusePT = iInfo.material->diffuse;
    Point3D p = iInfo.iCoordinate - location;
    double distance = p.length();
    double dot = iInfo.normal.dot(-direction.unit());
    double d = p.unit().dot(direction.unit());

    if(d < cos(cutOffAngle) || dot < 0) {
        return Point3D();
    }
    diffusePT = diffusePT * dot * pow(d, dropOffRate);
    
    //find atten for each coord
    double attenuation = constAtten + linearAtten*distance + quadAtten*pow(distance,2);
    diffusePT[0] *= color[0]/attenuation;
    diffusePT[1] *= color[1]/attenuation;
    diffusePT[2] *= color[2]/attenuation;

    return diffusePT;
}

Point3D RaySpotLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    Point3D p = location - iInfo.iCoordinate;
    double distance = p.length();
    p = p / distance;
    Point3D reflection = p - (iInfo.normal * (iInfo.normal.dot(p)) * 2);
    Point3D l = cameraPosition - iInfo.iCoordinate;
    l = l / l.length();
    double attenuation = constAtten + linearAtten*distance + quadAtten*pow(distance,2);
    Point3D specPT = color / attenuation;
    double temp = -p.dot(direction);
    double spec = reflection.dot(l);

    if (temp < 0) {
        return Point3D();
    }
    if (temp > cos(cutOffAngle)) {
        return iInfo.material->specular * pow(temp, dropOffRate) * pow(spec, iInfo.material->specularFallOff) * specPT;
    } else {
        return Point3D();
    }
}

int RaySpotLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
    Ray3D ray;
    ray.direction = iInfo.iCoordinate - location;
    ray.direction = ray.direction / ray.direction.length();
    ray.position = iInfo.iCoordinate + ray.direction * RAYEPS;

    if (ray.direction.dot(direction) > cos(cutOffAngle)) {
        isectCount++;
    }
    return 1;
    if (ray.direction.dot(iInfo.normal) < 0) {
        isectCount++;
    }
    return 1;

    RayIntersectionInfo temp;
    if (shape->intersect(ray, temp, -1) == -1) {
        return 0;
    } else {
        isectCount++;
    }
    return 1;
}

Point3D RaySpotLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
    Ray3D ray;
    ray.direction = location - iInfo.iCoordinate;
    double t = ray.direction.length();
    ray.direction = ray.direction / ray.direction.length();
    ray.position = iInfo.iCoordinate + ray.direction * RAYEPS;
    
    
    if (ray.direction.dot(iInfo.normal) < 0) { //no intersection
        return Point3D(0, 0, 0);
    }
    RayIntersectionInfo temp;
    Point3D trans = Point3D(1, 1, 1);
    double dis = shape->intersect(ray, temp, t);
    if (dis == -1) { //no intersection, no transp needed
        return Point3D(1, 1, 1);
    }
    while (dis != -1 && trans.p[0] >= cLimit.p[0] && trans.p[1] >= cLimit.p[1] && trans.p[2] >= cLimit.p[2]) {
        trans = trans * temp.material->transparent;
        ray.position = temp.iCoordinate + ray.direction * RAYEPS;
        dis = shape->intersect(ray, temp, t);
    }
    return trans;
}

//////////////////
// OpenGL stuff //
//////////////////
void RaySpotLight::drawOpenGL(int index){
float position[] = {location[0], location[1], location[2], 1};
	float specular[] = {color[0], color[1], color[2]};
	float diffuse[] = {color[0], color[1], color[2]};
	float attenConst[] = {constAtten};
	float attenLin[] = {linearAtten};
	float attenQuad[] = {quadAtten};
	float spotDir[] = {direction[0], direction[1], direction[2]};
	float spotExp[] = {dropOffRate};
	float spotCutOff[] = {cutOffAngle*180/PI};

	glLightfv(GL_LIGHT0+index,GL_POSITION, position);
	glLightfv(GL_LIGHT0+index, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0+index, GL_CONSTANT_ATTENUATION, attenConst);
	glLightfv(GL_LIGHT0+index, GL_LINEAR_ATTENUATION, attenLin);
	glLightfv(GL_LIGHT0+index, GL_QUADRATIC_ATTENUATION, attenQuad);
	glLightfv(GL_LIGHT0+index, GL_SPOT_DIRECTION, spotDir);
	glLightfv(GL_LIGHT0+index, GL_SPOT_EXPONENT, spotExp);
	glLightfv(GL_LIGHT0+index, GL_SPOT_CUTOFF, spotCutOff);
	glEnable(GL_LIGHT0+index);
}
