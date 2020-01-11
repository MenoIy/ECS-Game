/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:31:06 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:59:21 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class	Texture
{
	public	:
		static SDL_Texture *LoadTexture(const char *filename);
		static void	draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
};




#endif
