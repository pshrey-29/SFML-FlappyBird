#include "PipeManager.h"

PipeManager::PipeManager(sf::Vector2f position, float halfgap)
{
	this->spawnPosition = position;
	this->halfgap = halfgap;
}

void PipeManager::SpawnPipes()
{
	Pipe* upperPipe = new Pipe(spawnPosition.x, (spawnPosition.y));
	upperPipe->setOrigin(0.f, 1000.f);
	upperPipe->setPosition(spawnPosition + sf::Vector2f(0.f, -halfgap));

	Pipe* lowerPipe = new Pipe(spawnPosition.x, (spawnPosition.y));
	lowerPipe->setPosition(spawnPosition + sf::Vector2f(0.f, halfgap));

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
	while (listOfPipe.front()->getPosition().x < -100) {
		delete (listOfPipe.front());
		listOfPipe.pop_front();
	}
}

void PipeManager::setSpawnPosition(sf::Vector2f newPosition)
{
	this->spawnPosition = newPosition;
}
