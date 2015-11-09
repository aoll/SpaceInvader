#include "Hero.class.hpp"

int		Hero::nbHero = 0;
std::string Hero::img = "^";
int		Hero::col = 4;



Hero::Hero(void)
{
	this->_nbTir = 0;
	this->_nbTirMax = 100;
	this->x = 40;
	this->y = 45;

	this->life = 5;
	this->etat = true;
}
Hero::Hero(Hero const &src)
{
	(void)src;
// std::cout<<"const default call"
}
Hero::~Hero(void)
{
// std::cout<<"des default call"
}

Hero&	Hero::operator=(Hero const &srcOp)
{
// std::cout<<"operator= call"
	(void)srcOp;
	return *this;
}

/*
 * DIFFERENT STUFF
 */

void		Hero::init(void)
{
	this->x = 40;
	this->y = 45;
	this->life = 5;
}

void		Hero::move(bool const move) 
{
	if (move)
	{
		if ((this->x + 1) == this->maxX)
			this->x = this->minX;
		this->x += 1;
	}
	else
	{
		if ((this->x - 1) == this->minX)
			this->x = this->maxX;
		this->x -= 1;
	}
}	

void		Hero::moveUp(bool const move) 
{
	if (move)
	{
		if ((this->y ) > this->minY + 14)
			this->y -= 1;
	}
	else
	{
		if ((this->y) < this->maxY)
			this->y += 1;
	}

}	

void		Hero::takeDammage(void)
{
	this->life -= 1;
	if (this->life < 0)
		this->life = 0;
}

void		Hero::fire(void)
{
	this->tir[this->_nbTir].go(this->x, this->y - 1);
	this->_nbTir++;
	if (this->_nbTir >= this->_nbTirMax - 1)
		this->_nbTir = 0;
}

