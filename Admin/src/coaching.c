#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coaching.h" 

// fonction supprimer :desactiver un compte
void aminesupprimer(char ide[])
{
 Personnet p;
 FILE *f;
 FILE *f2;
 FILE *f3;
 FILE *f4;
        char jour[20];
        char mois[20];
        char annee[20];
	char date[20];
	char Heure[20];
        char Nombredeplace[20];
        char Cours[20];
        char Id[20];
        char Nombredeplacemax[20];


 f=fopen("seancee.txt","r");
    if(f==NULL)
    	{
	 return;
	}
    else
	{
         while(fscanf(f,"%s %s %s %s %s %s %s %s \n",Id,Cours,jour,mois,annee,Heure,Nombredeplace,Nombredeplacemax)!=EOF)
		{
		 if(strcmp(Id,ide)!=0)
			{
			 f2=fopen("test1.txt", "a");
			 if (f2==NULL)
				{
			 	 return;
				}
		 	 else	
				{
				 fprintf(f2,"%s %s %s %s %s %s %s %s \n" ,Id,Cours,jour,mois,annee,Heure,Nombredeplace,Nombredeplacemax);
				 fclose(f2);
				}
			}//sprintf(ch,"%d",n)
		/* else
			{
		 	 f2=fopen("test1.txt", "a");
			 if(f2!=NULL)
				{
				 char dis[30]="-";
				 strcat(dis,Id);
				 fprintf(f2,"%s %s %s %s %s %s %s %s \n" ,dis,Cours,jour,mois,annee,Heure,Nombredeplace,Nombredeplacemax);
				 fclose(f2);
				}
			}*/
	    	}
	}
 fclose(f);
 remove("seancee.txt");
 rename("test1.txt","seancee.txt");

}
      // get personne
Personnet chercheramine(char ide[])
{ 
    Personnet p ;
    FILE *f;
    
    
    f=fopen("seancee.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %d ",&p.Id,&p.Cours,
        &p.date.jour,&p.date.mois,&p.date.annee,&p.Heure,&p.Nombredeplace,&p.Nombredeplacemax)!=EOF)
        {
            
            if (strcmp(p.Id,ide)==0)
            {
                return(p);
            }
        }
    }
}











enum
{
    ID,
    COURS,
    NOMBREDEPLACE,
    DATE,
    HEURE,
    NOMBREDEPLACEMAX,
    COLUMNS
};

void ajouter_amine(Personnet p)
{

FILE*f;
f=fopen("seancee.txt","a+");//ouvertur du fichier en mode lecture
if(f!=NULL) 
{
fprintf(f,"%s %s %d %d %d %s %d %d\n", p.Id, p.Cours, p.date.jour, p.date.mois, p.date.annee ,p.Heure, p.Nombredeplace, p.Nombredeplacemax);
fclose(f);
}
              
}
void afficher_amine(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char jour[20];
        char mois[20];
        char annee[20];
	char date[20];
	char Heure[20];
        char Nombredeplace[20];
        char Cours[20];
        char Id[20];
        char Nombredeplacemax[20];
        store=NULL;

       FILE *f;

store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Cours", renderer, "text",COURS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               

renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nombredeplace", renderer, "text",NOMBREDEPLACE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nombredeplacemax", renderer, "text",NOMBREDEPLACEMAX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
            }



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("seancee.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("seancee.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",Id,Cours,jour,mois,annee,Heure,Nombredeplace,Nombredeplacemax)!=EOF)
		{if(Id[0]!='-'){
                 strcpy(date,jour);strcat(date,"/");
		 strcat(date,mois);strcat(date,"/");
		 strcat(date,annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, Id, COURS, Cours,DATE, date,HEURE, Heure,NOMBREDEPLACE, Nombredeplace, NOMBREDEPLACEMAX, Nombredeplacemax, -1); }
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


