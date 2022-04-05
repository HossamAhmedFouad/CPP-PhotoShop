// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: flip_image.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose:produce a flipped image

#include <iostream>
#include <cstring>
#include "bmplib.h"

using namespace std;
unsigned char imageF[SIZE][SIZE];
unsigned char image_flipped[SIZE][SIZE];
void loadImageF();
void saveImageF();
void flipImage();
int main(){
    loadImageF();
    flipImage();
    saveImageF();
}

void loadImageF(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageF);
}
void saveImageF() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeGSBMP(file_name, image_flipped);
}
void flipImage(){
    int choice{0};
    cout<<"please select flip option:"<<endl;
    cout<<"1-horizontally"<<endl;
    cout<<"2-vertically"<<endl;
    cout<<"->";
    cin>>choice;
    while (choice>3 || choice < 1){
        cout<<"Wrong option, please try again"<<endl;
        cin>>choice;
    }
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image_flipped[i][j] = imageF[SIZE-1-i][j];
            }
        }
    }else if(choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image_flipped[i][j] = imageF[i][SIZE-1-j];
            }
        }
    }

}


