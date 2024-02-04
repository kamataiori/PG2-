#pragma once
#include "struct.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <math.h>

class Collision
{
private:
	

public:
	float Distance(float ax, float ay, float bx, float by);
	float Radius(float Aradius, float Bradius);
};

