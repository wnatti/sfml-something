#pragma once
#include "Player.h"
class Input
{
public:
	Input(void);
	~Input(void);
	static Vector2f movePlayer(const Time& dt,Player& p);
	static bool rotatePlayer();
	static bool dodgeJump();
};