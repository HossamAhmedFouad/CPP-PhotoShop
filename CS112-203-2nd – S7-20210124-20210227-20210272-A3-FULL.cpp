// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd–S7-20210124-20210272-20210227-A3-Part2.cpp
// Last Modification Date: 20/04/2022
// Author1 and ID and Group: Hossam Ahmed Fouad 20210124 Group A
// Author2 and ID and Group: Omar Baddour       20210272 Group A
// Author3 and ID and Group: Abdelrahman Atef   20210227 Group A
// Teaching Assistant: Eng. Mahmoud
// Purpose:Applies different filters to images

#include <iostream>
#include "bmplib.h"
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char resultImage[SIZE][SIZE];
int sobelX[3][3] = {{-1,0,1},{-2,0,2}, {-1,0,1}};
int sobelY[3][3] = {{1,2,1},{0,0,0}, {-1,-2,-1}};
vector<vector<int>>image1(SIZE,vector<int>(SIZE));
vector<vector<int>>image2(SIZE,vector<int>(SIZE));
vector<vector<int>>image3(SIZE,vector<int>(SIZE));
vector<vector<int>>image4(SIZE,vector<int>(SIZE));


/**
 * Basic Functions
 */

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


/**
 * FILTERS
 */

/**
 * Black And White Filter
 */

void blackAndWhite(){
    //Calculating average
    int average =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            average+=image[i][j];
        }
    }
    average = average / (SIZE*SIZE);
    //if pixel greater than or equal average make it full brightness
    //if pixel less than average make it dark
    for (int i = 0; i < SIZE; i++) {
        for(int j =0; j<SIZE;j++){
            if(image[i][j]>= average){
                image[i][j]=255;
            } else{
                image[i][j]=0;
            }
        }
    }
}

/**
* Invert Image
*/

void invertImage(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            //invert each bit in the pixels
            image[i][j] ^= 0xFF  ;
        }
    }
}

/**
* Merge Images
*/

void mergeImage(){
    //Take second image to be merged
    unsigned char imageMerge[SIZE][SIZE];
    cout<<"Please enter second image to load: ";
    char file_name[100];
    //get file
    cin>>file_name;
    cout<<endl;
    strcat(file_name,".bmp");
    readGSBMP(file_name,imageMerge);

    //take average of pixel brightness between the two images
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = (image[i][j]+imageMerge[i][j])/2;
        }
    }
}

/**
* Flip Images
*/

void flipImage(){
    //take flip option from user
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
    //if image to be flipped horizontally, apply following equation
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image2[i][j] = image[SIZE-1-i][j];
            }
        }
    //if image to be flipped vertically, apply following equation
    }else if(choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image2[i][j] = image[i][SIZE-1-j];
            }
        }
    }
    //modify original image to be saved
    for (int x=0 ; x < SIZE; x++){
        for (int y=0 ; y < SIZE; y++){
            image[x][y] = image2[x][y];
        }
    }
}

/**
* Rotate Images
*/

void rotateImage(){
    // take rotation degree from user
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
    //if rotation degree is 90, apply the following equation
    if(rotation_degree == 1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image2[i][j] = image[SIZE-1-j][i];
            }
        }

    //if rotation degree is 180, apply the following equation
    }else if(rotation_degree==2){

        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                image2[i][j] = image[SIZE-1-i][SIZE-1-j];
            }
        }
    //if rotation degree is 270, apply the following equation
    }else if(rotation_degree==3){
        for(int i=0;i<SIZE;i++){
            for(int  j =0;j<SIZE;j++){
                image2[i][j] = image[j][SIZE-1-i];
            }
        }

    }
    //modify back original image
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            image[i][j] = image2[i][j];
        }
    }
}

/**
* Darken and Lighten Images
*/
void darkenAndLightenImage(){
    //calculate average brightness
    int average{0};
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            average+= image[i][j];
        }
    }
    average = average / (SIZE*SIZE);
    //take option from user
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
    //if option is to lighten, apply following equation
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j] += (255-image[i][j])/2;
            }
        }
    //if option is to darken, apply following equation
    }else if (choice==2){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j] -= (image[i][j])/2;
            }
        }
    }
}

/**
 * Detect Image Edges
 */
void detectEdge(){
    double sumX =0;
    double sumY =0;
    double result =0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int y=0;y<3;y++){
                for(int x=0;x<3;x++){
                    //apply sobel kernel(3x3) to each pixel in both x and y directions
                    //to detect extreme changes in value that satisfies the existence of an edge
                    sumX += sobelX[y][x] * image[i-1+y][j-1+x];
                    sumY += sobelY[y][x] * image[i-1+y][j-1+x];
                }
            }
            //Take the square root of the sum of the square of the two directions
            result = sqrt(pow(sumX,2)+ pow(sumY,2));
            if(result >= 120){
                resultImage[i][j] = 255;
            } else{
                resultImage[i][j] = 0;
            }
            sumX = 0;
            sumY = 0;
        }
    }
    //Invert each pixel color to make the edges black and background white
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            resultImage[i][j] ^= 0xFF;
        }
    }
    //Apply new results to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = resultImage[i][j];
        }
    }
}

/**
 * Enlarge Image
 */
void enlargeImage(){

    //Cutting the image into 4 quadrants

    //first quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            image1[i][j] = image[i][j];
        }
    }
    //second quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            image2[i][j - 129] = image[i][j];
        }
    }
    //third quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            image3[i - 129][j] = image[i][j];
        }
    }
    //fourth quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            image4[i - 129][j - 129] = image[i][j];
        }
    }
    //Take from user choice to enlarge which quadrant
    cout << "Please select which quarter you would like to enlarge" << endl;
    cout << "1-First Quarter" << endl;
    cout << "2-Second Quarter" << endl;
    cout << "3-Third Quarter" << endl;
    cout << "4-Fourth Quarter" << endl;
    cout << "->";
    int choice;
    cin >> choice;
    cout << endl;
    //enlarging quadrants by doubling the distance between each pixel and filling spaces with average

    //enlarge the first quadrant
    if (choice == 1) {
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                resultImage[0 + 2 * i][0 + 2 * j] = image1[i][j];
            }
        }
    //enlarge the second quadrant
    }else if(choice == 2){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                resultImage[0 + 2 * i][0 + 2 * j] = image2[i][j];
            }
        }
    //enlarge the third quadrant
    }else if(choice==3){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                resultImage[0 + 2 * i][0 + 2 * j] = image3[i][j];
            }
        }
    //enlarge the fourth quadrant
    }else if(choice==4){
        for (int i = 1; i < 128; i++) {
            for (int j = 1; j < 128; j++) {
                resultImage[0 + 2 * i][0 + 2 * j] = image4[i][j];
            }
        }

    }else{
        cout<<"Wrong Input"<<endl;
    }

    //Checking for neighbouring pixels on horizontal axis to take average for middle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (resultImage[i][j] == 0) {
                if (resultImage[i][j - 1] != 0 && resultImage[i][j + 1] != 0) {
                    resultImage[i][j] = (resultImage[i][j + 1] + resultImage[i][j - 1]) / 2;

                }
            }
        }
    }
    // checking for neighbouring pixels on vertical axis to take average for middle
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(resultImage[i][j]==0){
                resultImage[i][j] = (resultImage[i-1][j]+resultImage[i+1][j])/2;
            }
        }
    }
    // applying changes to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = resultImage[i][j];
        }
    }
}

/**
 * Shrink Image
 */
void shrinkImage(){
    // Take ratio of shrink from user
    cout<<"Please choose ratio to shrink to"<<endl;
    cout<<"1- 1/2"<<endl;
    cout<<"2- 1/3"<<endl;
    cout<<"3- 1/4"<<endl;
    cout<<"->";
    int choice{0};
    cin>>choice;
    cout<<endl;
    // Make the background of result image is white
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            resultImage[i][j] = 255;
        }
    }
    //Shrink with a ratio of 1/2 -> reduce distance between pixels by a half
    if(choice==1){
        for(int i=0;i<SIZE/2;i++){
            for(int j=0;j<SIZE/2;j++){
                resultImage[i][j] = image[2*i][2*j];
            }
        }
    //Shrink with a ratio of 1/3 -> reduce distance between pixels by a third
    }else if(choice==2){
        for(int i=0;i<SIZE/3;i++){
            for(int j=0;j<SIZE/3;j++){
                resultImage[i][j] = image[3*i][3*j];
            }
        }
    //Shrink with a ratio of 1/4 -> reduce distance between pixels by a quarter
    }else if(choice==3){
        for(int i=0;i<SIZE/4;i++){
            for(int j=0;j<SIZE/4;j++){
                resultImage[i][j] = image[4*i][4*j];
            }
        }
    }
    //Apply changes to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = resultImage[i][j];
        }
    }
}

/**
 * Mirror Half Image
 */

void mirrorImage() {
    // Take choice of which half side of the image to be mirrored
    cout << "Please select which part of image you would like to mirror:" << endl;
    cout << "1- Left 1/2" << endl;
    cout << "2- Right 1/2" << endl;
    cout << "3- Upper 1/2" << endl;
    cout << "4- Lower 1/2" << endl;
    cout << "->";
    int choice{0};
    cin >> choice;
    cout << endl;
    //Mirror left half using following equation
    if (choice == 1) {
        int counter = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 128; j < SIZE; j++) {
                image[i][j] = image[i][j - counter];
                counter += 2;
            }
            counter = 0;
        }
        //Mirror Right Half using following equation
    } else if (choice == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][SIZE - 1 - j];
            }
        }
        //Mirror upper half using following equation
    } else if (choice == 3) {
        int counter = 0;
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i - counter][j];

            }
            counter += 2;
        }
        //Mirror lower half using following equation
    } else if (choice == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[SIZE - 1 - i][j];
            }
        }
    }
}

/**
 * Shuffle Image
 */

void shuffleImage(){
    //Cutting the image into four quadrants

    //First Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            image1[i][j] = image[i][j];
        }
    }
    //Second Quadrant
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            image2[i][j - 129] = image[i][j];
        }
    }
    //Third Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            image3[i - 129][j] = image[i][j];
        }
    }
    //Fourth Quadrant
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            image4[i - 129][j - 129] = image[i][j];
        }
    }
    //A 3D vector that will hold 2D images
    vector<vector<vector<int>>>images = {{{}},image1,image2,image3,image4};

    //The variables that will hold which sequence the user will want to shuffle
    int first{0},second{0},third{0},fourth{0};

    cout<<"Please enter sequence of shuffle numbers separated by a space"<<endl;
    cin>>first>>second>>third>>fourth;

    //Start filling first quadrant with selected image at index first
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            resultImage[i][j] = images[first][i][j];
        }
    }
    //Start filling second quadrant with selected image at index second
    for (int i = 0; i <= 128; i++) {
        for (int j = 129; j < SIZE; j++) {
            resultImage[i][j] = images[second][i][j-129];
        }
    }
    //Start filling third quadrant with selected image at index third
    for (int i = 129; i < SIZE; i++) {
        for (int j = 0; j <= 128; j++) {
            resultImage[i][j] = images[third][i-129][j];
        }
    }
    //Start filling fourth quadrant with selected image at index fourth
    for (int i = 129; i < SIZE; i++) {
        for (int j = 129; j < SIZE; j++) {
            resultImage[i][j] = images[fourth][i-129][j-129];
        }
    }
    //Apply changes to original image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = resultImage[i][j];
        }
    }
}

/**
 *  Blur Image
 */

void blurImage(){
    //Create a box blur to apply to image with size of 7
    int boxSize = 7;
    vector<vector<double>>blurBox(boxSize,vector<double>(boxSize,1));

    //Calculate the offset of the index to be the center pixel in the box with respect to size
    int offset = (boxSize-1)/2;
    double sum = 0.0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int y=0;y<boxSize;y++){
                for(int x=0;x<boxSize;x++){
                    //Apply the box blur pixels to its matching pixel on the image
                    sum += blurBox[y][x] * (double)image[i-offset+y][j-offset+x];
                }
            }

            resultImage[i][j]=sum/49;
            sum = 0;
        }
    }
    //Applying changes to original Image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = resultImage[i][j];
        }
    }
}
// show menu of options to user

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
            darkenAndLightenImage();
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