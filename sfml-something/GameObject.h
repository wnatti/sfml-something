#pragma once
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace sf;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject(void);
	virtual void draw(RenderWindow& window);
	bool isDead();
	Vector2f getPosition(){return _sprite.getPosition();}
	float getRotation(){return _sprite.getRotation();}

protected:
	void middleOrigin(); //laittaa objectin originin keskelle tekstuuria
	Texture _texture;
	Sprite _sprite;
	float _speed;
	
};