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

struct filedata
{
	char *file;
	int range;
	int div;
};


class	Map
{
	public	:
		Map();
		~Map();
		static int	loadMap(const char *filename);
		//static int	readMap(int heigh, int width, vector <tilemap> resourcs);
};





#endif
