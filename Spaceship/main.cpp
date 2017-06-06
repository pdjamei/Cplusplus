/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:30:23 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:30:25 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PlayerShip.hpp>
#include <Bullet.hpp>
#include <Game.hpp>
#include <Enemy.hpp>

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#include <MapWindow.hpp>

Game		*init_game(std::string const name) {
	Game *game = new Game(name);
	MapWindow::initScreen();
	return game;
}

int main(int ac, char **av)
{
	Game *game;

	if (ac == 2) {
		game = init_game(av[1]);

		game->initMap(MAP_WIDTH, HEIGHT, 0, 0);
		game->doLoop();
		MapWindow::closeScreen();
	} else {
		std::cout << "Usage: ./ft_retro <playerName>" << std::endl;
	}
}
