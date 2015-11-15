#include "Ship.class.hpp"

int      Ship::minX = 0;
int      Ship::minY = -10;
int      Ship::maxX = 79;
int      Ship::maxY = 49;


Ship::Ship(void)
{
// std::cout<<"const default call"

}
Ship::Ship(Ship const &src)
{
// std::cout<<"const default call"
	(void)src;
}
Ship::~Ship(void)
{
// std::cout<<"des default call"
}

Ship&	Ship::operator=(Ship const &srcOp)
{
// std::cout<<"operator= call"
	(void)srcOp;

	return *this;
}

/*
 * DIFFERENT STUFF
 */

void		Ship::print(void)
{
	std::cout <<" x = "<< this->x<< " y = "<<this->y;
	std::cout << " etat = " << this->etat<< std::endl;
}
//void	Ship::move()
//{
//}

/*
void		Ship::move(int const x, int const y)
{
	this->setX(x);
	this->setY(y);
}	
*/
/*
 * Getter and setter
 */

int		Ship::getX(void) const
{
	return this->x;
}
void		Ship::setX(int const x)
{
	this->x = x;
}

int		Ship::getY(void) const
{
	return this->y;
}
void		Ship::setY(int const y)
{
	this->y = y;
}

int		Ship::getMinX(void) const
{
	return this->minX;
}
void		Ship::setMinX(int const x)
{
	this->minX = x;
}

int		Ship::getMinY(void) const
{
	return this->minY;
}
void		Ship::setMinY(int const y)
{
	this->minY = y;
}

int		Ship::getMaxX(void) const
{
	return this->maxX;
}
void		Ship::setMaxX(int const x)
{
	this->maxX = x;
}

int		Ship::getMaxY(void) const
{
	return this->maxY;
}
void		Ship::setMaxY(int const y)
{
	this->maxY = y;
}

bool		Ship::getEtat(void) const
{
	return this->etat;
}
void		Ship::setEtat(bool const newEtat)
{
	this->etat = newEtat;
}

/*
std::string		Ship::getImg(void) const
{
	return this->img;
}
void		Ship::setImg(bool const newImg)
{
	this->img = newImg;
}
*/
