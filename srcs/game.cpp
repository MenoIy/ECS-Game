/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:32:48 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 19:00:44 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"
#include "texture.hpp"
#include "map.hpp"
#include "ECL.hpp"
#include "components.hpp"
#include "collision.hpp"

SDL_Texture *player_texture;
SDL_Rect srcRect, destRect;
SDL_Renderer* Game::renderer = nullptr; 
SDL_Event	Game::event;
std::vector<ColliderComponent *> Game::colliders;
Map map_ = Map();
Manager manager;
auto& player(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}



void Game::addTile(float x, float y, int h, int w, int id, const char* path, const char *tag, int group, int coll)
{
	auto& tile(manager.addEntity(true));
	tile.addComponent<TileComponent>(x, y, h, w, id, path);
	if (coll){
		tile.addComponent<ColliderComponent>(tag);
	}
	tile.addGroup(group);
}


int	Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	_isRunning = false;

	if (SDL_Init(SDL_INIT_EVERYTHING)  < 0){
		cerr << "SDL_Init failed:" << SDL_GetError() << "\n";
		return (1);
	}
	_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullScreen ? SDL_WINDOW_FULLSCREEN : 0);
	if (_window == NULL){
		cerr << "SDL_CreateWindow failed" << SDL_GetError() << "\n";
		this->clean();
		return (1);
	}
	renderer = SDL_CreateRenderer(_window, -1, 0);
	if (renderer == NULL){
		cerr << "SDL_CreateRenderer failed" << SDL_GetError() << "\n";
		this->clean();
		return (1);
	}
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	_isRunning = true;

	player.addComponent<TransformComponent>(20, 100, 32, 32, 1);
	player.addComponent<SpriteComponent>("resources/textures/player/player.png", true);
	player.addComponent<KeyBoardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	if (map_.loadMap("text.x"))
		return (1);
	return (0);
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			_isRunning = false;
			break;
		default :
			break;
	}
}

auto &tiles = manager.getGroup(groupMap);
auto &players = manager.getGroup(groupPlayers);
auto &coll = manager.getGroup(groupColliders);

void Game::update()
{
	Vector2D playerPos = player.getComponent<TransformComponent>().position;
	manager.refresh();
	manager.update();
	for (auto cc : colliders){
		if (Collision::AABB(player.getComponent<ColliderComponent>(), *cc))
		{
			if (cc->tag.compare("player") != 0){
				player.getComponent<TransformComponent>().position = playerPos;
			}
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto& e : tiles){
		e->draw();
	}
	for (auto& e : coll){
		e->draw();
	}	
	for (auto& e : players){
		e->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	if (_window)
		SDL_DestroyWindow(_window);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned !\n";
}
