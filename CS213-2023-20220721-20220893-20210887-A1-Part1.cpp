                                                                                                                                                                                                                            /*
Names of the Team:
1. Tong Majok Kuc Akoon
   ID: 20220893
   Email: tongmajokss@gmail.com
2. Saeed Mudir Muhagir Ibrahim
   ID: 20210887
   Email: saeedmudir02@gmail.com
3. Diu Gach Deng Diu
   ID: 20220721
   Email: diugach72@gmail.com 
                                                                                                                                                                                                                            */
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char temp[SIZE][SIZE];

// Functions for loading, filtering and saving a gray scale image
void darker();
void lighter();
void loadImage();
void saveImage();
void blackWhite();
void mergeImages();
void load2Images();
void invertImages();
void flipVertical();
void flipHorizontal();
void rotate90Degree();
void rotate180Degree();
void rotate270Degree();
void SaveRotatedImage();

int main()
{
                                                                                                                                                                                                                            /*
This infinite loop continuous to run and displays choices for applying
the filters to a gray scale image as long as the user input is not 0,
if the input is 0, it will exit the loop and the program stop.
                                                                                                                                                                                                                            */
while (true){
    char choice;
    cout<<"\nGray Scale Image Editor Program\n";
    cout<<"Select a filter to apply to a gray scale image or 0 to exit:\n";
    cout<<"1. Black and White Image Filters\n";
    cout<<"2. Invert Image Filter\n";
    cout<<"3. Merge Images Filter\n";
    cout<<"4. Flip Image Filter\n";
    cout<<"5. Darken and Lighten Image Filters\n";
    cout<<"6. Rotate Image Filters\n";
    cout<<"0. Exit\n\n";
    cout<<"Choice > > > ";

    cin>>choice;
    cout<<"\n";

    // Check if the selected choice is 1, apply a black and white filter.
    if (choice == '1'){
        cout<<"Chosen filter > Black and White Image Filters\n";
        char saveImg;
        loadImage();
        blackWhite();
        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Check if the selected choice is 2, apply the invert filter.
    else if (choice == '2'){
        cout<<"Chosen filter > Invert Image Filter\n";
        char saveImg;
        loadImage();
        invertImages();
        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Check if the selected choice is 3, apply merge images filter.
    else if (choice == '3'){
        cout<<"Chosen filter > Merge Images Filter\n";
        char saveImg;
        load2Images();
        mergeImages();
        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Check if the selected choice is 4, apply a flip image filter.
    else if (choice == '4'){
        cout<<"Chosen filter > Flip Image Filter\n";
        char saveImg, flipImg;
        loadImage();
        cout<<"Do you want to flip it Horizontally or Vertically? (H or V): ";
        cin>>flipImg;
        if (flipImg == 'H' || flipImg == 'h'){
            flipHorizontal();
        } else if (flipImg == 'V' || flipImg == 'v'){
            flipVertical();
        }
        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Check if the selected choice is 5, apply a darker or lighter filter.
    else if (choice == '5'){
        cout<<"Chosen filter > Darken and Lighten Image Filters\n";
        char saveImg, dImg;
        loadImage();
        cout<<"Do you want to darken or lighten the image? (D or L): ";
        cin>>dImg;

        if (dImg == 'D' || dImg == 'd'){
            darker();
        } else if (dImg == 'L' || dImg == 'l'){
            lighter();
        }

        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Checks if the selected choice is 6, apply a rotate image filter.
    else if (choice == '6'){
        cout<<"Chosen filter > Rotate Image Filters\n";
        char saveImg;
        string theDegree;
        loadImage();
        cout<<"Do you want to rotate the image upto how many degrees? (90, 180, 270): ";
        cin>>theDegree;
        if (theDegree == "90"){
            rotate90Degree();
        } else if (theDegree == "180"){
            rotate180Degree();
        } else if (theDegree == "270"){
            rotate270Degree();
        }
        cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            SaveRotatedImage();
            cout<<"A modified version of the image is saved in the current working directory.\n";
        }
    }
    // Checks if the selected choice is 0, then exit.
    else if (choice == '0'){
        break;
    }
}

  return 0;
}

void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

void load2Images () {
   char imageFileName[100];
   char imageFileName2[100];

   // Get gray scale image file name
   cout << "Enter the source image file name 1: ";
   cin >> imageFileName;
   cout << "Enter the source image file name 2: ";
   cin >> imageFileName2;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   strcat (imageFileName2, ".bmp");
   readGSBMP(imageFileName, image);
   readGSBMP(imageFileName2, image2);
}

void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

void SaveRotatedImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, temp);
}

void blackWhite() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

void invertImages() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
}

void mergeImages() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2 + image2[i][j]/2;
        }
    }
}

void flipVertical() {
    const int ROWS = SIZE; const int COLS = SIZE;
    for (int i=0; i<ROWS/2; i++){
        for (int j=0; j<COLS; j++){
            unsigned char temP = image[i][j];
            image[i][j] = image[ROWS - i - 1][j];
            image[ROWS - i - 1][j] = temP;
        }
    }
}

void flipHorizontal() {
    const int ROWS = SIZE; const int COLS = SIZE;
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS/2; j++){
            unsigned char temP = image[i][j];
            image[i][j] = image[i][ROWS - j - 1];
            image[i][ROWS - j - 1] = temP;
        }
    }
}

void rotate90Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[j][SIZE - 1 - i] = image[i][j];
        }
    }
}

void rotate180Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - i][SIZE - 1 - j] = image[i][j];
        }
    }
}

void rotate270Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - j][i] = image[i][j];
        }
    }
}

void darker(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2;
        }
    }
}

void lighter(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = (image[i][j]/2) + 127;
        }
    }
}