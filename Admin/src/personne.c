#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personne.h"
#include <gtk/gtk.h>

/*
int exist(char user[])
{
 Personne p;
 FILE*f;
 int exist=-1;

 f=fopen("utilisateur.txt" , "r");
 if (f!=NULL)
	{
	 while (fscanf(f,"%s " , p.id)!=EOF)
		{
		 if (strcmp(user,p.id)==0 )
			 exist=1;	
		}
	}

 fclose(f);

 return(exist);						
}*/
// desactiver un compte

void dis_acc(char ide[])
{
 Personne p;
 FILE *f;
 FILE *f2;
 FILE *f3;
 FILE *f4;
 char nom[30];
 char prenom[30];
 char id[30];
 char jour[30];
 char mois[30];
 char annee[30];
 char date[30];
 char role[30];

 f=fopen("utilisateur.txt","r");
    if(f==NULL)
    	{
	 return;
	}
    else
	{
         while(fscanf(f,"%s %s %s %s %s %s %s \n",id,nom,prenom,jour,mois,annee,role)!=EOF)
		{
		 if(strcmp(id,ide)!=0)
			{
			 f2=fopen("test1.txt", "a");
			 if (f2==NULL)
				{
			 	 return;
				}
		 	 else	
				{
				 fprintf(f2,"%s %s %s %s %s %s %s \n" ,id,nom,prenom,jour,mois,annee,role);
				 fclose(f2);
				}
			}
		 else
			{
		 	 f2=fopen("test1.txt", "a");
			 if(f2!=NULL)
				{
				 char dis[30]="-";
				 strcat(dis,id);
				 fprintf(f2,"%s %s %s %s %s %s %s \n" ,dis,nom,prenom,jour,mois,annee,role);
				 fclose(f2);
				}
			}
	    	}
	}
 fclose(f);
 remove("utilisateur.txt");
 rename("test1.txt","utilisateur.txt");

//auth
char login[30];
char pass[30];
 f3=fopen("users.txt","r");
    if(f3==NULL)
    	{
	 return;
	}
    else
	{
         while(fscanf(f,"%s %s %s \n",login,pass,role)!=EOF)
		{
		 if(strcmp(login,ide))
			{
			 f4=fopen("test2.txt", "a");
			 if(f4!=NULL)
				{
				 fprintf(f4,"%s %s %s \n" ,login,pass,role);
				 fclose(f4);
				}
			}
		 else
			{
			 f4=fopen("test2.txt", "a");
			 if(f4!=NULL)
				{
			 	 char dis[30]="-";
			 	 strcat(dis,login);
			 	 fprintf(f4,"%s %s %s \n" ,dis,pass,role);
			 	 fclose(f4);
				}
			}
		}
	}
 fclose(f3);
 remove("users.txt");
 rename("test2.txt","users.txt");
}


// get personne

Personne get_personne(char ide[])
{
    Personne p ;
    FILE *f;
    
    
    f=fopen("utilisateur.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %s ",&p.id,&p.nom,&p.prenom,
        &p.date.jour,&p.date.mois,&p.date.annee,&p.role)!=EOF)
        {
            
            if (strcmp(p.id,ide)==0)
            {
                return(p);
            }
        }
    }
}

int exist(char user[])
{
 char login[30];
 char pass[30];
 char role[30];
 FILE*f;
 int exist=-1;

 f=fopen("users.txt" , "r");
 if (f!=NULL)
	{
	 while (fscanf(f,"%s %s %s" , login,pass,role)!=EOF)
		{
		 if (strcmp(user,login)==0 )
			 exist=1;	
		}
	}

 fclose(f);

 return(exist);						
}

enum   
{       
 IDENTIFIANT,
 NOM,
 PRENOM,
 DATE,
 ROLE,
 COLUMNS
};



//Ajouter une personne

void ajouter_personne(Personne p)
{
 FILE *f;
 int ln;
 char vil[20];
 char def [20];
 char def2 [20];
 int r=0;
 strcpy(def,"50");
 strcpy(vil,"test");
 strcpy(def2,"Aucune.");
 f=fopen("utilisateur.txt","a+");
 if(f!=NULL) 
	{
	 fprintf(f,"%s %s %s %d %d %d %s \n" ,p.id,p.nom,p.prenom,p.date.jour,p.date.mois,p.date.annee,p.role);
	 fclose(f);
	}
 FILE *f1;
 f1=fopen("users.txt","a+");
 if(f!=NULL) 
	{
	 if((strcmp(p.role,"Admin")==0))r=1;
	 else if((strcmp(p.role,"Kinésithérapeute")==0))r=2;
	 else if((strcmp(p.role,"Coach")==0))r=3;
	 else if((strcmp(p.role,"Adhérent")==0))r=5;
	 else if((strcmp(p.role,"Médecin_nutritionniste")==0))r=6;
	 else if((strcmp(p.role,"Médecin_généraliste")==0))r=4;
	 fprintf(f,"%s %s %d \n" ,p.id,p.id,r);
	 fclose(f);
	}
	FILE *f2;
 f=fopen("comptes.txt","a+");
 if(f!=NULL) 
	{
	 ln=getln();
	 fprintf(f,"%s %s %s %d %d %d %s %s %s %d \n" ,p.id,p.nom,p.prenom,p.date.jour,p.date.mois,p.date.annee,vil,vil,vil,ln);
	 fclose(f);
	}
	f=fopen("fiches.txt","a+");
 if(f!=NULL) 
	{
	 if(r==5){
	 fprintf(f,"%s %s %s %s %s %s %s\n" ,p.id,p.nom,p.prenom,def,def,def,def2);
	 fclose(f);}
	}
  
}



//Afficher une personne

void afficher_personne(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char nom [30];
 char prenom [30];
 char id[30];
 char jour[30];
 char mois[30];
 char annee[30];
 char date[30];
 char role[30];
 store=NULL;
 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);	
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",DATE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("utilisateur.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("utilisateur.txt", "a+");
	 while(fscanf(f,"%s %s %s %s %s %s %s \n",id,nom,prenom,jour,mois,annee,role)!=EOF)
		{
		 if(id[0]!='-')
			{
			 strcpy(date,jour);strcat(date,"/");
			 strcat(date,mois);strcat(date,"/");
			 strcat(date,annee);
			 gtk_list_store_append (store, &iter);
			 gtk_list_store_set (store,&iter,IDENTIFIANT,id,NOM,nom,PRENOM,prenom,DATE,date,ROLE,role,-1);
			}
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}


//Afficher une banned


void afficher_bpersonne(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char nom [30];
 char prenom [30];
 char id[30];
 char jour[30];
 char mois[30];
 char annee[30];
 char date[30];
 char role[30];
 store=NULL;
 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);	
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",DATE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("utilisateur.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("utilisateur.txt", "a+");
	 while(fscanf(f,"%s %s %s %s %s %s %s \n",id,nom,prenom,jour,mois,annee,role)!=EOF)
		{
		 if(id[0]=='-')
			{
			 char aid[30];
			 for(int i=0;i<strlen(id);i++)
				*(aid+i)=*(id+i+1);
			 strcpy(date,jour);strcat(date,"/");
			 strcat(date,mois);strcat(date,"/");
			 strcat(date,annee);
			 gtk_list_store_append (store, &iter);
			 gtk_list_store_set (store,&iter,IDENTIFIANT,aid,NOM,nom,PRENOM,prenom,DATE,date,ROLE,role,-1);
			}
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}


compte get_compte(int ide)
{
    compte cpt ;
    FILE *f;
    
    
    f=fopen("comptes.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s",&cpt.id,&cpt.nom,&cpt.prenom,
        &cpt.datenaiss.jour,&cpt.datenaiss.mois,&cpt.datenaiss.annee,&cpt.sexe,&cpt.ville,&cpt.numtel,&cpt.ligne)!=EOF)
        {
            
            if (cpt.id==ide)
            {
                return(cpt);
            }
        }
    }
}

int getln()
{
	FILE *f;
	compte cpt;
	int i;
	i=0;
	f=fopen("comptes.txt","r");
	if(f!=NULL)
	{
        while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s",&cpt.id,&cpt.nom,&cpt.prenom,
        &cpt.datenaiss.jour,&cpt.datenaiss.mois,&cpt.datenaiss.annee,&cpt.sexe,&cpt.ville,&cpt.numtel,&cpt.ligne)!=EOF)
        {
            i++;
        }
	}
	return(i);
}




