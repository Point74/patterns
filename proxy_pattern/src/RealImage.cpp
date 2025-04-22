#include "RealImage.h"

#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;


RealImage::RealImage(string file) : fileName(std::move(file)) {}

void RealImage::load() {
    string fullPath = getFullPathToFile(fileName);

    if (!texture.loadFromFile(fullPath))
        cerr << "Failed to load image: " << fullPath << endl;

    else sprite.setTexture(texture);
}

string RealImage::getFullPathToFile(const string& relativePath) {
    fs::path exePath = fs::current_path();
    fs::path fullPath = exePath / "../" / relativePath;

    return fullPath.lexically_normal().string();
}

void RealImage::display(sf::RenderWindow& window) {
    window.draw(sprite);
}

void RealImage::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Vector2f RealImage::getPosition() {
    return sprite.getPosition();
}

bool RealImage::isCursorInTheRealImage(sf::Vector2f point) {
    return sprite.getGlobalBounds().contains(point);
}
