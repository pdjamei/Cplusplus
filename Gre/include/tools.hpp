/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:57:40 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:57:41 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

std::string					getCmdOutput( const char *cmd );
std::vector<std::string>	split(const std::string &s, char delim);
std::vector<std::string>	&split(const std::string &s, char delim, std::vector<std::string> &elems);
