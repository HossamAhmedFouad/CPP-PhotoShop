#include <iostream>
#include "bmplib.h"
#include <cstring>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char imageS[SIZE][SIZE];
void loadImage();
void saveImage();
void shrink();
int main(){
loadImage();
shrink();
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
    writeGSBMP(file_name, imageS);
}
void shrink(){
    cout<<"Please choose ratio to shrink to"<<endl;
    cout<<"1- 1/2"<<endl;
    cout<<"2- 1/3"<<endl;
    cout<<"3- 1/4"<<endl;
    cout<<"->";
    int choice{0};
    cin>>choice;
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageS[i][j] = 255;
        }
    }
    if(choice==1){
        for(int i=0;i<SIZE/2;i++){
            for(int j=0;j<SIZE/2;j++){
                imageS[i][j] = image[2*i][2*j];
            }
        }

    }else if(choice==2){
        for(int i=0;i<SIZE/3;i++){
            for(int j=0;j<SIZE/3;j++){
                imageS[i][j] = image[3*i][3*j];
            }
        }
    }else if(choice==3){
        for(int i=0;i<SIZE/4;i++){
            for(int j=0;j<SIZE/4;j++){
                imageS[i][j] = image[4*i][4*j];
            }
        }
    }
}