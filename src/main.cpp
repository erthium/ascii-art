#include "converter.hpp"

using namespace std;

/* -- string target replacement --
string path = WHITE_PIECE_DIR;
path.replace(path.find("{}"), 2, string(1, char(i + '0')));
SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
*/

// images to convert
#define PATH_1 "assets/images/spider.png"
#define FONT_PATH "assets/fonts/mono_regular.ttf" 

// density tables
const string DENSITY_TABLE_1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.                                                                                                                                                      ";
const string DENSITY_TABLE_2 = " .:-=+*#%@";


ASCII_Converter *converter = nullptr;
int main(){
    converter = new ASCII_Converter(DENSITY_TABLE_2, TEST_IMAGE_PATH, FONT_PATH);
    converter->convert(8, true);
    converter->loop();
    delete converter;
    return 0;
}
