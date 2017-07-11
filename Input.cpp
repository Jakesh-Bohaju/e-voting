
  /************************************************************************
  *************************************************************************
  ******************************  Input.cpp  ******************************
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

 /************************************************************************
  ************************************************************************
  *********************  General Function Definitions ********************
  ************************************************************************
  ***********************************************************************/

 /************************************************************************/
 //---------------------------  GetInput( )  ----------------------------//
 /************************************************************************/

 const char* GetInput(const int x,const int y,int max_size,
				const int text_color,const int text_bgcolor,
							const int input_type)
    {
       HideMouse( );
       GetCurrentSettings( );

       char Input[90]={NULL};

       if(max_size>=80)
	  max_size=80;

       if(max_size<=0)
	  max_size=1;

       int x_1=x;
       int x_2=(x+(8*max_size)+15);
       int y_1=y;
       int y_2=(y+16);

       setfillstyle(1,text_bgcolor);
	 bar(x_1,y_1,x_2,y_2);

       int count=0;
       int key_code=0;

       char Key=NULL;

       do
	  {
	     if(kbhit( ))
		{
		   Key=NULL;
		   key_code=0;

		   Key=getch( );
		   key_code=int(Key);

		   if(key_code==13 || key_code==27)
		      break;

		   if(count<max_size && key_code!=8)
		      {
			 if(input_type==NUMBER && (isdigit(Key) || Key==','
					   || Key=='-' || Key=='/' || Key=='e'))
			    {
			       Input[count]=Key;
			       count++;
			    }

			 else if(input_type==CHARACTER && (isalpha(Key) || Key==' '))
			    {
			       Input[count]=Key;
			       count++;
			    }

			 else if(input_type==ANYTHING)
			    {
			       Input[count]=Key;
			       count++;
			    }
		      }

		   else if(key_code==8 && count>0)
		      {
			 setfillstyle(1,text_bgcolor);
			   bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

			 count--;
			 Input[count]=NULL;
		      }
		}

	     settextstyle(0,0,1);
	     setcolor(text_color);

	     moveto((x+5),(y+5));
	       outtext(Input);

	     int xx=getx( );
	     int yy=(gety( )+4);

	     while(!kbhit( ))
		{
		   settextstyle(0,0,1);
		     setcolor(text_color);
		       moveto(xx,yy);
			 outtext("-");

		   delay(250);

		     setcolor(text_bgcolor);
		       moveto(xx,yy);
			 outtext("-");

		   delay(200);
	       }
	  }
       while(1);

       RestorePreviousSettings( );
       ShowMouse( );

       return Input;
    }

 /************************************************************************/
 /************************************************************************/
 //-----------------------------  THE END  ------------------------------//
 /************************************************************************/
 /************************************************************************/
