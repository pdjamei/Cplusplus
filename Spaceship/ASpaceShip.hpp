/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:13 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:28:16 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPACE_SHIP_HPP
# define ASPACE_SHIP_HPP

# include <IGameEntity.hpp>
# include <Bullet.hpp>
# include <ctime>
# include <iostream>

class ASpaceShip : public IGameEntity {
	protected	:
		int			_HP;
		int			_maxHP;
		int			_armor;
		int			_damage;
		int			_X;
		int			_Y;
		char		_C;
		bool		_alive;
		bool		_colided;
		time_t		_lastMove;
		time_t		_lastAttack;
		int			_type;
		Bullet		*_bullets[50];

	public		:
		ASpaceShip( void );
		ASpaceShip( ASpaceShip const & src );
		ASpaceShip( int hp, int armor, int damage, int X, int Y, char C, int type);
		~ASpaceShip( void );
		ASpaceShip&		operator=( ASpaceShip const & rhs );
		void			move( int x, int y);
		void			move( int key );
		int				move( void );
		virtual void	attack( void ) = 0;
		void			takeDamage( int amount );
		bool			isAlive( void ) const;
		int				getHP( void ) const;
		int				getX( void ) const;
		int				getY( void ) const;
		int 			getC( void ) const;
		int 			getType( void ) const;
		virtual int		update( void ) = 0;
		void			initBullets( void );
		Bullet			**getBullet( void );
		int				collide( ASpaceShip * ship );
		int				collide( Bullet * bullet );
		void			setAlive( bool alive );
};

#endif
