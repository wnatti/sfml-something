#pragma once
#include "Player.h"
#include "Input.h"
#include "TextureLoader.h"
#include "BulletSys.h"
#include "EnemySys.h"

class Game
{
public:
	Game(RenderWindow& window, TextureLoader& tl);
	~Game(void);
	void update(const Time& dt);
	void draw();
private:
	RenderWindow& _window;
	Player _player;
	EnemySys _enemySys;
	BulletSys _bulletSys;
	TextureLoader& _textureLoader;
};