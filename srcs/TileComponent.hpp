/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TileComponent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:08:50 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/10 16:08:52 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILECOMPONENT_HPP
#define TILECOMPONENT_HPP

#include "components.hpp"
#include "SDL.h"
#include "ECL.hpp"
#include "game.hpp"
#include <vector>


class TileComponent : public Component
{
    public :
        SDL_Texture*         texture;
        SDL_Rect        srcRect, destRect;

        TileComponent() = default;

        TileComponent(int srcX, int srcY, int xpos, int ypos, const char *path)
        {
            bool s =  true;
            for (auto e : Game::GlobalTexture){
                if (e.first == srcX / 32  + (srcY  / 32) * 8){
                        texture = e.second;
                        s = false;
                    }
            }
            if (s){
                texture = Texture::LoadTexture(path);
                Game::GlobalTexture.emplace_back(std::make_pair(srcX / 32  + (srcY  / 32) * 8, texture));
            }
            srcRect.x = srcX;
            srcRect.y = srcY;
            srcRect.w = srcRect.h = 32;

            destRect.x = xpos;
            destRect.y = ypos;
            destRect.w = destRect.h = 32;
        }
        ~TileComponent()
        {
            SDL_DestroyTexture(texture);
        }

        void draw() override
        {
            Texture::draw(texture, srcRect, destRect);
        }


};


#endif
