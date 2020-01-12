/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TransformComponent.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:19:57 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:46:53 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP
#include "ECL.hpp"
#include "vector2d.hpp"

class TransformComponent : public Component
{
	public	:
		Vector2D	position;
		Vector2D	velocity;
		int			height = 10;
		int			width = 10;
		int			scale = 1;
		float		speed = 3.0;

		TransformComponent()
		{
			position.x = 416.0;
			position.y = 320.0;
		}

		TransformComponent(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		TransformComponent(float x, float y, int h, int w, int s)
		{
			position.x = x;
			position.y = y;
			width = w;
			height = h;
			scale = s;
		}
		
		void init() override
		{
			velocity.x = 0.0;
			velocity.y = 0.0;
		}

		void update() override
		{
			position.x += velocity.x * speed;
			position.y += velocity.y * speed;
		}
};

#endif 
