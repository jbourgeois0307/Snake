#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
	std::string mName;
	int mPoint;
public:
	Player();
	Player(std::string &name);
	~Player();
	std::string name();
	int point();
	void setName(std::string &newName);
	void setPoint(int point);
};



#endif //PLAYER_H
