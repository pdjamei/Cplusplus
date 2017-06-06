/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcNameDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:57 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:57 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCNAMEDISPLAY_HPP
#define NCNAMEDISPLAY_HPP

#include "ANcursesDisplay.hpp"

class NcNameDisplay : public ANcursesDisplay
{
public:
	NcNameDisplay();
	NcNameDisplay( int x );
	NcNameDisplay(NcNameDisplay const & obj);
	~NcNameDisplay();

	NcNameDisplay & operator=(NcNameDisplay const & obj);
	
	void		draw( IMonitorModule * src );
	void		draw( void );
	void		update();
};


#endif
