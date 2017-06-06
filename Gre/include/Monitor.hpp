/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:35 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:36 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Monitor_hpp
# define Monitor_hpp

# include "IMonitorModule.hpp"
# include <list>
# include <vector>
# include <iostream>

class Monitor
{
public:
	Monitor( void );

	Monitor( char **av );

	Monitor( Monitor const & src );

	virtual		~Monitor();

	Monitor&			operator=( Monitor const & rhs );

	void				initMap( std::vector<std::string> modules );

	void				doLoop( void );

private:
	std::list<IMonitorModule*>	_moduleMap;
};

#endif
