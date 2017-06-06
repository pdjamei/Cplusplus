/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:21 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:28:24 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWindow.hpp"

/*	Constructeur destructeur */
		AWindow::AWindow( void )
		{

			return;
		}

		AWindow::AWindow( AWindow const & obj )
		{
			*this = obj;
			return;
		}

		AWindow::~AWindow()
		{

			return;
		}

/* operteur */

		AWindow & 	AWindow::operator=( AWindow const & obj )
		{
			this->setLength( obj.getLength() );
			this->setHeight( obj.getHeight() );
			this->setWindow( obj.getWindow() );
			return *this;
		}

/* Fonction membre */

	void		AWindow::initScreen( void )
	{
		initscr();
		raw();
		curs_set(0);
		timeout(3);
		keypad(stdscr, true);
	}

	void		AWindow::closeScreen( void )
	{
		endwin();
	}

	void		AWindow::initNewWindow(int length , int height, int x, int y)
	{
		this->setLength(length);
		this->setHeight(height);
		this->setX(x);
		this->setY(y);

		this->setWindow(newwin(height,length , x, y));

		this->borderWindow();
	//	box(this->getWindow(), 0, 0);


	   	wrefresh(this->getWindow());

	}

	void		AWindow::borderWindow( void ) const
	{
		int x, y, i;

		y = this->getHeight();
		x = this->getLength();
	//	getmaxyx(this->getWindow(), y, x);
		// 4 corners
		mvwprintw(this->getWindow(), 0, 0, "+");
		mvwprintw(this->getWindow(), y - 1, 0, "+");
		mvwprintw(this->getWindow(), 0, x - 1, "+");
		mvwprintw(this->getWindow(), y - 1, x - 1, "+");
		// sides
		for (i = 1; i < (y - 1); i++) {
			mvwprintw(this->getWindow(), i, 0, "|");
			mvwprintw(this->getWindow(), i, x - 1, "|");
		}
		// top and bottom
		for (i = 1; i < (x - 1); i++) {
			mvwprintw(this->getWindow(), 0, i, "-");
			mvwprintw(this->getWindow(), y - 1, i, "-");
		}

		return;
	}

	void		AWindow::refresh( void ) const
	{
		wrefresh(this->getWindow());
	}

	void		AWindow::clear() const
	{
		wclear(this->getWindow());
	}



/* Get and set */

	WINDOW *	AWindow::getWindow( void ) const 	{ return this->_win; }
	int			AWindow::getLength( void ) const 	{ return this->_length; }
	int 		AWindow::getHeight( void ) const 	{ return this->_height; }
	int 		AWindow::getX( void ) const 		{ return this->_x; }
	int 		AWindow::getY( void ) const 		{ return this->_y; }

	AWindow &	AWindow::setWindow( WINDOW * win )	{ this->_win = win; return *this; }
	AWindow &	AWindow::setLength( int nbr )		{ this->_length = nbr; return *this; }
	AWindow &	AWindow::setHeight( int nbr )		{ this->_height = nbr; return *this; }
	AWindow &	AWindow::setX( int nbr )			{ this->_x = nbr; return *this; }
	AWindow &	AWindow::setY( int nbr )			{ this->_y = nbr; return *this; }


