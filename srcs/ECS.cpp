#include "ECL.hpp"

void Entity::addGroup(Group mGroup)
{
    _groupBitSet[mGroup] = true;
    _manager.addToGroup(this, mGroup);
}