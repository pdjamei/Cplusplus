/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcOSInfoDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:09 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCOSINFODISPLAY_HPP
#define NCOSINFODISPLAY_HPP

#include "ANcursesDisplay.hpp"

class NcOSInfoDisplay : public ANcursesDisplay
{
public:
	NcOSInfoDisplay( void );
	NcOSInfoDisplay( int x );
	NcOSInfoDisplay(NcOSInfoDisplay const & obj);
	~NcOSInfoDisplay();

	NcOSInfoDisplay & operator=(NcOSInfoDisplay const & obj);

	void		draw( IMonitorModule * src );
	void		update();
	
};


#endif
