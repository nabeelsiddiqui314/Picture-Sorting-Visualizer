#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(std::uint32_t width, std::uint32_t height, const std::string& title) {
	m_window.create(sf::VideoMode(width, height), title);
}

void MainWindow::display() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}

		m_window.clear();
		m_window.display();
	}
}
