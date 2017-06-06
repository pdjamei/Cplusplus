/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:30:00 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:30:03 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPWINDOW_HPP
# define MAPWINDOW_HPP

# include "AWindow.hpp"

class MapWindow : public AWindow {


public:
	/* Constructeur destructeur */
	MapWindow( void );
	MapWindow( MapWindow const & obj );
	MapWindow( int Lenght, int Height, int x, int y );
	~MapWindow();

	/* oprateur */
	MapWindow & 	operator=( MapWindow const & obj );

	/* fonction membre */
	void	drawWindow( void ) const;
	void	drawWindow( IGameEntity** entities, int nb_obj ) const;
	void	drawWindow( IGameEntity* entity ) const;
	void	font(  int & x, int & y ) const;

private:
	int 	_fontX;
	int 	_fontY;
};


#endif
