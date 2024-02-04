#pragma once
#include "struct.h"
#include <Novice.h>
#include "Bullet.h"

class Player 
{

private:
	Character player;

public:
	Player();
	~Player();
	void Update(char* keys, char* prekeys);
	void Draw();
	Bullet* bullet_;
	Character GetPlayer() { return player; };
	float GetPlayerPosX() { return player.Center.x; };
	float GetPlayerPosY() { return player.Center.y; };
	float GetPlayerLength() { return player.Length; };
	void SetPlayerIsAlive(bool isAlive);
	void SetPlayerPosX(float posX);
	void SetPlayerPosY(float posY);
	Bullet* GetBullet() { return bullet_; };
	int PlayerGraphHandle;
};


