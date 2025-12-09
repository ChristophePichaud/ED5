#include <dos.h>
#include <dir.h>

#define ESC	27
#define NORMAL	7
#define INVERSE 112
#define	BOLD	8
#define CLIGNOT	128
#define	F1	59
#define	F2	60
#define	F3	61
#define	F4	62
#define	F5	63
#define	F6	64
#define F7	65
#define F8	66
#define F9	67
#define F10	68

#define MODE	0xb800
#define BACKSPACE	8
#define RETURN	13
#define UP	72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

#define _ESC	0x011b
#define _F1	0x3b00
#define _F2	0x3c00
#define _F3	0x3d00
#define _F4	0x3e00
#define _F5	0x3f00
#define _F6	0x4000
#define _F7	0x4100
#define _F8	0x4200
#define _F9	0x4300
#define _F10	0x4400
#define _ESPACE	0x3920
#define _SHIFTTAB	0x0f00
#define _TAB	0x0f09
#define _DEL	0x0e08
#define _RETURN	0x1c0d
#define _UP	0x4800
#define _DOWN	0x5000
#define _LEFT	0x4b00
#define _RIGHT	0x4d00
#define _INSERT	0x5200
#define _SUPPR	0x5300
#define _FIN	0x4f00
#define _DEBUT	0x4700
#define _PAGEUP	0x4900
#define _PAGEDOWN	0x5100

int LeftMouseButton(void);
int RightMouseButton(void);
int LeftMouseButtonRel(void);
int RightMouseButtonRel(void);
int XMouse(void);
int YMouse(void);
void HideMouse(void);
void ShowMouse(void);
void MountMouse(void);
void MoveMouse(int x,int y);
void SetSpeedMouse(int v1,int v2);
void KillMouse(void);
void print(int x,int y,int attribut,char *chaine);
void print2(int x,int y,int attribut,char *chaine);
void AffCar(int x,int y,int attribut,unsigned char car);
void AffCar2(int x,int y,int attribut,unsigned char car);
unsigned char LirCar(int x,int y);
unsigned char LirCar2(int x,int y);
int Between(int var,int min,int max);
int BetweenOrEqual(int var,int min,int max);
void cls(void);
void Index(void);
void cadre_s(int x1, int y1, int x2, int y2);
void cadre_d(int x1, int y1, int x2, int y2);
void ligne_h_s(int x1, int y1, int x2);
void ligne_h_d(int x1, int y1, int x2);
void ligne_v_s(int x1, int y1, int y2);
void ligne_v_d(int x1, int y1, int y2);
void cadre_s2(int x1, int y1, int x2, int y2,int attribut);
void cadre_d2(int x1, int y1, int x2, int y2,int attribut);
int etendu(int c);
int codeetendu(int c);
int code(int c);
void getstring(int x1,int y1,char *d,int lg);
void Affxfois(int x,int y,int attribut,unsigned char car,int n);
void requester_s(int x1,int y1,int x2,int y2,char *titre);
void requester_d(int x1,int y1,int x2,int y2,char *titre);
void LineX(int x1,int y1,int x2,int attribut,unsigned char car);
void LineY(int x1,int y1,int y2,int attribut,unsigned char car);
void Limits_g(int *X,int MinX,int MaxX);
void getstring2(int x1,int y1,int attr,char *d,int lg);
void cherchefichier(char *nom,char *path);

void cherchefichier(char *nom,char *path)
{

	int i;
	int j;
	int in;
	int posy;
	char chemin[80];
	char nomfichier[80];
	struct ffblk f1;
	char ecranfi[80*25*2];

	i=15;
	j=1;
	HideMouse();
	gettext(1,1,80,25,ecranfi);
	cls();
	ShowMouse();
	if( findfirst(path,&f1,FA_DIREC)==0 );
	{
		HideMouse();
		print(i,j,NORMAL,f1.ff_name);
		ShowMouse();
		j+=2;
		while( findnext(&f1)==0 )
		{
			if( j>24 )
			{
				i+=15;
				j=1;
			}
			HideMouse();
			print(i,j,NORMAL,f1.ff_name);
			ShowMouse();
			j+=2;
		}
	}
	do
	{
		if( LeftMouseButton() )
		{
			in=XMouse()-((XMouse())%15);
			posy=YMouse();
			while(LeftMouseButton() );
			for( i=0; i<12 ; i++,in++ )
			{
				nomfichier[i]=LirCar(in,posy);
			}
			nomfichier[i]=0;
			HideMouse();
			puttext(1,1,80,25,ecranfi);
			ShowMouse();
			strcpy(nom,nomfichier);
			break;
		}
	}while( 1 );
}

void getstring2(int x1,int y1,int attr,char *d,int lg)
{
	int X=x1;
	int Y=y1;
	int MinX=x1;
	int MaxX=x1+lg;
	char avant[80];
	char iavant=0;
	char NOM[80];
	int IND=0;
	int c;
	int s;
	int tab=8;

	int i;
	int j;
	int insert=1;

	/* on recupere la ligne d'avant */
	for( i=x1 ; i<x1+lg+1 ; i++,iavant++ )
	{
		avant[iavant]=LirCar(i,Y);
	}
	avant[iavant]=0;

	/* on trace un cadre de blancs */
	for( i=x1 ; i<x1+lg+1 ; i++ )
	{
		AffCar(i,Y,attr,' ');
	}

	gotoxy(X,Y);
	do
	{
		if( kbhit() )
		{
			c=bioskey(0);
			s=bioskey(2);
			if( c==_ESC )
			{
				strcpy(d,avant);
				break;
			}
			/* CTRL y */
			/* efface la ligne courante */
			if( s&0x0004 && ((code(c)+0x60)=='y') )
			{
				for( i=MinX ; i<MaxX+1 ; i++ )
				{
					AffCar(i,Y,attr,' ');
				}
				X=MinX;
				gotoxy(X,Y);
			}
			if( c==_INSERT )
			{
				if( insert==0 )
					insert=1;
				else
					insert=0;
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
						AffCar(i,Y,attr,LirCar(i-1,Y) );
					}
					AffCar(i,Y,attr,' ');
				}
				gotoxy(X,Y);
				AffCar(X,Y,attr,code(c) );
				X++;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_ESPACE )
			{
				if( insert==1 )
				{
					/* INSERT ONE car */
					for( i=MaxX ; i>X ; i-- )
					{
						AffCar(i,Y,attr,LirCar(i-1,Y) );
					}
					AffCar(i,Y,attr,' ');
				}
				AffCar(X,Y,attr,' ');
				X++;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_RETURN )
			{
				/* on recupere la ligne */
				for( i=x1 ; i<x1+lg+1 ; i++,IND++ )
				{
					NOM[IND]=LirCar(i,Y);
				}
				NOM[IND]=0;
				strcpy(d,NOM);
				break;
			}
			if( c==_SUPPR )
			{
				for( i=X ; i<MaxX ; i++ )
				{
					AffCar(i,Y,attr,LirCar(i+1,Y) );
				}
				AffCar(i,Y,attr,' ');
			}
			if( c==_DEL )
			{
				if( X==MinX )
					continue;
				for( i=X-1 ; i<MaxX ; i++ )
				{
					AffCar(i,Y,attr,LirCar(i+1,Y) );
				}
				AffCar(i,Y,attr,' ');
				X--;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_LEFT )
			{
				X--;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_RIGHT )
			{
				X++;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_DEBUT )
			{
				X=MinX;
				gotoxy(X,Y);
			}
			if( c==_FIN )
			{
				i=MaxX;
				while( LirCar(i,Y)==' ' )
				{
					if( i<MinX )
					{
						i=MinX;
						break;
					}
					i--;
				}
				X=i+1;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
			if( c==_TAB )
			{
				X+=tab;
				Limits_g(&X,MinX,MaxX);
				gotoxy(X,Y);
			}
		}
	}while( 1 );
}

void Limits_g(int *X,int MinX,int MaxX)
{
	if( *X>MaxX )
	{
		*X=MaxX;
	}
	if( *X<MinX )
	{
		*X=MinX;
	}
}


void LineX(int x1,int y1,int x2,int attribut,unsigned char car)
{
	Affxfois(x1,y1,attribut,car,x2-x1+1);
}

void LineY(int x1,int y1,int y2,int attribut,unsigned char car)
{
	int y;
	for( y=y1 ; y<y2 ; y++ )
	{
		AffCar(x1,y,attribut,car);
	}
}

void requester_s(int x1,int y1,int x2,int y2,char *titre)
{
	cadre_s2(x1,y1,x2,y2,NORMAL);
	Affxfois(x1+1,y1+1,INVERSE,' ',x2-(x1+1));
	print(x1+3,y1+1,INVERSE,titre);
}

void requester_d(int x1,int y1,int x2,int y2,char *titre)
{
	cadre_d2(x1,y1,x2,y2,NORMAL);
	Affxfois(x1+1,y1+1,INVERSE,' ',x2-(x1+1));
	print(x1+3,y1+1,INVERSE,titre);
}

void getstring(int x1,int y1,char *d,int lg)
{
	char NOM[80];
	int c;
	int x=x1;
	int y=y1;
	int IND=0;
	int i;

	for( i=x1 ; i<x1+lg ; i++ )
		print(i,y1,INVERSE," ");
	gotoxy(x,y);
	do
	{
		c=bioskey(0);
		if( (code(c)>='!' && code(c)<='~') ||
		    (code(c)==' ') ||
		    (code(c)=='‚') ||
		    (code(c)=='Š') ||
		    (code(c)=='…') ||
		    (code(c)=='—') ||
		    (code(c)=='ƒ') ||
		    (code(c)=='ˆ') ||
		    (code(c)=='Œ') ||
		    (code(c)=='“') ||
		    (code(c)=='–') )
		{
			NOM[IND]=code(c);
			AffCar(x,y,INVERSE,code(c));
			x++;
			IND++;
		}
		if( c==_DEL )
		{
			IND--;
			NOM[IND]=' ';
			x--;
			if( x<x1 )
				x=x1;
			AffCar(x,y,INVERSE,' ');
			gotoxy(x,y);
		}
		if( x>x1+lg-1 )
			break;
		else
			gotoxy(x,y);
		if( c==_RETURN )
		{
			NOM[IND]=0;
			break;
		}
	}while(1);
	gotoxy(1,1);
	NOM[lg]=0;
	strcpy(d,NOM);
}


void KillMouse(void)
{
	union REGS registre;
	/* desactiver le driver de la souris */
	registre.x.ax=0x001f;
	int86(0x33,&registre,&registre);
}

void Affxfois(int x,int y,int attribut,unsigned char car,int n)
{
	int i;
	for( i=0 ; i<n ; i++ )
		AffCar(x+i,y,attribut,car);
}

void Index(void)
{
	void RunAuteur(int,int);
	int MaxY1=12;
	int MinY1=10;
	int y1=9;
	int c=DOWN;


	cadre_s(8,6,22,8);
	print(9,7,NORMAL,"Les mots-cl‚s");
	do
	{
		if( c!=UP && c!=DOWN && c!=ESC )
			goto fin;
		print(1,1,NORMAL,"Index ...");
		cadre_s(8,6,22,8);
		print(9,7,NORMAL,"Les mots-cl‚s");
		cadre_d(9,9,21,13);
		if( c==UP )
			y1--;
		if( c==DOWN )
			y1++;
		if( c==ESC )
			break;

		if( y1>MaxY1 )
			y1=MinY1;
		if( y1<MinY1 )
			y1=MaxY1;

		switch(y1)
		{
			case 10:
				print(10,10,INVERSE,"Les auteurs");
				print(10,11,NORMAL,"Les menus 1");
				print(10,12,NORMAL,"Les menus 2");
				break;
			case 11:
				print(10,10,NORMAL,"Les auteurs");
				print(10,11,INVERSE,"Les menus 1");
				print(10,12,NORMAL,"Les menus 2");
				break;
			case 12:
				print(10,10,NORMAL,"Les auteurs");
				print(10,11,NORMAL,"Les menus 1");
				print(10,12,INVERSE,"Les menus 2");
				break;
		}

		switch(y1)
		{
			int i;
			case 10:
				for( i=1 ; i<25 ; i++ )
				{
					Affxfois(29,i,NORMAL,' ',51);
				}
				cadre_s(29,1,79,10);
				print(30,2,INVERSE,"NOM      ");
				print(40,2,NORMAL,"Pichaud");
				print(30,3,INVERSE,"PRENOM   ");
				print(40,3,NORMAL,"Christophe");
				print(30,4,INVERSE,"ADRESSE  ");
				print(40,4,NORMAL,"67 Rue des Erables");
				print(40,5,NORMAL,"21800 Quetigny");
				print(30,6,INVERSE,"TELEPHONE");
				print(40,6,NORMAL,"80-46-29-58");
				cadre_d(65,2,72,5);
				print(66,6,NORMAL,"Photo");

				cadre_s(29,11,79,20);
				print(30,12,INVERSE,"NOM      ");
				print(40,12,NORMAL,"Pichaud");
				print(30,14,INVERSE,"PRENOM   ");
				print(40,14,NORMAL,"Christophe");
				print(30,16,INVERSE,"ADRESSE  ");
				print(40,16,NORMAL,"67 Rue des Erables");
				print(40,17,NORMAL,"21800 Quetigny");
				print(30,19,INVERSE,"TELEPHONE");
				print(40,19,NORMAL,"80-46-29-58");
				cadre_d(65,12,72,15);
				print(66,16,NORMAL,"Photo");
				break;
			case 11:
				for( i=1 ; i<25 ; i++ )
				{
					Affxfois(29,i,NORMAL,' ',51);
				}
				cadre_s(29,1,79,24);
				print(30,10,INVERSE,"aide ...");
				print(40,10,NORMAL,"aide ...");
				print(30,11,INVERSE,"aide ...");
				print(40,11,NORMAL,"aide ...");
				break;
			case 12:
				for( i=1 ; i<25 ; i++ )
				{
					Affxfois(29,i,NORMAL,' ',51);
				}
				cadre_s(29,1,79,24);
				print(30,10,INVERSE,"aide ...");
				print(40,10,NORMAL,"aide ...");
				print(30,11,INVERSE,"aide ...");
				print(40,11,NORMAL,"aide ...");
				break;
		}
fin:
		c=getch();
	}while( c!=ESC );
}

int etendu(int c)
{
	return( (c&0x00ff) ==0 );
}

int codeetendu(int c)
{
	c=c&0xff00;
	c=c>>8;
	return( c );
}

int code(int c)
{
	return( c&0x00ff);
}

void cls(void)
{
	int x;
	int y;

	for( x=0 ; x<81 ; x++ )
	{
		for( y=0 ; y<26 ; y++ )
		{
			print(x,y,NORMAL," ");
		}
	}
	gotoxy(1,1);
}

int Between(int var,int min,int max)
{
	return( min<var && var<max );
}

int BetweenOrEqual(int var,int min,int max)
{
	return( min<=var && var<=max );
}


int LeftMouseButton(void)
{
	union REGS registre;
	int left;
	int mask=0x07;


	registre.x.ax=0x0003;
	int86(0x33,&registre,&registre);
	left=registre.x.bx&mask;
	return( left==1 ? 1 : 0 );
}

int RightMouseButton(void)
{
	union REGS registre;
	int right;
	int mask=0x07;

	registre.x.ax=0x0003;
	int86(0x33,&registre,&registre);
	right=registre.x.bx&mask;
	return( right==2 ? 1 : 0 );
}

int LeftMouseButtonRel(void)
{
	union REGS registre;
	int left;
	int mask=0x07;


	registre.x.ax=0x0006;
	registre.x.bx=0x0000;

	int86(0x33,&registre,&registre);
	left=registre.x.bx&mask;
	return( left==1 ? 1 : 0 );
}

int RightMouseButtonRel(void)
{
	union REGS registre;
	int right;
	int mask=0x07;

	registre.x.ax=0x0006;
	registre.x.ax=0x0001;
	int86(0x33,&registre,&registre);
	right=registre.x.bx&mask;
	return( right==2 ? 1 : 0 );
}

void SetSpeedMouse(int v1,int v2)
{
	union REGS registre;

	registre.x.ax=0x000f;
	registre.x.cx=v1;
	registre.x.dx=v2;
	int86(0x33,&registre,&registre);
}


int XMouse(void)
{
	union REGS registre;
	int x;

	registre.x.ax=0x0003;
	int86(0x33,&registre,&registre);
	x=registre.x.cx;
	x=x>>3;
	x++;
	return( x );
}

int YMouse(void)
{
	union REGS registre;
	int y;

	registre.x.ax=0x0003;
	int86(0x33,&registre,&registre);
	y=registre.x.dx;
	y=y>>3;
	y++;
	return( y );
}


void HideMouse(void)
{
	union REGS registre;

	registre.x.ax=0x0002;
	int86(0x33,&registre,&registre);
}


void ShowMouse(void)
{
	union REGS registre;

	registre.x.ax=0x0001;
	int86(0x33,&registre,&registre);
}

void MoveMouse(int x,int y)
{
	union REGS registre;

	registre.x.ax=0x0004;
	registre.x.cx=x<<3;
	registre.x.dx=y<<3;
	int86(0x33,&registre,&registre);
}

void MountMouse(void)
{
	union REGS registre;

	registre.x.ax=0x0000;
	int86(0x33,&registre,&registre);
	if( registre.x.ax == 0 )
	{
		printf("Erreur, aucun driver de souris n'est install‚\n");
		printf("->ISOURIS.EXE  (Commodore)\n");
		printf("Appuyer sur une touche pour continuer...");
		getch();
		exit(0);
	}
}

void AffCar(int x,int y,int attribut,unsigned char car)
{
	char far *ptr=MK_FP(MODE,80*2*(y-1)+(x-1)*2);
	*ptr=car;
	*(ptr+1)=attribut;
}

void AffCar2(int x,int y,int attribut,unsigned char car)
{
	char far *ptr=MK_FP(MODE,80*2*(y-1)+(x-1)*2);
	if( YMouse()==y && XMouse()==x)
	{
		HideMouse();
		*ptr=car;
		*(ptr+1)=attribut;
		ShowMouse();
	}
	else
	{
		*ptr=car;
		*(ptr+1)=attribut;
	}
}

unsigned char LirCar(int x,int y)
{
	char far *ptr=MK_FP(MODE,80*2*(y-1)+(x-1)*2);
	return(*ptr);
}

unsigned char LirCar2(int x,int y)
{
	int varret;
	char far *ptr=MK_FP(MODE,80*2*(y-1)+(x-1)*2);
	if( YMouse()==y && XMouse()==x )
	{
		HideMouse();
		varret=*ptr;
		ShowMouse();
		return(varret);
	}
	else
	{
		return(*ptr);
	}
}

void print(int x,int y,int attribut,char *chaine)
{
	while(*chaine)
	{
		AffCar(x,y,attribut,*chaine);
		chaine++;
		x++;
	}
}

void print2(int x,int y,int attribut,char *chaine)
{
	while(*chaine)
	{
		AffCar2(x,y,attribut,*chaine);
		chaine++;
		x++;
	}
}

void ligne_h_s(int x1, int y1, int x2)
{
	int x;
	int y;
	for(x=x1 ; x<x2+1 ; x++)
		AffCar(x,y1,NORMAL,'Ä');
}

void ligne_h_d(int x1, int y1, int x2)
{
	int x;
	int y;
	for(x=x1 ; x<x2+1 ; x++)
		AffCar(x,y1,NORMAL,'Í');
}

void ligne_v_s(int x1, int y1, int y2)
{
	int x;
	int y;
	for(y=y1 ; y<y2+1 ; y++)
		AffCar(x1,y,NORMAL,'³');
}

void ligne_v_d(int x1, int y1, int y2)
{
	int x;
	int y;
	for(y=y1 ; y<y2+1 ; y++)
		AffCar(x1,y,NORMAL,'º');
}

void cadre_s(int x1, int y1, int x2, int y2)
{
	int x;
	int y;

	print(x1,y1,NORMAL,"Ú");
	print(x2,y1,NORMAL,"¿");
	print(x2,y2,NORMAL,"Ù");
	print(x1,y2,NORMAL,"À");

	for(x=x1+1 ; x<x2 ; x++)
	{
		print(x,y1,NORMAL,"Ä");
		print(x,y2,NORMAL,"Ä");
	}
	for(y=y1+1 ; y<y2 ; y++)
	{
		print(x1,y,NORMAL,"³");
		print(x2,y,NORMAL,"³");
	}
}

void cadre_d(int x1, int y1, int x2, int y2)
{
	int x;
	int y;

	print(x1,y1,NORMAL,"É");
	print(x2,y1,NORMAL,"»");
	print(x2,y2,NORMAL,"¼");
	print(x1,y2,NORMAL,"È");

	for(x=x1+1 ; x<x2 ; x++)
	{
		print(x,y1,NORMAL,"Í");
		print(x,y2,NORMAL,"Í");
	}

	for(y=y1+1 ; y<y2 ; y++)
	{
		print(x1,y,NORMAL,"º");
		print(x2,y,NORMAL,"º");
	}
}

void cadre_s2(int x1, int y1, int x2, int y2,int attribut)
{
	int x;
	int y;

	for( y=y1 ; y<y2 ; y++ )
		for( x=x1 ; x<x2 ; x++ )
			AffCar(x,y,attribut,' ');
	print(x1,y1,attribut,"Ú");
	print(x2,y1,attribut,"¿");
	print(x2,y2,attribut,"Ù");
	print(x1,y2,attribut,"À");

	for(x=x1+1 ; x<x2 ; x++)
	{
		print(x,y1,attribut,"Ä");
		print(x,y2,attribut,"Ä");
	}

	for(y=y1+1 ; y<y2 ; y++)
	{
		print(x1,y,attribut,"³");
		print(x2,y,attribut,"³");
	}
}

void cadre_d2(int x1, int y1, int x2, int y2,int attribut)
{
	int x;
	int y;

	for( y=y1 ; y<y2 ; y++ )
		for( x=x1 ; x<x2 ; x++ )
			AffCar(x,y,attribut,' ');
	print(x1,y1,attribut,"É");
	print(x2,y1,attribut,"»");
	print(x2,y2,attribut,"¼");
	print(x1,y2,attribut,"È");

	for(x=x1+1 ; x<x2 ; x++)
	{
		print(x,y1,attribut,"Í");
		print(x,y2,attribut,"Í");
	}

	for(y=y1+1 ; y<y2 ; y++)
	{
		print(x1,y,attribut,"º");
		print(x2,y,attribut,"º");
	}
}

