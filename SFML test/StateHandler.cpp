#include "StateHandler.h"



StateHandler::StateHandler()
{
}


StateHandler::~StateHandler()
{
	while (!mStates.empty()) {
		delete mStates.top(); 
		mStates.pop();
	}
}

void StateHandler::update(float dt)
{
	mStates.top()->update(dt);
}

void StateHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	mStates.top()->draw(target, states);
}

void StateHandler::input(const sf::Event & inputEvent) const
{
	mStates.top()->input(inputEvent);
}
