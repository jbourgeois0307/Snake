#include "Obstacle.h"

Obstacle::Obstacle() :mX{ 50}, mY{ 50 },mSize{1}
{
}

Obstacle::~Obstacle()
{
}

Obstacle::Obstacle(size_t size, Point p):mX{p.x()},mY{p.y()},mSize{size}
{
}

double Obstacle::X() {
	return mX;
}
double Obstacle::Y() {
	return mY;
}

size_t Obstacle::Size()
{
	return mSize;
}
