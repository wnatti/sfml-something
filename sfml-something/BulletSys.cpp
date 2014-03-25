#include "BulletSys.h"
const float SHOOT_INTERVAL = 0.1f;
const float SHOTGUN_INTERVAL = 0.7f;

BulletSys::BulletSys(void)
{
}

void BulletSys::shootBullet(const RenderWindow &window, const Time& deltaTime, const TextureLoader& tl, EnemySys& enemySys)
{
	shoot_switch = false;
	shoot_shotgun_switch = false;

	if(shoot_clock.getElapsedTime().asSeconds()>=SHOOT_INTERVAL)
	{
	checkBullet(window);
	
	std::vector<Enemy*>temp;
	temp = enemySys.getVect();


	for(int i = 0; i < temp.size();i++)
	{
		if(temp[i]->type == 'n')
		{

			if(shoot_clock.getElapsedTime().asSeconds()>=SHOOT_INTERVAL)
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation(),tl,1));
			shoot_switch = true;
		
		}

		if(temp[i]->type == 's')
		{

		if(shoot_clock_shotgun.getElapsedTime().asSeconds()>=SHOTGUN_INTERVAL)
		{
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation(),tl,0.8));
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation()+5,tl,0.8));
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation()-5,tl,0.8));
			shoot_shotgun_switch = true;
		}
		}
	}

if(shoot_switch)
shoot_clock.restart();

if(shoot_shotgun_switch)
shoot_clock_shotgun.restart();
	
	//std::cout << "Bang" << std::endl;	
	//std::cout << bullet_vector.size() << std::endl;
	
	}

	std::vector<Bullet>::iterator it = bullet_vector.begin();

	while(it != bullet_vector.end())
	{
		(*it).move(deltaTime);
		it++;
	}
}

void BulletSys::checkBullet(const RenderWindow &window)
{
	bullet_it = bullet_vector.begin();

	bool something_happened = false;

	while(bullet_it != bullet_vector.end())
	{	
		if((*bullet_it).getPosition().x > window.getSize().x || (*bullet_it).getPosition().x < 0)
		{	

			bullet_it = bullet_vector.erase(bullet_it);
			something_happened = true;

		}
		else if((*bullet_it).getPosition().y > window.getSize().y || (*bullet_it).getPosition().y < 0)
		{
		
			bullet_it = bullet_vector.erase(bullet_it);
			something_happened = true;
		}
		else
		{
			bullet_it++;
		}
	}

	if(something_happened == true)
	{
		bullet_vector.shrink_to_fit();
	}

}

void BulletSys::drawBullet(RenderWindow &window)
{
	bullet_it = bullet_vector.begin();

	while(bullet_it != bullet_vector.end())
	{	
		(*bullet_it).draw(window);
		bullet_it++;
	}

}

void BulletSys::renewBullets(std::vector<Bullet> bv)
{
	bullet_vector = bv;
}

BulletSys::~BulletSys(void)
{
}
