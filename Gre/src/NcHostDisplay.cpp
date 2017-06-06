/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcHostDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:58 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:00 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcHostDisplay.hpp"
#include "HostMonitor.hpp"

NcHostDisplay::NcHostDisplay ( void ) : ANcursesDisplay(),  _username("Default") , _hostname("Default")

{
	this->initScreen();
	this->initNewWindow(50, 3, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 3;
	return;
}

NcHostDisplay::NcHostDisplay( int x,  std::string username, std::string hostname ) : ANcursesDisplay() , _username(username) , _hostname(hostname)
{
	this->initScreen();
	this->initNewWindow(50, 3, x, 0);
	return;
}


NcHostDisplay::NcHostDisplay( NcHostDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcHostDisplay::~NcHostDisplay( void )
{
	return;
}


void		NcHostDisplay::draw( IMonitorModule * src )
{
	HostMonitor		*h = reinterpret_cast<HostMonitor *>(src);
	char			buff[1024];

	this->borderWindow();
	wattron(this->getWindow(), COLOR_PAIR(2));
	mvwprintw(this->getWindow(), 0, this->getCenter("HOST"), "HOST");
	wattroff(this->getWindow(), COLOR_PAIR(2));
	sprintf(buff, "%s@%s", h->getHostName().c_str(), h->getUserName().c_str());
	mvwprintw(this->getWindow(), 1, this->getCenter(buff), "%s", buff);

	this->refresh();
}

void		NcHostDisplay::update()
{
	return;
}
