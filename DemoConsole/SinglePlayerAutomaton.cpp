#include "SinglePlayerAutomaton.h"

SinglePlayerAutomaton::SinglePlayerAutomaton()
	:slow_m{500},
	mStartedAutomaton{false}
{
}

SinglePlayerAutomaton::~SinglePlayerAutomaton()
{
}


void SinglePlayerAutomaton::resetSinglePlayerAutomaton()
{
	mStartedAutomaton = false;
	GameSinglePlayer::getInstance().generateSnake();
	GameSinglePlayer::getInstance().generateFruit();
}

void SinglePlayerAutomaton::startSinglePlayerAutomaton(SinglePlayerState state)
{
	mStartedAutomaton = true;
	mState = state;
	state = update(state);
}

void SinglePlayerAutomaton::resumeSinglePlayerAutomaton()
{
	mState = update(mState);
}

bool SinglePlayerAutomaton::startedAutomaton() const
{
	//Retourne si oui ou non l'automate a �t� cr��
	return mStartedAutomaton;
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::nextSinglePlayerState(SinglePlayerState state)
{
	//Change l'�tat prochain 
	return (SinglePlayerState)((int)state +1);
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::update(SinglePlayerState state)
{
	switch (state) {
	case SinglePlayerState::Idle:
		if (Transaction::getInstance().conditionAnyInput()) {
			Game::getInstance().getKeyEvents().clear();
			return nextSinglePlayerState(state);
		}
		//S'il n'y a pas d'input de key
		else {
			return state;
		}
		break;
	case SinglePlayerState::Move:
		//Si collision a lieu
		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			return SinglePlayerState::Collision;
		}

		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GameSinglePlayer::getInstance().snake(), GameSinglePlayer::getInstance().fruit())) {
			return nextSinglePlayerState(state);
		}

		else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				//Change sa direction
				changeDirection(k);
			}
			//Le d�place
			GameSinglePlayer::getInstance().slitherSnake();
			return SinglePlayerState::Move;
		}
		else {
			//avance automatiquement
			GameSinglePlayer::getInstance().slitherSnake();
			return SinglePlayerState::Move;
		}
		break;
	case SinglePlayerState::Eat:
			GameSinglePlayer::getInstance().fruit()->beEaten(GameSinglePlayer::getInstance().snake());
			GameSinglePlayer::getInstance().generateFruit();
			return SinglePlayerState::Move;
		break;

	case SinglePlayerState::Collision:
		Game::getInstance().changeKnownState(Game::State::GameOver);
		return nextSinglePlayerState(state);
		break;
	case SinglePlayerState::EndGame:
		resetSinglePlayerAutomaton();
		return SinglePlayerState::Idle;
		break;
	default:
		return SinglePlayerState::Idle;
}
}

bool SinglePlayerAutomaton::changeDirection(ConsoleKeyEvent &k)
{
	//Autorise le changement de direction seulement si ce n'est pas dans le sens directement oppos�
	if (k.keyV() == VK_UP)
		if ((GameSinglePlayer::getInstance().snake())->curDirection() == Snake::Direction::Down)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Up);
	else if (k.keyV() == VK_DOWN)
		if ((GameSinglePlayer::getInstance().snake())->curDirection() == Snake::Direction::Up)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Down);
	else if (k.keyV() == VK_LEFT)
		if ((GameSinglePlayer::getInstance().snake())->curDirection() == Snake::Direction::Right)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Left);
	else {
		if ((GameSinglePlayer::getInstance().snake())->curDirection() == Snake::Direction::Left)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Right);
	}
}