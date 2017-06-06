/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:30 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:28:33 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWINDOW_HPP
# define AWINDOW_HPP

# include <IGameEntity.hpp>
# include <curses.h>

class AWindow {

private:
	WINDOW *	_win;
	int			_length;
	int 		_height; 
	int 		_x; 
	int 		_y;

public:
	/*	Constructeur destructeur */
		AWindow( void );
		AWindow( AWindow const & obj );
		~AWindow();

	/* operteur */

	AWindow & 	operator=( AWindow const & obj );

	/* Fonction membre */

	static void		initScreen( void );

	static void		closeScreen( void );

	void			initNewWindow(int length , int height, int x, int y);

	void			borderWindow( void ) const;

	virtual void	drawWindow( void ) const = 0;

	void			refresh( void ) const;
	
	void			clear( void ) const;



	/* get and set */
	WINDOW *	getWindow( void ) const;
	int			getLength( void ) const;
	int 		getHeight( void ) const;	
	int 		getX( void ) const;	
	int 		getY( void ) const;		

	AWindow &	setWindow( WINDOW * win );
	AWindow &	setLength( int nbr );
	AWindow &	setHeight( int nbr );		
	AWindow &	setX( int nbr );		
	AWindow &	setY( int nbr );			

};

#endif

