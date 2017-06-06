/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:56:08 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:56:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUInfo_hpp
# define CPUInfo_hpp

# include "IMonitorModule.hpp"
# include "NcCpuDisplay.hpp"
# include <iostream>

class CPUInfo : public IMonitorModule
{
public:
	CPUInfo( void );

	CPUInfo( int n );

	CPUInfo( CPUInfo const & src );

	virtual		~CPUInfo();

	CPUInfo&			operator=( CPUInfo const & rhs );

	std::string			getModel( void ) const;

	unsigned int		getFrequence( void ) const;

	unsigned int		getNbCore( void ) const;

	float				getUsage( void ) const;

	NcCpuDisplay		*getWindow( void ) const;

	std::string			getCpuModel( void ) const;

	unsigned int		getCpuNbCore( void ) const;

	unsigned int		getCpuFrequence( void ) const;

	float				getCpuUsage( void ) const;

	void				setUsage( float usage );

	void				setNbCore( unsigned int nbCore );

	void				setModel( std::string model );

	void				setFrequence( unsigned int frequence );

	void				update( void );

	void				display( void );

private:
	std::string			_model;
	unsigned int		_frequence;
	unsigned int		_nbCore;
	float				_usage;
	NcCpuDisplay		*_window;
};

#endif
