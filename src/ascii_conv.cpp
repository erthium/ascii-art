#include "ascii_conv.hpp"

#define TICK_INTERVAL 100
static Uint32 next_time;
Uint32 time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}


int to_gray_scale(int r, int g, int b){
    return (r + g + b) / 3;
}


ASCII_Converter::ASCII_Converter(string density_table, string path){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
    }
    window = SDL_CreateWindow(
        "ASCII Converter",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000,
        1000,
        0
    );
    renderer = SDL_CreateRenderer(window, -1, 0);

    this->density_table = density_table;
    image = load_texture(path);
    cout << SDL_GetError() << endl;
    ascii_image = convert(image);

    // get the width and height of the image
    SDL_QueryTexture(image, NULL, NULL, &width, &height);
    
    width /= 2;
    height /= 2;
    SDL_SetWindowSize(window, width, height);

    cout << "Game initialized." << endl;
}


ASCII_Converter::~ASCII_Converter(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game deconstructed." << endl;
}


void ASCII_Converter::handle_events(){
    // mouse events
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    
    // SDL events
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_r:
                restart = true;
                break;
            default:
                break;
            }
            break;
        
        default:
            break;
        }
    }         
}


void ASCII_Converter::render(){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect current_rect = {0, 0, width, height};
    SDL_RenderCopy(renderer, image, NULL, &current_rect);
    
    SDL_RenderPresent(renderer);

}


void ASCII_Converter::show(){
    next_time = SDL_GetTicks() + TICK_INTERVAL;
    while (!quit)
    {
        if (restart){
            cout << "Restarting the Game." << endl;
            restart = false;
        }
        handle_events();
        render();
        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;
    }
    cout << "Closing the Game." << endl;
}


SDL_Texture* ASCII_Converter::load_texture(string path){
    return IMG_LoadTexture(renderer, path.c_str());
}


SDL_Texture* ASCII_Converter::convert(SDL_Texture* texture){
    
    return texture;
}
