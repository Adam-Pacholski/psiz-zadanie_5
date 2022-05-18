#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct BMP_header
{
    char name[2];
    unsigned int size;
    int garbage; // nie koniecznie musi byc
    unsigned int offset;
}File;

struct DIB_header {
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned short int colorPlanes;
    unsigned short int bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;

}Dib;

void openFile() {


    FILE* fp = fopen("test.bmp", "rb");

    if (fp == nullptr) {
        cout << "cos poszlo nie tak";
        
    }
    else {
        cout << "udalo sie otworzyc plik\n";

       

        fread(File.name, 2, 1, fp);
        fread(&File.size, 3 * sizeof(int), 1, fp);
        fread(&File.garbage, 4, 1, fp);
        fread(&File.offset, 4, 1, fp);
        fread(&Dib,sizeof(struct DIB_header), 1, fp);

        
        cout << "Pierwsze dwa znaki :" << File.name[0] << File.name[1]<<"\n";
        cout << "Rozmiar pkiku: " << File.size << "\n";
        cout << "Rozmiar carbage: " << File.garbage << "\n";
        cout << "Rozmiar offsets: " << File.offset << "\n";

        cout << "Rozmiar dip heder: " << Dib.header_size << "\n";
        cout << "Rozmiar BMP:  " << Dib.width << " x " << Dib.height << "\n";
  
        cout << "Color planes: " << Dib.colorPlanes << "\n";

         fclose(fp);
    }
  
}

int main()
{
    
    openFile();

    return 0;
}


