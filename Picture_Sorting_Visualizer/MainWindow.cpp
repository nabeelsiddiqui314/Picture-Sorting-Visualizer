#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(std::uint32_t width, std::uint32_t height, const std::string& title, Application* app) 
 : p_app(app) {
	m_window.create(sf::VideoMode(width, height), title);
}

void MainWindow::run() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			p_app->onEvent(evnt);
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}

		m_window.clear();
		p_app->render(m_window);
		m_window.display();
	}
}
