/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 19:31:53 by ggilaber          #+#    #+#             */
//   Updated: 2015/11/08 13:03:23 by aollivie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

Game::Game(void) : _timeStep(200000), _live(5), _score(0), _time(0)
{
	initscr();        //init terminal
	curs_set(0);      //enlever cursor
	nodelay(stdscr, true);     //getch non-bloquant
	keypad(stdscr, true);      //KEY_LEFT
	getmaxyx(stdscr, this->_termY, this->_termX);  //get termsize

	if (this->_termX < 90 || this->_termY < 65)
	{
		mvprintw((this->_termY - 17) / 2, this->_termX / 2, "enlarge your term\n");
		refresh();
		sleep(2);
		endwin();
		exit(0);
	}
}

Game::Game(Game const &src)
{(void)src;}

Game::~Game(void)
{
	endwin();
}

Game	&Game::operator=(Game const &G)
{
	(void)G;
	return *this;
}

void		Game::getInput(void) 
{
	int b;

	b = getch();
	if (b == KEY_LEFT || b == KEY_RIGHT)
		this->_hero[0].move((b == KEY_RIGHT ? true : false));
	//else if (b == )
	//else if (b == KEY_NPAGE)
	if (b == KEY_NPAGE)
	{
		endwin();
		exit(0);
	}
}

void		Game::_drawVar(int row, int col, char const *str, int var) const
{
	std::ostringstream	s;

	mvprintw(row, col, str);
	s << var;
	printw(s.str().c_str());
}

void		Game::_drawHeader(void) const
{
	std::ostringstream	s;

	mvprintw(0, 0, GAMENAME);
	this->_drawVar(5, 60, "score: ", this->_score);
	this->_drawVar(6, 60, " time: ", this->_time / 1000);

	mvprintw(9, 60, " live:");
	for (int i=0; i < this->_live; ++i)
		s << "^ ";
	mvprintw(9, 67, s.str().c_str());
}

void		Game::_drawMap(void) const
{
	std::ostringstream	s;

	mvprintw(13, 0, BORDURE);
	for (std::size_t i=0; i < 50; ++i)
		printw(EMPTY);
	printw(BORDURE);
}

void		Game::_drawShip(int y, int x, char const *str) const
{mvprintw(14 + y, x + 1, str);}

void		Game::_drawVilain(void) const
{
	for (std::size_t i=0; i<50; ++i) {
		if (this->_vilain[i].getEtat() && this->_vilain[i].getY() >= 0) 
		{
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX(), Vilain::img.c_str());
			for (std::size_t j=0; j< 10; ++j){
				if (this->_vilain[i].tir[j].getEtat() == true)
					this->_drawShip(this->_vilain[i].tir[j].getY(), this->_vilain[i].tir[j].getX(), Shoot::img.c_str());}
		}
	}
}

void		Game::_drawRock(void) const
{
	for (std::size_t i=0; i<50; ++i) {
		if (this->_rock[i].getEtat() && this->_rock[i].getY() >= 0) {
			this->_drawShip(this->_rock[i].getY(), this->_rock[i].getX(), Rock::img.c_str());
		}
	}
}

void		Game::_drawHero(void) const
{
	this->_drawShip(this->_hero[0].getY(), this->_hero[0].getX(), Hero::img.c_str());
}

void		Game::update(void)
{
	this->_time += this->_timeStep / 1000;

//	SCORE !!!

	for (std::size_t i=0; i< 50; ++i) {
		this->_rock[i].move();
		this->_vilain[i].move();
		for (std::size_t j=0; j< 10; ++j)
			{this->_vilain[i].tir[j].move();}
	}
//	this->_hero.move();


//	COLLISION !!!
}

void		Game::display(void) const
{
	this->_drawHeader();
	this->_drawMap();
	this->_drawRock();
	this->_drawVilain();
	this->_drawHero();
	refresh();
}

int		Game::getTimeStep(void) const
{return this->_timeStep;}
void		Game::setTimeStep(int const timeStep)
{this->_timeStep = timeStep;}
