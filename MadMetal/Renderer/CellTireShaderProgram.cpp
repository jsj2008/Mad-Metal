#include "CellTireShaderProgram.h"

/*
Constructor. Takes path to the vertex shader and fragment shader,
loads them, links them and stores all the needed information (programID, attributes
and uniforms) in its instance variables.
*/
CellTireShaderProgram::CellTireShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath){
	//create the shader loader and create the program
	ShaderLoader *sl = new ShaderLoader();
	programID = sl->loadShaders(vertexShaderPath, fragmentShaderPath);
	delete sl;

	//this is mostly useless.
	//TODO: remove this
	char *line = new char[50];
	sprintf_s(line, 50, "New shader loaded with program ID %u", programID);
	Log::writeLine(line);
	delete[] line;

	//get and store all the uniforms
	projectionMatrixUniform = glGetUniformLocation(programID, "proj_matrix");
	viewMatrixUniform = glGetUniformLocation(programID, "view_matrix");
	modelMatrixUniform = glGetUniformLocation(programID, "model_matrix");
	textureUniform = glGetUniformLocation(programID, "texObject");
	textureValidUniform = glGetUniformLocation(programID, "texValid");

}


CellTireShaderProgram::~CellTireShaderProgram()
{
}

void CellTireShaderProgram::start(glm::mat4x4 *viewMatrix, glm::mat4x4 *projMatrix) {
	//tether the program
	glUseProgram(programID);

	//set view and projection matrices
	glUniformMatrix4fv(viewMatrixUniform, 1, false, glm::value_ptr(*viewMatrix));
	glUniformMatrix4fv(projectionMatrixUniform, 1, false, glm::value_ptr(*projMatrix));
}

void CellTireShaderProgram::end() {
	glUseProgram(0);
}