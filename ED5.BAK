#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <dos.h>
#include "util.h"


#define print print2
#define AffCar AffCar2
#define LirCar LirCar2


char ch[80];
int c;
int s;
char ecran[80*25*2];

#define MinX 2
#define MinY 3
#define MaxX 79
#define MaxY 200
static char buffer[MaxY+50][80];
int X=2;
int Y=3;
int tab=8;
int i;
int j;
int i2;
int j2;
char ligne[80];
int iligne=0;
int insert=0;
int attr=NORMAL;
#define UNDERLINE 1
#define UNDERLINE_BOLD 9
#define CTRL_Y	0x0019
#define ALT_F	0x2100
#define ALT_E	0x1200
#define ALT_A	0x1e00
int yF=3;
int yE=3;
int yA=3;
int car;
FILE *fichier;
char nomfichier[80]="Sans_Nom.txt";
char nomfichierprov[80];
int numeroligne;
int numerocol;
char ecran2[80*25*2];
char ecran3[80*25*2];
char prov[80*25*2];
int prov2;
int x;
int y;
int xdeplt=5;
int ydeplt=5;
int motif;
char cmd[80];
char strtab[80];
char ecranouvr[80*25*2];
char provouvr[80*25*2];

void Limits(void);
void menu1(int yF);
void menu2(int yE);
void menu3(int yA);
void BufferToEcran(int Y);
void init(void);
int YEcran(int n);
void goto_xy(void);
void EnregistrerSous(void);
void Enregistrer(void);
void Ouvrir(void);
void execmenu1(int yF);
void execmenu2(int yE);
void execmenu3(int yA);
void Nouveau(void);
void AffNomFichier(void);
void CouperLigne(void);
void EffacerLigne(void);
void InsererLigne(void);
void AideClavier(void);
void AideMenu(void);
void APropos(void);
void PageUp(void);
void PageDown(void);
void Debut(void);
void Fin(void);
void DefTabulation(void);
void Quitter(void);
void Imprimer(void);
void LigneHSimple(void);
void LigneHDouble(void);
void LigneVSimple(void);
void LigneVDouble(void);
void CadreSimple(void);
void CadreDouble(void);
void EcranToBuffer();
void OuvrirFichier(char *nomfichierf);
void main(int nbarg,char *nomarg[])
{
	init();
	cls();
	MountMouse();
	ShowMouse();
	LineX(1,1,80,INVERSE,' ');
	print(1,1,INVERSE,"   Fichier   Edition   Aide");
	LineX(1,25,80,INVERSE,' ');
	print(3,25,INVERSE,"Editeur ED");
	if( insert==1 )
	{
		print(65,25,INVERSE,"INSERT");
	}
	else
	{
		print(65,25,INVERSE,"      ");
	}
	AffCar(72,25,INVERSE,'³');
	cadre_s2(1,2,80,24,NORMAL);
	print(2,2,NORMAL,"[þ]");
	AffNomFichier();
	gotoxy(X,Y);
	if( nbarg==2 )
	{
		OuvrirFichier(nomarg[1]);
		AffNomFichier();
	}
	do
	{
		sprintf(ch,"%02d %03d",X,Y);
		print(74,25,INVERSE,ch);

		if( LeftMouseButton()
		    && XMouse()==3
		    && YMouse()==2 )
		{
			while( LeftMouseButton() );
			Quitter();
		}

		if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),3,11) )
		{
			while( LeftMouseButton() );
			goto menu1;
		}
		if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),13,21) )
		{
			while( LeftMouseButton() );
			goto menu2;
		}
		if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),23,28) )
		{
			while( LeftMouseButton() );
			goto menu3;
		}
		if( RightMouseButton()
		    && BetweenOrEqual(XMouse(),MinX,MaxX)
		    && BetweenOrEqual(YMouse(),3,23) )
		{
			Y=Y-YEcran(Y)+YMouse();
			X=XMouse();
			goto_xy();
			if( insert==1 )
			{
				/* INSERT ONE car */
				for( i=MaxX ; i>X ; i-- )
				{
					buffer[Y][i]=buffer[Y][i-1];
					AffCar(i,YEcran(Y),NORMAL,LirCar(i-1,YEcran(Y)) );
				}
				buffer[Y][i]=' ';
			}
			buffer[Y][X]=motif;
			AffCar(X,YEcran(Y),NORMAL,motif);
			X++;
			Limits();
			goto_xy();
			/*
			BufferToEcran( Y-(YEcran(Y)-3) );
			*/
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),MinX,MaxX)
		    && BetweenOrEqual(YMouse(),3,23) )
		{
			Y=Y-YEcran(Y)+YMouse();
			X=XMouse();
			goto_xy();
		}
		if( RightMouseButton()
		    && XMouse()==80
		    && YMouse()==1 )
		{
			while( RightMouseButton() );
			x=wherex();
			y=wherey();
			HideMouse();
			gettext(1,1,80,25,ecran);
			requester_s(1,5,79,10,"   CaractŠres sp‚ciaux");
			print(2,5,NORMAL,"[þ]");
			AffCar(5,8,INVERSE,'Ú');
			AffCar(7,8,INVERSE,'¿');
			AffCar(9,8,INVERSE,'À');
			AffCar(11,8,INVERSE,'Ù');
			AffCar(13,8,INVERSE,'Ä');
			AffCar(15,8,INVERSE,'³');
			AffCar(17,8,INVERSE,'É');
			AffCar(19,8,INVERSE,'»');
			AffCar(21,8,INVERSE,'È');
			AffCar(23,8,INVERSE,'¼');
			AffCar(25,8,INVERSE,'Í');
			AffCar(27,8,INVERSE,'º');
			AffCar(29,8,INVERSE,'Ã');
			AffCar(31,8,INVERSE,'´');
			AffCar(33,8,INVERSE,'Á');
			AffCar(35,8,INVERSE,'Â');
			AffCar(37,8,INVERSE,'Å');
			AffCar(39,8,INVERSE,'Ì');
			AffCar(41,8,INVERSE,'¹');
			AffCar(43,8,INVERSE,'Ê');
			AffCar(45,8,INVERSE,'Ë');
			AffCar(47,8,INVERSE,'Î');
			ShowMouse();
			do
			{
				if( LeftMouseButton() && XMouse()==3 && YMouse()==5 )
				{
					while( LeftMouseButton() );
					break;
				}
				if( LeftMouseButton() && BetweenOrEqual(XMouse(),3,63) && YMouse()==8 )
				{
					while( LeftMouseButton() );
					motif=LirCar(XMouse(),YMouse());
					break;
				}
			}while( 1 );
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
			gotoxy(x,y);
		}
		if( kbhit() )
		{
			c=bioskey(0);
			s=bioskey(2);
			if( c==_ESC && (s&0x0004) )
			{
				Quitter();
			}
			if( c==ALT_F )
			{
			menu1:
				HideMouse();
				gettext(1,1,80,25,ecran);
				ShowMouse();
				cadre_s2(3,2,24,8,NORMAL);
				do
				{
					menu1(yF);
					if( RightMouseButton() )
					{
						while( RightMouseButton() );
						break;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),3,11) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu1;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),13,21) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu2;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),23,28) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu3;
					}
					if( LeftMouseButton()
						 && BetweenOrEqual(YMouse(),3,7)
						 && BetweenOrEqual(XMouse(),4,23) )
					{
						while( LeftMouseButton() );
						yF=YMouse();
						goto returnF;
					}
					if( kbhit() )
					{
						c=bioskey(0);
						if( c==_ESC )
							break;
						if( c==_RETURN )
						{
						returnF:
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							execmenu1(yF);
							goto fin;
						}
						if( c==ALT_E || c==_RIGHT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu2;
						}
						if( c==ALT_A || c==_LEFT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu3;
						}
						if( c==_UP )
							yF--;
						if( c==_DOWN )
							yF++;
						if( yF>7 )
							yF=3;
						if( yF<3 )
							yF=7;
					}
				}while( 1 );
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
			}
			if( c==ALT_E )
			{
			menu2:
				HideMouse();
				gettext(1,1,80,25,ecran);
				ShowMouse();
				cadre_s2(13,2,29,16,NORMAL);
				do
				{
					menu2(yE);
					if( RightMouseButton() )
					{
						while( RightMouseButton() );
						break;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),3,11) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu1;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),13,21) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu2;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),23,28) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu3;
					}
					if( LeftMouseButton()
						 && BetweenOrEqual(YMouse(),3,15)
						 && BetweenOrEqual(XMouse(),14,28) )
					{
						while( LeftMouseButton() );
						yE=YMouse();
						goto returnE;
					}
					if( kbhit() )
					{
						c=bioskey(0);
						if( c==_ESC )
							break;
						if( c==_RETURN )
						{
						returnE:
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							execmenu2(yE);
							goto fin;
						}
						if( c==ALT_F || c==_LEFT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu1;
						}
						if( c==ALT_A || c==_RIGHT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu3;
						}
						if( c==_UP )
							yE--;
						if( c==_DOWN )
							yE++;
						if( yE>15 )
							yE=3;
						if( yE<3 )
							yE=15;
					}
				}while( 1 );
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
			}
			if( c==ALT_A )
			{
			menu3:
				HideMouse();
				gettext(1,1,80,25,ecran);
				ShowMouse();
				cadre_s2(23,2,32,6,NORMAL);
				do
				{
					menu3(yA);
					if( RightMouseButton() )
					{
						while( RightMouseButton() );
						break;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),3,11) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu1;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),13,21) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu2;
					}
					if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),23,28) )
					{
						while( LeftMouseButton() );
						HideMouse();
						puttext(1,1,80,25,ecran);
						ShowMouse();
						goto menu3;
					}
					if( LeftMouseButton()
						 && BetweenOrEqual(YMouse(),3,5)
						 && BetweenOrEqual(XMouse(),24,31) )
					{
						while( LeftMouseButton() );
						yA=YMouse();
						goto returnA;
					}
					if( kbhit() )
					{
						c=bioskey(0);
						if( c==_ESC )
							break;
						if( c==_RETURN )
						{
						returnA:
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							execmenu3(yA);
							goto fin;
						}
						if( c==ALT_F || c==_RIGHT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu1;
						}
						if( c==ALT_E || c==_LEFT )
						{
							HideMouse();
							puttext(1,1,80,25,ecran);
							ShowMouse();
							goto menu2;
						}
						if( c==_UP )
							yA--;
						if( c==_DOWN )
							yA++;
						if( yA>5 )
							yA=3;
						if( yA<3 )
							yA=5;
					}
				}while( 1 );
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
			}
			/* CTRL y */
			/* efface la ligne courante */
			if( s&0x0004 && ((code(c)+0x60)=='y') )
			{
				if( insert==0 )
				{
					EffacerLigne();
				}
				if( insert==1 )
				{
					CouperLigne();
				}
			}
			/* CTRL n */
			/* nouveau */
			if( s&0x0004 && ((code(c)+0x60)=='n') )
			{
				Nouveau();
			}
			/* CTRL t */
			/* definir la tabulation */
			if( s&0x0004 && ((code(c)+0x60)=='t') )
			{
				DefTabulation();
			}
			if( c==_INSERT )
			{
				if( insert==0 )
				{
					insert=1;
					print(65,25,INVERSE,"INSERT");
				}
				else
				{
					insert=0;
					print(65,25,INVERSE,"      ");
				}
			}
			if( code(c)>='!' && code(c)<='~' || c==0x382 ||
				c==0x088a || c==0x0b85 || c==0x0a87
				|| c==0x532e || c==0x332e
				|| c==0x0083
				|| c==0x0088
				|| c==0x008c
				|| c==0x0093
				|| c==0x0096
				|| c==0x0084
				|| c==0x0089
				|| c==0x008b
				|| c==0x0094
				|| c==0x0081
				|| c==0x2897
				|| c==0x2be6
				|| c==0x1b9c
				|| c==0x3515
				|| c==0x29fd
				|| c==0x0cf8 )
			{
				if( insert==1 )
				{
					/* INSERT ONE car */
					for( i=MaxX ; i>X ; i-- )
					{
						buffer[Y][i]=buffer[Y][i-1];
						AffCar(i,YEcran(Y),NORMAL,LirCar(i-1,YEcran(Y)) );
					}
					buffer[Y][i]=' ';
				}
				buffer[Y][X]=code(c);
				AffCar(X,YEcran(Y),NORMAL,code(c) );
				X++;
				Limits();
				goto_xy();
			}
			if( c==_ESPACE )
			{
				if( insert==1 )
				{
					/* INSERT ONE car */
					for( i=MaxX ; i>X ; i-- )
					{
						buffer[Y][i]=buffer[Y][i-1];
						AffCar(i,YEcran(Y),NORMAL,LirCar(i-1,YEcran(Y)) );
					}
					buffer[Y][i]=' ';
					AffCar(i,YEcran(Y),NORMAL,' ');
				}

				buffer[Y][X]=' ';
				AffCar(X,YEcran(Y),NORMAL,' ');
				X++;
				Limits();
				goto_xy();
			}
			if( c==_RETURN )
			{
				if( insert==0 )
				{
					X=MinX;
					if( YEcran(Y)==23 )
						goto linedown;
					Y++;
					Limits();
					goto_xy();
				}
				if( insert==1 )
				{
					/* on decale dans le buffer*/
					for( j=MaxY ; j>Y+1 ; j-- )
					{
						for( i=MinX ; i<MaxX+1 ; i++ )
						{
							buffer[j][i]=buffer[j-1][i];
						}
					}
					i2=MinX;
					j2=Y+1;
					/* on insert le bout de la ligne */
					for( i=X ; i<MaxX+1 ; i++,i2++ )
					{
						buffer[j2][i2]=buffer[Y][i];
					}
					/* remplit a droite par des blancs */
					for( ; i2<MaxX+1 ; i2++ )
					{
						buffer[j2][i2]=' ';
					}
					/* remplit ligne ori a droite
					   par des blancs */
					for( i=X ; i<MaxX+1 ; i++ )
					{
						buffer[Y][i]=' ';
					}
					/* on place le curseur en bas */
					X=MinX;
					Y++;
					Limits();
					goto_xy();
					BufferToEcran( Y-(YEcran(Y)-3) );
				}
			}
			if( c==_SUPPR )
			{
				for( i=X ; i<MaxX ; i++ )
				{
					buffer[Y][i]=buffer[Y][i+1];
					AffCar(i,YEcran(Y),NORMAL,LirCar(i+1,YEcran(Y)) );
				}
				buffer[Y][i]=' ';
				AffCar(i,YEcran(Y),NORMAL,' ');
			}
			if( c==_DEL )
			{
				if( X==MinX )
					continue;
				for( i=X-1 ; i<MaxX ; i++ )
				{
					buffer[Y][i]=buffer[Y][i+1];
					AffCar(i,YEcran(Y),NORMAL,LirCar(i+1,YEcran(Y)) );
				}
				buffer[Y][i]=' ';
				AffCar(i,YEcran(Y),NORMAL,' ');
				X--;
				Limits();
				goto_xy();
			}
			if( c==_PAGEUP )
			{
				PageUp();
			}
			if( c==_PAGEDOWN )
			{
				PageDown();
			}
			if( c==_UP && !(s&0x0001 || s&0x0002) )
			{
				if( YEcran(Y)==3 && Y!=3 )
				{
					Y-=21;
					Limits();
					BufferToEcran(Y);
					Y+=20;
					goto_xy();
				}
				else
				{
					Y--;
					Limits();
					goto_xy();
				}
			}
			if( c==_UP && (s&0x0001 || s&0x0002) )
			{
				Y-=ydeplt;
				Limits();
				BufferToEcran( Y-(YEcran(Y)-3) );
				goto_xy();
			}
			if( c==_DOWN && !(s&0x0001 || s&0x0002) )
			{
			linedown:
				Y++;
				Limits();
				goto_xy();
				if( YEcran(Y)==3 )
					BufferToEcran(Y);
			}
			if( c==_DOWN && (s&0x0001 || s&0x0002) )
			{
				Y+=ydeplt;
				Limits();
				BufferToEcran( Y-(YEcran(Y)-3) );
				goto_xy();
			}
			if( c==_LEFT && !(s&0x0001 || s&0x0002) )
			{
				X--;
				Limits();
				goto_xy();
			}
			if( c==_LEFT && (s&0x0001 || s&0x0002) )
			{
				X-=xdeplt;
				Limits();
				goto_xy();
			}
			if( c==_RIGHT && !(s&0x0001 || s&0x0002) )
			{
				X++;
				Limits();
				goto_xy();
			}
			if( c==_RIGHT && (s&0x0001 || s&0x0002) )
			{
				X+=xdeplt;
				Limits();
				goto_xy();
			}
			if( c==_DEBUT )
			{
				Debut();
			}
			if( c==_FIN && !(s&0x0001 || s&0x0002) )
			{
				Fin();
			}
			if( c==_FIN && (s&0x0001 || s&0x0002) )
			{
				X=MaxX;
				goto_xy();
			}
			if( c==_TAB )
			{
				X+=tab;
				Limits();
				goto_xy();
			}
			if( c==_SHIFTTAB )
			{
				X-=tab;
				Limits();
				goto_xy();
			}
		}
	fin: ;
	}while( 1 );
}

void LigneHSimple(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		ligne_h_s(x1,y1,XMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto finlhs;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		ligne_h_s(x1,y1,x2);
		ShowMouse();
	}
	EcranToBuffer();
	finlhs: ;
}

void LigneHDouble(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		ligne_h_d(x1,y1,XMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto finlhd;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		ligne_h_d(x1,y1,x2);
		ShowMouse();
	}
	EcranToBuffer();
	finlhd: ;
}

void LigneVSimple(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		ligne_v_s(x1,y1,YMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto finlvs;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		ligne_v_s(x1,y1,y2);
		ShowMouse();
	}
	EcranToBuffer();
	finlvs: ;
}

void LigneVDouble(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		ligne_v_d(x1,y1,YMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto finlvd;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		ligne_v_d(x1,y1,y2);
		ShowMouse();
	}
	EcranToBuffer();
	finlvd: ;
}

void CadreSimple(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		cadre_s(x1,y1,XMouse(),YMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto fincs;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		cadre_s(x1,y1,x2,y2);
		ShowMouse();
	}
	EcranToBuffer();
	fincs: ;
}


void CadreDouble(void)
{
	char ecranori[80*25*2];
	int x1,y1,x2,y2;
	HideMouse();
	gettext(1,1,80,25,ecranori);
	ShowMouse();
	while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x1=XMouse();
	y1=YMouse();
	do
	{
		HideMouse();
		cadre_d(x1,y1,XMouse(),YMouse());
		ShowMouse();
		HideMouse();
		puttext(1,1,80,25,ecranori);
		ShowMouse();
		if( kbhit() )
		{
			int touche=getch();
			if( touche==ESC )
			{
				puttext(1,1,80,25,ecranori);
				goto fincd;
			}
		}
	}while( !(LeftMouseButton()) );
	while( LeftMouseButton() );
	x2=XMouse();
	y2=YMouse();
	if( (MinX<=x1 && x1<=MaxX) && (MinX<=x2 && x2<=MaxX)
	   && (MinY<=y1 && y1<=23) && (MinY<=y2 && y2<=23) )
	{
		HideMouse();
		cadre_d(x1,y1,x2,y2);
		ShowMouse();
	}
	EcranToBuffer();
	fincd: ;
}

void EcranToBuffer()
{
	int vinit=Y-(YEcran(Y)-3);
	int i1=MinX;
	int j1=MinY;
	for( j=vinit ; j<vinit+21 ; j++,j1++ )
	{
		i1=MinX;
		for( i=MinX ; i<MaxX+1 ; i++,i1++ )
		{
			buffer[j][i]=LirCar(i1,j1);
		}
	}
}

void AffNomFichier(void)
{
	LineX(15,2,65,INVERSE,' ');
	print(15,2,INVERSE,nomfichier);
}

void DefTabulation(void)
{
	char ecrantab[80*25*2];
	x=wherex();
	y=wherey();
	HideMouse();
	gettext(1,1,80,25,ecrantab);
	ShowMouse();
	requester_s(5,5,31,12,"Definir la tabulation");
	print(7,8,NORMAL, "Ancienne valeur");
	sprintf(ch,"%02d",tab);
	print(23,8,INVERSE,ch);
	print(7,10,NORMAL,"Nouvelle valeur");
	print(23,10,NORMAL,ch);
	getstring2(23,10,INVERSE,strtab,1);
	tab=atoi(strtab);
	HideMouse();
	puttext(1,1,80,25,ecrantab);
	ShowMouse();
	gotoxy(x,y);
}


void PageUp(void)
{
	Y-=21;
	Limits();
	BufferToEcran( Y-(YEcran(Y)-3) );
	goto_xy();
}

void PageDown(void)
{
	Y+=21;
	Limits();
	BufferToEcran( Y-(YEcran(Y)-3) );
	goto_xy();
}

void Debut(void)
{
	X=MinX;
	goto_xy();
}

void Fin(void)
{
	i=MaxX;
	while( LirCar(i,YEcran(Y))==' ' )
	{
		if( i<MinX )
		{
			i=MinX;
			break;
		}
		i--;
	}
	X=i+1;
	Limits();
	goto_xy();
}

void InsererLigne(void)
{
	for( j=MaxY ; j>Y ; j-- )
	{
		for( i=MinX ; i<MaxX+1 ; i++ )
		{
			buffer[j][i]=buffer[j-1][i];
		}
	}
	EffacerLigne();
	BufferToEcran( Y-(YEcran(Y)-3) );
}

void EffacerLigne(void)
{
	for( i=MinX ; i<MaxX+1 ; i++ )
	{
		buffer[Y][i]=' ';
		AffCar(i,YEcran(Y),NORMAL,' ');
	}
	X=MinX;
	goto_xy();
}

void CouperLigne(void)
{
	for( j=Y ; j<MaxY ; j++ )
	{
		for( i=MinX ; i<MaxX+1 ; i++ )
		{
			buffer[j][i]=buffer[j+1][i];
		}
	}
	for( i=MinX ; i<MaxX+1 ; i++ )
	{
		buffer[j][i]=' ';
	}
	X=MinX;
	goto_xy();
	BufferToEcran( Y-(YEcran(Y)-3) );
}

void Nouveau(void)
{
	char ecrannouv[80*25*2];
	HideMouse();
	gettext(1,1,80,25,ecrannouv);
	requester_s(5,12,30,18,"Effacer tout ");
	print(11,15,NORMAL,"Confirmation ?");
	print(10,17,INVERSE," OK ");
	print(20,17,INVERSE," Annuler ");
	ShowMouse();
	do
	{
		if( BetweenOrEqual(XMouse(),10,13) && YMouse()==17 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			puttext(1,1,80,25,ecrannouv);
			ShowMouse();
			HideMouse();
			gettext(1,1,80,25,ecrannouv);
			ShowMouse();
			init();
			for( j=MinY ; j<24 ; j++ )
			{
				for( i=MinX ; i<MaxX+1 ; i++ )
				{
					AffCar(i,j,NORMAL,' ');
				}
			}
			X=MinX;
			Y=MinY;
			goto_xy();
			strcpy(nomfichier,"Sans_Nom.txt");
			AffNomFichier();
			break;
		}
		if( BetweenOrEqual(XMouse(),20,27) && YMouse()==17 && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			puttext(1,1,80,25,ecrannouv);
			ShowMouse();
			break;
		}
	}while( 1 );
}

void OuvrirFichier(char *nomfichierf)
{
	x=wherex();
	y=wherey();
	ShowMouse();
	fichier=fopen(nomfichierf,"r");
	if( fichier==NULL )
	{
		HideMouse();
		gettext(1,1,80,25,provouvr);
		requester_d(5,5,29,12,"Erreur Utilisateur");
		print(7,8,NORMAL,"Lecture impossible !");
		print(16,10,INVERSE,"OK");
		ShowMouse();
		do
		{
			if( BetweenOrEqual(XMouse(),16,17) && YMouse()==10 && LeftMouseButton() )
			{
				while( LeftMouseButton() );
				HideMouse();
				puttext(1,1,80,25,provouvr);
				ShowMouse();
				gotoxy(x,y);
				goto fichiernullf;
			}
		}while(1);
	}
	strcpy(nomfichier,nomfichierf);
	init();
	i=MinX;
	j=MinY;
	car=fgetc(fichier);
	while( car!=EOF )
	{
		if( j>MaxY )
			break;
		if( car=='\t' )
		{
			i+=tab-1;
			if( i>MaxX )
			{
				j++;
				i=MinX;
			}
			else
				i++;
			goto lirecarf;
		}
		if( car=='\n' )
		{
			j++;
			i=MinX;
		}
		else
		{
			if( i>MaxX )
			{
				i=MinX;
				j++;
			}
			buffer[j][i]=car;
			i++;
		}
	lirecarf:
		car=fgetc(fichier);
	}
	fclose(fichier);
	BufferToEcran( Y-(YEcran(Y)-3) );
	X=MinX;
	Y=MinY;
	BufferToEcran(Y);
	goto_xy();
fichiernullf: ;
}

void Ouvrir(void)
{
	x=wherex();
	y=wherey();
	HideMouse();
	gettext(1,1,80,25,ecranouvr);
	ShowMouse();
	cadre_s2(5,5,61,9,NORMAL);
	print(7,5,NORMAL," Ouvrir ");
	getstring2(8,7,INVERSE,nomfichierprov,50);
	HideMouse();
	puttext(1,1,80,25,ecranouvr);
	ShowMouse();
	fichier=fopen(nomfichierprov,"r");
	if( fichier==NULL )
	{
		HideMouse();
		gettext(1,1,80,25,provouvr);
		requester_d(5,5,29,12,"Erreur Utilisateur");
		print(7,8,NORMAL,"Lecture impossible !");
		print(16,10,INVERSE,"OK");
		ShowMouse();
		do
		{
			if( BetweenOrEqual(XMouse(),16,17) && YMouse()==10 && LeftMouseButton() )
			{
				while( LeftMouseButton() );
				HideMouse();
				puttext(1,1,80,25,provouvr);
				ShowMouse();
				gotoxy(x,y);
				goto fichiernull;
			}
		}while(1);
	}
	strcpy(nomfichier,nomfichierprov);
	init();
	i=MinX;
	j=MinY;
	car=fgetc(fichier);
	while( car!=EOF )
	{
		if( j>MaxY )
			break;
		if( car=='\t' )
		{
			i+=tab-1;
			if( i>MaxX )
			{
				j++;
				i=MinX;
			}
			else
				i++;
			goto lirecar;
		}
		if( car=='\n' )
		{
			j++;
			i=MinX;
		}
		else
		{
			if( i>MaxX )
			{
				i=MinX;
				j++;
			}
			buffer[j][i]=car;
			i++;
		}
	lirecar:
		car=fgetc(fichier);
	}
	fclose(fichier);
	BufferToEcran( Y-(YEcran(Y)-3) );
	X=MinX;
	Y=MinY;
	BufferToEcran(Y);
	goto_xy();
fichiernull: ;
}

void Enregistrer(void)
{
	char provenreg[80*25*2];
	x=wherex();
	y=wherey();
	for( j=MaxY ; j>MinY ; j-- )
	{
		for( i=MinX ; i<MaxX+1 ; i++ )
		{
			if( buffer[j][i]!=' ' )
			{
				goto suite;
			}
		}
	}
suite:
	numeroligne=j;
	fichier=fopen(nomfichier,"w");
	if( fichier==NULL )
	{
		HideMouse();
		gettext(1,1,80,25,provenreg);
		ShowMouse();
		requester_d(5,5,29,12,"Erreur Utilisateur");
		print(7,8,NORMAL,"Ecriture impossible !");
		print(16,10,INVERSE,"OK");
		do
		{
			if( BetweenOrEqual(XMouse(),16,17) && YMouse()==10 && LeftMouseButton() )
			{
				while( LeftMouseButton() );
				HideMouse();
				puttext(1,1,80,25,provenreg);
				ShowMouse();
				gotoxy(x,y);
				goto fichiernull;
			}
		}while(1);
	}
	for( j=MinY ; j<numeroligne+1 ; j++ )
	{
		for( i=MaxX ; i>MinX ; i-- )
		{
			if( buffer[j][i]!=' ' )
			{
				goto suite2;
			}
		}
	suite2:
		numerocol=i+1;
		for( i=2 ; i<numerocol ; i++ )
		{
			fprintf(fichier,"%c",buffer[j][i] );
		}
		fprintf(fichier,"\n");
	}
	fclose(fichier);
fichiernull: ;
}

void EnregistrerSous(void)
{
	char ecranenreg[80*25*2];
	char provsous[80*25*2];
	x=wherex();
	y=wherey();
	HideMouse();
	gettext(1,1,80,25,ecranenreg);
	ShowMouse();
	cadre_s2(5,5,61,9,NORMAL);
	print(7,5,NORMAL," Enregistrer sous ... ");
	getstring2(8,7,INVERSE,nomfichierprov,50);
	HideMouse();
	puttext(1,1,80,25,ecranenreg);
	ShowMouse();
	for( j=MaxY ; j>MinY ; j-- )
	{
		for( i=MinX ; i<MaxX+1 ; i++ )
		{
			if( buffer[j][i]!=' ' )
			{
				goto suite;
			}
		}
	}
suite:
	numeroligne=j;
	fichier=fopen(nomfichierprov,"w");
	if( fichier==NULL )
	{
		HideMouse();
		gettext(1,1,80,25,provsous);
		requester_d(5,5,29,12,"Erreur Utilisateur");
		print(7,8,NORMAL,"Ecriture impossible !");
		print(16,10,INVERSE,"OK");
		ShowMouse();
		do
		{
			if( BetweenOrEqual(XMouse(),16,17) && YMouse()==10 && LeftMouseButton() )
			{
				while( LeftMouseButton() );
				HideMouse();
				puttext(1,1,80,25,provsous);
				ShowMouse();
				gotoxy(x,y);
				goto fichiernull;
			}
		}while(1);
	}
	strcpy(nomfichier,nomfichierprov);
	for( j=MinY ; j<numeroligne+1 ; j++ )
	{
		for( i=MaxX ; i>MinX ; i-- )
		{
			if( buffer[j][i]!=' ' )
			{
				goto suite2;
			}
		}
	suite2:
		numerocol=i+1;
		for( i=2 ; i<numerocol ; i++ )
		{
			fprintf(fichier,"%c",buffer[j][i] );
		}
		fprintf(fichier,"\n");
	}
	fclose(fichier);
fichiernull: ;
}

int YEcran(int n)
{
	int r=(n-(n/21)*21);
	if( r==0 )
		return(21);
	if( r==1 )
		return(22);
	if( r==2 )
		return(23);
	return(r);
}

void goto_xy(void)
{
	gotoxy(X,YEcran(Y));
}

void BufferToEcran(int Y)
{
	for( j=Y ; j<Y+21 ; j++ )
		for( i=2 ; i<80 ; i++ )
			AffCar(i,YEcran(j),NORMAL,buffer[j][i] );
}

void Limits(void)
{
	if( X>MaxX )
	{
		X=MaxX;
	}
	if( X<MinX )
	{
		X=MinX;
	}
	if( Y>MaxY )
	{
		Y=MaxY;
	}
	if( Y<MinY )
	{
		Y=MinY;
	}
}

void init(void)
{
	for( j=0 ; j<MaxY+50 ; j++ )
	{
		for( i=0 ; i<80 ; i++ )
		{
			buffer[j][i]=' ';
		}
	}
}

void execmenu1(int yF)
{
	switch(yF)
	{
		case 3:
			Nouveau();
			break;
		case 4:
			Ouvrir();
			AffNomFichier();
			break;
		case 5:
			Enregistrer();
			AffNomFichier();
			break;
		case 6:
			EnregistrerSous();
			AffNomFichier();
			break;
		case 7:
			Quitter();
			break;
	}
}

void Imprimer(void)
{
	char ecranimpr[80*25*2];
	x=wherex();
	y=wherey();
	HideMouse();
	gettext(1,1,80,25,ecranimpr);
	cls();
	strcpy(cmd,"type ");
	strcat(cmd,nomfichier);
	system(cmd);
	ShowMouse();
	c=getch();
	HideMouse();
	puttext(1,1,80,25,ecranimpr);
	ShowMouse();
	AffNomFichier();
	gotoxy(x,y);
}

void Quitter(void)
{
	char ecranquit[80*25*2];
	HideMouse();
	gettext(1,1,80,25,ecranquit);
	requester_s(5,12,30,18,"QUITTER");
	print(11,15,NORMAL,"Confirmation ?");
	print(10,17,INVERSE," OK ");
	print(20,17,INVERSE," Annuler ");
	ShowMouse();
	do
	{
		if( BetweenOrEqual(XMouse(),10,13)
			&& YMouse()==17
			&& LeftMouseButton() )
		{
			while( LeftMouseButton() );
			if( BetweenOrEqual(XMouse(),10,13)
				&& YMouse()==17 )
			{
				HideMouse();
				puttext(1,1,80,25,ecranquit);
				cls();
				exit(0);
			}
		}
		if( BetweenOrEqual(XMouse(),20,27)
			&& YMouse()==17
			&& LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			puttext(1,1,80,25,ecranquit);
			ShowMouse();
			break;
		}
	}while( 1 );
}

void menu1(int yF)
{
	switch(yF)
	{
		case 3:
			print(4,3,INVERSE,"Nouveau");
			print(4,4,NORMAL,"Ouvrir");
			print(4,5,NORMAL,"Enregistrer");
			print(4,6,NORMAL,"Enregistrer sous ...");
			print(4,7,NORMAL,"Quitter");
			break;
		case 4:
			print(4,3,NORMAL,"Nouveau");
			print(4,4,INVERSE,"Ouvrir");
			print(4,5,NORMAL,"Enregistrer");
			print(4,6,NORMAL,"Enregistrer sous ...");
			print(4,7,NORMAL,"Quitter");
			break;
		case 5:
			print(4,3,NORMAL,"Nouveau");
			print(4,4,NORMAL,"Ouvrir");
			print(4,5,INVERSE,"Enregistrer");
			print(4,6,NORMAL,"Enregistrer sous ...");
			print(4,7,NORMAL,"Quitter");
			break;
		case 6:
			print(4,3,NORMAL,"Nouveau");
			print(4,4,NORMAL,"Ouvrir");
			print(4,5,NORMAL,"Enregistrer");
			print(4,6,INVERSE,"Enregistrer sous ...");
			print(4,7,NORMAL,"Quitter");
			break;
		case 7:
			print(4,3,NORMAL,"Nouveau");
			print(4,4,NORMAL,"Ouvrir");
			print(4,5,NORMAL,"Enregistrer");
			print(4,6,NORMAL,"Enregistrer sous ...");
			print(4,7,INVERSE,"Quitter");
			break;
	}

}

void execmenu2(int yE)
{
	switch(yE)
	{
		case 3:
			CouperLigne();
			break;
		case 4:
			EffacerLigne();
			break;
		case 5:
			InsererLigne();
			break;
		case 6:
			PageDown();
			break;
		case 7:
			PageUp();
			break;
		case 8:
			Debut();
			break;
		case 9:
			Fin();
			break;
		case 10:
			LigneHSimple();
			break;
		case 11:
			LigneHDouble();
			break;
		case 12:
			LigneVSimple();
			break;
		case 13:
			LigneVDouble();
			break;
		case 14:
			CadreSimple();
			break;
		case 15:
			CadreDouble();
			break;
	}
}

void menu2(int yE)
{
	switch(yE)
	{
		case 3:
			print(14,3,INVERSE,"Couper ligne");
			print(14,4,NORMAL, "Effacer ligne");
			print(14,5,NORMAL, "Ins‚rer ligne");
			print(14,6,NORMAL, "Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 4:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,INVERSE,"Effacer ligne");
			print(14,5,NORMAL, "Ins‚rer ligne");
			print(14,6,NORMAL, "Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 5:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,INVERSE,"Ins‚rer ligne");
			print(14,6,NORMAL, "Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 6:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,INVERSE,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 7:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,INVERSE,"Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 8:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL ,"Page pr‚c‚dente");
			print(14,8,INVERSE,"D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 9:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,INVERSE,"Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 10:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,INVERSE,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 11:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,INVERSE,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 12:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,INVERSE,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 13:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,INVERSE,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 14:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,INVERSE,"Cadre simple");
			print(14,15,NORMAL,"Cadre double");
			break;
		case 15:
			print(14,3,NORMAL ,"Couper ligne");
			print(14,4,NORMAL ,"Effacer ligne");
			print(14,5,NORMAL ,"Ins‚rer ligne");
			print(14,6,NORMAL ,"Page suivante");
			print(14,7,NORMAL, "Page pr‚c‚dente");
			print(14,8,NORMAL, "D‚but de ligne");
			print(14,9,NORMAL, "Fin de ligne");
			print(14,10,NORMAL,"Ligne h. simple");
			print(14,11,NORMAL,"Ligne h. double");
			print(14,12,NORMAL,"Ligne v. simple");
			print(14,13,NORMAL,"Ligne v. double");
			print(14,14,NORMAL,"Cadre simple");
			print(14,15,INVERSE,"Cadre double");
			break;
	}
}

void AideClavier(void)
{
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,60,23,"Les Commandes du Clavier (1)");
	print(7,7,INVERSE," CTRL ESC ");
	print(17,7,NORMAL,": Quitter l'‚diteur de texte");
	print(7,9,INVERSE,"[Inser]");
	print(17,9,NORMAL,": Passer en mode Insertion de caractŠres");
	print(7,11,INVERSE,"[D‚but]");
	print(17,11,NORMAL,": Se positionner au d‚but de la ligne");
	print(7,13,INVERSE,"[PageHaut]");
	print(17,13,NORMAL,": Se positionner … la page pr‚c‚dente");
	print(7,15,INVERSE,"[Suppr]");
	print(17,15,NORMAL,": Supprimer un caractŠre");
	print(7,17,INVERSE,"[ Fin ]");
	print(17,17,NORMAL,": Se positionner en fin de phrase");
	print(7,19,INVERSE,"SHIFT [ Fin ]");
	print(21,19,NORMAL,": Se positionner en fin de ligne");
	print(7,21,INVERSE,"[PageBas]");
	print(17,21,NORMAL,": Se positionner … la page suivante");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,60,23,"Les Commandes du Clavier (2)");
	print(7,7,INVERSE, "  HAUT  ");
	print(17,7,NORMAL,": Se placer un caractŠre plus haut");
	print(7,9,INVERSE, "  BAS   ");
	print(17,9,NORMAL,": Se placer un caractŠre plus bas");
	print(7,11,INVERSE, " GAUCHE ");
	print(17,11,NORMAL,": Se placer sur le caractŠre de gauche");
	print(7,13,INVERSE," DROITE ");
	print(17,13,NORMAL,": Se placer sur le caractŠre de droite");
	print(7,15,INVERSE, "SHIFT HAUT  ");
	print(20,15,NORMAL,": Se placer 5 caractŠres plus haut");
	print(7,17,INVERSE, "SHIFT BAS   ");
	print(20,17,NORMAL,": Se placer 5 caractŠres plus bas");
	print(7,19,INVERSE, "SHIFT GAUCHE");
	print(20,19,NORMAL,": Se placer 5 caractŠres plus … gauche");
	print(7,21,INVERSE, "SHIFT DROITE");
	print(20,21,NORMAL,": Se placer 5 caractŠres plus … droite");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,60,23,"Les Commandes du Clavier (3)");
	print(7,7,INVERSE, " ALT F  ");
	print(17,7,NORMAL, ": Activer le menu Fichier");
	print(7,9,INVERSE, " ALT E  ");
	print(17,9,NORMAL, ": Activer le menu Edition");
	print(7,11,INVERSE," ALT A  ");
	print(17,11,NORMAL,": Activer le menu Aide");
	print(7,13,INVERSE," CTRL N ");
	print(17,13,NORMAL,": Cr‚er un nouveau document");
	print(7,15,INVERSE," CTRL T ");
	print(17,15,NORMAL,": Red‚finir la tabulation");
	print(7,17,INVERSE," CTRL Y ");
	print(17,17,NORMAL,"+ INSER : Couper une ligne");
	print(17,18,NORMAL,"- INSER : Effacer une ligne");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
}

void AideMenu(void)
{
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,65,23,"Les Commandes du Menu Fichier (1)");
	print(7,7,INVERSE," Nouveau ");
	print(17,7,NORMAL,": Cr‚er un nouveau document");
	print(7,9,INVERSE," Ouvrir  ");
	print(17,9,NORMAL,": Reprendre un document existant");
	print(7,11,INVERSE," Enregistrer ");
	print(21,11,NORMAL,": Sauver un document sous son nom courant");
	print(7,13,INVERSE," Enreg. sous ");
	print(21,13,NORMAL,": Sauver un document sous un nouveau nom");
	print(7,15,INVERSE," Quitter ");
	print(17,15,NORMAL,": Quitter l'‚diteur de texte");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,65,23,"Les Commandes du Menu Edition (2)");
	print(7,7,INVERSE," Couper ligne  ");
	print(22,7,NORMAL,":  Supprime la ligne courante");
	print(7,9,INVERSE," Effacer ligne ");
	print(22,9,NORMAL,":  Efface la ligne courante");
	print(7,11,INVERSE," Ins‚rer ligne ");
	print(22,11,NORMAL,":  InsŠre une ligne o— est le curseur");
	print(7,13,INVERSE," Page suivante ");
	print(22,13,NORMAL,":  Affichage de la page suivante (bas)");
	print(7,15,INVERSE," Page pr‚c‚dente ");
	print(24,15,NORMAL,":  Affichage de la page pr‚c‚dente (haut)");
	print(7,17,INVERSE," D‚but de ligne ");
	print(22,17,NORMAL,":  Positionne le curseur en d‚but de ligne");
	print(7,19,INVERSE," Fin de ligne  ");
	print(22,19,NORMAL,":  Positionne le curseur en fin de ligne");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,65,23,"Les Commandes du Menu Edition (3)");
	print(7,7,INVERSE," Ligne h. simple ");
	print(24,7,NORMAL,":  Trace une ligne horizontale simple");
	print(7,9,INVERSE," Ligne h. double ");
	print(24,9,NORMAL,":  Trace une ligne horizontale double");
	print(7,11,INVERSE," Ligne v. simple ");
	print(24,11,NORMAL,":  Trace une ligne verticale simple");
	print(7,13,INVERSE," Ligne v double ");
	print(24,13,NORMAL,":  Trace une ligne verticale double");
	print(7,15,INVERSE," Cadre simple ");
	print(24,15,NORMAL,":  Trace un cadre simple ");
	print(7,17,INVERSE," Cadre double ");
	print(24,17,NORMAL,":  Trace un cadre double ");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,65,23,"Les Commandes du Menu Edition (4)");
	print(7,7,INVERSE," Clavier  ");
	print(18,7,NORMAL,":  Aide sur les commandes clavier");
	print(7,9,INVERSE," Menu  ");
	print(18,9,NORMAL,":  Aide sur les commandes des menus");
	print(7,11,INVERSE," A Propos ");
	print(18,11,NORMAL,":  A propos du logiciel");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
}

void APropos(void)
{
	HideMouse();
	gettext(1,1,80,25,ecran2);
	requester_s(5,4,60,23,"A Propos de l'‚diteur ED");
	print(7,9,INVERSE, "  DATE  ");
	print(17,9,NORMAL,": Mars 1994");
	print(7,11,INVERSE," AUTEUR ");
	print(17,11,NORMAL,": Christophe Pichaud");
	print(17,12,NORMAL,"  67, rue des ‚rables");
	print(17,13,NORMAL,"  21800 Qu‚tigny");
	print(15,23,NORMAL+BOLD,"Click souris...");
	ShowMouse();
	while( !LeftMouseButton() );
	while( LeftMouseButton() );
	HideMouse();
	puttext(1,1,80,25,ecran2);
	ShowMouse();
}

void execmenu3(int yA)
{
	switch(yA)
	{
		case 3:
			AideClavier();
			break;
		case 4:
			AideMenu();
			break;
		case 5:
			APropos();
			break;
	}
}

void menu3(int yA)
{
	switch(yA)
	{
		case 3:
			print(24,3,INVERSE,"Clavier");
			print(24,4,NORMAL,"Menu");
			print(24,5,NORMAL,"A Propos");
			break;
		case 4:
			print(24,3,NORMAL,"Clavier");
			print(24,4,INVERSE,"Menu");
			print(24,5,NORMAL,"A Propos");
			break;
		case 5:
			print(24,3,NORMAL,"Clavier");
			print(24,4,NORMAL,"Menu");
			print(24,5,INVERSE,"A Propos");
			break;
	}
}



