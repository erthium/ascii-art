#include "ascii_conv.hpp"


int to_gray_scale(int r, int g, int b){
    return (r + g + b) / 3;
}


ASCII_Converter::ASCII_Converter(string density_table, string path){
    this->density_table = density_table;

    image = load_image(path);
    sf::Texture texture = load_texture(path);
    image_s = sf::Sprite(texture);
    image_s.setPosition(0, 0);

    size = texture.getSize();

    window.create(sf::VideoMode(size.x, size.y), "ASCII Converter", sf::Style::Titlebar);
    
    cout << "Game initialized." << endl;
}


ASCII_Converter::~ASCII_Converter(){
    cout << "Game deconstructed." << endl;
}


void ASCII_Converter::handle_events(){
    // mouse events
    // int mouse_x, mouse_y;
    
    // SDL events

    sf::Event event;
    while (window.pollEvent(event)){
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
    window.draw(image_s);
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


sf::Image ASCII_Converter::load_image(string path){
    sf::Image _image;
    if (!_image.loadFromFile(path)){
        cout << "Error loading image." << endl;
    }
    return _image;
}

sf::Texture ASCII_Converter::load_texture(string path){
    sf::Texture _texture;
    if (!_texture.loadFromFile(path)){
        cout << "Error loading texture." << endl;
    }
    return _texture;
}


sf::Image ASCII_Converter::convert(sf::Image texture){
    return texture;
}
