#include <stdio.h>
#include <dir.h>
#include <dos.h>
#include "util.h"
void openwindow(int x,int y);
void Configuration(void);
void affichage(void);
void impression(void);
	int c;
	int x=20;
	int y=5;
	char ecran[80*25*2];
	char ecranori[80*25*2];
	char ecranfen[80*25*2];
	char ch[80];
	char ancfimaire[80]=   "lemaire.txt";
	char fimaire[80]=      "lemaire.txt";
	char ancfiservices[80]="service.txt";
	char fiservices[80]=   "service.txt";
	char nomfichier[80];
void main(void)
{

	MountMouse();
	cls();
	Affxfois(1,1,INVERSE,' ',80);
	print(20,1,INVERSE," Gestion Livret Mairie ");
	gettext(1,1,80,25,ecranori);
	openwindow(x,y);
	gettext(1,1,80,25,ecranfen);
	ShowMouse();
	do
	{

		if( kbhit() )
		{
			c=getch();
			if( c==ESC )
				break;
		}

		/* QUITTER */

		if( XMouse()==(x+3) && YMouse()==y && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			KillMouse();
			cls();
			break;
		}

		/* module MAIRE */

		if( XMouse()==(x+4) && YMouse()==(y+2) && LeftMouseButton() )
		{
			HideMouse();
			AffCar(x+4,y+2,NORMAL,'X');
			ShowMouse();
			while( LeftMouseButton() );
			HideMouse();
			AffCar(x+4,y+2,NORMAL,' ');
			gettext(1,1,80,25,ecran);
			sprintf(ch,"maire.exe lemaire.dat %s",fimaire);
			system(ch);
			ShowMouse();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* module SERVICES */

		if( XMouse()==(x+4) && YMouse()==(y+4) && LeftMouseButton() )
		{
			HideMouse();
			AffCar(x+4,y+4,NORMAL,'X');
			ShowMouse();
			while( LeftMouseButton() );
			HideMouse();
			AffCar(x+4,y+4,NORMAL,' ');
			gettext(1,1,80,25,ecran);
			sprintf(ch,"defserv2.exe service.dat %s",fiservices);
			system(ch);
			ShowMouse();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* affichage */

		if( XMouse()==(x+4) && YMouse()==(y+8) && LeftMouseButton() )
		{
			HideMouse();
			AffCar(x+4,y+8,NORMAL,'X');
			ShowMouse();
			while( LeftMouseButton() );
			HideMouse();
			AffCar(x+4,y+8,NORMAL,' ');
			gettext(1,1,80,25,ecran);
			ShowMouse();
			affichage();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* impression */

		if( XMouse()==(x+4) && YMouse()==(y+10) && LeftMouseButton() )
		{
			HideMouse();
			AffCar(x+4,y+10,NORMAL,'X');
			ShowMouse();
			while( LeftMouseButton() );
			HideMouse();
			AffCar(x+4,y+10,NORMAL,' ');
			gettext(1,1,80,25,ecran);
			ShowMouse();
			impression();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* module TEXTES */

		if( XMouse()==(x+4) && YMouse()==(y+6) && LeftMouseButton() )
		{
			HideMouse();
			AffCar(x+4,y+6,NORMAL,'X');
			ShowMouse();
			while( LeftMouseButton() );
			HideMouse();
			AffCar(x+4,y+6,NORMAL,' ');
			gettext(1,1,80,25,ecran);
			ShowMouse();
			cherchefichier(nomfichier,"livret\\*.txt");
			HideMouse();
			sprintf(ch,"ed5.exe livret\\%s",nomfichier);
			system(ch);
			ShowMouse();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* CONFIGURATION */

		if( XMouse()==(x+4) && YMouse()==(y+12) && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			ShowMouse();
			Configuration();
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		if( BetweenOrEqual(XMouse(),x,x+30) && XMouse()!=(x+3) && YMouse()==y && LeftMouseButton() )
		{
			int dx=XMouse()-x;
			do
			{
				if( !(LeftMouseButton()) )
					break;
				x=XMouse()-dx;
				y=YMouse();
				HideMouse();
				puttext(1,1,80,25,ecranori);
				if( x>50 )
					x=50;
				if( x<1 )
					x=1;
				if( y>11 )
					y=11;
				if( y<1 )
					y=1;
				openwindow(x,y);
				ShowMouse();
			}while( 1 );
			HideMouse();
			cls();
			x=XMouse()-dx;
			y=YMouse();
			puttext(1,1,80,25,ecranori);
			if( x>50 )
				x=50;
			if( x<1 )
				x=1;
			if( y>11 )
				y=11;
			if( y<1 )
				y=1;
			openwindow(x,y);
			ShowMouse();
		}
	fin: ;
	}while( 1 );
}

void impression(void)
{
	char ecranaff[80*25*2];
	HideMouse();
	cadre_d2(10,5,60,15,NORMAL);
	print(12,5,NORMAL,"[þ]");
	print(20,5,INVERSE," Impression ");
	print(13,7,NORMAL, "[ ] fichier g‚n‚r‚ par le module Maire");
	print(13,9,NORMAL, "[ ] fichier g‚n‚r‚ par le module Services");
	print(13,11,NORMAL,"[ ] chapitre du livret");
	ShowMouse();
	do
	{
		if( XMouse()==13 && YMouse()==5 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}

		/* afficher fichier gen maire */
		if( XMouse()==14 && YMouse()==7 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			cls();
			sprintf(ch,"copy %s prn:",fimaire);
			system(ch);
			print(30,9,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==9 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

		/* afficher fichier gen service */
		if( XMouse()==14 && YMouse()==9 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			cls();
			sprintf(ch,"copy %s prn:",fiservices);
			system(ch);
			print(30,25,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==25 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

		/* afficher chapitre du livret */
		if( XMouse()==14 && YMouse()==11 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			ShowMouse();
			cherchefichier(nomfichier,"livret\\*.txt");
			HideMouse();
			cls();
			sprintf(ch,"copy livret\\%s prn:",nomfichier);
			system(ch);
			print(30,25,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==25 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

	}while( 1 );
}

void affichage(void)
{
	char ecranaff[80*25*2];
	HideMouse();
	cadre_d2(10,5,60,15,NORMAL);
	print(12,5,NORMAL,"[þ]");
	print(20,5,INVERSE," Affichage ");
	print(13,7,NORMAL, "[ ] fichier g‚n‚r‚ par le module Maire");
	print(13,9,NORMAL, "[ ] fichier g‚n‚r‚ par le module Services");
	print(13,11,NORMAL,"[ ] chapitre du livret");
	ShowMouse();
	do
	{
		if( XMouse()==13 && YMouse()==5 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}

		/* afficher fichier gen maire */
		if( XMouse()==14 && YMouse()==7 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			cls();
			sprintf(ch,"more < %s",fimaire);
			system(ch);
			print(30,9,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==9 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

		/* afficher fichier gen service */
		if( XMouse()==14 && YMouse()==9 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			cls();
			sprintf(ch,"more < %s",fiservices);
			system(ch);
			print(30,25,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==25 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

		/* afficher chapitre du livret */
		if( XMouse()==14 && YMouse()==11 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranaff);
			ShowMouse();
			cherchefichier(nomfichier,"livret\\*.txt");
			HideMouse();
			cls();
			sprintf(ch,"more < livret\\%s",nomfichier);
			system(ch);
			print(30,25,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==25 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranaff);
			ShowMouse();
		}

	}while( 1 );
}

void Configuration(void)
{
	char ecranconfig[80*25*2];
	HideMouse();
	cadre_d2(10,5,60,15,NORMAL);
	print(12,5,NORMAL,"[þ]");
	print(20,5,INVERSE," Configuration ");
	print(13,7,NORMAL,"[ ] fichier g‚n‚r‚ par le module Maire");
	print(13,9,NORMAL,"[ ] fichier g‚n‚r‚ par le module Services");
	ShowMouse();
	do
	{
		if( XMouse()==13 && YMouse()==5 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}

		/* fichier gen maire */
		if( XMouse()==14 && YMouse()==7 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranconfig);
			cadre_d2(1,3,80,10,NORMAL);
			print(7,3,INVERSE," Configuration du module Maire ");
			sprintf(ch,"Nom du fichier : %s",ancfimaire);
			print(5,5,NORMAL,ch);
			print(22,7,NORMAL,ancfimaire);
			print(5,7,NORMAL,"Nouveau nom    :");
			getstring2(22,7,INVERSE,fimaire,50);
			Affxfois(22,7,NORMAL,' ',51);
			print(22,7,NORMAL,fimaire);
			strcpy(ancfimaire,fimaire);
			print(30,9,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==9 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranconfig);
			ShowMouse();
		}

		/* fichier gen service */
		if( XMouse()==14 && YMouse()==9 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecranconfig);
			cadre_d2(1,3,80,10,NORMAL);
			print(7,3,INVERSE," Configuration du module Service ");
			sprintf(ch,"Nom du fichier : %s",ancfiservices);
			print(5,5,NORMAL,ch);
			print(22,7,NORMAL,ancfiservices);
			print(5,7,NORMAL,"Nouveau nom    :");
			getstring2(22,7,INVERSE,fiservices,50);
			Affxfois(22,7,NORMAL,' ',51);
			print(22,7,NORMAL,fiservices);
			strcpy(ancfiservices,fiservices);
			print(30,9,INVERSE," OK ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),30,33) && YMouse()==9 && LeftMouseButton() )
				{
					while( LeftMouseButton() );
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecranconfig);
			ShowMouse();
		}
	}while( 1 );
}

void openwindow(int x,int y)
{
	cadre_d2(x,y,x+30,y+14,NORMAL);
	print(x+2,y,NORMAL,"[þ]");
	print(x+10,y,INVERSE," Groupe nø1 ");
	print(x+3,y+2,NORMAL, "[ ]  module Maire");
	print(x+3,y+4,NORMAL, "[ ]  module Services");
	print(x+3,y+6,NORMAL, "[ ]  module Textes");
	print(x+3,y+8,NORMAL, "[ ]  affichage");
	print(x+3,y+10,NORMAL,"[ ]  impression");
	print(x+3,y+12,NORMAL,"[ð]  Configuration");
}

