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
#include "components.hpp"
#include "collision.hpp"

SDL_Renderer* Game::renderer = nullptr; 
SDL_Event	Game::event;
Manager manager;
std::vector<ColliderComponent *> Game::colliders;
std::vector<pair<int, SDL_Texture* >> Game::GlobalTexture;
Camera Game::camera(WIDTH, HEIGHT);
auto& player(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}


auto &tiles = manager.getGroup(groupMap);
auto &players = manager.getGroup(groupPlayers);
auto &build = manager.getGroup(groupBuilding);
auto &water = manager.getGroup(groupWater);

void Game::addTile(int srcX, int srcY, int x, int y, int group, int id, const char *path)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, x, y, path, id);
	tile.addGroup(group);
	if (group == groupColliders)
		tile.addComponent<ColliderComponent>("tag");
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

	player.addComponent<TransformComponent>(416, 360, 32, 32, 1);
	player.addComponent<SpriteComponent>("resources/textures/player/player.png", true);
	player.addComponent<KeyBoardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	if (Map::loadMap("resources/levels/lvl_00/lvl_00.map"))
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

void Game::update()
{
	Vector2D playerPos = player.getComponent<TransformComponent>().position;
	manager.refresh();
	camera.update(playerPos);
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
	for (auto& e : water){
		e->draw();
	}
	for (auto& e : build){
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
