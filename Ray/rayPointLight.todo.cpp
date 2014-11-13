#include <math.h>
#include <GL/glut.h>
#include "rayPointLight.h"
#include "rayScene.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////

Point3D RayPointLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    //eq taken from class
    
    Point3D point = (location - iInfo.iCoordinate).unit();
    double dist = point.length();
    double attenuation = constAtten + linearAtten*dist + quadAtten*pow(dist,2);
    
    Point3D iL = color / attenuation;
    Point3D diffuse = iInfo.material->diffuse * iInfo.normal.dot(point.unit()) * iL;
    return diffuse;
}

Point3D RayPointLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
    //eq taken from class
    Point3D point = (location - iInfo.iCoordinate).unit();
    Point3D V = (cameraPosition - iInfo.iCoordinate).unit();
    Point3D R = iInfo.normal * (iInfo.normal.dot(point) * 2) - point;
    double c = V.dot(R);
    double dist = point.length();

    if (c > 0) {
        double attenuation = constAtten + linearAtten*dist + quadAtten*pow(dist,2);
        double specular = pow(c, iInfo.material->specularFallOff);
        Point3D specPT = (iInfo.material->specular * specular / attenuation) * color;
        return specPT;
    } else {
        return Point3D();
    }
}

int RayPointLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
    Ray3D ray = Ray3D(iInfo.iCoordinate, (location - iInfo.iCoordinate).unit());
    RayIntersectionInfo temp = RayIntersectionInfo();
    
    if (shape->intersect(ray, temp, (iInfo.iCoordinate - location).length()) >= 0) {
        isectCount++;
        return 1;
    }
    return 0;
}

Point3D RayPointLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
    RayIntersectionInfo temp;
    Point3D point = location - iInfo.iCoordinate;
    Ray3D r = Ray3D((iInfo.iCoordinate + point.unit() * RAYEPS), point.unit());
    double t = shape->intersect(r, temp, point.length());
    if (t != -1 && (temp.material->transparent[0] > cLimit[0] || temp.material->transparent[1] > cLimit[1] || temp.material->transparent[2] > cLimit[2])) {
        return temp.material->transparent * transparency(temp, shape, cLimit / temp.material->transparent);
    } else {
        return Point3D(1, 1, 1);
    }
}

//////////////////
// OpenGL stuff //
//////////////////
void RayPointLight::drawOpenGL(int index){
float position[] = {location[0], location[1], location[2], 1};
	float specular[] = {color[0], color[1], color[2]};
	float diffuse[] = {color[0], color[1], color[2]};
	float attenConst[] = {constAtten};
	float attenLin[] = {linearAtten};
	float attenQuad[] = {quadAtten};

	glLightfv(GL_LIGHT0+index,GL_POSITION, position);
	glLightfv(GL_LIGHT0+index, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0+index, GL_CONSTANT_ATTENUATION, attenConst);
	glLightfv(GL_LIGHT0+index, GL_LINEAR_ATTENUATION, attenLin);
	glLightfv(GL_LIGHT0+index, GL_QUADRATIC_ATTENUATION, attenQuad);
	glEnable(GL_LIGHT0+index);
}
