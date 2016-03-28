#include "Gargantulous.h"
#include "Factory\GameFactory.h"

Gargantulous::Gargantulous(long id, DrivingStyle* style, PxVehicleDrive4W &car, Audioable *aable, Physicable *pable, Animatable *anable, Renderable3D *rable) : Car(id, style, car, aable, pable, anable, rable)
{
	m_lastWeaponShot = LAST_WEAPON_SHOT_LEFT;
	m_reloadRateSeconds = 0.15;						//in s
	m_superReloadRateSeconds = 1;
	m_currentHealth = m_maxHealth = 100;


	m_superMaxDurationSeconds = 5;
	m_superDurationRemainingSeconds = 0;


}


Gargantulous::~Gargantulous()
{
}

void Gargantulous::fire()
{
	if (m_reloadRemainingSeconds > 0)
		return;




	PxTransform *pos;
	if (m_superDurationRemainingSeconds > 0)
	{
		glm::vec4 up = glm::normalize(getModelMatrix() * glm::vec4(0, 1, 0, 0));
		glm::vec4 forward = glm::normalize(getModelMatrix() * glm::vec4(0, 0, 1, 0));
		glm::vec4 weaponPos = glm::vec4(getFullPosition(), 1.0) + up * (getScale().y / 2) + forward * (getScale().z / 2);
		pos = new PxTransform(weaponPos.x, weaponPos.y, weaponPos.z);
		GameFactory::instance()->makeObject(GameFactory::OBJECT_BULLET_SUPER_VOLCANO, pos, NULL, this);
		delete pos;
		m_reloadRemainingSeconds = m_superReloadRateSeconds;

	}
	else {
		//if (m_activePowerUp != PowerUpType::NONE)
		//std::cout << "Shooting with powerup \n";
		//else
		//std::cout << "Shooting without Powerup \n";
		m_reloadRemainingSeconds = m_reloadRateSeconds;
		glm::vec4 up = glm::normalize(getModelMatrix() * glm::vec4(0, 1, 0, 0));
		glm::vec4 left = glm::normalize(getModelMatrix() * glm::vec4(-1, 0, 0, 0));
		if (m_lastWeaponShot == LAST_WEAPON_SHOT_LEFT)
		{
			m_lastWeaponShot = LAST_WEAPON_SHOT_RIGHT;
			glm::vec4 weaponPos = glm::vec4(getFullPosition(), 1.0) + up * (getScale().y / 3) + left * (getScale().x / 2);
			pos = new PxTransform(weaponPos.x, weaponPos.y, weaponPos.z);
			GameFactory::instance()->makeObject(GameFactory::OBJECT_BULLET_MEOW_MIX, pos, NULL, this);
			delete pos;
		}
		else
		{
			m_lastWeaponShot = LAST_WEAPON_SHOT_LEFT;
			glm::vec4 weaponPos = glm::vec4(getFullPosition(), 1.0) + up * (getScale().y / 3) - left * (getScale().x / 2);
			pos = new PxTransform(weaponPos.x, weaponPos.y, weaponPos.z);
			GameFactory::instance()->makeObject(GameFactory::OBJECT_BULLET_MEOW_MIX, pos, NULL, this);
			delete pos;
		}
	}


}

void Gargantulous::update(float dt) {
	Car::update(dt);

}

void Gargantulous::useSuper() {
	Car::useSuper();
	m_reloadRemainingSeconds = 0;
	m_renderable->setModel(Assets::getModel("Gargantulous_Lava"));
	static_cast<Renderable3D *>(m_renderable)->adjustModel(true, true);
	//m_animatable->updateScale(glm::vec3(0, 2, 0));
}

void Gargantulous::unuseSuper() {
	m_renderable->setModel(Assets::getModel("Gargantulous"));
	static_cast<Renderable3D *>(m_renderable)->adjustModel(true, true);
	//m_animatable->updateScale(glm::vec3(0, -2, 0));
}