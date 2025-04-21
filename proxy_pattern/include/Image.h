#pragma once

#include "SFML/Graphics.hpp"

class Image {
public:
    virtual ~Image() = default;
    virtual void display(sf::RenderWindow& window) = 0;
    virtual bool isCursorInTheRealImage(sf::Vector2f point) = 0;
};