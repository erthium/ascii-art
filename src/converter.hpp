#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

using namespace std;

class ASCII_Converter {
    private: // private variables
        // Rendering
        sf::Vector2u size;
        sf::RenderWindow window;
        sf::RenderTexture render_texture;
        sf::Font font;

        // Loop
        bool quit = false;
        bool restart = false;

        // States
        string density_table;
        sf::Texture texture;
        sf::Image image;
        sf::Sprite sprite;
        sf::Texture ascii_texture;

    public: // public variables

    public: // public methods
        ASCII_Converter(string density_table, string image_path, string font_path);
        ~ASCII_Converter();
        void handle_events();
        void render();
        void loop();
        void convert(int length, bool reverse_table = false);
};
