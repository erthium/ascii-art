#include "ascii_conv.hpp"

using namespace std;

/* -- string target replacement --
string path = WHITE_PIECE_DIR;
path.replace(path.find("{}"), 2, string(1, char(i + '0')));
SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
*/

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800


// images to convert
#define PATH_1 "../assets/test.png"

// density tables
static string DENSITY_TABLE_1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
static string DENSITY_TABLE_2 = " .:-=+*#%@";

ASCII_Converter *converter = nullptr;
int main(){
    converter = new ASCII_Converter(DENSITY_TABLE_1, PATH_1);
    converter->show();
    delete converter;
    return 0;
}
