#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>

class pos {
public:
	int x,y;
	void add(int a, int b)
	{
		x = a;
		y = b;
	}
};

void main()
{clrscr();
randomize();

cout<<"INTSTRUCTIONS : \nMove using W A S D\nEat as many pellets as you can\n";
cout<<"Press any key to continue: ";
getch();
clrscr();
char ss[24][79];
pos p[100];
for(int i = 0; i<24; i++)
{for(int j = 0; j<79;j++)
	ss[i][j] = ' ';
}
int f = 0,x = 1 + random(22),y = 1 + random(77),pn = 4;
char in;
for(int j = 0; j<5; j++)
p[j].add(0,j);
//ss[x][y] = char(-37);
while(!f)
{
ss[x][y] = 4;
for(int a = 0; a<pn; a++)
{
	ss[p[a].x][p[a].y] = char(-37); 
}
ss[p[pn].x][p[pn].y] = char(-2);
for(i = 0; i<24; i++)
{for(int j = 0; j<79;j++)
	{
		cout<<ss[i][j];
		ss[i][j] = char(-80);
	}
cout<<endl;
}
in = getch();
if(in=='a' && !(p[pn -1].x == p[pn].x && p[pn -1].y == p[pn].y -1) && (p[pn].y != 0) )
{
	for(int i = 0; i<pn; i++)
		p[i] = p[i + 1];
	p[pn].add(p[pn].x,p[pn].y - 1);
}
else if(in=='w' && !(p[pn -1].x == p[pn].x - 1 && p[pn -1].y == p[pn].y) && (p[pn].x != 0) )
{
	for(int i = 0; i<pn; i++)
		p[i] = p[i + 1];
	p[pn].add(p[pn].x - 1,p[pn].y);
}
else if(in=='d' && !(p[pn -1].x == p[pn].x && p[pn -1].y == p[pn].y + 1) && (p[pn].y != 78) )
{
	for(int i = 0; i<pn; i++)
		p[i] = p[i + 1];
	p[pn].add(p[pn].x,p[pn].y + 1);
}
else if(in=='s' && !(p[pn -1].x == p[pn].x + 1 && p[pn -1].y == p[pn].y) && (p[pn].x != 23) )
{
	for(int i = 0; i<pn; i++)
		p[i] = p[i + 1];
	p[pn].add(p[pn].x + 1,p[pn].y);
}
//else if(in=='f')
//f = 1;
if(p[pn].x==x && p[pn].y==y)
{
	pn++;
	if(pn>1) p[pn].add(2*p[pn - 1].x - p[pn - 2].x, 2*p[pn - 1].y - p[pn - 2].y);
	
	else {
			int f = random(2);
			p[pn].add(p[pn - 1].x + f,p[pn - 1].y + 1 - f);
		 }
	x = 1 + random(23);
	y = 1 + random(78);
}

for(int i = 0; i<=pn;i++)
{
	for(int j = 0; j<pn; j++)
	{
		if(p[i].x == p[j].x && i!=j)
		{
			if(p[i].y == p[j].y)
			{
				f = 1;
				clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n";
				cout<<setw(46)<<"GAME  OVER\n";
				cout<<setw(43)<<"Score: "<<pn - 4;
			}	}
	}}}
getch();
}