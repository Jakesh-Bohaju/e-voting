// # include  "window.h"
 # include  "Gui.h"
 # include  "Mouse.h"
 # include  "string.h"
 # include  "BmpLib.h"
 # include  "stdlib.h"

 /*************************************************************************/
 //-------------------  Global Variables & Objects -----------------------//
 /*************************************************************************/
 long int aa[10],sa[10],bb[10],as[10];
 int count=0,x,y,button,ii=0;
 long int n,m=756482,j,k,l,o;
 FlatButton Next,Back,Exit;
 EditBox EditBox_1,EditBox_2,EditBox_3,EditBox_4,EditBox_5,EditBox_6,EditBox_7,EditBox_8;

 /*************************************************************************/
 //------------------------  Function Prototypes  ------------------------//
 /*************************************************************************/

 void show_main_screen( );
 void show_bevel_demo( );
 void show_round_button_demo( );
 void getmousepos(int *,int *,int *);
 void select_next_move( );
 void voter_registration( );
 void party_registration( );
 void candidate_registration( );
 void symbol();
 void voting();
 void result();
 void about_programmer();
 void exit();
 void show();

FILE *fp,*fp1;
 static long int vote1=0,  vote2=0,  vote3=0,  vote4=0,  vote5=0,  vote6=0,  vote7=0,  vote8=0,  vote9=0,  vote10=0, vote11=0, vote12=0, vote13=0, vote14=0, vote15=0, vote16=0, vote17=0, vote18=0, vote19=0, vote20=0,  vote21=0,  vote22=0,  vote23=0,  vote24=0,  vote25=0,  vote26=0,  vote27=0,  vote28=0,  vote29=0,  vote30=0,  vote31=0;
 struct
{
       char z[11],v[11],name[40],fname[40],mname[40],address[40],partyname[50],year[4],month[2],day[2],gender[6],citizenno[11],voterno[11],symbol[10];

       long int zz;
}s;


 /*************************************************************************/
 /*************************************************************************/
 //----------------------------  main( )  --------------------------------//
 /*************************************************************************/
 /*************************************************************************/



 int main( )
    {


       int driver=VGA;

    int mode=VGAHI;
    int error_code;

    initgraph(&driver,&mode,"..\\Bgi");

       InitGraphicMode( );
       InitMouse( );

       ShowMouse( );

       show_main_screen( );

       Back.Init(10,10,"<<",BORDER,10,3,3);
       Back.Show( );

       Next.Init(20,445," Next ",BORDER,0,0,3);
       Next.Show( );

       Exit.Init(605,10,"X",BORDER,0,0,3);
       Exit.Show( );



       do
	  {

	      select_next_move( );
	  }
       while(count<=2);

       HideMouse( );

       closegraph( );

       return 0;
    }

 /*************************************************************************/
 /*************************************************************************/
 //------------------------  Function Definitions  -----------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //-----------------------  show_main_screen( )  -------------------------//
 /*************************************************************************/

 void show_main_screen( )
    {
       cleardevice( );

       Bevel Main_screen;

       Main_screen.Init(5,5,(getmaxx( )-5),(getmaxy( )-5),THIN,5);
       Main_screen.Show( );

       HideMouse( );

       setfillstyle(11,1);			//BACKGROUND PATTERN of 1st SCREEN
	 bar(10,10,(getmaxx( )-10),(getmaxy( )-10));	//SIZE OF PATTERN

       settextstyle(8,0,6);
	 setcolor(3);
	   outtextxy(47,153,"E-VOTING SYSTEM");	   outtextxy(48,153,"E-VOTING SYSTEM");	   outtextxy(48,152,"E-VOTING SYSTEM");	   outtextxy(49,152,"E-VOTING SYSTEM"); 	   outtextxy(49,151,"E-VOTING SYSTEM");	   outtextxy(49,150,"E-VOTING SYSTEM");	   outtextxy(50,150,"E-VOTING SYSTEM");
	 setcolor(YELLOW);
	   outtextxy(50,150,"E-VOTING SYSTEM");	   outtextxy(51,150,"E-VOTING SYSTEM");	   outtextxy(52,150,"E-VOTING SYSTEM");


	 settextstyle(2,0,6);
	 setcolor(YELLOW);


	 setcolor(YELLOW);
	   outtextxy(335,220,"Nepal Election Comission");


       ShowMouse( );
      SetMouseCoordinates(320,240);
     }
 /*************************************************************************/
 //-----------------------  about_programmer(int)  -----------------------//
 /*************************************************************************/





 void about_programmer()
    {
	   select_next_move( );
	   Heading(50,40,"E-VOTING SYSTEM",14,7,2);
	settextstyle(2,0,4);
	 setcolor(7);
	   outtextxy(100,360,"Nepal Election Comission");
     setcolor(15);
	   outtextxy(45,380,"Third Semester Project");
	   outtextxy(45,390,"Anil Tukanbanjar");
	   outtextxy(45,400,"Jakesh Bohaju");
	   outtextxy(45,410,"Shrawan Mahato");
	   outtextxy(45,432,"Khwopa Engineering College");

       ShowMouse( );


       ShowMouse( );

       Print3d(30,360,"E-VOTING SYSTEM");
       Print3d(50,370,"Nepal Election Comissiopn");
       Print3d(30,400,"CA Election 2072");
       Print3d(30,440,"Khwopa Engineering College");
    }



 /*************************************************************************/
 //-----------------------  select_next_move( )  -------------------------//
 /*************************************************************************/

 void select_next_move( )
    {
       int selected=0;

       if(Back.Hit( ) && count!=1)
	  Back.SelectAndRelease( );

	if(Next.Hit( ) && count<2)
	  Next.SelectAndRelease( );

       else if(Exit.Hit( ))
	  Exit.SelectAndRelease( );

       if(LeftMouseKeyPressed( ) && Back.Hit( ) && count!=1)
	  {
	     Back.PressAndRelease(LEFT_MOUSE_KEY);
	     count--;
	     selected=1;
	  }

	if(LeftMouseKeyPressed( ) && Next.Hit( ) && count<2)
	  {
	     Next.PressAndRelease(LEFT_MOUSE_KEY);

	     count++;
	     selected=1;
	  }

       else if(LeftMouseKeyPressed( ) && Exit.Hit( ))
	  {
	     Exit.PressAndRelease(LEFT_MOUSE_KEY);
	    // selected=MessageBox("Are you sure to exit EVS ?","E-Voting System",QUESTION,YES_NO);
	     exit();
	  }

       else if(kbhit( ))
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

	     if((key_code_1==8 || (key_code_1==0 && key_code_2==51))
								 && count!=1)
		{
		   Back.PressAndRelease(KEY_BOARD);

		   count--;
		   selected=1;
		}

	     else if((key_code_1==13 || (key_code_1==0 && key_code_2==52))
								 && count<20)
		{
		   Next.PressAndRelease(KEY_BOARD);

		   count++;
		   selected=1;
		}

	     else if(key_code_1==27 || (key_code_1==0 && key_code_2==18))
		{
		   Exit.PressAndRelease(KEY_BOARD);
		//   selected=MessageBox("Are you sure to exit EVS ?","E-Voting System",QUESTION,YES_NO);
		   exit();
		}
	  }

       if(selected)
	  {
	     HideMouse( );

	     setfillstyle(11,3);
	       bar(10,10,(getmaxx( )-10),(getmaxy( )-50));

	     ShowMouse( );
	   show_bevel_demo( );

	  }
    }


 /*************************************************************************/
 //------------------------  show_bevel_demo( )  -------------------------//
 /*************************************************************************/

      void show_bevel_demo( )
    {
       setfillstyle(11,1);			//BACKGROUND PATTERN of 1st SCREEN
	 bar(0,0,(getmaxx( )),(getmaxy( )));	//SIZE OF PATTERN
       select_next_move( );
       Bevel Thin;
       Bevel Thick;

       Bevel EditBox_window;
       Bevel Main_window;


       rectangle(95,20,550,62);

       rectangle(97,22,552,64);
       settextstyle(9,0,1);
       outtextxy(200,20,"E-Voting System ");       outtextxy(201,21,"E-Voting System ");
       setcolor(BLUE);
       outtextxy(201,21,"E-Voting System ");       outtextxy(202,22,"E-Voting System ");



	   settextstyle(2,0,8);
       setcolor(5);
       Thin.Init(55,100,255,160,THIN);
       Thin.Show( );

       outtextxy(105,105," Voter");       outtextxy(75,125,"Registration");


	Thin.Init(375,100,575,160,THIN);
       Thin.Show( );

       outtextxy(440,105,"Party");        outtextxy(395,125,"Registration");



       Thin.Init(55,200,255,260,THIN);
       Thin.Show( );

       outtextxy(95,205,"Candidate");       outtextxy(75,225,"Registration");

       Thin.Init(375,200,575,260,THIN);
       Thin.Show( );

       outtextxy(435,215,"Voting");


       Thin.Init(55,300,255,360,THIN);
       Thin.Show( );

       outtextxy(118,315,"Result");


       Thin.Init(375,300,575,360,THIN);
       Thin.Show( );

       outtextxy(448,315,"About");



       setcolor(1);
       outtextxy(104,104," Voter");        outtextxy(74,124,"Registration");       outtextxy(103,104," Voter");        outtextxy(73,124,"Registration");


       outtextxy(439,104,"Party");       outtextxy(394,124,"Registration");        outtextxy(438,104,"Party");        outtextxy(393,124,"Registration");


       outtextxy(94,205,"Candidate");        outtextxy(74,225,"Registration");       outtextxy(93,205,"Candidate");       outtextxy(73,225,"Registration");


      outtextxy(434,215,"Voting");       outtextxy(433,215,"Voting");


      outtextxy(117,315,"Result");       outtextxy(116,315,"Result");


      outtextxy(447,315,"About");        outtextxy(446,315,"About");




      do
      {   select_next_move( );

	  getmousepos(&button,&x,&y);

 if((button&1)==1&&x>55&&x<255&&y>100&&y<160)
{
  cleardevice();
  voter_registration();
  break;   }

  if((button&1)==1&&x>375&&x<575&&y>100&&y<160)
{
  cleardevice();
  party_registration();
  break;   }

  else if((button&1)==1&&x>55&&x<255&&y>200&&y<260)
{cleardevice();
  candidate_registration();
  break;      }

     else if((button&1)==1&&x>375&&x<575&&y>200&&y<260)
{cleardevice();
voting();

  break;      }
else if((button&1)==1&&x>55&&x<255&&y>300&&y<360)
{cleardevice();
  result();
  break;       }
else if((button&1)==1&&x>375&&x<575&&y>300&&y<360)
{cleardevice();
  about_programmer();
  break;      }

}            // END OF DO
while(1);
}


	 /*************************************************************************/
 //------------------------  voter_registration( )  -----------------------//
 /*************************************************************************/

  void voter_registration( )
    {  show();
       select_next_move( );

    fp=fopen("voterreg.txt","a+");

     char *cizno;
       settextstyle(8,0,4);
       outtextxy(155,40,"Voter Registration ");         outtextxy(156,41,"Voter Registration ");
       setcolor(WHITE);
       outtextxy(156,42,"Voter Registration ");         outtextxy(157,42,"Voter Registration ");



       Print3d(35,155,"Citizenship No.:",8);        Print3d(35,185,"Full Name      :",8);        Print3d(35,215,"Father Name    :",8);        Print3d(35,245,"Mother Name    :",8);        Print3d(35,275,"District       :",8);        Print3d(35,305,"Ward No.       :",8);        Print3d(35,335,"Date of Birth  :",8);        Print3d(35,365,"Gender         :",8);

       FlatButton Finish;

       Finish.Init(520,410," Finish ");
       Finish.Show( );

       static count=0;
	fprintf(fp,"\n");
      do
	  {    select_next_move( );

	     if(count>=7 && Finish.Hit() && LeftMouseKeyPressed())
	     {
		   Finish.PressAndRelease(LEFT_MOUSE_KEY );
		   {
		    n = strtol(s.v, &cizno, 10);
		    aa[ii]=n-15;
		   ltoa(aa[ii],s.z,10);
		    ii++;
		     Print3d(50,440,"Citizen no.: ");   Print3d(150,440,s.v);
		     Print3d(50,460,"Voter no.  : ");   Print3d(150,460,s.z);
		     Print3d(50,420,"Your have successfully registered");
		   }
		    break;


	      }

	      if(EditBox_1.Hit( ) && LeftMouseKeyPressed( ))
		{
		  strcpy(s.v,GetInput(162,150,11,14,1,NUMBER));
		   o = strtol(s.v, &cizno, 10);
		   bb[ii]=o;
		   ii++;
		   count++;
		 }

	      if(EditBox_2.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.name,GetInput(162,180,40,14,1,CHARACTER));
		   count++;
		 }

	     if(EditBox_3.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.fname,GetInput(162,210,40,14,1,CHARACTER));
		   count++;
		 }

	     if(EditBox_4.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.partyname,GetInput(162,240,40,14,1,CHARACTER));
		    count++;
		 }

	     if(EditBox_5.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.address,GetInput(162,270,15,14,1,CHARACTER));
		  count++;
		}

		if(EditBox_6.Hit( ) && LeftMouseKeyPressed( ))
		{
		  strcpy(s.mname,GetInput(162,300,2,14,1,NUMBER));
		  count++;
		}
		if(EditBox_7.Hit( ) && LeftMouseKeyPressed( ))
		{outtextxy(450,335,"(DD-MM-YYYY  in BS)");  strcpy(s.day,GetInput(162,330,2,14,1,NUMBER)); j=atoi(s.day);outtextxy(185,335,"-"); strcpy(s.month,GetInput(190,330,2,14,1,NUMBER));k=atoi(s.month); outtextxy(213,335,"-"); strcpy(s.year,GetInput(218,330,4,14,1,NUMBER));l=atoi(s.year);if(j>30||k>12){outtextxy(270,335,"Not Valid");}
		   else {n=l*365+k*30+j;n=m-n;if(n<6574){outtextxy(270,335,"You are less than 18");break;} }
		count++;

		}
		if(EditBox_8.Hit( ) && LeftMouseKeyPressed( ))
		{
		 strcpy(s.gender,GetInput(162,360,6,14,1,CHARACTER));
		 count++;

		}


	       }
       while(1);

	      fwrite(&s,sizeof(s),1,fp);
       fclose(fp);

       count=0;
 }


	 /*************************************************************************/
 //------------------------  Candidate_registration( )  -----------------------//
 /*************************************************************************/

  void candidate_registration( )
    {
    show();
       select_next_move( );
	fp=fopen("candidatereg.txt","a+");

      settextstyle(8,0,4);
       outtextxy(120,40,"Candidate Registration ");         outtextxy(121,41,"Candidate Registration ");
       setcolor(WHITE);
       outtextxy(121,42,"Candidate Registration ");         outtextxy(122,42,"Candidate Registration ");


       Print3d(35,155,"Citizenship No.:",8);        Print3d(35,185,"Full Name      :",8);        Print3d(35,215,"Father Name    :",8);        Print3d(35,245,"Party  Name    :",8);        Print3d(35,275,"District       :",8);        Print3d(35,305,"Ward No.       :",8);        Print3d(35,335,"Date of Birth  :",8);        Print3d(35,365,"Gender         :",8);

       FlatButton Finish;

       Finish.Init(520,410," Finish ");
       Finish.Show( );

       static count=0;
	fprintf(fp,"\n");
      do
	  {    select_next_move( );

	     if(count>=7 && Finish.Hit() && LeftMouseKeyPressed())
	     {
		   Finish.PressAndRelease(LEFT_MOUSE_KEY );
		   {
		   Print3d(50,450,"You have successfully registered");
		   }
		    break;


	      }

	      if(EditBox_1.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.citizenno,GetInput(162,150,11,14,1,NUMBER));
		   count++;
		 }

	      if(EditBox_2.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.name,GetInput(162,180,40,14,1,CHARACTER));
		   count++;
		 }

	     if(EditBox_3.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.fname,GetInput(162,210,40,14,1,CHARACTER));
		   count++;
		 }

	     if(EditBox_4.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.partyname,GetInput(162,240,50,14,1,CHARACTER));
		    count++;
		 }

	     if(EditBox_5.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.address,GetInput(162,270,15,14,1,CHARACTER));
		  count++;
		}

		if(EditBox_6.Hit( ) && LeftMouseKeyPressed( ))
		{
		  strcpy(s.mname,GetInput(162,300,2,14,1,NUMBER));
		  count++;
		}
		if(EditBox_7.Hit( ) && LeftMouseKeyPressed( ))
		{outtextxy(450,335,"(DD-MM-YYYY  in BS)");  strcpy(s.day,GetInput(162,330,2,14,1,NUMBER)); j=atoi(s.day);outtextxy(185,335,"-"); strcpy(s.month,GetInput(190,330,2,14,1,NUMBER));k=atoi(s.month); outtextxy(213,335,"-"); strcpy(s.year,GetInput(218,330,4,14,1,NUMBER));l=atoi(s.year); if(j>30||k>12){outtextxy(270,335,"Not Valid");}
		  else {n=l*365+k*30+j;n=m-n;if(n<9129){outtextxy(270,335,"You are less than 25");break;}} count++;

		}
		if(EditBox_8.Hit( ) && LeftMouseKeyPressed( ))
		{
		 strcpy(s.gender,GetInput(162,360,6,14,1,CHARACTER));
		 count++;

		}


	       }
       while(1);

	      fwrite(&s,sizeof(s),1,fp);
       fclose(fp);

       count=0;
 }


	 /*************************************************************************/
 //------------------------  Party_registration( )  -----------------------//
 /*************************************************************************/

  void party_registration( )
    {
       show();
       select_next_move( );

    fp=fopen("partyreg.txt","a+");
       settextstyle(8,0,4);
       outtextxy(155,40,"Party Registration ");       outtextxy(156,41,"Party Registration ");
       setcolor(WHITE);
       outtextxy(156,42,"Party Registration ");       outtextxy(157,42,"Party Registration ");



       Print3d(35,155,"Symbol        :",8);          Print3d(35,185,"Party Reg No. :",8);          Print3d(35,215,"Full Name     :",8);          Print3d(35,245,"Name in Short :",8);          Print3d(35,275,"Address       :",8);          Print3d(35,305,"President     :",8);       Print3d(35,335,"Estd Date     :",8);   Print3d(35,365,"Contact no.   :",8);

       FlatButton Finish;

       Finish.Init(520,410," Finish ");
       Finish.Show( );

       static count=0;
	fprintf(fp,"\n");
  //     for(int i=0;i<1;i++)
    //   {
       do
	  {    select_next_move( );

	     if(count>=8 && Finish.Hit() && LeftMouseKeyPressed())
	     {
		   Finish.PressAndRelease(LEFT_MOUSE_KEY );
		   {

		   Print3d(50,450,"Your party have successfully registered");
		   }

		    break;


	      }

	      if(EditBox_1.Hit( ) && LeftMouseKeyPressed( ))
		{  outtextxy(310,157,"symbolname.bmp  in 1bit 50*70 pixel");
		   strcpy(s.symbol,GetInput(162,150,15,14,1));
		   LoadBmp(550,40,s.symbol);
		   count++;
		 }

	      if(EditBox_2.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.citizenno,GetInput(162,180,5,14,1,NUMBER));
		   count++;
		 }

	     if(EditBox_3.Hit( ) && LeftMouseKeyPressed( ))
		{
		   strcpy(s.partyname,GetInput(162,210,50,14,1,CHARACTER));
		   count++;
		 }

	     if(EditBox_4.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.name,GetInput(162,240,5,14,1,CHARACTER));
		    count++;
		 }

	     if(EditBox_5.Hit( ) && LeftMouseKeyPressed( ))
		{
		    strcpy(s.address,GetInput(162,270,20,14,1,CHARACTER));
		  count++;
		}

		if(EditBox_6.Hit( ) && LeftMouseKeyPressed( ))
		{
		  strcpy(s.fname,GetInput(162,300,20,14,1,CHARACTER));
		  count++;
		}
		if(EditBox_7.Hit( ) && LeftMouseKeyPressed( ))
		{outtextxy(450,335,"(DD-MM-YYYY  in BS)");   strcpy(s.day,GetInput(162,330,2,14,1,NUMBER)); j=atoi(s.day);outtextxy(185,335,"-"); strcpy(s.month,GetInput(190,330,2,14,1,NUMBER));k=atoi(s.month); outtextxy(213,335,"-"); strcpy(s.year,GetInput(218,330,4,14,1,NUMBER)); if(j>30||k>12){outtextxy(270,335,"Not Valid");}

		   count++;

		}
		if(EditBox_8.Hit( ) && LeftMouseKeyPressed( ))
		{  	strcpy(s.mname,GetInput(162,360,10,14,1,NUMBER));
		  count++;

		}


	       }
       while(1);

	      fwrite(&s,sizeof(s),1,fp);
       fclose(fp);
       count=0;
 }


 void voting( )
    {
    fp1=fopen("voterlogin.txt","a");
    cleardevice();
    setfillstyle(11,1);			//BACKGROUND PATTERN of 1st SCREEN
	 bar(0,0,(getmaxx( )-0),(getmaxy( )-0));
  select_next_move( );            /*
struct no
{
 char czno[11],vtno[11];
 }j1,j2;   */
  long int vtno,czno;
  char cno[11],vno[11],*q;
   setcolor(WHITE);
   settextstyle(2,0,8);
   outtextxy(40,150,"Enter Citizen number and Voter number...");

  Print3d(80,220,"Citizenship Number :",8);
  strcpy(cno,GetInput(250,216,11,1,7,NUMBER));
  Print3d(80,270,"Voter Number       :",8);
  strcpy(vno,GetInput(250,266,11,1,7,NUMBER));
  czno = strtol(cno, &q, 10);
  vtno = strtol(vno, &q, 10);
  for(int iii=0;iii<ii;iii++)
  {
  if(vtno==aa[iii] )
  { cout<<vtno<<endl<<aa[iii]<<endl<<bb[iii]<<endl<<czno;
  if(sa[iii]!=aa[iii])
     {
     cout<<vtno<<endl<<czno<<aa[iii]<<endl<<bb[iii];
     symbol();
     sa[iii]=vtno;
     as[iii]=czno;
     delay(2000);
     show_bevel_demo( );
     }
     }
     }

  /* fp=fopen("voterregistration.txt","r+");
   while(fread(&s,sizeof(s),1,fp)==1)
   {                                             cout<<"while works";
	 cout<<j1.czno<<endl<<j1.vtno<<endl<<s.v<<endl<<s.z;
	 char c[11];
	 strcpy(c,s.v);
	if(strcmp(j1.czno,c)==0)// || strcmp(j1.vtno,s.z)==0)
	{                       cout<<"if works";
	     //	fp1=fopen("voterlogin.txt","r+");
	      //	while(fread(&j1,sizeof(j1),1,fp1)==1)
	       //	{
		if(strcmp(j1.czno,s.v)==0)// || strcmp(j1.vtno,s.z)==0)
		{
			cout<<"You have already done voting";
		}
		else
		{       symbol();
			fprintf(fp1,j1.czno);
			fprintf(fp1,j1.vtno);
			//symbol();
		}
	    //	}
	}
	else
	{
		cout<<"You are not registered\n";
	}
   }
   fclose(fp);
   fclose(fp1);      */
}


 //*************************************************************************/
 //------------------------  symbol( )  -----------------------//
 /*************************************************************************/

  void symbol( )
  {
    cleardevice();

    select_next_move( );

    fp=fopen("voting.txt","a");
  //  fp=fopen("partyreg.txt","r");
  //  int z=10,y=10;
  //  for(int i=1;i<=p;i++)
  //  { LoadBmp(z,y,s.symbol);
  //  z=z+50;
  //  y=y+70;
  //  }


	int select;
	LoadBmp(20,50,"s//s1.bmp");LoadBmp(80,50,"s//s2.bmp");    LoadBmp(140,50,"s//s3.bmp");     LoadBmp(200,50,"s//s4.bmp");    LoadBmp(260,50,"s//s5.bmp");    LoadBmp(320,50,"s//s6.bmp");    LoadBmp(380,50,"s//s7.bmp");    LoadBmp(440,50,"s//s8.bmp");     LoadBmp(500,50,"s//s9.bmp");    LoadBmp(560,50,"s//s10.bmp");    LoadBmp(20,150,"s//s11.bmp");     LoadBmp(80,150,"s//s12.bmp");    LoadBmp(140,150,"s//s13.bmp");    LoadBmp(200,150,"s//s14.bmp");    LoadBmp(260,150,"s//s15.bmp");    LoadBmp(320,150,"s//s16.bmp");    LoadBmp(380,150,"s//s17.bmp");     LoadBmp(440,150,"s//s18.bmp");     LoadBmp(500,150,"s//s19.bmp");    LoadBmp(560,150,"s//s20.bmp");    LoadBmp(20,250,"s//s21.bmp");     LoadBmp(80,250,"s//s22.bmp");    LoadBmp(140,250,"s//s23.bmp");    LoadBmp(200,250,"s//s24.bmp");    LoadBmp(260,250,"s//s25.bmp");    LoadBmp(320,250,"s//s26.bmp");    LoadBmp(380,250,"s//s27.bmp");    LoadBmp(440,250,"s//s28.bmp");     LoadBmp(500,250,"s//s29.bmp");       LoadBmp(560,250,"s//s30.bmp");
	LoadBmp(20,350,s.symbol);
  //	LoadBmp(20,350,"s//s31.bmp");    LoadBmp(80,350,"s//s32.bmp");      LoadBmp(140,350,"s//s33.bmp");   LoadBmp(200,350,"s//s34.bmp");             LoadBmp(260,350,"s//s35.bmp");    LoadBmp(320,350,"s//s36.bmp");    LoadBmp(380,350,"s//s37.bmp");   LoadBmp(440,350,"s//s38.bmp");
  //    fp=fopen("Voting.txt","a");			LoadBmp(500,350,"s//s39.bmp");    LoadBmp(560,350,"s//s40.bmp");

	do
	{
		getmousepos(&button,&x,&y);
		if((button&1)==1&&x>475&&x<580&&y>250&&y<280)
		{
		  break;
		}
		else if((button&1)==1&&x>20&&x<70&&y>50&&y<120)
		{
		       sound(1200);     delay(500);      nosound();
		       vote1++;         fprintf(fp,"\nNepal Comunist Party (Yekikrit Marksbadi Leninbadi) = %ld",vote1); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");         break;
		}
		else if((button&1)==1&&x>80&&x<130&&y>50&&y<120)
		{
			sound(1200);     delay(500);    nosound();
			vote2++;     fprintf(fp,"\nYekikrit Nepal Comunist party (Maobadi)             = %ld",vote2);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>140&&x<190&&y>50&&y<120)
		{
			sound(1200);     delay(500);      nosound();
			vote3++;      fprintf(fp,"\nRastriya Prajatantra Party Nepal                    = %ld",vote3);     setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");    break;
		}
		else if((button&1)==1&&x>200&&x<250&&y>50&&y<120)
		{
			sound(1200);      delay(500);    nosound();
			vote4++;       fprintf(fp,"\nNepali Congress                                    = %ld",vote4);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");    break;
		}
		else if((button&1)==1&&x>260&&x<310&&y>50&&y<120)
		{
			sound(1200);      delay(500);    nosound();
			vote5++;       fprintf(fp,"\nNepal Comunist Party (Maobadi - Leninbadi)          = %ld",vote5);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>320&&x<370&&y>50&&y<120)
		{
			sound(1200);    delay(500);     nosound();
			vote6++;      fprintf(fp,"\nTarai Madhesh Loktantrik Party                      = %ld",vote6);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>380&&x<430&&y>50&&y<120)
		{
			sound(1200);     delay(500);     nosound();
			vote7++;     fprintf(fp,"\nSadbhawona Party                                    = %ld",vote7);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>440&&x<490&&y>50&&y<120)
		{
			sound(1200);     delay(500);    nosound();
			vote8++;       fprintf(fp,"\nRastriya Prajatantra Party                          = %ld",vote8);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>500&&x<550&&y>50&&y<120)
		{
			sound(1200);    delay(500);     nosound();
			vote9++;     fprintf(fp,"\nMadheshi Janaadhikar Foram,Nepal (Locktantrik)      = %ld",vote9); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>560&&x<610&&y>50&&y<120)
		{
			sound(1200);    delay(500);     nosound();
			vote10++;     fprintf(fp,"\nSanghiya Locktantrik Rastriya Manch (Tharuhaat)     = %ld",vote10);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>20&&x<70&&y>150&&y<220)
		{
			sound(1200);     delay(500);      nosound();
			vote11++;         fprintf(fp,"\nNepal Pariwar Dal                                   = %ld",vote11);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>80&&x<130&&y>150&&y<220)
		{
			sound(1200);     delay(500);    nosound();
			vote12++;       fprintf(fp,"\nRastriya Janamukti Party                            = %ld",vote12);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>140&&x<190&&y>150&&y<220)
		{
			sound(1200);     delay(500);      nosound();
			vote13++;      fprintf(fp,"\nSamajbadi Janata Party                              = %ld",vote13);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>200&&x<250&&y>150&&y<220)
		{
			sound(1200);      delay(500);    nosound();
			vote14++;       fprintf(fp,"\nMadheshi Janaadhikar Foram,Nepal                    = %ld",vote14); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>260&&x<310&&y>150&&y<220)
		{
			sound(1200);      delay(500);    nosound();
			vote15++;       fprintf(fp,"\nRastriya Janamorcha                                 = %ld",vote15);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>320&&x<370&&y>150&&y<220)
		{
			sound(1200);    delay(500);     nosound();
			vote16++;      fprintf(fp,"\nNepal Comunist Party (Sanyukta)                     = %ld",vote16); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>380&&x<430&&y>150&&y<220)
		{
			sound(1200);     delay(500);     nosound();
			vote17++;     fprintf(fp,"\nNepali Janata Dal                                   = %ld",vote17);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>440&&x<490&&y>150&&y<220)
		{
			sound(1200);     delay(500);    nosound();
			vote18++;       fprintf(fp,"\nNepal Majdor Kishan Party                           = %ld",vote18);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>500&&x<550&&y>150&&y<220)
		{
			sound(1200);    delay(500);     nosound();
			vote19++;     fprintf(fp,"\nNepal Loktantrik Samajbadi Dal                      = %ld",vote19);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>560&&x<610&&y>150&&y<220)
		{
			sound(1200);    delay(500);     nosound();
			vote20++;     fprintf(fp,"\nChurebhawor Rastriya Yekata Party Nepal             = %ld",vote20); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>20&&x<70&&y>250&&y<320)
		{
			sound(1200);     delay(500);      nosound();
			vote21++;         fprintf(fp,"\nJanata Dal United                                   = %ld",vote21);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>80&&x<130&&y>250&&y<320)
		{
			sound(1200);     delay(500);    nosound();
			vote22++;       fprintf(fp,"\nNawa Nepal Nirman Party                             = %ld",vote22);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>140&&x<190&&y>250&&y<320)
		{
			sound(1200);     delay(500);      nosound();
			vote23++;      fprintf(fp,"\nDalit Janajati Party                                = %ld",vote23); setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>200&&x<250&&y>250&&y<320)
		{
			sound(1200);      delay(500);    nosound();
			vote24++;       fprintf(fp,"\nTarai Madhesh Sadbhawona Party Nepal                = %ld",vote24);setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>260&&x<310&&y>250&&y<320)
		{
			sound(1200);      delay(500);    nosound();
			vote25++;       fprintf(fp,"\nMadheshi Janaadhikar Foram (Ganatantrik)            = %ld",vote25);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>320&&x<370&&y>250&&y<320)
		{
			sound(1200);    delay(500);     nosound();
			vote26++;      fprintf(fp,"\nNepa:Rastriya Party                                 = %ld",vote26);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>380&&x<430&&y>250&&y<320)
		{
			sound(1200);     delay(500);     nosound();
			vote27++;     fprintf(fp,"\nSanghiya Sadbhawona Party                           = %ld",vote27);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>440&&x<490&&y>250&&y<320)
		{
			sound(1200);     delay(500);    nosound();
			vote28++;       fprintf(fp,"\nNepal Nagarik Party                                 = %ld",vote28);  setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>500&&x<550&&y>250&&y<320)
		{
			sound(1200);    delay(500);     nosound();
			vote29++;     fprintf(fp,"\nJana Prajatantrik Party                             = %ld",vote29);    setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
		else if((button&1)==1&&x>560&&x<610&&y>250&&y<320)
		{
			sound(1200);    delay(500);     nosound();
			vote30++;     fprintf(fp,"\nRastriya Madhesh Samajbadi Party                    = %ld",vote30);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");    break;
		}
		else if((button&1)==1&&x>20&&x<70&&y>350&&y<420)
		{
			sound(1200);     delay(500);      nosound();
			vote31++;         fprintf(fp,"\ns.partyname  = %ld",vote31);   setcolor(WHITE);       outtextxy(300,450,"Thanks for voting");     break;
		}
	}               // END OF DO
	while(1);

	fclose(fp);
	select_next_move( );
  }


 //*************************************************************************/
 //------------------------  result( )  -----------------------//
 /*************************************************************************/
 void result( )
    {
      //printf("\ns.partyname  				       	 = %ld",vote31);
	printf("\nNepal Comunist Party (Yekikrit Marksbadi Leninbadi) = %ld",vote1);
	printf("\nYekikrit Nepal Comunist party (Maobadi)             = %ld",vote2);
	printf("\nRastriya Prajatantra Party Nepal                    = %ld",vote3);
	printf("\nNepali Congress                                     = %ld",vote4);
	printf("\nNepal Comunist Party (Maobadi - Leninbadi)          = %ld",vote5);
	printf("\nTarai Madhesh Loktantrik Party                      = %ld",vote6);
	printf("\nSadbhawona Party                                    = %ld",vote7);
	printf("\nRastriya Prajatantra Party                          = %ld",vote8);
	printf("\nMadheshi Janaadhikar Foram,Nepal (Locktantrik)      = %ld",vote9);
	printf("\nSanghiya Locktantrik Rastriya Manch (Tharuhaat)     = %ld",vote10);
	printf("\nNepal Pariwar Dal                                   = %ld",vote11);
	printf("\nRastriya Janamukti Party                            = %ld",vote12);
	printf("\nSamajbadi Janata Party                              = %ld",vote13);
	printf("\nMadheshi Janaadhikar Foram,Nepal                    = %ld",vote14);
	printf("\nRastriya Janamorcha                                 = %ld",vote15);
	printf("\nNepal Comunist Party (Sanyukta)                     = %ld",vote16);
	printf("\nNepali Janata Dal                                   = %ld",vote17);
	printf("\nNepal Majdor Kishan Party                           = %ld",vote18);
	printf("\nNepal Loktantrik Samajbadi Dal                      = %ld",vote19);
	printf("\nChurebhawor Rastriya Yekata Party Nepal             = %ld",vote20);
	printf("\nJanata Dal United                                   = %ld",vote21);
	printf("\nNawa Nepal Nirman Party                             = %ld",vote22);
	printf("\nDalit Janajati Party                                = %ld",vote23);
	printf("\nTarai Madhesh Sadbhawona Party Nepal                = %ld",vote24);
	printf("\nMadheshi Janaadhikar Foram (Ganatantrik)            = %ld",vote25);
	printf("\nNepal Rastriya Party                                = %ld",vote26);
	printf("\nSanghiya Sadbhawona Party                           = %ld",vote27);
	printf("\nNepal Nagarik Party                                 = %ld",vote28);
	printf("\nJana Prajatantrik Party                             = %ld",vote29);
	printf("\nRastriya Madhesh Samajbadi Party                    = %ld",vote30);
    }


 void exit()
{
   int select;
   ShowMouse();
   select = MessageBox("  Are you sure you want to exit the program ?","E-Voting System",QUESTION,YES_NO);
   if(select == 1)
   {
   HideMouse();
   delay(1500);
   exit(0);
   }

}

void show()
{

       cleardevice();

       setfillstyle(11,1);			//BACKGROUND PATTERN of 1st SCREEN
	 bar(0,0,(getmaxx( )-0),(getmaxy( )-0));

       Bevel EditBox_window;
       Bevel Main_window;

       Main_window.Init(20,135,620,400,THIN);
       Main_window.Show( );

       EditBox_window.Init(100,30,530,100,THICK);
       EditBox_window.Show( );
       EditBox_1.Init(160,150,"",70,4);
       EditBox_1.Show( );

       EditBox_2.Init(160,180,"",70,4);
       EditBox_2.Show( );

       EditBox_3.Init(160,210,"",70,4);
       EditBox_3.Show( );

       EditBox_4.Init(160,240,"",70,4);
       EditBox_4.Show( );

       EditBox_5.Init(160,270,"",70,4);
       EditBox_5.Show( );

       EditBox_6.Init(160,300,"",70,4);
       EditBox_6.Show( );

       EditBox_7.Init(160,330,"",70,4);
       EditBox_7.Show( );


       EditBox_8.Init(160,360,"",70,4);
       EditBox_8.Show( );
     settextstyle(6,0,1);setcolor(15);  outtextxy(350,400,"Must fill all field...");
}