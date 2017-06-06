/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:34 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:35 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "QtDisplay.hpp"
#include <iostream>

	QtDisplay::QtDisplay()
	{
		return;
	}
	QtDisplay::~QtDisplay()
	{
		return;
	}

	QtDisplay::QtDisplay(QApplication *app)
	{
		this->_app = app;
	}

	void			QtDisplay::initScreen( void )
	{
	    this->fenetre = new QWidget();
	    this->fenetre->setFixedSize(350, 600);
	 
	}
	void			QtDisplay::run( void )
	{
		this->fenetre->show();
	}

	void	QtDisplay::draw( 
		DateTimeInfo * date,
		CPUInfo * cpu,
		RAMInfo * ram,
		OSInfo * os,
		NetInfo * net,
		HostMonitor * host
		)
	{
	    QVBoxLayout *layout = new QVBoxLayout;
		QString		str;
		QLabel* label=new QLabel(this->fenetre);
		QLabel* label1=new QLabel(this->fenetre);
		QLabel* label2=new QLabel(this->fenetre);
		QLabel* label3=new QLabel(this->fenetre);
		QLabel* label4=new QLabel(this->fenetre);
		QLabel* label5=new QLabel(this->fenetre);
		QLabel* label6=new QLabel(this->fenetre);
		QLabel* label7=new QLabel(this->fenetre);
		QLabel* label8=new QLabel(this->fenetre);
		QLabel* label9=new QLabel(this->fenetre);
		QLabel* label10=new QLabel(this->fenetre);
		QLabel* label11=new QLabel(this->fenetre);
		QLabel* label12=new QLabel(this->fenetre);
		QLabel* label13=new QLabel(this->fenetre);
		QLabel* label14=new QLabel(this->fenetre);
		QLabel* label15=new QLabel(this->fenetre);

		str = "Name : ";
		str += QString::fromStdString(host->getUserName());
		label->setText(str);
		str = "Host : ";
		str += QString::fromStdString(host->getHostName());
		label1->setText(str);

		str = "Date : ";
		str += QString::fromStdString(date->getDate());
		label2->setText(str);

		str = "CPU : ";
		str += QString::fromStdString(cpu->getModel());
		label3->setText(str);

		str = "Freq : ";
		str += QString::number(static_cast<float>(cpu->getFrequence()) / 1000 / 1000 / 1000);
		str += " GHz";
		label4->setText(str);

		str = "CPU Usage : ";
		str += QString::number(cpu->getUsage());
		str += "%";
		label5->setText(str);

		str = "Core : ";
		str += QString::number(cpu->getNbCore());
		label6->setText(str);

		str = "Ram Total : ";
		str += QString::number(static_cast<float>(ram->getTotal()) / 1024 / 1024 / 1024);
		str += ".00 GB";
		label7->setText(str);

		str = "Ram Free : ";
		str += QString::number(static_cast<float>(ram->getFree()) / 1024 / 1024 / 1024);
		str += " GB";
		label8->setText(str);

		str = "OS Name : ";
		str += QString::fromStdString(os->getOSName());
		label9->setText(str);

		str = "OS Version : ";
		str += QString::fromStdString(os->getOSVersion());
		label10->setText(str);

		str = "Kernel Name : ";
		str += QString::fromStdString(os->getKernelName());
		label11->setText(str);

		str = "Kernel Version : ";
		str += QString::fromStdString(os->getKernelVersion());
		label12->setText(str);

		str = "Upspeed : ";
		str += QString::number(net->getUpspeed());
		label13->setText(str);

		str = "Downspeed : ";
		str += QString::number(net->getDownspeed());
		label14->setText(str);

		str = "IP : ";
		str += QString::fromStdString(net->getIP());
		label15->setText(str);




	    layout->addWidget(label);
	    layout->addWidget(label1);
	    layout->addWidget(label2);
	    layout->addWidget(label3);
	    layout->addWidget(label4);
	    layout->addWidget(label5);
	    layout->addWidget(label6);
	    layout->addWidget(label7);
	    layout->addWidget(label8);
	    layout->addWidget(label9);
	    layout->addWidget(label10);
	    layout->addWidget(label11);
	    layout->addWidget(label12);
	    layout->addWidget(label13);
	    layout->addWidget(label14);
	    layout->addWidget(label15);
    	this->fenetre->setLayout(layout);

    	this->run();
	}

	void	QtDisplay::draw( IMonitorModule * src )
	{
		(void) src;
	}

	void	QtDisplay::draw( void )
	{

		QLabel* label=new QLabel(this->fenetre);

		label->setText("Test");

		QLabel* label1=new QLabel(this->fenetre);
				label1->setText("Test2");

	    QPushButton *bouton3 = new QPushButton("Zéros");

	    QVBoxLayout *layout = new QVBoxLayout;
	    layout->addWidget(label1);
	    layout->addWidget(label);
	    layout->addWidget(bouton3);

    	this->fenetre->setLayout(layout);

    	this->run();
	}
	void	QtDisplay::update()
	{
		return;
	}
	
	void		QtDisplay::closeScreen()
	{
		return;
	}
