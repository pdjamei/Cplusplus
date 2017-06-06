/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfo.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:33 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:34 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RAMInfo_hpp
# define	RAMInfo_hpp

# include "IMonitorModule.hpp"
# include "NcRamDisplay.hpp"

class RAMInfo : public IMonitorModule
{
public:
	RAMInfo( void );

	RAMInfo( int n );

	RAMInfo( RAMInfo const & src );

	virtual		~RAMInfo();

	RAMInfo&			operator=( RAMInfo const & rhs );

	unsigned long		getTotal( void ) const;

	unsigned long		getFree( void ) const;

	IMonitorDisplay		*getWindow( void ) const;

	float				getUsage( void ) const;

	void				setTotal( unsigned long total );

	void				setFree( unsigned long free );

	void				setUsage( float usage );

	void				update( void );

	void				display( void );

private:
	unsigned long		_total;

	unsigned long		_free;

	float				_usage;

	NcRamDisplay		*_window;
};

#endif
