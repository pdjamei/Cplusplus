/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcCpuDisplay.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:42 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:42 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCCPUDISPLAY_HPP
#define NCCPUDISPLAY_HPP

#include "ANcursesDisplay.hpp"

class IMonitorModule;

class NcCpuDisplay : public ANcursesDisplay
{

public:
	NcCpuDisplay();
	NcCpuDisplay( NcCpuDisplay const & obj );
	NcCpuDisplay(int x);
	~NcCpuDisplay();
	
	NcCpuDisplay & operator=(NcCpuDisplay const & obj);
	
	void		draw( IMonitorModule * src );
	void		update();
};

#endif
