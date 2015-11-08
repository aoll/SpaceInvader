#ifndef ROCK_CLASS_HPP
# define ROCK_CLASS_HPP
#include <iostream>

#include "Ship.class.hpp"


class Rock : public Ship
{
public:
	Rock(void);
	Rock(Rock const &src);
	~Rock(void);

	Rock	&operator=(Rock const &srcOp);

	static std::string	img;
// GETTER AND SETTER
	static int     getNbRock(void);

// LOT A FUNNY STUFF
	static int	nbRock;

	void		move();
protected:


private:

};
# endif
