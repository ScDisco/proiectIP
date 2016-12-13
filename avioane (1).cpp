#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
char a[20][20],b[20][20];
int C[5]={0, 10, 12, 14};
int i,j,n,m[0];
int x,y,d;
int eroare[10];
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}
void creare_avion(int d, int y, int x)
{

	if(d==1) //vf sus
	{
		//  'L'
		
		//Capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			m[0]--;
			goto loop;
		}
		else 
		{
		a[y][x]='C';
		}
		
		//Corpul test
		if(a[y+1][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y][x]='L'; //reinitializam capul
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x]='1';  //corp
		}
		
		//Aripa 1
		if(a[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //reinitializam corp
			a[y][x]='L'; //cap
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x-1]='1'; //A1
		}
		
		//Aripa 2
		if(a[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //corp
			a[y][x]='L'; //cap
			a[y+1][x-1]='L'; //reinitializam Aripa 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x+1]='1'; //A2
		}
		
		//Corpul
		if(a[y+2][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //corp
			a[y][x]='L'; //cap
			a[y+1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x+1]='L'; //reinitializam Aripa 2
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+2][x]='1';
		}
		
		//Corp iarasi...
		if(a[y+3][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //corp
			a[y][x]='L'; //cap
			a[y+1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x+1]='L'; //reinitializam Aripa 2
			a[y+2][x]='L'; //reinitializam corpul
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+3][x]='1';
		}
		
		//Coada 1
		if(a[y+3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //corp
			a[y][x]='L'; //cap
			a[y+1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x+1]='L'; //reinitializam Aripa 2
			a[y+2][x]='L'; //reinitializam corpul
			a[y+3][x]='L'; //reinitializam corpul iarasi...
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+3][x-1]='1';
		}
		
		//Coada 2
		if(a[y+3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			a[y+1][x]='L'; //corp
			a[y][x]='L'; //cap
			a[y+1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x+1]='L'; //reinitializam Aripa 2
			a[y+2][x]='L'; //reinitializam corpul
			a[y+3][x]='L'; //reinitializam corpul iarasi...
			a[y+3][x-1]='L'; //reinitializam Coada 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+3][x+1]='1';
		}
		
	}
	
	

	
	
	
	
	if(d==2) //vf dreapta
	{
		//corpul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x]='C';
		}
		
		//corp
		if(a[y][x-1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x-1]='2';
		}
		
		//alt corp
		if(a[y][x-2]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x-2]='2';
		}
		
		//mai mult corp
		if(a[y][x-3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			a[y][x-2]='L'; //reinitializam alt corp
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x-3]='2';
		}
		
		
		//A1
		if(a[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			a[y][x-2]='L'; //reinitializam alt corp
			a[y][x-3]='L'; //reinitializam mai mult corp
			m[0]--;
			goto loop;
		}
		else
		{
			
		a[y-1][x-1]='2';
		}
		
		
		//A2
		if(a[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			a[y][x-2]='L'; //reinitializam alt corp
			a[y][x-3]='L'; //reinitializam mai mult corp
			a[y-1][x-1]='L'; //reinitializam Aripa 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x-1]='2';
		}
		
		
		//C1
		if(a[y-1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			a[y][x-2]='L'; //reinitializam alt corp
			a[y][x-3]='L'; //reinitializam mai mult corp
			a[y-1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x-1]='L'; //reinitializam Aripa 2
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-1][x-3]='2';
		}
		
		
		//C2
		if(a[y+1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y][x-1]='L'; //reinitializam corpul
			a[y][x-2]='L'; //reinitializam alt corp
			a[y][x-3]='L'; //reinitializam mai mult corp
			a[y-1][x-1]='L'; //reinitializam Aripa 1
			a[y+1][x-1]='L'; //reinitializam Aripa 2
			a[y-1][x-3]='L'; //reinitializam Coada 1
			m[0]--;
			goto loop;
		}
		else
		{			
			a[y+1][x-3]='2';
		}
		
		
	}
	
	
	if(d==3) //vf jos
	{
		//capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			m[0]--;
			goto loop;
		}
		else 
		{
		a[y][x]='C';
		}
		
		//corpul
		if(a[y-1][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			m[0]--;
			goto loop;
		}
		else 
		{
			a[y-1][x]='3';
		}
		
		//alt corp
		if(a[y-2][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			m[0]--;
			goto loop;
		}
		else 
		{
			a[y-2][x]='3';
		}
		
		//si mai mult corp
		if(a[y-3][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			a[y-2][x]='L'; //reinitializam alt corp
			m[0]--;
			goto loop;
		}
		else 
		{
			a[y-3][x]='3';
		}
		
		
		//A1
		if(a[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			a[y-2][x]='L'; //reinitializam alt corp
			a[y-1][x-1]='L'; //reinitializam si mai mult corp
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-1][x-1]='3';
		}
		
		
		//A2
		if(a[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			a[y-2][x]='L'; //reinitializam alt corp
			a[y-1][x-1]='L'; //reinitializam si mai mult corp
			a[y-1][x+1]='L'; //reinitializam Aripa 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-1][x+1]='3';
		}
		
		
		//C1
		if(a[y-3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			a[y-2][x]='L'; //reinitializam alt corp
			a[y-1][x-1]='L'; //reinitializam si mai mult corp
			a[y-1][x+1]='L'; //reinitializam Aripa 1
			a[y-1][x+1]='L'; //reinitializam Aripa 2
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-3][x-1]='3';
		}
		
		
		//C2
		if(a[y-3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //reinitializam capul
			a[y-1][x]='L'; //reinitializam corpul
			a[y-2][x]='L'; //reinitializam alt corp
			a[y-1][x-1]='L'; //reinitializam si mai mult corp
			a[y-1][x+1]='L'; //reinitializam Aripa 1
			a[y-1][x+1]='L'; //reinitializam Aripa 2
			a[y-3][x-1]='L'; //reinitializam Coada 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-3][x+1]='3';
		}
		
		
	}
	

	
	if(d==4) //vf stanga
	{
		//capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			m[0]--;
			goto loop;
		}
		else 
		{
		a[y][x]='C';
		}
		
		//corpul
		if(a[y][x+1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x+1]='4';
		}
		
		//alt corp
		if(a[y][x+2]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			m[0]--;
			goto loop;
		}
		else
		{	
			a[y][x+2]='4';
		}
		
		//mai mult corp
		if(a[y][x+3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			a[y][x+2]='L'; //resetam alt corp
			m[0]--;
			goto loop;
		}
		else
		{
			a[y][x+3]='4';
		}
		
		
		//A1
		if(a[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			a[y][x+2]='L'; //resetam alt corp
			a[y][x+3]='L'; //resetam mai mult corp
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-1][x+1]='4';
		}
		
		
		//A2
		if(a[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			a[y][x+2]='L'; //resetam alt corp
			a[y][x+3]='L'; //resetam mai mult corp
			a[y-1][x+1]='L'; //resetam Aripa 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x+1]='4';	
		}
		
		
		//C1
		if(a[y-1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			a[y][x+2]='L'; //resetam alt corp
			a[y][x+3]='L'; //resetam mai mult corp
			a[y-1][x+1]='L'; //resetam Aripa 1
			a[y+1][x+1]='L'; //resetam Aripa 2
			m[0]--;
			goto loop;
		}
		else
		{
			a[y-1][x+3]='4';
		}
		
		
		//C2
		if(a[y+1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			a[y][x]='L'; //resetam capul
			a[y][x+1]='L'; //resetam corpul
			a[y][x+2]='L'; //resetam alt corp
			a[y][x+3]='L'; //resetam mai mult corp
			a[y-1][x+1]='L'; //resetam Aripa 1
			a[y+1][x+1]='L'; //resetam Aripa 2
			a[y-1][x+3]='L'; //resetam Coada 1
			m[0]--;
			goto loop;
		}
		else
		{
			a[y+1][x+3]='4';
		}
		
		
	}
	
	
	loop:
	for(int asd=1;asd<=5;asd++) asd++;
}
void afis_mat_a()
{
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			
			if(a[i][j]=='L')
			{
				setcolor(7);
				cout<<a[i][j];
			}
			else if(a[i][j]=='C')
				{
					setcolor(10);
					cout<<a[i][j];
				}
					else if(a[i][j]=='1')
						{
							setcolor(10);
							cout<<a[i][j];
						}
						else if(a[i][j]=='2')
							{
								setcolor(12);
								cout<<a[i][j];
							}
							else if(a[i][j]=='3')
								{
									setcolor(14);
									cout<<a[i][j];
								}
								else if(a[i][j]=='4')
									{
										setcolor(9);
										cout<<a[i][j];
									}
			setcolor(7);
		}
		cout<<"    ";
		cout<<'\n';
	}
}
int valabil()
{
	if(a[x][y]!=0) return 0;
	return 1;
}
int main()
{
	cout<<"Introdu coordonatele varfului si apoi directia\nDirectia varfului 1=sus, 2=dreapta, 3=jos, 4 stanga\n"<<'\n';
/*
	matricea arata ceva de genu:
	
		1  2  3  4  5  6  X (coloana) creste aici
Y   1	L  L   A    L  L     ( X=3 Y=1 )
	2	L   A  A  A    L     ( X=4  Y=2)
l   3	L  L   A    L  L     Avioanele notate cu A...
i | 4	L   A  A  A    L     Spatiile libere cu L...
n | 5   L  L  L  L  L  L
i |
a V
	
asa creste linia
*/
	//bordarea matricii...ofofof
	for(i=0;i<=10;i++)
		a[i][11]=a[i][0]='W';
	for(j=0;j<=10;j++)
		a[11][j]=a[0][j]='W';
	//crearea matricii de rezerva...
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			a[i][j]='L';
	citirea_avioanelor:
	m[0]++;
	//  setcolor(7);
	cout<<"Linia: ";cin>>y; 
	cout<<"Coloana: ";cin>>x;
	directie:
	cout<<"Directia: ";cin>>d;
	if(d<0 || d>4) {cout<<"Directie eronata \n"; goto directie;}
	creare_avion( d , y , x );
	//  setcolor(C[m]);
	afis_mat_a();
	if(m[0]<3) goto citirea_avioanelor;
	
	
	// Jocul propriu zis
	joc:
	return 0;
}
