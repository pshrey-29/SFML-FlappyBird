#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Pipe.h"

class PipeManager
{
public:
	PipeManager(sf::Vector2f position, float gap);

	void SpawnPipes();

	void drawSpawnedPipes(sf::RenderWindow& window);
	void updatePipes(float deltaTime);

	void setSpawnPosition(sf::Vector2f newPosition);
	sf::Vector2f getSpawnPosition() { return spawnPosition; }

public:
	std::list<Pipe*> listOfPipe;

private:
	sf::Vector2f spawnPosition;
	float halfgap;
};

