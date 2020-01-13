/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpriteComponent.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:20:33 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 19:01:24 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "SDL.h"
#include "components.hpp"
#include "texture.hpp"
#include "Animation.hpp"
#include <map>

class SpriteComponent : public Component
{
	private :
		TransformComponent *_transform;
		SDL_Rect	_srcRect, _destRect;
		SDL_Texture	*_texture;
		bool		_animated = false;
		int _frames = 0;
		int _speed = 100;

	public :
		int	animateIndex = 0;
		std::map<const char*, Animation> animations;

		SpriteComponent() = default;
		SpriteComponent(const char *path)
		{
			setTexture(path);
		}

		SpriteComponent(const char *path, bool isAnimated)
		{
			_animated = isAnimated;
			Animation left = Animation(1, 3, 100);
			Animation right = Animation(2, 3, 100);
			Animation up = Animation(0, 3, 100);
			Animation down = Animation(3, 3, 100);
			animations.emplace("up", up);
			animations.emplace("left", left);
			animations.emplace("down", down);
			animations.emplace("right", right);
			play("up");
			setTexture(path);
		}

		~SpriteComponent()
		{
			SDL_DestroyTexture(_texture);
		}

		void	setTexture(const char *path)
		{
			_texture = Texture::LoadTexture(path);
		}

		void	init() override
		{
			_transform = &entity->getComponent<TransformComponent>();
			_srcRect.x = _srcRect.y = 0;
			_srcRect.w = _transform->width;
			_srcRect.h = _transform->height;
		}

		void	update() override
		{
			if (_animated){
				_srcRect.x = _srcRect.w * static_cast<int>((SDL_GetTicks() / _speed) % _frames);
			}
			_srcRect.y = animateIndex * _transform->height;

			_destRect.x = (int)_transform->position.x - Game::camera.xpos;
			_destRect.y = (int)_transform->position.y - Game::camera.ypos;
			_destRect.w = _transform->width * _transform->scale;
			_destRect.h = _transform->height * _transform->scale;	
		}

		void	draw() override
		{
			Texture::draw(_texture, _srcRect, _destRect);
		}

		void play(const char *animeName)
		{
			_frames = animations[animeName].frames ;
			_speed = animations[animeName].speed ;
			animateIndex = animations[animeName].index;
		}
};





#endif
