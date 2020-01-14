/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:40:37 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/13 11:40:40 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vector2d.hpp"


class Camera
{

    public :
        int xpos;
        int ypos;
        int width;
        int height;
        int maxHeight;
        int maxWidth;
        Camera(int width, int height);
        ~Camera();
        void init(int h, int w, int gs);
        void update(const Vector2D& position);
};


#endif 
