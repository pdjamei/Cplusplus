/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:29 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:30 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.hpp"
#include <iostream>
#include "tools.hpp"

OSInfo::OSInfo( void ) {
	this->_window = new NcOSInfoDisplay();
}

OSInfo::OSInfo( int n ) {
	(void)n;
	this->update();
	this->_window = NULL;
}

OSInfo::OSInfo( OSInfo const & src ) : IMonitorModule(src) {
	*this = src;
}

OSInfo::~OSInfo( void ) {
	delete this->_window;
}

OSInfo&			OSInfo::operator=( OSInfo const & rhs ) {
	(void)rhs;
	return *this;
}

std::string		OSInfo::getKernelName( void ) const {
	return this->_kernelName;
}

std::string		OSInfo::getKernelVersion( void ) const {
	return this->_kernelVersion;
}

std::string		OSInfo::getOSName( void ) const {
	return this->_OSName;
}

std::string		OSInfo::getOSVersion( void ) const {
	return this->_OSVersion;
}

void			OSInfo::setKernelName( std::string name ) {
	this->_kernelName = name;
}

void			OSInfo::setKernelVersion( std::string version ) {
	this->_kernelVersion = version;
}

void			OSInfo::setOSName( std::string name ) {
	this->_OSName = name;
}

void			OSInfo::setOSVersion( std::string version ) {
	this->_OSVersion = version;
}

void			OSInfo::update( void ) {
	this->setKernelName(getCmdOutput("/usr/bin/uname"));
	this->setKernelVersion(getCmdOutput("/usr/bin/uname -r"));
	this->setOSName(getCmdOutput("sw_vers -productName"));
	this->setOSVersion(getCmdOutput("sw_vers -productVersion"));
}

void			OSInfo::display( void ) {
	this->getWindow()->draw(this);
}

IMonitorDisplay	*OSInfo::getWindow( void ) const {
	return this->_window;
}
