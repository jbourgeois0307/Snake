#ifndef FRUIT_H
#define FRUIT_H

class Fruit
{
	static int sCountFruit;
	int mX, mY, mPointVal;
public:
	Fruit();
	Fruit(int x, int y, int pointVal);
	~Fruit();
	void setX(int x);
	void setY(int y);
	int getMX();
	int getMY();
	int getMPointVal();
	void destroyFruit();
};




#endif //FRUIT_H
