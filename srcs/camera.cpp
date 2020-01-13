/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:43:40 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/13 11:43:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.hpp"

Camera::Camera(int _width, int _height)
{
    xpos = 0;
    ypos = 0;
    width = _width;
    height = _height;
}

Camera::~Camera()
{}


void Camera::update(const Vector2D& position)
{
    xpos = static_cast<int>(position.x) - (width / 2);
    ypos = static_cast<int>(position.y) - (height / 2);
    xpos = xpos < 0 ? 0 : xpos > width ? width : xpos;
    ypos = ypos < 0 ? 0 : ypos > height ? height : ypos;
}