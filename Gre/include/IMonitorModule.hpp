/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:30 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:31 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorModule_hpp
# define IMonitorModule_hpp

# include "tools.hpp"

class IMonitorDisplay;

class IMonitorModule
{
private:

public:
	virtual					~IMonitorModule( void );

	virtual void			update( void ) = 0;

	virtual void			display( void ) = 0;

	virtual IMonitorDisplay	*getWindow() const = 0;
};

#endif
