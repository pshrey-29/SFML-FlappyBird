#include "Pipe.h"

Pipe::Pipe(float x, float y) :
	body(sf::Vector2f(100.f, 1000.f))
{
	body.setPosition(x, y);
	body.setFillColor(sf::Color(60, 60, 60));
	//body.setOutlineThickness(10.f);
	//body.setOutlineColor(sf::Color(69, 69, 69));

	velocity = { -150.f, 0 };
	isPointCollected = false;
}

void Pipe::update(float deltaTime)
{
	this->setPosition(this->body.getPosition() + (velocity * deltaTime));
}

bool Pipe::checkForPoint(float playerPositionX)
{
	if (isPointCollected) return false;
	if (this->getPosition().x <= playerPositionX) {
		isPointCollected = true;
		return true;
	}
	return false;
}

void Pipe::setPosition(sf::Vector2f newPosition)
{
	body.setPosition(newPosition);
}

void Pipe::setOrigin(float x, float y)
{
	body.setOrigin(x, y);
}