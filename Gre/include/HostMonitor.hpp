/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostMonitor.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:18 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:19 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HostMonitor_hpp
# define HostMonitor_hpp

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "NcHostDisplay.hpp"

class HostMonitor : public IMonitorModule
{
public:
							HostMonitor( void );

							HostMonitor( int n );

	virtual					~HostMonitor();

	virtual void			display( void );

	virtual void			update( void );

	std::string				getUserName( void ) const;

	std::string				getHostName( void ) const;
	
	void					setHostName( std::string hostname );
	
	IMonitorDisplay			*getWindow() const;

private:
	std::string	const		_userName;

	std::string				_hostName;

							HostMonitor( HostMonitor const & src );

	HostMonitor&			operator=( HostMonitor const & rhs );

	IMonitorDisplay			*_window;
};

#endif
