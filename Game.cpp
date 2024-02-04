#include "Game.h"

Game_Scen::Game_Scen(Bullet*bullet)
{
	scene_ = Title;
	bullet_ = bullet;
	distanceA = 0;
	distanceB = 0;
	radianA = 0;
	radianB = 0;
}

Game_Scen::~Game_Scen()
{
	delete bullet_;
}

void Game_Scen::Update(char* keys, char* preKeys)
{
	switch (scene_)
	{
	case Title:
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		{
			scene_ = Opration;
		}
		enemy->SetEnemyIsAlive(true);
		enemy->enemyHP = 3;
		player->SetPlayerIsAlive(true);
		player->SetPlayerPosX(640);
		player->SetPlayerPosY(600);
		player->bullet_->SetPosition({ - 200, 100});
		player->bullet_->SetIsShot(false);
		break;

	case Opration:
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
		{
			scene_ = Game;
		}
		break;

	case Game:
		player->Update(keys, preKeys);
		enemy->Update();
		distanceA = collision->Distance(player->GetBullet()->GetBulletPosX(), player->GetBullet()->GetBulletPosY(), enemy->GetEnemyPosX(), enemy->GetEnemyPosY());
		radianA = collision->Radius(player->GetBullet()->GetBulletLength() - 8, enemy->GetEnemyLength() - 16);
		if (distanceA <= radianA)
		{
			if (enemy->GetEnemyIsAlive() == 1)
			{
				enemy->enemyHP--;
			}
			enemy->SetEnemyIsAlive(false);
			if (enemy->enemyHP <= 0)
			{
				scene_ = Clear;
			}
			
		}

		distanceB = collision->Distance(player->GetPlayerPosX(), player->GetPlayerPosY(), enemy->GetEnemyPosX(), enemy->GetEnemyPosY());
		radianB = collision->Radius(player->GetPlayerLength() - 16, enemy->GetEnemyLength() - 16);

		if (distanceB <= radianB)
		{
			player->SetPlayerIsAlive(false);
			scene_ = GameOver;
		}

		break;

	case Clear:
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
		{
			scene_ = Title;
		}
		break;

	case GameOver:
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
		{
			scene_ = Title;
		}
		break;
	}

}

void Game_Scen::Draw()
{
	switch (scene_)
	{
	case Title:
		
		Novice::DrawSprite(0, 0, TitleGraphHandle, 1, 1, 0.0f, WHITE);
		break;

	case Opration:
		
		Novice::DrawSprite(0, 0, OparationGraphHandle, 1, 1, 0.0f, WHITE);
		break;

	case Game:
		Novice::DrawSprite(0, 0, GameBGGraphHandle, 1, 1, 0.0f, WHITE);
		player->Draw();
		enemy->Draw();
		
		break;

	case Clear:
		
		Novice::DrawSprite(0, 0, ClearGraphHandle, 1, 1, 0.0f, WHITE);
		break;

	case GameOver:
		
		Novice::DrawSprite(0, 0, GameOverGraphHandle, 1, 1, 0.0f, WHITE);
		break;
	}
}
