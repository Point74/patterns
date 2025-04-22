#include "ProxyImage.h"


ProxyImage::ProxyImage(float width, float height, string file) :
        realImage(nullptr), fileName(std::move(file)), isImageLoad(false) {

    box.setSize(sf::Vector2f(width, height));
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(3);
    box.setOutlineColor(sf::Color::Cyan);
    box.setPosition(width - box.getSize().x / 2.0f, height - box.getSize().y / 2.0f);
}

void ProxyImage::display(sf::RenderWindow& window) {
    if (isImageLoad) {
        realImage->display(window);

    } else window.draw(box);
}

void ProxyImage::moveTo(float x, float y) {
    if (isImageLoad) {
        realImage->setPosition(x, y);

    } else box.setPosition(x, y);
}

void ProxyImage::onLeftDoubleClick() {
    if (!isImageLoad) {
        realImage = new RealImage(fileName);
        realImage->load();
        sf::Vector2f position = box.getPosition();
        realImage->setPosition(position.x, position.y);

        isImageLoad = true;
    }
}

sf::Vector2f ProxyImage::getPosition() {
    if (isImageLoad) {
        return realImage->getPosition();

    } else return box.getPosition();
}



ProxyImage::~ProxyImage() {
    delete realImage;
}

bool ProxyImage::isCursorInTheRealImage(sf::Vector2f point) {
    if (isImageLoad) {
        return realImage->isCursorInTheRealImage(point);

    } else {
        return box.getGlobalBounds().contains(point);
    }
}
