/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ANcursesDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:04 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:05 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANCURSESDISPLAY_HPP
# define ANCURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include <curses.h>
#include <string>

class ANcursesDisplay : public IMonitorDisplay
{

private:
	int			_nbElem;
	WINDOW *	_win;
	int			_length;
	int 		_height; 
	int 		_x; 
	int 		_y;



public:
    static int  _lastY;
	void		borderWindow( void ) const;
	ANcursesDisplay( void );
	ANcursesDisplay( ANcursesDisplay const & obj );
	virtual ~ANcursesDisplay( void );

	ANcursesDisplay & operator=(ANcursesDisplay const & obj );

	int						getNbElem( void ) const;
	IMonitorDisplay &		setNbElem( int & nb );

	int						getCenter( std::string str );


	void			initScreen( void );
	void			closeScreen( void );
	void			initNewWindow(int length , int height, int x, int y);
	void			refresh( void ) const;
	void			clear( void ) const;
		
	virtual	void	draw( IMonitorModule * src ) = 0;
	virtual	void	update() = 0;
	void			drawGraphBar(int x, int y, int size, int percent);

	void			NameWindow();


	WINDOW *	getWindow( void ) const;
	int			getLength( void ) const;
	int 		getHeight( void ) const;	
	int 		getX( void ) const;	
	int 		getY( void ) const;

	ANcursesDisplay &	setWindow( WINDOW * win );
	ANcursesDisplay &	setLength( int nbr );
	ANcursesDisplay &	setHeight( int nbr );		
	ANcursesDisplay &	setX( int nbr );		
	ANcursesDisplay &	setY( int nbr );
	
};



	

#endif
