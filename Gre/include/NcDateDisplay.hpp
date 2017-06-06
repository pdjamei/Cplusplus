/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcDateDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:47 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:48 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCDATEDISPLAY_HPP
#define NCDATEDISPLAY_HPP

#include "ANcursesDisplay.hpp"

class NcDateDisplay : public ANcursesDisplay
{
public:
	NcDateDisplay();
	NcDateDisplay( int x );
	NcDateDisplay(NcDateDisplay const & obj);
	~NcDateDisplay();

	NcDateDisplay & operator=(NcDateDisplay const & obj);
	
	void		draw( IMonitorModule * src );
	void		update();
};


#endif
