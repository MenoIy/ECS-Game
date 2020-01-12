/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:24:53 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:54:54 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

#define FPS 60

using namespace std;
class ColliderComponent;


enum groupLabels : std::size_t
{
	groupMap,
	groupColliders,
	groupEnemis,
	groupBonus,
	groupPlayers
};

class	Game
{
	public	:
		Game();
		~Game();
		int		init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen);
		void	handleEvents();
		void	update();
		void	render();
		void	clean();
		bool	running(){ return _isRunning; }
		static SDL_Renderer	*renderer;
		static SDL_Event event;
		static std::vector<ColliderComponent *> colliders;
		static std::vector<pair<int, SDL_Texture* >> GlobalTexture;
		static void addTile(int srcX, int srcY, int x, int y, const char *path);

	private	:
		bool 			_isRunning;
		SDL_Window		*_window;
};









# endif
