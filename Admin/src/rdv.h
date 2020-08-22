#include <gtk/gtk.h>

typedef struct 
{	char jour[10];
	char mois[10];
	char annee[10];
	
} Date2 ;

typedef struct 
{
	Date2 date_rdv ;
	char id1[10];
	char id2[10];
	char heure[10];
} Rdv;


void afficher_rdv(GtkWidget *liste,char ids[],char js[],char ms[],char as[]);
void addcache(char s[20]);
void getcache(char s[]);
void rmcache();
void spacex(char str[20]);
void xspace(char str[20]);
void addcachedat(char s1[],char s2[],char s3[]);
void getcachedat(char s1[],char s2[],char s3[]);
void rmcachedat();
void addrdv(char s[]);
int verifrdv(char s1[],char s3[],char s4[],char s5[],char s6[]);
int verifid(char s1[]);
int supprimer_rdv(char s1[],char s3[],char s4[],char s5[],char s6[]);
void chercrdv(char s1[],char s3[],char s4[],char s5[],char s6[],char ide[]);
void modifrdv(char s1[],char s3[],char s4[],char s5[],char s6[],char nv2[],char nv3[],char nv4[],char nv5[],char nv6[]);

