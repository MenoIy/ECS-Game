/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2D.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:54:36 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 21:54:38 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
#include <cmath>

class Vector2D
{
    public  :
        float x;
        float y;
        Vector2D();
        Vector2D(float x, float y);        
        Vector2D& add(const Vector2D& v1);
        Vector2D& sub(const Vector2D& v1);
        Vector2D& mult(const Vector2D& v1);
        Vector2D& divide(const Vector2D& v1);

        friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
        friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

        Vector2D& operator+=(const Vector2D& v1);
        Vector2D& operator-=(const Vector2D& v1);
        Vector2D& operator*=(const Vector2D& v1);
        Vector2D& operator/=(const Vector2D& v1);

        friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);

        float dist();
        Vector2D&   normalize();
        Vector2D& operator*(const float& s);
        Vector2D& zero();

};





#endif

