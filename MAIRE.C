#include <stdio.h>
#include <dos.h>
#include <dir.h>
#include "util.h"

	char Ville[80];
	char Dept[80];
	char Nom[80];
	char Prenom[80];
	char DateExp[80];
	int c;
	int i;
	int j;
	char ecran[80*25*2];
	char ch[80];
	int nbcar=50;
	int lg;
	FILE *fichier;
	char nomfichier[80];
	int n=35;

void requester_erreur_utilisateur(char *message);
void AffNomFichier(char *nom);
void main(int nbargs, char *nomarg[])
{
	cls();
	MountMouse();
	ShowMouse();
	HideMouse();
	if( nbargs!=3 )
	{
		cls();
		printf("Usage: maire.exe <file.dat> <file.txt>\n");
		printf("file.dat: fichier de donn‚es\n");
		printf("file.txt: fichier … g‚n‚rer\n");
		exit(0);
	}
	cadre_s2(62,1,75,12,NORMAL);
	print(65,1,NORMAL," Menu ");
	print(64,3,INVERSE, " NOUVEAU  ");
	print(64,5,INVERSE, " CHARGER  ");
	print(64,7,INVERSE, " SAUVER   ");
	print(64,9,INVERSE," GENERER  ");
	print(64,11,INVERSE," QUITTER  ");
	cadre_s2(1,1,61,20,NORMAL);
	print(5,1,NORMAL,"[þ]");
	print(20,1,INVERSE," Maire ");
	print(7,7,NORMAL,"Ville :");
	print(21,7,NORMAL,"INCONNU");
	print(7,9,NORMAL,"Departement :");
	print(21,9,NORMAL,"INCONNU");
	print(7,11,NORMAL,"Nom :");
	print(21,11,NORMAL,"INCONNU");
	print(7,13,NORMAL,"Pr‚nom :");
	print(21,13,NORMAL,"INCONNU");
	print(7,15,NORMAL,"Date Exp :");
	print(21,15,NORMAL,"INCONNU");
	if( nbargs==3 )
	{
		fichier=fopen(nomarg[1],"r");
		if( fichier==NULL )
		{
			gettext(1,1,80,25,ecran);
			requester_erreur_utilisateur("Lecture impossible !");
			fclose(fichier);
			HideMouse();
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}
		else
		{
			fgets(Ville,80,fichier);
			fgets(Dept,80,fichier);
			fgets(Nom,80,fichier);
			fgets(Prenom,80,fichier);
			fgets(DateExp,80,fichier);
			if( strlen(Ville) )
				Ville[ strlen(Ville) -1]=0;
			if( strlen(Dept) )
				Dept[ strlen(Dept) -1]=0;
			if( strlen(Nom) )
				Nom[ strlen(Nom) -1]=0;
			if( strlen(Prenom) )
				Prenom[ strlen(Prenom) -1]=0;
			if( strlen(DateExp) )
				DateExp[ strlen(DateExp) -1]=0;
			LineX(21,7,n+1,NORMAL,' ');
			LineX(21,9,n+1,NORMAL,' ');
			LineX(21,11,n+1,NORMAL,' ');
			LineX(21,13,n+1,NORMAL,' ');
			LineX(21,15,n+1,NORMAL,' ');
			print(21,7,NORMAL,Ville);
			print(21,9,NORMAL,Dept);
			print(21,11,NORMAL,Nom);
			print(21,13,NORMAL,Prenom);
			print(21,15,NORMAL,DateExp);
		}
		fclose(fichier);
	}
	ShowMouse();
	do
	{
		fflush(stdin);
		/* CLICK [þ] */
		if( LeftMouseButton()
		    && XMouse()==6
		    && YMouse()==1 )
		{
			while( LeftMouseButton() );
			goto quitter;
		}

		/* NOUVEAU */
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==3 )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			LineX(21,7,n+1,NORMAL,' ');
			LineX(21,9,n+1,NORMAL,' ');
			LineX(21,11,n+1,NORMAL,' ');
			LineX(21,13,n+1,NORMAL,' ');
			LineX(21,15,n+1,NORMAL,' ');
			print(7,7,NORMAL,"Ville :");
			print(21,7,NORMAL,Ville);
			print(7,9,NORMAL,"Departement :");
			print(21,9,NORMAL,Dept);
			print(7,11,NORMAL,"Nom :");
			print(21,11,NORMAL,Nom);
			print(7,13,NORMAL,"Pr‚nom :");
			print(21,13,NORMAL,Prenom);
			print(7,15,NORMAL,"Date Exp :");
			print(21,15,NORMAL,DateExp);
			ShowMouse();
			HideMouse();
			getstring2(21,7,INVERSE,Ville,n);
			Affxfois(21,7,NORMAL,' ',n+1);
			print(21,7,NORMAL,Ville);
			getstring2(21,9,INVERSE,Dept,n);
			Affxfois(21,9,NORMAL,' ',n+1);
			print(21,9,NORMAL,Dept);
			getstring2(21,11,INVERSE,Nom,n);
			Affxfois(21,11,NORMAL,' ',n+1);
			print(21,11,NORMAL,Nom);
			getstring2(21,13,INVERSE,Prenom,n);
			Affxfois(21,13,NORMAL,' ',n+1);
			print(21,13,NORMAL,Prenom);
			getstring2(21,15,INVERSE,DateExp,n);
			Affxfois(21,15,NORMAL,' ',n+1);
			print(21,15,NORMAL,DateExp);
			ShowMouse();
		}

		/* CHARGER */
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==5 )
		{
			while( LeftMouseButton() );
			fichier=fopen(nomarg[1],"r");
			if( fichier==NULL )
			{
				gettext(1,1,80,25,ecran);
				requester_erreur_utilisateur("Lecture impossible");
				HideMouse();
				puttext(1,1,80,25,ecran);
				fclose(fichier);
				ShowMouse();
				continue;
			}
			fgets(Ville,80,fichier);
			fgets(Dept,80,fichier);
			fgets(Nom,80,fichier);
			fgets(Prenom,80,fichier);
			fgets(DateExp,80,fichier);
			if( strlen(Ville) )
				Ville[ strlen(Ville) -1]=0;
			if( strlen(Dept) )
				Dept[ strlen(Dept) -1]=0;
			if( strlen(Nom) )
				Nom[ strlen(Nom) -1]=0;
			if( strlen(Prenom) )
				Prenom[ strlen(Prenom) -1]=0;
			if( strlen(DateExp) )
				DateExp[ strlen(DateExp) -1]=0;
			LineX(21,7,n+1,NORMAL,' ');
			LineX(21,9,n+1,NORMAL,' ');
			LineX(21,11,n+1,NORMAL,' ');
			LineX(21,13,n+1,NORMAL,' ');
			LineX(21,15,n+1,NORMAL,' ');
			print(21,7,NORMAL,Ville);
			print(21,9,NORMAL,Dept);
			print(21,11,NORMAL,Nom);
			print(21,13,NORMAL,Prenom);
			print(21,15,NORMAL,DateExp);
		}

		/* SAUVER */
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==7 )
		{
			while( LeftMouseButton() );
			fichier=fopen(nomarg[1],"w");
			if( fichier==NULL )
			{
				gettext(1,1,80,25,ecran);
				requester_erreur_utilisateur("Ecriture impossible");
				HideMouse();
				puttext(1,1,80,25,ecran);
				fclose(fichier);
				ShowMouse();
				continue;
			}
			fprintf(fichier,"%s\n",Ville);
			fprintf(fichier,"%s\n",Dept);
			fprintf(fichier,"%s\n",Nom);
			fprintf(fichier,"%s\n",Prenom);
			fprintf(fichier,"%s\n",DateExp);
			fclose(fichier);
		}

		/* GENERER */
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==9 )
		{
			while( LeftMouseButton() );
			HideMouse();
			fichier=fopen(nomarg[2],"w");
			fprintf(fichier,"Ville de        : %s\n",Ville);
			fprintf(fichier,"D‚partement     : %s\n",Dept);
			fprintf(fichier,"Nom du Maire    : %s\n",Nom);
			fprintf(fichier,"Prenom du Maire : %s\n",Prenom);
			fprintf(fichier,"Fin de mandat   : %s\n",DateExp);
			fclose(fichier);
			gettext(1,1,80,25,ecran);
			cadre_d2(5,5,50,10,NORMAL);
			print(10,7,NORMAL,"G‚n‚ration termin‚e");
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
			puttext(1,1,80,25,ecran);
			ShowMouse();
		}

		/* QUITTER */
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==11 )
		{
			while( LeftMouseButton() );
		quitter:
			HideMouse();
			gettext(1,1,80,25,ecran);
			requester_s(5,12,30,18,"QUITTER");
			print(11,15,NORMAL,"Confirmation ?");
			print(10,17,INVERSE," OK ");
			print(20,17,INVERSE," Annuler ");
			ShowMouse();
			do
			{
				if( BetweenOrEqual(XMouse(),10,10+3)
					&& YMouse()==17
					&& LeftMouseButton() )
				{
					while( LeftMouseButton() );
					if( BetweenOrEqual(XMouse(),10,10+3)
						&& YMouse()==17 )
					{
						HideMouse();
						puttext(1,1,80,25,ecran);
						cls();
						exit(0);
					}
				}
				if( BetweenOrEqual(XMouse(),20,20+7)
					&& YMouse()==17
					&& LeftMouseButton() )
				{
					while( LeftMouseButton() );
					HideMouse();
					puttext(1,1,80,25,ecran);
					ShowMouse();
					break;
				}
			}while( 1 );
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),21,60 )
		    && YMouse()==7 )
		{
			while( !(LeftMouseButton()) );
			HideMouse();
			getstring2(21,7,INVERSE,Ville,n);
			Affxfois(21,7,NORMAL,' ',n+1);
			print(21,7,NORMAL,Ville);
			ShowMouse();
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),21,60 )
		    && YMouse()==9 )
		{
			while( !(LeftMouseButton()) );
			HideMouse();
			getstring2(21,9,INVERSE,Dept,n);
			Affxfois(21,9,NORMAL,' ',n+1);
			print(21,9,NORMAL,Dept);
			ShowMouse();
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),21,60 )
		    && YMouse()==11 )
		{
			while( !(LeftMouseButton()) );
			HideMouse();
			getstring2(21,11,INVERSE,Nom,n);
			Affxfois(21,11,NORMAL,' ',n+1);
			print(21,11,NORMAL,Nom);
			ShowMouse();
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),21,60 )
		    && YMouse()==13 )
		{
			while( !(LeftMouseButton()) );
			HideMouse();
			getstring2(21,13,INVERSE,Prenom,n);
			Affxfois(21,13,NORMAL,' ',n+1);
			print(21,13,NORMAL,Prenom);
			ShowMouse();
		}
		if( LeftMouseButton()
		    && BetweenOrEqual(XMouse(),21,60 )
		    && YMouse()==15 )
		{
			while( !(LeftMouseButton()) );
			HideMouse();
			getstring2(21,15,INVERSE,DateExp,n);
			Affxfois(21,15,NORMAL,' ',n+1);
			print(21,15,NORMAL,DateExp);
			ShowMouse();
		}
		if( kbhit() )
		{
			c=bioskey(0);
			if( c==_ESC )
				goto quitter;
		}
	}while( 1 );
}

void requester_erreur_utilisateur(char *message)
{
	requester_d(5,12,30,18,"ERREUR UTILISATEUR");
	print(7,15,NORMAL,message);
	print(17,17,INVERSE," OK ");
	ShowMouse();
	do
	{
		if( BetweenOrEqual(XMouse(),17,17+3)
			&& YMouse()==17
			&& LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}
	}while( 1 );
}

