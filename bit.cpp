#include<iostream.h>
#include<graphics.h>
#include<fstream.h>
#include<conio.h>
struct A{
    char type[2];                 /* Magic identifier            */
    unsigned long size;                       /* File size in bytes          */
    unsigned short int reserved1, reserved2;
    unsigned long offset;                     /* Offset to image data, bytes */
}HEADER,HEADER1;
struct B{
    unsigned long size;               /* Header size in bytes      */
    unsigned long width,height;                /* Width and height of image */
    unsigned short int planes;       /* Number of colour planes   */
    unsigned short int bits;         /* Bits per pixel            */
    unsigned long compression;        /* Compression type          */
    unsigned long imagesize;          /* Image size in bytes       */
    unsigned long xresolution,yresolution;     /* Pixels per meter          */
    unsigned long ncolours;           /* Number of colours         */
    unsigned long importantcolours;   /* Important colours         */
}INFOHEADER,INFOHEADER1;
huge DetectSvga()

{
    return 2;
}
void Show()
{
    fstream File;
    File.open("c:\\tc\\bin\\play.bmp",ios::in);
    char Ch;
    File.read((char*)&HEADER,14); //This is the header part of the Bitmap.
    File.read((char*)&INFOHEADER,40); //This is another part of the bitmap
    unsigned int i;
    char ColorBytes[4];
    char*PaletteData;
    PaletteData=new char[256*3];
    if(PaletteData)//if memory allocated successfully
    {
	//read color data
	for(i=0;i<256;i++)
{

	    File.read(ColorBytes,4);
	    PaletteData[(int)(i*3+2)]=ColorBytes[3]>>2;
	    PaletteData[(int)(i*3+1)]=ColorBytes[2]>>2;
	    PaletteData[(int)(i*3+0)]=ColorBytes[1]>>2;
	}
	outp(0x03c8,0);      //tell DAC that data is coming
	for(i=0;i<256*3;i++) //send data to SVGA DAC
	{
	    outp(0x03c9,PaletteData[i]);
	}
	delete[]PaletteData;
    }
    for(i=0;i<INFOHEADER.height;i++)       //This for loop is used to display the bitmap.
    {
	for(int j=0;j<INFOHEADER.width;)
	{
	    File.read(&Ch,1); // Here Ch reads the color of your bitmap.
	    putpixel(0+(j++),0+INFOHEADER.height-i-1,Ch);
	}
    }
    File.close();
}
void star()
{
clrscr();
  

Show();
getch();
 
}
