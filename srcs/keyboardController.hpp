/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboardController.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:26:21 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/10 10:26:23 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "game.hpp"
#include "ECL.hpp"
#include "components.hpp"



class KeyBoardController : public Component
{
    public :
        TransformComponent *transform;
        SpriteComponent *sprite;
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }
    void update() override
    {
        if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
                case SDLK_w :
                    transform->velocity.y = -1;
                    sprite->play("down");
                    break;
                case SDLK_s :
                    transform->velocity.y = 1;
                    sprite->play("up");
                    break;
                case SDLK_a :
                    transform->velocity.x = -1;
                    sprite->play("left");
                    break;
                case SDLK_d :
                    transform->velocity.x = 1;
                    sprite->play("right");
                    break;
                default :
                    break;
            }
        }
       if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
                case SDLK_w :
                    transform->velocity.y = 0;
                    sprite->play("up");
                    break;
                case SDLK_s :
                    transform->velocity.y = 0;
                    sprite->play("up");
                    break;
                case SDLK_a :
                    sprite->play("up");
                    transform->velocity.x = 0;
                    break;
                case SDLK_d :
                    transform->velocity.x = 0;
                    sprite->play("up");
                    break;
                default :
                    break;
            }
        }
    }

};



#endif


