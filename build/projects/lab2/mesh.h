#pragma once
#include <vector>
#include "Matrix4D.h"
#include "Vector4D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class MeshResource {
public:
	MeshResource();

	~MeshResource();

	std::vector<Vector4D> verticies;
	std::vector<float> buffer;
	unsigned int vaoid;

	void genvertexarray() {

	}

};