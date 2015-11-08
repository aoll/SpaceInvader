// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 10:12:52 by aollivie          #+#    #+#             //
//   Updated: 2015/11/08 10:48:38 by aollivie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "class/Game.Class.hpp"
#include "class/Rock.class.hpp"
#include "class/Ship.class.hpp"
#include "class/Vilain.class.hpp"
#include "class/Shoot.class.hpp"


int		main(void)
{
	Game a;

	for(;;)
	{
		a.getInput();
		a.update();
		a.display();
		usleep(100000);
	}

	return 0;
}
