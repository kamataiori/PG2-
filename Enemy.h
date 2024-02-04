#pragma once
#include "Collision.h"
#include <Novice.h>

class Enemy
{
private:
	Character enemy;

public:
	Enemy();
	~Enemy();
	void Update();
	void Draw();
	Character GetEnemy() { return enemy; };
	float GetEnemyPosX() { return enemy.Center.x; };
	float GetEnemyPosY() { return enemy.Center.y; };
	float GetEnemyLength() { return enemy.Length; };
	void SetEnemyIsAlive(bool isAlive);
	int GetEnemyIsAlive() { return enemy.IsAlive; };
	int enemyHP;
	int respornCount;
	int EnemyGraphHandle;

};



