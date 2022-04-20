#include "bmplib.h"
#include <iostream>
#include <cstring>
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];
unsigned char enlargedImage[SIZE][SIZE];
void loadImage();
void saveImage();
void enlarge();

int main(){
    loadImage();
    enlarge();
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
    writeGSBMP(file_name, enlargedImage);
}

void enlarge() {
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            image1[i][j] = image[i][j];
        }
    }
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            image2[i][j - 129] = image[i][j];
        }
    }
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            image3[i - 129][j] = image[i][j];
        }
    }

    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            image4[i - 129][j - 129] = image[i][j];
        }
    }

    cout << "Please select which quarter you would like to enlarge" << endl;
    cout << "1-First Quarter" << endl;
    cout << "2-Second Quarter" << endl;
    cout << "3-Third Quarter" << endl;
    cout << "4-Fourth Quarter" << endl;
    cout << "->";
    int choice;
    cin >> choice;
    cout << endl;
    if (choice == 1) {
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                enlargedImage[0 + 2 * i][0 + 2 * j] = image1[i][j];
            }
        }
    }else if(choice == 2){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                enlargedImage[0 + 2 * i][0 + 2 * j] = image2[i][j];
            }
        }
    }else if(choice==3){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                enlargedImage[0 + 2 * i][0 + 2 * j] = image3[i][j];
            }
        }
    }else if(choice==4){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                enlargedImage[0 + 2 * i][0 + 2 * j] = image4[i][j];
            }
        }
    }else{
        cout<<"Wrong Input"<<endl;
    }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (enlargedImage[i][j] == 0) {
                    if (enlargedImage[i][j - 1] != 0 && enlargedImage[i][j + 1] != 0) {
                        enlargedImage[i][j] = (enlargedImage[i][j + 1] + enlargedImage[i][j - 1]) / 2;

                    }
                }
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(enlargedImage[i][j]==0){
                    enlargedImage[i][j] = (enlargedImage[i-1][j]+enlargedImage[i+1][j])/2;
                }
            }
        }
    }
