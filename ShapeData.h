#pragma once

#include "GL/glew.h"
#include "Vertex.h"

struct ShapeData
{
	ShapeData()
	: vertices(0), numVertices(0),
	  indices(0), numIndices(0)
	{}
	Vertex*		vertices;
	GLuint		numVertices;
	GLushort*	indices;
	GLuint		numIndices;

	GLsizeiptr vertexBufferSize() const
	{
		return numVertices * sizeof(Vertex);
	}

	GLsizeiptr indexBufferSize() const
	{
		return numIndices * sizeof(GLushort);
	}

	void cleanUp()
	{
		if (vertices)
			delete[] vertices;
		if (indices)
			delete[] indices;
		numVertices = numIndices = 0;
	}
};