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
