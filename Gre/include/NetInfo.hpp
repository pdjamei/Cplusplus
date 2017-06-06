/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetInfo.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:20 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:21 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		NetInfo_hpp
# define	NetInfo_hpp

# include "IMonitorModule.hpp"
# include "NcNetDisplay.hpp"
# include <sys/time.h>

class NetInfo : public IMonitorModule
{
public:
	NetInfo( void );

	NetInfo( int n );

	NetInfo( NetInfo const & src );

	virtual		~NetInfo();

	NetInfo&			operator=( NetInfo const & rhs );

	unsigned int		getUpspeed( void ) const;

	unsigned int		getDownspeed( void ) const;

	IMonitorDisplay		*getWindow( void ) const;

	std::string			getIP( void ) const;

	void				setUpspeed( unsigned int upspeed );

	void				setDownspeed( unsigned int downspeed );

	unsigned int		calcUpspeed( void );

	unsigned int		calcDownspeed( void );

	void				update( void );

	void				display( void );

	static struct timeval	_lastTimeUp;
	
	static struct timeval	_lastTimeDown;

	static unsigned long long int		_lastBytesUp;

	static unsigned long long int		_lastBytesDown;

private:
	unsigned int		_upspeed;

	unsigned int		_downspeed;

	std::string			_ip;

	NcNetDisplay		*_window;
};

#endif
