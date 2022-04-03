// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: darken_lighten-image.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose:produce a darkened or lightened image

#include <iostream>
#include <cstring>
#include "bmplib.h"
using namespace std;
unsigned char imageDL[SIZE][SIZE];
void loadImageDL();
void saveImageDL();
void darken_lighten_image();

int main(){

    loadImageDL();
    darken_lighten_image();
    saveImageDL();
    return 0;
}

void loadImageDL(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageDL);
}
void saveImageDL() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeGSBMP(file_name, imageDL);
}

void darken_lighten_image(){
    int average{0};
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            average+= imageDL[i][j];
        }
    }
    average = average / (SIZE*SIZE);
    int choice{0};
    cout<<"Please Select An Option:"<<endl;
    cout<<"1-Lighten"<<endl;
    cout<<"2-Darken"<<endl;
    cout<<"->";
    cin>>choice;
    while (choice>2 || choice < 1){
        cout<<"Wrong option, please try again"<<endl;
        cin>>choice;
    }
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                imageDL[i][j] += (255-imageDL[i][j])/2;
            }
        }
    }else if (choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                imageDL[i][j] -= (imageDL[i][j])/2;
            }
        }
    }

}
