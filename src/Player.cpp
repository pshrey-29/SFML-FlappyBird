#include "Player.h"

Player::Player() :
	body(25.f)
{
	body.setOrigin(25.f, 25.f);
	body.setFillColor(sf::Color(191, 161, 129));
	//body.setOutlineThickness(5.f);
	//body.setOutlineColor(sf::Color(119, 141, 169));

	velocity = sf::Vector2f(0, 0);
	gravity = 30.f;
}

void Player::applyForce(float x, float y)
{
	this->velocity += sf::Vector2f(x, y);
}

bool Player::isCircleRectangleCollision(sf::FloatRect& rectBounds)
{
	sf::Vector2f circleCenter = this->body.getPosition();
	float circleRadius = this->body.getRadius();

	sf::Vector2f rectClosestPoint;

	if (rectBounds.left - circleRadius > circleCenter.x) return false;
	if (rectBounds.top - circleRadius > circleCenter.y) return false;
	if (rectBounds.top + rectBounds.height + circleRadius < circleCenter.y) return false;
	if (rectBounds.left + rectBounds.width + circleRadius < circleCenter.x) return false;

	return true;
}

void Player::update(float deltaTime)
{
	body.setPosition(body.getPosition() + (velocity * deltaTime));
	velocity.y += gravity;
}
