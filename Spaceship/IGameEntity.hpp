/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:29:28 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:29:33 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

# define MAP_WIDTH 		200
# define SCORE_WIDTH 	50
# define HEIGHT			50
# define NB_BULLET		50
# define NB_ENTITY		50
# define NB_ENEMY		7

class ASpaceShip;
class Bullet;

class IGameEntity {
	public	:
		virtual	int				getX( void ) const = 0;
		virtual	int				getY( void ) const = 0;
		virtual int 			getC( void ) const = 0;
		virtual int 			getType( void ) const = 0;
		virtual int				update( void ) = 0;
		virtual int				collide( Bullet * bullet ) = 0;
		virtual int				collide( ASpaceShip * ship ) = 0;
		virtual					~IGameEntity( void );
};

#endif
