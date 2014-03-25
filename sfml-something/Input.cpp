#include "Input.h"
#include <iostream>
using namespace std;

static const float PII = 3.141592f;

Input::Input(void)
{
}

Vector2f Input::movePlayer(const Time& dt,Player& p)
{
	Vector2f movement(0,0);

	float delta = dt.asSeconds()*100;
	if(Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.x = (cos(p.getRotation()*PII/180)*delta*2);
		movement.y = (sin(p.getRotation()*PII/180)*delta*2);
	}
	if(Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.x = (cos(p.getRotation()*PII/180)*-delta);
		movement.y = (sin(p.getRotation()*PII/180)*-delta);
	}

	if(Keyboard::isKeyPressed(Keyboard::Left))
		movement.x -=1;
	if(Keyboard::isKeyPressed(Keyboard::Right))
		movement.x+=1;
	if(Keyboard::isKeyPressed(Keyboard::Up))
		movement.y-=1;
	if(Keyboard::isKeyPressed(Keyboard::Down))
		movement.y+=1;

	return movement;
}

bool Input::rotatePlayer()
{

	/*if(Keyboard::isKeyPressed(Keyboard::A))
	{
		rotation = -5*delta;
	}
	if(Keyboard::isKeyPressed(Keyboard::D))
	{
		rotation = 5*delta;
	}*/

	
	if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			return true;
		}
	
	else
		return false;

	
}

bool Input::dodgeJump()
{
	if(Keyboard::isKeyPressed(Keyboard::Q))
		return true;
	else
		return false;
}

Input::~Input(void)
{
}
