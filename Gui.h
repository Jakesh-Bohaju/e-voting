
 /**************************************************************************
  **************************************************************************
  ******************************  Gui.h  ***********************************
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
 //---------------------------  Header Files  ----------------------------//
 /*************************************************************************/
 /*************************************************************************/

 # include <iostream.h>
 # include <graphics.h>
 # include   <string.h>
 # include   <stdlib.h>
 # include    <stdio.h>
 # include    <conio.h>
 # include    <ctype.h>
 # include     <math.h>
 # include      <dos.h>

 /*************************************************************************/
 /*************************************************************************/
 //----------------------  Global Constant Variables  --------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //----------------------------  Panel , Bevel  --------------------------//
 /*************************************************************************/

 # define IN               0
 # define OUT              1

 # define THICK            0
 # define THIN             1

 /*************************************************************************/
 //-----  Button,RoundButton,FlatButton,Menu,OptionButton,MessageBox  ----//
 /*************************************************************************/

 # define KEY_BOARD        0
 # define LEFT_MOUSE_KEY   1
 # define RIGHT_MOUSE_KEY  2

 /*************************************************************************/
 //-----------------------------  GetInput  ------------------------------//
 /*************************************************************************/

 # define NUMBER           0
 # define CHARACTER        1
 # define ANYTHING         2

 /*************************************************************************/
 //----------------------------  FlatButton  -----------------------------//
 /*************************************************************************/

 # define BORDER           0
 # define NOBORDER         1

 /*************************************************************************/
 //----------------------------  RoundButton  ----------------------------//
 /*************************************************************************/

 # define LEFT_SIDE        0
 # define RIGHT_SIDE       1
 # define BOTH_SIDES       2

 /*************************************************************************/
 //----------------------------  MessageBox  -----------------------------//
 /*************************************************************************/

 # define OK               0
 # define YES_NO           1
 # define OK_CANCEL        2
 # define YES_NO_CANCEL    3

 # define INFORMATION      0
 # define EXCLAMATION      1
 # define QUESTION         2
 # define STOP             3


 /*************************************************************************/
 /*************************************************************************/
 //-------------------  General Functions Prototypes  --------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //--------------------------------  GUI  --------------------------------//
 /*************************************************************************/

 void GetCurrentSettings( );
 void RestorePreviousSettings( );
 void InitGraphicMode( );

 /*************************************************************************/
 //------------------------------  Print3d  ------------------------------//
 /*************************************************************************/

 void Print3d(const int,const int,const char*,const int=15,const int=0);
 void Print3d(const int,const int,const long double,const int=15,const int=0);

 /*************************************************************************/
 //----------------------------  Heading  --------------------------------//
 /*************************************************************************/

 void Heading(const int,const int,const char*,const int=12,
						   const int=5,const int=1);

 /*************************************************************************/
 //----------------------------  MessageBox  -----------------------------//
 /*************************************************************************/

 void MessageBox(const char*,const char*);

 const int MessageBox(const char*,const char*,const int,const int=OK);

 /*************************************************************************/
 //-----------------------------  GetInput  ------------------------------//
 /*************************************************************************/

 const char* GetInput(const int,const int,int,
				const int=15,const int=8,const int=ANYTHING);


 /*************************************************************************/
 /*************************************************************************/
 //------------------------  Class Definitions  --------------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //------------------------------  Button  -------------------------------//
 /*************************************************************************/

 class Button
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;
	     int text_color;
	     int button_color;
	     int red_char_position;

	     char Label[35];

       public:
	     Button( );
	     ~Button( )  {  }

	     const int Hit( );

	     void Show( );
	     void Press( );
	     void PressAndRelease(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,const int=0,
			    const int=0,const int=7,const int=0,const int=0);
    };

 /*************************************************************************/
 //----------------------------  RoundButton  ----------------------------//
 /*************************************************************************/

 class RoundButton
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;
	     int radius;
	     int text_color;
	     int button_color;
	     int rounded_side;
	     int red_char_position;

	     char Label[35];

       public:
	     RoundButton( );
	     ~RoundButton( )  {  }

	     const int Hit( );

	     void Show( );
	     void Press( );
	     void PressAndRelease(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,const int=2,
				    const int=0,const int=0,const int=7,
						    const int=0,const int=0);
    };

 /*************************************************************************/
 //----------------------------  FlatButton  -----------------------------//
 /*************************************************************************/

 class FlatButton
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;
	     int text_color;
	     int button_color;
	     int border_noborder;
	     int red_char_position;

	     char Label[35];

       public:
	     FlatButton( );
	     ~FlatButton( )  {  }

	     const int Hit( );

	     void Show( );
	     void Press( );
	     void Select( );
	     void SelectAndRelease(const int=LEFT_MOUSE_KEY);
	     void PressAndRelease(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,const int=BORDER,
					const int=0,const int=0,const int=7,
						    const int=0,const int=0);
    };

 /*************************************************************************/
 //--------------------------------  Menu  -------------------------------//
 /*************************************************************************/

 class Menu_Button
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;

	     char Label[35];

       public:
	     Menu_Button( );
	     ~Menu_Button( )  {  }

	     const int Hit( );

	     void Show( );
	     void Release( );
	     void Hilight( );
	     void HilightAndRelease(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,
						    const int=0,const int=0);
    };

 class Menu
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int mid_x;
	     int mid_y;
	     int max_length;
	     int number_of_items;
	     int red_char_position;

	     char Label[35];
	     char Menu_items[10][35];

	     Menu_Button MenuArea;
	     Menu_Button MenuItems[10];

       public:
	     Menu( );
	     ~Menu( )  {  }

	     const int Hit( );
	     const int
			 GetSelectedMenuItem(const int=LEFT_MOUSE_KEY);

	     void Show( );
	     void Press( );
	     void Select( );
	     void SelectAndRelease( );
	     void Init(const int,const int,const char *,
					const int,const int,const char* []);
    };

 /*************************************************************************/
 //------------------------------  EditBox  ------------------------------//
 /*************************************************************************/

 class EditBox
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int max_length;

	     char Editbox_value[90];

       public:
	     EditBox( );
	     ~EditBox( )  {  }

	     const int Hit( );

	     const char* GetValue( );

	     void Show( );
	     void GetUserInput( );
	     void SetValue(const char*);
	     void Init(const int,const int,const char*,
						  const int=10,const int=0);
    };

 /*************************************************************************/
 //----------------------------  OptionButton  ---------------------------//
 /*************************************************************************/

 class Option_Button
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int check;
	     int box_color;
	     int text_color;

	     char Label[90];

       public:
	     Option_Button( );
	     ~Option_Button( )  {  }

	     const int Hit( );
	     const int Checked( );

	     void Show( );
	     void Clear( );
	     void Press( );
	     void Select(const int=LEFT_MOUSE_KEY);
	     void Init(const int,const int,const char *,
			    int=0,const int=7,const int=0);
    };

 class OptionButton
    {
       private:
	     int max_length;
	     int default_selected;
	     int number_of_options;

	     char Option_items[10][90];

	     Option_Button Options[10];

       public:
	     OptionButton( );
	     ~OptionButton( )  {  }

	     const int Hit( );
	     const int
			   GetSelectedOption(const int=LEFT_MOUSE_KEY);

	     void Show( );
	     void SelectAndRelease( );
	     void ChangeSelectedOption(const int);
	     void Init(const int,const int,const int,const char* [],
				    const int=1,const int=0,const int=0,
						   const int=7,const int=0);
	     void DrawBorder(const int,const int,const int,
						     const int,const char*);
    };

 /*************************************************************************/
 //-----------------------------  CheckBox  ------------------------------//
 /*************************************************************************/

 class CheckBox
    {
       private:
	     int x_1;
	     int y_1;
	     int x_2;
	     int y_2;
	     int check;
	     int box_color;
	     int text_color;
	     int default_check;

	     char Label[90];

       public:
	     CheckBox( );
	     ~CheckBox( )  {  }

	     const int Hit( );
	     const int Checked( );

	     void Show( );
	     void Press( );
	     void SelectAndRelease( );
	     void Init(const int,const int,const char *,const int=0,int=0,
						   const int=7,const int=0);
    };

 /*************************************************************************/
 //-------------------------------  Panel  -------------------------------//
 /*************************************************************************/

 class Panel
    {
       private:
	     int x_1;
	     int x_2;
	     int y_1;
	     int y_2;
	     int in_out;
	     int thick_thin;
	     int panel_color;

       public:
	     Panel( );
	     ~Panel( )  {  }

	     const int Hit( );

	     void Show( );
	     void Init(const int,const int,const int,const int,const int,
						     const int,const int=7);
    };

 /*************************************************************************/
 //-------------------------------  Bevel  -------------------------------//
 /*************************************************************************/

 class Bevel_Panel
    {
       private:
	     int x_1;
	     int x_2;
	     int y_1;
	     int y_2;
	     int in_out;
	     int thick_thin;
	     int panel_color;

       public:
	     Bevel_Panel( );
	     ~Bevel_Panel( )  {  }

	     void Show( );
	     void Init(const int,const int,const int,const int,const int,
						      const int,const int=7);
    };

 class Bevel
    {
	private :
	     int x_1;
	     int x_2;
	     int y_1;
	     int y_2;

	     Bevel_Panel OuterBevel;
	     Bevel_Panel InnerBevel;

	public :
		Bevel( )   {  }
		~Bevel( )  {  }

		const int Hit( );

		void Show( );
		void Init(const int,const int,const int,const int,
						     const int,const int=7);
    };

 /*************************************************************************/
 /*************************************************************************/
 //-----------------------------  THE END  -------------------------------//
 /*************************************************************************/
 /*************************************************************************/