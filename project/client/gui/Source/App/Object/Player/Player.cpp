/*
** EPITECH PROJECT, 2022
** project
** File description:
** Player
*/

#include "Player.hpp"
#include "raymath.h"

Object::Player::Player(std::pair<std::string, std::string> const &pathToRessources, std::string const pathToAnimation, unsigned int nbAnimation, Position const &position, Object::MAP_OBJECTS type) :
    AThreeDimensionObject(pathToRessources, pathToAnimation, nbAnimation, position, type)
{
    _scale = 7.0f;
    _speed = 0.6f;
    _level = 1;
}

Object::Player::Player(Object::Render::MyModel &pathToModel, Object::Render::MyTexture &pathToRessources, Object::Render::MyAnimation &pathToAnimation, unsigned int numberOfAnimations, Position const &position, Object::MAP_OBJECTS type, int playerId) :
    AThreeDimensionObject(pathToModel, pathToRessources, pathToAnimation, numberOfAnimations, position, type)
{
    _scale = 7.0f;
    _speed = 0.6f;
    _playerId = playerId;
    _level = 1;
}

Object::Player::~Player()
{
}

void Object::Player::animation(std::size_t animNb)
{
    _animFrameCounter++;
    UpdateModelAnimation(_model, _anims[animNb], _animFrameCounter);
    if (_animFrameCounter >= _anims[animNb].frameCount)
        _animFrameCounter = 0;
}

void Object::Player::move(Position const &position, Position const &direction)
{
    animation(0);

    _model.transform = MatrixRotateXYZ((Vector3){ DEG2RAD * direction.getX(), DEG2RAD * direction.getY(), DEG2RAD * direction.getZ()});
    Position tmp = position;
    _position += (tmp * _speed);
}

void Object::Player::draw()
{
    Vector3 modelPosition = {
        getPosition().getX(),
        getPosition().getY(),
        getPosition().getZ()
    };
    if (_isEnable)
        DrawModel(_model, modelPosition, _scale, WHITE);
}

void Object::Player::setSpeed(bool addSpeed)
{
    if (addSpeed) {
        if (_speed < _defaultSpeed.second)
            _speed += 0.1f;
    }
    else {
        if (_speed > _defaultSpeed.first)
            _speed -= 0.1f;
    }
}

void Object::Player::setLevel(int level)
{
    _level = level;
}

void Object::Player::setInventory(std::vector<PLAYER_RESSOURCES, int> const &inventory)
{
    _inventory = inventory;
}
