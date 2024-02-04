#include "Enemy.h"

Enemy::Enemy()
{
	enemy =
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},

		{640.0f,50.0f},

		{32.0f},

		{10.0f,0.0f},

		{0.0f,0.0f},

		{true},

		{RED},
	};
	EnemyGraphHandle = Novice::LoadTexture("./Enemy.png");
	enemyHP = 3;
}

Enemy::~Enemy()
{
	
}

void Enemy::Update()
{
	if (enemy.Center.x + 16 >= 1280)
	{
		enemy.Velocity.x = -10;
	}
	else if (enemy.Center.x - 16 <= 0)
	{
		enemy.Velocity.x = 10;
	}
	GetEnemyPosX();
	GetEnemyPosY();
	GetEnemy();

	if (enemyHP == 2 || enemyHP == 1)
	{
		if (enemy.IsAlive == false)
		{
			respornCount++;
		}
		if (respornCount > 60)
		{
			enemy.IsAlive = true;
			respornCount = 0;
		}
	}

	enemy.Center.x += enemy.Velocity.x;
	enemy.Center.y += enemy.Velocity.y;
}

void Enemy::Draw()
{
	if (enemy.IsAlive == true)
	{
		Novice::DrawSprite((int)(enemy.Center.x - 16), (int)(enemy.Center.y - 16), EnemyGraphHandle, 1, 1, 0.0f, WHITE);
	}
}

void Enemy::SetEnemyIsAlive(bool isAlive)
{
	enemy.IsAlive = isAlive;
}

