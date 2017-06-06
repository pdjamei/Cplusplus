/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:29 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:31 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.hpp"
#include "DateTimeInfo.hpp"
#include "RAMInfo.hpp"
#include "CPUInfo.hpp"
#include "OSInfo.hpp"
#include "HostMonitor.hpp"
#include "Title.hpp"
#include "NetInfo.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <unistd.h>

Monitor::Monitor( char **av ) {
	std::vector<std::string>	v;

	for (int i = 1; av[i]; i++) {
		v.push_back(av[i]);
	}
	this->initMap(v);
}

Monitor::Monitor( void ) { }

Monitor::Monitor( Monitor const & src ) {
	*this = src;
}

Monitor::~Monitor( void ) { }

Monitor&			Monitor::operator=( Monitor const & rhs ) {
	(void)rhs;
	return *this;
}

void				Monitor::initMap( std::vector<std::string> modules ) {
	std::vector<std::string>::iterator		itBegin = modules.begin();
	std::vector<std::string>::iterator		itEnd = modules.end();
	modules.erase(std::unique(modules.begin(), modules.end()), modules.end());

	this->_moduleMap.push_back(new Title());
	for (; itBegin != itEnd; ++itBegin) {
		if (*itBegin == "date") {
			this->_moduleMap.push_back(new DateTimeInfo());
		} else if (*itBegin == "name") {
			this->_moduleMap.push_back(new HostMonitor());
		} else if (*itBegin == "os") {
			this->_moduleMap.push_back(new OSInfo());
		} else if (*itBegin == "cpu") {
			this->_moduleMap.push_back(new CPUInfo());
		} else if (*itBegin == "ram") {
			this->_moduleMap.push_back(new RAMInfo());
		} else if (*itBegin == "net") {
			this->_moduleMap.push_back(new NetInfo());
		}
	}
}

void				Monitor::doLoop() {
	std::list<IMonitorModule*>::iterator	itBegin;
	std::list<IMonitorModule*>::iterator	itEnd;

	do {
		itBegin = this->_moduleMap.begin();
		itEnd = this->_moduleMap.end();
		for (; itBegin != itEnd; ++itBegin) {
			(*itBegin)->update();
			(*itBegin)->display();
		}
		usleep(500000);
    } while( getch() != 'q');
	for (itBegin = this->_moduleMap.begin(); itBegin != itEnd; ++itBegin) {
		delete *itBegin;
	}
}
