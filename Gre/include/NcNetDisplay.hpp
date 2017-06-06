/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcNetDisplay.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:01 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:02 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCNETDISPLAY_HPP
#define NCNETDISPLAY_HPP

#include "ANcursesDisplay.hpp"

class NcNetDisplay : public ANcursesDisplay
{
public:
	NcNetDisplay();
	NcNetDisplay( NcNetDisplay const & obj );
	NcNetDisplay(int x);
	~NcNetDisplay();
	
	NcNetDisplay & operator=(NcNetDisplay const & obj);
	
	void		draw( IMonitorModule * src );
	void		update();
};

#endif
