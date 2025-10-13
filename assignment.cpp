/*
==============================================
file name : cs213_A1_part1_sec7_20240743_20240758_20242116
team members :
             - Esraa Ahmed Hassan     20240743   filter(1,4)
             - Jana Yahia Mostafa     20240758   filter(2,5)
             - Dalia Sami Abd El Aziz 20242116   filter(3,6)
Description:
This program applies different filters on an image.
The user can choose a filter from a menu.
==============================================
*/
#include <iostream>
#include "Image_Class.h"
#include<set>
using namespace std;

void convert_image(int c) {
    string t, s;
    cout << "Write name of the picture:\n";
    cin >> t;
    Image image(t);
    int y;
    
    switch (c) {
            
        case 1: // Grayscale
        {
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    unsigned int avg = 0;
                    for (int k = 0; k < image.channels; ++k) {
                        avg += image(i, j, k);
                    }
                    avg = avg / 3;
                    for (int k = 0; k < 3; ++k) {
                        image(i, j, k) = avg;
                    }
                }
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 2: // Black & White
        {
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    unsigned int avg = 0;
                    for (int k = 0; k < image.channels; ++k) {
                        avg += image(i, j, k);
                    }
                    avg = avg / 3;
                    for (int k = 0; k < 3; ++k) {
                        image(i, j, k) = avg;
                    }
                }
            }
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    for (int k = 0; k < image.channels; ++k) {
                        if (image(i, j, k) >= 128) image(i, j, k) = 255;
                        else image(i, j, k) = 0;
                    }
                }
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 3: // Invert
        {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        y = image(i, j, k);
                        image(i, j, k) = 255 - y;
                    }
                }
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 4: // Merge
        {
            cout << "Upload 2nd Image\n";
            string filename;
            cin >> filename;
            Image image2(filename);
            Image resized(image.width, image.height);
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    int x = (i * image2.width) / image.width;
                    int y = (j * image2.height) / image.height;
                    for (int k = 0; k < image.channels; k++) {
                        resized(i, j, k) = image2(x, y, k);
                    }
                }
            }
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        image(i, j, k) = (image(i, j, k) + resized(i, j, k)) / 2;
                    }
                }
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 5: // Flip
        {
            Image test = image;
            int x;
            cout << "#1 Horizontal / #2 Vertical" << endl;
            cin >> x;
            if (x == 1) {
                for (int i = image.width - 1; i >= 0; i--) {
                    for (int j = 0; j < image.height; j++) {
                        for (int k = 0; k < image.channels; k++) {
                            test(image.width - 1 - i, j, k) = image(i, j, k);
                        }
                    }
                }
            } else if (x == 2) {
                for (int i = 0; i < image.width; i++) {
                    for (int j = image.height - 1; j >= 0; j--) {
                        for (int k = 0; k < image.channels; k++) {
                            test(i, image.height - 1 - j, k) = image(i, j, k);
                        }
                    }
                }
            }
            image = test;
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 6: // Rotate
        {
            cout << "Degree of rotate (90, 180, 270)\n";
            int x;
            cin >> x;
            if (x == 90) {
                Image img(image.height, image.width);
                for (int i = 0; i < image.width; i++) {
                    for (int j = 0; j < image.height; j++) {
                        for (int k = 0; k < image.channels; k++) {
                            img(image.height - 1 - j, i, k) = image(i, j, k);
                        }
                    }
                }
                image = img;
            } else if (x == 180) {
                Image img(image.height, image.width);
                for (int i = 0; i < image.width; i++) {
                    for (int j = 0; j < image.height; j++) {
                        for (int k = 0; k < image.channels; k++) {
                            img(image.height - 1 - j, i, k) = image(i, j, k);
                        }
                    }
                }
                Image img2(img.height, img.width);
                for (int i = 0; i < img.width; i++) {
                    for (int j = 0; j < img.height; j++) {
                        for (int k = 0; k < img.channels; k++) {
                            img2(img.height - 1 - j, i, k) = img(i, j, k);
                        }
                    }
                }
                image = img2;
            } else if (x == 270) {
                Image img(image.height, image.width);
                for (int i = 0; i < image.width; i++) {
                    for (int j = 0; j < image.height; j++) {
                        for (int k = 0; k < image.channels; k++) {
                            img(j, image.width - 1 - i, k) = image(i, j, k);
                        }
                    }
                }
                image = img;
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 7: // Darken and Lighten
        {
            int x;
            cout << "#1 Darken / #2 Lighten" << endl;
            cin >> x;
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        int value = image(i, j, k);
                        if (x == 1) {
                            value = value * 0.5;
                        } else if (x == 2) {
                            value = value * 1.5;
                        }
                        if (value > 255) value = 255;
                        if (value < 0) value = 0;
                        image(i, j, k) = value;
                    }
                }
            }
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 8: // Crop
        {
            int x, y, w, h;
            cout << "Enter starting point x and y:\n";
            cin >> x >> y;
            cout << "Enter width and height to crop:\n";
            cin >> w >> h;
            if (x + w > image.width || y + h > image.height) {
                cout << "Invalid crop size!\n";
                break;
            }
            Image newimg(w, h);
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        newimg(i, j, k) = image(x + i, y + j, k);
                    }
                }
            }
            image = newimg;
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
        case 9: // frame
        {
            cout<<"How do you want to Frame ?\n"<<"1- purred\n"<<"2-baster\n";
            string f;
            cin>>f;
            if(f=="baster"){
                for(int i=0;i<image.width;i++)
                {
                    for(int j=0;j<image.height;j++)
                    {
                        
                        for(int k=0;k<image.channels;k++)
                        {
                            if(i==0){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==0){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==image.height -1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==image.width -1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==image.height -2){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==image.width -2){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                        }
                    }
                }
                
            }
            
            else {
                for(int i=0;i<image.width;i++)
                {
                    for(int j=0;j<image.height;j++)
                    {
                        
                        for(int k=0;k<image.channels;k++)
                        {
                            if(i==0){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==0){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==image.height -1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==image.width -1){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            
                            if(i==1 && (j!=0 && j!=image.height-1)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(j==1 && (i!=0 && j!=image.width-1)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(j==image.height -2 && (i!=0 && i!=image.width-1)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(i==image.width -2 && (j!=0 && j!=image.height-1)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(i==2&& (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(j==2  && (i!=0 && i!=image.width-1  && i!=1 && i!=image.width-2 )){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(j==image.height -3 && (i!=0 && i!=image.width-1 && i!=1  && i!=image.width-2 )){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            
                            if(i==image.width -3 && (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2)){
                                image(i,j,0)=0;
                                image(i,j,1)=0;
                                image(i,j,2)=0;
                            }
                            if(i==3 && (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2 && j!=2 && j!=image.height-3 )){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==3 && (i!=0 && i!=image.width-1 && i!=1 && i!=image.width-2 && i!=2 && i!=image.width-3  )){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(j==image.height -4  && (i!=0 && i!=image.width-1 && i!=1 && i!=image.width-2 && i!=2 && i!=image.width-3  )){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==image.width -4 && (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2 && j!=2 && j!=image.height-3 )){
                                image(i,j,0)=255;
                                image(i,j,1)=255;
                                image(i,j,2)=255;
                            }
                            if(i==4 && (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2 && j!=2 && j!=image.height-3 && j!=3 && j!=image.height-4)){
                                
                                image(i,j,2)=255;
                            }
                            if(j==4 && (i!=0 && i!=image.width-1 && i!=1 && i!=image.width-2 && i!=2 && i!=image.width-3 && i!=3 && i!=image.width-4 )){
                                
                                image(i,j,2)=255;
                            }
                            if(j==image.height -5  && (i!=0 && i!=image.width-1 && i!=1 && i!=image.width-2 && i!=2 && i!=image.width-3  && i!=3 && i!=image.width-4 )){
                                
                                image(i,j,2)=255;
                            }
                            if(i==image.width -5 && (j!=0 && j!=image.height-1 && j!=1 && j!=image.height-2 && j!=2 && j!=image.height-3 && j!=3 && j!=image.height-4 )){
                                
                                image(i,j,2)=255;
                            }
                        }
                    }
                }
            }
            cout<<"do you want to save image (yes or no) \n";
            cin>>s;
            if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
                
                cin >> t;
                
                image.saveImage(t);
                break;
            }
            
        }
        case 10: // Detect Image Edges
        {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    unsigned int avg = 0;
                    for (int k = 0; k < image.channels; k++) {
                        avg += image(i, j, k);
                    }
                    avg = avg / 3;
                    for (int k = 0; k < 3; k++) {
                        image(i, j, k) = avg;
                    }
                }
            }
            Image edgeImg = image;
            for (int i = 0; i < image.width - 1; i++) {
                for (int j = 0; j < image.height - 1; j++) {
                    int current = image(i, j, 0);
                    int right = image(i + 1, j, 0);
                    int down = image(i, j + 1, 0);
                    int diff = abs(current - right) + abs(current - down);
                    int edgeValue = (diff > 50) ? 0 : 255;
                    for (int k = 0; k < 3; k++) {
                        edgeImg(i, j, k) = edgeValue;
                    }
                }
            }
            image = edgeImg;
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
            
        case 11: // Resize
        {
            int w, h;
            cout << "Enter new width:\n";
            cin >> w;
            cout << "Enter new height:\n";
            cin >> h;
            if (w <= 0 || h <= 0) {
                cout << "Invalid size\n";
                break;
            }
            Image newimg(w, h);
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    int x = (i * image.width) / w;
                    int y = (j * image.height) / h;
                    for (int k = 0; k < image.channels; k++) {
                        newimg(i, j, k) = image(x, y, k);
                    }
                }
            }
            image = newimg;
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
        case 12: //Blur
        {
            
            int g;
            cout<<" enter number of redius for doing blur :\n";
            cin>>g;
            
            for(int i=0;i<image.width;i++)
            {
                
                for(int j=0;j<image.height;j++)
                {
                    int p=0;
                    int o=0;
                    int u=0;
                    int a=0;
                    
                    int b=i-g;
                    int c=i+g;
                    if(b<0)
                    {
                        b=0;
                    }
                    if(c>=image.width){
                        c=image.width-1;
                    }
                    int l=j-g;
                    int v=j+g;
                    if(l<0)
                    {
                        l=0;
                    }
                    if(v>=image.height){
                        v=image.height-1;
                    }
                    for(int k=b;k<=c;k++)
                    {
                        
                        for(int q=l;q<=v;q++)
                        {
                            p+=image(k,q,0);
                            o+=image(k,q,1);
                            u+=image(k,q,2);
                            a++;
                        }
                        
                    }
                    image(i,j,0)=p/a;
                    image(i,j,1)=o/a;
                    image(i,j,2)=u/a;
                }
                
            }
            cout<<"do you want to save image (yes or no) \n";
            cin>>s;
            if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
                
                cin >> t;
                
                image.saveImage(t);
                break;
            }
        }
            
        case 13: // Wano Sunlight Fix
        {
            cout << "Fixing sunlight like Wano filter..." << endl;
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    int r = image(i, j, 0);
                    int g = image(i, j, 1);
                    int b = image(i, j, 2);
                    
                    r = r * 1.3 + 20;
                    g = g * 1.15 + 10;
                    b = b * 0.9;
                    
                    if (r > 255) r = 255;
                    if (g > 255) g = 255;
                    if (b > 255) b = 255;
                    
                    image(i, j, 0) = r;
                    image(i, j, 1) = g;
                    image(i, j, 2) = b;
                }
            }
            
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
        case 14: // Skew Image
        {
            double degree;
            cout << "Enter degree of vertical skew:\n";
            cin >> degree;

            double rad = degree * 3.14159265 / 180.0;
            int shiftMax = (int)(tan(rad) * image.height);

            Image newimg(image.width + abs(shiftMax), image.height);

            for (int j = 0; j < image.height; j++) {
                int shift = (int)(tan(rad) * j);
                for (int i = 0; i < image.width; i++) {
                    for (int k = 0; k < image.channels; k++) {
                        int newX = i + shift;
                        if (newX >= 0 && newX < newimg.width) {
                            newimg(newX, j, k) = image(i, j, k);
                        }
                    }
                }
            }

            image = newimg;

            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n";
                cin >> t;
                image.saveImage(t);
            }
            break;
        }
        case 15: //purple at night
        {
            
            for(int i=0;i<image.width ;i++){
                
                for(int j=0;j<image.height ;j++)
                {
                    
                    
                    image(i,j,1)=0 ;
                    
                }
                
                
            }
            cout<<"do you want to save image (yes or no) \n";
            cin>>s;
            if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
                
                cin >> t;
                
                image.saveImage(t);
            }
            break;
        }
                 case 16:
        {

         
            for(int i=0;i<image.width;i++)
            {
                
                for(int j=0;j<image.height;j++)
                {
                    int p=0;
                    int o=0;
                    int u=0;
                    int a=0;
                    
                    int b=i-3;
                    int c=i+3;
                    if(b<0)
                    {
                        b=0;
                    }
                    if(c>=image.width){
                        c=image.width-1;
                    }
                    int l=j-3;
                    int v=j+3;
                    if(l<0)
                    {
                        l=0;
                    }
                    if(v>=image.height){
                        v=image.height-1;
                    }
                    for(int k=b;k<=c;k++)
                    {
                        
                        for(int q=l;q<=v;q++)
                        {
                            p+=image(k,q,0);
                            o+=image(k,q,1);
                            u+=image(k,q,2);
                            a++;
                        }
                    
                     
                    }
                    image(i,j,0)=p/a;
                    image(i,j,1)=o/a;
                    image(i,j,2)=u/a;
             

                }
                
            }
             for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                   
                     image(i, j, 1)*=.8;
              
                  
                }
            }
           cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
               
                 image.saveImage(t);
       
            
      }
        break;    
        } 
        case 17:
        {
           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               for(int k=0;k<image.channels ;k++)
               {
              
              if( image(i,j,k)==0)  image(i,j,k)=255;
                 if( image(i,j,k)==255)  image(i,j,k)=  image(i,j,0);
                 image(i,j,1)=255-image(i,j,1);
                 image(i,j,2)=255-image(i,j,2);
                  image(i,j,0)=255;
               }

             }
        
          }
               cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
               
                 image.saveImage(t);
            
      }
         break;
        }
      
   
        case 18:
        {
            int u=0;
           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j+=3)
             {
               for(int k=0;k<image.channels ;k++)
               {
          
              image(i,j,k)=0;
            
            
             
                if(( image(u,j,0)*1.2)<255) image(u,j,0)*=1.2;
             else image(u,j,0)=255;
              if(( image(u,j,1)*1.2)<255) image(u,j,1)*=1.2;
             else image(u,j,1)=255;
               if(( image(u,j,2)*1.2)<255) image(u,j,2)*=1.2;
             else image(u,j,2)=255;

               }
             
             }
           u++;
          }
               cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
               
                 image.saveImage(t);
            
      }
         break;
        }
       /*
       case 18:   //tv onther code
        {
             for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j+=3)
             {
               for(int k=0;k<image.channels ;k++)
               {
                image(i,j,0)*=.272;
                image(i,j,1)*=.534;
                image(i,j,2)*=.131;
               }
            }
        }
          cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
               
                 image.saveImage(t);
               
            
        }
        break;
    }
       */ 
      case 19:
        { 
            cout<<"1#most  2#least\n";
            int g;
            cin>>g;
            if(g==2)
            {
 for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j+=3)
             {
               for(int k=0;k<image.channels ;k++)
               {
                image(i,j,0)=((image(i,j,0)-128)*.7)+128;
                image(i,j,1)=((image(i,j,1)-128)*.7)+128;
                image(i,j,2)=((image(i,j,2)-128)*.7)+128;
               }
            }
        }
          
            }
                  if(g==1)
            {
 for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j+=3)
             {
               for(int k=0;k<image.channels ;k++)
               {
                image(i,j,0)=((image(i,j,0)-128)*1.4)+128;
                image(i,j,1)=((image(i,j,1)-128)*1.4)+128;
                image(i,j,2)=((image(i,j,2)-128)*1.4)+128;
               }
            }
        }
          
            }
           cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
               
                 image.saveImage(t);
               
            
        }
        break;
    }
}
        }
        
            int main() {
                int c;
                do {
                    cout << " Menu " << endl;
                    cout << "1- Grayscale conversion\n";
                    cout << "2- Black and White\n";
                    cout << "3- Invert Image\n";
                    cout << "4- Merge Image\n";
                    cout << "5- Flip Image\n";
                    cout << "6- Rotate the Picture\n";
                    cout << "7- Darken / Lighten Image\n";
                    cout << "8- Crop Image\n";
                    cout << "9- Frame Image\n";
                    cout << "10- Detect Image Edges\n";
                    cout << "11- Resize Image\n";
                    cout << "12- Blur Image\n";
                    cout << "13- Wano Sunlight Fix\n";
                    cout << "14- Skew image \n";
                    cout << "15- purple at night\n";
                    cout<<  "16-oil\n";
                    cout<<  "17-infrared photographyn\n";
                    cout<<  "18-tv\n";
                    cout<<  "19-contrast\n";
                    cout << "21- Exit\n";
                    cout << "What do you want?\n";
                    cin >> c;
                    if (c == 21) break;
                    convert_image(c)
                                  
                                  ;
                } while (c != 21);
            }