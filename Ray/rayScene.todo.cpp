#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

///////////////////////
// Ray-tracing stuff //
///////////////////////

void printPoint(Point3D p) {
        printf("%f\t%f\t%f\n", p[0], p[1], p[2]);
}

Point3D RayScene::Reflect(Point3D v, Point3D n) {
    Point3D Reflection = v-(n*2*(v.dot(n)));
    return Reflection;
}

int RayScene::Refract(Point3D v, Point3D n, double ir, Point3D& refract) {
    v = -(v);
    if (n.dot(v) < 0) {
            ir = 1 / ir;
            n = n * -1;
    }
    double a = acos(v.dot(n));
    double c = sin(a) / ir;
    if (c > 1 || c < -1) {
            return 0;
    }
    double b = asin(c);
    refract = n * ((1 / ir)*cos(a)-cos(b))-v*(1/ir);
    refract /= refract.length();
    return 1;
}

Ray3D RayScene::GetRay(RayCamera* camera, int i, int j, int width, int height) {

    Point3D p0 = camera->position;
    //pick arbitrary distance value from camera to
    //view screen
    double d = 1;
    double a = (camera->heightAngle)/2;
    Point3D up = camera->up;
    Point3D dir = camera->direction;
    Point3D right = camera->right;

    //equations modified from in class notes
    Point3D p1 = p0 + (dir * d) - (right * d * tan(a)) - (up * d * tan(a));
    Point3D p2 = p0 + (dir * d) + (right * d * tan(a)) - (up * d * tan(a));
    Point3D p3 = p0 + (dir * d) - (right * d * tan(a)) + (up * d * tan(a));
    Point3D p4 = p0 + (dir * d) + (right * d * tan(a)) + (up * d * tan(a));
    
    //for each point on the screen
    Point3D pij = p1 + (p2 - p1) * ((i + .5) / width) + (p3 - p1) * ((j + .5) / height);

    Point3D raydir = pij - p0;
    
    //normalize
    raydir /= raydir.length();

    return Ray3D(p0, raydir);
}

bool t = true;
Point3D RayScene::GetColor(Ray3D ray, int rDepth, Point3D cLimit) {
        // Declare vars
        Point3D color; //return value
        double dist;
        double var = 0.0001;
        int shadow, numIntersections = 0;
        RayIntersectionInfo iInfo;
        Ray3D refractPT, reflectedRay;
        Point3D reflect, reflectedColor, refractedColor;
        
        // run intersect to get dist to obj
        dist = group->intersect(ray, iInfo, -1);
        if (dist == -1) { //ray missed, return bg color
                return background;
        }

        // Ambient & emissive
        color = ambient * iInfo.material->ambient + iInfo.material->emissive;
        if (ray.direction.dot(iInfo.normal) < 0) { //obj is front facing
                /////////////////////////
                //shadow & transparency//
                ////////////////////////
                for (int j = 0; j < this->lightNum; j++) {
                        // Are we in shadow?
                        shadow = this->lights[j]->isInShadow(iInfo, this->group,
                                        numIntersections);
                        // transparency
                        Point3D transp = lights[j]->transparency(iInfo, group, cLimit);

                        color += this->lights[j]->getDiffuse(ray.position, iInfo) * transp;
                        color += this->lights[j]->getSpecular(ray.position, iInfo) * transp;
                }

                ///////////////
                // reflection//
                ///////////////
                reflect = Reflect(ray.direction, iInfo.normal);
                reflectedRay = Ray3D(iInfo.iCoordinate, reflect);
                reflectedRay.position = reflectedRay(var);
                if (rDepth > 0 && (iInfo.material->specular[0] > cLimit[0])
                                && (iInfo.material->specular[1] > cLimit[1])
                                && (iInfo.material->specular[2] > cLimit[2])) {
                        // recurse getcolor to get reflections
                        reflectedColor = GetColor(reflectedRay, rDepth - 1,
                                        (cLimit / iInfo.material->specular));
                        // prevent bg color from effecting reflections
                        if (reflectedColor.p[0] == background.p[0]
                                        && reflectedColor.p[1] == background.p[1]
                                        && reflectedColor.p[2] == background.p[2]) {
                                reflectedColor = Point3D();
                        }
                        // Add reflected colors
                        reflectedColor *= iInfo.material->specular;
                        color += reflectedColor;
                }
        }
        //////////////
        //refraction//
        //////////////
        if (this->Refract(ray.direction, iInfo.normal, iInfo.material->refind,
                        refractPT.direction)) {
                refractPT.position = iInfo.iCoordinate;
                refractPT.position = refractPT(var);
                refractedColor = this->GetColor(refractPT, rDepth - 1, cLimit);
                if (refractedColor.p[0] == background.p[0]
                                && refractedColor.p[1] == background.p[1]
                                && refractedColor.p[2] == background.p[2]) {
                        refractedColor = Point3D();
                }
                refractedColor *= iInfo.material->transparent;
                color += refractedColor;
        }

        //bound the color value in case of outliers
        for (int i = 0; i < 3; i++)
                if (color.p[i] > 1)
                        color.p[i] = 1;


        for (int i = 0; i < 3; i++)
                if (color.p[i] < 0)
                        color.p[i] = 0;

        return color;
}


// OpenGL stuff //
//////////////////

void RayMaterial::drawOpenGL(void) {

    //Background color
    //glClearColor(0,0,0,1);
    /////////////////////
    GLfloat matDiffuse[] = {diffuse[0], diffuse[1], diffuse[2]};
	GLfloat matSpecular[] = {specular[0], specular[1], specular[2]};
	GLfloat matEmissive[] = {emissive[0], emissive[1], emissive[2]};
	GLfloat matAmbient[] = {ambient[0], ambient[1], ambient[2]};
	GLfloat matShiny[] = {specularFallOff};
    //GLfloat matShiny = 100;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEmissive);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShiny);

    /*glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matEmissive);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, matShiny);*/
  
  
/*	glEnable(GL_TEXTURE_2D);
		if (tex != NULL) {
			(*tex).setUpOpenGL();
			glBindTexture(GL_TEXTURE_2D,(*tex).openGLHandle);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);*/
	
	///////////////////////////////		
    //glClear(GL_COLOR_BUFFER_BIT );
    //glFlush();
    //////////////////////////////
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->img->width(), tex->img->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex->img->getPixels());
//}
}
void RayTexture::setUpOpenGL(void) {
    glGenTextures(1,&openGLHandle);
}
