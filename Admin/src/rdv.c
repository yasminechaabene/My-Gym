#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "rdv.h"



enum 
{ ID1,
  ID2,
  JOUR,
  MOIS,
  ANNEE,
  HEURE,
  COLUMNS
};

void afficher_rdv(GtkWidget *liste,char ids[],char js[],char ms[],char as[])	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char id1[10];
	char id2[20];
	char jour[20];
	char mois[10];
	char annee[10];
	char heure[10];
	
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ID médecin", renderer, "text",ID1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ID adhérant", renderer, "text",ID2, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Année", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("rdv.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("rdv.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s\n", id1,id2,jour,mois,annee,heure)!=EOF)
			  {if ((strcmp(jour,js)==0)&&(strcmp(mois,ms)==0)&&(strcmp(annee,as)==0)&&strcmp(id1,ids)==0)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID1,id1,ID2,id2,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure ,-1); 
		}}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void addcache(char s[20])
{
    FILE *f;
    f = fopen("cache.txt", "a+");
	if(f==NULL)
	{

		return;
	}		
	else 
    { 
        fprintf(f,"%s" ,s);
    }
    fclose(f);
}
void getcache(char s[])
{
    {
    FILE *f;
    f = fopen("cache.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    { 
        fscanf(f,"%s",s);
    }
    fclose(f);
}
}

void rmcache()
{
    FILE *fptr1, *fptr2;
    char temp[] = "temp.txt";
    fptr1 = fopen("cache.txt", "r");
    fptr2 = fopen(temp, "w");
    fclose(fptr1);
    fclose(fptr2);
    remove("cache.text");
    rename(temp, "cache.txt");
}

void spacex(char str[20])
{
   int i=0;
   while (str[i])
  {
    if (isspace(str[i]))
        str[i]='_';
    i++;
  }
}

void xspace(char str[20])
{
   int i=0;
   while (str[i])
  {
    if ((str[i])=='_')
        str[i]=' ';
    i++;
  }
}

void addcachedat(char s1[],char s2[],char s3[])
{
    FILE *f;
    f = fopen("cachedat.txt", "a+");
	if(f==NULL)
	{

		return;
	}		
	else 
    { 
        fprintf(f,"%s %s %s" ,s1,s2,s3);
    }
    fclose(f);
}

void getcachedat(char s1[],char s2[],char s3[])
{
    {
    FILE *f;
    f = fopen("cachedat.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    { 
        fscanf(f,"%s %s %s",s1,s2,s3);
    }
    fclose(f);
}
}

void rmcachedat()
{
    FILE *fptr1, *fptr2;
    char temp[] = "temp.txt";
    fptr1 = fopen("cachedat.txt", "r");
    fptr2 = fopen(temp, "w");
    fclose(fptr1);
    fclose(fptr2);
    remove("cachedat.text");
    rename(temp, "cachedat.txt");
}

void addrdv(char s[])
{
    FILE *f;
    f = fopen("rdv.txt", "a+");
	if(f==NULL)
	{

		return;
	}		
	else 
    { 
        fprintf(f,"%s\n" ,s);
    }
    fclose(f);
}

int verifrdv(char s1[],char s3[],char s4[],char s5[],char s6[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	char st5[20];char st6[20];
	FILE *f;
    f = fopen("rdv.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
        {
		if ((strcmp(s1,st1)==0)&&(strcmp(s3,st3)==0)&&(strcmp(s4,st4)==0)&&(strcmp(s5,st5)==0)&&(strcmp(s6,st6)==0))
		{
			return(1);
		}
		}
		return(0);
    }
    fclose(f);
}

int verifid(char s1[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	char st5[20];char st6[20];
    char st7[20];
	FILE *f;
    f = fopen("fiches.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6,st7)!=EOF)
        {
		if ((strcmp(s1,st1)==0))
		{
			return(1);
		}
		}
		return(0);
    }
    fclose(f);
}

int supprimer_rdv(char s1[],char s3[],char s4[],char s5[],char s6[])
{
  FILE*f,*f1;
  int i,j;
  f=fopen("rdv.txt","r+");
  f1=fopen("rdv1.txt","w+");
  char st1[20];char st2[20];
  char st3[20];char st4[20];
  char st5[20];char st6[20];
  char st7[20];

  i=0;
  j=0;
  
  if(f !=NULL) 
  { 
     while(fscanf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
    {
	 i++;
     if ((strcmp(s1,st1)!=0)&&(strcmp(s3,st3)!=0)||(strcmp(s4,st4)!=0)||(strcmp(s5,st5)!=0)||(strcmp(s6,st6)!=0))	 
    	{fprintf(f1,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6);
		j++;}

    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("rdv.txt","w+");
  f1=fopen("rdv1.txt","r+");
 while (fscanf(f1,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
	fprintf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6);

  fclose(f1);
  fclose(f);
  remove("rdv1.txt");

  if (i==j)
  {
	  return (1);
  }
  else
	return (0);
}


void chercrdv(char s1[],char s3[],char s4[],char s5[],char s6[],char ide[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	char st5[20];char st6[20];
	FILE *f;
    f = fopen("rdv.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
        {
		if ((strcmp(s1,st1)==0)&&(strcmp(s3,st3)==0)&&(strcmp(s4,st4)==0)&&(strcmp(s5,st5)==0)&&(strcmp(s6,st6)==0))
		{
			strcpy(ide,st2);
		}
		}
    }
    fclose(f);
}

void modifrdv(char s1[],char s3[],char s4[],char s5[],char s6[],char nv2[],char nv3[],char nv4[],char nv5[],char nv6[])
{
  FILE*f,*f1;
  char ide[20];
  char st1[20];char st2[20];
  char st3[20];char st4[20];
  char st5[20];char st6[20];
  chercrdv(s1,s3,s4,s5,s6,ide);
  
  f=fopen("rdv.txt","r+");
  f1=fopen("rdv1.txt","w+");
  
  if(f !=NULL) 
  { 
    while(fscanf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
    {
     if ((strcmp(s1,st1)==0)&&(strcmp(s3,st3)==0)&&(strcmp(s4,st4)==0)&&(strcmp(s5,st5)==0)&&(strcmp(s6,st6)==0))	 
	{
	fprintf(f1,"%s %s %s %s %s %s\n",st1,nv2,nv3,nv4,nv5,nv6);
	}
     else 
     	fprintf(f1,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6);
    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("rdv.txt","w+");
  f1=fopen("rdv1.txt","r+");
    while(fscanf(f1,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6)!=EOF)
	fprintf(f,"%s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6);


  fclose(f1);
  fclose(f);
  remove("rdv1.txt"); 

}
