#include <GL/glut.h>
#include <math.h>
#include "rayCamera.h"



//////////////////
// OpenGL stuff //
//////////////////
void RayCamera::drawOpenGL(void){
    gluLookAt(position[0],position[1],position[2],direction[0],direction[1],direction[2],up[0],up[1],up[2]);
}
void RayCamera::rotateUp(Point3D center,float angle){
}
void RayCamera::rotateRight(Point3D center,float angle){
	float theta = acosf(Point3D(1, 0, 0).dot(up.unit()));
	float gamma = acosf(Point3D(0, 1, 0).dot(up.unit()));
	glTranslatef(-center[0]+position[0], -center[1]+position[1], -center[2]+position[2]);
	glRotatef(theta, 1, 0, 0);
	glRotatef(gamma, 0, 1, 0);
	glRotatef(angle*180/PI, right[0], right[1], right[2]);
	glRotatef(-theta, 1, 0, 0);
	glRotatef(-gamma, 0, 1, 0);
	glTranslatef(center[0]-position[0], center[1]-position[1], center[2]-position[2]);
}
void RayCamera::moveForward(float dist){
    position -= direction*dist; //move in direction
                                //we're facing
}
void RayCamera::moveRight(float dist){
    //right side should be perpindicular
    //position += (position.crossProduct(direction))*dist;
    glTranslatef(right[0]*dist, right[1]*dist, right[2]*dist);
}
void RayCamera::moveUp(float dist){
    //position += up*dist;
    glTranslatef(up[0]*dist, up[1]*dist, up[2]*dist);
}
