#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "rayBox.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayBox::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RayBox::setBoundingBox(void){
	bBox=BoundingBox3D(center-(length/2),center+(length/2));
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayBox::drawOpenGL(int materialIndex){
    int mat = material->index;
	if (mat != materialIndex)
		material->drawOpenGL();
		
	int xlength = fabs(center[0]-length[0])*2;
	int ylength = fabs(center[1]-length[1])*2;
	int zlength = fabs(center[2]-length[2])*2;
	
	glPushMatrix();
    glTranslatef(center[0], center[1], center[2]);	
    glScalef (xlength,ylength,zlength);
    glutSolidCube(1.0);
    glPopMatrix();	
	
	return mat;
}
