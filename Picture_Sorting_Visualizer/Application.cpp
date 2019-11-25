#include "stdafx.h"
#include "Application.h"

Application::Application() {
	m_window.create(sf::VideoMode(800, 600), "Picture Sorter");

	applyTextureToImage();

	const auto& pictureSize = m_array.getPictureBuffer().getSize();
	const auto& windowSize = m_window.getSize();

	m_pictureQuad.setSize({ (float)pictureSize.x, (float)pictureSize.y });
	m_pictureQuad.setPosition(windowSize.x / 2 - pictureSize.x / 2, windowSize.y / 2 - pictureSize.y / 2);
}


void Application::run() {
	while (m_window.isOpen()) {
		handleEvents();

		m_window.clear();

		m_window.draw(m_pictureQuad);

		m_window.display();
	}
}

void Application::handleEvents() {
	sf::Event evnt;
	while (m_window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}
void Application::applyTextureToImage() {
	m_pictureTexture.loadFromImage(m_array.getPictureBuffer());
	m_pictureQuad.setTexture(&m_pictureTexture);
}