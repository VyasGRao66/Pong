#include "Ball.h"


Ball::Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_BallShape.setRadius(5);
	m_BallShape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition() {
	return m_BallShape.getGlobalBounds();
}

sf::CircleShape Ball::getShape() {

	return m_BallShape;
}

void Ball::bounceSides() {

	m_DirectionY = -m_DirectionY;
}


void Ball::increaseSpeed() {

	m_Speed += 5;
}

void Ball::hitBall() {

	m_DirectionX = -m_DirectionX;
}

void Ball::update(sf::Time dt) {

	m_Position.x += m_DirectionX * dt.asSeconds() * m_Speed;
	m_Position.y += m_DirectionY * dt.asSeconds() * m_Speed;

	m_BallShape.setPosition(m_Position);

}