#include "rayScene.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <cstdlib>

///////////////////////
// Ray-tracing stuff //
///////////////////////

Point3D RayScene::Reflect(Point3D v, Point3D n) {
	return (v - (n * (v.dot(n)) * 2)); //page 87 of Shirley
}

int RayScene::Refract(Point3D v, Point3D n, double ir, Point3D& refract) {
	v = v * -1;
	if (n.dot(v) < 0) {
		ir = 1 / ir;
		n = n * -1;
	}
	if (sin(acos(v.dot(n))) / ir > 1 || sin(acos(v.dot(n))) / ir < -1)
		return 0;
	refract = n
			* ((1 / ir) * cos(acos(v.dot(n)))
					- cos(asin(sin(acos(v.dot(n))) / ir))) - v * (1 / ir);
	refract /= refract.length();
	return 1;
}

Ray3D RayScene::GetRay(RayCamera* camera, int i, int j, int width, int height) {
	Ray3D ray;
	Point3D p;
	ray.position = camera->position;
	p = camera->position
			+ (camera->direction)
			* (height / (2 * tan(camera->heightAngle / 2)))
			+ (camera->up) * (j + .5 - (height / 2))
			+ (camera->right) * (i + .5 - (width / 2));
	ray.direction = (p - camera->position) / ((p - camera->position).length());

	return ray;
	
	//JITTER//
	// Ray3D ray;
	// ray.position = camera->position;
	// float u = tan(camera->heightAngle/2.0);
	// float r = camera->aspectRatio*u;
	// float x = (float)rand();
	// x /=(float)RAND_MAX;
	// float y = (float)rand();
	// y/=(float)RAND_MAX;
	// float sR = ((float)i+x)/((float)width);
	// float sU = ((float)j+y)/((float)height);
	// ray.direction = camera->direction+(camera->right*(2.0*sR-1.0)*r)+(camera->up*(2.0*sU-1.0)*u);

	// return ray;

}

Point3D RayScene::GetColor(Ray3D ray, int rDepth, Point3D cLimit) {

	/*	--------Slides Pseudocode----
	 Point3D p(0,0,0);
	 Ray3D reflect, refract;
	 Intersection hit=FindIntersection(ray,scene);
	 if (hit){
	 p+=GetSurfaceColor(hit.position);

	 reflect.direction = Reflect(ray.direction, hit.normal);
	 reflect.position = hit.position + reflect.direction*epsilon;
	 if(rDepth>0 && hit.kSpec>cLimit){
	 p+=GetColor(scene, reflect, depth-1, cutOff/hit.kSpec)*hit.kSpec;
	 }

	 refract.direction=Refract(ray.direction, hit.normal, hit.ir);
	 refract.position = hit.position+refract.direction*epsilon;
	 if(depth>0 && hit.kTran>cutOff){
	 p+=GetColor(scene, refract, depth-1, cutOff/hit.kTran)*hit.kTran;
	 }
	 }

	 return p;
	 */

	RayIntersectionInfo iInfo = RayIntersectionInfo();
	double intersect = group->intersect(ray, iInfo, -1);
	Point3D diffuse = Point3D();
	Point3D specular = Point3D();
	Point3D reflectP = Point3D();
	Point3D refractP = Point3D();
	Point3D shadow = Point3D();
	Point3D trans = Point3D();
	Point3D texColor = Point3D();

	Ray3D reflectR = Ray3D();
	Ray3D refractR = Ray3D();
	
	texColor = Point3D(1, 1, 1);

	if (intersect > 0) {

	/* TEXTURE MAPPING */

	// if (intersect < 0) {
	// 	return Point3D(0, 0, 0);
	// }

	// else {
	// 	if (iInfo.material->tex != 0) {
	// 		Image32* tex = iInfo.material->tex->img;
	// 		Pixel t = Pixel(
	// 				tex->BilinearSample(iInfo.texCoordinate[0] * tex->width(),
	// 						iInfo.texCoordinate[1] * tex->height()));
	// 		texColor[0] = t.r;
	// 		texColor[1] = t.r;
	// 		texColor[2] = t.r;
	// 	}

		for (int i = 0; i < lightNum; i++) {
			trans = lights[i]->transparency(iInfo, group, cLimit);
			diffuse += lights[i]->getDiffuse(camera->position, iInfo)*trans;
			specular += lights[i]->getSpecular(camera->position, iInfo)*trans;

			/*			SHADOWS							*/
			// if (lights[i]->isInShadow(iInfo, group, i) == 1)
			// 	shadow += (diffuse + specular);
		}

		/* REFLECT */
		if (iInfo.normal.dot(ray.direction) > 0) {
			reflectR.direction = this->Reflect(ray.direction, iInfo.normal);
			reflectR.direction = reflectR.direction.unit();
			reflectR.position = iInfo.iCoordinate + reflectR.direction * RAYEPS;
			if (rDepth > 0
					&& (iInfo.material->specular.p[0] > cLimit.p[0]
					                                             || iInfo.material->specular.p[1] > cLimit.p[1]
					                                                                                         || iInfo.material->specular.p[2] > cLimit.p[2])) {
				reflectP += iInfo.material->specular
						* this->GetColor(reflectR, rDepth - 1,
								cLimit / iInfo.material->specular);
			}
		}

		/* REFRACT */
		if (this->Refract(ray.direction, iInfo.normal, iInfo.material->refind,
				refractR.direction) == 1) {
			refractR.direction /= refractR.direction.length();
			refractR.position = iInfo.iCoordinate + refractR.direction * RAYEPS;
			refractP += iInfo.material->transparent
					* this->GetColor(refractR, rDepth - 1, cLimit);
			for (int i = 0; i <= 2; i++)
				if (refractP.p[i] > 1)
					refractP.p[i] = 1;
			for (int i = 0; i <= 2; i++)
				if (refractP.p[i] < 0)
					refractP.p[i] = 0;
		}


		Point3D temp = iInfo.material->emissive
				+ ambient * iInfo.material->ambient + diffuse + specular
				+ reflectP + refractP;// + shadow;	//+texColor;
		for (int i = 0; i <= 2; i++)
			if (temp.p[i] > 1)
				temp.p[i] = 1;
		for (int i = 0; i <= 2; i++)
			if (temp.p[i] < 0)
				temp.p[i] = 0;
		return temp;
	}

	if (ray.position[0] == camera->position[0]
	                                        && ray.position[1] == camera->position[1]
	                                                                               && ray.position[2] == camera->position[2])
		return background;
	else
		return Point3D(0, 0, 0);

}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void) {

    GLfloat matDiffuse[] = {diffuse[0], diffuse[1], diffuse[2]};
    GLfloat matSpecular[] = {specular[0], specular[1], specular[2]};
    GLfloat matEmissive[] = {emissive[0], emissive[1], emissive[2]};
    GLfloat matAmbient[] = {ambient[0], ambient[1], ambient[2]};
    GLfloat matShiny[] = {specularFallOff};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEmissive);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShiny);

///////////Texture Stuff//////////////

	glEnable(GL_TEXTURE_2D);
		if (tex != NULL) {
			(*tex).setUpOpenGL();
			glBindTexture(GL_TEXTURE_2D,(*tex).openGLHandle);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->img->width(), tex->img->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex->img->getPixels());
		}

}


/*
void RayMaterial::turnOffLights(void) {
    GLfloat lightsOffArray[] = {0,0,0};
	GLfloat matDiffuse[] = {0,0,0};
	GLfloat matSpecular[] = {0,0,0};
	GLfloat matEmissive[] = {0,0,0};
	GLfloat matAmbient[] = {0,0,0};
	GLfloat matShiny[] = {specularFallOff};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEmissive);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShiny);

    //lightsOn = false;

///////////Texture Stuff//////////////

	glEnable(GL_TEXTURE_2D);
		if (tex != NULL) {
			(*tex).setUpOpenGL();
			glBindTexture(GL_TEXTURE_2D,(*tex).openGLHandle);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->img->width(), tex->img->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex->img->getPixels());
		}
}*/

void RayTexture::setUpOpenGL(void) {
	glGenTextures(1,&openGLHandle);
}
