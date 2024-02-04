#pragma once

typedef struct Vector2
{
	float x;
	float y;
}Vector2;

typedef struct Vector {
	int x;
	int y;
}Vector;

//キャラクター
typedef struct Character
{
	//座標
	Vector2 LeftTop;
	Vector2 LeftBottom;
	Vector2 RightTop;
	Vector2 RightBottom;

	//中心点
	Vector2 Center;

	//幅
	float Length;

	//速度
	Vector2 Velocity;
	//加速度
	Vector2 Acceleration;

	bool IsAlive;

	unsigned int color;

}Character;

//弾
typedef struct Object {

	//座標
	Vector2 LeftTop;
	Vector2 LeftBottom;
	Vector2 RightTop;
	Vector2 RightBottom;

	//中心点
	Vector2 Center;

	//幅
	float Length;

	//速度
	Vector2 Velocity;

	bool IsShot;

	unsigned int Color;

}Object;