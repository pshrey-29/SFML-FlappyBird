#include <SFML/Graphics.hpp>
#include <list>
#include <cstdlib> //only for random number generation : rand()
#include "PipeManager.h"
#include "Player.h"

int main()
{
    float windowWidth = 1366.f;
    float windowHeight = 768.f;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Flappppyyyy!!!");
    window.setFramerateLimit(60);

    sf::Clock clock;
    float deltaTime;

    Player player;
    player.setPosition(sf::Vector2f(windowWidth/2, windowHeight/2));

    PipeManager PipeManager(sf::Vector2f(windowWidth, windowHeight / 2), 150.f);
    PipeManager.SpawnPipes();

    sf::Clock pipeSpawnClock;
    float pipeSpawnInterval = 4.0f;

    while (window.isOpen())
    {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto pipe : PipeManager.listOfPipe) {
            sf::FloatRect bounds = pipe->getBounds();
            bool collisionOccured = player.isCircleRectangleCollision(bounds);
            if (collisionOccured) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.setVelocity({0, 0});
            player.applyForce(0, -400);
        }

        if (pipeSpawnClock.getElapsedTime().asSeconds() >= pipeSpawnInterval)
        {
            float randomNumber = (rand() % ((int)windowHeight - 150)) / 2.f;
            randomNumber += 75.f;
            PipeManager.setSpawnPosition(PipeManager.getSpawnPosition() + sf::Vector2f(0, randomNumber - PipeManager.getSpawnPosition().y));
            PipeManager.SpawnPipes();
            pipeSpawnClock.restart(); 
        }

        player.update(deltaTime);
        PipeManager.updatePipes(deltaTime);

        window.clear(sf::Color(20, 20, 20));
        player.draw(window);
        PipeManager.drawSpawnedPipes(window);
        window.display();
    }

    return 0;
}