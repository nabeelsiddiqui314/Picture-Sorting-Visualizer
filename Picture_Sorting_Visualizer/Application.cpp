#include "stdafx.h"
#include "Application.h"

Application::Application() {
	m_testShape.setPosition(200, 200);
	m_testShape.setSize(sf::Vector2f(200, 200));
}

void Application::onEvent(const sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		m_testShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
}

void Application::render(sf::RenderTarget& renderer) {
	renderer.draw(m_testShape);
}