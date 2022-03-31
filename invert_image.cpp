// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: invert_image.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose:Invert an image

#include <iostream>
#include <cstring>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void invertImage();

int main(){
    cout<<"Hi"<<endl;
    loadImage();
    invertImage();
    saveImage();
}

void loadImage(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,image);
}
void saveImage () {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, image);
}

void invertImage(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            //invert each bit in the pixels
            image[i][j] ^= 0xFF  ;
        }
    }
}
