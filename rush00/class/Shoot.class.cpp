#include "Shoot.class.hpp"

int		Shoot::nbShoot = 0;
std::string Shoot::img = "!";

int		Shoot::col = 5;


Shoot::Shoot(void)
{
	this->etat = false;
}
Shoot::Shoot(Shoot const &src)
{
	(void)src;
// std::cout<<"const default call"
}
Shoot::~Shoot(void)
{
// std::cout<<"des default call"
}

Shoot&	Shoot::operator=(Shoot const &srcOp)
{
	(void)srcOp;
	// std::cout<<"operator= call"
	
	return *this;
}

/*
 * DIFFERENT STUFF
 */


void		Shoot::move()
{

	this->y += 2;
	if (this->y >= this->maxY)
	{
		this->etat = false;
		this->y = this->minY;
	}

}	

void		Shoot::go(int x, int y)
{
	this->etat = true;
	this->x = x;
	this->y = y + 1;
}
