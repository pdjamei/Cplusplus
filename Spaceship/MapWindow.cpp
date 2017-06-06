/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:29:54 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/20 17:29:57 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapWindow.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

		MapWindow::MapWindow( void ) : AWindow( )
		{
			return;
		}

		MapWindow::MapWindow( int Lenght, int Height, int x, int y ) : AWindow( )
		{
			this->initNewWindow(Lenght, Height, x, y);
			this->_fontX = 0;
			this->_fontY = 0;

			return;
		} 

		MapWindow::MapWindow( MapWindow const & obj ) : AWindow( obj )
		{
			*this = obj;
			return ;
		}

		MapWindow::~MapWindow( void )
		{
			delwin(this->getWindow());
			return;
		}

	MapWindow &		MapWindow::operator=( MapWindow const & obj )
	{
		this->setLength( obj.getLength() );
		this->setHeight( obj.getHeight() );
		this->setWindow( obj.getWindow() );
		return *this;
	}

	void			MapWindow::drawWindow( void ) const
	{
		return;
	}

	void			MapWindow::drawWindow( IGameEntity** entities, int nb_obj ) const
	{

		this->borderWindow();
		std::string	*s;
		for (int i = 0; i < nb_obj; i ++) {
			if (entities[i])
			{
				s = new std::string(1, entities[i]->getC());
				mvwprintw(this->getWindow() , entities[i]->getX() , entities[i]->getY() , s->c_str());
				delete s;
			}
		}
		return;
	}

	void			MapWindow::drawWindow( IGameEntity* entity ) const {
	/*	static int fontX = 0;
		static int fontY = 0;


		if (fontX <= - 100 || fontX >= this->getLength() + 1)
		{
			fontX = this->getLength();
		}
		fontY = 0;*/



		if (entity) 
		{
	//		this->font(fontX, fontY );
			this->borderWindow();
			std::string *s = new std::string(1, entity->getC());
			mvwprintw(this->getWindow() , entity->getX() , entity->getY() , s->c_str());
			delete s;
		}
		return;
	}

	void		MapWindow::font( int & x, int & y ) const
	{
		std::string art = "             MDZZZZZZZNI$8Z             W          MMN$$$ZZZZZZM$$$$$$M          W        DNDZZZ$$DZZZZZO$$$$$$$7M        W      MZMNMZ$Z$$MZZD$$MZ$$$$IN$MZ,      W     ZZZZZMN$$I$$ZM$$$$$$$$$ZZ7ZZZM     W    ZZZZZ$$IZ$M$$$$$$$$$$ND$MNI8ZZZ8    W   8ZZZZZZMZZZZ$$$$$$$$$IZZ$ZZZZZZZZ    W  MZZZZZZZZZZ8$ND$$$$$$$$$$ZZZZZZZZZZ   W  $ZZZZZZZZZ8I$$$$$$$$$$$ZZN$NZ$Z$8DZ$  W  ZZZZZZZZN$$$$$$$$$$$$$$NNMNZ7N$ZNZZM  W  ZZZZZZZZ$$$$$$$$$$$$$$$ZZZZZNN$IMZZ$  W  NMZZ$$$M$$$$$$$I$$$$$$ZZZZZZZZZZMZZ$  W  $$Z$$Z$$NN$$$II$IIIII$ZZZZZZZZZZZNZZ  W  $$$$$NZ$$$$$$I$$$I$I$ZZZZZZZZZZZZMZM  W  M$$$$$$MZZZ$$$$$$$$$$IZZZZZZZZZZZZZ   W   I$$$$$$ZZZZZZ$$$$$$$$$$$$NZZZZZZZM   W    $$$$$$ZZZZZZZZM$$$$$$$$$IZZZZN$N    W     $$$$$NZZZZZZZM$$$$$$$$$$ZZZZZM     W      I$$$$NZZZZZZ$$$$$$$$$$MZZZZM      W       D$$$DZZZZ8$$$$$$$$$$$NZZO        W          $$ZZMD$$$$$$$$$$$$I8          W            NM$$$$$$$$$$$$N             W                   ~$                   \0";
		int 	i = 0;
		int  	oy = y;
		int 	ox = x;


		std::string	*s;
		start_color();
		use_default_colors();
		init_pair(1, COLOR_BLUE, COLOR_BLACK);
		wattron(this->getWindow() ,COLOR_PAIR(1));

			i = 0;
			while (art[i] != '\0')
			{
				if (art[i] == 'W')
				{
					ox++;
					ox++;
					ox++;
					oy = 0;
				}
				else
				{
					s = new std::string(1, art[i]);
					mvwprintw(this->getWindow() , oy , ox , s->c_str());
					delete s;
					oy++;
				}
				i++;
			}
		x--;

		
		wattroff(this->getWindow() ,COLOR_PAIR(1));

		this->refresh();

		return;
	}
