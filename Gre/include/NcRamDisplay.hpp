/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcRamDisplay.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:16 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:16 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCRAMDISPLAY_HPP
#define NCRAMDISPLAY_HPP

#include "ANcursesDisplay.hpp"

class NcRamDisplay : public ANcursesDisplay
{
public:
	NcRamDisplay();
	NcRamDisplay( NcRamDisplay const & obj );
	NcRamDisplay(int x);
	~NcRamDisplay();
	
	NcRamDisplay & operator=(NcRamDisplay const & obj);
	
	void		draw( IMonitorModule * src );
	void		update();
};

#endif
