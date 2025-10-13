#include<iostream>
#include"C:\Users\HP\Desktop\images1\Image_Class.h"
using namespace std ;
void convert_image(int c){
      string t,s,h;
     cout<<" write name of the picture :\n";
    cin>>t;
    Image image(t);
    int y;
 switch(c){
  case 1:
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
     cout<<"do you want to save image (yes or no) \n";

                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

                      cin >> t;
   
                 image.saveImage(t);
                 break; 
  }
}
  case 2:
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


     cout<<"do you want to save image (yes or no) \n";

                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

                      cin >> t;
   
                 image.saveImage(t);
                 break; 
  }
}
            case 3:
           { for(int i=0;i<image.width;i++)
            {
                 for(int j=0;j<image.height;j++)
                    {
                 for(int k=0;k<image.channels;k++)
                   {
                   
                     y=image(i,j,k);
                     image(i,j,k)=255-y;

                  }
                 

               }
               }
                cout<<"do you want to save image (yes or no) \n";

                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

                      cin >> t;
   
                 image.saveImage(t);
             
                }
                 break;}
  case 4:
  {
        cout << "Upload 2nd Image\n";
        Image image1 ;
    string filename;
    cin >> filename;
    Image image2(filename);
    int w = min(image1.width, image2.width);
    int h = min(image1.height, image2.height);
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            for (int k = 0; k < 3; ++k) {
                image1(x, y, k) = (image1(x, y, k) + image2(x, y, k)) / 2;
            }
        }
    }


     cout<<"do you want to save image (yes or no) \n";

                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

                      cin >> t;
   
                 image.saveImage(t);
                 break; 
  }
}
   
 case 5:
  {
    Image  original;
  
    Image test = original;
    int x;
    cout << "#1 Horizontal / #2 Vertical" << endl;
    cin >> x;
    if (x == 1) {
        for (int i = original.width - 1; i >= 0; i--) {
            for (int j = 0; j < original.height; j++) {
                for (int k = 0; k < original.channels; k++) {
                    test(original.width - 1 - i, j, k) = original(i, j, k);
                }
            }
        }
        original = test;
        original.saveImage("horizontal_flipped.png");
    } else if (x == 2) {
        for (int i = 0; i < original.width; i++) {
            for (int j = original.height - 1; j >= 0; j--) {
                for (int k = 0; k < original.channels; k++) {
                    test(i, original.height - 1 - j, k) = original(i, j, k);
                }
            }
        }

     cout<<"do you want to save image (yes or no) \n";

                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

                      cin >> t;
   
                 image.saveImage(t);
                 break; 
  }
}
  }
         case 6:
          
   { Image img(image.height , image.width);
   cout<<"degree of rotate is 270 , 180 , 90\n";
   int x;
   cin>>x;
    if(x==270){
      for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               for(int k=0;k<image.channels ;k++)
               {
                 img(j,image.width-1-i,k)=image(i,j,k);
               
               }

             }
        
          }
           cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
                      image=img;
                 image.saveImage(t);
           
          
     
   }
          break;
  }
 
   else if(x==180){
    
        for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               for(int k=0;k<image.channels ;k++)
               {
                 img(j,image.width-1-i,k)=image(i,j,k);
               
               }

             }
        
          }
    
          image=img;
         
           Image imag(img.height , img.width);
            for(int i=0;i<img.width ;i++){
            
             for(int j=0;j<img.height ;j++)
             {
               for(int k=0;k<img.channels ;k++)
               {
                 imag(j,img.width-1-i,k)=img(i,j,k);
               
               }

             }
        
          }
           Image im(imag.height , imag.width);
            for(int i=0;i<imag.width ;i++){
            
             for(int j=0;j<imag.height ;j++)
             {
               for(int k=0;k<imag.channels ;k++)
               {
                 im(j,imag.width-1-i,k)=imag(i,j,k);
               
               }

             }
        
          }
           cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
                      im=imag;
                 im.saveImage(t);
                 break;
   
        

   }
  }
    else if(x==90){
     for(int i=0;i<image.width ;i++){
            
             for(int j=0;j<image.height ;j++)
             {
               for(int k=0;k<image.channels ;k++)
               {
                 img(image.height-1-j,i,k)=image(i,j,k);
               
               }

             }
        
          }
            cout<<"do you want to save image (yes or no) \n";
                cin>>s;
                if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES"|| s=="YEs"|| s=="yeS"|| s=="yEs"){
                        cout << "Pls enter image name to store new image\n";
                         cout << "and specify extension .jpg, .bmp, .png, .tga: \n";

                      cin >> t;
                image=img;
                 image.saveImage(t);


   
   }
           break;
  }
         

      }
  
      case 9:
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
      case 12:
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
      case 14:
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
        case 16:
          break;
        
   
      
 }
}
}
int main()

{
   int c;
   
   do
   {
     cout<<"   Menu    "<<endl;
       cout<<"1-Grayscale conversion\n";
       cout<<"2-Black and White\n ";
         cout<<"3-Invert Image \n";
        cout <<"4-merge Image \n";
         cout <<"5-Flip Image \n";
       cout<<"6-Rotate the Picture\n";
         cout<<"9-Adding a Frame to the Picture \n";
          cout<<"12-Blur image \n";
           cout<<"13-land of wano \n";
             cout<<"14-infrared photography \n";
       cout<<"16-Exit \n";
         cout<<"what do you want ?\n";
         cin>>c;
         if(c==16){
            break;
         }
    convert_image(c);
        
     
}while (c!=13);

}
