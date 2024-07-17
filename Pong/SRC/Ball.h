#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
private:
	sf::Vector2f m_Position;
	sf::CircleShape m_BallShape;

	float m_Speed = 400;
	float m_DirectionX = 1.0f;
	float m_DirectionY = 1.0f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::CircleShape getShape();

	void bounceSides();

	void hitBall();

	void increaseSpeed();

	void update(sf::Time dt);
	

};

