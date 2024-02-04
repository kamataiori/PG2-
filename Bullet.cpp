#include "Bullet.h"

Bullet::Bullet()
{
	bullet_ =
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},

		{-200.0f,100.0f},

		{16.0f},

		{0.0f,0.0f},

		{false},

		{GREEN},
	};

}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (bullet_.IsShot == true)
	{
		bullet_.Velocity.y = -8;
	}

	if(bullet_.Center.y <= -20.0f)
	{ 
		bullet_.IsShot = false;
	}

	bullet_.Center.x += bullet_.Velocity.x;
	bullet_.Center.y += bullet_.Velocity.y;
}

void Bullet::Draw()
{
	if (bullet_.IsShot == true)
	{
		Novice::DrawBox((int)(bullet_.Center.x), (int)(bullet_.Center.y), (int)(bullet_.Length), (int)(bullet_.Length), 0.0f, (int)(bullet_.Color), kFillModeSolid);
	}
}

void Bullet::SetPosition(Vector2 position) {
	bullet_.Center = position;
}

void Bullet::SetIsShot(bool isShot) {
	bullet_.IsShot = isShot;
}
