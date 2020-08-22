typedef struct
{	
	char jour[10];
	char mois[10];
	char annee[10];
}Dates;

typedef struct
{	
	char num[10];
	char type[50];
	char periode[50];
	char nbp[10];
	Dates date_seance;
}Seance;

void ajouter_seance(Seance s);
void afficher_seance(GtkWidget *liste);
void intstring(int x,char su[]);
void modifier_seance(char n[],char nvtype[],char nvjour[],char nvmois[],char nvannee[],char nvperiode[],char nvnbp[]);
void supprimer_seance(char n[]);

