#ifndef FRUIT_H
#define FRUIT_H

class Fruit
{
	static int sCountFruit;
	int mX, mY;
public:
	Fruit();
	~Fruit();
	void setX(int x);
	void setY(int y);
	int getMX();
	int getMY();
	void destroyFruit();
};




#endif //FRUIT_H
