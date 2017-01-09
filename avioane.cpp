#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
char a[20][20],b[20][20];
char mat_calc[20][20];
int C[5]={0, 10, 12, 14}; //matricea culorilor afisate
int i,j,n,m[0];
int lin_dist, col_dist;
int avi_dist_de_calc=0;
int x,y,d;
int jucator=1;
int t[0];
int nr_morti;

char cap='A';
char cap_pc='A';
char z='0';
int eroare[10];

struct avion
{
    int x1; int y1; int d1;
    int x2; int y2; int d2;
    int x3; int y3; int d3;
};
avion vec[10];

void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}
void golire()
{
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			a[i][j]='L';
	m[0]=0;
	t[0]=1;
}
void creare_avion(int d, int y, int x, char &nr, char &C)
{
	if(d==1) //vf sus
	{
		//  'L'

		//Capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x]=C;
		}

		//Corpul
		if(a[y+1][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x]=nr;  //corp
		}

		//alt corp
		if(a[y+2][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+2][x]=nr;
		}

		//Corp iarasi...
		if(a[y+3][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+3][x]=nr;
		}

		//Aripa 1
		if(a[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x-1]=nr; //A1
		}

		//Aripa 2
		if(a[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x+1]=nr; //A2
		}


		//Coada 1
		if(a[y+3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+3][x-1]=nr;
		}

		//Coada 2
		if(a[y+3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+3][x+1]=nr;
		}

	}



	if(d==2) //vf dreapta
	{
		//corpul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x]=C;
		}

		//corp
		if(a[y][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x-1]=nr;
		}

		//alt corp
		if(a[y][x-2]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x-2]=nr;
		}

		//mai mult corp
		if(a[y][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x-3]=nr;
		}


		//A1
		if(a[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{

		a[y-1][x-1]=nr;
		}


		//A2
		if(a[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x-1]=nr;
		}


		//C1
		if(a[y-1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x-3]=nr;
		}


		//C2
		if(a[y+1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x-3]=nr;
		}


	}


	if(d==3) //vf jos
	{
		//capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
		a[y][x]=C;
		}

		//corpul
		if(a[y-1][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x]=nr;
		}

		//alt corp
		if(a[y-2][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-2][x]=nr;
		}

		//si mai mult corp
		if(a[y-3][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-3][x]=nr;
		}


		//A1
		if(a[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x-1]=nr;
		}


		//A2
		if(a[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x+1]=nr;
		}


		//C1
		if(a[y-3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-3][x-1]=nr;
		}


		//C2
		if(a[y-3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-3][x+1]=nr;
		}


	}



	if(d==4) //vf stanga
	{
		//capul
		if(a[y][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
		a[y][x]=C;
		}

		//corpul
		if(a[y][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x+1]=nr;
		}

		//alt corp
		if(a[y][x+2]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x+2]=nr;
		}

		//mai mult corp
		if(a[y][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y][x+3]=nr;
		}


		//A1
		if(a[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x+1]=nr;
		}


		//A2
		if(a[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x+1]=nr;
		}


		//C1
		if(a[y-1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y-1][x+3]=nr;
		}


		//C2
		if(a[y+1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			a[y+1][x+3]=nr;
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
				cout<<a[i][j]<<" ";
			}
			else if(a[i][j]=='C')
				{
					setcolor(14);
					cout<<a[i][j]<<" ";
				}
				else if(a[i][j]=='A')
                {
                    setcolor(10);
					cout<<a[i][j]<<" ";
                }
                else if(a[i][j]=='B')
                {
                    setcolor(12);
					cout<<a[i][j]<<" ";
                }
					else if(a[i][j]=='1')
						{
							setcolor(10);
							cout<<a[i][j]<<" ";
						}
						else if(a[i][j]=='2')
							{
								setcolor(12);
								cout<<a[i][j]<<" ";
							}
							else if(a[i][j]=='3')
								{
									setcolor(14);
									cout<<a[i][j]<<" ";
								}/*
								else if(a[i][j]=='4')
									{
										setcolor(9);
										cout<<a[i][j];
									}*/
			setcolor(7);
		}
		cout<<"    ";
		cout<<'\n';
	}
}


void afis_mat_b()
{
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{

			if(b[i][j]=='L')
			{
				setcolor(7);
				cout<<b[i][j]<<" ";
			}
			else if(b[i][j]=='C' || b[i][j]=='A'|| b[i][j]=='B')
				{
					setcolor(10);
					cout<<b[i][j]<<" ";
				}
					else if(b[i][j]=='1')
						{
							setcolor(10);
							cout<<b[i][j]<<" ";
						}
						else if(b[i][j]=='2')
							{
								setcolor(12);
								cout<<b[i][j]<<" ";
							}
							else if(b[i][j]=='3')
								{
									setcolor(14);
									cout<<b[i][j];
								}
								else if(b[i][j]=='4')
									{
										setcolor(9);
										cout<<b[i][j];
									}
			setcolor(7);
		}
		cout<<"    ";
		cout<<'\n';
	}
}

void avisare_totala_mc()
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
            cout<<mat_calc[i][j]<<" ";
        cout<<'\n';
    }

}

void afis_mat_calc()
{
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{

			if(mat_calc[i][j]=='L')
			{
				setcolor(7);
				cout<<mat_calc[i][j]<<" ";
			}
			else if(mat_calc[i][j]=='X')
				{
					setcolor(12);
					cout<<mat_calc[i][j]<<" ";
                }
                else if(mat_calc[i][j]=='O')
                {
                    setcolor(10);
                    cout<<mat_calc[i][j]<<" ";
                }
			setcolor(7);
		}
		cout<<"    ";
		cout<<'\n';
	}
}
void creare_avion_pc(int d, int y, int x, char &nr, char &C)
{
	if(d==1) //vf sus
	{
		//  'L'

		//Capul
		if(b[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x]=C;
		}

		//Corpul
		if(b[y+1][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x]=nr;  //corp
		}

		//alt corp
		if(b[y+2][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+2][x]=nr;
		}

		//Corp iarasi...
		if(b[y+3][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+3][x]=nr;
		}

		//Aripa 1
		if(b[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x-1]=nr; //A1
		}

		//Aripa 2
		if(b[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x+1]=nr; //A2
		}


		//Coada 1
		if(b[y+3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+3][x-1]=nr;
		}

		//Coada 2
		if(b[y+3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+3][x+1]=nr;
		}

	}



	if(d==2) //vf dreapta
	{
		//corpul
		if(b[y][x]!='L')
		{
			cout<<"Coordonate eronate\n"; //nu trebuie reinitializat nimic
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x]=C;
		}

		//corp
		if(b[y][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x-1]=nr;
		}

		//alt corp
		if(b[y][x-2]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x-2]=nr;
		}

		//mai mult corp
		if(b[y][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x-3]=nr;
		}


		//A1
		if(b[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
            b[y-1][x-1]=nr;
		}


		//A2
		if(b[y+1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x-1]=nr;
		}


		//C1
		if(b[y-1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x-3]=nr;
		}


		//C2
		if(b[y+1][x-3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x-3]=nr;
		}


	}


	if(d==3) //vf jos
	{
		//capul
		if(b[y][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
            b[y][x]=C;
		}

		//corpul
		if(b[y-1][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x]=nr;
		}

		//alt corp
		if(b[y-2][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-2][x]=nr;
		}

		//si mai mult corp
		if(b[y-3][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-3][x]=nr;
		}


		//A1
		if(b[y-1][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x-1]=nr;
		}


		//A2
		if(b[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x+1]=nr;
		}


		//C1
		if(b[y-3][x-1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-3][x-1]=nr;
		}


		//C2
		if(b[y-3][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-3][x+1]=nr;
		}


	}



	if(d==4) //vf stanga
	{
		//capul
		if(b[y][x]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
            b[y][x]=C;
		}

		//corpul
		if(b[y][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x+1]=nr;
		}

		//alt corp
		if(b[y][x+2]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x+2]=nr;
		}

		//mai mult corp
		if(b[y][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y][x+3]=nr;
		}


		//A1
		if(b[y-1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x+1]=nr;
		}


		//A2
		if(b[y+1][x+1]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x+1]=nr;
		}


		//C1
		if(b[y-1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y-1][x+3]=nr;
		}


		//C2
		if(b[y+1][x+3]!='L')
		{
			cout<<"Coordonate eronate\n";
			golire();
			nr='0';
			goto loop;
		}
		else
		{
			b[y+1][x+3]=nr;
		}


	}


	loop:
	for(int asd=1;asd<=5;asd++) asd++;
}
int main()
{
    ///aluc
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
	//bordarea matricii...
	for(i=0;i<=10;i++)
		a[i][11]=a[i][0]='W';
	for(j=0;j<=10;j++)
		a[11][j]=a[0][j]='W';

	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			a[i][j]='L';
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			b[i][j]='L';
    for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			mat_calc[i][j]='L';

	citirea_avioanelor:
	m[0]++;
	z++;
	//  setcolor(7);
	cout<<"Linia: ";cin>>y;
	cout<<"Coloana: ";cin>>x;
	directie:
	cout<<"Directia: ";cin>>d;
	if(d<0 || d>4) {cout<<"Directie eronata \n"; goto directie;}
	creare_avion( d , y , x , z, cap);
	if(t[0]%2==1) {cap='A';t[0]=2;}
	else cap++;
	//  setcolor(C[m]);
	afis_mat_a();
	if(m[0]<3) goto citirea_avioanelor;

    cout<<"\n\nCalculatorul is va genera avioanele acum.\n";

    char z1='0';
    srand(time(NULL));

    int setul=rand()%5+1;
vec[1].x1=5;
vec[1].y1=5;
vec[1].d1=1;

vec[1].x2=2;
vec[1].y2=1;
vec[1].d2=1;

vec[1].x3=7;
vec[1].y3=1;
vec[1].d3=1;





vec[2].x1=1;
vec[2].y1=2;
vec[2].d1=4;

vec[2].x2=10;
vec[2].y2=2;
vec[2].d2=2;

vec[2].x3=6;
vec[2].y3=10;
vec[2].d3=3;





/*
vec[3].x1=;
vec[3].y1=;
vec[3].d1=;

vec[3].x2=;
vec[3].y2=;
vec[3].d2=;

vec[3].x3=;
vec[3].y3=;
vec[3].d3=;






vec[4].x1=;
vec[4].y1=;
vec[4].d1=;

vec[4].x2=;
vec[4].y2=;
vec[4].d2=;

vec[4].x3=;
vec[4].y3=;
vec[4].d3=;







vec[5].x1=;
vec[5].y1=;
vec[5].d1=;

vec[5].x2=;
vec[5].y2=;
vec[5].d2=;

vec[5].x3=;
vec[5].y3=;
vec[5].d3=;
*/
z1++;

setul =rand()%2 + 1;
    creare_avion_pc(vec[setul].d1, vec[setul].y1, vec[setul].x1, z1, cap_pc);
if(t[0]%2==1) {cap='A';t[0]=2;}
	else cap_pc++;
z1++;
	creare_avion_pc(vec[setul].d2, vec[setul].y2, vec[setul].x2, z1, cap_pc);
if(t[0]%2==1) {cap='A';t[0]=2;}
	else cap_pc++;
z1++;
    creare_avion_pc(vec[setul].d3, vec[setul].y3, vec[setul].x3, z1, cap_pc);
	// Jocul propriu zis


	system("pause");
	system("cls");

	//afis_mat_b();


	joc:

if(jucator==1)
{


	//citirea coordonatelor
	cout<<"Linia pe care vrei sa o distrugi: ";cin>>lin_dist;
	cout<<"Coloana pe care vrei sa distrugi: ";cin>>col_dist;


//a e a ta
//b calculator
//mat_calc matricea care o vezidupa ce ai lovit in matricea calcuatorului

	//In caz de rateu
	if(b[lin_dist][col_dist]=='L') {cout<<"\n\nRatat\n\n";	mat_calc[lin_dist][col_dist]='O'; b[lin_dist][col_dist]='L';}

	//testul coordonatelor
		if((b[lin_dist][col_dist]!='L') && (b[lin_dist][col_dist]!='C') && (b[lin_dist][col_dist]!='B') && (b[lin_dist][col_dist]!='A'))
			{cout<<"\n\nLovit\n\n";  mat_calc[lin_dist][col_dist]='X'; b[lin_dist][col_dist]='L';}


	//in caz de lovitura la motor
	if(b[lin_dist][col_dist]=='A' || b[lin_dist][col_dist]=='C' || b[lin_dist][col_dist]=='B')
	{
		cout<<"\n\nMort\n\n";
		nr_morti++;
		if(b[lin_dist][col_dist]=='A')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(b[i][j]=='1') {b[i][j]='L'; mat_calc[i][j]='L';}
				{b[lin_dist][col_dist]='L';mat_calc[lin_dist][col_dist]='X';}
		}
		if(b[lin_dist][col_dist]=='B')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(b[i][j]=='2') {b[i][j]='L'; mat_calc[i][j]='L';}
				{b[lin_dist][col_dist]='L'; mat_calc[lin_dist][col_dist]='X';}
		}
		if(b[lin_dist][col_dist]=='C')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(b[i][j]=='3') {b[i][j]='L'; mat_calc[i][j]='L';}
				{b[lin_dist][col_dist]='L'; mat_calc[lin_dist][col_dist]='X';}
		}
	}
//avisare_totala_mc();
	afis_mat_calc();
	cout<<"\n\n";
	afis_mat_a();
	cout<<"\n\n";
	//afis_mat_a();

jucator=2;
	if(nr_morti!=3) goto joc;
	else return 69;
}


if(jucator==2)
{
    lin_dist=rand()%10+1;
    col_dist=rand()%10+1;

    if((a[lin_dist][col_dist]!='L') && (a[lin_dist][col_dist]!='C') && (a[lin_dist][col_dist]!='B') && (a[lin_dist][col_dist]!='A'))
			{
			    cout<<"\nAi fost lovit\n\n";
			    a[lin_dist][col_dist]='L';
            }


	//in caz de lovitura la motor
	if(a[lin_dist][col_dist]=='A' || a[lin_dist][col_dist]=='C' || a[lin_dist][col_dist]=='B')
	{
		cout<<"\nU iz ded!\n\n";
		avi_dist_de_calc++;
		if(a[lin_dist][col_dist]=='A')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(a[i][j]=='1') {a[i][j]='L';}
				{a[lin_dist][col_dist]='L';}
		}
		if(a[lin_dist][col_dist]=='B')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(a[i][j]=='2') {a[i][j]='L'; }
				{a[lin_dist][col_dist]='L'; }
		}
		if(a[lin_dist][col_dist]=='C')
		{
			for(i=1;i<=10;i++)
				for(j=1;j<=10;j++)
					if(a[i][j]=='3') {a[i][j]='L';}
				{a[lin_dist][col_dist]='L'; }
		}
	}
		jucator=1;
		if(avi_dist_de_calc!=3) goto joc;
		else return 5;
}

	return 0;
}
