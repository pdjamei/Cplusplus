/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:28:07 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:28:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ASpaceShip.hpp>
#include <ncurses.h>
#include <cstdlib>

ASpaceShip::ASpaceShip( void ) {
	this->initBullets();
	this->_HP = 0;
	this->_maxHP = 0;
	this->_armor = 0;
	this->_X = 0;
	this->_Y = 0;
	this->_alive = true;
	this->_damage = 0;
	this->_C = 'C';
	this->_colided = false;
	this->_type = 4;
}

ASpaceShip::ASpaceShip( ASpaceShip const & src ) {
	this->initBullets();
	*this = src;
}

ASpaceShip::ASpaceShip( int hp, int armor, int damage, int X, int Y, char C, int type) :
	_HP(hp), _maxHP(hp), _armor(armor), _damage(damage), _X(X), _Y(Y), _C(C), _alive(true), _colided(false), _type(type)
{
	this->initBullets();
}

ASpaceShip::~ASpaceShip( void ) {
}

ASpaceShip&		ASpaceShip::operator=( ASpaceShip const & rhs ) {
	this->_HP = rhs._HP;
	this->_maxHP = rhs._maxHP;
	this->_armor = rhs._armor;
	this->_damage = rhs._damage;
	this->_X = rhs._X;
	this->_Y = rhs._Y;
	this->_alive = rhs._alive;
	return *this;
}

int				ASpaceShip::getHP( void ) const {
	return this->_HP;
}

void			ASpaceShip::takeDamage( int amount ) {
	amount -= this->_armor;
	amount = (amount < 0) ? 0 : amount;
	this->_HP -= amount;
	this->_alive = (this->_HP < 0) ? false : true;
}

bool			ASpaceShip::isAlive( void ) const {
	return this->_alive;
}

void			ASpaceShip::move( int key ) {
	switch (key) {
		case KEY_LEFT :
			this->move( 0, -1 );
			break;
		case KEY_RIGHT :
			this->move( 0, +1 );
			break;
		case KEY_UP :
			this->move( -1, 0 );
			break;
		case KEY_DOWN :
			this->move( +1, 0 );
			break;
	}
}

void			ASpaceShip::initBullets( void ) {
	for (int i = 0; i < NB_BULLET; i++) {
		this->_bullets[i] = NULL;
	}
}

void			ASpaceShip::setAlive( bool alive ) {
	this->_alive = alive;
}

void			ASpaceShip::move( int x, int y ) {
	this->_X += x;
	this->_Y += y;
	this->_X = (this->_X < 1) ? 1 : this->_X;
	this->_Y = (this->_Y < 1) ? 1 : this->_Y;
	this->_Y = (this->_Y > MAP_WIDTH - 2) ? MAP_WIDTH - 2 : this->_Y;
	this->_X = (this->_X > HEIGHT - 2) ? HEIGHT - 2 : this->_X;
}

int				ASpaceShip::move( void ) {
	int			x = 0, y = -1;
	if (rand() % 50 == 0) {
		if (rand() % 2) {
			x = 1;
		} else {
			x = -1;
		}
	}
	this->move(x, y);
	if(this->_Y <= 2) {
		return -1;
	}
	return 1;
}

int				ASpaceShip::getY( void ) const {
	return this->_Y;
}

int				ASpaceShip::getX( void ) const {
	return this->_X;
}

int 		ASpaceShip::getC( void ) const {
	return this->_C;
}

int 			ASpaceShip::getType( void ) const {
	return this->_type;
}

int				ASpaceShip::collide( ASpaceShip * ship ) {
	int			ret = -1;
	if (this != ship) {
		if (this->_X == ship->_X && this->_Y == ship->_Y) {
			return 3;
		}
		for (int i = 0; i < NB_BULLET; i++) {
			if (this->_bullets[i]) {
				ret = ship->collide(this->_bullets[i]);
				if (ret) {
					delete this->_bullets[i];
					this->_bullets[i] = NULL;
					return ret;
				}
			}
		}
	}
	return 0;
}

int				ASpaceShip::collide( Bullet * bullet ) {
	if (this->_X == bullet->getX() && this->_Y == bullet->getY()) {
		return 2;
	}
	return 0;
}

Bullet			**ASpaceShip::getBullet( void ) {
	return this->_bullets;
}
