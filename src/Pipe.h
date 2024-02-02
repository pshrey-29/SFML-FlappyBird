#pragma once
#include <SFML/Graphics.hpp>

class Pipe
{
public:
	Pipe(float x, float y);

	void update(float deltaTime);
	void draw(sf::RenderWindow& window) { window.draw(body); }

	bool checkForPoint(float playerPositionX);
	sf::Vector2f getPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f newPosition);
	void setOrigin(float x, float y);
	sf::FloatRect getBounds() { return body.getGlobalBounds(); }

	void changeColor() { body.setFillColor(sf::Color::Green); }

private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
	bool isPointCollected;
};

