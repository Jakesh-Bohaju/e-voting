
 /**************************************************************************
  **************************************************************************
  *****************************  BmpLib.h  *********************************
  **************************************************************************
  *************************************************************************/

  /*************************************************************************

	  By :
		Muhammad Tahir Shahzad  [ MTS ]
		B.C.S Honours  [ 2000-04 ]
		Government College University Lahore
		Pakistan

      E-mail :  mtshome@wol.net.pk

    Web-Site :  www.mts-home.cjb.net  [ www.wol.net.pk/mtshome ]
		www.mtshome.cjb.net   [ www.geocities.com/mtahirshahzad ]

  *************************************************************************/

 /*************************************************************************/
 /*************************************************************************/
 /*****************************  Header Files  ****************************/
 /*************************************************************************/
 /*************************************************************************/

 # include <graphics.h>
 # include  <fstream.h>

 /*************************************************************************/
 /*************************************************************************/
 /**************************  Functions Prototypes  ***********************/
 /*************************************************************************/
 /*************************************************************************/

 const int LoadBmp(const int,const int,const char*);
 const int SaveBmp(const unsigned int,const unsigned int,const unsigned int,
				const unsigned int,const char*,const int=4);

 /*************************************************************************/
 /*************************************************************************/
 /**************************  Type Definitions  ***************************/
 /*************************************************************************/
 /*************************************************************************/

 typedef unsigned char BYTE;
 typedef unsigned int  WORD;
 typedef unsigned long DWORD;

 /*************************************************************************/
 /*************************************************************************/
 /******************  Class Declarations & Definitions  *******************/
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //--------------------------  BitmapFileHeader  -------------------------//
 /*************************************************************************/

 class BitmapFileHeader
 {
    public:
       BYTE Type[2];

       DWORD Size;

       WORD Reserved_1;
       WORD Reserved_2;

       DWORD Offset;

       BitmapFileHeader( )
       {
	  Type[0]='B';
	  Type[1]='M';

	  Size=0;

	  Reserved_1=0;
	  Reserved_2=0;

	  Offset=118;
       }
 };

 /*************************************************************************/
 //--------------------------  BitmapInfoHeader  -------------------------//
 /*************************************************************************/

 class BitmapInfoHeader
 {
    public:
       DWORD Size;
       DWORD Width;
       DWORD Height;

       WORD Planes;
       WORD BitCount;

       DWORD Compression;
       DWORD ImageSize;
       DWORD HorizontalPixelsPerMeter;
       DWORD VerticalPixelsPerMeter;
       DWORD ColorsUsed;
       DWORD ColorsImportant;

       BitmapInfoHeader( )
       {
	  Size=40;
	  Width=0;
	  Height=0;
	  Planes=1;

	  BitCount=4;
	  Compression=0;

	  ImageSize=0;
	  HorizontalPixelsPerMeter=0;
	  VerticalPixelsPerMeter=0;
	  ColorsUsed=16;
	  ColorsImportant=16;
       }
    };

 /*************************************************************************/
 //------------------------  BitmapColorPalette  -------------------------//
 /*************************************************************************/

 class BitmapColorPalette
 {
    public:
       BYTE Blue;
       BYTE Green;
       BYTE Red;
       BYTE Reserved;

       BitmapColorPalette( )
       {
	  Blue=0;
	  Green=0;
	  Red=0;
	  Reserved=0;
       }
 };

 /*************************************************************************/
 /*************************************************************************/
 /***************************  Global Objects  ****************************/
 /*************************************************************************/
 /*************************************************************************/

 BitmapFileHeader   BmpFileHeader;
 BitmapInfoHeader   BmpInfoHeader;

 BitmapColorPalette BmpColorPalette[16];

 /*************************************************************************/
 /*************************************************************************/
 /*************************  Function Definitions  ************************/
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //------------------------  WriteBmpFileHeader( )  ----------------------//
 /*************************************************************************/

 const int WriteBmpFileHeader(const char *BmpFile)
 {
    fstream File(BmpFile,ios::out|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.seekp(0,ios::beg);
    File.write((char*)&BmpFileHeader,sizeof(BmpFileHeader));
    File.close( );

    return 0;
 }

 /*************************************************************************/
 //------------------------  WriteBmpInfoHeader( )  ----------------------//
 /*************************************************************************/

 const int WriteBmpInfoHeader(const char *BmpFile)
 {
    fstream File(BmpFile,ios::out|ios::nocreate|ios::binary|ios::app);

    if(!File)
       return 1;

    File.write((char*)&BmpInfoHeader,sizeof(BmpInfoHeader));
    File.close( );

    return 0;
 }

 /*************************************************************************/
 //----------------------  WriteBmpColorPalette( )  ----------------------//
 /*************************************************************************/

 const int WriteBmpColorPalette(const char *BmpFile)
 {
    fstream File(BmpFile,ios::out|ios::nocreate|ios::binary|ios::app);

    if(!File)
       return 1;

    BYTE RGB_0=BYTE(0);
    BYTE RGB_128=BYTE(128);
    BYTE RGB_192=BYTE(192);
    BYTE RGB_255=BYTE(255);

    if(BmpInfoHeader.BitCount==1)
    {
       BYTE Palette[2][4]={
			     { RGB_0   , RGB_0   , RGB_0   , RGB_0 },
			     { RGB_255 , RGB_255 , RGB_255 , RGB_0 }
			  };

       for(int color=0;color<2;color++)
	  File.write((char*)&Palette[color],sizeof(Palette[color]));
    }

    else if(BmpInfoHeader.BitCount==4)
    {
       BYTE Palette[16][4]={
			      { RGB_0   , RGB_0   , RGB_0   , RGB_0 },
			      { RGB_0   , RGB_0   , RGB_128 , RGB_0 },
			      { RGB_0   , RGB_128 , RGB_0   , RGB_0 },
			      { RGB_0   , RGB_128 , RGB_128 , RGB_0 },
			      { RGB_128 , RGB_0   , RGB_0   , RGB_0 },
			      { RGB_128 , RGB_0   , RGB_128 , RGB_0 },
			      { RGB_128 , RGB_128 , RGB_0   , RGB_0 },
			      { RGB_192 , RGB_192 , RGB_192 , RGB_0 },
			      { RGB_128 , RGB_128 , RGB_128 , RGB_0 },
			      { RGB_0   , RGB_0   , RGB_255 , RGB_0 },
			      { RGB_0   , RGB_255 , RGB_0   , RGB_0 },
			      { RGB_0   , RGB_255 , RGB_255 , RGB_0 },
			      { RGB_255 , RGB_0   , RGB_0   , RGB_0 },
			      { RGB_255 , RGB_0   , RGB_255 , RGB_0 },
			      { RGB_255 , RGB_255 , RGB_0   , RGB_0 },
			      { RGB_255 , RGB_255 , RGB_255 , RGB_0 }
			   };

       for(int color=0;color<16;color++)
	  File.write((char*)&Palette[color],sizeof(Palette[color]));
    }

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //----------------------  GetBitmapColorIndex( )  -----------------------//
 /*************************************************************************/

 const BYTE GetBitmapColorIndex(const int color)
 {
    if(BmpInfoHeader.BitCount==1)
    {
       if(color==7 || color==8 || color==11 ||
					color==13 || color==14 || color==15)
	  return BYTE(1);

       else
	  return BYTE(0);
    }

    else
    {
       switch(color)
       {
	  case  0 : return BYTE(0);

	  case  1 : return BYTE(4);

	  case  2 : return BYTE(2);

	  case  3 : return BYTE(6);

	  case  4 : return BYTE(1);

	  case  5 : return BYTE(5);

	  case  6 : return BYTE(3);

	  case  7 : return BYTE(7);

	  case  8 : return BYTE(8);

	  case  9 : return BYTE(12);

	  case 10 : return BYTE(10);

	  case 11 : return BYTE(14);

	  case 12 : return BYTE(9);

	  case 13 : return BYTE(13);

	  case 14 : return BYTE(11);

	  case 15 : return BYTE(15);

	  default : return BYTE(color);
       }
    }
 }

 /*************************************************************************/
 //--------------------------  Save2ColorBmp( )  -------------------------//
 /*************************************************************************/

 const int Save2ColorBmp(const int x,const int y,const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary|ios::app);

    if(!File)
       return 1;

    BYTE Color;
    BYTE RGB_colors[8]={BYTE(0)};

    int screen_x;
    int screen_y;
    int extra_pixels=(BmpInfoHeader.Width%8);
    int extra_bytes=(BmpInfoHeader.Width%32);
    int horizontal_pixels=BmpInfoHeader.Width;
    int vertical_pixels=BmpInfoHeader.Height;

    if(extra_bytes!=0)
    {
       extra_bytes=(32-extra_bytes);
       extra_bytes/=8;
    }

    if(extra_pixels!=0)
       horizontal_pixels-=extra_pixels;

    for(int i=0;i<vertical_pixels;i++)
    {
       for(int j=0;j<horizontal_pixels;j++)
       {
	  Color=0x00;

	  screen_x=(x+j);
	  screen_y=(y-i);

	  RGB_colors[0]=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	  RGB_colors[0]<<=7;
	  Color|=RGB_colors[0];

	  for(int bit=1;bit<8;bit++)
	  {
	     j++;
	     screen_x=(x+j);

	     RGB_colors[bit]=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	     RGB_colors[bit]<<=(7-bit);
	     Color|=RGB_colors[bit];
	  }

	  File.put(Color);
       }

       if(extra_pixels)
       {
	  Color=0x00;

	  screen_x=(x+j);

	  RGB_colors[0]=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	  RGB_colors[0]<<=7;
	  Color|=RGB_colors[0];

	  for(int bit=1;bit<extra_pixels;bit++)
	  {
	     j++;
	     screen_x=(x+j);

	     RGB_colors[bit]=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	     RGB_colors[bit]<<=(7-bit);
	     Color|=RGB_colors[bit];
	  }

	  File.put(Color);
       }

       Color=0x00;

       for(int k=0;k<extra_bytes;k++)
	  File.put(Color);
    }

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //-------------------------  Save16ColorBmp( )  -------------------------//
 /*************************************************************************/

 const int Save16ColorBmp(const int x,const int y,const char *BmpFile)
 {
    fstream File(BmpFile,ios::out|ios::nocreate|ios::binary|ios::app);

    if(!File)
       return 1;

    BYTE Color;
    BYTE RGB_color_1;
    BYTE RGB_color_2;

    int screen_x;
    int screen_y;
    int extra_bytes=(BmpInfoHeader.Width%8);
    int horizontal_pixels=BmpInfoHeader.Width;
    int vertical_pixels=BmpInfoHeader.Height;

    if(extra_bytes!=0)
    {
       extra_bytes=(8-extra_bytes);
       extra_bytes/=2;
    }

    if((BmpInfoHeader.Width%2)==1)
       horizontal_pixels--;

    for(int i=0;i<vertical_pixels;i++)
    {
       for(int j=0;j<horizontal_pixels;j++)
       {
	  screen_x=(x+j);
	  screen_y=(y-i);

	  RGB_color_1=GetBitmapColorIndex(getpixel(screen_x,screen_y));

	  j++;
	  screen_x=(x+j);

	  RGB_color_2=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	  RGB_color_1<<=4;
	  Color=(RGB_color_1|RGB_color_2);

	  File.put(Color);
       }

       if((BmpInfoHeader.Width%2)==1)
       {
	  Color=0x00;

	  screen_x=(x+j);

	  RGB_color_1=GetBitmapColorIndex(getpixel(screen_x,screen_y));
	  RGB_color_1<<=4;
	  Color=RGB_color_1;

	  File.put(Color);
       }

       Color=0x00;

       for(int k=0;k<extra_bytes;k++)
	  File.put(Color);
    }

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //-----------------------------  SaveBmp( )  ----------------------------//
 /*************************************************************************/

 const int SaveBmp(const unsigned int x_1,const unsigned int y_1,
			 const unsigned int x_2,const unsigned int y_2,
				    const char *BmpFile,const int color_bits)
 {
    int driver;
    int mode;

    if(color_bits!=1 && color_bits!=4)
       return 5;

    fstream File(BmpFile,ios::out|ios::binary|ios::trunc);

    if(!File)
       return 1;

    File.close( );

    DWORD horizontal_pixels=((x_2-x_1)+1);
    DWORD vertical_pixels=((y_2-y_1)+1);

    int extra_bytes=(horizontal_pixels%8);

    horizontal_pixels+=extra_bytes;
    horizontal_pixels/=2;

    DWORD image_size=(horizontal_pixels*vertical_pixels);
    DWORD size=(image_size+54);

    if(color_bits==1)
       size+=8;

    else if(color_bits==4)
       size+=64;

    // Writing Bitmap File Header
    BmpFileHeader.Size=size;

    if(color_bits==1)
       BmpFileHeader.Offset=62;

    else if(color_bits==4)
       BmpFileHeader.Offset=118;

    if(WriteBmpFileHeader(BmpFile))
       return 1;

    // Writing Bitmap Info Header
    BmpInfoHeader.Width=((x_2-x_1)+1);
    BmpInfoHeader.Height=((y_2-y_1)+1);
    BmpInfoHeader.ImageSize=image_size;

    if(color_bits==1)
    {
       BmpInfoHeader.BitCount=1;
       BmpInfoHeader.ColorsUsed=2;
       BmpInfoHeader.ColorsImportant=2;
    }

    else
    {
       BmpInfoHeader.BitCount=4;
       BmpInfoHeader.ColorsUsed=16;
       BmpInfoHeader.ColorsImportant=16;
    }

    if(WriteBmpInfoHeader(BmpFile))
       return 1;

    // Writing Bitmap Color Palette
    if(WriteBmpColorPalette(BmpFile))
       return 1;

    // Saving Bitmap
    if(BmpInfoHeader.BitCount==1)
       Save2ColorBmp(x_1,y_2,BmpFile);

    else if(BmpInfoHeader.BitCount==4)
       Save16ColorBmp(x_1,y_2,BmpFile);

    return 0;
 }

 /*************************************************************************/
 //------------------------  ReadBmpFileHeader( )  -----------------------//
 /*************************************************************************/

 const int ReadBmpFileHeader(const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.seekg(0,ios::beg);
    File.read((char*)&BmpFileHeader,sizeof(BmpFileHeader));
    File.close( );

    return 0;
 }

 /*************************************************************************/
 //------------------------  ReadBmpInfoHeader( )  -----------------------//
 /*************************************************************************/

 const int ReadBmpInfoHeader(const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.seekg(14,ios::beg);
    File.read((char*)&BmpInfoHeader,sizeof(BmpInfoHeader));
    File.close( );

    return 0;
 }

 /*************************************************************************/
 //----------------------  ReadBmpColorPalette( )  -----------------------//
 /*************************************************************************/

 const int ReadBmpColorPalette(const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    int palette_size=16;

    if(BmpInfoHeader.BitCount==1)
       palette_size=2;

    File.seekg(54,ios::beg);

    for(int color=0;color<palette_size;color++)
       File.read((char*)&BmpColorPalette[color],sizeof(BmpColorPalette[color]));

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //--------------------------  GetBitmapColor( )  ------------------------//
 /*************************************************************************/

 const int GetBitmapColor(const int index)
 {
    int red=BmpColorPalette[index].Red;
    int green=BmpColorPalette[index].Green;
    int blue=BmpColorPalette[index].Blue;

    if(BmpInfoHeader.BitCount==1)
    {
       if(red==0 && green==0 && blue==0)
	  return 0;

       else if(red==255 && green==255 && blue==255)
	  return 15;

       else
	  return 15;
    }

    else
    {
       if(red==0 && green==0 && blue==0)
	  return 0;

       else if(red==0 && green==0 && blue==128)
	  return 1;

       else if(red==0 && green==128 && blue==0)
	  return 2;

       else if(red==0 && green==128 && blue==128)
	  return 3;

       else if(red==128 && green==0 && blue==0)
	  return 4;

       else if(red==128 && green==0 && blue==128)
	  return 5;

       else if(red==128 && green==128 && blue==0)
	  return 6;

       else if(red==192 && green==192 && blue==192)
	  return 7;

       else if(red==128 && green==128 && blue==128)
	  return 8;

       else if(red==0 && green==0 && blue==255)
	  return 9;

       else if(red==0 && green==255 && blue==0)
	  return 10;

       else if(red==0 && green==255 && blue==255)
	  return 11;

       else if(red==255 && green==0 && blue==0)
	  return 12;

       else if(red==255 && green==0 && blue==255)
	  return 13;

       else if(red==255 && green==255 && blue==0)
	  return 14;

       else if(red==255 && green==255 && blue==255)
	  return 15;

       else
	  return index;
    }
 }

 /*************************************************************************/
 //--------------------------  Show2ColorBmp( )  -------------------------//
 /*************************************************************************/

 const int Show2ColorBmp(const int x,const int y,const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.seekg(BmpFileHeader.Offset,ios::beg);

    BYTE Color;

    int screen_x;
    int screen_y;
    int extra_pixels=(BmpInfoHeader.Width%8);
    int extra_bytes=(BmpInfoHeader.Width%32);
    int horizontal_pixels=BmpInfoHeader.Width;
    int vertical_pixels=(BmpInfoHeader.Height-1);

    if(extra_bytes!=0)
    {
       extra_bytes=(32-extra_bytes);
       extra_bytes/=8;
    }

    if(extra_pixels!=0)
       horizontal_pixels-=extra_pixels;

    for(int i=vertical_pixels;i>=0;i--)
    {
       for(int j=0;j<horizontal_pixels;j++)
       {
	  File.get(Color);

	  screen_x=(x+j);
	  screen_y=(y+i);

	  putpixel(screen_x,screen_y,GetBitmapColor(Color>>7));

	  for(int bit=1;bit<8;bit++)
	  {
	     j++;
	     screen_x=(x+j);

	     Color<<=1;

	     putpixel(screen_x,screen_y,GetBitmapColor(Color>>7));
	  }
       }

       if(extra_pixels)
       {
	  screen_x=(x+j);

	  File.get(Color);

	  putpixel(screen_x,screen_y,GetBitmapColor(Color>>7));

	  for(int bit=1;bit<extra_pixels;bit++)
	  {
	     j++;
	     screen_x=(x+j);

	     Color<<=1;

	     putpixel(screen_x,screen_y,GetBitmapColor(Color>>7));
	  }
       }

       for(int k=0;k<extra_bytes;k++)
	  File.get(Color);
    }

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //-------------------------  Show16ColorBmp( )  -------------------------//
 /*************************************************************************/

 const int Show16ColorBmp(const int x,const int y,const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.seekg(BmpFileHeader.Offset,ios::beg);

    BYTE Color;

    int screen_x;
    int screen_y;
    int extra_bytes=(BmpInfoHeader.Width%8);
    int horizontal_pixels=BmpInfoHeader.Width;
    int vertical_pixels=(BmpInfoHeader.Height-1);

    if(extra_bytes!=0)
    {
       extra_bytes=(8-extra_bytes);
       extra_bytes/=2;
    }

    if((BmpInfoHeader.Width%2)==1)
       horizontal_pixels--;

    for(int i=vertical_pixels;i>=0;i--)
    {
       for(int j=0;j<horizontal_pixels;j++)
       {
	  File.get(Color);

	  screen_x=(x+j);
	  screen_y=(y+i);

	  putpixel(screen_x,screen_y,GetBitmapColor(Color>>4));

	  j++;
	  screen_x=(x+j);

	  Color<<=4;

	  putpixel(screen_x,screen_y,GetBitmapColor(Color>>4));
       }

       if((BmpInfoHeader.Width%2)==1)
       {
	  File.get(Color);

	  screen_x=(x+j);

	  putpixel(screen_x,screen_y,GetBitmapColor(Color>>4));
       }

       for(int k=0;k<extra_bytes;k++)
	  File.get(Color);
    }

    File.close( );

    return 0;
 }

 /*************************************************************************/
 //-----------------------------  LoadBmp( )  ----------------------------//
 /*************************************************************************/

 const int LoadBmp(const int x,const int y,const char *BmpFile)
 {
    fstream File(BmpFile,ios::in|ios::nocreate|ios::binary);

    if(!File)
       return 1;

    File.close( );

    // Reading Bitmap File Header
    if(ReadBmpFileHeader(BmpFile))
       return 1;

    if(BmpFileHeader.Type[0]!='B' || BmpFileHeader.Type[1]!='M')
       return 2;

    // Reading Bitmap Info Header
    if(ReadBmpInfoHeader(BmpFile))
       return 1;

    if(BmpInfoHeader.BitCount!=4 && BmpInfoHeader.BitCount!=1)
       return 3;

    if(BmpInfoHeader.Compression!=0)
       return 4;

    // Reading Bitmap Color Palette
    if(ReadBmpColorPalette(BmpFile))
       return 1;

    // Showing Bitmap
    if(BmpInfoHeader.BitCount==1)
       Show2ColorBmp(x,y,BmpFile);

    else if(BmpInfoHeader.BitCount==4)
       Show16ColorBmp(x,y,BmpFile);

    return 0;
 }

 /*************************************************************************/
 /*************************************************************************/
 /****************************  End of File  ******************************/
 /*************************************************************************/
 /*************************************************************************/