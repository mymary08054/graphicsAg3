#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "rayGroup.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayGroup::intersect(Ray3D ray, RayIntersectionInfo& iInfo, double mx) {

	double temp;
	
	Point3D tempPosition = ray.position;
	Point3D tempCoordinates;
	ray.position = this->getInverseMatrix().multPosition(ray.position);
	ray.direction = this->getInverseMatrix().multDirection(ray.direction);
	ray.direction /= ray.direction.length();
	
	int hitNum = 0;
	
	for (int j = 0; j < this->sNum; j++) {
		temp = this->shapes[j]->bBox.intersect(ray);
		if (temp > 0) {
			this->hits[hitNum].t = temp;
			this->hits[hitNum].shape = this->shapes[j];
			hitNum++;
		}
	}
	
	qsort(this->hits, hitNum, sizeof(RayShapeHit), RayShapeHit::Compare);
	
	for (int i = 0; i < hitNum; i++) {
		if (this->hits[i].t > mx && mx != -1)
			break;
		if (this->hits[i].shape->intersect(ray, iInfo, mx) < 0)
			continue;
		tempCoordinates = this->getMatrix().multPosition(iInfo.iCoordinate);
		temp = (tempCoordinates - tempPosition).length();
		if (temp > 0 && (temp < mx || mx == -1)) {
			mx = temp;
			iInfo.iCoordinate = tempCoordinates;
			iInfo.normal = this->getMatrix().multNormal(iInfo.normal);
			iInfo.normal /= iInfo.normal.length();

		}
	}
	return mx;
}

BoundingBox3D RayGroup::setBoundingBox(void) {
	Point3D* pList;
	BoundingBox3D tBBox;
	pList = new Point3D[sNum * 2];
	for (int i = 0; i < sNum; i++) {
		tBBox = shapes[i]->setBoundingBox();
		pList[2 * i] = tBBox.p[0];
		pList[2 * i + 1] = tBBox.p[1];
	}
	tBBox = BoundingBox3D(pList, sNum * 2);

	delete[] pList;
	bBox = tBBox.transform(getMatrix());
	return bBox;
}

int StaticRayGroup::set(void) {
	normalTransform = inverseTransform.transpose();
	inverseTransform = localTransform.invert();
	return 1;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayGroup::getOpenGLCallList(void) {
	if(sNum>0){
		GLuint g = glGenLists(1);
		glNewList(g, GL_COMPILE);
		drawOpenGL(-1);
		glEndList();
		return g;
	}
	else{
		return 0;
	}
}

int RayGroup::drawOpenGL(int materialIndex) {
	if (openGLCallListID == 0) {
	
		Matrix4D transMatrix = getMatrix();
		//store transformation as an array for glMultMatrix
		//void glMultMatrixf(	const GLfloat *  	m)
		//m - Points to 16 consecutive values that are used as the elements of a 4 × 4 column-major matrix.
		float transArray[] = {transMatrix(0,0), transMatrix(0,1), transMatrix(0,2), transMatrix(0,3),
						   transMatrix(1,0), transMatrix(1,1), transMatrix(1,2), transMatrix(1,3),
						   transMatrix(2,0), transMatrix(2,1), transMatrix(2,2), transMatrix(2,3),
						   transMatrix(3,0), transMatrix(3,1), transMatrix(3,2), transMatrix(3,3)};

		GLint viewPort[4];
		glGetIntegerv(GL_VIEWPORT, viewPort);
		//iterate through shapes in group
	    for (int i = 0; i < sNum; i++) {
		    glMatrixMode(GL_MODELVIEW);
		    glPushMatrix();
		    glMultMatrixf(transArray);
		    shapes[i]->drawOpenGL(materialIndex);
		    glPopMatrix();
	    }
	}
	else{
	glCallList(openGLCallListID);
	}
	return -1;
}

/////////////////////
// Animation Stuff //
/////////////////////
Matrix4D ParametrizedEulerAnglesAndTranslation::getMatrix(void) {
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedClosestRotationAndTranslation::getMatrix(void) {
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedRotationLogarithmAndTranslation::getMatrix(void) {
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedQuaternionAndTranslation::getMatrix(void) {
	return Matrix4D::IdentityMatrix();
}
