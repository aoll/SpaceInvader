#include "Shoot2.class.hpp"

int		Shoot2::nbShoot2 = 0;
std::string Shoot2::img = "|";



Shoot2::Shoot2(void)
{
	this->etat = false;
}
Shoot2::Shoot2(Shoot2 const &src)
{
	(void)src;
// std::cout<<"const default call"
}
Shoot2::~Shoot2(void)
{
// std::cout<<"des default call"
}

Shoot2&	Shoot2::operator=(Shoot2 const &srcOp)
{
	(void)srcOp;
// std::cout<<"operator= call"
	
	return *this;
}

/*
 * DIFFERENT STUFF
 */


void		Shoot2::move()
{

	this->y -= 1;
	if (this->y == this->minY)
		this->etat = false;

}	

void		Shoot2::go(int x, int y)
{
	this->etat = true;
	this->x = x;
	this->y = y;
}
