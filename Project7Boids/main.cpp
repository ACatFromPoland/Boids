#include <SFML/Graphics.hpp>
#include "Vectors.h"
#include "buttonInput.h"
#include "Boid.h"
#include "Defineslol.h"

void RenderScreen(sf::RenderWindow &window, Camera &camera, BoidVector &boids) {
	for (int i = 0; i < boids.size(); i++) {
		boids[i].draw(window, camera);
	}
}

void UpdateScreen(float deltatime, BoidVector &boids) {
	for (int i = 0; i < boids.size(); i++) {
		Boid &bobj = boids[i];
		bobj.update(deltatime, boids);
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Boids", sf::Style::Close);
	sf::Clock clock;

	Camera camera;
	BoidVector boids(NUMBER_OF_BOIDS);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		clock.restart();
		window.clear(sf::Color::Black);
		double deltatime = clock.getElapsedTime().asSeconds();
		//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			camera.position = camera.position + Vector2(C_SPEED, 0.f) * deltatime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			camera.position = camera.position + Vector2(C_SPEED * -1, 0.f) * deltatime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			camera.position = camera.position + Vector2(0.f, C_SPEED) * deltatime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			camera.position = camera.position + Vector2(0.f, C_SPEED * -1) * deltatime;

		UpdateScreen(deltatime, boids);
		//
		RenderScreen(window, camera, boids);
		//
		window.display();

	}
	return 0;
}