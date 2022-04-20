// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: edge_detect.cpp
// Last Modification Date: 31/03/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: Eng Mahmoud
// Purpose:detect edges of an image

#include <iostream>
#include <cstring>
#include "bmplib.h"
#include <cmath>

using namespace std;
unsigned char imageE[SIZE][SIZE];
int sobelX[3][3] = {{-1,0,1},{-2,0,2}, {-1,0,1}};
int sobelY[3][3] = {{1,2,1},{0,0,0}, {-1,-2,-1}};


unsigned char resultSobel[SIZE][SIZE];


void loadImageE();
void saveImageE();
void edge_detect();

int main(){
    loadImageE();
    edge_detect();
    saveImageE();
}
void loadImageE(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageE);
}
void saveImageE() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeGSBMP(file_name, resultSobel);
}

void edge_detect(){
    double sumX =0;
    double sumY =0;
    double result =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int y=0;y<3;y++){
                for(int x=0;x<3;x++){
                    sumX += sobelX[y][x] * imageE[i-1+y][j-1+x];
                    sumY += sobelY[y][x] * imageE[i-1+y][j-1+x];
                }
            }
            result = sqrt(pow(sumX,2)+ pow(sumY,2));
            if(result >= 120){
                resultSobel[i][j] = 255;
            } else{
                resultSobel[i][j] = 0;
            }
            sumX = 0;
            sumY = 0;
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            resultSobel[i][j] ^= 0xFF;
        }
    }

}

