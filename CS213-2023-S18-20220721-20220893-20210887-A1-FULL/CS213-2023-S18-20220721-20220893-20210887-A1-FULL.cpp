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
unsigned char yampa[SIZE][SIZE];
unsigned char zoomed[SIZE][SIZE];
unsigned char skew[SIZE][SIZE];
unsigned char mirror[SIZE][SIZE];

// Functions for loading, filtering and saving a gray scale image
void darker();
void lighter();
void loadImage();
void saveImage();
void blackWhite();
void mergeImages();
void load2Images();
void invertImage();
void flipVertical();
void flipHorizontal();
void rotate90Degree();
void rotate180Degree();
void rotate270Degree();
void detectImageEdges();
void SaveRotatedImage();
void shrinkImageBy2();
void shrinkImageBy3();
void shrinkImageBy4();
void shuffleQuarters(char array[], int size);
void saveShuffledImage();
void saveShrinkedImage();
void zoomQuarter1();
void zoomQuarter2();
void zoomQuarter3();
void zoomQuarter4();
void saveZoomedImage();
void skewImageRight();
void saveSkewedImage();
void leftMirrorImage();
void rightMirrorImage();
void topMirrorImage();
void bottomMirrorImage();
void saveMirrorImage();

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
        cout<<"7. Detect Image Edges Filter\n";
        cout<<"8. Enlarge Image Filter\n";
        cout<<"9. Shrink Image Filter\n";
        cout<<"a. Mirror Image 1/2 Filter\n";
        cout<<"b. Shuffle Image Filter\n";
        // cout<<"c. Blur Image Filter\n";
        // cout<<"d. Crop Image Filter\n";
        // cout<<"e. Skew Image Right Filter\n";
        // cout<<"f. Skew Image Up Filter\n";
        cout<<"0. Exit\n\n";
        cout<<"Choice > > > ";

        cin>>choice;
        cout<<"\n";

        // Check if the selected choice is 1, then apply a black and white filter.
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
        // Check if the selected choice is 2, then apply the invert filter.
        else if (choice == '2'){
            cout<<"Chosen filter > Invert Image Filter\n";
            char saveImg;
            loadImage();
            invertImage();
            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveImage();
                cout<<"A modified version of the image is saved in the current working directory.\n";
            }
        }
        // Check if the selected choice is 3, then apply merge images filter.
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
        // Check if the selected choice is 4, then apply a flip image filter.
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
        // Check if the selected choice is 5, then apply a darker or lighter filter.
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
        // Checks if the selected choice is 6, then apply a rotate image filter.
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
        // Checks if the selected choice is 7, then apply detect image edges filter.
        else if (choice == '7'){
            cout<<"Chosen filter > Detect Image Edges Filter\n";
            char saveImg;
            loadImage();
            detectImageEdges();
            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveImage();
                cout<<"A modified version of the image is saved in the current working directory.\n";
            }
        }
        // Checks if the selected choice is 8, then apply enlarge image filter.
        else if (choice == '8'){
            cout<<"Chosen filter > Enlarge Image Filter\n";
            char saveImg, quarter;
            loadImage();
            cout<<"Choose the quarter to enlarge (1, 2, 3 or 4): ";
            cin>>quarter;

            if (quarter == '1'){
                zoomQuarter1();
            } else if (quarter == '2'){
                zoomQuarter2();
            } else if (quarter == '3'){
                zoomQuarter3();
            } else if (quarter == '4'){
                zoomQuarter4();
            } else{
                cout<<"\nPlease enter a valid choose!\n";
            }

            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveZoomedImage();
                cout<<"A modified version of the image is saved in the current working directory.\n";
            }
        }
        // Checks if the selected choice is 9, then apply shrink image filter.
        else if (choice == '9'){
            cout<<"Chosen filter > Shrink Image Filter\n";
            char saveImg;
            string dim;
            loadImage();
            cout<<"Choose the dimension (1/2, 1/3 or 1/4): ";
            cin>>dim;

            if (dim == "1/2"){
                shrinkImageBy2();
            } else if (dim == "1/3"){
                shrinkImageBy3();
            } else if (dim == "1/4"){
                shrinkImageBy4();
            } else{
                cout<<"\nPlease enter a valid choose!\n";
            }

            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveShrinkedImage();
                cout<<"A modified version of the image is saved in the current working directory.\n";
            }
        }
        // Checks if the selected choice is b, then apply shuffle image filter.
        else if (choice == 'b'){
            cout<<"Chosen filter > Shuffle Image Filter\n";
            loadImage();
            char saveImg;
            string order;
            int size = 4;
            char array[size];
            cout<<"Enter your preferred order of quarters (1-4): ";
            cin>>order;
            for (int i=0; i<size; i++){
                array[i]=order[i];
            }

            shuffleQuarters(array, size);

            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveShuffledImage();
                cout<<"A modified version of the image is saved in the current working directory.\n";
            }
        }
        // Checks if the selected choice is a, then apply mirror image filter.
        else if (choice == 'a'){
            cout<<"Chosen filter > Mirror Image 1/2 Filter\n";
            loadImage();
            char saveImg;
            string start;
            cout<<"Mirror the image Left (LT), Right (RT), Upper (UR) or Lower (LR): ";
            cin>>start;
            if (start == "LT" || start == "lt"){
                leftMirrorImage();
            } else if (start == "RT" || start == "rt"){
                rightMirrorImage();
            } else if (start == "UR" || start == "ur"){
                topMirrorImage();
            } else if (start == "LR" || start == "lr"){
                bottomMirrorImage();
            } else {
                cout<<"Please enter a valid choose!\n";
            }
            cout<<"The filter has been applied to the image!\nDo you want to save the filtered image? ( Y or N ): ";
            cin>>saveImg;
            if (saveImg == 'Y' || saveImg == 'y'){
                saveMirrorImage();
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

void saveShuffledImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, yampa);
}

void saveShrinkedImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, yampa);
}

void saveZoomedImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, zoomed);
}

void saveSkewedImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, skew);
}

void saveMirrorImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, mirror);
}

// function for turning a gray scale image to black and white
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

// function for inverting every pixel in a gray scale image
void invertImage() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
}

// function for merging two gray scale images
void mergeImages() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2 + image2[i][j]/2;
        }
    }
}

// function for flipping a gray scale image vertically
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

// function for flipping a gray scale image horizontally
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

// function for rotating a gray scale image 90 degrees
void rotate90Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[j][SIZE - 1 - i] = image[i][j];
        }
    }
}

// function for rotating a gray scale image 180 degrees
void rotate180Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - i][SIZE - 1 - j] = image[i][j];
        }
    }
}

// function for rotating a gray scale image 270 degrees
void rotate270Degree() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - j][i] = image[i][j];
        }
    }
}

// function for detecting a gray scale image edges
void detectImageEdges(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (image[i][j] > 127 && image[i+1][j+1] < 127 || image[i][j] < 127 && image[i+1][j+1] > 127){
                image[i][j] = 0;
            } else {
                image[i][j] = 255;
            }
        }
    }
}

// function for turning a gray scale image 50% darker
void darker(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2;
        }
    }
}

// function for turning a gray scale image 50% lighter
void lighter(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = (image[i][j]/2) + 127;
        }
    }
}

// function for shrinking the image 1/2
void shrinkImageBy2(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            yampa[i][j] = 255;
        }
    }
    for(int i=0; i<SIZE/2; i++){
        for(int j=0; j<SIZE/2; j++){
            int SIZE1 = i*2;
            int SIZE2 = j*2;
            yampa[i][j] = image[SIZE1][SIZE2];
        }
    }
}

// function for shrinking image 1/3
void shrinkImageBy3(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            yampa[i][j] = 255;
        }
    }
    for(int i=0; i<SIZE/3; i++){
        for(int j=0; j<SIZE/3; j++){
            int SIZE1 = i*3;
            int SIZE2 = j*3;
            yampa[i][j] = image[SIZE1][SIZE2];
        }
    }
}

// function for shrinking image 1/4
void shrinkImageBy4(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            yampa[i][j] = 255;
        }
    }
    for(int i=0; i<SIZE/4; i++){
        for(int j=0; j<SIZE/4; j++){
            int SIZE1 = i*4;
            int SIZE2 = j*4;
            yampa[i][j] = image[SIZE1][SIZE2];
        }
    }
}

// function shuffling the order of image according to user's input
void shuffleQuarters(char array[], int size){
    for(int i=0; i<size; i++){

    // Loops through the first index, and Checks if the first index is 0 then fills the first quarter according
    //to the number in the first index
        if (i==0){
            if (array[i]=='1'){
                int ii = 0;
                for(int i=0; i<SIZE/2; i++){ //first
                    int jj = 0;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='2'){
                int ii = 0;
                for(int i=0; i<SIZE/2; i++){ //second
                    int jj = 0;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='3'){
                int ii = 0;
                for(int i=SIZE/2; i<SIZE; i++){ //third
                    int jj = 0;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } 
            else if(array[i]=='4'){
                int ii = 0;
                for(int i=SIZE/2; i<SIZE; i++){ //fourth
                    int jj = 0;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            }


    // Loops through the second index, and Checks if the second index is 1 then fills the second quarter according
    //to the number in the second index
        } else if (i==1){
            if (array[i]=='1'){
                int ii = 0;
                for(int i=0; i<SIZE/2; i++){ //first
                    int jj = SIZE/2;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='2'){
                int ii = 0;
                for(int i=0; i<SIZE/2; i++){ //second
                    int jj = SIZE/2;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='3'){
                int ii = 0;
                for(int i=SIZE/2; i<SIZE; i++){ //third
                    int jj = SIZE/2;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } 
            else if(array[i]=='4'){
                int ii = 0;
                for(int i=SIZE/2; i<SIZE; i++){ //fourth
                    int jj = SIZE/2;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            }


    // Loops through the third index, and Checks if the third index is 2 then fills the third quarter according
    //to the number in the third index
        } else if (i==2){
            if (array[i]=='1'){
                int ii = SIZE/2;
                for(int i=0; i<SIZE/2; i++){ //first
                    int jj = 0;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='2'){
                int ii = SIZE/2;
                for(int i=0; i<SIZE/2; i++){ //second
                    int jj = 0;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='3'){
                int ii = SIZE/2;
                for(int i=SIZE/2; i<SIZE; i++){ //third
                    int jj = 0;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } 
            else if(array[i]=='4'){
                int ii = SIZE/2;
                for(int i=SIZE/2; i<SIZE; i++){ //fourth
                    int jj = 0;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            }


    // Loops through the fourth index, and Checks if the fourth index is 3 then fills the fourth quarter according
    //to the number in the fourth index
        } else if (i==3){
            if (array[i]=='1'){
                int ii = SIZE/2;
                for(int i=0; i<SIZE/2; i++){ //first
                    int jj = SIZE/2;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='2'){
                int ii = SIZE/2;
                for(int i=0; i<SIZE/2; i++){ //second
                    int jj = SIZE/2;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            } else if(array[i]=='3'){
                int ii = SIZE/2;
                for(int i=SIZE/2; i<SIZE; i++){ //third
                    int jj = SIZE/2;
                    for(int j=0; j<SIZE/2; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            }
            else if(array[i]=='4'){
                int ii = SIZE/2;
                for(int i=SIZE/2; i<SIZE; i++){ //fourth
                    int jj = SIZE/2;
                    for(int j=SIZE/2; j<SIZE; j++){
                        yampa[ii][jj] = image[i][j];
                        jj++;
                    }
                    ii++;
                }
            }
        }
    }
}




// Function for zooming the first quarter of the image
void zoomQuarter1(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int SIZE1 = i/2;
            int SIZE2 = j/2;
            zoomed[i][j] = image[SIZE1][SIZE2];
        }
    }
}


// Function for zooming the second quarter of the image
void zoomQuarter2(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int SIZE1 = 0 + i/2;
            int SIZE2 = 127 + j/2;
            zoomed[i][j] = image[SIZE1][SIZE2];
        }
    }
}


// Function for zooming the third quarter of the image
void zoomQuarter3(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int SIZE1 = 127 + i/2;
            int SIZE2 = 0 + j/2;
            zoomed[i][j] = image[SIZE1][SIZE2];
        }
    }
}


// Function for zooming the fourth quarter of the image
void zoomQuarter4(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int SIZE1 = 127 + i/2;
            int SIZE2 = 127 + j/2;
            zoomed[i][j] = image[SIZE1][SIZE2];
        }
    }
}


// Function for skewing the image to the right
void skewImageRight(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            int SIZE1 = i;
            int SIZE2 = j + i;
            if (SIZE2 < SIZE){
                skew[i][j] = image[SIZE1][SIZE2];
            }
        }
    }
}


// Function for mirroring the image from the left
void leftMirrorImage(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE/2; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = 0;
    for(int i=0; i<SIZE; i++){
        int jj = SIZE-1;
        for(int j=0; j<SIZE/2; j++){
            mirror[ii][jj] = image[i][j];
            jj--;
        }
        ii++;
    }
}

// Function for mirroring the image from the right
void rightMirrorImage(){
    for(int i=0; i<SIZE; i++){
        for(int j=SIZE/2; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = 0;
    for(int i=0; i<SIZE; i++){
        int jj = 0;
        for(int j=SIZE-1; j>=SIZE/2; j--){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii++;
    }
}

// Function for mirroring the image from the top
void topMirrorImage(){
    for(int i=0; i<SIZE/2; i++){
        for(int j=0; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = SIZE-1;
    for(int i=0; i<SIZE/2; i++){
        int jj = 0;
        for(int j=0; j<SIZE; j++){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii--;
    }
}

// Function for mirroring the image from the bottom
void bottomMirrorImage(){
    for(int i=SIZE/2; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = SIZE/2;
    for(int i=SIZE/2; i<SIZE; i++){
        int jj = 0;
        for(int j=0; j<SIZE; j++){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii--;
    }
}