/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Title.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:44 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:45 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Title.hpp"

Title::Title( void ) {
	this->_window = new NcNameDisplay();
}

Title::~Title( void ) {
	delete this->_window;
}

NcNameDisplay	*Title::getWindow( void ) const {
	return this->_window;
}

void			Title::display( void ) {
	this->getWindow()->draw(this);
}

void			Title::update( void ) {
}
