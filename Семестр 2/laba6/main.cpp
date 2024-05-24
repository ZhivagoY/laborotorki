#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>

int main()
{
    float DeltaTime;
    float moveSpeed = 500.f;
    sf::Vector2f movement(0.f, 0.f);
    sf::Clock* clock = new sf::Clock;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML figures");
    sf::Texture trackTexture;
    sf::Texture tankTexture;
    sf::Sprite track;
    sf::Sprite tank;

    if (!trackTexture.loadFromFile("C:/Users/SystemX/Documents/GitHub/laborotorki/Семестр 2/laba6/assets/track.jpg")) {
        std::cout << "Fail while loading file 'C:/Users/SystemX/Documents/GitHub/laborotorki/Семестр 2/laba6/assets/track.jpg'" << std::endl;
        return 0;
    }

    if (!tankTexture.loadFromFile("C:/Users/SystemX/Documents/GitHub/laborotorki/Семестр 2/laba6/assets/car.png")) {
        std::cout << "Fail while loading file 'C:/Users/SystemX/Documents/GitHub/laborotorki/Семестр 2/laba6/assets/car.png'" << std::endl;
        return 0;
    }

    track.setTexture(trackTexture);
    tank.setTexture(tankTexture);

    track.setPosition(0, 0);
    tank.setPosition(100, 100);

    while (window.isOpen())
    {
        DeltaTime = clock->restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            tank.move(0.0f, -moveSpeed * DeltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            tank.move(0.0f, moveSpeed * DeltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            tank.move(-moveSpeed * DeltaTime, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            tank.move(moveSpeed * DeltaTime, 0.0f);


        window.clear();
        window.draw(track);
        window.draw(tank);
        window.display();
    }
    return 0;
}