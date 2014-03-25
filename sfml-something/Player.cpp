#include "Player.h"

static const float PII = 3.141592f;

Player::Player(TextureLoader& tl)
{	
	_sprite = (tl.getSprite("torso"));
	//_headsprite = (tl.getSprite("head"));
	_sprite.scale(5.0f,5.0f);
	middleOrigin();
	_headsprite.setOrigin(_sprite.getOrigin().x+8,_sprite.getOrigin().y-32);
	_sprite.setPosition(320,240);
	//_headsprite.setPosition(320,240);
	//_boundaries = _sprite.getGlobalBounds();
	dodgeSwitch = false;
	godMode = false;
}

void Player::checkCollision(BulletSys& bs)
{	
	std::vector<Bullet> bvec = bs.getBVector();
	std::vector<Bullet>::iterator it = bvec.begin();
	_boundaries = _sprite.getGlobalBounds();
	
	while(it!=bvec.end())
	{
		if(_boundaries.contains((it)->getPosition()) && godMode == false)
		{
		it->hitWarn();
		it++;
		}
		
		else
		{
		it++;
		}
	}

	bs.renewBullets(bvec);
}


void Player::move(Vector2f direction)
{
	_headsprite.setPosition(_sprite.getPosition());
	_sprite.move(direction);
}
void Player::rotate(bool keyPressed)
{
	if(keyPressed == true && rotateTick.getElapsedTime().asSeconds() > 0.2)
	{
		_sprite.rotate(90);
		rotateTick.restart();
	}

}

void Player::dodge(bool keyPressed, const Time& dt)
{
	if(keyPressed == true && dodgeTick.getElapsedTime().asSeconds() > 2 || dodgeSwitch == true)
	{
		if(dodgeTick.getElapsedTime().asSeconds() > 2)
		{
		dodgeTick.restart();
		dodgeSwitch = true;
		dodgeTime.restart();
		}


		if(dodgeTime.getElapsedTime().asSeconds() < 0.3)
			{
				godMode = true;
				float delta = (dt.asSeconds()*300-(dodgeTime.getElapsedTime().asSeconds()*15));
				movement.x = (cos((_sprite.getRotation())*PII/180)*delta);
				movement.y = (sin((_sprite.getRotation())*PII/180)*delta);



				if(delta>1)
				_sprite.setScale(delta,delta);
				
			

				_sprite.move(movement);
			}

		else
		{
		_sprite.setScale(1.0,1.0);
		dodgeSwitch = false;
		godMode = false;
		}
	}
}

float Player::getRotation()
{
	return _sprite.getRotation()-90;
}

void Player::draw(RenderWindow& window)
{
	GameObject::draw(window);
	window.draw(_headsprite);

}
Player::~Player(void)
{
}
