#ifndef SHOOT2_CLASS_HPP
# define SHOOT2_CLASS_HPP
#include <iostream>

#include "Ship.class.hpp"


class Shoot2 : public Ship
{
public:
	Shoot2(void);
	Shoot2(Shoot2 const &src);
	~Shoot2(void);

	Shoot2	&operator=(Shoot2 const &srcOp);

	static std::string	img;
// GETTER AND SETTER
	static int     getNbShoot2(void);

// LOT A FUNNY STUFF
	static int	nbShoot2;

	void		go(int x, int y);

	void		move();
protected:


private:

};
# endif
