#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>
#include <dos.h>
#include <process.h>
////////////////////////////// '
int pf = 0;
class player
{int num;

public:
char name[50];
int c,b,sl,m,so;
int avg;

public:
player()
{c = -1;
b = -1;
sl = -1;
m = -1;
so= -1;
avg = 0;
num = 0;
}
void addname(char nam[50])
{strcpy(name,nam);
}
void score(int n, int p, int f = 0)
{
if(n == 1)
c = p;
else if (n == 2)
b = p;
else if (n == 3)
sl = p;
else if (n == 4)
m = p;
else if (n == 5)
so = p;
num++;
avg = (avg*(num - 1) + p)/num;
if(f){
ofstream fo;
fo.open("score.dat",ios::binary|ios::app);
fo.write((char *)this, sizeof(player));
fo.close();}
}
};
player p;
void leaderboard(int n)
{
 int s = 0;
ifstream fin;
fin.open("score.dat",ios::binary|ios::in|ios::nocreate);
fin.seekg(0,ios::beg);
player a[20];
while(!fin.eof())
{fin.read((char *)(a + s), sizeof(player));
s++;}
if(n == 1)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].c > a[j+ 1].c)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].c != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].c<<'\n';}
}
}

if(n == 2)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].b > a[j+ 1].b)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].b != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].b<<'\n';}}
}

if(n == 3)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].sl > a[j+ 1].sl)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].sl != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].sl<<'\n';}
}                      }

if(n == 4)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].m > a[j+ 1].m)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].m != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].m<<'\n';}
}
}

if(n == 5)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].so > a[j+ 1].so)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].so != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].so<<'\n';}}
}

if(n == 6)
{
for(int i = 0; i<s - 1; i++)
{for (int j = 0; j< s - i - 1; j++)
{if(a[j].avg > a[j+ 1].avg)
{player sw =a[j];
a[j] = a[j + 1];
a[j + 1] = sw;
}
}
}
cout<<setw(30)<<"Name";
cout<<setw(30)<<"Score"<<endl;
for(i = s-1; i>0;i--)
{if(a[i].avg != -1){cout<<setw(30)<<a[i].name;
cout<<setw(30)<<a[i].avg<<'\n';}
}
}
}
/////////////////////////////////////
int ti=75;
int ded = 0;
int li = 3;  //lives
int le = 3; //level
//char cha;
int x=19,y=1;//x,y coords
char a[50][100]; //le maze
int dead[10];//y-of dead enemies
//int genx[1000],geny[1000];
int xb[10],yb[10];//guy
int exb[100],eyb[100][100];
int xp,yp;
int esh = 0;
int lol = 0;
int sh = 0; //shoot check variable

void eshoot()
{
if(!(lol%(16-4*le)))
  {esh++;
   lol-=16-4*le;}

 for(int la=0;la<10;la++)
 for(int i = 2; i<20; i+=6-le)
 for(int r = 1; r<=esh; r++)
 {
 if(i!=dead[la])
 {exb[(i-2)/(6-le)]=i;
 eyb[(i-2)/(6-le)][r-1]=75- (16-4*le)*(r)-((lol));
  } }
  lol++;
}

void printerr(int sh=0)
{int f=0,secks=0;
 while(dead[f]>-1)
 {
  f++;
 }
//deaths
 for(int i=2;i<20;i+=6-le)
 { for (int h = 0; h<sh + 1; h++)
   {
   if (xb[h] == i && yb[h] >=76)
   {a[i][76] = ' ';
	dead[h]=i;
	ded++;
   }
   }
 }
 while(dead[secks]>-1)
 {
  secks++;
 }
 if(secks-f==1)
 {
	for(int i = 0; i<3; i++)
	sound(300 + 50*i);
	delay(ti*3);
	nosound();
 }
 //guns
}

int checkpos(void)
{
 if(x==xp&&y==74)
 return 0;

 else
 return 1;
}

void topscene()
{
cout<<"LIVES : ";
for (int i = 0; i<li; i++)
cout<<char(3);
cout<<"\nBullets left :"<<5-sh;
cout<<endl<<endl<<endl;
}

void printmaze()
{ xp =19;
  yp=0;
  for(int i=0;i<20;i++)
  {
   for(int k=0;k<75;k++)
   {
  a[i][k]=char(-37);
   }
   cout<<'\n';
  } randomize();
  a[xp][yp + 1] = ' ';
  int t=0;
  for(int k=0;k<4;k++)
 {    xp =19-5*k;
  yp = 0;
  for(int j=0;j<1000;j++)
  {
  a[xp][yp]=' ';
   t = random(4);
  //genx[j]=xp;
  //geny[j]=yp;
  if (t == 0&&xp<18)
  xp++;
  if(t==1&&xp>2)
  xp--;
  if(t==2&&yp<73)
  yp++;
  /*if(t==3&&yp>1)
  yp--;*/

  }}
  a[xp][74] = char(-80);

 }


int printguy(int sh=0,char kk='l')
{

  {
   for(int i=0;i<20;i++)
   {cout<<"  ";
   for(int k=0;k<77;k++)
   {
   /* for(int t =0;t<sh;t++)
  {
   if(i==xb[t] && k == yb[t] &&sh)
   {cout<<char(-9);
   yb[t]+=5;
   }
  }*/
   int t=0;
   int f=0;
  //--enemies
  for(int jk =0;jk<3+le;jk++)
  for(int g=0;g<esh;g++)
  {if(i==exb[jk]&&k==eyb[0][g])//&&k!=dead[g])

  if(!(i==dead[0]||i==dead[1]||i==dead[2]||i==dead[3]||i==dead[4]||i==dead[5]))
  {
  cout<<char(-82); //enemy bullet
  t=1;
  {if((i==x&&k==y&&--li)||(i==x&&k==y-1&&kk=='d'&&--li))
	{
   clrscr();
   cout<<"\n\n\n\n\n\n\n\n\n\n"<<setw(44)<<"GAME OVER.";
   cout<<'\n'<<setw(44)<<"Lives left: "<<li;
   for(i = 0; i<5; i++){
   sound(440 - 50*i);
  delay(40);
  nosound();}
   delay(2000);
   x=19,y=1;
   clrscr();
   topscene();
   printguy();
   return 1;
	}
	else if((i==x&&k==y&&!li)||(i==x&&k==y-1&&kk=='d'&&!li))
	{
	 clrscr();
	 cout<<"\n\n\n\n\n\n\n\n\n\n"<<setw(44)<<"GAME OVER.";
	 cout<<'\n'<<setw(44)<<"Lives left: 0";
	 cout<<'\n'<<setw(50)<<"Better luck next time.";
	  for(i = 0; i<5; i++){
	  sound(440 - 50*i);
  delay(ti*2);
  nosound();}
	 delay(3000);
	 return(9);
	} }

   }
  }
  if(f==1)
  break;
  if(t==0)
  {
  if(i==xb[0] && k==yb[0])
  cout<<char(-9);
  else if(i==xb[1] && k==yb[1])
  cout<<char(-9);
  else if(i==xb[2] && k==yb[2])
  cout<<char(-9);
  else if(i==xb[3] && k==yb[3])
  cout<<char(-9);
  else if(i==xb[4] && k==yb[4])
  cout<<char(-9);
  else if(i==xb[5] && k==yb[5])
  cout<<char(-9);
  else if(i==xb[6] && k==yb[6])
  cout<<char(-9);
  else if(i==xb[7] && k==yb[7])
  cout<<char(-9);
  else if(i==xb[8] && k==yb[8])
  cout<<char(-9);
  else if(i==xb[9] && k==yb[9])
  cout<<char(-9);
  else if(i==x&&k==y)
   cout<<char(2);

   else if(t==0)
   cout<<a[i][k];
   }
   }

   cout<<'\n';
   }
   for( int g = 0; g<sh; g++)
   {
   yb[g]+=5;

  }
  }
  return 0;
}
////////////////////////////////////
int mazeutil();
void scramble(char b[30], int j);
void encode(char st[100], int x);
void intro()
{
	clrscr();
	int a[100][100], t = 1, y;
	char x[] = "  WELCOME TO BANDERSNATCH  ",ran;
	randomize();
	do{
		t++;
		y = 0;
		for(int i = 0; i<24;i++)
			{for(int j = 0; j<70;j++)
				{  /*	ran = random(3);
					if(ran == 0) */
						ran = random(10) + 48;
					/*else if (ran == 1)
						ran = random(26) + 97;
					else
						ran = random(26) + 65;*/
					//randomize();
					//if((ran >=65 && ran <=92) || (ran >=97 && ran <=122) || (ran >=48 && ran <=57))

					if(i == 10)
					{
						if(t>(6 + y) && j == (21 + y) && y<strlen(x))
							cout<<x[y++];
						else if (t>(6 + y) && j == (22 + y) && y<strlen(x))
							cout<<" ";
						else
							cout<<ran;
					}
					else
						cout<<ran;

				}

			cout<<"\n";
			}
		if(t%2)
		sound(250+4*t);
		else
		sound(250-4*t);
		delay(70);
		nosound();
		clrscr();
		}while(t<=55);
}

void fA();
void fB();
void fC();
void fD();
void fE();
void xc();
int maze();
int crypto();
int slots();
void play(int x);
int sonic();
int blackjack();

void EB1();
void EB2();
void EB3();
void EG1();
//void EG2();
int checkname(char* nameaf)
{
 ifstream fin;
 fin.open("score.dat",ios::binary);
 player f;
 while(fin)
 {
  fin.read((char*)&f,sizeof(f));
  if(!strcmpi(f.name,nameaf))
  {
   fin.close();
   return 1;
  }
 }
 fin.close();
 return 0;
}
void main()
{
	intro();
	clrscr();
	cout<<"Choose a mode -\n(1)Player\n(2)Admin\n(3)Leaderboard\n--> ";
	int c =0,t=0;
	cin>>c;
do
{
	if(c==1)
  {
	t =0;
	clrscr();
	cout<<"Enter your name: ";
	char nameaf[50];
	gets(nameaf);
	while(checkname(nameaf))
	{
	 cout<<"\nThis name has already been chosen. Please enter another name : ";
	 gets(nameaf);
	}
	p.addname(nameaf);
	clrscr();
	/////////////
	cout<<"Hello. You have signed up for a mission for which the memory of your past life will temporarily be erased. Follow me, and I'll tell you what else you need to know.";
	cout << "\nDo you wish to follow?\nYes or No?\n-->";
	char st[10];
	gets(st);
	if(!strcmpi(st,"yes"))
	{
	//cout<<"\nFollowing...";
	xc();
	cout<<"\nNow, we're going to be running a few standard tests before we proceed with the mission. For you, we have a cryptography challenge. Do you accept?";

	cout<<"\nYes or No?\n-->";
	gets(st);
	if(!(strcmpi(st,"yes")))
	{
		fE();
	}
	else
	{
		fA();
	}
	}
	else
	{
	fA();
	}
	getch();
  }
  else if(c == 2)
  {
	t=0;
	clrscr();
	cout<<"Admin mode";
	cout<<"\nChoose function to test";
	cout<<"\n(1)cryptography\n(2)slots\n(3)blackjack\n(4)maze\n(5)sonic\n(6)Delete existing records\n(0)EXIT (none of these)\n--> ";
	int k,ret;
	cin>>k;
	switch(k)
	{
	 case 1:
	 {
	  ret = crypto();
	  break;
	 }
	 case 2:
	 {
	  ret = slots();
	  break;
	 }
	 case 3:
	 {
	  ret = blackjack();
	  break;
	 }
	 case 4:
	 {
	  ret = maze();
	  break;
	 }
	 case 5:
	 {
	  ret = sonic();
	  break;
	 }
	 case 6:
	 {
	  remove("score.dat");
	  break;
	 }
	 case 0:
	 {
	  cout<<"EXITING in ";
	  for(int g =3;g>0;g--)
	  {
	   cout<<g<<" ";
	   delay(500);
	  }
	  delay(100);
	  exit(0);
	 }
	 default:
	 {
	  cout<<"\nInvalid choice";
	  delay(500);
	  exit(0);
	 }
	}
	getch();
  }
  else if(c== 3)
  {
	t =-1;
	clrscr();
	cout<<"LEADERBOARD\n";
	//cout<<"\nChoose function to test";
	cout<<"\n(1)cryptography\n(2)blackjack\n(3)slots\n(4)maze\n(5)sonic\n(6)Overall\n--> ";
	int n;
	cin>>n;
	leaderboard(n);
	cout<<"\nDo you wish to exit (yes / no) : ";
	char s[4];
	cin>>s;
	if(!strcmpi(s,"yes"))
	{
	 t=0;
	}
	else
	{
	 t =-1;
	 clrscr();
	 cout<<"Choose a mode -\n(1)Player\n(2)Admin\n(3)Leaderboard\n--> ";
	 cin>>c;
	}

  }
  else
  {     t =-1;
	cout<<"Invalid choice, input again (1,2 or 3)\n--> ";
	cin>>c;
  }
}while(t==-1);


}
void fA()
{
	cout<<"\nYOU: Wait, this door said exit. Where am I?";
	//cout<<"\nMAZE";
	int f = maze();
	p.score(4,pf);
	clrscr();
	if(f)
	{
	cout<<"YOU: Wait, I cleared the maze, why am I at the same place?";
	getch();
	cout<<"\nWell done! You've cleared our maze. I might have somewhat misled you when I said that door was an exit. You must stay here till you finish your mission. But it's great to see you could beat our maze.";
	//xc();
	cout<<"\nLet's move on to the next mission.";
	fD();
	}
	else
	{
	cout<<"Well, I might not have emphasised the lack of choice you have in this whole thing. You've signed up for this mission, and you will go for it. However, it's clear that you won't be useful for any task involving naviagtion. Let's move on to a different type of test.";
	fE();
	}


}
void fB()
{
	//cout<<"\n...Entering B";
	{
	//cout<<"\nLost crypto";
	cout<<"\nWe have barely any spots remaining for this mission, so you'll just have to get lucky to be part of it.";
	int f;
	f = slots();
	clrscr();
	if(f)
	{   clrscr();
		cout<<"\nWell, congrats! Looks like this your lucky day! We've chosen you for this mission.";
		p.score(3,pf);
		getch();
		fC();
	}
	else
	{
		//cout<<"\nUnfortunately, we won't be considering you for this mission. Let's move on to another test and find another mission for you.";
		p.score(3,pf,1);
		EB2();
	}
	}
}
void fC()
{
	//cout<<"\n...Entering C";

	cout<<"\nThese are the details of your mission: \nWe've recently discovered that the Wamapoke casino, the biggest casino in the world, has been cheating their customers of thousands of dollars. You will be provided with a remote hacking device, all you need to do is sit at the blackajck table for at least 10 rounds, and we'll infiltrate their system. And oh - don't lose all your money or they'll throw you out.";
	int f = blackjack();
	p.score(2,pf,1);
	clrscr();
	if(f)
	{
	EG1();
	}
	else
	{
	EB1();
	}
}
void fD()
{
	int f = sonic();
	clrscr();
	if(f)
	{
		cout<<"\nGreat job! I think you're ready now.";
		p.score(5,pf);
		getch();
		fB();
	}
	else
	{
		p.score(5,pf,1);
		EB2();
	}
}
void fE()
{
	//cout<<"\n...Entering E";
	int f = crypto();
	p.score(1,pf);
	clrscr();
	if(f)
	{
	cout<<"\nGreat! You've passed your first test! Now, we have just one more test before we tell you your mission. ";
	f = sonic();
	p.score(5,pf);
	clrscr();
	if(f)
	{
		cout<<"Fantastic! You've done really well. Your mission has been chosen.";
		getch();
		fC();
	}
	else
	{
		cout<<"Hmm, that's not too great. Nevertheless, we've found a mission suitable for you.";
		getch();
		fB();
	}
	}
	else
	{getch();
	fB();}
}
int maze()
{
	//cout<<"...Maze";
 getch();
 pf = mazeutil();
 clrscr();

	if(pf)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int crypto()
{getch();
 int per =0;
	{
clrscr();
randomize();
char a [5][100] = {"top of the morning to ya gov'ner","thats a strange place to put a piano","and then the bartender says","it was a dark and stormy night","is it a bird? is it a plane? yeah, its a plane"};
int x = random(7) + 1;
int y = random(5);
cout<<"Question 1:";
cout<<"\nIf 'rajesh' is encoded as ";
encode("rajesh",x);
cout<<"\nDecode: ";
encode(a[y],x);
cout<<"\nHint: ";
for(int i = 1; i<=26;i++)cout<<char(64 + i)<<":"<<i<<'\t';
cout<<"\nEnter the decrpyted message: \n";
char in[100];
gets(in);
if(strcmpi(in,a[y]))
cout<<"Sorry. The correct message is '"<<a[y]<<"'.";
else
{cout<<"Correct!";per+=50;}
getch();
clrscr();
cout<<"\nQuestion 2: ";
cout<<"\nUnscramble the words and enter the correct sentence: \n";
int z,j = 0;
char b[30];
do{z = random(5);}while(z==y);
for(i =0; a[z][i]!= '\0'; i++)
{if(a[z][i] == ' ')
{scramble(b,j);
j = 0;}
else if(a[z][i + 1]=='\0')
{b[j++] = a[z][i];
scramble(b,j);}
else
b[j++] = a[z][i];
}
cout<<"\n\nEnter the correct sentence: \n";
gets(in);
if(strcmpi(in,a[z]))
cout<<"Sorry. The correct message is '"<<a[z]<<"'.";
else
{cout<<"Correct!";per+=50;}
getch();
}
//store percentage per
int win=0;
pf = per;
if(per == 100)
win = 1;
	if(win)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int slots()
{ getch();
  clrscr();
  cout<<setw(40)<<"SLOTS";
  int score = 0,n =0,win =0;
  cout<<"\nHow many rounds do you wish to play (from 1 to 9): ";
  cin>>n;
  while(n<=0||n>=10)
  {
   cout<<"\nInvalid input, enter another number : ";
   cin>>n;
  }
  cout<<"Let's go! You need atleast "<<20*n<<" to win!";
  cout<<"\nPress any key to continue: ";
  getch();
  int temp =n,s1=0,s2=0,s3=0;
  randomize();
  char sy[7] = {char(14),char(2),char(3),char(-19),char(-24),char(127),char(15)};
  do{
  s1=random(7),s2 = random(7),s3 = random(7);
  clrscr();
   cout<<setw(40)<<"SLOTS";
   gotoxy(15,3);
   for(int i =0;i<7;i++)
   {
	cout<<sy[i]<<" \t";
   }
   gotoxy(33,10);
   for(int j =0;j<13;j++)
   {
	cout<<(char(-37));
   }
   gotoxy(33,11);
   cout<<char(-41)<<" "<<sy[s1]<<" "<<char(-41)<<" "<<sy[s2]<<" "<<char(-41)<<" "<<sy[s3]<<" "<<char(-41);
   gotoxy(33,12);
   for(int k= 0;k<13;k++)
   {
	cout<<(char(-37));
   }
   if(s1 == s2)
   {
	if(s2 == s3)
	{
	 cout<<"\n\n"<<setw(50)<<"Yay! You scored 100 points";
	 score+=100;
	}
	else
	{
	 cout<<"\n\n"<<setw(50)<<"You scored 50 points!";
	 score+=50;
	}
   }
   else
   {
	if(s2 == s3 || s1 == s3)
	{
	 cout<<"\n\n"<<setw(50)<<"You scored 50 points!";
	 score+=50;
	}
	else
	{
	 cout<<"\n\n"<<setw(50)<<"You didn't score :(";
	}
   }

   cout<<"\n\n\n\n\n\n\n"<<setw(40)<<"SCORE : "<<score;
   getch();
   temp--;
  }while(temp>0);
  clrscr();
  cout<<"Your final score is "<<score<<"/"<<100*n;
  float per = score/n;
  //store percentage per
  pf = per;
  if(per>=20)
  {
   win = 1;
  }
  else
  {
   cout<<"\nTough Luck :(";
   win = 0;
  }
  getch();
	if(win)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void play(int x)
{
   if (x ==1)
   {
	sound(200);
	delay(300);
	nosound();
	delay(200);
   }
   else if(x == 2)
   {
	sound(200);
	delay(700);
	nosound();
	delay(200);
   }
   else if (x ==3)
   {
	sound(500);
	delay(300);
	nosound();
	delay(200);
   }
   else if(x == 4)
   {
	sound(500);
	delay(700);
	nosound();
	delay(200);
   }
   else if(x == 5)
   {
	for(int k =0;k<10;k++)
	{
	 sound(500 - 50 * k);
	 delay(60);
	 nosound();
	}
	delay(200);
   }
   else if(x == 6)
   {
	for(int k =0;k<10;k++)
	{
	 sound(50 + 50 * k);
	 delay(70);
	 nosound();
	}
	delay(200);
	}

}

int sonic()
{
  getch();
  int win = 1;
  int per =0,nx = 0;//% , iter no.
  clrscr();
 char des[7][30] = {"silence","short low pitched sound","long low pitched sound","short high pitched sound","long high pitched sound","down laser!","up laser!"};
 cout<<setw(35)<<"SONIC";
 cout<<"\nInstructions :\nYour task is to identify the series of given sounds based on their numerical constants. A sample of each sound and its assigned constant will be played for you now.";
 cout<<"\nPress any key to continue: ";
 getch();
 clrscr();
 for(int i = 1; i<7;i++)
 {
  cout<<i<<":- "<<des[i]<<'\n';
  play(i);
  cout<<"Press any key to continue: \n\n";
  getch();
 }
 clrscr();
 int l = 1;
 int a[7],inp[7];
 randomize();
 while(l<4)
 {
  int size = l + 2,f = 0;
  clrscr();
  cout<<setw(30)<<"\nLevel "<<l<<": ";
  cout<<"\nPress any key to play the sounds ";
  getch();
  clrscr();
  cout<<setw(30)<<"\nLevel "<<l<<"\n";
  for(i = 1; i<7;i++)
 {
  cout<<i<<":- "<<des[i]<<'\n';
 }
  for(int i=0;i<size;i++)
  {
   do
   {
	a[i] = random(6) + 1;
	if((a[i] == a[i - 1] && a[i] == 0)  || a[0] == 0)
	f = 1;
	else
	f =0;
   }while(f);
   int x = a[i];
   play(x);
  }
  int p=0;
  cout<<"Enter the numerical constants sequentially (separated by spaces) : ";
  for(int j =0;j<size;j++)
  {
   cin>>inp[j];
   if(a[j] == inp[j])
   {
	p++;
   }
  }
  if(p == size)
  {
   cout<<"\nYou win!";
   per+=100*size;
   if(l!=3)cout<<"Press any key to continue to level "<<++l;
   else
   {
	cout<<"Well played!";
	l++;
   }
   getch();
  }
  else
  {
   cout<<"\nYou got "<<p<<" out of "<<size<<" sounds correct.\nThe correct sequence was: ";
   per = (100 * p);
   for(int g =0;g<size;g++)
   {
	cout<<a[g]<<" ";
   }
   getch();
   l=4;
   win = 0;
  }

 }
 per /= 12;
 pf = per;
 //
// cout<<"%%%"<<per;
 //store percentage per
	if(win)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void cdet(int ca, char cs, int &cb, int &cc){
		if(ca <=10)
			{cout<<"The "<<ca<<" of ";
			cb+= ca;}
		else if (ca == 11)
			{cout<<"The jack of ";
			cb+= 10;}
		else if (ca == 12)
			{cout<<"The queen of ";
			cb+= 10;}
		else if (ca == 13)
			{cout<<"The king of ";
			cb+= 10;}
		else if (ca == 14)
			{cout<<"The ace of ";
			cb+= 11;
			cc++;}
		if (cs == 4)
			cout<<"clubs.\n";
			else if (cs == 5)
			cout<<"hearts.\n";
		else if (cs == 6)
			cout<<"diamonds.\n";
		else
			cout<<"spades.\n";
}

int blackjack()
{getch();
struct card{
	char suit;
	int num;
};

	clrscr();
	cout<<"\nWelcome to blackjack.\nHere are the rules:\nYou play 10 rounds starting with a 100 dollars\nYou must have atleast 70 dollars at the end of the game\nMinimum bet = 5 dollars\nMaixmum bet = 30 dollars\nYou lose 10 dollars if you go bust";
	cout<<"\nPress any key to begin: ";
	int m = 100,bet,f;
	getch();
	randomize();
	clrscr();
	char ch2 = 0;
	int pw = 0, dw = 0;
	while(ch2++<10){
	clrscr();
	card c[10];
	int ch;
	int a = 0,f = 1, x = 0,b,dx = 0;
	do{
		cout<<"Total: "<<x;
		cout<<"\n1.Hit";
		cout<<"\n2.Stop\n";
		cin>>ch;

		if(ch==1)
		{
			do{
				c[a].num = random(13) + 2;
				c[a].suit = random(4) + 3;
				if(a == 0)f = 0;
				for(int i = 0; i<a; i++)
				{
					if(c[i].suit == c[a].suit && c[i].num == c[a].num)
					{
						f = 1;
						break;
					}
					f = 0;
				}
			}while(f);

			clrscr();
			x = 0;
			b = 0;
			if(c[a].num <=10)
				cout<<"You drew the "<<c[a].num<<" of ";
			else if (c[a].num == 11)
				cout<<"You drew the jack of ";
			else if (c[a].num == 12)
				cout<<"You drew the queen of ";
			else if (c[a].num == 13)
				cout<<"You drew the king of ";
			else if (c[a].num == 14)
				cout<<"You drew the ace of ";
			if(c[a].suit == 3)
				cout<<"spades.";
			else if (c[a].suit == 4)
				cout<<"clubs.";
			else if (c[a].suit == 5)
				cout<<"hearts.";
			else if (c[a].suit == 6)
				cout<<"diamonds.";
			cout<<" You currently have: \n";
			a++;
			for(int i = 0; i<a;i++)
			{
				cdet(c[i].num,c[i].suit,x,b);
			}
			while(x>21 && b)
			{
				x -=10;
				b--;
			}
			if(x>21)
				{cout<<"You've gone bust. Dealer wins.\n";
				dw++;
				m -=10;
				getch();
				break;}
			if(x==21)
				{cout<<"Blackjack!\n";
				ch = 2;}
		}

		if(ch==2){
			do{cout<<"\nHow much will you bet?";
			cin>>bet;
			if(bet>30 || bet<5)
			{cout<<"\nInvalid bet. Enter a different amount.";
			f = 1;}
			else
			f = 0;
			}while(f);
			b = 0;
			cout<<"Dealer drew: \n";
			while(dx<x || (dx==x && x<14)){
				do{
					c[a].num = random(13) + 2;
					c[a].suit = random(4) + 3;
					if(a == 0)f = 0;
					for(int i = 0; i<a; i++)
					{
						if(c[i].suit == c[a].suit && c[i].num == c[a].num)
						{
							f = 1;
							break;
						}
						f = 0;
					}
				}while(f);
				cdet(c[a].num,c[a].suit,dx,b);
				a++;
				while(dx>21 && b)
					dx-=10;
			}

			if (dx == x)
			{
				cout<<"Dealer Total:"<<dx;
				cout<<"\nDraw.";
			}
			else if(dx <=21)
				{
					cout<<"Dealer Total:"<<dx;
					cout<<"\nDealer wins.";
					m-=bet;
					dw++;
				}
			else
				{
					cout<<"Dealer went bust.";
					cout<<"\nPlayer wins.";
					m +=bet;
					pw++;
				}

		}
	}while(ch==1);
	cout<<"\nDealer Wins: "<<dw;
	cout<<"\nPlayer Wins: "<<pw;
	cout<<"\nMoney: "<<m;
	getch();
	};
	int per = 0;
	if(m>200)
	{
	 per = 100;
	}
	else
	{
	 per = m/2;
	}
	pf = per;
	if(m>70)
	return 1;
	else
	return 0;

}

void EB1()
{
	cout<<"\nThe dealer looks at you suspiciously.\n'Hey, how'd you get in here? This is a table for veterans and you're clearly a beginner.'\nYou start to sweat. 'Ummm, sorry guys, but I have to go now.'\n'no, no, wait a minute here. Hey, what's that on your wrist?'\nYou turn around to run but see two huge bodyguards standing in front of you. The dealer approaches you menacingly.\n'Oh, you're gonna reget trying to cheat us'.\nAs they close in on you, you start to feel that ytou might never see the light of day again.\n";
	cout<<setw(43);
	cout<<"THE END";
}
void EB2()
{
	cout<<"\nUnfortunately, we won't be considering you for this mission. And since you weren't really of any use to us, we won't be giving you the money we promised. Also, we'll hold on to your memories. Have a good life!\n\nTwo bodyguards throw you out as you limp, dazed and confused, into a cold and unforgiving world.\n";
	cout<<setw(43);
	cout<<"THE END";
}
void EB3()
{   cout<<"Well, I'm sorry to say that I don't think we could really use you for any mission right now. The good news for you is that you're free to go. However, I regret to inform you that you won't be getting the money we promised and we won't be returning your memories. Have a good life!";
	//cout<<"\nEB3";
	cout<<setw(43);
	cout<<"THE END";
}

void EG1()
{
	cout<<"\nWell, its been a fine game, gentlemen, but I really need to get going.\nAs you walk out of the casino, you can't resist the urge to smile a little. Finally, you've done something you can be proud of. You get in the car waiting for you, and try to enjoy the hour-long ride back to the base. As you put your head out of the window to feel the pleasant breeze, you also try to enjoy a feeling you haven't felt in a long time.\nFreedom.\n";
	cout<<setw(43);
	cout<<"THE END";
}
void EG2()
{
	cout<<"\nEG2";
}
void xc()
{
	cout<<"\nAs you follow the man, you begin to question what he's just told you. Why would anyone sign up for something like this? You suddenly feel this impulsive need to know who you were before you arrived here. Do you wish to ask him?\nYes or No? ";
	char c[5];

	cin>>c;
	if(!strcmpi(c,"yes"))
	{
		cout<<"\nYOU: Who am I?\nOh, in your past life, you were a businessman whose company went, well, broke. But don't worry! We're paying you quite a large sum of money to be here today.";
		getch();
		cout<<"\nYOU: Okay, I guess.";

	}
}
void scramble(char b[30], int j)
{int x;
char temp;
for(int i = 0; i<j ; i++)
{ x = random(j);
temp = b[x];
b[x] = b[i];
b[i] = temp;
}
for(i = 0; i<j; i++)
cout<<b[i];
cout<<" ";
}
void encode(char st[100], int x)
{
for(int i = 0; i<strlen(st); i++)
{if(isalpha(st[i]) && ((st[i] + x) <= 122))
cout<<char(st[i] + x);
else if (isalpha(st[i]))
cout<<char(st[i] + x - 26);
else
cout<<st[i];
}
}
int mazeutil()
{
clrscr();
//cout<<"Welcome to our maze."<<endl<<endl;
//getch();
///////&&&&&&&&&& edit here///////////////////////////
/*cout<<"You, a noble warrior ("<<char(2)<<"), are trapped at the bottom of a dungeon, and are left  with only one route out. The path to survival seems simple enough, right?"<<endl;
getch();
cout<<"\nHowever, many challenges await you. A legion of enemies ("<<char(-71)<<") is present at the   end of the chamber, constantly firing a barrage of bullets, any one of which    will prove fatal to your health."<<endl;
getch();
cout<<"\nDo not worry,noble warrior. You have a special rifle to eliminate your enemies, which fires fatal bullets at a speed much faster than theirs. But be miserly,   for you have only 5 bullets (for all 3 levels) with which to fire."<<endl;
getch();
cout<<"\nYou have 3 lives and thus 3 tries to complete this Herculean task. Make sure to move carefully, as each bullet moves along with you."<<endl;
getch();
cout<<"\nAre you up to this challenge? "<<endl<<endl;*/
cout<<"INTSTRUCTIONS : \nMOVE using W A S D\nSHOOT using X\nExit is indicated by : "<<char(-80)<<"\nEnemy Bullets are fatal\n\n";
cout<<"Press any key to continue: ";
getch();
delay(400);

int f = 0;
//randomize();
for(int h=0;h<10;h++)
{
 xb[h]=yb[h]=-1;
}
for(int g = 0; g<5; g++){
do{
for(int xx=0;xx<20;xx++)
{
 for(int yy=0;yy<77;yy++)
 a[xx][yy]=' ';
}
 x=19;
  y=1;
 for (int h = 0; h<10 + 1; h++)
 {
 xb[h] =-1;
 yb[h] =-1; }
  printmaze();
  for(int l=0;l<10;l++)
  dead[l]=-1;
  for(int i=2;i<20;i+=6-le)
 a[i][76]=char(-71);    //gun bhais
 esh =0;
  topscene();
 printguy();
  //printerr();


for(int k=0;checkpos();k++)
  {
  int cha=getch();

  if (cha == 'w'&&a[x -1][y] !=char(-37)&&x>0)
  {x--;
  clrscr();
  topscene();
  f = printguy(sh);
  if(f == 9)
  {
   return(0);
  }
   sound(330);
  delay(ti);
  nosound(); }
  if (cha == 'a'&&a[x][y - 1] !=char(-37)&&y>0)
  {y--;
   clrscr();
  topscene();
  f = printguy(sh);
  if(f == 9)
  {
   return(0);
  }
   sound(260);
  delay(ti);
  nosound();}
  if (cha == 's'&&a[x +1][y] !=char(-37)&&x<19)
  {x++;
  clrscr();
  topscene();
  f = printguy(sh);
  if(f == 9)
  {
   return(0);
  }
   sound(360);
  delay(ti);
  nosound();}
  if (cha == 'd'&&a[x][y + 1] !=char(-37)&&y<74)
  {y++;
  clrscr();
  topscene();
  f = printguy(sh,cha);
  if(f == 9)
  {
   return(0);
  }
   sound(294);
  delay(ti);
  nosound();}
  if(cha =='x'&&sh<=4)
  {
   xb[sh] =x;
  yb[sh] =y+1;
   sh++;
   clrscr();
  topscene();
  f = printguy(sh);
  if(f == 9)
  {
   return(0);
  }
   sound(110);
  delay(ti*2);
  nosound();}

  eshoot();
  printerr(sh);
//  if(cha == 'o')
 // exit(0);
}
if(checkpos()==0)
{
  clrscr();
  if(le<3)
{
  cout<<"\n\n\n\n\n\n\n\n"<<setw(44);
  cout<<"WELL DONE!";
  cout<<"\n\n"<<setw(48)<<"Let's move to level "<<++le;
  delay(1000);
  cout<<"\n\n\n\n"<<setw(50);
  cout<<"Press o any time to exit";
  delay(1000);
 }
 else
 {
	 cout<<"\n\n\n\n\n\n\n\n\n\n"<<setw(44);
 cout<<"Well done!";
 delay(1500);
 if(li==3)
 return(100);
 else if(li == 2)
 return(67);
 else if(li == 1)
 return 33;
 else
 return 0;
 }
}
}while(!f);
}
getch();

}