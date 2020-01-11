/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:20:36 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/10 11:20:37 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.hpp"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
    if (rectA.x + rectA.w >= rectB.x &&
        rectB.x + rectB.w >= rectA.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y){ return  true; }
    
    return false;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
    if (AABB(colA.collider, colB.collider)){
        return true;
    }
    return false;
}
