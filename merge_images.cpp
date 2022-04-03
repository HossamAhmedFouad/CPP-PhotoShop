// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: merge_images.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose:merge two images

#include <iostream>
#include <cstring>
#include "bmplib.h"

using namespace std;

unsigned char imageM1[SIZE][SIZE];
unsigned char imageM2[SIZE][SIZE];
unsigned char imageM[SIZE][SIZE];

void loadImageM1();
void loadImageM2();
void saveImageM();
void merge_images();

int main(){
    loadImageM1();
    loadImageM2();
    merge_images();
    saveImageM();
}

void loadImageM1(){
    char file_name[100];
    //get file
    cout <<"Enter name of image 1: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageM1);
}
void loadImageM2(){
    char file_name[100];
    //get file
    cout <<"Enter name of image 2: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageM2);
}
void saveImageM() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeGSBMP(file_name, imageM);
}

void merge_images(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageM[i][j] = (imageM1[i][j]+imageM2[i][j])/2;
        }
    }
}
