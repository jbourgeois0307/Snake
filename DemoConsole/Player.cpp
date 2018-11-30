#include "Player.h"

Player::Player()
	: mName{ "default"},
	mPoint{0}
{
}

Player::Player(std::string &name)
	: mName{ name },
	mPoint {0}
{
}

Player::~Player()
{
}

std::string Player::name()
{
	return mName;
}

int Player::point()
{
	return mPoint;
}

void Player::setName(std::string &newName)
{
	mName = newName;
}

void Player::setPoint(int point)
{
	mPoint = point;
}
