#include "bmplib.h"
#include <iostream>
#include <cstring>

#include <vector>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char result[SIZE][SIZE];


void loadImage();
void saveImage();
void blur();



int main(){

    loadImage();
    blur();
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
    writeGSBMP(file_name, result);
}
void blur(){
    int radius =7;

    vector<vector<double>>gaussian_kernel(radius,vector<double>(radius,1));

    int offset = (radius-1)/2;
    double sum = 0.0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int y=0;y<radius;y++){
                for(int x=0;x<radius;x++){
                    sum += gaussian_kernel[y][x] * (double)image[i-offset+y][j-offset+x];
                }
            }
            result[i][j]=sum/49;
            sum = 0;
        }
    }


}