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
	const char *tag;

	if (!stream.is_open()){
		cerr << "Error can't read map file .\n";
		return(1);
	}
	getline(stream , line);
	sscanf(line.c_str(), "%d %d", &_height, &_width);
	while (getline(stream, line))
	{
		if (line.empty())
			break;
		labels tile;
		sscanf(line.c_str(), "%d %d %s %s", &(tile.collider) , &(tile.group), (tile.tag), (tile.path));
		_tiles.push_back(tile);
	}

	_tab = vector<vector <int> >(_height , vector<int>(_width));
	int	value;

	for (int i = 0; i < _height; i++){
		for (int j = 0; j < _width; j++){
			value = 0;
			while (stream.get(c))
			{
				if (!isdigit(c))
					break;
				value += value * 10 + (c - '0');
			}
			_tab[i][j] = value;
			Game::addTile(j * 32.0, i * 32.0, 32, 32, value , _tiles[value].path, _tiles[value].tag, _tiles[value].group , _tiles[value].collider);
		}
	}
	stream.close();
	cout << "Loading map done\n";
	return 0;
}