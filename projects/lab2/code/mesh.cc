#include "mesh.h"
#include "config.h"

/// generate vertex buffer object
void MeshResource::genvertexbuffer() {
	//generate buffer id
	glGenBuffers(1, &vertexbuffer);

	//bind buffer to id
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// copy vertex array to vertex buffer object
	glBufferData(GL_ARRAY_BUFFER, sizeof(bufferdata), bufferdata, GL_STATIC_DRAW);
}

/// set attributes
void MeshResource::setattrib(){
	//enable the vertex attribute
	glEnableVertexAttribArray(0);
	//set vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

	//enable color attribute
	glEnableVertexAttribArray(1);
	//set color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));

}

/// generate vertex array object
void MeshResource::genvertexarray() {

	//generate vertex array object id
	glGenVertexArrays(1, &vertexarray);

	//bind vertex array object
	glBindVertexArray(vertexarray);
}

/// generate index buffer
void MeshResource::genindexbuffer() {
	//generate index buffer id
	glGenBuffers(1, &indexbuffer);
	//bind index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
}
