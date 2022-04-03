// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: rotate_image.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose:rotate an image

#include <iostream>
#include <cstring>
#include "bmplib.h"

using namespace std;
unsigned char imageR[SIZE][SIZE];
unsigned char image_rotated[SIZE][SIZE];

void loadImageR();
void saveImageR();
void rotateImage();


void rotate(){
    loadImageR();
    rotateImage();
    saveImageR();
}

void loadImageR(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageR);
}
void saveImageR() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, image_rotated);
}

void rotateImage(){
    int rotation_degree{0};
    cout<<"please select rotation degree:"<<endl;
    cout<<"1-90  degrees"<<endl;
    cout<<"2-180 degrees"<<endl;
    cout<<"3-270 degrees"<<endl;
    cout<<"->";
    cin>>rotation_degree;
    while (rotation_degree>3 || rotation_degree < 1){
        cout<<"Wrong option, please try again"<<endl;
        cin>>rotation_degree;
    }
    if(rotation_degree == 1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image_rotated[i][j] = imageR[SIZE-1-j][i];
            }
        }
    }else if(rotation_degree==2){

        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                image_rotated[i][j] = imageR[SIZE-1-i][SIZE-1-j];
            }
        }

    }else if(rotation_degree==3){
        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                image_rotated[i][j] = imageR[j][SIZE-1-i];
            }
        }

    }

}