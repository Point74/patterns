#include "MouseController.h"


MouseController::MouseController(ProxyImage* image) :
    proxyImage(image), isDragging(false), clickCount(0) {}

void MouseController::handleEvent(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (clickClock.getElapsedTime().asMilliseconds() < 300) {
                clickCount++;

            } else clickCount = 1;

            clickClock.restart();

            if (clickCount == 2) {
                if (proxyImage->isCursorInTheRealImage(mousePosition)) {
                    proxyImage->onLeftDoubleClick();
                }

                clickCount = 0;

            } else if (clickCount == 1) {
                if (proxyImage->isCursorInTheRealImage(mousePosition)) {
                    isDragging = true;
                    offset = mousePosition - proxyImage->getPosition();
                }

            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
        }
    }

    if (event.type == sf::Event::MouseMoved) {
        if (isDragging) {
            sf::Vector2f newMousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x,event.mouseMove.y));
            proxyImage->moveTo(newMousePosition.x - offset.x, newMousePosition.y - offset.y);
        }
    }
}