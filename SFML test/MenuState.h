#ifndef MENUSTATE_H
#define MENUSTATE_H

#include"State.h"

class MenuState : public State
{
public:
	MenuState(TextureHandler * textures);
	~MenuState();

	void init();
	void update(float dt);
};

#endif