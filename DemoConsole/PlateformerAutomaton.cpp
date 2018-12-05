#include "PlateformerAutomaton.h"

PlateformerAutomaton::PlateformerAutomaton()
{
}

PlateformerAutomaton::~PlateformerAutomaton()
{
}

void PlateformerAutomaton::startPlateformerAutomaton(PlateformerState state)
{
	state = update(state);
}

void PlateformerAutomaton::resumePlateformerAutomaton(PlateformerState state)
{
	state = update(state);
}

bool PlateformerAutomaton::startedAutomaton() const
{
	return mStartedAutomaton;
}

PlateformerAutomaton::PlateformerState PlateformerAutomaton::nextPlateformerState(PlateformerState state)
{
	//Change l'état prochain 
	return (PlateformerState)((int)state + 1);
}

PlateformerAutomaton::PlateformerState PlateformerAutomaton::update(PlateformerState state)
{
	switch (state) {
	case PlateformerState::Idle:
		if (true) {
			return nextPlateformerState(state);
		}
		//S'il n'y a pas d'input de key
		else {
			return state;
		}
		break;
	case PlateformerState::Move:
		if (Transaction::getInstance().conditionSnakeCollision(GamePlateformer::getInstance().snake())) {
			return PlateformerState::Collision;
		}
		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GamePlateformer::getInstance().snake(), GamePlateformer::getInstance().fruit())) {
			GamePlateformer::getInstance().generateFruit();
			return nextPlateformerState(state);
		}
		else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents()) 
			{
				changeDirection(k);
			}
			for (Obstacle o : GamePlateformer::getInstance().obstacles()) {
				if (o.Y() + 1.0 < 100)
				{
					o.setY(o.Y() + 1.0);
				}
			}
		////avance automatiquement
		//if (Transaction::getInstance().conditionSnakeCollision(GamePlateformer::getInstance().snake())) {
		//	return PlateformerState::Collision;
		//}
		////s'il mange un fruit
		//else if (Transaction::getInstance().conditionSnakeEat(GamePlateformer::getInstance().snake(), GamePlateformer::getInstance().fruit())) {
		//	GamePlateformer::getInstance().generateFruit(true);
		//	return nextPlateformerState(state);
		//}
		//else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
		//	//Change sa direction
		//	for (auto &k : Game::getInstance().getKeyEvents())
		//	{
		//		changeDirection(k);
		//	}
		//	//Le déplace
		//	GamePlateformer::getInstance().slitherSnake();
		//	return PlateformerState::Move;
		//}
		//else {
		//	//avance automatiquement
		//	GamePlateformer::getInstance().slitherSnake();
		//	return PlateformerState::Move;
		}
	break;
	case PlateformerState::Eat:
		//GamePlateformer::getInstance().generateFruit(true);
		return PlateformerState::Move;
		break;
	case PlateformerState::Collision:
		return nextPlateformerState(state);
		break;
	case PlateformerState::EndGame:
		return PlateformerState::Idle;
		break;
	default:
		return PlateformerState::Idle;
	}
}

bool PlateformerAutomaton::changeDirection(ConsoleKeyEvent &k)
{
	if (k.keyV() == VK_LEFT)
		if ((GamePlateformer::getInstance().snake()).curDirection() == Snake::Direction::Right)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Left);
	else {
		if ((GamePlateformer::getInstance().snake()).curDirection() == Snake::Direction::Left)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Right);
	}
}
