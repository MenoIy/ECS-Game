/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:54:41 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 21:54:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.hpp"

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::add(const Vector2D &v1)
{
    this->x += v1.x;
    this->y += v1.y;
    return *this;
}

Vector2D& Vector2D::sub(const Vector2D &v1)
{
    this->x -= v1.x;
    this->y -= v1.y;
    return *this;

}

Vector2D& Vector2D::mult(const Vector2D &v1)
{
    this->x *= v1.x;
    this->y *= v1.y;
    return *this;
}

Vector2D& operator+(Vector2D &v1, const Vector2D &v2)
{
    return v1.add(v2);
}

Vector2D& operator-(Vector2D &v1, const Vector2D &v2)
{
    return v1.sub(v2);
}

Vector2D& operator*(Vector2D &v1, const Vector2D &v2)
{
    return v1.mult(v2);
}




Vector2D& Vector2D::operator+=(const Vector2D &v1)
{
    return this->add(v1);
}

Vector2D& Vector2D::operator-=(const Vector2D &v1)
{
    return this->sub(v1);
} 

Vector2D& Vector2D::operator*=(const Vector2D &v1)
{
    return this->mult(v1);
}


std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
    stream << "(" << vec.x << " , " << vec.y << ") \n";  
    return stream;
}

float Vector2D::dist()
{
    return (sqrt(this->x * this->x + this->y * this->y)); 
}

Vector2D&   Vector2D::normalize()
{
    float dist = this->dist();

    if (dist != 0.0){
        this->x = this->x / dist;
        this->y = this->y / dist;
    }
    return (*this);
}

Vector2D& Vector2D::operator*(const float& s)
{
    this->x *= s;
    this->y *= s;
    return *this;
}

Vector2D& Vector2D::zero()
{
    this->x = 0.0;
    this->y = 0.0;
    return *this;
}
