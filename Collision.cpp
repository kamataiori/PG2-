#include "Collision.h"

float Collision::Distance(float ax, float ay, float bx, float by)
{
	float result;
	return  result = sqrtf((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

float Collision::Radius(float Aradius, float Bradius)
{
	float result;
	return result = (Aradius + Bradius);
}
