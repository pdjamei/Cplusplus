/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:26 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:27 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorModule;

class IMonitorDisplay
{

public:
	virtual ~IMonitorDisplay( void ) = 0;

	virtual	void	draw( IMonitorModule * src ) = 0;
	virtual	void	update() = 0;

	virtual void	initScreen( void ) = 0;
	virtual void	closeScreen( void ) = 0;

};


#endif
