#pragma once
#include "struct.h"
#include <Novice.h>

class Bullet
{

private:
	//Vector2 vector2_;
	Object bullet_;
	

public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
	/// <summary>
	/// bulletのゲッター
	/// </summary>
	/// <returns></returns>
	Object GetBullet() { return bullet_; };
	float GetBulletPosX() { return bullet_.Center.x; };
	float GetBulletPosY() { return bullet_.Center.y; };
	float GetBulletLength() { return bullet_.Length; };

	void SetPosition(Vector2 position);

	void SetIsShot(bool isShot);

};

