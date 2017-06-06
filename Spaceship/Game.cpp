/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:29:08 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:29:11 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <Enemy.hpp>
#include <curses.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

Game::Game( void ) : _playerName("playerOne"), _playerShip(new PlayerShip()), _scorePoint(0) {
}

Game::Game( Game const & src ) {
	*this = src;
}

Game::Game( std::string const playerName ) :
	_playerName(playerName),
	_playerShip(new PlayerShip()),
	_scorePoint(0)
{
	for (int i = 0; i < NB_ENEMY; i++) {
		this->_entities[i] = NULL;
	}
}

Game::~Game( void ) {
}

Game&			Game::operator=( Game const & rhs ) {
	this->_scorePoint = rhs._scorePoint;
	for (int i = 0; i < NB_ENTITY; i++) {
		this->_entities[i] = rhs._entities[i];
	}
	return *this;
}

PlayerShip*		Game::getPlayerShip( void ) {
	return this->_playerShip;
}

std::string const	Game::getPlayerName( void ) const {
	return this->_playerName;
}

void			Game::generateEnemy( void ) {
	for (int i = 0; i < NB_ENEMY; i++) {
		if (rand() % 7 != 1) {
		if (!this->_entities[i]) {
				this->_entities[i] = new Enemy(100, 10, 10, (rand() % 15) * 3, MAP_WIDTH - 2);
			}
		}
	}
//	this->_entities[0] = new Enemy(10, 10, 10, 3, 25);
}

void			Game::doLoop( void ) {
	int			key = 42;
	clock_t		time_start;
	float		tmp;
	clock_t 	diff;

	srand(time(NULL));
	while (key != 'q') {
		time_start = clock();
		this->generateEnemy();
		key = this->getInput();
		if (key != -1) {
			if (key == ' ') {
				this->getPlayerShip()->attack();
			} else {
				this->getPlayerShip()->move(key);
			}
		}
		if (this->updateEntities() == -1) {
			return ;
		}
		this->renderDisplay();
		diff = clock() - time_start;
		tmp = ((float)diff)/CLOCKS_PER_SEC;
		this->sleepcp( 50 - tmp);
	}
}

void			Game::sleepcp( int millisecond )
{
	if (millisecond > 0)
	{
		clock_t time_end;
		time_end = clock() + millisecond * CLOCKS_PER_SEC/1000;
		while (clock() < time_end)
		{
		}
	}
}

IGameEntity			*Game::checkCollide( ASpaceShip * ship, IGameEntity * entity ) {
	Enemy*			tmp;
	tmp = (Enemy *)entity;
	int ret = tmp->collide(ship);
	switch (ret) {
		case 1	:
			tmp->setAlive(false);
			return entity;
		case 2	:
			tmp->setAlive(false);
			return entity;
		case 3	:
			ship->setAlive(false);
			tmp->setAlive(false);
			return entity;
	}
	ret = ship->collide(tmp);
	switch (ret) {
		case 1	:
			ship->setAlive(false);
			return entity;
		case 2	:
			tmp->setAlive(false);
			return entity;
		case 3	:
			ship->setAlive(false);
			tmp->setAlive(false);
			return entity;
	}
	return entity;
}

IGameEntity			*Game::checkCollide( IGameEntity * entity) {
	IGameEntity**		entities = this->_entities;
	Enemy				*enemy, *tmp;
	tmp = (Enemy *) entity;
	int				ret = -1;
	for (int i = 0; i < NB_ENTITY; i++) {
		if (entities[i]) {
			enemy = (Enemy *) entities[i];
			switch (entities[i]->getType()) {
				case 0	:
					ret = entity->collide((Enemy *)entities[i]);
					break;
				case 1	:
					ret = entity->collide((Bullet *)entities[i]);
					break;
				case 2	:
					ret = entity->collide((PlayerShip *)entities[i]);
					break;
			}
			if (entity != entities[i]) {
				switch (ret) {
					case 1	:
						enemy->setAlive(false);
						return entity;
					case 2	:
						enemy->setAlive(false);
						return entity;
					case 3	:
						tmp->setAlive(false);
						enemy->setAlive(false);
						return entity;
				}
			}
		}
	}
	return entity;
}

int				Game::updateEntities( void ) {
	int			score;
	Enemy*		enemy;
	this->getPlayerShip()->update();
	this->_playerShip = (PlayerShip *) this->checkCollide(this->getPlayerShip());
	if (this->_playerShip) {
		for (int i = 0; i < NB_ENTITY; i++) {
			score = 0;
			if (this->_entities[i]) {
				enemy = (Enemy *) this->_entities[i];
				if (this->_entities[i]->update() == -1) {
					this->_entities[i] = NULL;
				} else {
					score = enemy->getScore();
					this->_entities[i] = this->checkCollide(this->_playerShip, this->_entities[i]);
					if (!this->_playerShip->isAlive()) {
						return -1;
					}
					if (this->_entities[i] && enemy->isAlive()) {
						this->_entities[i] = this->checkCollide(this->_entities[i]);
					} else {
						delete this->_entities[i];
						this->_entities[i] = NULL;
						this->_scorePoint += score;
					}
				}
			}
		}
	}
	return 1;
}

void			Game::renderDisplay( void ) {
	IGameEntity	*spaceShip = (IGameEntity *)this->_playerShip;
	Bullet		**tmp = this->_playerShip->getBullet();
	IGameEntity **bullets = (IGameEntity **)tmp;
	Enemy*		enemies;

	this->getMapWindow()->clear();
	this->getMapWindow()->drawWindow(spaceShip);
	this->getMapWindow()->drawWindow(this->_entities, NB_ENTITY);
	this->getMapWindow()->drawWindow(bullets, NB_BULLET);
	for (int i = 0; i < NB_ENEMY; i++) {
		if (this->_entities[i] != NULL) {
			enemies = (Enemy *)this->_entities[i];
			bullets = (IGameEntity **)enemies->getBullet();
			this->getMapWindow()->drawWindow(bullets, NB_BULLET);
		}
	}
	this->getMapWindow()->refresh();
}

int				Game::getInput( void ) {
	int			key = getch();
	return key;
}

void			Game::initMap( int width, int height, int x, int y ) {
	this->_map = new MapWindow(width, height, x, y);
}

MapWindow const *		Game::getMapWindow( void ) const {
	return this->_map;
}

int						Game::getScore( void ) {
	return this->_scorePoint;
}
