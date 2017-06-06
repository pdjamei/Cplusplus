/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:24 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:25 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSInfo_hpp
# define OSInfo_hpp

#include <iostream>
#include "IMonitorModule.hpp"
#include "NcOSInfoDisplay.hpp"

class OSInfo : public IMonitorModule
{
public:
	OSInfo( void );

	OSInfo( int n );

	OSInfo( OSInfo const & src );

	virtual				~OSInfo();

	OSInfo&				operator=( OSInfo const & rhs );

	std::string			getKernelName( void ) const;

	std::string			getKernelVersion( void ) const;

	std::string			getOSName( void ) const;

	std::string			getOSVersion( void ) const;
	
	IMonitorDisplay		*getWindow() const;

	void				setKernelName( std::string name );

	void				setKernelVersion( std::string version );

	void				setOSName( std::string name );

	void				setOSVersion( std::string version );

	void				update( void );
	
	void				display( void );

private:
	std::string			_kernelName;

	std::string			_kernelVersion;

	std::string			_OSName;
	
	std::string			_OSVersion;

	NcOSInfoDisplay		*_window;
};

#endif
