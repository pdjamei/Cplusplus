/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcHostDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:51 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:52 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NcHOSTDISPLAY_HPP
# define NcHOSTDISPLAY_HPP

#include "ANcursesDisplay.hpp"
#include <iostream>

class NcHostDisplay : public ANcursesDisplay
{
private:
	std::string		_username;
	std::string 	_hostname;


public:
	NcHostDisplay( void );
	NcHostDisplay( int x, std::string username, std::string hostname );
	NcHostDisplay( NcHostDisplay const & obj );
	~NcHostDisplay( void );

	NcHostDisplay &  operator=( NcHostDisplay const & obj );
	
	void		draw( IMonitorModule * src );
	void		update();
};

# endif
