#include "converter.hpp"

using namespace std;

/* -- string target replacement --
string path = WHITE_PIECE_DIR;
path.replace(path.find("{}"), 2, string(1, char(i + '0')));
SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
*/

// images to convert
#define TEST_IMAGE_PATH "assets/images/spider.png"
#define FONT_PATH "assets/fonts/mono_regular.ttf" 

// density tables
const string DENSITY_TABLE_1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.                                                                                                                                                      ";
const string DENSITY_TABLE_2 = " .:-=+*#%@";

string parse_args(int argc, char const *argv[]){
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <path>" << endl;
        exit(1);
    }

    return argv[1];
}


ASCII_Converter *converter = nullptr;
int main(int argc, char const *argv[]){
    string image_path = parse_args(argc, argv);
    converter = new ASCII_Converter(DENSITY_TABLE_2, image_path, FONT_PATH);
    converter->convert(8, true);
    converter->loop();
    delete converter;
    return 0;
}
