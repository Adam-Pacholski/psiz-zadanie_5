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
}header_bmp;

struct DIB_header{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short int planes;
    unsigned short int bitPerPixel;
    unsigned int compresion;
    unsigned int imageSize;
    unsigned int xPelsPerMeter;
    unsigned int yPelsPerMeter;
    unsigned int colorUsed;
    unsigned int colorImportant;

}header_dib;


void openFile() {


    FILE* fp = fopen("test.bmp", "rb");

    if (fp == nullptr) {
        cout << "cos poszlo nie tak";
        
    }
    else {
       // cout << "udalo sie otworzyc plik\n";

       // cout << sizeof(BMP_header) << "\n";

        fread(header_bmp.name, 2, 1, fp);
        fread(&header_bmp.size, sizeof(header_bmp.size), 1, fp);
        fread(&header_bmp.garbage, sizeof(header_bmp.garbage), 1, fp);
        fread(&header_bmp.offset, sizeof(header_bmp.offset), 1, fp);

        
        fread(&header_dib, sizeof(struct DIB_header), 1, fp);


       /* cout << "Pierwsze dwa znaki :" << header_bmp.name[0] << header_bmp.name[1] << "\n";
        cout << "Rozmiar pkiku: " << header_bmp.size << " bajtow\n";
        cout << "Garbage: " << header_bmp.garbage << "\n";
        cout << "Offset: " << header_bmp.offset << "\n"; */

        cout << "Wielkosc nagłowka informacyjnego: " << header_dib.headerSize << "\n";
        cout << "Szerokosc obrazu: " << header_dib.width << " pikseli\n";
        cout << "Wysokosc obrazu: " << header_dib.height << " pikseli\n";
        cout << "Liczba warstw kolorow: " << header_dib.planes << "\n";
        cout << "Liczba bitow na piksel: " << header_dib.bitPerPixel << "\n";
        cout << "Algorytm kompresji: " << header_dib.compresion << "\n";
        cout << "Rozmiar samego rysunku: " << header_dib.imageSize << "\n";
        cout << "Rozdzielczosc pozioma: " << header_dib.xPelsPerMeter << "\n";
        cout << "Rozdzielczosc pionowa: " << header_dib.yPelsPerMeter << "\n";
        cout << "Liczba kolorow w palecie: " << header_dib.colorUsed << "\n";
        cout << "Liczba waznych kolorow w palecie: " << header_dib.colorImportant << "\n";

         fclose(fp);
    }
  
}

int main()
{
    
    openFile();

    return 0;
}


