/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:30:16 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:30:19 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PLAYERSHIP_HPP
# define PLAYERSHIP_HPP

# include <ASpaceShip.hpp>

class PlayerShip : public ASpaceShip {
	private	:
		int			_live;

	public	:
		PlayerShip( void );
		PlayerShip( PlayerShip const & src );
		PlayerShip( int hp, int armor, int damage, int X, int Y );
		virtual ~PlayerShip( void );
		PlayerShip&		operator=( PlayerShip const & rhs );
		void		attack( void );
		int			getLive( void ) const;
		int			update( void );
};

#endif
