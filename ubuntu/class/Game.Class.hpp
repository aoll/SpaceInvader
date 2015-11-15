/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 19:31:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/08 22:26:38 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "Rock.class.hpp"
# include "Vilain.class.hpp"
# include "Shoot.class.hpp"
# include "Shoot2.class.hpp"
# include "Hero.class.hpp"

# include <iostream>
# include <sstream>
# include <ncurses.h>
# include <ctime>
# include <cstdlib>

# define GAMENAME "  _________\n /   _____/__________    ____  ____\n \\_____  \\\\____ \\__  \\ _/ ___\\/ __ \\\n /        \\  |_| \\ __ \\\\  \\__\\  ___/\n/_______  /   __(____  /\\___  >___  >\n        \\/|__|       \\/     \\/    \\/\n.___                         .___\n|   | _______  _______     __| _/___________\n|   |/    \\  \\/ /\\__  \\   / __ |/ __ \\_  __ \\\n|   |   |  \\   /  / __ \\_/ /_/ \\  ___/|  | \\/\n|___|___|  /\\_/  (____  /\\____ |\\___  >__|\n         \\/           \\/      \\/    \\/\n " 

# define  BORDURE "+--------------------------------------------------------------------------------+\n"
# define EMPTY "|                                                                                |\n"

class Game
{
public:
	Game(void);
	Game(Game const &src);
	~Game(void);
	Game		&operator=(Game const &G);

	void		getInput(void);
	void		update(void);
	void		display(void) const;

	int			getTimeStep(void) const;
	void		setTimeStep(int const timeStep);


private:
	int			_timeStep;
	int			_termX;
	int			_termY;
	int			_live;
	int			_score;
	int			_time;
	Rock		_rock[50];
	Hero		_hero;
	Vilain		_vilain[50];

	void	_drawShip(int y, int x, char const *str, int col) const;
	void	_drawHeader(void) const;
	void	_drawMap(void) const;
	void	_drawRock(void) const;
	void	_drawVilain(void) const;
	void	_drawHero(void) const;
	void	_drawVar(int col, int row, char const *str, int var) const;
	void	_collisition(void);

};
# endif
