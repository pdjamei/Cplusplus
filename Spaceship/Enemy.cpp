/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:53 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:30:43 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>
#include <Bullet.hpp>
#include <iostream>
#include <cstdlib>

Enemy::Enemy( void ) : ASpaceShip(100,  60, 50, 10, 10, 'E', 0) {
	this->_score = 10;
	this->initBullets();
}

Enemy::Enemy( int hp, int armor, int damage, int X, int Y ) : ASpaceShip(hp,  armor, damage, X, Y, 'E', 0) {
	this->_score = 10;
	this->initBullets();
}

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	this->_score = 10;
	this->initBullets();
}

Enemy::~Enemy( void ) {
}

Enemy&					Enemy::operator=( Enemy const & rhs ) {
	this->_score = rhs._score;
	return *this;
}

void					Enemy::attack( void ) {
	int		ind = -1;

	for (int i = 0; i < NB_BULLET; i++) {
		if (this->_bullets[i] == NULL) {
			ind = i;
			break ;
		}
	}
	if (ind != -1) {
		this->_bullets[ind] = new Bullet(this->_X, this->_Y - 1, this->_damage);
	}
}

int						Enemy::update( void ) {
	static	int			i;
	if (rand() % 42 == 0) {
		this->attack();
	}
	if (i % 2) {
		if (this->move() == -1) {
			return -1;
		}
	}
	i++;
	for (int i = 0; i < NB_BULLET; i++) {
		if (this->_bullets[i] != NULL) {
			if (this->_bullets[i]->update(false) == 0) {
				delete this->_bullets[i];
				this->_bullets[i] = NULL;
			}
		}
	}
	return 0;
}

int						Enemy::getScore( void ) {
	return this->_score;
}
