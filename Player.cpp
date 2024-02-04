#include "Player.h"

Player::Player()
{
	player =
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},

		{640.0f,650.0f},

		{32.0f},

		{0.0f,0.0f},

		{0.0f,0.0f},

		{true},

		{WHITE},
	};

	bullet_ = new Bullet;

	PlayerGraphHandle = Novice::LoadTexture("./Player.png");
}

Player::~Player()
{
}

void Player::Update(char* keys, char* prekeys)
{
	//player = DistanceCenter(player);

	player.Velocity.x = 0;
	player.Velocity.y = 0;

	if (keys[DIK_W])
	{
		player.Velocity.y = -6;
	}

	if (keys[DIK_A])
	{
		player.Velocity.x = -6;
	}

	if (keys[DIK_S])
	{
		player.Velocity.y = 6;
	}

	if (keys[DIK_D])
	{
		player.Velocity.x = 6;
	}

	if (player.Center.x - 16 <= 0)
	{
		player.Center.x = 16;
	}

	if (player.Center.x + 16 >= 1280)
	{
		player.Center.x = 1264;
	}

	if (player.Center.y + 16 >= 720)
	{
		player.Center.y = 704;
	}

	if (player.Center.y - 16 <= 0)
	{
		player.Center.y = 16;
	}

	player.Center.x += player.Velocity.x;
	player.Center.y += player.Velocity.y;

	if (bullet_->GetBullet().IsShot == false)
	{
		if (keys[DIK_SPACE] && prekeys[DIK_SPACE])
		{
			bullet_->SetIsShot(true);
			bullet_->SetPosition(player.Center);
		}
	}

	if (bullet_->GetBullet().IsShot == true)
	{
		bullet_->Update();
		bullet_->GetBulletPosX();
		bullet_->GetBulletPosY();
	}

	GetPlayerPosX();
	GetPlayerPosY();
	GetPlayerLength();
}

void Player::Draw()
{
	bullet_->Draw();
	if (player.IsAlive == true)
	{
		Novice::DrawSprite((int)(player.Center.x - 16), (int)(player.Center.y - 16), PlayerGraphHandle, 1, 1, 0.0f, WHITE);
	}
}

void Player::SetPlayerIsAlive(bool isAlive_)
{
	player.IsAlive = isAlive_;
}

void Player::SetPlayerPosX(float posX)
{
	player.Center.x = posX;
}

void Player::SetPlayerPosY(float posY)
{
	player.Center.y = posY;
}
