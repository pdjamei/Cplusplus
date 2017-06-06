/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ANcursesDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:53:48 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:53:50 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ANcursesDisplay.hpp"
#include <string>



ANcursesDisplay::ANcursesDisplay( void ) : IMonitorDisplay()
{
	return;
}

ANcursesDisplay::ANcursesDisplay( ANcursesDisplay const & obj ) : IMonitorDisplay( obj )
{
	*this = obj;
	return;
}

ANcursesDisplay::~ANcursesDisplay( void )
{
	this->closeScreen();
	return;
}

ANcursesDisplay & ANcursesDisplay::operator=(ANcursesDisplay const & obj )
{
	this->_length =  obj._length;
	this->_height = obj._height;
	this->_win = obj._win;
	return *this;
}


void		ANcursesDisplay::initScreen( void )
{
	initscr();
	raw();
	start_color();
	use_default_colors();
	curs_set(0);
	timeout(3);
	keypad(stdscr, true);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE , COLOR_BLACK);
	init_pair(4, COLOR_GREEN , COLOR_BLACK);
   	init_pair(5, COLOR_YELLOW  , COLOR_BLACK);
   	init_pair(6, COLOR_RED  , COLOR_BLACK);

}

void		ANcursesDisplay::closeScreen( void )
{
	endwin();
}


void		ANcursesDisplay::refresh( void ) const
{
	wrefresh(this->_win);
}

void		ANcursesDisplay::clear() const
{
	wclear(this->_win);
}

void		ANcursesDisplay::initNewWindow(int length , int height, int x, int y)
{
	this->_length = length;
	this->_height = height;
	this->_x = x;
	this->_y = y;

	this->_win = newwin(height,length , x, y);

	this->borderWindow();

   	this->refresh();

}

void		ANcursesDisplay::borderWindow( void ) const
{
	int x, y, i;

	y = this->getHeight();
	x = this->getLength();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(this->getWindow(), COLOR_PAIR(1));
	mvwprintw(this->getWindow(), 0, 0, "+");
	mvwprintw(this->getWindow(), y - 1, 0, "+");
	mvwprintw(this->getWindow(), 0, x - 1, "+");
	mvwprintw(this->getWindow(), y - 1, x - 1, "+");


	for (i = 1; i < (y - 1); i++) {
		mvwprintw(this->getWindow(), i, 0, "|");
		mvwprintw(this->getWindow(), i, x - 1, "|");
	}


	for (i = 1; i < (x - 1); i++) {
		mvwprintw(this->getWindow(), 0, i, "-");
		mvwprintw(this->getWindow(), y - 1, i, "-");
	}

	wattroff(this->getWindow(), COLOR_PAIR(1));

	return;
}

void	ANcursesDisplay::drawGraphBar(int x, int y, int size, int percent)
{
	int val = (percent * size / 100) - 1;
    int i = 0;

    wattron(this->getWindow(), COLOR_PAIR(3));

	mvwprintw(this->getWindow(), y, x - 1, "[");

	wattroff(this->getWindow(), COLOR_PAIR(3));

	while (i <= val)
	{
		if (val < (size / 2))
		{
   			wattron(this->getWindow(), COLOR_PAIR(4));
   		}
   		else if (val >= (size / 2) && val < (size - (size / 4)) )
   		{
   			wattron(this->getWindow(), COLOR_PAIR(5));
   		}
   		else
   		{
   			wattron(this->getWindow(), COLOR_PAIR(6));
   		}

		mvwprintw(this->getWindow(), y, x + i, "#");

		if (val < 45)
		{
   			wattroff(this->getWindow(), COLOR_PAIR(4));
   		}
   		else if (val >= 45 && val < 80)
   		{
   			wattroff(this->getWindow(), COLOR_PAIR(5));
   		}
   		else
   		{
   			wattroff(this->getWindow(), COLOR_PAIR(6));
   		}

		++i;
	}
	while (i < size)
	{
		mvwprintw(this->getWindow(), y, x + i, " ");
		++i;
	}

	mvwprintw(this->getWindow(), y, size + x, "]");
    wattroff(this->getWindow(), COLOR_PAIR(3));
}

int						ANcursesDisplay::getCenter( std::string str ) {
	int x = 25;
	x -= (str.length() / 2);
	if (str.length() % 2) {
		x = x - 1;
	}
	return x;
}

int						ANcursesDisplay::getNbElem( void ) const { return this->_nbElem; }

IMonitorDisplay &		ANcursesDisplay::setNbElem( int & nb ) { this->_nbElem = nb; return *this; }

WINDOW *	ANcursesDisplay::getWindow( void ) const 	{ return this->_win; }
int			ANcursesDisplay::getLength( void ) const 	{ return this->_length; }
int 		ANcursesDisplay::getHeight( void ) const 	{ return this->_height; }
int 		ANcursesDisplay::getX( void ) const 		{ return this->_x; }
int 		ANcursesDisplay::getY( void ) const 		{ return this->_y; }

ANcursesDisplay &	ANcursesDisplay::setWindow( WINDOW * win )	{ this->_win = win; return *this; }
ANcursesDisplay &	ANcursesDisplay::setLength( int nbr )		{ this->_length = nbr; return *this; }
ANcursesDisplay &	ANcursesDisplay::setHeight( int nbr )		{ this->_height = nbr; return *this; }
ANcursesDisplay &	ANcursesDisplay::setX( int nbr )			{ this->_x = nbr; return *this; }
ANcursesDisplay &	ANcursesDisplay::setY( int nbr )			{ this->_y = nbr; return *this; }
