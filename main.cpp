#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>

int main() {

	using namespace sf;

	RenderWindow window(sf::VideoMode(800, 600), "Siurek");

	// Player shape
	CircleShape PlayerShape(50.0f);
	PlayerShape.setFillColor(Color::Cyan);
	PlayerShape.setPosition(400.0f, 300.0f); // starting position

	// Enemy shape
	CircleShape EnemyShape(30.0f);
	EnemyShape.setFillColor(Color::Green);
	EnemyShape.setPosition(100.0f, 100.0f);

	// Variables
	float SPEED = 5.0f; // shape moving speed
	int score = 0;

	std:srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random position

	while (window.isOpen()) {

		Event event;

		float RandomX = static_cast<float>(std::rand()); // Random X speed
		float RandomY = static_cast<float>(std::rand()); // Random Y speed
		EnemyShape.move(RandomSpeedX.f, RandomSpeedY.f);

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {

					window.close();
			}
		}

		Vector2f movement(0.0f, 0.0f);
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			movement.x -= SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			movement.x += SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			movement.y -= SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			movement.y += SPEED;
		}
		PlayerShape.move(movement);



			// Check collisions and change color when overlap
		if (PlayerShape.getGlobalBounds().intersects(EnemyShape.getGlobalBounds())) {
			EnemyShape.setFillColor(Color::Magenta);
			score++;

			// Random position for enemy
			float RandomX = static_cast<float>(std::rand() % 700 + 50); // Random X position
			float RandomY = static_cast<float>(std::rand() % 500 + 50); // Random Y position
			EnemyShape.setPosition(RandomX, RandomY);
		}
		else {
			EnemyShape.setFillColor(Color::Green);
		}
			
		window.clear();
		window.draw(PlayerShape);
		window.draw(EnemyShape);

		Font font;
		font.loadFromFile("arial.ttf");

		Text scoreText("score: " + std::to_string(score), font, 30);
		scoreText.setPosition(20, 20);
		window.draw(scoreText);

		window.display();
		}

	return 0;
}