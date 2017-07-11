
  /************************************************************************
  *************************************************************************
  *****************************  TextBox.cpp  *****************************
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
 //----------------------  Class Function Definitions  -------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************
  *************************************************************************
  ******************************  TextBox  ********************************
  *************************************************************************
  *************************************************************************/

 /*************************************************************************/
 //-----------------------------  EditBox( )  ----------------------------//
 /*************************************************************************/

 EditBox::EditBox( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       max_length=10;

       strset(Editbox_value,NULL);
    }

 /************************************************************************/
 //------------------------------  Init( )  -----------------------------//
 /************************************************************************/

 void EditBox::Init(const int x,const int y,const char* Initial_value,
					const int max_size,const int width)
    {
       if(max_size>80)
	  max_length=80;

       else if(max_size<=0)
	  max_length=1;

       else
	  max_length=max_size;

       x_1=x;
       y_1=y;
       x_2=(width+x_1+(6*max_length)+15);
       y_2=(y_1+18);

       int length=strlen(Initial_value);

       if(length>max_length)
	 length=max_length;

       for(int count=0;count<length;count++)
	  {
	     Editbox_value[count]=NULL;

	     if(Initial_value[count]=='"')
		Editbox_value[count]='ø';

	     else
		Editbox_value[count]=Initial_value[count];
	  }

       Editbox_value[count]=NULL;
    }

 /*************************************************************************/
 //------------------------------  Show( )  ------------------------------//
 /*************************************************************************/

 void EditBox::Show( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,1);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(1);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,(y_2-1));

       setcolor(1);
	 line((x_1+1),(y_1+1),(x_2-1),(y_1+1));
	 line((x_1+1),(y_1+1),(x_1+1),(y_2-2));

       setcolor(1);
	 line(x_1,y_2,x_2,y_2);
	 line(x_2,y_2,x_2,(y_1+1));

       setcolor(1);
	 line((x_1+1),(y_2-1),(x_2-1),(y_2-1));
	 line((x_2-1),(y_2-1),(x_2-1),(y_1+2));

       setcolor(14);
       settextstyle(15,0,4);
	 outtextxy((x_1+5),(y_1+3),Editbox_value);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //--------------------------  GetUserInput( )  -------------------------//
 /************************************************************************/

 void EditBox::GetUserInput( )
    {
       HideMouse( );
       GetCurrentSettings( );

       char Value[90]={NULL};

       strcpy(Value,Editbox_value);

       setfillstyle(1,1);
	 bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

       setcolor(0);
       settextstyle(15,0,4);
	 outtextxy((x_1+5),(y_1+3),Value);

       int count=0;

       count=strlen(Value);

       do
	  {
	     if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char Key_1=NULL;
		   char Key_2=NULL;

		   Key_1=getch( );
		   key_code_1=int(Key_1);

		   if(key_code_1==0)
		      {
			 Key_2=getch( );
			 key_code_2=int(Key_2);
		      }

		   if(key_code_1!=0)
		      {
			 if(key_code_1==13)
			    {
			       strset(Editbox_value,NULL);
			       strcpy(Editbox_value,Value);

			       break;
			    }

			 else if(key_code_1==27)
			    {
			       setfillstyle(1,1);
				 bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

			       setcolor(14);
			       settextstyle(15,0,4);
				 outtextxy((x_1+5),(y_1+3),Editbox_value);

			       break;
			    }

			 else if(count<max_length && key_code_1!=8)
			    {
			       if(Key_1=='"')
				  {
				     Value[count]='ø';

				     count++;
				  }

			       else if(isprint(Key_1))
				  {
				     Value[count]=Key_1;

				     count++;
				  }
			    }

			 else if(key_code_1==8 && count>0)
			    {
			       setfillstyle(1,1);
				 bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

			       count--;

			       Value[count]=NULL;
			    }
		      }

		   else if(key_code_1==0)
		      {
			 key_code_1=key_code_2;
		      }
		}

	     setcolor(14);
	     settextstyle(15,0,4);

	     moveto((x_1+5),(y_1+3));
	       outtext(Value);

	     int x=(getx( )+1);
	     int y=gety( );

	     while(!kbhit( ))
		{
		   settextstyle(15,0,4);
		     setcolor(14);
		       moveto(x,(y-2));
			 outtext("³");

		       moveto(x,(y+1));
			 outtext("³");

		   delay(250);

		     setcolor(1);
		       moveto(x,(y-2));
			 outtext("³");

		       moveto(x,(y+1));
			 outtext("³");

		   delay(200);
	       }
	  }
       while(1);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //---------------------------  GetValue( )  ----------------------------//
 /************************************************************************/

 const char* EditBox::GetValue( )
    {
       int length=strlen(Editbox_value);

       for(int count=0;count<length;count++)
	  {
	     if(Editbox_value[count]=='ø')
		Editbox_value[count]='"';
	  }

       return Editbox_value;
    }

 /************************************************************************/
 //---------------------------  SetValue( )  ----------------------------//
 /************************************************************************/

 void EditBox::SetValue(const char *Value)
    {
       int length=strlen(Value);

       strset(Editbox_value,NULL);

       for(int count=0;count<length;count++)
	  {
	     if(Value[count]=='"')
		Editbox_value[count]='ø';

	     else
		Editbox_value[count]=Value[count];
	  }

       Editbox_value[count]=NULL;

       setfillstyle(1,1);
	 bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

       setcolor(14);
       settextstyle(15,0,4);
	 outtextxy((x_1+5),(y_1+3),Editbox_value);
    }

 /************************************************************************/
 //---------------------------  Hit( )  ---------------------------------//
 /************************************************************************/

 const int EditBox::Hit( )
    {
       int x=0;
       int y=0;

       GetMouseCoordinates(&x,&y);

       return ((x>=x_1 && x<=x_2 && y>=y_1 && y<=y_2)?1:0);
    }

 /************************************************************************/
 /************************************************************************/
 //-----------------------------  THE END  ------------------------------//
 /************************************************************************/
 /************************************************************************/
