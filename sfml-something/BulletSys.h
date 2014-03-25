#pragma once
#include "Bullet.h"
#include "SFML\Graphics.hpp"
#include "Enemy.h"
#include "EnemySys.h"

class BulletSys
{
public:
	BulletSys(void);
	~BulletSys(void);
	void shootBullet(const RenderWindow &window,const Time& deltaTime,const TextureLoader& tl, EnemySys& enemySys);
	void drawBullet(RenderWindow &window);
	std::vector<Bullet>& getBVector(){return bullet_vector;}
	void renewBullets(std::vector<Bullet> bv);
private:
	void checkBullet(const RenderWindow &window);
	std::vector<Bullet>bullet_vector;
	std::vector<Bullet>::iterator bullet_it;
	Clock shoot_clock;
	Clock shoot_clock_shotgun;
	bool shoot_switch;
	bool shoot_shotgun_switch;
	int test;
};

