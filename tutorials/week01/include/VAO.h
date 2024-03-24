WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"
#include <iostream>

void print() {

}

class VAO {
public:
	GLuint ID;
//	VAO();
//
//	void LinkVBO(VBO VBO, GLuint layout);
//	void Bind();
//	void Unbind();
//	void Delete();
	VAO() {
		glGenVertexArrays(1, &ID);
	}

	void LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
		VBO.Bind();
		glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(layout);

		VBO.Unbind();
	}

	void Bind() {
		glBindVertexArray(ID);
	}

	void Unbind() {
		glBindVertexArray(0);
	}

	void Delete() {
		glDeleteVertexArrays(1, &ID);
	}
};

#endif