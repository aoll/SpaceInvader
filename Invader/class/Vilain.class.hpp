#ifndef VILAIN_CLASS_HPP
# define VILAIN_CLASS_HPP
#include <iostream>

#include "Ship.class.hpp"

#include "Shoot.class.hpp"

class Vilain : public Ship
{
public:
	Vilain(void);
	Vilain(Vilain const &src);
	~Vilain(void);

	Vilain	&operator=(Vilain const &srcOp);

	static std::string	img;
// GETTER AND SETTER
	static int     getNbVilain(void);

// LOT A FUNNY STUFF
	void		fire(void);
	void		move(void);
// Attribut
	static int	nbVilain;
	
	Shoot	tir[10];
	
protected:


private:
	int		_nbTir;
	int		_nbTirMax;
};
# endif
