#include "Player.h"
#include <iostream>

Player::Player(int size, int type):
    Bot(getStage()->getSize() / 2, size, type)
{
}

Player::~Player()
{}

