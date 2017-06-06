/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcNetDisplay.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:09 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcNetDisplay.hpp"
#include "NetInfo.hpp"

NcNetDisplay::NcNetDisplay ( void ) : ANcursesDisplay()

{
	this->initScreen();
	this->initNewWindow(50, 5, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 5;
	return;
}

NcNetDisplay::NcNetDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 4, x, 0);
	return;
}


NcNetDisplay::NcNetDisplay( NcNetDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcNetDisplay::~NcNetDisplay( void )
{
	return;
}


void		NcNetDisplay::draw( IMonitorModule * src )
{
	NetInfo	*n = reinterpret_cast<NetInfo *>(src);
	wclear(this->getWindow());
	this->borderWindow();

	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 0, this->getCenter("NET"), "NET");
	wattroff(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 1, 14, "IP        : %s", n->getIP().c_str());
	mvwprintw(this->getWindow(), 2, 14, "Downspeed : %.2f", static_cast<float>(n->getDownspeed()) / 1000);
	mvwprintw(this->getWindow(), 3, 14, "Upspeed   : %.2f", static_cast<float>(n->getUpspeed()) / 1000);

	this->refresh();
}

void		NcNetDisplay::update()
{
	return;
}
