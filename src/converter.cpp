#include "converter.hpp"


int to_gray_scale(int r, int g, int b) {
    return (r + g + b) / 3;
}


ASCII_Converter::ASCII_Converter(string density_table, string image_path, string font_path) {
    this->density_table = density_table;
    // reverse the density table
    

    if (!texture.loadFromFile(image_path)) {
        cout << "Error loading image." << endl;
        return;
    }
    sprite.setTexture(texture);
    // sprite.setPosition(0, 0);
    size = texture.getSize();

    window.create(sf::VideoMode(size.x, size.y), "ASCII Converter", sf::Style::Titlebar);
    
    if (!font.loadFromFile(font_path)){
        cout << "Error loading font." << endl;
        return;
    }
    image = texture.copyToImage();

    cout << "Game initialized." << endl;
}


ASCII_Converter::~ASCII_Converter() {
    cout << "Game deconstructed." << endl;
}


void ASCII_Converter::handle_events() {
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


void ASCII_Converter::render() {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}


void ASCII_Converter::loop() {
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


void ASCII_Converter::convert(int length, bool reverse_table) {
    // go through each AxA pixels and determine the average color
    // then convert the average color to a character
    // then draw the character to the screen

    string current_table = density_table;
    if (reverse_table){
        reverse(current_table.begin(), current_table.end());
    }

    render_texture.clear();
    render_texture.create(texture.getSize().x, texture.getSize().y);
    for (size_t i = 0; i < texture.getSize().x; i += length){
        for (size_t j = 0; j < texture.getSize().y; j += length){
            // get the average of the density x density pixels
            int r = 0, g = 0, b = 0;
            for (size_t x = 0; x < length; x++){
                for (size_t y = 0; y < length; y++){
                    if (i + x < texture.getSize().x && j + y < texture.getSize().y){
                        sf::Color color = image.getPixel(i + x, j + y);
                        r += color.r;
                        g += color.g;
                        b += color.b;
                    }
                }
            }
            r /= length * length;
            g /= length * length;
            b /= length * length;
            int gray = to_gray_scale(r, g, b);
            int index = gray * density_table.size() / 256;
            char c = density_table[density_table.size() - index];
            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(length);
            text.setFillColor(sf::Color::White);
            text.setString(string(1, c));
            text.setPosition(i, j);
            render_texture.draw(text);
        }
    }
    render_texture.display();
    ascii_texture = render_texture.getTexture();
    sprite.setTexture(ascii_texture);
}
