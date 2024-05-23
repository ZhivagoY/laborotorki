#include <SFML/Graphics.hpp>

int main()
{
    const int N = 5;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML FIGURES!");
    sf::CircleShape circles[N];
    sf::RectangleShape rectangles[N];
    sf::RectangleShape lines[N];
    sf::CircleShape triangles[N];
    sf::CircleShape triangle(50, 3); //создание одного треугольника


    for (int i = 0; i < N; i++) { // создание кругов
        circles[i].setRadius(50.f);
        circles[i].setFillColor(sf::Color::Magenta);
        circles[i].setPosition(200.f * i, 100.f);
    }
    for (int i = 0; i < N; i++) { // создание прямоугольников
        rectangles[i].setSize(sf::Vector2f(100.f, 50.f));
        rectangles[i].setFillColor(sf::Color::Red);
        rectangles[i].setPosition(150.f * i, 300.f);
    }

    for (int i = 0; i < N; i++) { // создание треугольников
        triangles[i] = triangle;
        triangles[i].setFillColor(sf::Color::Green);
        triangles[i].setPosition(150.f * i, 500);
    }
    for (int i = 0; i < N; i++) { // создание линий
        lines[i].setSize(sf::Vector2f(180.f, 5.f));
        lines[i].setFillColor(sf::Color::Yellow);
        lines[i].setPosition(200.f * i, 600.f);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < N; i++) {
            window.draw(circles[i]);
            window.draw(rectangles[i]);
            window.draw(triangles[i]);
            window.draw(lines[i]);
        }
        window.display();
    }

    return 0;
}