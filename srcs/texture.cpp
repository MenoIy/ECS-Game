/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:36:02 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:59:53 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.hpp"
#include "game.hpp"

SDL_Texture* Texture::LoadTexture(const char *file)
{
	SDL_Surface	*tmpSurface;
	SDL_Texture	*texture;
	
	tmpSurface = IMG_Load(file);
	if (tmpSurface == NULL){
		cerr << "Error Loading texture !" << IMG_GetError() << "\n";
		return NULL;
	}
	texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	if (texture == NULL){
		cerr << "Error Creating Texture From Surface" << SDL_GetError() << "\n" ;
	}
	SDL_FreeSurface(tmpSurface);
	return (texture);
}

void	Texture::draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect)
{
	if (SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect)){
		cerr << "Error  RenderCopy Texture " << SDL_GetError() << "\n";
	}
}

