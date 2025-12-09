#include <stdio.h>
#include <dos.h>
#include "util.h"

void Mairie(void);

void main(void)
{
	char MAIRIE[80];
	char NOM[80];
	char PRENOM[80];
	char DATEEXP[80];
	char NBSERVICE[80];
	int i;

	cls();
	MountMouse();
	ShowMouse();

	Mairie();
	do
	{
		char ch[80];
		sprintf(ch,"%02d %02d",XMouse(),YMouse() );
		print(35,1,INVERSE,ch);
		if( kbhit() )
		{
			int c=getch();
			if( c==ESC )
				break;
		}
		if( XMouse()==1 && YMouse()==1 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}
		if( BetweenOrEqual(XMouse(),30,49) && YMouse()==5 && LeftMouseButton() )
		{
			HideMouse();
			getstring(30,5,MAIRIE,20);
			if( strlen(MAIRIE)==0 )
			{
				for( i=0 ; i<20 ; i++ )
					AffCar(30+i,5,INVERSE,127);
			}
			else
			{
				for( i=0 ; i<20 ; i++ )
					print(30+i,5,NORMAL," ");
				print(30,5,NORMAL,MAIRIE);
			}
			ShowMouse();
		}
		if( BetweenOrEqual(XMouse(),30,49) && YMouse()==7 && LeftMouseButton() )
		{
			HideMouse();
			getstring(30,7,NOM,20);
			if( strlen(NOM)==0 )
			{
				for( i=0 ; i<20 ; i++ )
					AffCar(30+i,7,INVERSE,127);
			}
			else
			{
				for( i=0 ; i<20 ; i++ )
					print(30+i,7,NORMAL," ");
				print(30,7,NORMAL,NOM);
			}
			ShowMouse();
		}
		if( BetweenOrEqual(XMouse(),30,49) && YMouse()==9 && LeftMouseButton() )
		{
			HideMouse();
			getstring(30,9,PRENOM,20);
			if( strlen(PRENOM)==0 )
			{
				for( i=0 ; i<20 ; i++ )
					print(30+i,9,INVERSE,"°");
			}
			else
			{
				for( i=0 ; i<20 ; i++ )
					print(30+i,9,NORMAL," ");
				print(30,9,NORMAL,PRENOM);
			}
			ShowMouse();
		}
		if( BetweenOrEqual(XMouse(),30,39) && YMouse()==11 && LeftMouseButton() )
		{
			HideMouse();
			getstring(30,11,DATEEXP,10);
			if( strlen(DATEEXP)==0 ||
			    !(DATEEXP[2]=='/' && DATEEXP[5]=='/') )
			{
				for( i=0 ; i<10 ; i++ )
					AffCar(30+i,11,INVERSE,15);
			}
			else
			{
				for( i=0 ; i<10 ; i++ )
					print(30+i,11,NORMAL," ");
				print(30,11,NORMAL,DATEEXP);
			}
			ShowMouse();
		}
		if( BetweenOrEqual(XMouse(),30,31) && YMouse()==13 && LeftMouseButton() )
		{
			HideMouse();
			getstring(30,13,NBSERVICE,2);
			if( strlen(NBSERVICE)==0 ||
			    !( (NBSERVICE[0]>='0' && NBSERVICE[0]<='9') &&
			       (NBSERVICE[1]>='0' && NBSERVICE[1]<='9')) )
			{
				for( i=0 ; i<2 ; i++ )
					print(30+i,13,INVERSE,"X");
			}
			else
			{
				for( i=0 ; i<2 ; i++ )
					print(30+i,13,NORMAL," ");
				print(30,13,NORMAL,NBSERVICE);
			}
			ShowMouse();
		}
	}while(1);

	HideMouse();
	KillMouse();
}

void Mairie(void)
{
	int i;

	cadre_s(4,3,55,14);
	HideMouse();
	print(16,3,NORMAL," Definition ");
	print(5,5,NORMAL, "Mairie de               :");
	for( i=0 ; i<20 ; i++ )
		AffCar(30+i,5,INVERSE,'±');
	print(5,7,NORMAL, "Nom du Maire            :");
	for( i=0 ; i<20 ; i++ )
		AffCar(30+i,7,INVERSE,45);
	print(5,9,NORMAL, "Pr‚nom                  :");
	for( i=0 ; i<20 ; i++ )
		AffCar(30+i,9,INVERSE,22);
	print(5,11,NORMAL,"Date Expiration Mandat  :");
	for( i=0 ; i<10 ; i++ )
		AffCar(30+i,11,INVERSE,99);
	print(5,13,NORMAL,"Nombre de services      :");
	for( i=0 ; i<2 ; i++ )
		AffCar(30+i,13,INVERSE,1);
	ShowMouse();
}

