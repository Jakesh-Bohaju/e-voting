
 /**************************************************************************
  **************************************************************************
  ******************************  Menu.cpp  ********************************
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
 //----------------------------  Header Files  ---------------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //----------------------------  User Defined  ---------------------------//
 /*************************************************************************/

 # include   "Gui.h"
 # include "Mouse.h"

 /*************************************************************************/
 /*************************************************************************/
 //--------------------  Class Function Definitions  ---------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************
  *************************************************************************
  ****************************  Menu_Button  ******************************
  *************************************************************************
  ************************************************************************/

 /*************************************************************************/
 //----------------------------  Menu_Button( )  -------------------------//
 /*************************************************************************/

 Menu_Button::Menu_Button( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       mid_x=0;
       mid_y=0;

       strset(Label,NULL);
    }

 /************************************************************************/
 //-----------------------------  Init( )  ------------------------------//
 /************************************************************************/

 void Menu_Button::Init(const int x,const int y,const char* Text,
					   const int width,const int height)
    {
       x_1=x;
       y_1=y;

       if(strlen(Text)<=25)
	  strcpy(Label,Text);

       else
	  {
	     strncpy(Label,Text,23);
	     strcat(Label,"..");
	  }

       settextstyle(0,0,1);

       x_2=(textwidth(Label)+14+width+x_1);
       y_2=(textheight(Label)+12+height+y_1);

       mid_x=(((x_1+x_2)/2)-(textwidth(Label)/2)+1);
       mid_y=(((y_1+y_2)/2)-(textheight(Label)/2)+1);
    }

 /*************************************************************************/
 //------------------------------  Show( )  ------------------------------//
 /*************************************************************************/

 void Menu_Button::Show( )
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

       settextstyle(0,0,1);
	 setcolor(7);
	   outtextxy((mid_x+1),(mid_y+1),Label);

	  setcolor(0);
	    outtextxy(mid_x,mid_y,Label);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /*************************************************************************/
 //----------------------------  Hilight( )  -----------------------------//
 /*************************************************************************/

 void Menu_Button::Hilight( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,1);
	 bar((x_1+3),(y_1+2),(x_2-4),(y_2-3));

       setcolor(15);
       settextstyle(0,0,1);
	 outtextxy(mid_x,mid_y,Label);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /*************************************************************************/
 //----------------------------  Release( )  -----------------------------//
 /*************************************************************************/

 void Menu_Button::Release( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,7);
	 bar((x_1+2),(y_1+2),(x_2-2),(y_2-2));

       setcolor(0);
       settextstyle(0,0,1);
	 outtextxy(mid_x,mid_y,Label);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //-----------------------  HilightAndRelease( )  -----------------------//
 /************************************************************************/

 void Menu_Button::HilightAndRelease(const int key_pressed)
    {
       Hilight( );

       if(key_pressed==KEY_BOARD)
	  while(!kbhit( ) && !LeftMouseKeyPressed( ));

       else if(key_pressed==LEFT_MOUSE_KEY)
	  while(Hit( ) && !LeftMouseKeyPressed( ) && !kbhit( ));

       Release( );
    }

 /************************************************************************/
 //----------------------------  Hit( )  --------------------------------//
 /************************************************************************/

 const int Menu_Button::Hit( )
    {
       int x=0;
       int y=0;

       GetMouseCoordinates(&x,&y);

       return ((x>=x_1 && x<=x_2 && y>=y_1 && y<=y_2)?1:0);
    }

 /*************************************************************************
  *************************************************************************
  ********************************  Menu  *********************************
  *************************************************************************
  *************************************************************************/

 /*************************************************************************/
 //------------------------------  Menu( )  ------------------------------//
 /*************************************************************************/

 Menu::Menu( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       mid_x=0;
       mid_y=0;
       max_length=0;
       red_char_position=0;
       number_of_items=0;

       strset(Label,NULL);

       for(int count=0;count<10;count++)
	  strset(Menu_items[count],NULL);
    }

 /************************************************************************/
 //-----------------------------  Init( )  ------------------------------//
 /************************************************************************/

 void Menu::Init(const int x,const int y,const char *Text,const int red_char,
				  const int item_counter,const char* Items[])
    {
       x_1=x;
       y_1=y;

       if(item_counter>10)
	  number_of_items=10;

       else if(item_counter<=0)
	  number_of_items=1;

       else
	  number_of_items=item_counter;

       for(int count_1=0;count_1<number_of_items;count_1++)
	  {
	     if(strlen(Items[count_1])<=25)
		strcpy(Menu_items[count_1],Items[count_1]);

	     else
		{
		   strncpy(Menu_items[count_1],Items[count_1],23);
		   strcat(Menu_items[count_1],"..");
		}
	  }

       int count_2=0;

       while(Text[count_2]==' ')
	  count_2++;

       red_char_position=count_2;

       if(red_char!=0)
	  red_char_position=red_char;

       if(strlen(Text)<=25)
	  strcpy(Label,Text);

       else
	  {
	     strncpy(Label,Text,23);
	     strcat(Label,"..");
	  }

       settextstyle(0,0,1);

       x_2=(textwidth(Label)+14+x_1);
       y_2=(textheight(Label)+10+y_1);

       mid_x=(((x_1+x_2)/2)-(textwidth(Label)/2)+1);
       mid_y=(((y_1+y_2)/2)-(textheight(Label)/2)+1);

       for(int count_3=0;count_3<number_of_items;count_3++)
	  {
	     if(strlen(Menu_items[count_3])>max_length)
		max_length=strlen(Menu_items[count_3]);
	  }

       if(max_length<strlen(Label))
	  max_length=strlen(Label);

       max_length++;

       for(int count_4=0;count_4<number_of_items;count_4++)
	  {
	     while(strlen(Menu_items[count_4])<max_length)
		strcat(Menu_items[count_4]," ");
	  }

       MenuArea.Init(x_1,(y_1+17),"",(max_length*8),
					       ((number_of_items*18)-18));
    }

 /*************************************************************************/
 //------------------------------  Show( )  ------------------------------//
 /*************************************************************************/

 void Menu::Show( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setfillstyle(1,7);
	 bar(x_1,y_1,x_2,y_2);

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

       if(red_char_position!=-1)
	  outtextxy(mid_x,mid_y,Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //-----------------------------  Press( )  -----------------------------//
 /************************************************************************/

 void Menu::Press( )
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

       if(red_char_position!=-1)
	  outtextxy((mid_x+1),(mid_y+1),Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //-----------------------------  Select( )  ----------------------------//
 /************************************************************************/

 void Menu::Select( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setcolor(15);
	 line(x_1,y_1,x_2,y_1);
	 line(x_1,y_1,x_1,y_2);

       setcolor(7);
	 line((x_1+1),(y_1+1),(x_1+1),(y_2-2));
	 line((x_1+1),(y_1+1),(x_2-2),(y_1+1));

       setcolor(8);
	 line((x_1+1),(y_2-1),x_2,(y_2-1));
	 line((x_2-1),y_2,(x_2-1),(y_1+1));

       setcolor(0);
	 line(x_2,y_2,x_2,y_1);
	 line(x_1,y_2,x_2,y_2);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //------------------------------  Hit( )  ------------------------------//
 /************************************************************************/

 const int Menu::Hit( )
    {
       int x=0;
       int y=0;

       GetMouseCoordinates(&x,&y);

       return ((x>=x_1 && x<=x_2 && y>=y_1 && y<=y_2)?1:0);
    }

 /************************************************************************/
 //------------------------  SelectAndRelease( )  -----------------------//
 /************************************************************************/

 void Menu::SelectAndRelease( )
    {
       Select( );

       while(Hit( ) && !LeftMouseKeyPressed( ) && !kbhit( ));

       Show( );
    }


 /*************************************************************************/
 //----------------------  GetSelectedMenuItem( )  -----------------------//
 /************************************************************************/

 const int Menu::GetSelectedMenuItem(const int key_pressed)
    {
       Press( );

       int image_size=0;

       char *Bitmap=NULL;

       image_size=imagesize((x_1-5),(y_1+17),(x_1+20+(max_length*8)),
					      (y_1+25+(number_of_items*18)));
       Bitmap=new char[image_size];

       HideMouse( );

       getimage((x_1-5),(y_1+17),(x_1+20+(max_length*8)),
				       (y_1+25+(number_of_items*18)),Bitmap);

       for(int count_1=0;count_1<number_of_items;count_1++)
	  {
	     MenuItems[count_1].Init(x_1,(y_1+19+(count_1*18)),
						   Menu_items[count_1],0,-2);
	     MenuItems[count_1].Show( );
	  }

       ShowMouse( );

       int flag_1=0;
       int flag_2=0;
       int selected=0;

       do
	  {
	     if(key_pressed==LEFT_MOUSE_KEY)
		{
		   for(int count_2=0;count_2<number_of_items;count_2++)
		      {
			 if(MenuItems[count_2].Hit( ))
			    MenuItems[count_2].HilightAndRelease( );

			 if(MenuItems[count_2].Hit( ) &&
						     LeftMouseKeyPressed( ))
			    {
			       selected=(count_2+1);
			       flag_1=1;

			       break;
			    }

			 if(kbhit( ))
			    {
			       selected=0;
			       flag_1=1;

			       break;
			    }
		      }

		if(flag_1)
		   break;

		if(!MenuArea.Hit( ) && !Hit( ))
		   {
		      selected=0;

		      break;
		   }
		}

	     if(key_pressed==KEY_BOARD)
		{
		   if(kbhit( ))
		      {
			 char Key_1=NULL;
			 char Key_2=NULL;

			 int key_code_1=0;
			 int key_code_2=0;

			 Key_1=getch( );
			 key_code_1=int(Key_1);

			 if(key_code_1==0)
			    {
			       Key_2=getch( );
			       key_code_2=int(Key_2);
			    }

			 if(key_code_1==13)
			    {
			       selected++;

			       break;
			    }

			 else if(key_code_1==27)
			    {
			       selected=0;

			       break;
			    }

			 else if(key_code_1==0 && key_code_2==72)
			    {
			       if(!flag_2)
				  {
				     flag_2=1;
				     selected=(number_of_items-1);
				  }

			       else
				  selected--;

			       if(selected==-1)
				  selected=(number_of_items-1);

			       MenuItems[selected].HilightAndRelease(KEY_BOARD);
			    }

			 else if(key_code_1==0 && key_code_2==80)
			    {
			       if(!flag_2)
				  {
				     flag_2=1;
				     selected=0;
				  }

			       else
				  selected++;

			       if(selected==number_of_items)
				  selected=0;

			       MenuItems[selected].HilightAndRelease(KEY_BOARD);
			    }
		      }
		}
	  }
       while(1);

       HideMouse( );

       putimage((x_1-5),(y_1+17),Bitmap,0);

       ShowMouse( );

       delete Bitmap;

       Show( );

       return selected;
    }

 /*************************************************************************/
 /*************************************************************************/
 //------------------------------  THE END  ------------------------------//
 /*************************************************************************/
 /*************************************************************************/