#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>

using namespace std;

class ASCII_Converter {
    private: // private variables
        // window Rendering
        int width;
        int height;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        // game Loop
        bool quit = false;
        bool restart = false;

        // game state
        string density_table;
        SDL_Texture* image = nullptr;
        SDL_Texture* ascii_image = nullptr;
    
    public: // public variables

    public: // public methods
        ASCII_Converter(string density_table, string path);
        ~ASCII_Converter();
        void handle_events();
        void render();
        void show();
        SDL_Texture* load_texture(string path);
        SDL_Texture* convert(SDL_Texture* texture);
};
