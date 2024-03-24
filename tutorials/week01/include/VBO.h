WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
	GLuint ID;
//	VBO(){};
//	VBO(GLfloat* vertices, GLsizeiptr size);
//
//	void Bind();
//	void Unbind();
//	void Delete();

VBO(GLfloat* vertices, GLsizeiptr size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
    	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	
}

void Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Delete() {
	glDeleteBuffers(1, &ID);
}

};

#endif