/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:06:24 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/11 18:06:25 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_HPP
# define ANIMATION_HPP


struct Animation
{
    int index;
    int frames;
    int speed;


    Animation() {}
    Animation(int i, int f, int s)
    {
        index = i;
        frames = f;
        speed = s;
    }

};


#endif
