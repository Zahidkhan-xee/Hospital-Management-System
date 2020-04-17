//O! My Allah, My Lord HELP & GUIDE Me To Code It & Prevent This Program from Clumpsy.
#include <fstream.h>                   //WORKS ALSO AS IOSTREAM (INHERITED)
#include <iomanip.h>
#include <stdio.h>                    //Flushall(),gets()
#include <mouse.h>                    //#include <dos.h> defined inside.
#include <conio.h>                   //GOTOXY(), Getch(), Wherey(),. . .
#include <graphics.h>
#include <string.h>
#include <stdlib.h>	      //RAND()
int get_string(char *array, const int size); //To get string, specifically designed to arrays bound checking and form fill.
inline void showcursor() {
	 cout<<'_', gotoxy(wherex()-1, wherey() );
}
int db_delete() {   //Copied Code from Turbo Library . .
	   union REGS regs;
	   int ret;
	   regs.h.ah = 0x41;
	/* delete file */
	   regs.x.dx = (unsigned) "Database.txt";
	   ret = intdos(&regs, &regs);
	   /* if carry flag is set, there was an error */
	   return(regs.x.cflag ? ret : 0);
}
class patient
{
               private:
	 char address[15], phone[11],name[10], father[10];
	 char age[3],sex;
	 int id;
               public:
	 int giveid() { return id; }
	 int  getdetail();              //Getting all details of patient.
	 int showdetail();             //Showing all details of patient.
	 void lview(int);              //Show Linewise Detail, linked with interact::display
	 int  total_patients(int);       //Will Return total no of patients saved in file.
	 int  editdetails();
}OBJECT1;
class interact {
	 private:
	     char choice;
	 public:
	  void load();
	  int editpage();
	  int homepage();
	  int rec_number();                      //RESPONSIBLE FOR GETTING A CHARACTER AND StOpPING SCREEN FROM BEEN SCROLLED DOWN.
	  int display();                         //Show All Objects Stored in Files
	  int keyboard();
	  int search(int );
	  int mouse_wclose();
	  void marquee();
	  void aboutpage();
	  int insert();                    //Saving In Files
	  int problem_definition(char *, char *);  //Problem & solutions.
	  void close_window();              //Display of Close WIndow
	  void setting();
}OBJECT;
int main() {
	 char choice = 0;
	 cout.setf(ios::left);
	 OBJECT.load();
	 while(1) {
	 choice=NULL;
	 choice=OBJECT.homepage();
	 mouse.show();              //Shows Mouse.
	 switch(choice) {
	  case '1':   OBJECT.insert();       break;
	  case '2':   OBJECT.editpage();     break;
	  case '3':   	                     break;
	  case '4':   OBJECT.search(0);	     break;
	  case '6':   OBJECT.display();      break;
	  case '7':   OBJECT.aboutpage();    break;
	  case '8':   OBJECT.setting();      break;
	  case '9':
	  case 27:    return 0;                   //Esc
               } flushall();                //Flush it.
	 closegraph();
           } 		            //Loop Ends here.
}
void interact :: aboutpage() {
	 cleardevice();
	 close_window();
	 setbkcolor( BLUE );
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,100);
	 setcolor(14);                //Color Suitable 3(AVG),7(LOW) ,14(HIGH),10
	 outtextxy(43,10,"THANKS");
	 outtextxy(67,108,"FOR");
	 settextstyle(2,HORIZ_DIR,200);
	 setcolor(7);
	 outtextxy(290,140,"YOUR SUPPORT.");
	 settextstyle(2,1,7);
	 setcolor(35);
	 outtextxy(4,35,"By Anonymous #003");
	 settextstyle(2,HORIZ_DIR,5);
	 setcolor(10);
	 outtextxy(340,190,"LIKE US ON FACEBOOK:");
	 setcolor(11);
	 outtextxy(310,210,"http://WWW.FACEBOOK.COM/H1CK3R.711");
	 setcolor(1);
	 setcolor(10);
	 outtextxy(15,250, "Tested (Techniques) : Black Box Tested, Alpha Tested.");
	 gotoxy(2,18);
	 for(int loop=0 ; loop<349 && !kbhit() ; loop++) {
	 if(mouse_wclose()==1)
	 break;
	 if(loop%170 == 0)        //Prints rectangle which dimish with text
	 rectangle(4,473,634,245);                   //x,y,x,const y
	 cout<<"Developer/Programmer : Zahid Fayaz Khan.\n "
	 "Tested By : Black Box Testing, Alpha Testing\n "
	 "Reponsiblity :Design & Maintance. \n "
	 "Central Objective : Provide Assistance to the Users.\n "
	 "Type Of Software : Open Source.(Educational Purpose Only.)\n "
	 "Disclaimer : Damage Of Program By The Improper Use.\n "
	 "Thanks For Using This Software.\n\n\t\t Have a Happy Time . . "[loop];
	 delay(10);
               }
}
int interact :: homepage() {                  //FIRST PAGE
	 closegraph();
	 int gd=0 , gm;
	 initgraph(&gd,&gm,"C:\\TC\\bgi");
	 if (graphresult() != grOk) {
	   printf("Graphics error %s",grapherrormsg(graphresult()));
	   printf("\nPress any key to halt:");
	   getch();
	   exit(1);
	} cleardevice();
	 close_window();
	 mouse.show();
	 setcolor(7);
	 setbkcolor(BLUE);
	 rectangle(140,300,530,50 );  //(x1,y1,x2,const y2)
	 setpalette(3,YELLOW);
	 gotoxy(20,5);
	 cout<<"#1.Press 1 To Add A New Patient.";
	 gotoxy(20, wherey() + 1 );
	 cout<<"#2.Press 2 To Edit The Details Of A Patient.";
	 gotoxy(20, wherey() + 1 );
	 cout<<"#3.Press 3 To Delete A Patient's Details.";
	 gotoxy(20, wherey() + 1 );
	 cout<<"#4.Press 4 To search The Details Of A Patient.";
	 gotoxy(20, wherey() + 1 );
	 cout<<"#6.Press 6 To View Patients.";
	 gotoxy(20, wherey() + 1 );
	 cout<<"#7.Press 7 To Know More About Us.";
	 gotoxy(20, wherey() +1 );
	 cout<<"#8.Press 8 For Settings.";
	 gotoxy(20, wherey()+1);
	 cout<<"#9.Press 9 | Esc To Exit From The Program.";
	 gotoxy(20,17);
	 cout<<"Enter Your Choice : ";
	 while(!kbhit() )
	 marquee();
	 if(rec_number()==-1)  {
	 cout<<"Do you want to exit";
	 delay(5000);
	 }
	 return choice;
}
int interact :: rec_number() {              //This Function Is Specific For The Main Menu.
	 choice=10;
	 showcursor();
	 if(mouse_wclose()==1)
	 return -1;
         label:	 while( choice == 10 || choice== ' ') {
	 gotoxy(40,17);
	 marquee();
	 cin.get(choice);
              }
	 if( (choice <= '0' || choice >'9') && choice!=27) {  //Invalid typed case.
	 gotoxy(40,17);
	 delline();
	 gotoxy(25,18);
	 cerr<<"INVALID CHOICE."<<flush;
	 choice=10;
	 goto label;
               } gotoxy(25,18);              //TO ERASE THE WRONG TYPED WORD
	 cout<<"                   ";
	 return 0;
}
int interact :: insert() {             //SAVING details Of Object in A File.
	 fstream file;
	 cleardevice();
	 patient object;
	 file.open("Database.txt", ios::out | ios::ate);
	 /*Mouse Close Window Click, So Don't Save. */
	 if(object.getdetail()==0)       //Getting The Details from User.
	 return 0;
	 file.write( (char *) &object, sizeof(object) );
	 file.close();
}
int patient::getdetail() {                  //Getting Details Of Provoked Object
	 gotoxy(0x5, 0x7);
	 id=total_patients(1);         //Read Mode=1
	 rectangle(30,90,90,114);
	 OBJECT.close_window();
	 rectangle(135,130,580,330);
	 cout<<"ID : "<<id;
	 gotoxy(20 ,10);
	 cout<<"Enter The Name Of The Patient : ";
	 rectangle(455,143,565, 160);           //x,-17
	 line(134,168,580,168);
	 gotoxy(20,wherey()+2);
	 cout<<"Enter The Parentage Of The Patient : ";
	 rectangle(455,175,565,192);
	 gotoxy(20,wherey()+2);
	 line(134,200,580,200);
	 cout<<"Enter The Age Of The Patient  : ";
	 rectangle(455,206,565,224);
	 gotoxy(20,wherey()+2);
	 line(134,232,580,232);
	 cout<<"Enter Address Of The Patient : ";
	 rectangle(455,239,565,256);
	 gotoxy(20,wherey ()+2);
	 line(134,264,580,264);
	 cout<<"Enter Contact No. Of The Patient : +0";
	 rectangle(455,271,565,288);
	 gotoxy(20,wherey()+2);
	 line(134,296,580,296);
	 cout<<"Enter Sex Of The Patient (M/F) : ";
	 rectangle(455,303,565,320);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	 setcolor(14);                //Color Suitable 3(AVG),7(LOW) ,14(HIGH),10
	 outtextxy(25,10,"PATIENT INFORMATION.");
	 gotoxy(59,10);
	 if( get_string(name,10) == -1)        //FOR NAME.
	 return 0;
	 gotoxy(59,wherey()+2 );          //For Parent.
	 if( get_string(father,10) == -1)
	 return 0;
	 gotoxy(59,wherey()+2);            //AGE
	 if( get_string(age, 3) == -1)
	 return 0;
	 gotoxy(59,wherey()+2 );
	 if(get_string(address, 15)==-1)
	 return 0;          //Address
	 gotoxy(59,wherey()+ 2 );
	 if(get_string(phone, 11)==-1)
	 return 0;            //Phone
	 gotoxy(59, wherey()+ 2 );
	 flushall();
	 showcursor();
	 sex=getch();
	 (sex>='a' && sex<='z') ? sex=sex-32 : sex=sex;
	 cout<<sex<<"   ";
	 sex=='M'? cout<<"(MALE)." : sex == 'F' ? cout<< "(FEMALE)." : cout<<"UNKNOWN.";
	 strupr(name), strupr(address), strupr(father);
	 id=total_patients(0);           //increment mode
	 getch();
	 return 1;                       //SUCCESSFUL
}
int interact :: display() {                   //All Object's Detail saved in files in one glance.
	 fstream file;
	 patient object;
	 close_window();
	 int loop=0;
	 file.open("Database.txt", ios::in | ios::beg);
	 if ( file == 0) {             //FILE NOT EXIST
	 cleardevice();
	 problem_definition("CAN'T DISPLAY","Display");       //FUNCTION RESPONSIBLE FOR DISPLAYING ERRORS.
	 return -1;
	}
         start:  cleardevice();                 //Goto Label.
	 close_window();
	 line(3,50,700,50);
	 gotoxy(0x3, 0x2);
	 cout<<"S.NO"<<"   "<<"ID"<<"      "<<"NAMES"<<"       "
	 <<"PARENTAGE"<<"         "<<"ADDRESS"<<"            "<<"CONTACT";
	 gotoxy(01, 05);
	 file.read( (char *) &object, sizeof( object ) );
	 while( 1 ) {
	 if(file.eof()!=0 ) {                   //DONT CHANGE LOCATION.
	 while(!kbhit() )
	 if( OBJECT.mouse_wclose()==1 )
	 return 0;                             //Returns in case of click.
	 return 0;                             //Returns in case of  type.
               } object.lview(++loop);
	 if( wherey() >=29 ) {                 //Clears screen if reachs to line 29.
	 cout<<endl<<"Press Any Key To Continue & 'E' To Exit . .";
	 while(!kbhit() )
	 if( OBJECT.mouse_wclose()==1 )
	 return 0;
	 if(getch() == 'E')  return  0;
	 else
	 goto start;
               }
	 file.read( (char *) &object, sizeof( object ) );
             }	 file.close();
	 while(!kbhit() )
	 if( OBJECT.mouse_wclose()==1 )
	 return 0;
}
void patient ::  lview(int no) {                //LINE VIEW Option 6 . .
	 cout<<setiosflags(ios::left)<<setw(3)<<setfill(' ')<<no<<setw(9)<<setiosflags(ios::right)<< id<<"     "<<
	 name<<"     "<<
	 father << "      "<<
	 address << "      " <<
	 "+0"<<phone<<'.'<<endl;
}
int interact :: search( int mode=0 ) {
               /*In mode 0 (default) it will behave like search function that
	 display error or search. However on mode=1 it will only
	 search thats in edit mode & won't display anything.*/
	 fstream file;
	 int no;
	 cleardevice();
	 close_window();
	 file.open("Database.txt", ios::in);
	 file.seekg(0,ios::beg);
	 if( file==0) {                     //File Doesn't Exist
	 if(problem_definition("CAN'T SEARCH","Search")==-1);
	 return -1;
               } setcolor(11);
	/*The Mode decides how function behaves. */
	 if ( mode==0 )   {                //Search Mode
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,10);
	 outtextxy( 80 , 20 ,"SEARCH " );
               } else if( mode == 1 )  {           //Edit Mode.
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
	 outtextxy( 80 , 20 ,"EDIT MENU" );
               } gotoxy( 11, 13 );
	 cout<<"Enter The Patient's ID No : ";
	 settextstyle(0,HORIZ_DIR,1);
	 setcolor(19);
	 outtextxy( 10 , 240 ,"[NOTE  :  FORGOTTEN   USER_ID  ?  Go  To   MAIN   MENU"
	 " Use The \"Display Menu\" " );
	 outtextxy( 100 , 255 ,"Option To Get User's ID.]");
	 gotoxy(40, 13);
	 setcolor(14);
	 rectangle(305,190,400,208);             //For The Input Box
	 cin>>no;
	 while(OBJECT1.giveid()!= no ) {
	 file.read( (char *) &OBJECT1, sizeof(OBJECT1) );
	 if(file.eof()!=0)                 //END OF FILE
	 break;
              }
	 cleardevice();
	 close_window();
	 if( mode==1 ) {                 //Behave like edit function
	 if( OBJECT1.giveid()==no)
	 return no;            //OFFSET LOCATION IN FILE.
	 else return -1;                    //NOT FOUND
	 }
	 if(OBJECT1.giveid()==no) {                 //If Entered Record no matches to the patient.
	 if(OBJECT1.showdetail()==1)               //IF MOUSE CLICK ON CLOSE Button.
	 file.close();
	 return 0;
               } else  {                                  //IF RECORDS NOT FOUND.
	 problem_definition("PATIENT / ","Search");
               } file.close();
	 return 1;
}
int patient :: showdetail() {                //Showing Details Of Patient.
	  setcolor(3);
	  OBJECT.close_window();
	  line(03,100,800,100);
	  line(03,102,800,102);
	  rectangle(50,135,600,360);
	  gotoxy(12,10);
	  line(50,165,600,165);
	  cout<<"ID = ", gotoxy(60,wherey() ), cout<<id<<'.';
	  gotoxy(12, wherey()+2 );
	  cout<<"Name  :",gotoxy(60,wherey() ), cout<<name<<".";
	  line(50,200,600,200);
	  gotoxy(12,wherey() + 2);
	  cout<<"Parentage : ",gotoxy(60,wherey() ),cout<<father<<".";
	  gotoxy(12,wherey()+2 );
	  cout<<"Phone Number : ",gotoxy(60, wherey() ),cout<<phone<<".";
	  gotoxy(12,wherey() +2);
	  cout<<"Address  : ",gotoxy(60, wherey()), cout<<address<<".";
	  line(50,230,600,230);
	  gotoxy(12,wherey()+2 );
	  cout<<"Age = ",gotoxy(60, wherey() ), cout<<age<<".";
	  line(50,260,600,260);
	  gotoxy(12,wherey()+2 );
	  cout<<"Sex : ",gotoxy(60,wherey() ),cout<<sex<<"   ";
	  sex=='M' ? cout<<"(MALE)." : sex == 'F' ? cout<< "(FEMALE)." : cout<<"UNKNOWN.";
	  line(50,294,600,294);
	  line(50,330,600,330);
	  line(450,135,450,355);	      //Horizontal Line.
	  gotoxy(1, wherey()+2);
	  cout<<"The Above Details Are Based On Input Fed."
	  "In Case Of Any Alteration In Details Ofthe Patient"
	  ".\n\n\t Visit : [Homepage]  -> [Edit Menu].";
	  cout<<"\n\t[Press Any Key To Go To Back Screen]";
	  while( !kbhit() ) {
	  settextstyle(3,HORIZ_DIR, 7 );
	  setcolor( rand() % 20 );        //3,10,15
	  outtextxy( 35 , 25 , "DETAILS" );
	  settextstyle(10,HORIZ_DIR, 2 );
	  outtextxy( 270 , 50 , "OF A" );
	  settextstyle(3,HORIZ_DIR, 7 );
	  outtextxy( 355 , 25 , "PATIENT." );
	  if(OBJECT.mouse_wclose()==1)
	  return 1;
	}
}
int patient:: total_patients(int rw=1 ) {             //Function To Show Number Of Total Nos Patients.
	  fstream file,dbExist;
	  int check=0;
	  file.open("DB245.txt", ios::beg | ios::in );
	  dbExist.open("Database.txt", ios::in | ios::beg);     //If the database | counter file is not found it'll print from 0
	  if( file == 0 || dbExist==0) {          //Missing File.
	   file.close(); dbExist.close();
	   }
	  else  {
	   file.seekg(0, ios::beg);
	   file>>check;                //Else getting (int) value from File.
	   file.close();
	  if(rw==0)
	   check++;                   //Increment & replace by new value.
               }  file.open("DB245.txt", ios::out | ios::trunc  );
	  file<<check;                   //Writing 0 to file if not exist.
	  file.close();  dbExist.close();
	  return check;
}
int interact :: problem_definition(char *error_name,char *operation) {
	  close_window();
	  setcolor(WHITE);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	  outtextxy( 140 , 70 , error_name );
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
	  outtextxy(30,130,"FILE NOT EXIST.");
	  gotoxy(10,15);
	  cout<<"[Please Press Any Key To Return Back To The Main Menu.]";
	  setcolor(2);
	  line(3,250,700,250);
	  line(3,252,700,252);
	  gotoxy(1, 17 );
	  cout<<" Description Of Problem : The Program Is Unable to Find The Content in the OS."<<endl;
	  cout<<"\n 1.The Database File(Database.txt) May Have Been Renamed By Some Other Name.";
	  cout<<"\n 2.Yew Are Trying To Perform "<<operation<<", however Database Is Not Yet Created.";
	  cout<<"\n 3.The Database File(Database.txt) may have been deleted.";
	  cout<<"\n 4.The Database File Has Been Moved To Some Other Location.";
	  cout<<"\n 5.The Extension Of File(.txt) Has Been Changed.";
	  cout<<"\n 6.You Are Trying To "<<operation<<" Howsoever The Patient Doesn't Exist.";
	  while(!kbhit() )
	  if(OBJECT.mouse_wclose()==1)
	  return -1;
}
int get_string(char array[], const int size) {           //Tested
	  char token ;
	  flushall();
	  showcursor();
	  for(int loop=0; loop<size ; loop++) {
	  while(!kbhit() )
         label:   if(OBJECT.mouse_wclose()==1)
	  return -1;
	  token = getch();
	  if((token >= 'a' && token<= 'z') ||  (token >= 'A' && token<= 'Z') || (token >= '0' && token<= '9') ||
	  token=='+' || token=='_' || token=='$' )
	  array[loop] = token , cout<<char(token);                     //Directly assigning value of token to string
	  else if((token== ' ' || token== 13)  && loop==0 )
	  goto label;                        //next iteration & assign a valid character to string.
	  else if( token == '\b' && loop>0 ) {
	  loop--;
	  gotoxy (wherex()-1, wherey() );
	  cout <<" ";
	  gotoxy (wherex()-1 , wherey() );
	  goto label;
               }  else if( (token==13 || token==' ') && loop>0)	 break;
	  else  loop--;                           //Suppose The Esc is pressed
	}                                            //Loop Closing.
	  while(loop<size)
	  array[loop++]=' ';
	  array[--loop] = NULL;              //  IN CASE OF END OF ARRAY.
	  cout<<".";                        //   FOR TESTING & USER FRIENDLY.
	  flushall();
	  if(array[size-1]==' ')
	  getch();
	  return 0;
}
void interact :: load() {
	  int loop=0,gd=DETECT,gm;
	  initgraph(&gd, &gm,"C:\\TC\\bgi");
	  cleardevice();
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	  setbkcolor( 21 );
	  setcolor( 4 );
	  for(int e=0; e<15; e++)
	  for(loop=50;loop<100 && !kbhit();loop++) {
	  settextstyle(SMALL_FONT, HORIZ_DIR, 13);
	  outtextxy(120,150,"Loading...");
	  settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	  outtextxy(125,147,"Please Wait . . ");
	  setcolor(rand()%15);
	  circle(350,164,loop);
	  circle(350,163,loop/50);
	  circle(350,165,rand()%25);
	  cleardevice();
	  setcolor( rand()%20 );
	  circle(350+e*30, 180, 10);
	  circle(350+e*27, 180, 9);
	  circle(350+e*24, 180, 8);
	  circle(350+e*21, 180, 7);
	  circle(350+e*18, 180, 6);
	  circle(350+e*15, 180, 5);
	  circle(350+e*12, 180, 4);
	} 		          //Inner Loop }.
	  cleardevice();
	  close_window();
	  mouse.show();
	  setbkcolor(0x9);
	  setcolor(0xAAA);
	  settextstyle( 10 , HORIZ_DIR, 7);     //Use 5 for signature,10
	  outtextxy(50 , 10 ,"WELCOME");
	  setcolor( 7 );
	  settextstyle( 10, HORIZ_DIR, 5);
	  setcolor( 0xAFFFF );
	  outtextxy(150,120,"TO");
	  outtextxy(280,120,"THE");
	  settextstyle( 3 , HORIZ_DIR , 10);
	  setcolor(0XAEAAA);
	  outtextxy(70,140,"H");
	  outtextxy(140,155,"o");
	  outtextxy( 200 , 170 ,"spit");
	  outtextxy( 400 , 155 ,"a");
	  outtextxy( 465 , 148 ,"L.");
	  settextstyle( 2 , HORIZ_DIR , 5);
	  outtextxy( 450 , 450 ,"Signature Of Developer.");
	  settextstyle( 5 , HORIZ_DIR, 3);       //5 for signature
	  outtextxy( 445 , 425 ,"zahid fayaz khan.");
	  setcolor(WHITE);
	  settextstyle(2 , HORIZ_DIR, 5);
	  outtextxy( 6 , 425 ,"SRINAGAR MEDICAL COLLEGE.");
	  outtextxy( 6 , 440,"JAMMU & KASHMIR.");
	  outtextxy( 6 , 455,"190002.");
	  setcolor(YELLOW);
	  rectangle(2,425, 200,475);
	  getch();
	  getch();
	  closegraph();
}
void interact :: close_window() {
	  setfillstyle(10, 10);
	  fillellipse(630, 12,20, 20);
	  arc(630, 12, 130, 310, 20);       //FOR CURVE
	  setcolor(2);
	  settextstyle(0, HORIZ_DIR, 2);
	  outtextxy(623, 9, "X");           //CLOSE BUTTON
}
int interact :: mouse_wclose() {
	mouse.button_location(mouse.button,mouse.x,mouse.y);
	if( mouse.x>=610 && mouse.y<=23 && mouse.button==1 ) {          //Mouse Is Used.
	mouse.button=1;
	mouse.gotoxy(580,26);             //DEFAULT LOCATION (DEBUG).
	return 1;
              } mouse.button=-1;
	return 0;
}
int interact :: keyboard() {
	int value = 0;
	static int x1, y1;
	x1=wherex(), y1=wherey()+1;         //STORING ORIGINAL CO-Ords
	while(!kbhit() ) {
	value = peek(0x40, 0x17);
	if (value & 64) {
	gotoxy(15,y1);
	cout<<"[Caps lock on]";
	}
	else {
	gotoxy(x1,y1);
	cout<<"              ";
	}
              } gotoxy(x1,y1-1);               //Ensuring Orginal X & Y Co-Ordinates Points.
	return 0;
}
int interact :: editpage() {
	//Search(editmode=1) will return -1 in case patient doesn't exist.
	//Else returns the Patient ID .
	int value=search(1);
	if( value==-1 ) {    //PATIENT NOT FOUND.
	 problem_definition("PATIENT / ","Edit");
	 return 0;
              } cleardevice();
	setcolor(WHITE);
	settextstyle(9 , HORIZ_DIR, 5	);
	outtextxy( 20 , 10 ,"SKIMS");
	rectangle(19,100,590,440);
	line(20,130,590,130);     //Id Line.
	line(140,130,140,440);    //Horizontal Line 1.
	line(300,130,300,440);    //Horizontal Line 2.
	line(20, 170,590,170);  //Particulars line.
	gotoxy(5,10),  cout<<"PARTICULARS";
	gotoxy(20,10), cout<<"EXIST DETAILS";
	gotoxy(40,10), cout<<"REPLACED BY";
	gotoxy(5,12),  cout<<"NAME : ";
	gotoxy(5, wherey()+2), cout<<"PARENTAGE : ";
	gotoxy(5, wherey()+2), cout<<"ADDRESS : ";
	gotoxy(5, wherey()+2), cout<<"CONTACT NO : ";
	gotoxy(5, wherey()+2), cout<<"AGE : ";
	gotoxy(5, wherey()+2), cout<<"Sex : ";
	close_window() ;
	if(OBJECT1.editdetails() == 0)             //If Close Is Mously Clicked.
	return 0;
	patient temp;
	fstream oldfile, newfile ;
	oldfile.open("Database.txt", ios::in | ios::beg) ;
	newfile.open("Temp.txt", ios::out  | ios::beg | ios::trunc) ;
	while(oldfile.eof()==0){
	oldfile.read( (char *) &temp, sizeof( temp )) ;
	if(temp.giveid()!=value)
	newfile.write( (char *) &temp, sizeof( temp )) ;
	else
	newfile.write( (char *) &OBJECT1, sizeof(OBJECT1) );
	}
	newfile.close();
	oldfile.close();
	db_delete();
	if( rename("Temp.txt","Database.txt") != 0)
	cout<<"ERROR";
	getch();
}
int patient :: editdetails() {         //Linked with editpage
	gotoxy(20,8);
	cout<<"ID OF THE DESIRED PATIENT : "<<id;
	gotoxy(20,wherey()+4), cout<<name;
	gotoxy(20,wherey()+2), cout<<father;
	gotoxy(20,wherey()+2), cout<<address;
	gotoxy(20,wherey()+2), cout<<phone;
	gotoxy(20, wherey()+2),cout<<age;
	gotoxy(20, wherey()+2),cout<<sex<<' ';
	sex=='M'?cout<<"(MALE)":sex=='F'?cout<<"(FEMALE)":cout<<"(UNKNOWN)";
	gotoxy(40,12);
	if( get_string(name,10) == -1)        //FOR NAME.
	return 0;
	gotoxy(40,wherey()+2 );          //For Parent.
	if( get_string(father,10) == -1)
	return 0;
	gotoxy(40,wherey()+2);            //AGE
	if(get_string(address, 15)==-1)
	return 0;          //Address
	gotoxy(40,wherey()+2 );
	if(get_string(phone, 11)==-1)
	return 0;            //Phone
	gotoxy(40,wherey()+ 2 );
	if( get_string(age, 3) == -1)
	return 0;
	gotoxy(40, wherey()+ 2 );
	flushall();
	showcursor();
	sex=getch();
	cout<<sex<<"   ";
	sex=='M' ? cout<<"(MALE)." : sex == 'F'? cout<< "(FEMALE)." : cout<<"UNKNOWN.";
	strupr(name), strupr(address), strupr(father);
	return 1;                       //SUCCESSFUL
}
void interact :: marquee()
{
	auto const char *array[]= {
               "Hospital", "Helpline Number : " , "09596000908.", "In Case" ,
               "Of any technical" , "Assitance,", "Please Contact@www.hacking.com" };
	static int a=100,b=170,c=320,d=430,e=500,f=640,g=720;
	const auto int y=352;                     //Y Co-Ordinate
	randomize();
	setcolor(YELLOW);
	settextstyle(2 , HORIZ_DIR, 5);
	const int x1=wherex(),y1=wherey();
	int temp=0;
	while(temp++==0 ) {
	gotoxy(1,23);
	cout<<"                                                                         "
	"                                                   ";
	 outtextxy(a-=5,y, array[0]);
	 outtextxy(b-=5,y, array[1] );
	 outtextxy(c-=5,y, array[2] );
	 outtextxy(d-=5,y, array[3] );
	 outtextxy(e-=5,y, array[4] );
	 outtextxy(f-=5,y, array[5] );
	 outtextxy(g-=5,y, array[6] );
	 if(a<=0)       a=940;
	 else if (b<=0) b=940;
	 else if (c<=0) c=940;
	 else if (d<=0) d=940;
	 else if (e<=0) e=940;
	 else if (f<=0) f=940;
	 else if (g<=0) g=940;
	 delay(80);
              }  gotoxy(x1,y1);        //GOTO WHERE IT WAS.
}
void interact :: setting()
{
	cleardevice();
	outtextxy( 50 , 100 , "Change Username/Password." );
	outtextxy( 50 , 120  , "Delete Database." );
	close_window();
	getch();
}