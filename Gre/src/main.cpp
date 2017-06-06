/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:48 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 14:35:34 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <QtWidgets>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "QtDisplay.hpp"
#include "HostMonitor.hpp"
#include "DateTimeInfo.hpp"
#include "tools.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include "NetInfo.hpp"
#include "Monitor.hpp"

int 	ANcursesDisplay::_lastY = 0;
struct timeval	NetInfo::_lastTimeUp;
struct timeval	NetInfo::_lastTimeDown;
unsigned long long int 	NetInfo::_lastBytesUp = 0;
unsigned long long int 	NetInfo::_lastBytesDown = 0;

int main(int ac, char *av[])
{
		if (ac < 2) 
		{
			std::cout << "Usage : ./SuperMoni [date, name, cpu, ram, os]" << std::endl;
		}
		else
		{
			std::string test = av[1];
			if (ac >= 2 && test == "gui")
			{

				QApplication app(ac, av);

				QtDisplay  *window = new QtDisplay(&app);
				window->initScreen();
				window->draw(new DateTimeInfo(5), new CPUInfo(5), new RAMInfo(5), new OSInfo(5), new NetInfo(5), new HostMonitor(5));

				return app.exec();
			}
			else
			{
				(void)av; 
				Monitor		monitor(av);

				monitor.doLoop();
			}
		}	
	return 0;
}
