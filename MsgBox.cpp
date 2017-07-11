
  /************************************************************************
  *************************************************************************
  ****************************  MsgBox.cpp  *******************************
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
 //-------------------------  Class Definitions  -------------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //--------------------------  MessageBox_Panel  -------------------------//
 /*************************************************************************/

 class MessageBox_Panel
    {
       private:
	     int x_1;
	     int x_2;
	     int y_1;
	     int y_2;
	     int color;

       public:
	     MessageBox_Panel( );
	     ~MessageBox_Panel( )  {  }

	     void Show( );
	     void Init(const int,const int,const int,const int,const int);
    };

 /*************************************************************************/
 //------------------------  MessageBox_Button  --------------------------//
 /*************************************************************************/

 class MessageBox_Button
    {
       protected:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;
	     int red_char_position;

	     char Label[35];

       public:
	     MessageBox_Button( );
	     ~MessageBox_Button( )  {  }

	     const int Hit( );

	     void Show( );
	     void Press( );
	     void PressAndRelease(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,const int);
    };

 /*************************************************************************/
 /*************************************************************************/
 //--------------------  Class Function Definitions  ---------------------//
 /*************************************************************************/
 /*************************************************************************/

 /************************************************************************
  ************************************************************************
  *************************  MessageBox_Panel  ***************************
  ************************************************************************
  ***********************************************************************/

 /************************************************************************/
 //---------------------  MessageBox_Panel( )  --------------------------//
 /************************************************************************/

 MessageBox_Panel::MessageBox_Panel( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       color=7;
    }

 /************************************************************************/
 //-------------------------------  Init( )  ----------------------------//
 /************************************************************************/

 void MessageBox_Panel::Init(const int left,const int top,const int right,
				     const int bottom,const int panel_color)
    {
       x_1=left;
       y_1=top;
       x_2=right;
       y_2=bottom;
       color=panel_color;
    }

 /************************************************************************/
 //------------------------------  Show( )  -----------------------------//
 /************************************************************************/

 void MessageBox_Panel::Show( )
   {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,color);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(15);
	 line(x_1,y_1,(x_2-1),y_1);
	 line(x_1,y_1,x_1,(y_2-1));

       setcolor(0);
	 line((x_1+1),y_2,x_2,y_2);
	 line(x_2,(y_1+1),x_2,y_2);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /*************************************************************************
  *************************************************************************
  *************************  MessageBox_Button  ***************************
  *************************************************************************
  ************************************************************************/

 /*************************************************************************/
 //-----------------------  MessageBox_Button( )  ------------------------//
 /*************************************************************************/

 MessageBox_Button::MessageBox_Button( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       mid_x=0;
       mid_y=0;
       red_char_position=0;

       strcpy(Label,NULL);
    }

 /************************************************************************/
 //------------------------------  Init( )  -----------------------------//
 /************************************************************************/

 void MessageBox_Button::Init(const int x,const int y,
					  const char* Text,const int width)
    {
       x_1=x;
       y_1=y;

       int count=0;

       while(Text[count]==' ')
	  count++;

       red_char_position=count;

       if(strlen(Text)<=25)
	  strcpy(Label,Text);

       else
	  {
	     strncpy(Label,Text,23);
	     strcat(Label,"..");
	  }

       settextstyle(0,0,1);

       x_2=(textwidth(Label)+14+width+x_1);
       y_2=(textheight(Label)+12+y_1);

       mid_x=(((x_1+x_2)/2)-(textwidth(Label)/2)+1);
       mid_y=(((y_1+y_2)/2)-(textheight(Label)/2)+1);
    }

 /*************************************************************************/
 //------------------------------  Show( )  ------------------------------//
 /*************************************************************************/

 void MessageBox_Button::Show( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,7);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(15);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,y_2);

       setcolor(8);
	 line((x_1+1),(y_2-1),x_2,(y_2-1));
	 line((x_2-1),y_2,(x_2-1),(y_1+1));

       setcolor(0);
	 line(x_2,y_2,x_2,y_1);
	 line(x_1,y_2,x_2,y_2);

       int label_size=strlen(Label);

       char Title[35]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	 strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
	 setcolor(7);
	   outtextxy((mid_x+1),(mid_y+1),Label);

	  setcolor(0);
	    outtextxy(mid_x,mid_y,Label);

	  setcolor(4);
	    outtextxy(mid_x,mid_y,Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //-----------------------------  Press( )  -----------------------------//
 /************************************************************************/

 void MessageBox_Button::Press( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setcolor(7);
	 line((x_1+1),(y_2-1),x_2,(y_2-1));
	 line((x_1+1),(y_1+2),x_2,(y_1+2));
	 line((x_1+2),(y_1+2),(x_1+2),y_2);
	 line((x_2-1),(y_1+2),(x_2-1),(y_2-1));

       setcolor(15);
	 line(x_2,y_2,x_2,y_1);
	 line(x_1,y_2,x_2,y_2);

       setcolor(0);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,y_2);

       setcolor(8);
	 line((x_1+1),(y_1+1),(x_1+1),(y_2-1));
	 line((x_1+1),(y_1+1),(x_2-1),(y_1+1));

       int label_size=strlen(Label);

       char Title[35]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	  strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
	 setcolor(7);
	   outtextxy(mid_x,mid_y,Label);

	  setcolor(0);
	    outtextxy((mid_x+1),(mid_y+1),Label);

	  setcolor(4);
	    outtextxy((mid_x+1),(mid_y+1),Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //------------------------  PressAndRelease( )  ------------------------//
 /************************************************************************/

 void MessageBox_Button::PressAndRelease(const int pressed_key)
    {
       Press( );

       if(pressed_key==KEY_BOARD)
	  delay(250);

       else if(pressed_key==LEFT_MOUSE_KEY)
	  while(Hit( ) && LeftMouseKeyPressed( ) && !kbhit( ));

       else if(pressed_key==RIGHT_MOUSE_KEY)
	  while(Hit( ) && RightMouseKeyPressed( ) && !kbhit( ));

	 Show( );
    }

 /************************************************************************/
 //----------------------------  Hit( )  --------------------------------//
 /************************************************************************/

 const int MessageBox_Button::Hit( )
    {
       int x=0;
       int y=0;

       GetMouseCoordinates(&x,&y);

       return ((x>=x_1 && x<=x_2 && y>=y_1 && y<=y_2)?1:0);
    }

 /************************************************************************
  ************************************************************************
  *********************  General Function Definitions  *******************
  ************************************************************************
  ***********************************************************************/

 /************************************************************************/
 //--------------------------  write_message( )  ------------------------//
 /************************************************************************/

 void write_message(const int x,const int y,const char* Message)
    {
       int flag=0;
       int temp_x=x;
       int temp_y=y;
       int end_of_line=0;
       int number_of_text_lines=(strlen(Message)/50);

       char Character[5]={NULL};

       if((strlen(Message)%50)>0)
	  number_of_text_lines++;

       setcolor(0);
       settextstyle(2,0,4);

       for(int count_1=0;count_1<number_of_text_lines;count_1++)
	  {
	     flag=0;

	     int count_2=end_of_line;

	     if(count_1==(number_of_text_lines-1))
		{
		   if((strlen(Message)-count_2)<=50)
		      end_of_line+=(strlen(Message)-count_2);

		   else
		      {
			 end_of_line+=50;
			 number_of_text_lines++;
		      }
		}

	     else
		{
		   end_of_line+=50;

		   while(Message[end_of_line]!=' ' &&
						    end_of_line>(count_2+45))
		      end_of_line--;

		   if(end_of_line==(count_2+45))
		      {
			 end_of_line+=6;
			 flag=1;
		      }
		}

	     for(;count_2<end_of_line;count_2++)
		{
		   strset(Character,NULL);

		   Character[0]=Message[count_2];

		   if(flag && count_2==(end_of_line-1))
		      Character[0]='-';

		   moveto(temp_x,temp_y);
		     outtext(Character);

		   temp_x=getx( );
		}

	     temp_x=(x-6);
	     temp_y+=10;

	     if(flag)
		{
		   end_of_line--;
		   temp_x+=6;
		}
	  }
    }

 /************************************************************************/
 //---------------------------  display_icon( )  ------------------------//
 /************************************************************************/

 void display_icon(const int x,const int y,const int icon_type)
    {
       if(icon_type==INFORMATION)
	  {
	     setcolor(1);
	       ellipse((x+35),(y+55),0,360,20,15);

	     setcolor(15);
	     setfillstyle(1,15);
	       fillellipse((x+35),(y+55),19,14);

	     int shape[8]={(x+40),(y+70),(x+40),(y+80),(x+35),(y+70),
			   (x+40),(y+70)};

	     setfillstyle(1,15);
	       fillpoly(4,shape);

	     setcolor(1);
	       line((x+35),(y+71),(x+40),(y+80));
	       line((x+40),(y+70),(x+40),(y+80));

	     settextstyle(0,0,3);
	       setcolor(7);
		 outtextxy((x+25),(y+44),"i");

	       setcolor(9);
		 outtextxy((x+23),(y+44),"i");
		 outtextxy((x+24),(y+44),"i");
	  }

       else if(icon_type==QUESTION)
	  {
	     setcolor(1);
	       ellipse((x+35),(y+55),0,360,20,15);

	     setcolor(15);
	     setfillstyle(1,15);
	       fillellipse((x+35),(y+55),19,14);

	     int shape[8]={(x+40),(y+70),(x+40),(y+80),(x+35),(y+70),(x+40),
			  (y+70)};

	     setfillstyle(1,15);
	       fillpoly(4,shape);

	     setcolor(1);
	       line((x+35),(y+71),(x+40),(y+80));
	       line((x+40),(y+70),(x+40),(y+80));

	     settextstyle(0,0,3);
	       setcolor(7);
		 outtextxy((x+25),(y+45),"?");

	       setcolor(9);
		 outtextxy((x+23),(y+45),"?");
		 outtextxy((x+24),(y+45),"?");
	  }

       else if(icon_type==EXCLAMATION)
	  {
	     int poly[20]={(x+33),(y+38),(x+35),(y+36),(x+37),(y+38),(x+53),
			   (y+69),(x+54),(y+71),(x+52),(y+72),(x+16),(y+72),
			   (x+14),(y+71),(x+15),(y+69),(x+33),(y+38)};

	     setcolor(1);
	     setfillstyle(1,14);
	       fillpoly(10,poly);

	     settextstyle(0,0,3);
	       setcolor(7);
		 outtextxy((x+24),(y+47),"!");

	       setcolor(0);
		 outtextxy((x+22),(y+47),"!");
		 outtextxy((x+23),(y+47),"!");
	  }

       else if(icon_type==STOP)
	  {
	     setcolor(12);
	     setfillstyle(1,12);
	       pieslice((x+35),(y+55),0,360,20);

	     setcolor(1);
	       circle((x+35),(y+55),20);

	     setcolor(15);
	       line((x+26),(y+44),(x+46),(y+64));
	       line((x+25),(y+45),(x+45),(y+65));
	       line((x+24),(y+46),(x+44),(y+66));

	       line((x+24),(y+64),(x+44),(y+44));
	       line((x+25),(y+65),(x+45),(y+45));
	       line((x+26),(y+66),(x+46),(y+46));
	  }
    }

 /************************************************************************/
 //----------------  MessageBox(const char*,const char*)  ---------------//
 /************************************************************************/

 void MessageBox(const char* Message,const char* Title)
    {
       HideMouse( );
       GetCurrentSettings( );

       sound(2500);
       delay(50);
       nosound( );

       int x_1=250;
       int y_1=190;
       int x_2=390;
       int y_2=290;

       char *Msg_title=new char[(strlen(Title)+10)];

       strset(Msg_title,NULL);
       strcpy(Msg_title,Title);

       if(strlen(Title)>35)
	  {
	     Msg_title[30]='.';
	     Msg_title[31]='.';
	     Msg_title[32]='.';
	     Msg_title[33]=NULL;
	  }

       if(strlen(Message)>50)
	  {
	     x_1=150;
	     x_2=490;
	     y_1=(195-((strlen(Message)/50)*5));
	     y_2=(285+((strlen(Message)/50)*6));
	  }

       else if(strlen(Message)>=strlen(Msg_title) && strlen(Message)>16)
	  {
	     x_1-=((strlen(Message)-16)*3);
	     x_2+=((strlen(Message)-16)*3);
	  }

       else if(strlen(Message)<strlen(Msg_title) && strlen(Msg_title)>14)
	  {
	     x_1-=((strlen(Msg_title)-14)*4);
	     x_2+=((strlen(Msg_title)-14)*4);
	  }

       char *Bitmap=NULL;

       int image_size=imagesize((x_1-5),(y_1-5),(x_2+5),(y_2+5));

       Bitmap=new char[(image_size+10)];

       getimage((x_1-5),(y_1-5),(x_2+5),(y_2+5),Bitmap);

       Panel Message_box;
       Panel Title_bar;

       Message_box.Init(x_1,y_1,x_2,y_2,OUT,THIN);
       Title_bar.Init(x_1,y_1,x_2,(y_1+20),OUT,THIN,9);

       Message_box.Show( );
       Title_bar.Show( );

       setcolor(1);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,y_2);
	 line(x_2,y_1,x_2,y_2);
	 line(x_1,y_2,x_2,y_2);
	 line(x_1,(y_1+20),x_2,(y_1+20));

       settextstyle(0,0,1);
	 setcolor(0);
	   outtextxy((x_1+3),(y_1+11),Msg_title);

	 setcolor(15);
	   outtextxy((x_1+4),(y_1+10),Msg_title);

       if(strlen(Message)<=50)
	  {
	     setcolor(0);
	     settextstyle(2,0,4);
	       outtextxy((x_1+20),(y_1+35),Message);
	  }

       else
	  write_message((x_1+30),(y_1+35),Message);

       Button Ok;

       Ok.Init(290,(y_2-30),"  Ok  ");
       Ok.Show( );

       ShowMouse( );

       int selected=0;

       do
	  {
	     if(Ok.Hit( ) && LeftMouseKeyPressed( ))
		{
		   Ok.PressAndRelease(LEFT_MOUSE_KEY);

		   selected=1;
		}

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

		   if(key_code_1==13 || (key_code_1==0 && key_code_2==24))
		      {
			 Ok.PressAndRelease(KEY_BOARD);

			 selected=1;
		      }
		}
	  }
       while(selected==0);

       delay(200);

       HideMouse( );

       putimage((x_1-5),(y_1-5),Bitmap,0);

       delete Msg_title;
       delete Bitmap;

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //----------------------------  MessageBox( )  -------------------------//
 /************************************************************************/

 const int MessageBox(const char* Message,const char* Title,
				      const int icon_type,const int msg_type)
    {
       HideMouse( );
       GetCurrentSettings( );

       sound(2500);
       delay(50);
       nosound( );

       int x_1=250;
       int y_1=190;
       int x_2=390;
       int y_2=290;

       if(msg_type==OK)
	  {
	     x_1=200;
	     x_2=440;
	  }

       else if(msg_type==OK_CANCEL || msg_type==YES_NO)
	  {
	     x_1=195;
	     x_2=445;
	  }

       else if(msg_type==YES_NO_CANCEL)
	  {
	     x_1=190;
	     x_2=450;
	  }

       char *Msg_title=new char[(strlen(Title)+10)];

       strset(Msg_title,NULL);
       strcpy(Msg_title,Title);

       if(strlen(Title)>35)
	  {
	     Msg_title[30]='.';
	     Msg_title[31]='.';
	     Msg_title[32]='.';
	     Msg_title[33]=NULL;
	  }

       if(strlen(Message)>50)
	  {
	     x_1=125;
	     x_2=515;
	     y_1=(195-((strlen(Message)/50)*5));
	     y_2=(285+((strlen(Message)/50)*6));
	  }

       else if(strlen(Message)>=strlen(Msg_title))
	  {
	     if(strlen(Message)>26)
		{
		   x_1-=((strlen(Message)-26)*3);
		   x_2+=((strlen(Message)-26)*3);
		}
	  }

       else if(strlen(Message)<strlen(Msg_title))
	  {
	     if(strlen(Msg_title)>25)
		{
		   x_1-=((strlen(Msg_title)-25)*4);
		   x_2+=((strlen(Msg_title)-25)*4);
		}
	  }

       char *Bitmap=NULL;

       int image_size=imagesize((x_1-5),(y_1-5),(x_2+5),(y_2+5));

       Bitmap=new char[(image_size+10)];

       getimage((x_1-5),(y_1-5),(x_2+5),(y_2+5),Bitmap);

       MessageBox_Panel Message_box;
       MessageBox_Panel Title_bar;

       Message_box.Init(x_1,y_1,x_2,y_2,7);
       Title_bar.Init(x_1,y_1,x_2,(y_1+20),9);

       Message_box.Show( );
       Title_bar.Show( );

       setcolor(1);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,y_2);
	 line(x_2,y_1,x_2,y_2);
	 line(x_1,y_2,x_2,y_2);
	 line(x_1,(y_1+20),x_2,(y_1+20));

       display_icon(x_1,y_1,icon_type);

       settextstyle(0,0,1);
	 setcolor(0);
	   outtextxy((x_1+14),(y_1+7),Msg_title);

	 setcolor(14);
	   outtextxy((x_1+15),(y_1+6),Msg_title);

       if(strlen(Message)<=50)
	  {
	     setcolor(0);
	     settextstyle(2,0,4);
	       outtextxy((x_1+70),(y_1+40),Message);
	  }

       else
	  write_message((x_1+70),(y_1+40),Message);

       MessageBox_Button Ok;
       MessageBox_Button Cancel;
       MessageBox_Button Yes;
       MessageBox_Button No;

       if(msg_type==OK)
	  {
	     Ok.Init(290,(y_2-30),"  Ok  ",0);
	     Ok.Show( );
	  }

       else if(msg_type==OK_CANCEL)
	  {
	     Ok.Init((x_2-160),(y_2-30),"Ok",37);
	     Ok.Show( );

	     Cancel.Init((x_2-85),(y_2-30),"Cancel",5);
	     Cancel.Show( );
	  }

       else if(msg_type==YES_NO)
	  {
	     Yes.Init((x_2-160),(y_2-30),"Yes",24);
	     Yes.Show( );

	     No.Init((x_2-90),(y_2-30),"No",32);
	     No.Show( );
	  }

       else if(msg_type==YES_NO_CANCEL)
	  {
	     Yes.Init((x_2-220),(y_2-30),"Yes",24);
	     Yes.Show( );

	     No.Init((x_2-150),(y_2-30),"No",32);
	     No.Show( );

	     Cancel.Init((x_2-80),(y_2-30),"Cancel",5);
	     Cancel.Show( );
	  }

       ShowMouse( );

       int selected=0;

       do
	  {
	     if(Ok.Hit( ) && LeftMouseKeyPressed( ) &&
				       (msg_type==OK || msg_type==OK_CANCEL))
		{
		   Ok.PressAndRelease(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(Cancel.Hit( ) && LeftMouseKeyPressed( ) &&
			    (msg_type==OK_CANCEL || msg_type==YES_NO_CANCEL))
		{
		   Cancel.PressAndRelease(LEFT_MOUSE_KEY);

		   if(msg_type==OK_CANCEL)
		      selected=2;

		   else if(msg_type==YES_NO_CANCEL)
		      selected=3;
		}

	     else if(Yes.Hit( ) && LeftMouseKeyPressed( ) &&
			       (msg_type==YES_NO || msg_type==YES_NO_CANCEL))
		{
		   Yes.PressAndRelease(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(No.Hit( ) && LeftMouseKeyPressed( ) &&
			       (msg_type==YES_NO || msg_type==YES_NO_CANCEL))
		{
		   No.PressAndRelease(LEFT_MOUSE_KEY);

		   selected=2;
		}

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

		   if((key_code_1==13 || (key_code_1==0 && key_code_2==24))
				    && (msg_type==OK || msg_type==OK_CANCEL))
		      {
			 Ok.PressAndRelease(KEY_BOARD);

			 selected=1;
		      }

		   else if((key_code_1==27 ||
			  (key_code_1==0 && key_code_2==46)) &&
			    (msg_type==OK_CANCEL || msg_type==YES_NO_CANCEL))
		      {
			 Cancel.PressAndRelease(KEY_BOARD);

			 if(msg_type==OK_CANCEL)
			    selected=2;

			 else if(msg_type==YES_NO_CANCEL)
			    selected=3;
		      }

		   else if((key_code_1==13 ||
			     (key_code_1==0 && key_code_2==21)) &&
			       (msg_type==YES_NO || msg_type==YES_NO_CANCEL))
		      {
			 Yes.PressAndRelease(KEY_BOARD);

			 selected=1;
		      }

		   else if((key_code_1==27 ||
			    (key_code_1==0 && key_code_2==49)) &&
			       (msg_type==YES_NO || msg_type==YES_NO_CANCEL))
		      {
			 No.PressAndRelease(KEY_BOARD);

			 selected=2;
		      }
		}
	  }
       while(!selected);

       delay(200);

       HideMouse( );

       putimage((x_1-5),(y_1-5),Bitmap,0);

       delete Msg_title;
       delete Bitmap;

       RestorePreviousSettings( );
       ShowMouse( );

       return selected;
    }

 /************************************************************************/
 /************************************************************************/
 //-----------------------------  THE END  ------------------------------//
 /************************************************************************/
 /************************************************************************/