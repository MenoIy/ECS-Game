/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:05:50 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 16:41:02 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

int	Map::loadMap(const char *filename)
{
	ifstream	stream(filename);
	string line;

	_width = 0;
	_height = 0;
	char c;
	//133
	if (!stream.is_open()){
		cerr << "Error can't read map file .\n";
		return(1);
	}
	getline(stream , line);
	sscanf(line.c_str(), "%d %d", &_height, &_width);
	getline(stream, line);
	char path1[100];
	sscanf(line.c_str(), "%s", path1);
	char path2[100];
	getline(stream, line);
	sscanf(line.c_str(), "%s", path2);
	int	srcX, srcY, value;

	for (int i = 0; i < _height; i++){
		for (int j = 0; j < _width; j++){
			value = 0;
			while (stream.get(c))
			{
				if (!isdigit(c))
					break;
				value = value * 10 + (c - '0');
			}
			if (value + 577 >= 1641){
				srcY = (value + 577  - 1641) / 8;
				srcX = (value + 577 - 1641) % 8;
				Game::addTile(srcX * 32, srcY * 32 , j * 32 , i * 32 , path2);
			}
			else{
				srcY = (value / 8);
				srcX = value % 8;
				Game::addTile(srcX * 32, srcY * 32 , j * 32 , i * 32 , path1);
			}
		}
	}
	stream.close();
	cout << "Loading map done\n";
	return 0;
}