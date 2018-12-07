#include "PlateformerAutomaton.h"

PlateformerAutomaton::PlateformerAutomaton()
{
}

PlateformerAutomaton::~PlateformerAutomaton()
{
}

void PlateformerAutomaton::resetPlateformerAutomaton()
{
	mStartedAutomaton = false;
	GamePlateformer::getInstance().generateSnake();
	GamePlateformer::getInstance().generateFruit();
	GamePlateformer::getInstance().generateObstacles();

}

void PlateformerAutomaton::startPlateformerAutomaton(PlateformerState state)
{
	mStartedAutomaton = true;
	mState = state;
	state = update(state);
}

void PlateformerAutomaton::resumePlateformerAutomaton()
{
	mState = update(mState);
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
		if (Transaction::getInstance().conditionAnyInput()) {
			Game::getInstance().getKeyEvents().clear();
			return nextPlateformerState(state);
		}
		//S'il n'y a pas d'input de key
		else {
			return state;
		}
		break;
	case PlateformerState::Move:
		//Si collision a lieu
		if (Transaction::getInstance().conditionSnakeCollision(GamePlateformer::getInstance().snake(), GamePlateformer::getInstance().obstacles())) {
			return PlateformerState::Collision;
		}

		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GamePlateformer::getInstance().snake(), GamePlateformer::getInstance().fruit())) {
			return nextPlateformerState(state);
		}

		else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				//Change sa direction
				changeDirection(k);
			}
			//Le déplace
			GamePlateformer::getInstance().slitherSnake();
			moveObstacles();
			return PlateformerState::Move;
		}
		else {
			//avance automatiquement
			GamePlateformer::getInstance().slitherSnake();
			moveObstacles();
			return PlateformerState::Move;
		}
		break;
	case PlateformerState::Eat:
		GamePlateformer::getInstance().fruit()->beEaten(GamePlateformer::getInstance().snake());
		GamePlateformer::getInstance().generateFruit();
		return PlateformerState::Move;
		break;
	case PlateformerState::Collision:
		Game::getInstance().changeKnownState(Game::State::GameOver);
		return nextPlateformerState(state);
		break;
	case PlateformerState::EndGame:
		resetPlateformerAutomaton();
		return PlateformerState::Idle;
		break;
	default:
		return PlateformerState::Idle;
	}
}
void PlateformerAutomaton::moveObstacles() {
	std::vector<Obstacle>* obstacles = &(GamePlateformer::getInstance().obstacles());
	for (int i{ 0 }; i < obstacles->size(); ++i) {
		if (obstacles->at(i).Y() + 1 >= 100) {
			obstacles->at(i).setY(0);
			obstacles->at(i).setX(Random::getInstance().uniformRandomize(0, 90) + 5);
		}
		else {
			obstacles->at(i).setY(obstacles->at(i).Y() + 1);
		}
	}
}
bool PlateformerAutomaton::changeDirection(ConsoleKeyEvent &k)
{
	//Autorise le changement de direction seulement si ce n'est pas dans le sens directement opposé
	if (k.keyV() == VK_UP)
		if ((GamePlateformer::getInstance().snake())->curDirection() == Snake::Direction::Down)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Up);
	else if (k.keyV() == VK_DOWN)
		if ((GamePlateformer::getInstance().snake())->curDirection() == Snake::Direction::Up)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Down);
	else if (k.keyV() == VK_LEFT)
		if ((GamePlateformer::getInstance().snake())->curDirection() == Snake::Direction::Right)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Left);
	else {
		if ((GamePlateformer::getInstance().snake())->curDirection() == Snake::Direction::Left)
			return false;
		else
			GamePlateformer::getInstance().directionSnake(Snake::Direction::Right);
	}
}











