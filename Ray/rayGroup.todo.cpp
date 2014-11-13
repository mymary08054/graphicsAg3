#include <stdlib.h>
#include <GL/glut.h>
#include "rayGroup.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////

double RayGroup::intersect(Ray3D ray, RayIntersectionInfo& iInfo, double mx) {

        //return -1;

        int numShapes = sNum;

        double minIntersection = mx;

        Ray3D newRay = Ray3D();
        newRay.direction = getInverseMatrix().multDirection(ray.direction);
        newRay.position = getInverseMatrix().multPosition(ray.position);
        newRay.direction /= newRay.direction.length();

        int i;
        int j = 0;

        for (i = 0; i < sNum; i++) {
                //Perform an intersection on each shape
                RayShape* tempS = *(shapes + i);

                // Bounding box test
                double boundingBoxIntersection = shapes[i]->bBox.intersect(newRay);
                if (boundingBoxIntersection > 0) {
                        hits[j].t = boundingBoxIntersection;
                        hits[j].shape = shapes[i];
                        j++;
                }
        }

        qsort(hits, j, sizeof(RayShapeHit), RayShapeHit::Compare);

        for (i = 0; i < j; i++) {

                if (hits[i].t > minIntersection && minIntersection != -1) {
                        break;
                }

                //Perform an intersection on each shape
                RayShape* tempS = hits[i].shape;

                RayIntersectionInfo tempiInfo = RayIntersectionInfo();
                double tempIntersection = tempS->intersect(newRay, tempiInfo,
                                minIntersection);

                if (tempIntersection != -1) // We have an intersection
                                {

                        if (minIntersection == -1 || minIntersection > tempIntersection) {

                                tempiInfo.iCoordinate = getNormalMatrix()
                                                * tempiInfo.iCoordinate;
                                tempiInfo.normal = getNormalMatrix().multNormal(
                                                tempiInfo.normal);
                                tempiInfo.normal /= tempiInfo.normal.length();

                                minIntersection =
                                                (tempiInfo.iCoordinate - newRay.position).length();
                                iInfo = tempiInfo;

                        }
                }
        }

        // Return the minimum value at the end.
        if (mx > 0 && minIntersection > mx) {
                return -1;
        }

        return minIntersection;
}

BoundingBox3D RayGroup::setBoundingBox(void) {

        Point3D allThePoints[2 * sNum];

        int i;
        for (i = 0; i < sNum; i++) {
                RayShape *tempShape = *(shapes + i);
                tempShape->setBoundingBox();

                Point3D temp1 = tempShape->bBox.p[0];
                Point3D temp2 = tempShape->bBox.p[1];

                allThePoints[2 * i] = temp1;
                allThePoints[2 * i + 1] = temp2;

        }

        bBox = BoundingBox3D(allThePoints, 2 * sNum);

        bBox = bBox.transform(getNormalMatrix());

        return bBox;
}

int StaticRayGroup::set(void) {
        Matrix4D m = getMatrix();
        this->normalTransform = m;
        this->inverseTransform = m.invert();

        return 1;
}
//////////////////
// OpenGL stuff //
//////////////////
int RayGroup::getOpenGLCallList(void) {
        if(sNum>0){
		GLuint displayList = glGenLists(1); //display list
		glNewList(displayList, GL_COMPILE);
		drawOpenGL(-1); //store group in displaylist
		glEndList();
		return displayList;
	}
	else{
		return 0;
	}
}

#define MATRIX_SIZE 4

int RayGroup::drawOpenGL(int materialIndex) {
if (openGLCallListID == 0) {
		Matrix4D transMatrix = getMatrix();
		
		//fMatrix holds the transformation matrix
        float fMatrix [MATRIX_SIZE*MATRIX_SIZE];
        int count = 0;
        for(int i = 0; i < MATRIX_SIZE; i++) {
            for(int j = 0; j < MATRIX_SIZE; j++) {
                fMatrix[count++] = transMatrix(i,j);
            }
        }

    GLint viewPort[4];
    /*
    params returns four values: the x and y window coordinates of the viewport, followed by its width and height. Initially the x and y window coordinates are both set to 0, and the width and height are set to the width and height of the window into which the GL will do its rendering.
    */
		glGetIntegerv(GL_VIEWPORT, viewPort);

		float jitMatrix[5][2];
		jitMatrix[0][0] = 0.5; jitMatrix[0][1] = 0.5;
		jitMatrix[1][0] = 0.3; jitMatrix[1][1] = 0.1;
		jitMatrix[2][0] = 0.7; jitMatrix[2][1] = 0.9;
		jitMatrix[3][0] = 0.9; jitMatrix[3][1] = 0.3;
		jitMatrix[4][0] = 0.1; jitMatrix[4][1] = 0.7;
	
		glClear(GL_ACCUM_BUFFER_BIT);
		int jitNum = 1;
		for (int j = 0; j < jitNum; j++) {		
			for (int i = 0; i < sNum; i++) {
				glMatrixMode(GL_MODELVIEW);
				glPushMatrix();
				glTranslatef(jitMatrix[j][0]/viewPort[2], jitMatrix[j][1]/viewPort[3], 0);
				glMultMatrixf(fMatrix);
				shapes[i]->drawOpenGL(materialIndex);
				glAccum(GL_ACCUM, 1/jitNum);
				glPopMatrix();
			}
		}
		glAccum(GL_RETURN, 1.0);
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
