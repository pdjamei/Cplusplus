/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeInfo.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:54:02 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:54:04 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "QtDisplay.hpp"
#include "DateTimeInfo.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

DateTimeInfo::DateTimeInfo( void ) {
	this->_window = new NcDateDisplay();
}

DateTimeInfo::DateTimeInfo( int n ) {
	(void)n;
	this->update();
	this->_window = NULL;
}

DateTimeInfo::DateTimeInfo( DateTimeInfo const & src ) : IMonitorModule(src) {
	*this = src;
}

DateTimeInfo::~DateTimeInfo( void ) {
	delete this->_window;
}

DateTimeInfo&			DateTimeInfo::operator=( DateTimeInfo const & rhs ) {
	(void)rhs;
	return *this;
}

time_t					DateTimeInfo::getTimestamp( void ) const {
	return this->_timestamp;
}

std::string				DateTimeInfo::getDate( void ) const {
	return this->_sdate;
}

void					DateTimeInfo::setTimestamp( time_t timestamp ) {
	this->_timestamp = timestamp;
}

void					DateTimeInfo::setDate( std::string date ) {
	this->_sdate = date;
}

void					DateTimeInfo::update( void ) {
	time_t				raw = time(NULL);
	this->setTimestamp(raw);
	struct tm*			timeinfo = localtime(&raw);
	char				buffer[1024];
	strftime(buffer, 1024, "%A, %B %d, %Y %I:%M:%S %p", timeinfo);
	this->setDate(buffer);
}

void					DateTimeInfo::display( void ) {
	this->getWindow()->draw(this);
}

IMonitorDisplay			*DateTimeInfo::getWindow( void ) const {
	return this->_window;
}
