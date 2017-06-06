/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:52 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:54 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetInfo.hpp"
#include "NcNetDisplay.hpp"
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>

NetInfo::NetInfo( void ) {
	this->_window = new NcNetDisplay();
	gettimeofday(&NetInfo::_lastTimeUp, NULL);
	gettimeofday(&NetInfo::_lastTimeDown, NULL);
	NetInfo::_lastBytesUp = 0;
	NetInfo::_lastBytesDown = 0;
}
NetInfo::NetInfo( int n ) {
	(void)n;
	this->_window = NULL;
	this->update();
	gettimeofday(&NetInfo::_lastTimeUp, NULL);
	gettimeofday(&NetInfo::_lastTimeDown, NULL);
	NetInfo::_lastBytesUp = 0;
	NetInfo::_lastBytesDown = 0;
}

NetInfo::NetInfo( NetInfo const & src ) : IMonitorModule(src) {
	*this = src;
}

NetInfo::~NetInfo( void ) {
	delete this->_window;
}

NetInfo&			NetInfo::operator=( NetInfo const & rhs ) {
	(void)rhs;
	return *this;
}

unsigned int		NetInfo::getUpspeed( void ) const {
	return this->_upspeed;
}

unsigned int		NetInfo::getDownspeed( void ) const {
	return this->_downspeed;
}

void				NetInfo::setUpspeed( unsigned int upspeed ) {
	this->_upspeed = upspeed;
}

void				NetInfo::setDownspeed( unsigned int downspeed ) {
	this->_downspeed = downspeed;
}

void				NetInfo::display( void ) {
	this->getWindow()->draw(this);
/*	std::cout << "Up : " << static_cast<float>(this->getUpspeed()) / 1000 << std::endl;
	std::cout << "Down : " << static_cast<float>(this->getDownspeed()) / 1000 << std::endl;*/
}

void				NetInfo::update( void ) {
	this->setUpspeed(this->calcUpspeed());
	this->setDownspeed(this->calcDownspeed());
	this->_ip = getCmdOutput("ipconfig getifaddr en0");
}

IMonitorDisplay		*NetInfo::getWindow( void ) const {
	return this->_window;
}

unsigned int		NetInfo::calcUpspeed( void ) {
	struct timeval	currentTime;
	gettimeofday(&currentTime, NULL);
	std::string		currentByte = getCmdOutput("netstat -ib -I en0 | grep en0 | head -n1 | awk \'{print $10}\'");
	long			diff, seconds, useconds;
	unsigned long long int	diff_octets = strtoull(currentByte.c_str(), NULL, 10) - NetInfo::_lastBytesUp;


	seconds = currentTime.tv_sec - NetInfo::_lastTimeUp.tv_sec;
	useconds = currentTime.tv_usec - NetInfo::_lastTimeUp.tv_usec;
	diff = ((seconds) * 1000 + useconds/ 1000.0) + 0.5;
	if (diff >= 800) {
		NetInfo::_lastTimeUp = currentTime;
		NetInfo::_lastBytesUp = strtoull(currentByte.c_str(), NULL, 10);
		return diff_octets / diff;
	}
	return this->_upspeed;
}

unsigned int		NetInfo::calcDownspeed( void ) {
	struct timeval	currentTime;
	gettimeofday(&currentTime, NULL);
	std::string		currentByte = getCmdOutput("netstat -ib -I en0 | grep en0 | head -n1 | awk \'{print $7}\'");
	long			diff, seconds, useconds;
	unsigned long long int	diff_octets = strtoull(currentByte.c_str(), NULL, 10) - NetInfo::_lastBytesDown;


	seconds = currentTime.tv_sec - NetInfo::_lastTimeDown.tv_sec;
	useconds = currentTime.tv_usec - NetInfo::_lastTimeDown.tv_usec;
	diff = ((seconds) * 1000 + useconds/ 1000.0) + 0.5;
	if (diff >= 800) {
		NetInfo::_lastTimeDown = currentTime;
		NetInfo::_lastBytesDown = strtoull(currentByte.c_str(), NULL, 10);
		return diff_octets / diff;
	}
	return this->_downspeed;
}

std::string			NetInfo::getIP( void ) const {
	return this->_ip;
}
