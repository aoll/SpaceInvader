#include "Vilain.class.hpp"

int		Vilain::nbVilain = 0;
std::string Vilain::img = "#";

int		Vilain::col = 1;   //BLUE, BLACK


Vilain::Vilain(void)
{
	this->_nbTir = 0;
	this->_nbTirMax = 10;
	this->x = rand() % 80;
	this->y = -1  * rand() % 10;

	this->etat = rand() % 10 == 2 ? true: false;
}
Vilain::Vilain(Vilain const &src):
  Ship(src)
{
	(void)src;
// std::cout<<"const default call"
}
Vilain::~Vilain(void)
{
// std::cout<<"des default call"
}

Vilain&	Vilain::operator=(Vilain const &srcOp)
{
	(void)srcOp;
// std::cout<<"operator= call"
	
	return *this;
}

/*
 * DIFFERENT STUFF
 */


void		Vilain::move(void)
{
	int tp;
	this->y += 1;
	
	tp = rand() % 3;
	if (tp > 0)
	{
		if (this->x == this->maxX)//or (this->maxX - 1))
			this->x -= 1;
		else if	(this->x == (this->minX))
			this->x += 1;
		else
			tp == 1 ? this->x -= 1: this->x += 1;
	}
	tp = rand() % 10;
	if (tp == 1)
		this->fire();
	if (this->y >= this->maxY)
	{
		this->etat = rand() % 10 == 2 ? true: false;
		this->x = rand() % 80;
		this->y = -1  * rand() % 10;
	}
}	


void		Vilain::fire(void)
{
	this->tir[this->_nbTir].go(this->x, this->y);
	this->_nbTir++;
	if (this->_nbTir == this->_nbTirMax - 2)
		this->_nbTir = 0;
}
