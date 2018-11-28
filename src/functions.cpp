#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "structs.hpp"
#include "bibli.hpp"

void SF_Error(sf::RenderWindow *p1, const char *p2)
{
    std::cout << "error : " << p2 << std::endl;
    (*p1).close();
    exit(EXIT_FAILURE);
}

sf::RectangleShape PB_Bouton(float PosX, float PosY)
{
    sf::RectangleShape name;
    name.setSize(sf::Vector2f(440.f, 160.f));
    name.setFillColor(sf::Color(0, 255, 255, 125));
    name.setPosition(sf::Vector2f(PosX, PosY));

    return name;
}