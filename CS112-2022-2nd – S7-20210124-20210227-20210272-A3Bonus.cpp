// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-2022-2nd–S7-20210124-20210227-20210272-A3Bonus.cpp
// Last Modification Date: 20/04/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: Eng. Mahmoud
// Purpose:Applies different filters to colored images


#include <iostream>
#include "bmplib.h"
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char imageMerge[SIZE][SIZE][RGB];
unsigned char resultImage[SIZE][SIZE][RGB];
unsigned char resultSobel[SIZE][SIZE][RGB];

vector<vector<vector<int>>>image1(SIZE,vector<vector<int>>(SIZE,vector<int>(3,0)));
vector<vector<vector<int>>>image2(SIZE,vector<vector<int>>(SIZE,vector<int>(3,0)));
vector<vector<vector<int>>>image3(SIZE,vector<vector<int>>(SIZE,vector<int>(3,0)));
vector<vector<vector<int>>>image4(SIZE,vector<vector<int>>(SIZE,vector<int>(3,0)));

int sobelX[3][3] = {{-1,0,1},{-2,0,2}, {-1,0,1}};
int sobelY[3][3] = {{1,2,1},{0,0,0}, {-1,-2,-1}};

/**
 * Basic Functions
 */
void loadImage();
void saveImage();

/**
 * Filters prototypes
 */

void blackAndWhite();
void invertImage();
void mergeImage();
void flipImage();
void rotateImage();
void darkenAndLighten();
void detectEdge();
void enlargeImage();
void shrinkImage();
void mirrorImage();
void shuffleImage();
void blurImage();
void menu();

int main(){
    //Load image once to apply effects on it
    loadImage();
    while (true){

        cout<<"Please select a filter to apply:"<<endl;
        menu();
        //Take choice from user as char
        char choice;
        cin>>choice;
        //If selected char value equivalent to desired number or letter->Apply change
        //ASCII Numbers: 0->48, 1->49, 2->50, 3->51, ...

        if(choice==49){
            blackAndWhite();
        }else if(choice==50){
            invertImage();
        }else if(choice==51){
            mergeImage();
        }else if(choice==52){
            flipImage();
        }else if(choice==53){
            darkenAndLighten();
        }else if(choice==54){
            rotateImage();
        }else if(choice==55){
            detectEdge();
        } else if(choice==56){
            enlargeImage();
        } else if(choice==57){
            shrinkImage();
        }else if(choice == 'a'){
            mirrorImage();
        } else if(choice == 'b') {
            shuffleImage();
        }else if(choice == 'c') {
            blurImage();
        }else if(choice == 's'){
            saveImage();
        }else if(choice == 'l'){
            loadImage();
        }else if(choice == 48){
            cout<<"Thank you for using our program"<<endl;
            break;
        } else{
            cout<<"Wrong input,please try again"<<endl;
        }
    }
    return 0;

}
//Showing menu

void menu(){
    cout<<"1-Black And White Filter"<<endl;
    cout<<"2-Invert Filter"<<endl;
    cout<<"3-Merge Filter"<<endl;
    cout<<"4-Flip image"<<endl;
    cout<<"5-Darken And LightenImage"<<endl;
    cout<<"6-Rotate Image"<<endl;
    cout<<"7-Detect Image Edges"<<endl;
    cout<<"8-Enlarge Image"<<endl;
    cout<<"9-Shrink Image"<<endl;
    cout<<"a-Mirror 1/2 Image"<<endl;
    cout<<"b-Shuffle Image"<<endl;
    cout<<"c-Blur Image"<<endl;
    cout<<"s-Save Image To A File"<<endl;
    cout<<"l-Load a new image"<<endl;
    cout<<"0-exit"<<endl;
    cout<<"->";
}

void loadImage(){
    char file_name[100];
    //get file
    cout <<"Enter file name: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readRGBBMP(file_name,image);
}

void saveImage() {
    char file_name[100];

    // Get gray scale image target file name
    cout << "Enter file name of output image: ";
    cin >> file_name;
    cout<<endl;

    // Add to it .bmp extension and save image
    strcat(file_name, ".bmp");
    writeRGBBMP(file_name, image);
}

/**
 * Black and white filter
 */

void blackAndWhite(){
    int value =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            value = (image[i][j][0] + image[i][j][1] + image[i][j][2])/3;
            //if average gray scale value > 127 then make it white else make it black
            if(value>=127){
                image[i][j][0]=image[i][j][1]=image[i][j][2] = 255;
            }else{
                image[i][j][0]=image[i][j][1]=image[i][j][2] = 0;
            }
        }
    }
}

/**
 * Invert image filter
 */
void invertImage(){
    int value =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                //Apply XOR operation to each pixel with 0xFF to invert it
                image[i][j][k]^=0xFF;
            }

        }
    }
}
/**
 * Merge image filter
 */

void mergeImage(){
    char file_name[100];
    //get file
    cout <<"Enter file name to merge: ";
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readRGBBMP(file_name,imageMerge);

    int value =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for (int k = 0; k < 3; k++) {
                //take average value of pixels from two images to be merged
                image[i][j][k] = (image[i][j][k]+imageMerge[i][j][k])/2;
            }
        }
    }

}
/**
 * Flip image filter
 */

void flipImage(){
    int choice{0};
    cout<<"please select flip option:"<<endl;
    cout<<"1-horizontally"<<endl;
    cout<<"2-vertically"<<endl;
    cout<<"->";
    cin>>choice;
    while (choice>2 || choice < 1){
        cout<<"Wrong option, please try again"<<endl;
        cin>>choice;
    }
    //Flip image horizontally
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<3;k++){
                    resultImage[i][j][k] = image[SIZE-1-i][j][k];
                }
            }
        }
    //Flip image vertically
    }else if(choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<3;k++){
                    resultImage[i][j][k] = image[i][SIZE-1-j][k];
                }
            }
        }
    }
    //Apply effect to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }
}
/**
 * Rotate image filter
 */

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
    //Rotate image 90 degrees
    if(rotation_degree == 1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<3;k++){
                   resultImage[i][j][k] = image[SIZE-1-j][i][k];
                }
            }
        }
    //Rotate image 180 degrees
    }else if(rotation_degree==2){
        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                for(int k=0;k<3;k++){
                    resultImage[i][j][k] = image[SIZE-1-i][SIZE-1-j][k];
                }
            }
        }
    //Rotate image 270 degrees
    }else if(rotation_degree==3){
        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                for(int k=0;k<3;k++){
                    resultImage[i][j][k] = image[j][SIZE-1-i][k];
                }
            }
        }
    }
    //Apply effect to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }
}
/**
 * Darken and lighten filter
 */
void darkenAndLighten(){
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
    //Lighten Image
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<3;k++) {
                    image[i][j][k] += (255 - image[i][j][k]) / 2;
                }
            }
        }
    //Darken Image
    }else if (choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<3;k++) {
                    image[i][j][k]  -= (image[i][j][k])/2;
                }
            }
        }
    }
}
/**
 * Detect edges filter
 */
void detectEdge(){
    double sumX =0;
    double sumY =0;
    double result =0;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int y=0;y<3;y++){
                for(int x=0;x<3;x++){
                    //Applying Sobel Operator To each pixel
                    sumX += sobelX[y][x] * image[i-1+y][j-1+x][0];
                    sumY += sobelY[y][x] * image[i-1+y][j-1+x][0];
                }
            }
            result = sqrt(pow(sumX,2)+ pow(sumY,2));
            //Applying a threshold of 120 to each pixel. If its greater or equal to it. Mark it as an edge
            if(result >= 120){
                resultSobel[i][j][0] = 255;
            } else{
                resultSobel[i][j][0] = 0;
            }
            sumX = 0;
            sumY = 0;
        }
    }
    //Finding non-black pixels identifies that we found edges
    //On finding an edge pixel, make the edge color channels equivalent to the original image actual colors
    //So the edges can match the colors of their original places
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            if (resultSobel[i][j][0]>0){
                resultSobel[i][j][0] = image[i][j][0];
                resultSobel[i][j][1] = image[i][j][1];
                resultSobel[i][j][2] = image[i][j][2];
            }
        }
    }
    //Apply effect to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultSobel[i][j][k];
            }
        }
    }
}
/**
 * Enlarge image filter
 */
void enlargeImage(){
    //Cutting the image into 4 quadrants

    //First Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; k++) {
                image1[i][j][k] = image[i][j][k];
            }
        }
    }
    //Second Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image2[i][j-129][k] = image[i][j][k];
            }
        }
    }
    //Third Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; k++) {
                image3[i-129][j][k] = image[i][j][k];
            }
        }
    }
    //Fourth Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image4[i-129][j-129][k] = image[i][j][k];
            }
        }
    }
    //Taking input from user to enlarge which quadrant
    cout << "Please select which quarter you would like to enlarge" << endl;
    cout << "1-First Quarter" << endl;
    cout << "2-Second Quarter" << endl;
    cout << "3-Third Quarter" << endl;
    cout << "4-Fourth Quarter" << endl;
    cout << "->";
    int choice;
    cin >> choice;
    cout << endl;
    //Enlarge quadrants by doubling the distance between every pixel and filling
    //Empty spaces with average value.

    //Enlarge First Quadrant
    if (choice == 1) {
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                for (int k = 0; k <3 ; k++) {
                    resultImage[0 + 2 * i][0 + 2 * j][k] = image1[i][j][k];
                }
            }
        }
    //Enlarge Second Quadrant
    }else if(choice == 2){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                for (int k = 0; k <3 ; k++) {
                    resultImage[0 + 2 * i][0 + 2 * j][k] = image2[i][j][k];
                }
            }
        }
    //Enlarge Third Quadrant
    }else if(choice==3){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                for (int k = 0; k <3 ; k++) {
                    resultImage[0 + 2 * i][0 + 2 * j][k] = image3[i][j][k];
                }
            }
        }
    //Enlarge Fourth Quadrant
    }else if(choice==4){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                for (int k = 0; k <3 ; k++) {
                    resultImage[0 + 2 * i][0 + 2 * j][k] = image4[i][j][k];
                }
            }
        }
    }else{
        cout<<"Wrong Input"<<endl;
    }
    //Filling empty pixels with average values

    //Horizontally
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <3 ; ++k) {
                if (resultImage[i][j][k] == 0) {
                    if (resultImage[i][j - 1][k] != 0 && resultImage[i][j + 1][k] != 0) {
                        resultImage[i][j][k] = (resultImage[i][j + 1][k] + resultImage[i][j - 1][k]) / 2;

                    }
                }
            }

        }
    }
    //Vertically
    for(int i=0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                if (resultImage[i][j][k] == 0) {
                    resultImage[i][j][k] = (resultImage[i - 1][j][k] + resultImage[i + 1][j][k]) / 2;
                }
            }
        }
    }
    //Applying effects to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }
}
/**
 * Shrink Image Filter
 */
void shrinkImage(){
    //Take input from user to shrink image with which ratio
    cout<<"Please choose ratio to shrink to"<<endl;
    cout<<"1- 1/2"<<endl;
    cout<<"2- 1/3"<<endl;
    cout<<"3- 1/4"<<endl;
    cout<<"->";
    int choice{0};
    cin>>choice;
    cout<<endl;

    //Make a white background
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for (int k = 0; k <3 ; ++k) {
                resultImage[i][j][k] = 255;
            }
        }
    }
    //Shrink image by half
    if(choice==1){
        for(int i=0;i<SIZE/2;i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; ++k) {
                    resultImage[i][j][k] = image[2 * i][2 * j][k];
                }
            }
        }
    //Shrink image by a third
    }else if(choice==2){
        for(int i=0;i<SIZE/3;i++){
            for(int j=0;j<SIZE/3;j++) {
                for (int k = 0; k < 3; ++k) {
                    resultImage[i][j][k] = image[3 * i][3 * j][k];
                }
            }
        }
    //Shrink image by a quarter
    }else if(choice==3){
        for(int i=0;i<SIZE/4;i++){
            for(int j=0;j<SIZE/4;j++){
                for (int k = 0; k < 3; ++k) {
                    resultImage[i][j][k] = image[4 * i][4 * j][k];
                }
            }
        }
    }
    //Apply effects to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }
}
/**
 * Mirror Image Filter
 */
void mirrorImage() {
    //Take input from user to mirror which part of the image
    cout << "Please select which part of image you would like to mirror:" << endl;
    cout << "1- Left 1/2" << endl;
    cout << "2- Right 1/2" << endl;
    cout << "3- Upper 1/2" << endl;
    cout << "4- Lower 1/2" << endl;
    cout << "->";
    int choice{0};
    cin >> choice;
    cout << endl;
    //Mirror Left Half
    if (choice == 1) {
        int counter = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[i][j - counter][k];
                }
                counter += 2;
            }
            counter = 0;
        }
        //Mirror Right Half
    } else if (choice == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[i][SIZE - 1 - j][k];
                }
            }
        }
        //Mirror Upper Half
    } else if (choice == 3) {
        int counter = 0;
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[i - counter][j][k];
                }
            }
            counter += 2;
        }
        //Mirror Lower Half
    } else if (choice == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[SIZE - 1 - i][j][k];
                }
            }
        }
    }
}
/**
 * Shuffle Image Filter
 */
void shuffleImage(){
    //Cutting image into four quadrants

    //First Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; k++) {
                image1[i][j][k] = image[i][j][k];
            }
        }
    }
    //Second Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image2[i][j-129][k] = image[i][j][k];
            }
        }
    }
    //Third Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; k++) {
                image3[i-129][j][k] = image[i][j][k];
            }
        }
    }
    //Fourth Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image4[i-129][j-129][k] = image[i][j][k];
            }
        }
    }
    //A 4D vector that will hold 3D colored images that can be accessed individually

    vector<vector<vector<vector<int>>>>images = {{{{}}},image1,image2,image3,image4};

    //Variables to hold sequence of shuffling
    int first{0},second{0},third{0},fourth{0};

    cout<<"Please enter sequence of shuffle numbers separated by a space"<<endl;
    cin>>first>>second>>third>>fourth;

    //Fill first quadrant with first image
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; ++k) {
                resultImage[i][j][k] = images[first][i][j][k];
            }
        }
    }
    //Fill first quadrant with second image
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                resultImage[i][j][k] = images[second][i][j-129][k];
            }
        }
    }
    //Fill third quadrant with third image
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            for (int k = 0; k < 3; ++k) {
                resultImage[i][j][k] = images[third][i-129][j][k];
            }
        }
    }
    //Fill fourth quadrant with fourth image
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                resultImage[i][j][k] = images[fourth][i-129][j-129][k];
            }
        }
    }
    //Apply effects to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }

}
/**
 * Blur Image Filter
 */
void blurImage(){
    //Applying blur using a blur box kernel of size 9 (9x9)
    int blurBoxSize =9;
    vector<vector<double>>blurBox(blurBoxSize,vector<double>(blurBoxSize,1));
    int offset = (blurBoxSize-1)/2;
    double sum = 0.0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++) {
                for (int y = 0; y < blurBoxSize; y++) {
                    for (int x = 0; x < blurBoxSize; x++) {
                        //Multiplying each pixel in blur box with its opposite in original image
                        sum += blurBox[y][x] * (double) image[i - offset + y][j - offset + x][k];
                    }
                }
                resultImage[i][j][k]=sum/81;
                sum = 0;
            }

        }
    }
    //Applying effects to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k] = resultImage[i][j][k];
            }
        }
    }
}