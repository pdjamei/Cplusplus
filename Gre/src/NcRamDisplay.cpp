/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcRamDisplay.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:20 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:22 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcRamDisplay.hpp"
#include "RAMInfo.hpp"

NcRamDisplay::NcRamDisplay ( void ) : ANcursesDisplay()

{
	this->initScreen();
	this->initNewWindow(50, 4, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 4;
	return;
}

NcRamDisplay::NcRamDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 4, x, 0);
	return;
}


NcRamDisplay::NcRamDisplay( NcRamDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcRamDisplay::~NcRamDisplay( void )
{
	return;
}


void		NcRamDisplay::draw( IMonitorModule * src )
{
	RAMInfo	*r = reinterpret_cast<RAMInfo *>(src);
	
	this->borderWindow();

	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 0, this->getCenter("RAM"), "RAM");
	wattroff(this->getWindow(), COLOR_PAIR(2));

	mvwprintw(this->getWindow(), 1, this->getCenter("XX.XX / XX.XX GB"), "%.2f / %.2f GB", static_cast<float>(r->getFree()) / 1024 / 1024 / 1024, static_cast<float>(r->getTotal()) / 1024 / 1024 / 1024);
	this->drawGraphBar(4, 2, 42, static_cast<int>(r->getUsage() * 100));


	this->refresh();
}

void		NcRamDisplay::update()
{
	return;
}
