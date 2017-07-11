
  /************************************************************************
  *************************************************************************
  ****************************  Gui.cpp  **********************************
  *************************************************************************
  ************************************************************************/

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
 //--------------------------  Header Files  -----------------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //---------------------------  User Defined  ----------------------------//
 /*************************************************************************/

 # include   "Gui.h"
 # include "Mouse.h"

 /*************************************************************************/
 /*************************************************************************/
 //------------------------  Global Variables  ---------------------------//
 /*************************************************************************/
 /*************************************************************************/

 int text_font=0;
 int text_direction=0;
 int text_size=0;
 int text_color=0;
 int fill_pattern=0;
 int fill_color=0;

 /************************************************************************
  ************************************************************************
  *********************  General Function Definitions ********************
  ************************************************************************
  ***********************************************************************/

 /************************************************************************/
 //------------------------  InitGraphicMode( )  ------------------------//
 /************************************************************************/

 void InitGraphicMode( )
    {
       int driver=VGA;
       int mode=VGAHI;

       int error_code=0;
       int flag=0;

       char Bgi_path[100]={NULL};

       initgraph(&driver,&mode,"..\\Bgi");

       Initialize_graphic_mode:

       if(flag)
	  {
	     driver=VGA;
	     mode=VGAHI;
	     error_code=0;

	     initgraph(&driver,&mode,Bgi_path);
	  }

       error_code=graphresult( );

       if(error_code!=grOk)
	  {
	     clrscr( );
	     textmode(C4350);

	     gotoxy(1,7);
	     cout<<"     **********************************************************************"<<endl;
	     cout<<"     **********                                                  **********"<<endl;
	     cout<<"     **--------   Error : Graphic Driver cannot be initialized   --------**"<<endl;
	     cout<<"     **********                                                  **********"<<endl;
	     cout<<"     **********************************************************************"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **        Possible Cause of Error:                                  **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **            *  Incorrect Bgi Path                                 **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **            *  Corruption of Egavga.bgi file                      **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **            *  Egavga.bgi file may not exists                     **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **            *  Incompatible Hardware / Invalid Device Driver      **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **        Press <Esc> to exit or <Enter> to try again...            **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **                                                                  **"<<endl;
	     cout<<"     **********************************************************************"<<endl;
	     cout<<"     **********************************************************************"<<endl;

	     gotoxy(62,26);

	     char Key=NULL;

	     Key=getch( );

	     if(int(Key)==13)
		{
		   flag=1;

		   strset(Bgi_path,NULL);

		   gotoxy(1,35);
		   cout<<"     **********************************************************************"<<endl;
		   cout<<"     ****************************              ****************************"<<endl;
		   cout<<"     **--------------------------   Bgi Path   --------------------------**"<<endl;
		   cout<<"     ****************************              ****************************"<<endl;
		   cout<<"     **********************************************************************"<<endl;
		   cout<<"     **                                                                  **"<<endl;
		   cout<<"     **                                                                  **"<<endl;
		   cout<<"     **        Enter the Bgi Path =                                      **"<<endl;
		   cout<<"     **                                                                  **"<<endl;
		   cout<<"     **                                                                  **"<<endl;
		   cout<<"     **********************************************************************"<<endl;
		   cout<<"     **********************************************************************"<<endl;

		   gotoxy(37,42);
		   gets(Bgi_path);

		   goto Initialize_graphic_mode;
		}

	     else if(int(Key)==27)
             {
                delay(500);
                clrscr( );
		exit(0);
             } 
	  }
    }

 /************************************************************************/
 //-----------------------  GetCurrentSettings( )  ----------------------//
 /************************************************************************/

 void GetCurrentSettings( )
    {
       struct textsettingstype text_settings;
       struct fillsettingstype fill_settings;

       gettextsettings(&text_settings);
       getfillsettings(&fill_settings);

       text_font=text_settings.font;
       text_direction=text_settings.direction;
       text_size=text_settings.charsize;

       fill_pattern=fill_settings.pattern;
       fill_color=fill_settings.color;

       text_color=getcolor( );
    }

 /************************************************************************/
 //---------------------  RestorePreviousSettings( )  -------------------//
 /************************************************************************/

 void RestorePreviousSettings( )
    {
       setcolor(text_color);
       settextstyle(text_font,text_direction,text_size);

       setfillstyle(fill_pattern,fill_color);
    }

 /************************************************************************/
 /************************************************************************/
 //-----------------------------  THE END  ------------------------------//
 /************************************************************************/
 /************************************************************************/