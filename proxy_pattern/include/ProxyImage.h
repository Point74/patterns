#pragma once

#include "SFML/Graphics.hpp"
#include "RealImage.h"
#include "Image.h"

#include <string>


using namespace std;


class ProxyImage : public Image {
    RealImage* realImage;
    sf::RectangleShape box;
    string fileName;
    bool isImageLoad;

public:
    ProxyImage(float width, float height, string file);

    ~ProxyImage() override;

    void display(sf::RenderWindow& window) override;

    void moveTo(float x, float y);

    void onLeftDoubleClick();

    sf::Vector2f getPosition();

    bool isCursorInTheRealImage(sf::Vector2f point);
};