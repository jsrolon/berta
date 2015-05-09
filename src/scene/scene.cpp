/*
 * scene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "scene.h"
#include "ReflectiveMaterial.h"
#include "TransparentMaterial.h"
#include "ThinLensCamera.h"
#include "DielectricMaterial.h"

/**
 * Builds the scene environment
 */
Scene::Scene() {
	film = new Film();
	Point pp = Point(200, -55, 0); // camera position
	Point p2 = Point(0, 0, 0);
	Vector v = Vector(0, 1, 0);
	cam = new ThinLensCamera(film, this, pp, p2, v, 800, 3, 210, 1);

	// Lights
	ambientLight = new AmbientLight();
	PointLight* dLight = new PointLight(Point(70, -50, -70), this); // uses radians
	SpotLight* dLight2 = new SpotLight(Point(-230, -60, -80), this,
			Point(-230, 0, -70), 0.8, 0.6); // uses radians
	SpotLight* dLight3 = new SpotLight(Point(0, -40, 60), this, Point(), 0.8,
			0.6); // uses radians
	SpotLight* dLight4 = new SpotLight(Point(120, -80, 25), this,
			Point(120, -40, 10), 0.8, 0.6); // uses radians
	lights.push_back(dLight);
	lights.push_back(dLight2);
	lights.push_back(dLight3);
	lights.push_back(dLight4);

	background_color = Color(0, 0, 0);

	// red cone
//	Shape* s15 = new Cone(0,-40);
//	PhongMaterial* mat15 = new PhongMaterial(this, 0.6, 0.15, 0.2, Color(1, 0, 0),
//					50);
//	Primitive* redCone = new Primitive(s15, mat15);
//	primitives.push_back(redCone);

	// red triangle
	Shape * s14 = new Triangle(Point(40, -30, 40), Point(40, 0, 35),
			Point(40, 0, 55));
	PhongMaterial* mat14 = new PhongMaterial(this, 0.6, 0.15, 0.2,
			Color(1, 0, 0), 50);
	Primitive* redtriangle = new Primitive(s14, mat14);
	primitives.push_back(redtriangle);

	//red cylindah
	Shape * s13 = new Cylinder(20, 0, -40);
	ReflectiveMaterial* mat13 = new ReflectiveMaterial(this, 0.6, 0.15, 0.2, 0.75,
			Color(1, 0, 0), Color(1,1,1), 500);
	Instance* redCylindah = new Instance(s13, mat13);
	primitives.push_back(redCylindah);

//	// red sphere
//	Shape * s = new Sphere();
//	PhongMaterial* mat = new PhongMaterial(this, 0.6, 0.15, 0.2, Color(1, 0, 0),
//			50);
//	Instance* redSphere = new Instance(s, mat);
////	redSphere->scale(1, 1.5, 1);
////	redSphere->rotatex(1); // rad
//	primitives.push_back(redSphere);
//
//	// blue sphere
	Shape * s2 = new Sphere(Point(10, -10, 26), 8);
	ReflectiveMaterial* mat3 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0, 0, 1), Color(1, 1, 1), 50);
	Primitive * grrSphere = new Primitive(s2, mat3);
	primitives.push_back(grrSphere);
//
//	// green sphere
	Shape * s3 = new Sphere(Point(0, -45, 0), 4);
	ReflectiveMaterial* mat4 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0, 1, 0), Color(1, 1, 1), 2);
	Primitive* omgSphere = new Primitive(s3, mat4);
//	omgSphere->rotatex(1); //rad
//	omgSphere->scale(1,1,2);
	primitives.push_back(omgSphere);
//
//	// yellow sphere
	Shape * s4 = new Sphere(Point(28, 0, 0), 6);
	ReflectiveMaterial* mat5 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(1, 1, 0), Color(1, 1, 1), 2);
	Primitive * yellowSphere = new Primitive(s4, mat5);
	primitives.push_back(yellowSphere);
//
//	//transparent sphere
	Shape * s5 = new Sphere(Point(35, -15, -20), 15);
	DielectricMaterial* mat6 = new DielectricMaterial(this, 0.65, 0.15, 0.2,
			0.95, Color(0, 0, 0), Color(1, 1, 1), 2000, 1, 1.2, Color(1, 1, 1),
			Color(1, 1, 1));
	Primitive* purpleSphere = new Primitive(s5, mat6);
//	purpleSphere->scale(1,1,2);
	primitives.push_back(purpleSphere);
//
//	//transparent sphere inside the other one
	Shape * s12 = new Sphere(Point(35, -15, -18), 8);
	DielectricMaterial* mat12 = new DielectricMaterial(this, 0.65, 0.15, 0.2,
			0.95, Color(0, 0, 0), Color(1, 1, 1), 2000, 1, 1.4, Color(0, 0, 1),
			Color(0, 0, 1));
	Primitive* transSphere = new Primitive(s12, mat12);
	//	purpleSphere->scale(1,1,2);
	primitives.push_back(transSphere);
//
//	// faraway sphere 1
	Shape * s11 = new Sphere(Point(-230, 0, -70), 25);
	PhongMaterial* mat11 = new PhongMaterial(this, 0.6, 0.15, 0.2,
			Color(0.2941, 0, 0.5098), 50);
	Primitive* farSphere = new Primitive(s11, mat11);
//	farSphere->scale(1,1,2);
	primitives.push_back(farSphere);

	// faraway yellow sphere
	Shape * s16 = new Sphere(Point(-195, 0, -80), 6);
	ReflectiveMaterial* mat16 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(1, 1, 0), Color(1, 1, 1), 2);
	Primitive * yellowSphere2 = new Primitive(s16, mat16);
	primitives.push_back(yellowSphere2);

	// close transparent sphere
	Shape * s17 = new Sphere(Point(120, -40, 10), 8);
	DielectricMaterial* mat17 = new DielectricMaterial(this, 0.65, 0.15, 0.2,
			0.95, Color(0, 0, 0), Color(1, 1, 1), 2000, 1, 1.4, Color(0, 0, 1),
			Color(0, 0, 1));
	Primitive* transSphere2 = new Primitive(s17, mat17);
	//	purpleSphere->scale(1,1,2);
	primitives.push_back(transSphere2);

//	// create and add plane
	Shape* pl = new Plane();
	ReflectiveMaterial* mat2 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.4, Color(0.8, 0.4, 0), Color(1, 1, 1), 300);
	Primitive* bluePlane = new Primitive(pl, mat2);
	primitives.push_back(bluePlane);
}

void Scene::render() {
	cam->render();
}

bool Scene::intersect(const Ray& ray, Intersection& isect) {
	Intersection iTmp; // to return the intersection at the actual minimum t
	float tMin = INFINITY;
	for (int i = 0; i < primitives.size(); i++) {
		float t;
		if (primitives[i]->intersect(ray, t, iTmp) && t < tMin) {
			tMin = t;
			isect = iTmp;
		}
	}
	/**
	 * A lowest t has been found
	 */
	if (tMin != INFINITY) {
		isect.ray = ray;
		return true;
	} else {
		return false;
	}
}

Scene::~Scene() {
	delete film;
	delete cam;
}
