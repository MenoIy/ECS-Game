/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:00:29 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:54:17 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"
#include "map.hpp"

Game	*game = NULL;

int main()
{
	game = new Game();
	unsigned int	frameStart;
	int				frameTime;

	if (game->init("testing",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false)){
		cerr << "Failed to start the game.\n";
		return (0);
	}

	const int		frameDelay = 1000 / FPS;
	while (game->running()){
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = frameStart - SDL_GetTicks();
		if (frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return (0);
}
