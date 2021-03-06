#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "rayCylinder.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayCylinder::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}

BoundingBox3D RayCylinder::setBoundingBox(void){
	Point3D p;
	p=Point3D(radius,height/2,radius);
	bBox=BoundingBox3D(center+p,center-p);
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
/*
    Interpreting cylinder center as center of circle faces and
    halfway through the column
*/
#define CYLINDER_SUBDIVISIONS 32
int RayCylinder::drawOpenGL(int materialIndex){
    int mat = material->index;
	if (mat != materialIndex)
		//material->drawOpenGL();
	
	glPushMatrix();
    glTranslatef(center[0], center[1]-(height/2), center[2]);	
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f); //rotate about x axis
	GLUquadricObj* quadObj = gluNewQuadric();
	gluCylinder(quadObj, radius, radius, height, CYLINDER_SUBDIVISIONS, CYLINDER_SUBDIVISIONS);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, height);
    gluDisk(quadObj, 0.0f, radius, 30, 1);
    glPopMatrix();
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    gluDisk(quadObj, 0.0f, radius, 30, 1);
    gluDeleteQuadric(quadObj);
    glPopMatrix();	
	
	return mat;
}
