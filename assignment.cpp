/*
==============================================
file name : cs213_A1_part1_ allB(sec27)_20242116_20242076
team members :
             - Dalia Sami Abd El Aziz 20242116 
             -Bassant Mohammed Farouk 20242076             
Description:
This program applies different filters on an image.
The user can choose a filter from a menu.
==============================================
*/
#include <iostream>
#include "Image_Class.h"
#include<cmath>
#include<vector>
#include<algorithm>
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
            for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                   
                     y=image(i,j,k);
                  }
                  y=y/3;
                  image(i,j,0)=y;
                  image(i,j,1)=y;
                  image(i,j,2)=y;

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
             for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                   
                     y=image(i,j,k);
                  }
                  y=y/3;
                  image(i,j,0)=y;
                  image(i,j,1)=y;
                  image(i,j,2)=y;

               }
               }
            for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                       y=image(i,j,k);
         
                  }
                
                 if(y<127){
                     image(i,j,0)+=y;
                     image(i,j,1)+=y;
                     image(i,j,2)+=y;
                  }
                  else if (y>127){
                      image(i,j,0)=255;
                     image(i,j,1)=255;
                     image(i,j,2)=255;
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
            
 case 4:   
 // Merge
        {
            cout << "Upload 2nd Image\n";
            string filename;
            cin >> filename;
            Image image2(filename);
            Image resized(image.width, image.height);
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    for(int k=0;k<3;k++)
                    {
                      resized(i,j,k)=image(i,j,k)*.6 + image2(i,j,k)*.4 ;
                    }
                }
            }
          
            cout << "Do you want to save image (yes or no)\n";
            cin >> s;
            if (s == "yes" || s == "YES") {
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";
                cin >> t;
                resized.saveImage(t);
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
                            value = value *.4;
                        } else if (x == 2) {
                            value = value * 2;
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
        {  for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                   
                     y=image(i,j,k);
                  }
                  y=y/3;
                  image(i,j,0)=y;
                  image(i,j,1)=y;
                  image(i,j,2)=y;

               }
               }
            for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                       y=image(i,j,k);
         
                  }
                
                 if(y<127){
                     image(i,j,0)+=y;
                     image(i,j,1)+=y;
                     image(i,j,2)+=y;
                  }
                  else if (y>127){
                      image(i,j,0)=255;
                     image(i,j,1)=255;
                     image(i,j,2)=255;
                  }

               }
               }
            Image edgeImg = image;
            for (int i = 0; i < image.width - 1; i++) {
                for (int j = 0; j < image.height - 1; j++) {
                    int current = image(i, j, 0);
                    if(i-1 >=0)
                    {
                            int top     = image(i-1, j, 0);
                            int right = image(i + 1, j, 0);
                            int down = image(i, j + 1, 0);
                            int diff = abs(current - right) + abs(current - down);

                    if(diff >=30)
                    {
                        edgeImg(i, j, 0)=0;
                        edgeImg(i, j, 1)=0;
                        edgeImg(i, j, 2)=0;
                    }
                    else {
                        edgeImg(i, j, 0)=255;
                        edgeImg(i, j, 1)=255;
                        edgeImg(i, j, 2)=255;
                    }
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
                   
                   image(i, j, 0) =image(i, j, 0) * 1.4 + 30;
                   image(i, j, 1) = image(i, j, 1)* 1.2 + 15;
                     image(i, j, 2)=  image(i, j, 2) * 0.8;
                    
                    if (image(i, j, 0) > 255) image(i, j, 0) = 255;
                    if ( image(i, j, 1) > 255)  image(i, j, 1) = 255;
                    if ( image(i, j, 2) > 255)  image(i, j, 2)= 255;
                    
                  
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

            double r= degree * 3.14159265 / 180.0;
            int shiftMax = (int)(tan(r) * image.height);

            Image newimg(image.width + abs(shiftMax), image.height);

            for (int j = 0; j < image.height; j++) {
                int shift = (int)(tan(r) * j);
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
                case 16:    //oil painting
        {

         
            for(int i=0;i<image.width;i++)
            {
                
                for(int j=0;j<image.height;j++)
                {
                   vector<int>R,G,B;
                    
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
                            for (int u=0;u<3;u++)
                            {
                               R.push_back(image(k,q,0));
                               G.push_back(image(k,q,1));
                               B.push_back(image(k,q,2));
                            }
                        }
                    
                     
                    }
                  
                    sort(R.begin(),R.end());
                    sort(G.begin(),G.end());
                    sort(B.begin(),B.end());
                    int size =R.size()/2;
                    image(i,j,0)=R[size];
                    image(i,j,1)=G[size];
                    image(i,j,2)=B[size];

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
        case 17:   //infrared photographyn   الاشعه تحت الحمراء
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
  
        case 18:   //old_tv
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
 
      case 19:   // vignette      ظل ناعم حوالين الصوره 
        { 
       
            
          float dis , maxdis , dx , dy , h , dark ; 
                int center_X,center_Y;
                center_X = (image.width - 1) / 4;
                center_Y = (image.height - 1) / 4;
                maxdis = sqrt(center_X * center_X + center_Y * center_Y);  //max_distance to center
           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               
                dx = i - center_X;
                dy = j - center_Y;
                dis=sqrt(dx * dx + dy * dy);
                h= dis / maxdis;
                dark = 1 - ( h * h);
                if(dark < 0)   dark = 0;
               for(int k=0;k<image.channels ;k++)
               {
                image(i,j,k) = image(i,j,k) * dark;
                if (image(i, j, k) > 255) image(i, j, k) = 255;
                if (image(i, j, k) < 0) image(i, j, k) = 0;
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
    case  20:    //increacing blue im image    
    {

           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               
               
               for(int k=0;k<image.channels ;k++)
               {
                    image(i,j,2)=255;
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
    case 21:    //contrast    عمل تباين اللون تقيل الفرق بين الالوان
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
    case 22:    //blur only body    بعمل بلور فقط للوجه او الجسم
    {
          float dis , maxdis , dx , dy , h  ; 
                int center_X,center_Y ,radius ;
                center_X = (image.width - 1) /2;
                center_Y = (image.height - 1) /2;
                maxdis = sqrt(center_X * center_X + center_Y * center_Y);  //max_distance to center
           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               
                dx = i - center_X;
                dy = j - center_Y;
                dis=sqrt(dx * dx + dy * dy);
                h= dis / maxdis;
                if(h<.3)  radius=15;
                else if (h<.8) radius=7;
                else              radius=0;
                if(radius==0)   
                {
                    image(i,j,0)= image(i,j,0);
                    image(i,j,1)= image(i,j,1);
                    image(i,j,2)= image(i,j,2);
                    continue;
                }
                if(i-radius >=0  && i+radius<=image.width-1)
                {
                    if(j-radius >=0  && j+radius<=image.height-1)
                { 
                    int p=0,o=0,u=0,a=0;
                    for(int m=i-radius;m<i+radius ;m++){
            
                     for(int n=j-radius;n<j+radius ;n++)
                     {
                            p+=image(m,n,0);
                            o+=image(m,n,1);
                            u+=image(m,n,2);
                            a++;
                     }
                }
                    image(i,j,0)=p/a;
                    image(i,j,1)=o/a;
                    image(i,j,2)=u/a;
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
    case 23:    //portrait blur   بنسيب الشخص و نعمل بلور لباقي الصوره 
    {
                float dis , maxdis , dx , dy , h , dark ; 
                int center_X,center_Y ,radius ;
                center_X = (image.width - 1) / 2;
                center_Y = (image.height - 1) / 2;
                maxdis = sqrt(center_X * center_X + center_Y * center_Y);  //max_distance to center
           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               
                dx = i - center_X;
                dy = j - center_Y;
                dis=sqrt(dx * dx + dy * dy);
                h= dis / maxdis;
                if(h<.3)  radius=0;
                else if (h<.8) radius=3;
                else              radius=6;
                if(radius==0)   
                {
                    image(i,j,0)= image(i,j,0);
                    image(i,j,1)= image(i,j,1);
                    image(i,j,2)= image(i,j,2);
                    continue;
                }
                if(i-radius >=0  && i+radius<=image.width-1)
                {
                    if(j-radius >=0  && j+radius<=image.height-1)
                {
                    int p=0,o=0,u=0,a=0;
                    for(int m=i-radius;m<i+radius ;m++){
            
                     for(int n=j-radius;n<j+radius ;n++)
                     {
                            p+=image(m,n,0);
                            o+=image(m,n,1);
                            u+=image(m,n,2);
                            a++;
                     }
                }
                    image(i,j,0)=p/a;
                    image(i,j,1)=o/a;
                    image(i,j,2)=u/a;
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
     case  24:    //increacing green im image   رؤيه ليليه باللون الاخضر
    {

           for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               
               
               for(int k=0;k<image.channels ;k++)
               {
                    image(i,j,1)=255;
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
                    cout<<  "16-oil painting\n";
                    cout<<  "17-infrared photographyn\n";
                    cout<<  "18-old_tv\n";
                    cout<<  "19-vignette \n";
                    cout<<  "20-increacing blue im image \n";
                    cout<<  "21-contrast\n";
                    cout<<  "22-blur only body\n";
                    cout<<  "23-portrait blur\n";
                    cout << "24- increacing green im image\n";
                    cout<<  "25-Exist\n";
                    cout << "What do you want?\n";
                    cin >> c;
                    if (c == 25) break;
                    convert_image(c)
                                  
                                  ;
                } while (c != 25);
            }