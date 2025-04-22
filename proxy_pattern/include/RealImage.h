#pragma once

#include "SFML/Graphics.hpp"
#include "Image.h"

#include <string>


using namespace std;


class RealImage : public Image {
    sf::Texture texture; // загрузить картинку
    sf::Sprite sprite; // отобразить картинку
    string fileName;

    string getFullPathToFile(const string& relativePath);

public:
    RealImage(string file);

    ~RealImage() override = default;

    void load();

    void display(sf::RenderWindow& window) override;

    void setPosition(float x, float y);

    sf::Vector2f getPosition();

    bool isCursorInTheRealImage(sf::Vector2f point) override;
};