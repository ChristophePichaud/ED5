#include <stdio.h>
#include <dos.h>
#include <dir.h>
#include "util.h"

	struct
	{
		char serv[80];
		char resp[80];
		char activ[3][80];		/* 3 activit‚s maxi */
	} mairie[80];
	int im=0;
	int c;
	int i;
	int j;
	int nbasuppr;
	char ecran[80*25*2];
	char ch[80];
	int nbcar=50;
	int lg;
	FILE *fichier;
	char nomfichier[80];
	char nomfichierprov[80];
	int nb;

void requester_erreur_utilisateur(char *message);
void requester_confirm_supprder_utilisateur(void);
void requester_confirm_supprno_utilisateur(void);
void AffServices(void);
void AffNomFichier(char *nom);
void main(int nbargs,char *nomarg[])
{
	cls();
	MountMouse();
	ShowMouse();
	HideMouse();

	if( nbargs!=3 )
	{
		cls();
		printf("Usage: defserv2.exe <file.dat> <file.txt>\n");
		printf("file.dat: fichier de donn‚es\n");
		printf("file.txt: fichier … g‚n‚rer\n");
		exit(0);
	}
	cadre_s2(62,1,75,18,NORMAL);
	print(68,1,NORMAL," Menu ");
	print(64,3,INVERSE, " NOUVEAU  ");
	print(64,5,INVERSE, " CHARGER  ");
	print(64,7,INVERSE, " SAUVER   ");
	print(64,9,INVERSE, " AJOU SERV");
	print(64,11,INVERSE," SUPPR SER");
	print(64,13,INVERSE," SUPPR NøS");
	print(64,15,INVERSE," GENERER  ");
	print(64,17,INVERSE," QUITTER  ");
	cadre_s2(1,1,61,24,NORMAL);
	print(2,1,NORMAL,"[þ]");
	print(6,1,NORMAL," Services ");
	strcpy(nomfichier,"Sans_Nom.dat");
	AffNomFichier(nomfichier);
	if( nbargs==3 )
	{
		gettext(1,1,80,25,ecran);
		fichier=fopen(nomarg[1],"r");
		fseek(fichier,0,SEEK_END);
		lg=ftell(fichier);
		fseek(fichier,0,SEEK_SET);
		if( fichier==NULL )
		{
			requester_erreur_utilisateur("Lecture impossible");
			fclose(fichier);
			HideMouse();
			puttext(1,1,80,25,ecran);
			goto finn3;
		}
		im=0;
		while( lg>ftell(fichier) )
		{
			fgets(mairie[im].serv,80,fichier);
			fgets(mairie[im].resp,80,fichier);
			fgets(mairie[im].activ[0],80,fichier);
			fgets(mairie[im].activ[1],80,fichier);
			fgets(mairie[im].activ[2],80,fichier);
			im++;
		}
		fclose(fichier);
		/* oter les \n */
		for( i=0 ; i<im ; i++ )
		{
			if( strlen(mairie[i].serv) )
				mairie[i].serv[ strlen(mairie[i].serv) -1]=0;
			if( strlen(mairie[i].resp) )
				mairie[i].resp[ strlen(mairie[i].resp) -1]=0;
			if( strlen(mairie[i].activ[0]) )
				mairie[i].activ[0][ strlen(mairie[i].activ[0]) -1]=0;
			if( strlen(mairie[i].activ[1]) )
				mairie[i].activ[1][ strlen(mairie[i].activ[1]) -1]=0;
			if( strlen(mairie[i].activ[2]) )
				mairie[i].activ[2][ strlen(mairie[i].activ[2]) -1]=0;
		}
		puttext(1,1,80,25,ecran);
		AffServices();
		strcpy(nomfichier,nomarg[1]);
		AffNomFichier(nomfichier);
	finn3: ;
	}
	ShowMouse();
	do
	{
		fflush(stdin);
		if( LeftMouseButton()
		    && XMouse()==3
		    && YMouse()==1 )
		{
			while( LeftMouseButton() );
			goto quitter;
		}

		/* NOUVEAU */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==3
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			requester_s(5,12,30,18,"Effacer tout ");
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
					im=0;
					HideMouse();
					puttext(1,1,80,25,ecran);
					strcpy(nomfichier,"Sans_Nom.dat");
					AffNomFichier(nomfichier);
					AffServices();
					break;
				}
				if( BetweenOrEqual(XMouse(),20,20+7)
					&& YMouse()==17
					&& LeftMouseButton() )
				{
					while( LeftMouseButton() );
					HideMouse();
					puttext(1,1,80,25,ecran);
					break;
				}
			}while( 1 );
			ShowMouse();
		}
		/* CHARGER */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==5
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			cadre_s2(1,23,nbcar+4,25,NORMAL);
			print(5,23,NORMAL," Nom du Fichier ");
			getstring2(3,24,INVERSE,nomfichierprov,nbcar);
			fichier=fopen(nomfichierprov,"r");
			fseek(fichier,0,SEEK_END);
			lg=ftell(fichier);
			fseek(fichier,0,SEEK_SET);
			if( fichier==NULL )
			{
				requester_erreur_utilisateur("Lecture impossible");
				fclose(fichier);
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			im=0;
			while( lg>ftell(fichier) )
			{
				fgets(mairie[im].serv,80,fichier);
				fgets(mairie[im].resp,80,fichier);
				fgets(mairie[im].activ[0],80,fichier);
				fgets(mairie[im].activ[1],80,fichier);
				fgets(mairie[im].activ[2],80,fichier);
				im++;
			}
			fclose(fichier);
			/* oter les \n */
			for( i=0 ; i<im ; i++ )
			{
				if( strlen(mairie[i].serv) )
					mairie[i].serv[ strlen(mairie[i].serv) -1]=0;
				if( strlen(mairie[i].resp) )
					mairie[i].resp[ strlen(mairie[i].resp) -1]=0;
				if( strlen(mairie[i].activ[0]) )
					mairie[i].activ[0][ strlen(mairie[i].activ[0]) -1]=0;
				if( strlen(mairie[i].activ[1]) )
					mairie[i].activ[1][ strlen(mairie[i].activ[1]) -1]=0;
				if( strlen(mairie[i].activ[2]) )
					mairie[i].activ[2][ strlen(mairie[i].activ[2]) -1]=0;
			}
			puttext(1,1,80,25,ecran);
			AffServices();
			strcpy(nomfichier,nomfichierprov);
			AffNomFichier(nomfichier);
			ShowMouse();
		}
		/* SAUVER */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==7
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			cadre_s2(1,23,nbcar+4,25,NORMAL);
			print(5,23,NORMAL," Nom du Fichier ");
			getstring2(3,24,INVERSE,nomfichierprov,nbcar);
			fichier=fopen(nomfichierprov,"w");
			if( fichier==NULL )
			{
				requester_erreur_utilisateur("Ecriture impossible");
				fclose(fichier);
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			for( i=0 ; i<im ; i++ )
			{
				fprintf(fichier,"%s\n",mairie[i].serv);
				fprintf(fichier,"%s\n",mairie[i].resp);
				fprintf(fichier,"%s\n",mairie[i].activ[0]);
				fprintf(fichier,"%s\n",mairie[i].activ[1]);
				fprintf(fichier,"%s\n",mairie[i].activ[2]);
			}
			fclose(fichier);
			puttext(1,1,80,25,ecran);
			AffServices();
			strcpy(nomfichier,nomfichierprov);
			AffNomFichier(nomfichier);
			ShowMouse();
		}
		/* AJOU SERV */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==9
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			if( im>19 )
			{
				requester_erreur_utilisateur("Trop de services !!!");
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			cadre_s2(5,5,nbcar+25,20,NORMAL);
			print(6,5,NORMAL,"[þ]");
			print(20,5,INVERSE," Nouveau service ");
			print(7,7,NORMAL,"Service :");
			print(21,7,NORMAL,"INCONNU");
			print(7,9,NORMAL,"Responsable :");
			print(21,9,NORMAL,"INCONNU");
			print(7,11,NORMAL,"Activit‚s  :");
			print(21,11,NORMAL,"INCONNU");
			print(21,12,NORMAL,"INCONNU");
			print(21,13,NORMAL,"INCONNU");
			ShowMouse();
			strcpy(mairie[im].serv,"INCONNU");
			strcpy(mairie[im].resp,"INCONNU");
			strcpy(mairie[im].activ[0],"INCONNU");
			strcpy(mairie[im].activ[1],"INCONNU");
			strcpy(mairie[im].activ[2],"INCONNU");
			HideMouse();
			getstring2(21,7,INVERSE,mairie[im].serv,nbcar);
			Affxfois(21,7,NORMAL,' ',nbcar+1);
			print(21,7,NORMAL,mairie[im].serv);
			getstring2(21,9,INVERSE,mairie[im].resp,nbcar);
			Affxfois(21,9,NORMAL,' ',nbcar+1);
			print(21,9,NORMAL,mairie[im].resp);
			getstring2(21,11,INVERSE,mairie[im].activ[0],nbcar);
			Affxfois(21,11,NORMAL,' ',nbcar+1);
			print(21,11,NORMAL,mairie[im].activ[0]);
			getstring2(21,12,INVERSE,mairie[im].activ[1],nbcar);
			Affxfois(21,12,NORMAL,' ',nbcar+1);
			print(21,12,NORMAL,mairie[im].activ[1]);
			getstring2(21,13,INVERSE,mairie[im].activ[2],nbcar);
			Affxfois(21,13,NORMAL,' ',nbcar+1);
			print(21,13,NORMAL,mairie[im].activ[2]);
			ShowMouse();
			do
			{
				if( LeftMouseButton()
				    && XMouse()==7
				    && YMouse()==5 )
				{
					while( LeftMouseButton() );
					break;
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==7 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,7,INVERSE,mairie[im].serv,nbcar);
					Affxfois(21,7,NORMAL,' ',nbcar+1);
					print(21,7,NORMAL,mairie[im].serv);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==9 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,9,INVERSE,mairie[im].resp,nbcar);
					Affxfois(21,9,NORMAL,' ',nbcar+1);
					print(21,9,NORMAL,mairie[im].resp);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==11 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,11,INVERSE,mairie[im].activ[0],nbcar);
					Affxfois(21,11,NORMAL,' ',nbcar+1);
					print(21,11,NORMAL,mairie[im].activ[0]);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==12 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,12,INVERSE,mairie[im].activ[1],nbcar);
					Affxfois(21,12,NORMAL,' ',nbcar+1);
					print(21,12,NORMAL,mairie[im].activ[1]);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==13 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,13,INVERSE,mairie[im].activ[2],nbcar);
					Affxfois(21,13,NORMAL,' ',nbcar+1);
					print(21,13,NORMAL,mairie[im].activ[2]);
					ShowMouse();
				}
			}while(1);
			HideMouse();
			puttext(1,1,80,25,ecran);
			im++;
			if( im>79 )
				im=79;
			AffServices();
			ShowMouse();
		}

		/* SUPPR SERV */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==11
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			if( im==0 )
			{
				requester_erreur_utilisateur("Aucun service !!!");
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			requester_confirm_supprder_utilisateur();
			HideMouse();
			puttext(1,1,80,25,ecran);
			AffServices();
			ShowMouse();
		}

		/* SUPPR NøS */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==13
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			gettext(1,1,80,25,ecran);
			if( im==0 )
			{
				requester_erreur_utilisateur("Aucun service !!!");
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			requester_s(5,12,30,18,"Nø … supprimer ?");
			print(11,15,NORMAL,"Nø ? ");
			getstring2(15,15,INVERSE,ch,1);
			nbasuppr=atoi(ch);
			/*
			gotoxy(16,15);
			scanf("%d",&nbasuppr);
			*/
			if( !(nbasuppr>=0 && nbasuppr<=im-1) )
			{
				sprintf(ch,"Nombre de services :%02d",im);
				requester_erreur_utilisateur(ch);
				HideMouse();
				puttext(1,1,80,25,ecran);
				ShowMouse();
				continue;
			}
			requester_confirm_supprno_utilisateur();
			HideMouse();
			puttext(1,1,80,25,ecran);
			AffServices();
			ShowMouse();
		}

		/* GENERER */
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==15
		    && LeftMouseButton() )
		{
			while( LeftMouseButton() );
			HideMouse();
			fichier=fopen(nomarg[2],"w");
			for( i=0 ; i<im ; i++ )
			{
				fprintf(fichier,"Service: %s\n",mairie[i].serv);
				fprintf(fichier,"Responsable : %s\n",mairie[i].resp);
				fprintf(fichier,"Activit‚s   : _%s\n",mairie[i].activ[0]);
				fprintf(fichier,"              _%s\n",mairie[i].activ[1]);
				fprintf(fichier,"              _%s\n",mairie[i].activ[2]);
				fprintf(fichier,"\n");
			}
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
		if( BetweenOrEqual(XMouse(),64,73)
		    && YMouse()==17
		    && LeftMouseButton() )
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
		    && BetweenOrEqual(XMouse(),4,59)
		    && BetweenOrEqual(YMouse(),3,22) )
		{
			nb=YMouse()-3;
			while( LeftMouseButton() );
			if( nb>=im )
				continue;
			HideMouse();
			gettext(1,1,80,25,ecran);
			cadre_s2(5,5,nbcar+25,20,NORMAL);
			print(6,5,NORMAL,"[þ]");
			sprintf(ch," Modification service nø%02d ",nb);
			print(20,5,INVERSE,ch);
			print(7,7,NORMAL,"Service :");
			print(21,7,NORMAL,mairie[nb].serv);
			print(7,9,NORMAL,"Responsable :");
			print(21,9,NORMAL,mairie[nb].resp);
			print(7,11,NORMAL,"Activit‚s  :");
			print(21,11,NORMAL,mairie[nb].activ[0]);
			print(21,12,NORMAL,mairie[nb].activ[1]);
			print(21,13,NORMAL,mairie[nb].activ[2]);
			ShowMouse();
			do
			{
				if( LeftMouseButton()
				    && XMouse()==7
				    && YMouse()==5 )
				{
					while( LeftMouseButton() );
					break;
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==7 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,7,INVERSE,mairie[nb].serv,nbcar);
					Affxfois(21,7,NORMAL,' ',nbcar+1);
					print(21,7,NORMAL,mairie[nb].serv);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==9 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,9,INVERSE,mairie[nb].resp,nbcar);
					Affxfois(21,9,NORMAL,' ',nbcar+1);
					print(21,9,NORMAL,mairie[nb].resp);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==11 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,11,INVERSE,mairie[nb].activ[0],nbcar);
					Affxfois(21,11,NORMAL,' ',nbcar+1);
					print(21,11,NORMAL,mairie[nb].activ[0]);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==12 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,12,INVERSE,mairie[nb].activ[1],nbcar);
					Affxfois(21,12,NORMAL,' ',nbcar+1);
					print(21,12,NORMAL,mairie[nb].activ[1]);
					ShowMouse();
				}
				if( LeftMouseButton()
				    && BetweenOrEqual(XMouse(),21,70 )
				    && YMouse()==13 )
				{
					while( !(LeftMouseButton()) );
					HideMouse();
					getstring2(21,13,INVERSE,mairie[nb].activ[2],nbcar);
					Affxfois(21,13,NORMAL,' ',nbcar+1);
					print(21,13,NORMAL,mairie[nb].activ[2]);
					ShowMouse();
				}
			}while(1);
			HideMouse();
			puttext(1,1,80,25,ecran);
			AffServices();
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

void AffNomFichier(char *nom)
{
	HideMouse();
	Affxfois(20,1,INVERSE,' ',40);
	print(20,1,INVERSE,nom);
	ShowMouse();
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

void requester_confirm_supprder_utilisateur(void)
{
	requester_s(5,12,30,18,"Supprimer le dernier");
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
			strcpy(&mairie[im].serv,0);
			strcpy(&mairie[im].resp,0);
			im--;
			if( im<0 )
				im=0;
				break;
		}
		if( BetweenOrEqual(XMouse(),20,20+7)
			&& YMouse()==17
			&& LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}
	}while( 1 );
}
void requester_confirm_supprno_utilisateur(void)
{
	sprintf(ch,"Supprimer le nø%02d",nbasuppr);
	requester_s(5,12,30,18,ch);
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
			for( i=nbasuppr ; i<im-1 ; i++ )
				mairie[i]=mairie[i+1];
			im--;
			if( im<0 )
				im=0;
			break;
		}
		if( BetweenOrEqual(XMouse(),20,20+7)
			&& YMouse()==17
			&& LeftMouseButton() )
		{
			while( LeftMouseButton() );
			break;
		}
	}while( 1 );
}

void AffServices(void)
{
	for( j=3 ; j<23 ; j++ )
		for( i=3 ; i<60 ; i++ )
			AffCar(i,j,NORMAL,' ');
	for( i=0 ; i<im ; i++ )
	{
		sprintf(ch,"%02d : %s",i,mairie[i].serv);
		print(4,3+i,NORMAL,ch);
	}
}




