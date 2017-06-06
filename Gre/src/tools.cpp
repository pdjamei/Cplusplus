/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:55:54 by pdjamei           #+#    #+#             */
/*   Updated: 2015/06/28 12:55:54 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>

std::string				getCmdOutput( const char *cmd ) {
	char				buffer[1024];
	std::string			result = "";
	FILE*				pipe = popen(cmd, "r");

	if(!pipe)
		return "";
	while (!feof(pipe)) {
		if (fgets(buffer, 1024, pipe) != NULL) {
			result += buffer;
		}
	}
	pclose(pipe);
	result = result.substr(0, result.size() - 1);
	return result;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
