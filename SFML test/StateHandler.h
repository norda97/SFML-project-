#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include"SFML\Graphics.hpp"
#include<stack>
#include"State.h"

class StateHandler : public sf::Drawable
{
public:
	StateHandler();
	~StateHandler();

	void	update(float dt);
	void	draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void	input(const sf::Event & inputEvent) const;

	State&	top()					{ return *mStates.top();				};
	void	pop()					{ delete mStates.top(); mStates.pop();	};
	void	emplace(State * state)	{ mStates.emplace(state);				 };
	bool	empty()					{ return mStates.empty();				};

private:
	std::stack<State*> mStates;
};

#endif
