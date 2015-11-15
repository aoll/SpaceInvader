#ifndef SHIP_CLASS_HPP
# define SHIP_CLASS_HPP
#include <iostream>
#include <cstdlib>


class Ship
{
public:
	Ship(void);
	Ship(Ship const &src);
	~Ship(void);

	Ship	&operator=(Ship const &srcOp);


// GETTER AND SETTER
	
		
	int     getX(void) const;
	void        setX(int const x);
	int     getY(void) const;
	void        setY(int const y);
	

	int     getMinX(void) const;
	void        setMinX(int const x);
	int     getMinY(void) const;
	void        setMinY(int const y);

	int     getMaxX(void) const;
	void        setMaxX(int const x);
	int     getMaxY(void) const;
	void        setMaxY(int const y);

	bool     getEtat(void) const;
	void        setEtat(bool const newEtat);

	std::string     getImg(void) const;
	void        setImg(bool const newEtat);
	

// LOT A FUNNY STUFF
	void		print(void);

	//virtual void		move(int const x, int const y);
protected:
	
	
	std::string		img;
	int		x;
	int		y;
	static int		minX;
	static int		minY;
	static int		maxX;
	static int		maxY;
	bool	etat;
	
	
	
private:

};
# endif
