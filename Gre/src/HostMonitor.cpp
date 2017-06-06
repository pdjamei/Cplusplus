/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostMonitor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:09 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostMonitor.hpp"
#include <iostream>
#include "tools.hpp"

HostMonitor::HostMonitor( void ) : _userName(getCmdOutput("/usr/bin/users")), _hostName(getCmdOutput("/bin/hostname")) {
	this->_window = new NcHostDisplay();
}

HostMonitor::HostMonitor( int n ) : _userName(getCmdOutput("/usr/bin/users")), _hostName(getCmdOutput("/bin/hostname")) {
	(void)n;
	this->update();
	this->_window = NULL;
}

HostMonitor::HostMonitor( HostMonitor const & src ) : IMonitorModule(src) {
	*this = src;
}

HostMonitor::~HostMonitor( void ) {
	delete this->_window;
}

HostMonitor&			HostMonitor::operator=( HostMonitor const & rhs ) {
	(void)rhs;
	return *this;
}

void					HostMonitor::display( void ) {
	this->getWindow()->draw(this);
}

void					HostMonitor::update( void ) {
	this->setHostName(getCmdOutput("/bin/hostname"));
}

std::string				HostMonitor::getHostName( void ) const {
	return this->_hostName;
}

std::string				HostMonitor::getUserName( void ) const {
	return this->_userName;
}

void					HostMonitor::setHostName( std::string hostname ) {
	this->_hostName = hostname;
}

IMonitorDisplay			*HostMonitor::getWindow( void ) const {
	return this->_window;
}
