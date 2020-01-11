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


class TileComponent : public Component
{
    public :
        TransformComponent  *transform;
        SpriteComponent     *sprite;
        SDL_Rect            tileRect;
        int                 tileID;
        const char           *path;

        TileComponent() = default;

        TileComponent(int x, int y, int height, int width, int id, const char *path)
        {
            tileRect.x = x;
            tileRect.y = y;
            tileRect.h = height;
            tileRect.w = width;
            tileID = id;
            this->path = path;
        }

        void init() override
        {
            entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.h, tileRect.w, 1);
            transform = &entity->getComponent<TransformComponent>();
            entity->addComponent<SpriteComponent>(path);
            sprite = &entity->getComponent<SpriteComponent>();
        }


};


#endif
