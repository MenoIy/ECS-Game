/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:17:59 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/10 11:18:00 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SDL.h"
#include "components.hpp"


class Collision
{
    public :
        static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
        static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);

};




#endif