/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Title.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:37 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:38 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Title_hpp
# define Title_hpp

# include "IMonitorModule.hpp"
# include "NcNameDisplay.hpp"

class Title : public IMonitorModule
{
public:
	Title( void );

	virtual		~Title();

	NcNameDisplay		*getWindow( void ) const;

	void				display( void );

	void				update( void );

private:
	NcNameDisplay	*_window;

	Title( Title const & src );

	Title&			operator=( Title const & rhs );
};

#endif
