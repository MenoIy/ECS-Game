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



static int	readMap(char *file, int group, int height, int width,int gridSize , vector <filedata> resources)
{
	ifstream stream(file);
	int value;
	char c;
	int cap, div;
	char *path;
	int srcX, srcY;
	
	for(int i = 0; i < height ; i++){
		for (int j = 0; j < width; j++){
			value = 0;
			while(stream.get(c))
			{
				if (!isdigit(c))
					break;
				value = value * 10 + (c - '0');
			}
			if (value != 0){
				for (auto& e : resources){
					if (value >= e.range){
						path = e.file;
						div = e.div;
						cap = e.range;
						break;
					}
				}
				if (group < 100){
					srcY = (value - cap) / div;
					srcX = (value - cap) % div;
					Game::addTile(srcX * gridSize, srcY * gridSize , j * gridSize , i * gridSize ,group, value ,path);
				}
				else{
					Game::addCollider(j * gridSize, i * gridSize, gridSize, gridSize);
				}
			}
		}
	}
	stream.close();
	return (0);
}

static bool sortinrev(const filedata &a, const filedata &b) 
{ 
       return (a.range > b.range); 
} 

int Map::loadMap(const char *filename)
{
	ifstream	stream(filename);
	string line;
	vector < filedata > resources;

	int count = 0;
	if (!stream.is_open()){
		cerr << "Error can't read map file .\n";
		return(1);
	}

	getline(stream , line);	
	sscanf(line.c_str(), "%d %d %d %d", &height, &width, &gridSize , &count);
	while (getline(stream, line))
	{
		if (line.empty())
			break;
		filedata data;
		data.file = (char *)malloc(sizeof(char ) * 100);
		sscanf(line.c_str(), "%d %d %s", &(data.range), &(data.div), data.file);
		resources.emplace_back(data);
	}
	sort(resources.begin(), resources.end(), sortinrev);

	thread th[count];
	char file[count][100];
	for(int i = 0; i < count  && getline(stream , line) ; i++){
		int group;
		sscanf(line.c_str(), "%d %s", &group, file[i]);
		th[i] = thread(readMap, file[i], group , height, width, gridSize, resources);
	}
	for (int i = 0; i < count ; i++){
		th[i].join();
	}
	for (auto&e : resources){
		free(e.file);
	}
	stream.close();
	cout << "Loading map done\n";
	return 0;
}