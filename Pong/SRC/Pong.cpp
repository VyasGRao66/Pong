#include <SFML/Graphics.hpp>
#include "PlayerPaddle.h"
#include "Ball.h"
#include "BotPaddle.h"
#include <iostream>

int main()
{
    int guiX = 800;
    int guiY = 400;
    sf::VideoMode VM(guiX, guiY);
    sf::RenderWindow window(VM, "Pong");

    PlayerPaddle myPlayerPaddle(780, guiY/2);
    Ball myBall(guiX/2, guiY/2);
    BotPaddle myBotPaddle(20, guiY / 2);

    sf::Clock clock;

    sf::Time dt;

    sf::Font font;
    font.loadFromFile("SRC/Fonts/Bangers-Regular.ttf");
    sf::Text endText;
    endText.setFont(font);
    endText.setPosition(guiX / 2, guiY / 2);
    endText.setCharacterSize(50);
    endText.setFillColor(sf::Color::Green);

    bool playerWon = false;
    bool botWon = false;


    float bounceTimer = 0.05f;

    while (window.isOpen()) {
        sf::Event event;
        dt = clock.restart();
        bounceTimer -= dt.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (myBall.getPosition().getPosition().x < 0) {

            playerWon = true;
        }

        if (myBall.getPosition().getPosition().x > guiX) {

            botWon = true;
        }


        if (myBall.getPosition().intersects(myPlayerPaddle.getPosition())) {
            if (bounceTimer < 0) {

                myBall.hitBall();
                myBall.increaseSpeed();
                bounceTimer = 0.05f;

            }
        }

        if (myBall.getPosition().intersects(myBotPaddle.getPosition())) {
            if (bounceTimer < 0) {


                myBall.hitBall();
                myBall.increaseSpeed();
                bounceTimer = 0.05f;
            }
        }

        if (myBall.getPosition().top + myBall.getPosition().height >= guiY) {
            if (bounceTimer < 0) {

                myBall.bounceSides();
                bounceTimer = 0.05f;
            }
        }

        if (myBall.getPosition().top <= 0 && myBotPaddle.getPosition().getPosition().y != 0) {

            if (bounceTimer < 0) {

                myBall.bounceSides();
                bounceTimer = 0.05f;
            }
        }

        if (myBall.getPosition().getPosition().y < myBotPaddle.getPosition().getPosition().y && myBotPaddle.getPosition().top > 0) {

            myBotPaddle.ballUp();
        }
        else
        {
            myBotPaddle.ballStopUp();
        }


        if (myBall.getPosition().getPosition().y > myBotPaddle.getPosition().getPosition().y && myBotPaddle.getPosition().top + myBotPaddle.getPosition().height < guiY) {

            myBotPaddle.ballDown();
        }
        else {

            myBotPaddle.ballStopDown();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && myPlayerPaddle.getPosition().top > 0) {

            myPlayerPaddle.moveUp();
        }
        else {

            myPlayerPaddle.stopUp();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && myPlayerPaddle.getPosition().top + myPlayerPaddle.getPosition().height < guiY) {

            myPlayerPaddle.moveDown();
        }
        else {

            myPlayerPaddle.stopDown();
        }

              
        
        
        window.clear();

        if (playerWon == false && botWon == false) {
            myPlayerPaddle.update(dt);
            myBall.update(dt);
            myBotPaddle.update(dt);
        }
        else {
            if (playerWon) {

                endText.setString("You Won");
            }
            else {

                endText.setString("You Lost");
            }
            window.draw(endText);
        }
        
        window.draw(myPlayerPaddle.getShape());
        window.draw(myBall.getShape());
        window.draw(myBotPaddle.getShape());
        
        window.display();

           
    }
}
