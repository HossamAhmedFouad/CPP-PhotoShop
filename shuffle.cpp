#include <iostream>
#include "bmplib.h"
#include <cstring>
#include <vector>
using namespace std;

unsigned char image[SIZE][SIZE],result[SIZE][SIZE];
vector<vector<int>>image1(SIZE,vector<int>(SIZE)),image2(SIZE,vector<int>(SIZE)),image3(SIZE,vector<int>(SIZE)),image4(SIZE,vector<int>(SIZE));

void loadImage();
void saveImage();
void shuffle();

ostream& operator<<(ostream& out, vector<vector<int>>images){
    for(int i=0;i<128;i+=10){
        for(int j=0;j<128;j+=10){
            out<<images[i][j];
        }
        out<<endl;
    }
    return out;
}


int main(){
    loadImage();
    shuffle();
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
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, result);
}

void shuffle(){
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

    vector<vector<vector<int>>>images = {{{}},image1,image2,image3,image4};
    int first{0},second{0},third{0},fourth{0};
    cout<<"Please enter sequence of shuffle numbers separated by a space"<<endl;
    cin>>first>>second>>third>>fourth;
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            result[i][j] = images[first][i][j];
        }
    }
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            result[i][j] = images[second][i][j-129];
        }
    }
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            result[i][j] = images[third][i-129][j];
        }
    }
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            result[i][j] = images[fourth][i-129][j-129];
        }
    }

}