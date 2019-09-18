#pragma once
#include <vector>
#include "Matrix4D.h"
#include "Vector4D.h"
#include "core/app.h"
#include "render/window.h"
#include "config.h"
class MeshResource {
public:
	MeshResource() {
	}

	~MeshResource() {
	}

	float bufferdata[24]{
		0.5f,	0.5f,	0.0f,			// top right
	    1.0f,	0.0f,   0.0f,           // color top right
		0.5f,  -0.5f,	0.0f,			// bottom right
	    0.0f,   1.0f,   0.0f,	        // color bottom right
	   -0.5f,  -0.5f,	0.0f,			// bottom left
	    0.0f,   0.0f,   1.0f,       	// color bottom left
	   -0.5f,	0.5f,	0.0f,			// top left
	    0.0f,   0.0f,   1.0f	        // color top left

	
	};

	unsigned int indicies[6]{
		0,1,3, //first triangle 
		1,2,3  //secound triangle
	};


	unsigned int vertexarray;
	unsigned int vertexbuffer;
	unsigned int indexbuffer;

	void setattrib();

	void genvertexarray();

	void genvertexbuffer();

	void genindexbuffer();

};