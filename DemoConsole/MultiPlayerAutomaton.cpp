#include "MultiPlayerAutomaton.h"

MultiPlayerAutomaton::MultiPlayerAutomaton()
	:slow_m{ 500 },
	mStartedAutomaton{ false }
{
}


MultiPlayerAutomaton::~MultiPlayerAutomaton()
{
}

void MultiPlayerAutomaton::resetMultiPlayerAutomaton()
{
	mStartedAutomaton = false;
	GameMultiPlayer::getInstance().generateSnake();
	GameMultiPlayer::getInstance().generateFruit();
}

void MultiPlayerAutomaton::startMultiPlayerAutomaton(MultiPlayerState state)
{
	mStartedAutomaton = true;
	state = update(state);
}

void MultiPlayerAutomaton::resumeMultiPlayerAutomaton(MultiPlayerState state)
{
	state = update(state);
}

bool MultiPlayerAutomaton::startedAutomaton() const
{
	return mStartedAutomaton;
}

MultiPlayerAutomaton::MultiPlayerState MultiPlayerAutomaton::nextMultiPlayerState(MultiPlayerState state)
{
	//Change l'état prochain 
	return (MultiPlayerState)((int)state + 1);
}

MultiPlayerAutomaton::MultiPlayerState MultiPlayerAutomaton::update(MultiPlayerState state)
{
	switch (state) {
	case MultiPlayerState::Idle:
		if (Transaction::getInstance().conditionAnyInput()) {
			Game::getInstance().getKeyEvents().clear();
			return nextMultiPlayerState(state);
		}
		//S'il n'y a pas d'input de key
		else {
			return state;
		}
		break;
	case MultiPlayerState::Move:
		//avance automatiquement
		if (Transaction::getInstance().conditionSnakeCollision(GameMultiPlayer::getInstance().caterpillar(), GameMultiPlayer::getInstance().snake())) {
			return MultiPlayerState::Collision;
		}
		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GameMultiPlayer::getInstance().snake(), GameMultiPlayer::getInstance().fruit()) ||
			Transaction::getInstance().conditionSnakeEat(GameMultiPlayer::getInstance().caterpillar(), GameMultiPlayer::getInstance().fruit())) {
			
			return nextMultiPlayerState(state);
		}

		else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents()) ) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				changeDirection(k);
			}
			//Le déplace
			GameMultiPlayer::getInstance().slitherSnake();
			GameMultiPlayer::getInstance().slitherCaterpillar();
			return state;
		}
		else {
			//avance automatiquement
			GameMultiPlayer::getInstance().slitherSnake();
			GameMultiPlayer::getInstance().slitherCaterpillar();
			return state;
		}
		break;
	case MultiPlayerState::Eat:
		GameMultiPlayer::getInstance().fruit()->beEaten(GameMultiPlayer::getInstance().snake());
		GameMultiPlayer::getInstance().generateFruit();
		return MultiPlayerState::Move;
		break;
	case MultiPlayerState::Collision:
		return nextMultiPlayerState(state);
		break;
	case MultiPlayerState::EndGame:
		resetMultiPlayerAutomaton();
		return MultiPlayerState::Idle;
		break;
	default:
		return MultiPlayerState::Idle;
	}
}

bool MultiPlayerAutomaton::changeDirection(ConsoleKeyEvent &k)
{
	//Autorise le changement de direction seulement si ce n'est pas dans le sens directement opposé
	if (k.keyV() == VK_UP)
		if ((GameMultiPlayer::getInstance().snake())->curDirection() == Snake::Direction::Down)
			return false;
		else
			GameMultiPlayer::getInstance().directionSnake(Snake::Direction::Up);
	else if (k.keyV() == VK_DOWN)
		if ((GameMultiPlayer::getInstance().snake())->curDirection() == Snake::Direction::Up)
			return false;
		else
			GameMultiPlayer::getInstance().directionSnake(Snake::Direction::Down);
	else if (k.keyV() == VK_LEFT)
		if ((GameMultiPlayer::getInstance().snake())->curDirection() == Snake::Direction::Right)
			return false;
		else
			GameMultiPlayer::getInstance().directionSnake(Snake::Direction::Left);
	else if (k.keyV() == VK_RIGHT) {
		if ((GameMultiPlayer::getInstance().snake())->curDirection() == Snake::Direction::Left)
			return false;
		else
			GameMultiPlayer::getInstance().directionSnake(Snake::Direction::Right);
	}

	char keyEntered = toupper(k.keyA());
	if (keyEntered == 'W')
		if ((GameMultiPlayer::getInstance().caterpillar())->curDirection() == Snake::Direction::Down)
			return false;
		else
			GameMultiPlayer::getInstance().directionCaterpillar(Snake::Direction::Up);
	else if (keyEntered == 'S')
		if ((GameMultiPlayer::getInstance().caterpillar())->curDirection() == Snake::Direction::Up)
			return false;
		else
			GameMultiPlayer::getInstance().directionCaterpillar(Snake::Direction::Down);
	else if (keyEntered == 'A')
		if ((GameMultiPlayer::getInstance().caterpillar())->curDirection() == Snake::Direction::Right)
			return false;
		else
			GameMultiPlayer::getInstance().directionCaterpillar(Snake::Direction::Left);
	else if (keyEntered == 'D'){
		if ((GameMultiPlayer::getInstance().caterpillar())->curDirection() == Snake::Direction::Left)
			return false;
		else
			GameMultiPlayer::getInstance().directionCaterpillar(Snake::Direction::Right);
	}
}
