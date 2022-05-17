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

void openFile() {


    FILE* fp = fopen("test.bmp", "rb");

    if (fp == nullptr) {
        cout << "cos poszlo nie tak";
        
    }
    else {
        cout << "udalo sie otworzyc plik\n";

        cout << sizeof(BMP_header) << "\n";

        fread(header_bmp.name, 2, 1, fp);
        fread(&header_bmp.size, 3 * sizeof(int), 1, fp);
        //fread(&header, sizeof(struct BMP_header), 1, fp);
        cout << "Pierwsze dwa znaki :" << header_bmp.name[0] << header_bmp.name[1]<<"\n";
        cout << "Rozmiar pkiku: " << header_bmp.size << "\n";

         fclose(fp);
    }
  
}

int main()
{
    
    openFile();

    return 0;
}


