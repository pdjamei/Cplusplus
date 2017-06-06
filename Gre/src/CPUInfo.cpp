/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:53:56 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:53:57 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfo.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include "tools.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}

float getCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}

CPUInfo::CPUInfo( void ) {
	this->_window = new NcCpuDisplay();
}

CPUInfo::CPUInfo( int n ) {
	(void)n;
	this->update();
	this->_window = NULL;
}

CPUInfo::CPUInfo( CPUInfo const & src ) : IMonitorModule(src) {
	*this = src;
}

CPUInfo::~CPUInfo( void ) {
	delete this->_window;
}

CPUInfo&			CPUInfo::operator=( CPUInfo const & rhs ) {
	(void)rhs;
	return *this;
}

std::string			CPUInfo::getModel( void ) const {
	return this->_model;
}

unsigned int		CPUInfo::getFrequence( void ) const {
	return this->_frequence;
}

unsigned int		CPUInfo::getNbCore( void ) const {
	return this->_nbCore;
}

float				CPUInfo::getUsage( void ) const {
	return this->_usage;
}

void				CPUInfo::setNbCore( unsigned int nbCore ) {
	this->_nbCore = nbCore;
}

void				CPUInfo::setUsage( float usage ) {
	this->_usage = usage;
}

void				CPUInfo::setModel( std::string model ) {
	this->_model = model;
}

void				CPUInfo::setFrequence( unsigned int frequence ) {
	this->_frequence = frequence;
}

void				CPUInfo::update( void ) {
	this->setModel(this->getCpuModel());
	this->setNbCore(this->getCpuNbCore());
	this->setFrequence(this->getCpuFrequence());
	this->setUsage(this->getCpuUsage());
}

void				CPUInfo::display( void ) {
	this->_window->draw(this);
}

std::string			CPUInfo::getCpuModel( void ) const {
	return getCmdOutput("sysctl -n machdep.cpu.brand_string | cut -d@ -f1");
}

unsigned int		CPUInfo::getCpuNbCore( void ) const {
	return strtoul(getCmdOutput("sysctl -n machdep.cpu.core_count").c_str(), NULL, 10);
}

unsigned int		CPUInfo::getCpuFrequence( void ) const {
	return strtoul(getCmdOutput("sysctl -n hw.cpufrequency").c_str(), NULL, 10);
}

float				CPUInfo::getCpuUsage( void ) const {
//	std::string s 	= getCmdOutput("ps aux | awk {'sum+=$3;print sum'} | tail -n 1");
	std::string s 	= getCmdOutput("top -l 1 | head -n 10 | grep \"CPU usage\" | cut -d\' \' -f3 | cut -d% -f1");
	return strtof(s.c_str(), NULL);
}

NcCpuDisplay		*CPUInfo::getWindow( void ) const {
	return this->_window;
}
