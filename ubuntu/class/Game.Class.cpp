/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 19:31:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/08 22:57:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.Class.hpp"

Game::Game(void) : _timeStep(200000), _live(5), _score(0), _time(0)
{
	initscr();        //init terminal
	curs_set(0);      //enlever cursor
       	nodelay(stdscr, true);     //getch non-bloquant
	keypad(stdscr, true);      //KEY_LEFT
	start_color();	
	cbreak();
	init_pair(Hero::col, COLOR_RED, COLOR_BLACK);
	init_pair(Vilain::col, COLOR_BLUE, COLOR_BLACK);
	init_pair(Shoot::col, COLOR_YELLOW, COLOR_BLACK);
	init_pair(Rock::col, COLOR_WHITE, COLOR_BLACK);
	/*
	getmaxyx(stdscr, this->_termY, this->_termX);  //get termsize

	if (this->_termX < 90 || this->_termY < 65)
	{
		mvprintw((this->_termY - 17) / 2, this->_termX / 2, "enlarge your term\n");
		refresh();
		//		sleep(2);
		endwin();
		exit(0);
	}
	*/
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
		this->_hero.move((b == KEY_RIGHT ? true : false));
	else if (b == KEY_UP || b == KEY_DOWN)
			this->_hero.moveUp((b == KEY_UP ? true : false));
	else if (b == ' ')
		this->_hero.fire();
	else if (b == KEY_NPAGE || (b == 'y' && this->_hero.life <= 0))
	{
		this->_hero.init();
		this->_score = 0;
	}
	else if (b == KEY_NPAGE || (b == 'n' && this->_hero.life <= 0))
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
	for (int i=0; i < this->_hero.life; ++i)
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

void		Game::_drawShip(int y, int x, char const *str, int col) const
{
	attron(COLOR_PAIR(col));
	mvprintw(14 + y, x + 1, str);
	attroff(COLOR_PAIR(col));
}

void		Game::_drawVilain(void) const
{
	for (std::size_t i=0; i<50; ++i) {
		if (this->_vilain[i].getEtat() && this->_vilain[i].getY() >= 0) 
		{
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX(), Vilain::img.c_str(), Vilain::col);
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX() - 1, "=", Vilain::col);
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX() + 1, "=", Vilain::col);
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX() - 2, "=", Vilain::col);
			this->_drawShip(this->_vilain[i].getY(), this->_vilain[i].getX() + 2, "=", Vilain::col);
			for (std::size_t j=0; j< 10; ++j){
				if (this->_vilain[i].tir[j].getEtat() == true)
					this->_drawShip(this->_vilain[i].tir[j].getY(), this->_vilain[i].tir[j].getX(), Shoot::img.c_str(), Shoot::col);}
		}
	}
}

void		Game::_drawRock(void) const
{
	for (std::size_t i=0; i<50; ++i) {
		if (this->_rock[i].getEtat() && this->_rock[i].getY() >= 0) {
			this->_drawShip(this->_rock[i].getY(), this->_rock[i].getX(), Rock::img.c_str(), Rock::col);
		}
	}
}

void		Game::_drawHero(void) const
{
	this->_drawShip(this->_hero.getY(), this->_hero.getX(), Hero::img.c_str(), Hero::col);
	//this->_drawShip(this->_hero.getY() + 1, this->_hero.getX(), Hero::img.c_str(), Hero::col);
	this->_drawShip(this->_hero.getY() + 1, this->_hero.getX() - 1, "|", Hero::col);
	this->_drawShip(this->_hero.getY() + 1, this->_hero.getX() + 1, "|", Hero::col);
	
	for (std::size_t j=0; j< 100; ++j)
	{
		if (this->_hero.tir[j].getEtat() == true)
			this->_drawShip(this->_hero.tir[j].getY(), this->_hero.tir[j].getX(), Shoot2::img.c_str(), Shoot::col);
	}
}

void		Game::update(void)
{
	this->_time += this->_timeStep / 3000;




//	COLLISION  Contre le Hero!!!
	for (std::size_t i=0; i< 50; ++i) {
		if (this->_rock[i].getEtat() == true && this->_rock[i].getX() == this->_hero.getX() && this->_rock[i].getY() == this->_hero.getY())
		{
			beep();
			this->_hero.life--;
		}
		else if (this->_vilain[i].getEtat() == true && this->_vilain[i].getX() == this->_hero.getX() && this->_vilain[i].getY() == this->_hero.getY())
		{
			beep();
			this->_hero.life--;
		}

			for (std::size_t j=0; j< 10; ++j){
				if (this->_vilain[i].getEtat() == true && this->_vilain[i].tir[j].getEtat() == true && this->_vilain[i].tir[j].getX() == this->_hero.getX() && this->_vilain[i].tir[j].getY() == this->_hero.getY())
		{
					beep();
					this->_hero.life--;
		}
				else if (this->_vilain[i].getEtat() == true && this->_vilain[i].tir[j].getEtat() == true && this->_vilain[i].tir[j].getX() == this->_hero.getX() && this->_vilain[i].tir[j].getY() == this->_hero.getY() - 1)
		{
					beep();
					this->_hero.life--;
		}
		
			}
	}

//	COLLISION  Contre les Vilains!!!
	for (std::size_t i=0; i< 100; ++i) {
		
		for (std::size_t z=0; z< 50; ++z){
			if (this->_vilain[z].getEtat() == true && this->_hero.tir[i].getEtat() == true && this->_vilain[z].getX() == this->_hero.tir[i].getX() && this->_vilain[z].getY() == this->_hero.tir[i].getY())
			 {
				 this->_vilain[z].setEtat(false);
				 this->_score += 10;
			 }
			else if (this->_vilain[z].getEtat() == true && this->_hero.tir[i].getEtat() == true && this->_vilain[z].getX() == this->_hero.tir[i].getX() && this->_vilain[z].getY() - 1== this->_hero.tir[i].getY())
			 {
				 this->_vilain[z].setEtat(false);
				 this->_score += 10;
			 }

/*				 for (std::size_t j=0; j< 50; ++j){
					 if (this->_vilain[z].tir[j].getEtat() == true && this->_vilain[z].tir[j].getX() == this->_hero.tir[i].getX() && this->_vilain[z].tir[j].getY() == this->_hero.tir[i].getY())
					 {
						 this->_vilain[z].tir[j].setEtat(false);
						 this->_score += 10;
					 }
				 }
*/		}
	}
	
	for (std::size_t i = 0; i < 100; ++i){
		for (std::size_t z=0; z < 50; ++z){
			if (this->_rock[z].getEtat() == true && this->_rock[z].getX() == this->_hero.tir[i].getX() && this->_rock[z].getY() == this->_hero.tir[i].getY())
				this->_hero.tir[i].setEtat(false);
			else if (this->_rock[z].getEtat() == true && this->_rock[z].getX() == this->_hero.tir[i].getX() && this->_rock[z].getY() == this->_hero.tir[i].getY() + 1)
				this->_hero.tir[i].setEtat(false);
			else if (this->_rock[z].getEtat() == true && this->_rock[z].getX() == this->_hero.tir[i].getX() && this->_rock[z].getY() == this->_hero.tir[i].getY() - 1)
				this->_hero.tir[i].setEtat(false);
		}
	}


										


//	SCORE !!!

	for (std::size_t i=0; i< 50; ++i) {
		this->_rock[i].move();
		this->_vilain[i].move();
		for (std::size_t j=0; j< 10; ++j){
			this->_vilain[i].tir[j].move();}
		
	}	
		for (std::size_t j=0; j< 100; ++j){
				this->_hero.tir[j].move();} 
//	this->_hero.move();


}

void		Game::display(void) const
{
	this->_drawHeader();
	this->_drawMap();
	this->_drawRock();
	if (_hero.life > 0)
		this->_drawHero();
	else
		mvprintw(this->_termY / 2, (this->_termX - 20) / 2, "Wanna retry looser ?");
	this->_drawVilain();
	refresh();
}

int		Game::getTimeStep(void) const
{return this->_timeStep;}
void		Game::setTimeStep(int const timeStep)
{this->_timeStep = timeStep;}
