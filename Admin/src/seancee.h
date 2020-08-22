#include <gtk/gtk.h>

typedef struct
{
    char jour[10];
    char mois[10];
    char annee[10];
}date55;

typedef struct
{	char num[20];
	char cours[40];
	date55 date;
	char heure[40];
	char nplace[20];
	char nplacemax[20];
}seancee;

void afficher_seancee(GtkWidget *liste);
int ajout_part1(char num[],char id[]);
int modif_nb2(char num[]);
int inscription1(char id[],char num[]);
int modif_nb3(char num[]);
void supression_part1(char num[]);
int annulation1(char id[],char num[]);
