#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void applyForce(float x, float y);
	bool isCircleRectangleCollision(sf::FloatRect& rectBounds);

	void update(float deltaTime);
	void draw(sf::RenderWindow& window) { window.draw(body); }

	sf::Vector2f getPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f newPosition) { body.setPosition(newPosition); }
	void setVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }

private:
	sf::CircleShape body;
	sf::Vector2f velocity;
	float gravity;
};

