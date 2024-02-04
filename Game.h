#pragma once
#include"struct.h"
#include"Player.h"
#include"Enemy.h"
#include "Bullet.h"
#include "Collision.h"

class Game_Scen
{
public://包含
	//プレイヤークラス
	Player* player = new Player();
	//エネミークラス
	Enemy* enemy = new Enemy();
	Bullet* bullet_;
	Game_Scen(Bullet* bullet);
	~Game_Scen();
	//更新処理
	void Update(char* keys, char* preKeys);
	//描画
	void Draw();

	int scene_;

	float distanceA;
	float distanceB;
	float radianA;
	float radianB;

	Collision* collision = new Collision();

	enum Scene
	{
		Title,
		Opration,
		Game,
		Clear,
		GameOver,
	};

	int TitleGraphHandle = Novice::LoadTexture("./Title.png");
	int OparationGraphHandle = Novice::LoadTexture("./Oparation.png");
	int GameBGGraphHandle = Novice::LoadTexture("./BG.png");
	int ClearGraphHandle = Novice::LoadTexture("./Clear.png");
	int GameOverGraphHandle = Novice::LoadTexture("./GameOver.png");
};

