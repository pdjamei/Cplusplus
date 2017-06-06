/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeInfo.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:14 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:15 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DateTimeInfo_hpp
# define DateTimeInfo_hpp

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "NcDateDisplay.hpp"

class DateTimeInfo : public IMonitorModule
{
public:
	DateTimeInfo( void );

	DateTimeInfo( int n );

	DateTimeInfo( DateTimeInfo const & src );

	virtual		~DateTimeInfo();

	DateTimeInfo&			operator=( DateTimeInfo const & rhs );

	time_t					getTimestamp( void ) const;

	std::string				getDate( void ) const;

	std::string				getTime( void ) const;

	IMonitorDisplay			*getWindow() const;

	void					setTimestamp( time_t timestamp );

	void					setDate( std::string date );

	void					setTime( std::string time );

	void					update( void );

	void					display( void );

private:
	time_t					_timestamp;
	std::string				_sdate;
	IMonitorDisplay			*_window;
};

#endif
