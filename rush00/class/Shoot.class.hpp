#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
#include <iostream>

#include "Ship.class.hpp"


class Shoot : public Ship
{
public:
	Shoot(void);
	Shoot(Shoot const &src);
	~Shoot(void);

	Shoot	&operator=(Shoot const &srcOp);

	static std::string	img;
	static int			col;
// GETTER AND SETTER
	static int     getNbShoot(void);

// LOT A FUNNY STUFF
	static int	nbShoot;

	void		go(int x, int y);

	void		move();
protected:


private:

};
# endif
