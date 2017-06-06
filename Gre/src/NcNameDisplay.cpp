/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcNameDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:05 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:06 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcNameDisplay.hpp"
#include <cstring>

NcNameDisplay::NcNameDisplay ( void ) : ANcursesDisplay()

{
	this->initScreen();
	this->initNewWindow(50, 3, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 3;
	return;
}

NcNameDisplay::NcNameDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 5, x, 0);
	return;
}


NcNameDisplay::NcNameDisplay( NcNameDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcNameDisplay::~NcNameDisplay( void )
{
	return;
}


void		NcNameDisplay::draw( IMonitorModule * src )
{	
	this->borderWindow();
	(void)src;

	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 1, this->getCenter("PonyThor"), "PonyThor");
	wattroff(this->getWindow(), COLOR_PAIR(2));


	this->refresh();
}

void		NcNameDisplay::draw( void )
{	
	this->borderWindow();

	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 1, this->getCenter("PonyThor"), "PonyThor");
	wattroff(this->getWindow(), COLOR_PAIR(2));


	this->refresh();
}


void		NcNameDisplay::update()
{
	return;
}
