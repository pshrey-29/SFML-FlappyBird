#include <SFML/Graphics.hpp>
#include <list>
#include <cstdlib> //only for random number generation : rand()
#include "PipeManager.h"
#include "Player.h"
//#include <iostream>

int main()
{
    float windowWidth = 1366.f;
    float windowHeight = 768.f;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Flappppyyyy!!!");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../../../Assets/Fonts/VinaSans-Regular.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text scoreText;
    scoreText.setString(" ");
    scoreText.setCharacterSize(400);
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color(60, 60, 60, 120));
    sf::Vector2f offset = sf::Vector2f(scoreText.getLocalBounds().width / 4, 0);

    sf::Clock clock;
    float deltaTime;
    sf::Clock pipeSpawnClock;
    float pipeSpawnInterval = 4.0f;

    float pipesHalfGap = 150.f;
    float upwardPlayerThrust = 400.f;
    unsigned int currentScore = 0;
    sf::Color darkbg = sf::Color(20, 20, 20);
    sf::Color bgColor = darkbg;

    Player player;
    player.setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 2));

    PipeManager PipeManager(sf::Vector2f(windowWidth, windowHeight / 2), pipesHalfGap);
    PipeManager.SpawnPipes();

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
                pipe->changeColor();
                //window.close();
            }

            if (pipe->checkForPoint(windowWidth / 2)) currentScore++;
        }
        if (player.getPosition().y > windowHeight || player.getPosition().y < 0) {
            bgColor = sf::Color::Red;
        }
        else {
            bgColor = darkbg;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.setVelocity({ 0, 0 });
            player.applyForce(0, -upwardPlayerThrust);
        }

        if (pipeSpawnClock.getElapsedTime().asSeconds() >= pipeSpawnInterval)
        {
            float randomNumber = (rand() % ((int)(windowHeight - (2 * pipesHalfGap)))) / 2.f;
            randomNumber += (pipesHalfGap);
            PipeManager.setSpawnPosition(PipeManager.getSpawnPosition() + sf::Vector2f(0, randomNumber - PipeManager.getSpawnPosition().y));
            PipeManager.SpawnPipes();
            pipeSpawnClock.restart();
        }

        scoreText.setString(std::to_string(currentScore / 2));
        sf::FloatRect textBounds = scoreText.getLocalBounds();
        sf::Vector2f textCenter(textBounds.width / 2, textBounds.height);
        scoreText.setOrigin(textCenter + offset);
        scoreText.setPosition({ windowWidth / 2, windowHeight / 2 });

        player.update(deltaTime);
        PipeManager.updatePipes(deltaTime);

        window.clear(bgColor);
        window.draw(scoreText);
        player.draw(window);
        PipeManager.drawSpawnedPipes(window);
        window.display();
    }
    return 0;
}