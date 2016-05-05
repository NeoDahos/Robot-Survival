#include <SFML\Window\Event.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include <Engine\EngineCore.h>
#include <Engine\Object\Transform.h>

#include "Global.h"

#include "Player\Player.h"
#include "SpaceShip\SpaceShip.h"
#include "Scrap\Scrap.h"

int main()
{
	sf::RenderWindow window;
	sf::RenderStates renderStates;
	sf::View view;
	sf::Event event;
	sf::Clock timer;
	float deltaTime;

	window.create(sf::VideoMode(global::windowWidth, global::windowHeight), "Robot Survival");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	view = window.getView();

	engine::TextureMng.AddTexture("Player", "../Data/Sprites/Player.png");
	engine::TextureMng.AddTexture("SpaceShip", "../Data/Sprites/SpaceShip.png");
	engine::TextureMng.AddTexture("Scrap_Little", "../Data/Sprites/Scrap_Little.png");
	engine::TextureMng.AddTexture("LiftLaser", "../Data/Sprites/LiftLaser.png");

	Player player;
	SpaceShip ship;
	std::list<Scrap> scraps;
	scraps.emplace_back("Scrap_Little", 1);
	scraps.front().Move(sf::Vector2f(100.f, 0.f));

	while (window.isOpen())
	{
		deltaTime = timer.restart().asSeconds();
		window.setTitle("Robot Survival - FPS : " + std::to_string(1.f / deltaTime));
		global::mousePosInWindow = sf::Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				else if (event.key.code == sf::Keyboard::E)
					player.Lift(scraps);
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					player.StartWalkning();
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					player.StopWalkning();
				}
			}
		}

		player.Update(deltaTime);
		ship.Update(deltaTime);

		engine::ColliderMng.ComputeCollisions();

		view.setCenter(player.GetPosition());
		window.setView(view);
		window.clear(sf::Color::White);

		// Update scraps
		for (auto&& scrap : scraps)
			scrap.Draw(window);
		// End update scraps

		ship.Draw(window);

		player.Draw(window);

		window.display();
	}

	engine::TextureMng.ClearAllTextures();

	return 0;
}