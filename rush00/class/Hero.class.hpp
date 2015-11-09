#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP
#include <iostream>

#include "Ship.class.hpp"

#include "Shoot2.class.hpp"

class Hero : public Ship
{
public:
	Hero(void);
	Hero(Hero const &src);
	~Hero(void);

	Hero	&operator=(Hero const &srcOp);

	static std::string	img;
	static int			col;
// GETTER AND SETTER
	static int     getNbHero(void);

// LOT A FUNNY STUFF
	void		fire(void);
	void		move(bool const move);
	void		moveUp(bool const move);
	void		init(void);



// Attribut
	static int	nbHero;
	
	Shoot2	tir[100];
	int		life;

	void	takeDammage(void);
	
protected:


private:
	int		_nbTir;
	int		_nbTirMax;
};
# endif
