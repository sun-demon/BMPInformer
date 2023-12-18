#include "include/bmp.h"
#include "include/Bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

void printInfo(char * filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Bad file input format: needed BMP";
        return;
    }
    fin.seekg(0, ios::end);
    size_t length = fin.tellg();
    fin.seekg(0, ios::beg);
    vector<char> buffer(length);
    fin.read(&buffer[0], length);
    auto file_header = (PBITMAPFILEHEADER)(&buffer[0]);
    cout << "First bytes: \"" << buffer[0] << buffer[1] << "\"" << endl;
    cout << "File header size: " << file_header->bfSize << " Bytes" << endl;
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        cerr << "[Utility format]: BMPInformer input.bmp output.bmp";
        return 1;
    }

    printInfo(argv[1]);

    bmp::Bitmap image(argv[1]);
    cout << "Image width: " << image.width() << ", height: " << image.height();
    for (auto & pixel : image) {
        pixel.b ^= 255;
        pixel.g ^= 255;
        pixel.r ^= 255;
    }
    image.save(argv[2]);

    return 0;
}