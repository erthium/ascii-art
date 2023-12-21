#include "ascii_conv.hpp"


int to_gray_scale(int r, int g, int b){
    return (r + g + b) / 3;
}


ASCII_Converter::ASCII_Converter(string density_table, string path){
    window.create(sf::VideoMode(800, 800), "ASCII Converter");

    this->density_table = density_table;
    image = load_texture(path);
    ascii_image = convert(image);

    // get the width and height of the image

    //SDL_SetWindowSize(window, width, height);

    cout << "Game initialized." << endl;
}


ASCII_Converter::~ASCII_Converter(){
    cout << "Game deconstructed." << endl;
}


void ASCII_Converter::handle_events(){
    // mouse events
    int mouse_x, mouse_y;
    
    // SDL events

    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed){
            quit = true;
            window.close();
        }
        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code)
            {
            case sf::Keyboard::R:
                restart = true;
                break;
            default:
                break;
            }
        }
    }       
}


void ASCII_Converter::render(){
    window.clear();

    window.display();
}


void ASCII_Converter::show(){
    while (!quit && window.isOpen())
    {
        if (restart){
            cout << "Restarting the Game." << endl;
            // No restart logic needed for now
            restart = false;
        }
        handle_events();
        render();
        sf::sleep(sf::seconds(0.01));
    }
    cout << "Closing the Game." << endl;
    if (window.isOpen()) window.close();
}


sf::Texture ASCII_Converter::load_texture(string path){
    sf::Texture texture;
    if (!texture.loadFromFile(path)){
        cout << "Error loading image." << endl;
    }
    return texture;
}


sf::Texture ASCII_Converter::convert(sf::Texture texture){
    return texture;
}
