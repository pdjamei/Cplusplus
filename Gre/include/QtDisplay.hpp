/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:29 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:30 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QTDISPLAY_HPP
#define QTDISPLAY_HPP

#include <QtWidgets>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "DateTimeInfo.hpp"
#include "CPUInfo.hpp"
#include "RAMInfo.hpp"
#include "OSInfo.hpp"
#include "NetInfo.hpp"
#include "HostMonitor.hpp"

#include "IMonitorDisplay.hpp"

class QtDisplay : public IMonitorDisplay
{
private:
	QWidget *fenetre;
	QApplication *_app;

public:
	QtDisplay();
	QtDisplay(QApplication *app);
	~QtDisplay();

	void			initScreen( void );
	void			run( void );
	void			closeScreen( void );
	void			draw( IMonitorModule * src );
	void			draw( void );
	void			draw(DateTimeInfo * date,CPUInfo * cpu,RAMInfo * ram,OSInfo * os,NetInfo * net,HostMonitor * host);
	void			update();
	
};

#endif
