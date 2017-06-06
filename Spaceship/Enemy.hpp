/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:59 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:29:02 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ENEMY_HPP
# define ENEMY_HPP

# include <ASpaceShip.hpp>

class Enemy : public ASpaceShip {
	private	:
		int			_score;

	public	:
		Enemy( void );
		Enemy( Enemy const & src );
		Enemy( int hp, int armor, int damage, int X, int Y );
		~Enemy( void );
		Enemy&		operator=( Enemy const & rhs );
		void		attack( void );
		int			update( void );
		int			getScore( void );
};

#endif
