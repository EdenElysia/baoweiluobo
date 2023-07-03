#include"Block.h"
void Block::handleClick(int x, int y)
{
	curState->handleClick(row, col, x, y);
}

void Block::draw()
{
	curState->draw(row, col);
}

Block::Block(int j, int i) :row(j), col(i)
{
	i = i - 1;
	if (i == -1)curState = make_shared<BanState>();
	else if (j == 0 || j == 11) curState = make_shared<BanState>();
	else if (j == 1 && (i >= 2 && i <= 5)) curState = make_shared<BanState>();
	else if (i == 5 && (j >= 1 && j <= 5))curState = make_shared<BanState>();
	else if (j == 5 && (i == 3 || i == 4))curState = make_shared<BanState>();
	else if (i == 3 && j == 6)curState = make_shared<BanState>();
	else if (j == 7 && (i >= 1 && i <= 3)) curState = make_shared<BanState>();
	else if (j == 8 && (i >= 1 && i <= 2)) curState = make_shared<BanState>();
	else if (i == 2 && (j >= 9 && i <= 11)) curState = make_shared<BanState>();
	else
	{
		curState = make_shared<EmptyState>();
	}
	staticState = curState;
}

void Block::resetState(shared_ptr<BlockState>state)
{
	curState = state;
}

void Block::resetStaticState(shared_ptr<BlockState>state)
{
	staticState = state;
}

void Block::updateState()
{
	curState = staticState;
}