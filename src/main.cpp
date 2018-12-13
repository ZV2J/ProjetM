#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "structs.hpp"
#include "bibli.hpp"

/*
    g++ -std=c++14 src/*.cpp -o bin/prog -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system
*/

int main()
{
    sf::RenderWindow window;
    sf::Clock clock;

    sf::RectangleShape b_hautgauche = PB_Bouton(100, 100);
    sf::RectangleShape b_hautmilieu = PB_Bouton(740, 100);
    sf::RectangleShape b_hautdroite = PB_Bouton(1380, 100);

    sf::RectangleShape b_milieugauche = PB_Bouton(100, 460);
    sf::RectangleShape b_milieumilieu = PB_Bouton(740, 460);
    sf::RectangleShape b_milieudroite = PB_Bouton(1380, 460);   

    sf::RectangleShape b_basgauche = PB_Bouton(100, 820);
    sf::RectangleShape b_basmilieu = PB_Bouton(740, 820);
    sf::RectangleShape b_basdroite = PB_Bouton(1380, 820);

    sf::RectangleShape b_exit;
    sf::RectangleShape b_menu;
    sf::RectangleShape l_exit_d;
    sf::RectangleShape l_exit_c;

    sf::String m_saisie("");

    window.create(sf::VideoMode(WIN_W, WIN_H), "SFML Test", sf::Style::Fullscreen);

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    if(!background_texture.loadFromFile("src/image/background.png"))
        SF_Error(&window, "load texture background");


    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(sf::Vector2f(0.f, 0.f));

    b_exit.setSize(sf::Vector2f(50.f, 50.f));
    b_exit.setPosition(sf::Vector2f(1870.f, 0.f));
    b_exit.setFillColor(sf::Color(50, 50, 50, 255));

    b_menu.setSize(sf::Vector2f(570.f, 1080.f));
    b_menu.setPosition(sf::Vector2f(0.f, 0.f));
    b_menu.setFillColor(sf::Color(0, 0, 0, 205));

    l_exit_d.setSize(sf::Vector2f(57.f, 2.f));
    l_exit_c.setSize(sf::Vector2f(57.f, 2.f));
    l_exit_d.setPosition(sf::Vector2f(1875.f, 5.f));
    l_exit_c.setPosition(sf::Vector2f(1915.f, 5.f));
    l_exit_d.rotate(45);
    l_exit_c.rotate(135);
    l_exit_d.setFillColor(sf::Color::White);
    l_exit_c.setFillColor(sf::Color::White);

    sf::Font font_arial;

    if(!font_arial.loadFromFile("src/police/arial.ttf"))
        SF_Error(&window, "load arial font");

    sf::Text t_date;
    t_date.setFont(font_arial);
    t_date.setString("Date (JJ/MM/AAAA)");
    t_date.setCharacterSize(20);
    t_date.setFillColor(sf::Color::White);
    t_date.setStyle(sf::Text::Bold);
    t_date.setPosition(sf::Vector2f(215.f, 74.f));

    sf::Text saisie_date;
    saisie_date.setFont(font_arial);
    saisie_date.setString("");
    saisie_date.setCharacterSize(20);
    saisie_date.setFillColor(sf::Color::White);
    saisie_date.setStyle(sf::Text::Bold);
    saisie_date.setPosition(sf::Vector2f(215.f, 170.f));

    bool bool_menu = false;

    window.setFramerateLimit(144);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 1870 && event.mouseButton.y < 50)
                {
                    window.close();
                }
            }

            if(event.type == sf::Event::TextEntered)
            {
                if((event.text.unicode > 30 && (event.text.unicode < 128 || event.text.unicode > 159)))
                {
                    m_saisie += static_cast<char>(event.text.unicode);
                    saisie_date.setString(m_saisie);

                }
            }

            if (bool_menu == false)
                b_menu.setFillColor(sf::Color(0, 0, 0, 0));

            if(bool_menu == true)
                b_menu.setFillColor(sf::Color(0, 0, 0, 205));



            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 100 && event.mouseMove.y < 260 && bool_menu == false)
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




            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 460 && event.mouseMove.y < 620 && bool_menu == false)
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




            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 100 && event.mouseMove.x < 540 && event.mouseMove.y > 820 && event.mouseMove.y < 980 && bool_menu == false)
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

            
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Tab)
                {
                    if(bool_menu == true)
                        bool_menu = false;
                    else
                        bool_menu = true;
                }
            }



            if(event.type == sf::Event::MouseMoved && event.mouseMove.x > 1870 && event.mouseMove.y < 50)
                b_exit.setFillColor(sf::Color(255, 0, 0, 255));
            else
                b_exit.setFillColor(sf::Color(50, 50, 50, 255));

            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Tab:

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

        window.draw(b_exit);
        window.draw(l_exit_d);
        window.draw(l_exit_c);

        window.draw(t_date);

        window.draw(saisie_date);

        window.draw(b_menu);
        window.display();
    }
    return 0;
}