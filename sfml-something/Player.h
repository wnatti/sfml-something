#pragma once
#include "GameObject.h"
#include "BulletSys.h"
class Player : public GameObject
{
public:
	Player(TextureLoader& tl);
	~Player(void);
	void move(Vector2f direction);
	void rotate(bool keyPressed);
	void draw(RenderWindow& window);	
	void dodge(bool keyPressed, const Time& dt);
	float getRotation();
	float getX(){return _sprite.getPosition().x;}
	float getSpeed(){return _speed;}
	void checkCollision(BulletSys& bs);
	bool dodgeSwitch;
	bool godMode;
	Vector2f movement;
	FloatRect _boundaries;
private:
	Sprite _headsprite;
	Clock rotateTick;
	Clock dodgeTick;
	Clock dodgeTime;
};

