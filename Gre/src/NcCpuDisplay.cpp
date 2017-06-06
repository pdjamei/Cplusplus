/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcCpuDisplay.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:39 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:40 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcCpuDisplay.hpp"
#include "CPUInfo.hpp"

#include <sstream>

NcCpuDisplay::NcCpuDisplay ( void ) : ANcursesDisplay()
{
	this->initScreen();
	this->initNewWindow(50, 6, ANcursesDisplay::_lastY, 0);
    ANcursesDisplay::_lastY += 6;
	return;
}

NcCpuDisplay::NcCpuDisplay( int x )
{
	this->initScreen();
	this->initNewWindow(50, 6, x, 0);
	return;
}


NcCpuDisplay::NcCpuDisplay( NcCpuDisplay const & obj ) : ANcursesDisplay(obj)
{
	return;
}

NcCpuDisplay::~NcCpuDisplay( void )
{
	return;
}


void		NcCpuDisplay::draw( IMonitorModule * src )
{
	CPUInfo	*c = reinterpret_cast<CPUInfo *>(src);
	int		percent = static_cast<int>(c->getUsage());

	this->borderWindow();

	percent = (percent > 100) ? 100 : percent;

	wattron(this->getWindow(), COLOR_PAIR(2));

	mvwprintw(this->getWindow(), 0, this->getCenter("CPU"), "CPU");

	wattroff(this->getWindow(), COLOR_PAIR(2));

	mvwprintw(this->getWindow(), 1, 3, "Cpu usage : ");
	this->drawGraphBar( 16, 1, 30, percent);
	mvwprintw(this->getWindow(), 2, 3, "Cpu name  : ");
	mvwprintw(this->getWindow(), 2, 15, c->getModel().c_str());
	mvwprintw(this->getWindow(), 3, 3, "Nb core   : ");
	mvwprintw(this->getWindow(), 3, 15, "%d", c->getNbCore());
	mvwprintw(this->getWindow(), 4, 3, "Frequence : ");
	mvwprintw(this->getWindow(), 4, 15, "%.2f GHz", static_cast<float>(c->getFrequence()) / 1000000000);

	this->refresh();
}

void		NcCpuDisplay::update()
{
	return;
}
