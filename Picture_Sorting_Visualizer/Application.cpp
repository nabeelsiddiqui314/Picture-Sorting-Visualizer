#include "stdafx.h"
#include "Application.h"

#include "Shuffle.h"
#include "BubbleSort.h"

Application::Application() {
	m_window.create(sf::VideoMode(800, 600), "Picture Sorter");

	m_array = std::make_shared<PictureArray>();

	applyTextureToImage();

	const auto& pictureSize = m_array->getImageBuffer().getSize();
	const auto& windowSize = m_window.getSize();

	m_pictureQuad.setSize({ (float)pictureSize.x * 2, (float)pictureSize.y * 2});
	m_pictureQuad.setPosition(windowSize.x / 2 - m_pictureQuad.getSize().x / 2, windowSize.y / 2 - m_pictureQuad.getSize().y / 2);
}


void Application::run() {
	while (m_window.isOpen()) {
		handleEvents();

		m_window.clear();

		runAlgorithm(300000);

		applyTextureToImage();
		m_window.draw(m_pictureQuad);

		m_window.display();
	}
}

void Application::handleEvents() {
	sf::Event evnt;
	while (m_window.pollEvent(evnt)) {
		if (!m_algorithm) {
			if (evnt.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					m_algorithm = std::make_unique<Shuffle>(m_array);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
					m_algorithm = std::make_unique<BubbleSort>(m_array);
				}
			}
		}

		if (evnt.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}
void Application::applyTextureToImage() {
	m_pictureTexture.loadFromImage(m_array->getImageBuffer());
	m_pictureQuad.setTexture(&m_pictureTexture);
}

void Application::runAlgorithm(std::uint32_t times) {
	std::uint32_t counter = 0;

	while (counter < times) {
		if (m_algorithm) {
			m_algorithm->run();

			if (m_algorithm->hasCompleted()) {
				m_algorithm.reset();
				return;
			}
		}
		else {
			return;
		}

		counter++;
	}
}