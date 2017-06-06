/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcDateDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:44 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:46 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcDateDisplay.hpp"
#include "DateTimeInfo.hpp"

NcDateDisplay::NcDateDisplay ( void ) : ANcursesDisplay()

{
	this->initScreen();
	this->initNewWindow(50, 3, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 3;
	return;
}

NcDateDisplay::NcDateDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 5, x, 0);
	return;
}


NcDateDisplay::NcDateDisplay( NcDateDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcDateDisplay::~NcDateDisplay( void )
{
	return;
}


void		NcDateDisplay::draw( IMonitorModule * src )
{
	DateTimeInfo	*d = reinterpret_cast<DateTimeInfo *>(src);
    this->borderWindow();
	
	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 0, this->getCenter("Date Time"), "Date Time");
	wattroff(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 1, this->getCenter(d->getDate()), "%s", d->getDate().c_str());

	this->refresh();
}

void		NcDateDisplay::update()
{
	return;
}
