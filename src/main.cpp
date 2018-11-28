#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "structs.hpp"
#include "bibli.hpp"

sf::RectangleShape b_hautgauche = PB_Bouton(100, 100);
sf::RectangleShape b_hautmilieu = PB_Bouton(740, 100);
sf::RectangleShape b_hautdroite = PB_Bouton(1380, 100);

sf::RectangleShape b_milieugauche = PB_Bouton(100, 460);
sf::RectangleShape b_milieumilieu = PB_Bouton(740, 460);
sf::RectangleShape b_milieudroite = PB_Bouton(1380, 460);

sf::RectangleShape b_basgauche = PB_Bouton(100, 820);
sf::RectangleShape b_basmilieu = PB_Bouton(740, 820);
sf::RectangleShape b_basdroite = PB_Bouton(1380, 820);

/*
    g++ -std=c++14 src/*.cpp -o bin/prog -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system
*/

int main()
{
    sf::RenderWindow window;
    sf::Clock clock;

    window.create(sf::VideoMode(WIN_W, WIN_H), "SFML Test", sf::Style::Fullscreen);

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    if(!background_texture.loadFromFile("src/image/background.png"))
        SF_Error(&window, "load texture background");


    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(sf::Vector2f(0.f, 0.f));

    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 100 && event.mouseMove.y < 260)
                b_hautgauche.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_hautgauche.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 740 && event.mouseMove.x < 1180 && event.mouseMove.y > 100 && event.mouseMove.y < 260)
                b_hautmilieu.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_hautmilieu.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 1380 && event.mouseMove.x < 1820 && event.mouseMove.y > 100 && event.mouseMove.y < 260)
                b_hautdroite.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_hautdroite.setFillColor(sf::Color(0, 255, 255, 125));




            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 460 && event.mouseMove.y < 620)
                b_milieugauche.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_milieugauche.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 740 && event.mouseMove.x < 1180 && event.mouseMove.y > 460 && event.mouseMove.y < 620)
                b_milieumilieu.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_milieumilieu.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 1380 && event.mouseMove.x < 1820 && event.mouseMove.y > 460 && event.mouseMove.y < 620)
                b_milieudroite.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_milieudroite.setFillColor(sf::Color(0, 255, 255, 125));




            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 820 && event.mouseMove.y < 980)
                b_basgauche.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_basgauche.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 740 && event.mouseMove.x < 1180 && event.mouseMove.y > 820 && event.mouseMove.y < 980)
                b_basmilieu.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_basmilieu.setFillColor(sf::Color(0, 255, 255, 125));

            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 1380 && event.mouseMove.x < 1820 && event.mouseMove.y > 820 && event.mouseMove.y < 980)
                b_basdroite.setFillColor(sf::Color(0, 255, 255, 255));
            else
                b_basdroite.setFillColor(sf::Color(0, 255, 255, 125));
                

            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Space:
                            window.close();
                            break;
                    }
                    break;

                default:
                    break;
            }
        }


        sf::Time time = clock.getElapsedTime();
        clock.restart();
        window.clear(sf::Color::Black);
        window.draw(background_sprite);
        window.draw(b_hautgauche);
        window.draw(b_hautmilieu);
        window.draw(b_hautdroite);

        window.draw(b_milieugauche);
        window.draw(b_milieumilieu);
        window.draw(b_milieudroite);

        window.draw(b_basgauche);
        window.draw(b_basmilieu);
        window.draw(b_basdroite);

        window.display();
    }
    return 0;
}