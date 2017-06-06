/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:39 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:40 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMInfo.hpp"
#include "NcRamDisplay.hpp"
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>

static double ParseMemValue(const char * b)
{
	while((*b)&&(isdigit(*b) == false)) b++;
	return isdigit(*b) ? atof(b) : -1.0;
}

float GetSystemMemoryUsagePercentage()
{
	FILE * fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double pagesUsed = 0.0, totalPages = 0.0;
		char buf[512];
		while(fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;
		}
		pclose(fpIn);

		if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
	}
	return -1.0f;
}

RAMInfo::RAMInfo( void ) {
	this->_window = new NcRamDisplay();
}

RAMInfo::RAMInfo( int n ) {
	(void)n;
	this->update();
	this->_window = NULL;
}

RAMInfo::RAMInfo( RAMInfo const & src ) : IMonitorModule(src) {
	*this = src;
}

RAMInfo::~RAMInfo( void ) {
	delete this->_window;
}

RAMInfo&			RAMInfo::operator=( RAMInfo const & rhs ) {
	(void)rhs;
	return *this;
}

unsigned long		RAMInfo::getTotal( void ) const {
	return this->_total;
}

unsigned long		RAMInfo::getFree( void ) const {
	return this->_free;
}

void				RAMInfo::setFree( unsigned long free ) {
	this->_free = free;
}

void				RAMInfo::setTotal( unsigned long total ) {
	this->_total = total;
}

void				RAMInfo::display( void ) {
	this->getWindow()->draw(this);
}

void				RAMInfo::update( void ) {
	this->setTotal(strtoul(getCmdOutput("sysctl -n hw.memsize").c_str(), NULL, 10));
	this->setUsage(GetSystemMemoryUsagePercentage());
	unsigned long n = this->getUsage() * this->getTotal();
	this->setFree(n);
}

IMonitorDisplay		*RAMInfo::getWindow( void ) const {
	return this->_window;
}

float				RAMInfo::getUsage( void ) const {
	return this->_usage;
}

void				RAMInfo::setUsage( float usage ) {
	this->_usage = usage;
}
