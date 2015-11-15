#include "Rock.class.hpp"

int		Rock::nbRock = 0;
std::string Rock::img = "o";
int		Rock::col = 3;



Rock::Rock(void)
{
	
	this->x = rand() % 80;
	this->y = -1  * rand() % 50;
	this->etat = rand() % 2 == 1 ? true : false;
}
Rock::Rock(Rock const &src):
  Ship(src)
{
	(void)src;
// std::cout<<"const default call"
}
Rock::~Rock(void)
{
// std::cout<<"des default call"
}

Rock&	Rock::operator=(Rock const &srcOp)
{
// std::cout<<"operator= call"
	
	(void) srcOp;
	return *this;
}

/*
 * DIFFERENT STUFF
 */


void		Rock::move()
{
	
	this->y += 1;
	if (this->y >= this->maxY)
	{
		this->x = rand() % 80;
		this->y = -1  * rand() % 50;
		this->etat = rand() % 2 == 1 ? true : false;
	}
}	



