// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 10:12:52 by aollivie          #+#    #+#             //
/*   Updated: 2015/11/08 21:06:26 by ggilaber         ###   ########.fr       */
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
	long double	next = 0;

	for(;;)
	{
	 		long double curTime = (long double)clock() / 1000000.;
	  		if (curTime > next)
	  		{
	  			next = curTime + 0.05;
				a.getInput();
	 			a.update();
				a.display();
			}
	}			
//	std::cout << result << std::endl;
//	std::cout << timeRef << std::endl;
	return 0;
}
