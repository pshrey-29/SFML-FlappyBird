#include "PipeManager.h"

PipeManager::PipeManager(sf::Vector2f position, float gap)
{
	this->spawnPosition = position;
	this->gap = gap;
}

void PipeManager::SpawnPipes()
{
	Pipe* upperPipe = new Pipe(spawnPosition.x, (spawnPosition.y));
	upperPipe->setOrigin(0.f, 1000.f);
	upperPipe->setPosition(spawnPosition + sf::Vector2f(0.f, -gap));
	Pipe* lowerPipe = new Pipe(spawnPosition.x, (spawnPosition.y));
	lowerPipe->setPosition(spawnPosition + sf::Vector2f(0.f, gap));
	listOfPipe.push_back(upperPipe);
	listOfPipe.push_back(lowerPipe);
}

void PipeManager::drawSpawnedPipes(sf::RenderWindow& window)
{
	for (auto pipe : listOfPipe) {
		pipe->draw(window);
	}
}

void PipeManager::updatePipes(float deltaTime)
{
	for (auto pipe : listOfPipe) {
		pipe->update(deltaTime);
	}
	for (auto pipe : listOfPipe) {
		if (pipe->getPosition().x < -100) {
			listOfPipe.pop_front();
		}
		else {
			break;
		}
	}
}

void PipeManager::setSpawnPosition(sf::Vector2f newPosition)
{
	this->spawnPosition = newPosition;
}
