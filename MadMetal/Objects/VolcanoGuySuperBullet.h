#pragma once

#include "Bullet.h"

class VolcanoGuySuperBullet : public Bullet
{
public:
	VolcanoGuySuperBullet(long id, Audioable *aable, Physicable *pable, Animatable *anable, Renderable3D *rable,  Car *owner);
	~VolcanoGuySuperBullet();
	virtual void update(float dt) { Bullet::update(dt); }
};

