#include <iostream>
#include <cstring>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void mirror();

int main(){
    loadImage();
    mirror();
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
void saveImage() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeGSBMP(file_name, image);
}

void mirror(){
    cout<<"Please select which part of image you would like to mirror:"<<endl;
    cout<<"1- Left 1/2"<<endl;
    cout<<"2- Right 1/2"<<endl;
    cout<<"3- Upper 1/2"<<endl;
    cout<<"4- Lower 1/2"<<endl;
    cout<<"->";
    int choice{0};
    cin>>choice;
    cout<<endl;
    if(choice==4){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j <SIZE ; j++) {
                image[i][j] = image[SIZE-1-i][j];
            }
        }
    }else if(choice==2){
        for(int i=0;i<SIZE;i++){
            for (int j = 0; j <SIZE ; j++) {
                image[i][j] = image[i][SIZE-1-j];
            }
        }
    }else if(choice == 1){
        int counter=0;
        for(int i=0;i<SIZE;i++){
            for (int j = 128; j <SIZE ; j++) {
                image[i][j] = image[i][j-counter];
                counter+=2;
            }
            counter=0;
        }
    }else if(choice==3){
        int counter=0;
        for(int i=128;i<SIZE;i++){
            for (int j = 0; j <SIZE ; j++) {
                image[i][j] = image[i-counter][j];

            }
            counter+=2;
        }
    }
}


