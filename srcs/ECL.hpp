/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ECL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:50:28 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/08 18:50:56 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECL_HPP
#define ECL_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#define MAXCOMPONENTS 3200
#define MAXGROUPS 32


using ComponentID = std::size_t;
using Group = std::size_t;

class	Component;
class	Entity;
class 	Manager;

inline ComponentID getNewComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getNewComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = MAXCOMPONENTS;
constexpr std::size_t maxGroups = MAXGROUPS;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component 
{
	public	:
		Entity	*entity;
		virtual	void init() {}
		virtual	void update() {}
		virtual	void draw() {}
	
		virtual	~Component() {}
};

class Entity
{
	private	:
		bool	_active = true;
		Manager& _manager;
		std::vector<std::unique_ptr<Component>> _components;
		ComponentArray	_componentArray;
		ComponentBitSet	_componentBitSet;
		GroupBitSet _groupBitSet;
		bool	_oneLife = false;

	public	:
		Entity(Manager& mManager) : _manager(mManager) {}

		void	update()
		{
			for (auto& c : _components) c->update();
		}
		void	draw()
		{
			for (auto& c : _components) c->draw();
		}

		bool hasGroup(Group mGroup)
		{
			return _groupBitSet[mGroup];
		}

		void addGroup(Group mGroup);

		void delGroup(Group mGroup)
		{
			_groupBitSet[mGroup] = false;
		}

		bool	isActive() const { return  _active ;}
		void	destroy() { _active = false ;}
		template <typename T> bool hasComponent() const
		{
			return _componentBitSet[getComponentTypeID<T>()];
		}

		template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs)
		{
			T*	c(new T(std::forward<TArgs>(mArgs)...));
			c->entity = this;
			std::unique_ptr<Component> uPtr{ c };
			_components.emplace_back(std::move(uPtr));
			_componentArray[getComponentTypeID<T>()] = c;
			_componentBitSet[getComponentTypeID<T>()] = true;

			c->init();
			return *c;
		}
		template <typename T> T& getComponent() const
		{
			auto ptr(_componentArray[getComponentTypeID<T>()]);
			return *static_cast<T *>(ptr);
		}
};

class Manager
{
	private	:
		std::vector<std::unique_ptr<Entity>> _entities;
		std::array<std::vector<Entity *> , maxGroups > _groupedEntities;

	public	:
		void	update()
		{
			for (auto& e : _entities) e->update();
		}

		void	draw()
		{
			for (auto& e : _entities) e->draw();
		}
		
		void refresh()
		{
			for (auto i(0u); i <  maxGroups; i++){
				auto& v(_groupedEntities[i]);
				v.erase(std::remove_if(std::begin(v), std::end(v),
						[i](Entity* mEntity)
						{
							return !mEntity->isActive() || !mEntity->hasGroup(i);
						}), std::end(v));
			}

			_entities.erase(std::remove_if(std::begin(_entities), std::end(_entities), 
						[](const std::unique_ptr<Entity> &mEntity)
						{
							return !mEntity->isActive();
						}), std::end(_entities));
		}
		void	addToGroup(Entity* mEntity, Group mGroup)
		{
			_groupedEntities[mGroup].emplace_back(mEntity);
		}

		std::vector<Entity *>& getGroup(Group mGroup)
		{
			return(_groupedEntities[mGroup]);
		}

		Entity& addEntity()
		{
			Entity* e = new Entity(*this);
			std::unique_ptr<Entity> uPtr{ e };
			_entities.emplace_back(std::move(uPtr));
			return *e;
		}
};


#endif
