/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColliderComponent.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:02:02 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/10 11:02:04 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDERCOMPONENT_HPP
#define COLLIDERCOMPONENT_HPP

#include "SDL.h"
#include <string>
#include "components.hpp"
#include "ECL.hpp"
#include <vector>



class ColliderComponent : public Component
{
    public :
        SDL_Rect    collider;
        std::string     tag;
        TransformComponent *transform;

        ColliderComponent(std::string t)
        {
            tag = t;
        }

        void init() override
        {
            if (!entity->hasComponent<TransformComponent>()){
                entity->addComponent<TransformComponent>();
            } 
            transform = &entity->getComponent<TransformComponent>();
            Game::colliders.push_back(this);
        }

        void update() override
        {
            collider.x = static_cast<int>(transform->position.x);
            collider.y = static_cast<int>(transform->position.y);
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }
};



#endif
