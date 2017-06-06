/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcOSInfoDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:15 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:16 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcOSInfoDisplay.hpp"
#include "OSInfo.hpp"

NcOSInfoDisplay::NcOSInfoDisplay ( void ) : ANcursesDisplay()

{
	this->initScreen();
	this->initNewWindow(50, 6, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 6;
	return;
}

NcOSInfoDisplay::NcOSInfoDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 6, x, 0);
	return;
}


NcOSInfoDisplay::NcOSInfoDisplay( NcOSInfoDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcOSInfoDisplay::~NcOSInfoDisplay( void )
{
	return;
}


void		NcOSInfoDisplay::draw( IMonitorModule * src )
{
	OSInfo	*o = reinterpret_cast<OSInfo *>(src);
	char	buff[1024];

	this->borderWindow();
	
	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 0, this->getCenter("OS"), "OS");
	wattroff(this->getWindow(), COLOR_PAIR(2));


	sprintf(buff, "OS Name     : %s", o->getOSName().c_str());
	int x = this->getCenter(buff);
	mvwprintw(this->getWindow(), 1, x, "%s", buff);
	sprintf(buff, "OS Vers     : %s", o->getOSVersion().c_str());
	mvwprintw(this->getWindow(), 2, x, "%s", buff);
	sprintf(buff, "Kernel Name : %s", o->getKernelName().c_str());
	mvwprintw(this->getWindow(), 3, x, "%s", buff);
	sprintf(buff, "Kernel Vers : %s", o->getKernelVersion().c_str());
	mvwprintw(this->getWindow(), 4, x, "%s", buff);

	this->refresh();
}

void		NcOSInfoDisplay::update()
{
	return;
}
