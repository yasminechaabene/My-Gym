#include <gtk/gtk.h>

typedef struct
	{
	 int jour;
	 int mois;
	 int annee;
	}Date;

typedef struct
	{
	 char id[20];
	 char nom[20];
	 char prenom[30];
	 char role[30];
	 Date date;
	}Personne;

typedef struct
{
    char jour[6];
    char mois[6];
    char annee[6];
}age;

typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    age datenaiss;
    char sexe[20];
    char ville[20];
    char numtel[20];
    char ligne[20];
}compte;

typedef struct
{
    char id[10];
    char nom[20];
    char prenom[20];
    age datenaiss;
    char sexe[20];
    char ville[20];
    char numtel[20];
    char ligne[20];
}compte1;

typedef struct
{
    char id[6];
    char mdp[6];
    char role[6];
}user;

void dis_acc(char id[]);
Personne get_personne(char ide[]);

compte get_compte(int ide);
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
int exist(char user[]);
