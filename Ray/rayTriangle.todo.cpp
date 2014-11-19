#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rayTriangle.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
void RayTriangle::initialize(void){
}

#define SMALL_NUM   0.00000001 // anything that avoids division overflow

double RayTriangle::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
    Point3D    v0v1, v0v2, norm;              // triangle vectors
    Point3D    dir, w0;           // ray vectors
    Point3D P; //intersection point

    //norm is the triangle's normal vector
    v0v1 = this->v[1]->position - this->v[0]->position;
    v0v2 = this->v[2]->position - this->v[0]->position;
    /*printf("\nv0 ");
    this->v[0]->position.printout();
    printf("\nv1 ");
    this->v[1]->position.printout();
    printf("\nv2 ");
    this->v[2]->position.printout();*/
    norm = v0v1.crossProduct(v0v2);              // cross product
    dir = ray.direction;
    //are the triangle and ray parallel?
    if(norm.dot(dir) == 0)
        return -1; //if so, no intersection
    //printf("got 1\n");
    //P = w0 + dir*t
    //want to find t to fin P intersection
    
    w0 = ray.position;
    
    //find distance D from origin to triangle plane
    float D = norm.dot(this->v[0]->position);
    //find t
    //equation derived from substituting P in the following:
    //P = w0 + dir*t
    //Ax+By+Cz+D=0 (plane that the triangle is in)
    float t = - (norm.dot(w0) + D) / norm.dot(dir);
    
    if(t<0) //triangle is behind camera
        return -1;
    //printf("got 2\n");
    P = w0 +dir*t; //P is intersection point
    
    ///////////////////
    //Inside out test//
    ///////////////////
    Point3D perp; //vector perp to triangle's plane
 
    Point3D v1v0 = this->v[1]->position - this->v[0]->position;
    Point3D Pv0 = P - this->v[0]->position;
    perp = v1v0.crossProduct(Pv0);
    if (norm.dot(perp) < 0)
        return -1;
 
    Point3D v2v1 = this->v[2]->position - this->v[1]->position;
    Point3D Pv1 = P - this->v[1]->position;
    perp = v2v1.crossProduct(Pv1);
    if (norm.dot(perp) < 0)
        return -1;
 
    Point3D v0v2_ = this->v[0]->position - this->v[2]->position;
    Point3D Pv2 = P - this->v[2]->position;
    perp = v0v2_.crossProduct(Pv2);
    if (norm.dot(perp) < 0)
        return -1;
    //printf("got 3\n");
    //This ray intersects
    iInfo.iCoordinate = P;
    iInfo.material = material;
    iInfo.normal = norm;
    iInfo.texCoordinate = Point2D();
    double xterm = P.p[0] - w0.p[0];
    double yterm = P.p[1] - w0.p[1];
    double zterm = P.p[2] - w0.p[2];
    double dist = sqrt(pow(xterm,2)+pow(yterm,2)+pow(zterm,2));
    if(mx <= 0) {
        return dist;
    }
    else if(mx > 0 && dist <= mx) {
        return dist;
        }
    else {
        return -1;
    }
}
BoundingBox3D RayTriangle::setBoundingBox(void){
	Point3D pList[3];
	pList[0] = v[0]->position;
	pList[1] = v[1]->position;
	pList[2] = v[2]->position;
	bBox = BoundingBox3D(pList, 3);
	for (int i = 0; i < 3; i++) {
		bBox.p[0][i] -= RAYEPS;
		bBox.p[1][i] += RAYEPS;
	}
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayTriangle::drawOpenGL(int materialIndex){
    int mat = material->index;
	if (mat != materialIndex)
		material->drawOpenGL();

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0,0);
    Point3D pt = v[0]->position;
    int i = 0;
    glNormal3d(v[i]->normal[0],v[i]->normal[1],v[i]->normal[2]);
    glVertex3f(pt[0],pt[1],pt[2]);
    
    glTexCoord2f(1,0);
    pt = v[1]->position;
    i = 1;
    glNormal3d(v[1]->normal[0],v[i]->normal[1],v[i]->normal[2]);
    glVertex3f(pt[0],pt[1],pt[2]);
    
    glTexCoord2f(1,1);
    pt = v[2]->position;
    i = 2;
    glNormal3d(v[2]->normal[0],v[i]->normal[1],v[i]->normal[2]);
    glVertex3f(pt[0],pt[1],pt[2]);
    /*for (int i = 0; i < 3; i++){
        
        Point3D pt = v[i]->position;
        
        glNormal3d(v[i]->normal[0],v[i]->normal[1],v[i]->normal[2]);
        //pt.printout();
        glVertex3f(pt[0],pt[1],pt[2]);
    }*/
    glEnd();
    
    //This shape will appear
    /*glBegin(GL_POLYGON);
    printf("triangle");
    for (int i = 0; i < 3; i++){
        Point3D pt = v[i]->position;
        pt.printout();
        glVertex3f(-pt.p[0],pt.p[1],-pt.p[2]);
    }
    glEnd();*/
	return mat;
}
