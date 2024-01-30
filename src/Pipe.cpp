#include "Pipe.h"

Pipe::Pipe(float x, float y) :
	body(sf::Vector2f(100.f, 1000.f))
{
	body.setPosition(x, y);
	body.setFillColor(sf::Color(60, 60, 60, 120));
	//body.setOutlineThickness(10.f);
	//body.setOutlineColor(sf::Color(69, 69, 69));

	velocity = {-150.f, 0};
}

void Pipe::update(float deltaTime)
{
	this->setPosition(this->body.getPosition() + (velocity * deltaTime));
}

void Pipe::setPosition(sf::Vector2f newPosition)
{
	body.setPosition(newPosition);
}

void Pipe::setOrigin(float x, float y)
{
	body.setOrigin(x, y);
}