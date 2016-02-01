#pragma once

#include "Model.h"
#include "Renderer/VAO.h"
#include "Libraries\glm\mat4x4.hpp"
#include "Libraries/glm/gtc/matrix_transform.hpp"
#include "Global/Log.h"

class GameObject
{
private:
	glm::vec3 position, rotation;
public:
	VAO *vao;
	Model *model;

	GameObject();
	GameObject(VAO *vao, Model *model);
	~GameObject();
	void setVAO(VAO *vao) { this->vao = vao; }
	void setModel(Model *model) { this->model = model; }
	void setPosition(glm::vec3 pos) { this->position = pos; }
	void updatePosition(glm::vec3 dPos);
	void updateRotation(glm::vec3 angles);
	glm::mat4x4 getModelMatrix();
};

