#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class ASCII_Converter {
    private: // private variables
        // window Rendering
        sf::Vector2u size;
        sf::RenderWindow window;

        // game Loop
        bool quit = false;
        bool restart = false;

        // game state
        string density_table;
        sf::Texture image;
        sf::Sprite image_s;
        sf::Texture ascii_image;
        sf::Sprite ascii_image_s;
    
    public: // public variables

    public: // public methods
        ASCII_Converter(string density_table, string path);
        ~ASCII_Converter();
        void handle_events();
        void render();
        void show();
        sf::Texture load_texture(string path);
        sf::Texture convert(sf::Texture texture);
};
