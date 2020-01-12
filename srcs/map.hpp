/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:03:24 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 14:25:05 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "game.hpp"
#include "texture.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>
#include <thread>
#include "texture.hpp"


using namespace std;


class	Map
{
	public	:
		Map();
		~Map();
		int	loadMap(const char *filename);

	private	:
		int		_height;
		int		_width;
};





#endif
