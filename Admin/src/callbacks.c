#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"
#include "fiche.h"
#include "seances_cures.h"
#include "coaching.h"
#include "offre.h"
#include "rdv.h"
#include "consultm.h"
#include "consultc.h"
#include "seancec.h"
#include "seancee.h"
#include "event.h"


//Login
void on_button_clicked(GtkWidget       *objet_graphique,gpointer         user_data)
{
 GtkWidget *input1;
 GtkWidget *input2;
 GtkWidget *output;
 GtkWidget *Login;
 GtkWidget *Admin;
 GtkWidget *window1;
 GtkWidget *Coach;
 GtkWidget *List_view;
 GtkWidget *Med;GtkWidget *adh;
 GtkWidget *lab50;
 GtkWidget *input6;
 GtkWidget *input7;
 GtkWidget *spin7;
 GtkWidget *spin8;
 GtkWidget *output61;
 GtkWidget *input8;
 GtkWidget *cbbox4;
 GtkWidget *cbbox5;
 GtkWidget *rols;
 GtkWidget *modifs;


 char nom[30],mdp[30],test[30];
 int v,cpts;
 compte cp;


 input1=lookup_widget(objet_graphique,"entry1");
 input2=lookup_widget(objet_graphique,"entry2");
 output=lookup_widget(objet_graphique,"Error");
 strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
 spacex(nom);
 strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(mdp);
 v=verif(nom,mdp);
 switch(v)
 	{case 1:
 	 	{
		 Login=lookup_widget(objet_graphique,"Login");
		 Admin=create_Admin();
		 gtk_widget_show(Admin);
		 gtk_widget_hide(Login);
         break;
		}
     case 2:
        {
         Login=lookup_widget(objet_graphique,"Login");
		 window1=create_window1();
		 gtk_widget_show(window1);

		 rmcache();
		 addcache(nom);


		 lab50=lookup_widget(window1,"ident");
		 gtk_widget_hide(Login);
		 gtk_label_set_text(GTK_LABEL(lab50),nom);
		 strcpy(test,gtk_label_get_text(GTK_LABEL(lab50)));
		 spacex(test);
		 cpts=atoi(nom);
		 cp=get_compte(cpts);
		 input6=lookup_widget(window1,"entry6");
		 input7=lookup_widget(window1,"entry7");
		 spin7=lookup_widget(window1,"spinbutton7");
		 spin8=lookup_widget(window1,"spinbutton8");
		 output61=lookup_widget(window1,"label61");
		 input8=lookup_widget(window1,"entry8");
		 cbbox4=lookup_widget(window1,"combobox4");
		 cbbox5=lookup_widget(window1,"combobox5");
		 rols=lookup_widget(window1,"rol");
		 modifs=lookup_widget(window1,"modif");


		 gtk_entry_set_text(GTK_ENTRY(input6),cp.nom);
		 gtk_entry_set_text(GTK_ENTRY(input7),cp.prenom);
		 int a,b;
		 a=atoi(cp.datenaiss.jour);
		 b=atoi(cp.datenaiss.mois);
		 gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin7),a);
		 gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin8),b);
		 gtk_label_set_text(GTK_LABEL(output61),cp.datenaiss.annee);
		 gtk_entry_set_text(GTK_ENTRY(input8),cp.numtel);
		 gtk_label_set_text(GTK_LABEL(rols),"Kinésithérapeute");
		 
		 
		 

		 



         break;
        }
	 case 3:
        {
         Login=lookup_widget(objet_graphique,"Login");
		 Coach=create_Coach();
		 gtk_widget_hide(Login);
		 List_view=lookup_widget(Coach,"treeview500");
		 afficher_amine(List_view);
		 gtk_widget_show(Coach);
		 
         break;
        }
	case 4:
        {
         Login=lookup_widget(objet_graphique,"Login");
		 Med=create_Med();
		 gtk_widget_show(Med);
		 gtk_widget_hide(Login);
		 rmcache();
		 addcache(nom);
		


         break;
        }
	case 5:
        {
         Login=lookup_widget(objet_graphique,"Login");
		 adh=create_adh();
		 gtk_widget_show(adh);
		 gtk_widget_hide(Login);
		 rmcache();
		 addcache(nom);
         break;
        }    	            
	 case 0:
 	 	 gtk_label_set_text(GTK_LABEL(output),"Erreur: verifier login ou mot de passe");
 	}
}



// Espace Admin -> Gestion des comptes
void
on_admin_list_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *Admin;
 GtkWidget *treeview1;

 Admin=lookup_widget(objet,"Admin");
 list=create_list();
 treeview1=lookup_widget(list,"treeview1");

 gtk_widget_destroy(Admin);
 gtk_widget_show(list);
 afficher_personne(treeview1);
}



// Ajouter un compte -> retour
void
on_add_return_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *add, *list;
 GtkWidget *treeview1; 

 add=lookup_widget(objet,"add");
 list=create_list();
 treeview1=lookup_widget(list,"treeview1");

 gtk_widget_destroy(add);
 gtk_widget_show(list);
 afficher_personne(treeview1);
}



//Ajouter un compte -> Ajouter
void
on_add_ajouter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *add;
 GtkWidget *output;
 GtkWidget *combobox1;



 add=lookup_widget(objet,"add");

 input1=lookup_widget(objet,"add_ent_id");
 input2=lookup_widget(objet,"add_ent_nom");
 input3=lookup_widget(objet,"add_ent_prenom");

 jour=lookup_widget(objet, "spinbutton1");
 mois=lookup_widget(objet, "spinbutton2");
 annee=lookup_widget(objet, "spinbutton3");

 combobox1=lookup_widget(objet,"combobox1");

 output=lookup_widget(objet,"label15");



 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
 spacex(p.id);
 strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
 spacex(p.nom);
 strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
 spacex(p.prenom);

 p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

 strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
 
 //Condition manquante!!(cases non vides)
 int e;
 e=exist(p.id);
 if(e==1)
	 gtk_label_set_text(GTK_LABEL(output),"L'identifiant existe");
 else
	{
	 ajouter_personne(p);
	 gtk_label_set_text(GTK_LABEL(output),"Ajout réussi!");
	}
	 
}



//Gestion des comptes -> retour
void
on_list_return_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *Admin;

 list=lookup_widget(objet,"list");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(list);
}



//Liste des Adherents -> ajouter
void
on_list_add_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *add;
 GtkWidget *c;

 list=lookup_widget(objet,"list");
 add=create_add();
 c=lookup_widget(add,"combobox1");

 gtk_widget_show(add);
 gtk_widget_destroy(list);
 gtk_combo_box_set_active(c,0);
}




void
on_activ_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *Admin;

 activ=lookup_widget(objet,"activ");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(activ);
}

void
on_stats_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *stats;
 GtkWidget *Admin;

 stats=lookup_widget(objet,"stats");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(stats);
}

void
on_admin_activ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *Admin;
 GtkWidget *treeview;

 Admin=lookup_widget(objet,"Admin");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
 gtk_widget_destroy(Admin);
}




void
on_admin_stats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *stats;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 stats=create_stats();

 gtk_widget_show(stats);
 gtk_widget_destroy(Admin);

 GtkWidget *tree;
 tree=lookup_widget(stats,"stats_treeview");
 afficher_bpersonne(tree);
}




void
on_admin_deals_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
 gtk_widget_destroy(Admin);
}











void
on_button13_clicked                    (GtkWidget       *objgr,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *Login;
		
	window1=lookup_widget(objgr,"window1");
	gtk_widget_hide(window1);
	Login=create_Login();
	gtk_widget_show(Login);
	
}


void
on_button14_clicked                    (GtkWidget       *objgr,
                                        gpointer         user_data)
{
	GtkWidget *input ;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *window1;
	GtkWidget *window2;
	
	char nom [50]; char ficha[1000];



input=lookup_widget(objgr,"entry4");
output1=lookup_widget(objgr,"label32");


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
spacex(nom);

if (verifier(nom)==-1)
	{ gtk_label_set_text(GTK_LABEL(output1),"Identifiant Introuvable ");}
else 
{
	gtk_widget_hide(window1);
	window2=create_window2();
	gtk_widget_show(window2);
	output2=lookup_widget(window2,"label31");
	afficher(nom,ficha);
	gtk_widget_show(window2);
	gtk_label_set_text(GTK_LABEL(output2),ficha);
	
	
	
	
}
}


void
on_button15_clicked                    (GtkWidget       *objger2,
                                        gpointer         user_data)
{
	
	GtkWidget *window1;
	GtkWidget *window3;
	GtkWidget *treeview2;
	
	
	window1=lookup_widget(objger2,"window1");
	//gtk_widget_hide(window1);
	window3=lookup_widget(objger2,"window3");
	window3=create_window3();
	gtk_widget_show(window3);
	
	treeview2=lookup_widget(window3,"treeview2");
	afficher_fiche(treeview2);
	
	
	

}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button16_clicked                    (GtkWidget       *objgr,
                                        gpointer         user_data)
{
GtkWidget *combobox2; //comobox pour la période
GtkWidget *combobox3; //comobox pour le type
GtkWidget *jo; //spinbuttun pour le choix du jour
GtkWidget *mo; //spinbuttun pour le choix du mois 
GtkWidget *an; //spinbuttun pour le choix de l’année
GtkWidget *nb;
GtkWidget *input;
GtkWidget *output;
Seance s;
int jj,mm,aa,nbb;

combobox2=lookup_widget(objgr, "combobox2");
jo=lookup_widget(objgr, "spinbutton4"); 
mo=lookup_widget(objgr, "spinbutton5"); 
an=lookup_widget(objgr, "spinbutton6"); 
nb=lookup_widget(objgr, "spinbutton13");
combobox3=lookup_widget(objgr, "combobox3");
output=lookup_widget(objgr, "label33"); 
input=lookup_widget(objgr,"entry13");

jj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jo));
mm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mo));
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (an));
nbb=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));

sprintf(s.date_seance.jour,"%d",jj);
sprintf(s.date_seance.mois,"%d",mm);
sprintf(s.date_seance.annee,"%d",aa);
sprintf(s.nbp,"%d",nbb);

if(strcmp("9h-->10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  
	strcpy(s.periode,"9h-->10h");
if(strcmp("10h-->11h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	strcpy(s.periode,"10h-->11h");
if(strcmp("11h-->12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0) 
	strcpy(s.periode,"11h-->12h");
if(strcmp("15h-->16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0) 
	strcpy(s.periode,"15h-->16h");
if(strcmp("16h-->17h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0) 
	strcpy(s.periode,"16h-->17h");

strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

strcpy(s.num,gtk_entry_get_text(GTK_ENTRY(input)));spacex(s.num);



ajouter_seance(s);

gtk_label_set_text(GTK_LABEL(output),"Séance ajoutée :) ");


}


void
on_button23_clicked                    (GtkWidget       *objger3,
                                        gpointer         user_data)
{
	GtkWidget *Coach;
	GtkWidget *Login;
		
	Coach=lookup_widget(objger3,"Coach");
	gtk_widget_hide(Coach);
	Login=create_Login();
	gtk_widget_show(Login);
	
}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button24_clicked                    (GtkWidget       *objger2,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window4;
	GtkWidget *treeview4;
	
	
	window1=lookup_widget(objger2,"window1");
	//gtk_widget_hide(window1);
	window4=lookup_widget(objger2,"window4");
	window4=create_window4();
	gtk_widget_show(window4);
	
	treeview4=lookup_widget(window4,"treeview4");
	afficher_seance(treeview4);
}


void
on_button26_clicked                    (GtkWidget      *objger4,
                                        gpointer         user_data)
{
	GtkWidget *input ;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *window1;
	GtkWidget *FicheMed;
	
	char nom [50]; char ficha[1000];



input=lookup_widget(objger4,"entry5");
output1=lookup_widget(objger4,"label573");


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
spacex(nom);

if (verifier(nom)==-1)
	{ gtk_label_set_text(GTK_LABEL(output1),"Identifiant Introuvable ");}
else 
{
	//gtk_widget_hide(window1);
	FicheMed=create_FicheMed();
	gtk_widget_show(FicheMed);
	output2=lookup_widget(FicheMed,"label572");
	afficher(nom,ficha);
	//gtk_widget_show(FicheMed);
	gtk_label_set_text(GTK_LABEL(output2),ficha);
		
}
}

void
on_button27_clicked                    (GtkWidget       *objger4,
                                        gpointer         user_data)
{
	
	GtkWidget *Med;
	GtkWidget *ListMed;
	GtkWidget *treeview5;
	
	
	Med=lookup_widget(objger4,"Med");
	//gtk_widget_hide(window1);
	//ListMed=lookup_widget(objger4,"ListMed");
	ListMed=create_ListMed();
	gtk_widget_show(ListMed);
	
	treeview5=lookup_widget(ListMed,"treeview5");
	afficher_fiche(treeview5);
	
	
	

}


void
on_button25_clicked                    (GtkWidget       *objger4,
                                        gpointer         user_data)
{
	GtkWidget *Med;
	GtkWidget *Login;

	rmcache();	
	Med=lookup_widget(objger4,"Med");
	gtk_widget_hide(Med);
	Login=create_Login();
	gtk_widget_show(Login);
	
}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkWidget       *objger7,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input;
	Seance s;
	char nn[5];

	output=lookup_widget(objger7,"label114"); 
	input=lookup_widget(objger7,"entry14");

	strcpy(nn,gtk_entry_get_text(GTK_ENTRY(input)));spacex(nn);

	supprimer_seance(nn);
	gtk_label_set_text(GTK_LABEL(output),"Suppression réussie :) ");

}


void
on_button43_clicked                    (GtkWidget       *objger5,
                                        gpointer         user_data)
{
	GtkWidget *window6 ;
	GtkWidget *window4 ;
	window4=lookup_widget(objger5,"window4");
	window6=lookup_widget(objger5,"window6");
	window6=create_window6();
	gtk_widget_show(window6);
}


void
on_button44_clicked                    (GtkWidget       *objger5,
                                        gpointer         user_data)
{
	GtkWidget *window7 ;
	GtkWidget *window4 ;
	window4=lookup_widget(objger5,"window4");
	window7=lookup_widget(objger5,"window7");
	window7=create_window7();
	gtk_widget_show(window7);

}

void
on_button45_clicked                    (GtkWidget       *objger6,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	Seance s;
	char nn[5];char m7[20];char m2[20];char m3[20];char m4[20];char m5[20];char m6[20];

	output=lookup_widget(objger6,"label113");
	input1=lookup_widget(objger6,"entry15");
	input2=lookup_widget(objger6,"entry16");
	input3=lookup_widget(objger6,"entry17");
	input4=lookup_widget(objger6,"entry18");
	input5=lookup_widget(objger6,"entry19");
	input6=lookup_widget(objger6,"entry20");
	input7=lookup_widget(objger6,"entry21");
	
	strcpy(nn,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(nn);
	strcpy(m2,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(m2);
	strcpy(m3,gtk_entry_get_text(GTK_ENTRY(input3)));spacex(m3);
	strcpy(m4,gtk_entry_get_text(GTK_ENTRY(input4)));spacex(m4);
	strcpy(m5,gtk_entry_get_text(GTK_ENTRY(input5)));spacex(m5);
	strcpy(m6,gtk_entry_get_text(GTK_ENTRY(input6)));spacex(m6);
	strcpy(m7,gtk_entry_get_text(GTK_ENTRY(input7)));spacex(m7);


	modifier_seance(nn,m2,m3,m4,m5,m6,m7);/*
					   gtk_entry_get_text(GTK_ENTRY(input3)),
					   gtk_entry_get_text(GTK_ENTRY(input4)),
					   gtk_entry_get_text(GTK_ENTRY(input5)),
					   gtk_entry_get_text(GTK_ENTRY(input6)),
					   gtk_entry_get_text(GTK_ENTRY(input7)));*/

	gtk_label_set_text(GTK_LABEL(output),"Modification réussie :) ");				

}


void
on_button49_clicked                    (GtkWidget       *objger8,
                                        gpointer         user_data)
{
GtkWidget *adh;
GtkWidget *adhoffres;
	
	adhoffres=create_adhoffres();
	gtk_widget_show (adhoffres);
	

}


void
on_button59_clicked                    (GtkWidget       *objger9,
                                        gpointer         user_data)
{
GtkWidget *combobox10;
GtkWidget *button59;
GtkWidget *label121;
char nom1[10];
offre offre1;
char str[100];


combobox10=lookup_widget(objger9,"combobox10");
strcpy(nom1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10)));
offre1=getoffre(nom1);
label121=lookup_widget(objger9,"label121");
strcpy(str,"Déscription : ");
strcat(str,offre1.description);
strcat(str,"\nPrix :");
strcat(str,offre1.prix);
gtk_label_set_text(GTK_LABEL(label121),str);

}


void
on_calendar1_day_selected_double_click (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
    GtkWidget *calmed;
    GtkWidget *output;
	GtkWidget *treeview7;
	
    

    char dayz[20];char js[20];
	char monthz[20];char ms[20];
	char yearz[20];char as[20];char outpt[20];
	char idmed[20];
    guint month;
    guint year;
    guint day;
    
    
    
    gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
    calmed = create_calmed ();
    gtk_widget_show (calmed);
    
    output=lookup_widget(calmed,"label123");
    sprintf(dayz, "%u", day);
	month++;
	sprintf(monthz, "%u", month); 
	sprintf(yearz, "%u", year);

	rmcachedat();
	addcachedat(dayz,monthz,yearz);

	strcpy(outpt,dayz);strcat(outpt,"/");
	strcat(outpt,monthz);strcat(outpt,"/");
	strcat(outpt,yearz);

    gtk_label_set_text(GTK_LABEL(output),outpt);
	treeview7=lookup_widget(calmed,"treeview7");
	strcpy(js,dayz);
	strcpy(ms,monthz);
	strcpy(as,yearz);

	getcache(idmed);
	afficher_rdv(treeview7,idmed,js,ms,as);
    
    
}


void
on_button60_clicked                    (GtkWidget      *objger10,
                                        gpointer         user_data)
{
	GtkWidget *ajmed;
	GtkWidget *calmed;
	GtkWidget *output;
	GtkWidget *output2;
	char pass[20];

	calmed=lookup_widget(objger10,"calmed");
	gtk_widget_hide(calmed);

	ajmed = create_ajmed ();
    gtk_widget_show (ajmed);

	output=lookup_widget(objger10,"label123");
	output2=lookup_widget(ajmed,"label144");
	strcpy(pass,gtk_label_get_text(GTK_LABEL(output)));spacex(pass);
	gtk_label_set_text(GTK_LABEL(output2),pass);
}


void
on_button66_clicked                    (GtkWidget       *objger10,
                                        gpointer         user_data)
{
	GtkWidget *ListeMed2;
	GtkWidget *treeview8;
		
		
	ListeMed2=create_ListeMed2();                  
	gtk_widget_show(ListeMed2);
	
	treeview8=lookup_widget(ListeMed2,"treeview8");
	afficher_fiche(treeview8);

}


void
on_button67_clicked                    (GtkWidget       *objger10,
                                        gpointer         user_data)
{
	
	GtkWidget *input;
	GtkWidget *combobox1;
	GtkWidget *ermsg;

	char idmed[20];char otp[60];
	char id2[20];char per[20];
	char jr[20];char ms[20];char as[20];

	input=lookup_widget(objger10,"entry25");
	ermsg=lookup_widget(objger10,"label146");
	strcpy(id2,gtk_entry_get_text(GTK_ENTRY(input)));spacex(id2);
	combobox1=lookup_widget(objger10,"combobox13");
	strcpy(per,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	getcachedat(jr,ms,as);

	
	getcache(idmed);
	// Realiser le cache de la date avant de terminer 
	strcpy(otp,idmed);strcat(otp," ");
	strcat(otp,id2);strcat(otp," ");
	strcat(otp,jr);strcat(otp," ");
	strcat(otp,ms);strcat(otp," ");
	strcat(otp,as);strcat(otp," ");
	strcat(otp,per);
	if (verifid(id2)==0)
	{
		gtk_label_set_text(GTK_LABEL(ermsg),"Identifiant Introuvable");
	}
	else {if (verifrdv(idmed,jr,ms,as,per)==0)
	{
		addrdv(otp);
		gtk_label_set_text(GTK_LABEL(ermsg),"Rendez-vous ajouté avec succès !");		
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(ermsg),"Impossible d'ajouter le Rendez-vous");
	}
	}
	
	

	

}


void
on_button69_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	
}


void
on_button68_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *ajmed;
	GtkWidget *calmed;
	GtkWidget *treeview7;
	GtkWidget *output;
	char js[20];char as[20];char ms[20];char outpt[60];char idmed[20];



	ajmed=lookup_widget(objger,"ajmed");
	calmed=create_calmed();
	gtk_widget_show(calmed);
	gtk_widget_hide(ajmed);

	output=lookup_widget(calmed,"label123");
	getcachedat(js,ms,as);
	strcpy(outpt,js);strcat(outpt,"/");
	strcat(outpt,ms);strcat(outpt,"/");
	strcat(outpt,as);

    gtk_label_set_text(GTK_LABEL(output),outpt);
	treeview7=lookup_widget(calmed,"treeview7");
	getcache(idmed);
	afficher_rdv(treeview7,idmed,js,ms,as);
}


void
on_button62_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *calmed;
	GtkWidget *suppmed;

	calmed=lookup_widget(objger,"calmed");
	gtk_widget_hide(calmed);

	suppmed = create_suppmed ();
    gtk_widget_show (suppmed);
}


void
on_button70_clicked                    (GtkWidget      *objger,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *ermsg;
	int i;
	char per[20];char js[20];char as[20];char ms[20];char idmed[20];

	ermsg=lookup_widget(objger,"label149");
	combobox1=lookup_widget(objger,"combobox14");
	strcpy(per,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

	getcachedat(js,ms,as);
	getcache(idmed);
	

	i=supprimer_rdv(idmed,js,ms,as,per);

	if (i==0)
		gtk_label_set_text(GTK_LABEL(ermsg),"Suppression Réussie !");
	else
		gtk_label_set_text(GTK_LABEL(ermsg),"Période introuvable !");

}


void
on_button71_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *suppmed;
	GtkWidget *calmed;
	GtkWidget *treeview7;
	GtkWidget *output;
	char js[20];char as[20];char ms[20];char outpt[60];char idmed[20];



	suppmed=lookup_widget(objger,"suppmed");
	calmed=create_calmed();
	gtk_widget_show(calmed);
	gtk_widget_hide(suppmed);

	output=lookup_widget(calmed,"label123");
	getcachedat(js,ms,as);
	strcpy(outpt,js);strcat(outpt,"/");
	strcat(outpt,ms);strcat(outpt,"/");
	strcat(outpt,as);

    gtk_label_set_text(GTK_LABEL(output),outpt);
	treeview7=lookup_widget(calmed,"treeview7");
	getcache(idmed);
	afficher_rdv(treeview7,idmed,js,ms,as);
	
}


void
on_button74_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{

}


void
on_button73_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *entry1;
	GtkWidget *combobox2;
	GtkWidget *jr;
	GtkWidget *moi;
	GtkWidget *ann;
	GtkWidget *spin1;
	GtkWidget *spin2;
	GtkWidget *spin3;
	GtkWidget *output;

	char per2[20];char js[20];char as[20];char ms[20];char idmed[20];
	char id2[20];char ja[20];char ma[20];char aa[20];char per[20];
	int a,b,c;
	
	output=lookup_widget(objger,"label158");
	entry1=lookup_widget(objger,"entry26");
	combobox2=lookup_widget(objger,"combobox16");
	combobox1=lookup_widget(objger,"combobox15");
	spin1=lookup_widget(objger,"spinbutton16");
	spin2=lookup_widget(objger,"spinbutton17");
	spin3=lookup_widget(objger,"spinbutton18");

	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin1));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin2));
	c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin3));
	strcpy(per2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	strcpy(per,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	strcpy(id2,gtk_entry_get_text(GTK_ENTRY(entry1)));spacex(id2);
	getcache(idmed);
	getcachedat(ja,ma,aa);

	sprintf(js,"%d",a);
	sprintf(ms,"%d",b);
	sprintf(as,"%d",c);

	if (verifid(id2)==0)
	{
		gtk_label_set_text(GTK_LABEL(output),"Idet introuvable !");
	}
	else
	{
		if(verifrdv(idmed,js,ms,as,per)==1)
		{
			gtk_label_set_text(GTK_LABEL(output),"Date indisponible !");
		}
		else
		{
			modifrdv(idmed,ja,ma,aa,per,id2,js,ms,as,per2);
			gtk_label_set_text(GTK_LABEL(output),"Modification réussie !");
		}
	}

}


void
on_button72_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *entry1;
	GtkWidget *combobox2;
	GtkWidget *jr;
	GtkWidget *moi;
	GtkWidget *ann;
	GtkWidget *spin1;
	GtkWidget *spin2;
	GtkWidget *spin3;

	char per[20];char js[20];char as[20];char ms[20];char idmed[20];
	char id2[20];
	int a,b,c;

	getcachedat(js,ms,as);
	getcache(idmed);

	entry1=lookup_widget(objger,"entry26");
	combobox1=lookup_widget(objger,"combobox15");
	strcpy(per,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	spin1=lookup_widget(objger,"spinbutton16");
	spin2=lookup_widget(objger,"spinbutton17");
	spin3=lookup_widget(objger,"spinbutton18");

	chercrdv(idmed,js,ms,as,per,id2);
	gtk_entry_set_text(GTK_ENTRY(entry1),id2);

	a=atoi(js);b=atoi(ms);c=atoi(as);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin1),a);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin2),b);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin3),c);
}


void
on_button61_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *calmed;
	GtkWidget *modmed;

	calmed=lookup_widget(objger,"calmed");
	gtk_widget_hide(calmed);

	modmed = create_modmed ();
    gtk_widget_show (modmed);
}


void
on_button48_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *adh;
GtkWidget *consad;
	
	consad=create_consad();
	gtk_widget_show (consad);
}


void
on_button75_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *consad;
GtkWidget *admed;
GtkWidget *treeview9;
	
	admed=create_admed();
	gtk_widget_show (admed);

	treeview9=lookup_widget(admed,"treeview9");
	afficher_med(treeview9);
}


void
on_button76_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *consad;
GtkWidget *adcoach;
GtkWidget *treeview11;
	
	adcoach=create_adcoach();
	gtk_widget_show (adcoach);
	
	treeview11=lookup_widget(adcoach,"treeview11");
	afficher_c(treeview11);
}


void
on_button78_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *adcoach;
GtkWidget *notcoach;
	
	notcoach=create_notcoach();
	gtk_widget_show (notcoach);
}


void
on_button79_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output;
GtkWidget *label161;
char ch[20],msg1[60],msg2[60],msg3[60],note[20],idc[20],ida[20],aa[20];
int s,s1;
getcache(aa);
strcpy(ida,aa);//juste pour le test
strcpy(msg1,"Vous avez modifié la note du coach");
strcpy(msg2,"Votre note est prise .Merci" );
strcpy(msg3,"veuillez entrer un id valide du coach");
input1=lookup_widget(objger,"entry27");
strcpy(idc,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(idc);
input2=lookup_widget(objger,"entry28");
strcpy(note,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(note);
output=lookup_widget(objger,"label161");
s=comparaison_id(idc);
s1=comparaison_id1(idc,ida);
if(s==1)
	{if(s1==1){modif_note(ida,idc,note);
		   gtk_label_set_text(GTK_LABEL(output),msg1);
		  }
	 else {
		ajout_note(ida,idc,note);
	 	gtk_label_set_text(GTK_LABEL(output),msg2);
	      }
	}
else gtk_label_set_text(GTK_LABEL(output),msg3);	   	
}


void
on_button47_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *adcur;
GtkWidget *treeview12;
	
	adcur=create_adcur();
	gtk_widget_show (adcur);

	treeview12=lookup_widget(adcur,"treeview12");
	afficher_seancec(treeview12);
}


void
on_button80_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{

	GtkWidget *adinscur;

	adinscur=create_adinscur();
	gtk_widget_show (adinscur);
	
}


void
on_button81_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label163;
char msg1[60],msg2[60],msg3[60],msg4[60],num[20],id[20];
int s;

getcache(id);
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
strcpy(msg4,"Veuillez entrer un numéro valide ." );
input1=lookup_widget(objger,"entry29");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objger,"label163");
s=inscription2(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb4(num);
			   ajout_part2(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		case -1 : {
			   gtk_label_set_text(GTK_LABEL(output),msg4);
		   	break;
		  	}
		}
}


void
on_button82_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label163;
char msg1[60],msg2[60],num[20],id[20];
int s;
getcache(id);
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objger,"entry29");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objger,"label163");
s=annulation2(id,num);
switch (s)
		{case 0 : {modif_nb5(num);
			   supression_part2(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
}


void
on_button50_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *adent;
GtkWidget *treeview13;
	
	adent=create_adent();
	gtk_widget_show (adent);
	
	treeview13=lookup_widget(adent,"treeview13");
	afficher_seancee(treeview13);
}


void
on_button83_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *adinsent;
	
	adinsent=create_adinsent();
	gtk_widget_show (adinsent);
}


void
on_button84_activate                   (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label165;
char msg1[60],msg2[60],msg3[60],msg4[60],num[20],id[20];
int s;
getcache(id);
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
strcpy(msg4,"Veuillez entrer un numéro valide ." );
input1=lookup_widget(objger,"entry30");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objger,"label165");
s=inscription1(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb2(num);
			   ajout_part1(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		case -1 : {
			   gtk_label_set_text(GTK_LABEL(output),msg4);
		   	break;
		  	}
		}
}

void
on_button85_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label165;
char msg1[60],msg2[60],num[20],id[20];
int s;

getcache(id);
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objger,"entry30");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objger,"label165");
s=annulation1(id,num);
switch (s)
		{case 0 : {modif_nb3(num);
			   supression_part1(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
		
}


void
on_button87_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *seancecoach;
GtkWidget *Coach;

Coach=lookup_widget(objger,"Coach");
seancecoach=create_seancecoach ();
gtk_widget_show(seancecoach);
gtk_widget_hide(Coach);
}


void
on_button88_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *Coach;
GtkWidget *mod;

Coach=lookup_widget(objger,"Coach");
mod=create_mod();
gtk_widget_show(mod);
gtk_widget_hide(Coach);
}


void
on_button86_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
}


void
on_button89_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
Personnet p;
GtkWidget *Nombredeplace;
GtkWidget *Nombredeplacemax;
GtkWidget *input1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox1, *combobox2;
GtkWidget *seancecoach;
GtkWidget *output;

seancecoach=lookup_widget(objger,"seancecoach");

Nombredeplace=lookup_widget(objger, "spinbutton502");
Nombredeplacemax=lookup_widget(objger, "spinbutton503");

jour=lookup_widget(objger, "spinbutton504");
mois=lookup_widget(objger, "spinbutton505");
annee=lookup_widget(objger, "spinbutton506");

combobox1=lookup_widget(objger,"combobox500");
combobox2=lookup_widget(objger,"combobox502");


output=lookup_widget(objger,"label517");
input1=lookup_widget(objger,"entry500");
strcpy(p.Id,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(p.Id);

p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


p.Nombredeplace=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplace));
p.Nombredeplacemax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplacemax));

strcpy(p.Cours,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(p.Heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));


ajouter_amine(p);
gtk_label_set_text(GTK_LABEL(output),"Cours ajouté!");



}


void
on_button90_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
GtkWidget *seancecoach;
GtkWidget *Coach;
GtkWidget *treeview1;
seancecoach=lookup_widget(objger,"seancecoach");
Coach=create_Coach ();
gtk_widget_show(Coach);
gtk_widget_hide(seancecoach);
treeview1=lookup_widget(Coach,"treeview500");

afficher_amine(treeview1);
}


void
on_button93_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{

Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
 char Id[30];
 //GtkWidget *output;
 mod=lookup_widget(objger,"mod");
 input2=lookup_widget(objger,"entry502");

 strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(Id);
 aminesupprimer(Id);


}


void
on_button92_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
 //GtkWidget *output;

char Id[30];
mod=lookup_widget(objger,"mod");


Nombredeplace=lookup_widget(objger, "spinbutton511");
Nombredeplacemax=lookup_widget(objger, "spinbutton512");

jour=lookup_widget(objger, "spinbutton508");
mois=lookup_widget(objger, "spinbutton509");
annee=lookup_widget(objger, "spinbutton510");

combobox4=lookup_widget(objger,"combobox504");
combobox5=lookup_widget(objger,"combobox505");
input2=lookup_widget(objger,"entry502");
 strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(Id);
 strcpy(p.Id,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(p.Id);

p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

p.Nombredeplace=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplace));
p.Nombredeplacemax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplacemax));


strcpy(p.Cours,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy(p.Heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));
aminesupprimer(Id);
ajouter_amine(p);


}


void
on_button91_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
char Id[30];
Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
 //GtkWidget *output;

mod=lookup_widget(objger,"mod");
input2=lookup_widget(objger,"entry502");
Nombredeplace=lookup_widget(objger, "spinbutton511");
Nombredeplacemax=lookup_widget(objger, "spinbutton512");

jour=lookup_widget(objger, "spinbutton508");
mois=lookup_widget(objger, "spinbutton509");
annee=lookup_widget(objger, "spinbutton510");

combobox4=lookup_widget(objger,"combobox504");
combobox5=lookup_widget(objger,"combobox505");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(Id);

 p=chercheramine(Id);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),p.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.date.annee);


 gtk_spin_button_set_value(GTK_SPIN_BUTTON(Nombredeplace),p.Nombredeplace);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(Nombredeplacemax),p.Nombredeplacemax);

gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _(p.Cours));
gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _(p.Heure));

}


void
on_button94_clicked                    (GtkWidget       *objger,
                                        gpointer         user_data)
{
	GtkWidget *List_view;
	GtkWidget *mod;
	GtkWidget *Coach;

	mod=lookup_widget(objger,"mod");
	Coach=create_Coach();
	gtk_widget_hide(mod);
	List_view=lookup_widget(Coach,"treeview500");
	afficher_amine(List_view);
	gtk_widget_show(Coach);
}


void
on_button95_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *edit_acc;
 GtkWidget *c;

 list=lookup_widget(objet,"list");
 edit_acc=create_edit_acc();
 c=lookup_widget(edit_acc,"comborole");
 gtk_combo_box_set_active (c,0);
 gtk_widget_show(edit_acc);
 gtk_widget_destroy(list);
}


void
on_activ_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_add;

 activ=lookup_widget(objet,"activ");
 activ_add=create_activ_add();

 gtk_widget_show(activ_add);
 gtk_widget_destroy(activ);
 GtkWidget *c;
 c=lookup_widget(activ_add,"combomin_ev");
 gtk_combo_box_set_active (c,0);
}



void
on_activ_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_edit;
 activ=lookup_widget(objet,"activ");
 activ_edit=create_activ_edit();
 gtk_widget_show(activ_edit);
 gtk_widget_destroy(activ);
 GtkWidget *c;
 c=lookup_widget(activ_edit,"comboedev");
 gtk_combo_box_set_active (c,0);
}

void
on_search_acc_enter                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 char id[30];
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;

 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");
 input2=lookup_widget(objet,"edit_last");
 input3=lookup_widget(objet,"edit_first");

 jour=lookup_widget(objet, "spinday");
 mois=lookup_widget(objet, "spinmonth");
 annee=lookup_widget(objet, "spinyear");

 combobox=lookup_widget(objet,"comborole");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(id);
 p=get_personne(id);
 gtk_entry_set_text (GTK_ENTRY(input2),p.nom);
 gtk_entry_set_text (GTK_ENTRY(input3),p.prenom);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),p.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.date.annee);
 gtk_combo_box_prepend_text (GTK_COMBO_BOX (combobox), _(p.role));
 GtkWidget *c;
 c=lookup_widget(edit_acc,"comborole");
 gtk_combo_box_set_active (c,0);
}



void
on_des_acct_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;
 char id[30];

 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(id);

 dis_acc(id); 
}

void
on_EDITT_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;
 char id[30];



 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");
 input2=lookup_widget(objet,"edit_last");
 input3=lookup_widget(objet,"edit_first");

 jour=lookup_widget(objet, "spinday");
 mois=lookup_widget(objet, "spinmonth");
 annee=lookup_widget(objet, "spinyear");

 combobox=lookup_widget(objet,"comborole");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(id);
 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(p.id);
 strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(p.nom);
 strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));spacex(p.prenom);

 p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

 strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
 dis_acc(id);
 ajouter_personne(p);
	 
}


void
on_edit_acc_return_enter               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *edit_acc;
 GtkWidget *list;
 GtkWidget *treeview1;

 edit_acc=lookup_widget(objet,"edit_acc");
 list=create_list();

 gtk_widget_show(list);
 treeview1=lookup_widget(list,"treeview1");
 afficher_personne(treeview1);
 gtk_widget_destroy(edit_acc);
}


void
on_add_activ_return_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_add;
 GtkWidget *treeview;

 activ_add=lookup_widget(objet,"activ_add");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
 gtk_widget_destroy(activ_add); 
}


void
on_add_activ_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 event e;

 GtkWidget *name;
 GtkWidget *des;
 GtkWidget *spind;
 GtkWidget *spinm;
 GtkWidget *spiny;
 GtkWidget *spinh;
 GtkWidget *combomin;
 GtkWidget *nb_ev;
 GtkWidget *nbm_ev;
 GtkWidget *num_ev;
 GtkWidget *activ_add;
 GtkWidget *output;



 activ_add=lookup_widget(objet,"activ_add");

 name=lookup_widget(objet,"name_ev");
 des=lookup_widget(objet,"des_ev");
 spind=lookup_widget(objet,"spind_ev");
 spinm=lookup_widget(objet,"spinm_ev");
 spiny=lookup_widget(objet,"spiny_ev");
 spinh=lookup_widget(objet,"spinh_ev");
 combomin=lookup_widget(objet,"combomin_ev");
 nb_ev=lookup_widget(objet,"nb_ev");
 nbm_ev=lookup_widget(objet,"nbm_ev");
 num_ev=lookup_widget(objet,"num_ev");



 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));spacex(e.num);
 strcpy(e.description,gtk_entry_get_text(GTK_ENTRY(des)));spacex(e.num);
 strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(name)));spacex(e.num);
 e.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spind));
 e.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinm));
 e.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spiny));
 e.heure.h=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinh));
 strcpy(e.heure.min,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomin)));
 strcpy(e.nombre,gtk_entry_get_text(GTK_ENTRY(nb_ev)));spacex(e.nombre);
 strcpy(e.nombremax,gtk_entry_get_text(GTK_ENTRY(nbm_ev)));spacex(e.nombremax);

 if (existev(e.num)!=1)
 ajout_ev(e);
}


void
on_edev_return_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_edit;
 GtkWidget *treeview;

 activ_edit=lookup_widget(objet,"activ_edit");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
 gtk_widget_destroy(activ_edit);
}


void
on_edit_ev_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 event e;

 GtkWidget *name;
 GtkWidget *des;
 GtkWidget *spind;
 GtkWidget *spinm;
 GtkWidget *spiny;
 GtkWidget *spinh;
 GtkWidget *combomin;
 GtkWidget *nb_ev;
 GtkWidget *nbm_ev;
 GtkWidget *num_ev;
 GtkWidget *activ_edit;
 GtkWidget *output;



 activ_edit=lookup_widget(objet,"activ_edit");

 name=lookup_widget(objet,"nameedev");
 des=lookup_widget(objet,"desedev");
 spind=lookup_widget(objet,"edjev");
 spinm=lookup_widget(objet,"edmev");
 spiny=lookup_widget(objet,"edyev");
 spinh=lookup_widget(objet,"edhev");
 combomin=lookup_widget(objet,"comboedev");
 nb_ev=lookup_widget(objet,"nbedev");
 nbm_ev=lookup_widget(objet,"nbmedev");
 num_ev=lookup_widget(objet,"numedev");



 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));spacex(e.num);
 strcpy(e.description,gtk_entry_get_text(GTK_ENTRY(des)));spacex(e.description);
 strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(name)));spacex(e.nom);
 e.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spind));
 e.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinm));
 e.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spiny));
 e.heure.h=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinh));
 strcpy(e.heure.min,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomin)));
 strcpy(e.nombre,gtk_entry_get_text(GTK_ENTRY(nb_ev)));spacex(e.nombre);
 strcpy(e.nombremax,gtk_entry_get_text(GTK_ENTRY(nbm_ev)));spacex(e.nombremax);

 suppev(e.num);
 ajout_ev(e);
}


void
on_delev_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 event e;
 GtkWidget *num_ev;
 GtkWidget *activ_edit;
 GtkWidget *output;



 activ_edit=lookup_widget(objet,"activ_edit");
 num_ev=lookup_widget(objet,"numedev");
 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));spacex(e.num);
 suppev(e.num);
}


void
on_deals_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *Admin;

 deals=lookup_widget(objet,"deals");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(deals);
}

void
on_deals_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *deals_add;

 deals=lookup_widget(objet,"deals");
 deals_add=create_deals_add();

 gtk_widget_show(deals_add);
 gtk_widget_destroy(deals);
}


void
on_deals_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *deals_edit;

 deals=lookup_widget(objet,"deals");
 deals_edit=create_deals_edit();

 gtk_widget_show(deals_edit);
 gtk_widget_destroy(deals);
}


void
on_editdeal_return_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *deals_edit;

 deals_edit=lookup_widget(objet,"deals_edit");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
 gtk_widget_destroy(deals_edit);
}


void
on_editdeal_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 offre o;
  GtkWidget *deals;
 GtkWidget *e1;
 GtkWidget *e2;
 GtkWidget *e3;
 GtkWidget *output;



 deals=lookup_widget(objet,"deals_edit");

 e1=lookup_widget(objet,"numeddl");
 e2=lookup_widget(objet,"deseddl");
 e3=lookup_widget(objet,"preddl");



 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));spacex(o.nbre);
 strcpy(o.description,gtk_entry_get_text(GTK_ENTRY(e2)));spacex(o.description);
 strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(e3)));spacex(o.prix);
 suppof(o.nbre);
 ajout_of(o);
}


void
on_suppdeal_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{offre o;
GtkWidget *deals;
 GtkWidget *e1;
deals=lookup_widget(objet,"deals_edit");
 e1=lookup_widget(objet,"numeddl");
 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));spacex(o.nbre);
 suppof(o.nbre);
}

void
on_button200_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 offre o;
  GtkWidget *deals;
 GtkWidget *e1;
 GtkWidget *e2;
 GtkWidget *e3;
 GtkWidget *output;



 deals=lookup_widget(objet,"deals_add");

 e1=lookup_widget(objet,"numaddl");
 e2=lookup_widget(objet,"desaddl");
 e3=lookup_widget(objet,"praddl");



 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));spacex(o.nbre);
 strcpy(o.description,gtk_entry_get_text(GTK_ENTRY(e2)));spacex(o.description);
 strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(e3)));spacex(o.prix);
 if (existof(o.nbre)!=1)
 ajout_of(o);
}


void
on_button201_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *deals_add;

 deals_add=lookup_widget(objet,"deals_add");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
 gtk_widget_destroy(deals_add);
}



void
on_button46_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *adhev;
GtkWidget *treeview501;	
adhev=create_adhev();
gtk_widget_show (adhev);

treeview501=lookup_widget(adhev,"treeview501");
afficher_event(treeview501);
}


void
on_button202_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *adinscev;
	adinscev=create_adinscev();
	gtk_widget_show (adinscev);
}


void
on_button204_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label563;
char msg1[60],msg2[60],num[20],id[20];
int s;
getcache(id);
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objet,"entry503");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objet,"label563");
s=annulation(id,num);
switch (s)
		{case 0 : {modif_nb1(num);
			   supression_part(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
}


void
on_button203_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label563;
char msg1[60],msg2[60],msg3[60],msg4[60],num[20],id[20];
int s;
getcache(id);
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
strcpy(msg4,"Veuillez entrer un numéro valide ." );
input1=lookup_widget(objet,"entry503");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(num);
output=lookup_widget(objet,"label563");
s=inscription(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb(num);
			   ajout_part(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		case -1 : {
			   gtk_label_set_text(GTK_LABEL(output),msg4);
		   	break;
		  	}
		}
}


void
on_ficheval_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	FILE*f,*f1;
	GtkWidget *input ;
	GtkWidget *input2 ;
	GtkWidget *input3;
	GtkWidget *output1;
	GtkWidget *spin4;
	GtkWidget *spin5;
	GtkWidget *spin6;
	GtkWidget *input7;
	
  char ide[20];char nom[20];
  char nom2[20];char nom4[20];char nom5[20];char nom6[20];
  char nom3[20];char nom7[20];
  char st1[20];char st2[20];
  char st3[20];char st4[20];
  char st5[20];char st6[20];
  char st7[20];
  int a,b,c;

	input=lookup_widget(objet,"fh1");
	input2=lookup_widget(objet,"fh2");
	input3=lookup_widget(objet,"fh3");
	spin4=lookup_widget(objet,"fhs4");
	spin5=lookup_widget(objet,"fhs5");
	spin6=lookup_widget(objet,"fhs6");		
	input7=lookup_widget(objet,"fh7");

	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));spacex(nom);
	strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(nom2);
	strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));spacex(nom3);
	strcpy(nom7,gtk_entry_get_text(GTK_ENTRY(input7)));spacex(nom7);
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin4));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin5));
	c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spin6));
	sprintf(nom4,"%d",a);
	sprintf(nom5,"%d",b);
	sprintf(nom6,"%d",c);
	
  
  
  f=fopen("fiches.txt","r+");
  f1=fopen("fiches1.txt","w+");
  
  if(f !=NULL) 
  { 
    while(fscanf(f,"%s %s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6,st7)!=EOF)
    {
		
     if ((strcmp(nom,st1)==0))	 
	{
	fprintf(f1,"%s %s %s %s %s %s %s\n",nom,nom2,nom3,nom4,nom5,nom6,nom7);
	}
     else 
     	fprintf(f1,"%s %s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6,st7);
    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("fiches.txt","w+");
  f1=fopen("fiches1.txt","r+");
    while(fscanf(f1,"%s %s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6,st7)!=EOF)
	fprintf(f,"%s %s %s %s %s %s %s\n",st1,st2,st3,st4,st5,st6,st7);


  fclose(f1);
  fclose(f);
  remove("fiches1.txt");
	
}


void
on_button28_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input ;
	GtkWidget *output1;
	GtkWidget *input2;
	GtkWidget *window1;
	GtkWidget *modfiche;
	
	char nom [50]; char ficha[1000];



input=lookup_widget(objet,"entry5");
output1=lookup_widget(objet,"label46");


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));spacex(nom);

if (verifier(nom)==-1)
	{ gtk_label_set_text(GTK_LABEL(output1),"Identifiant Introuvable ");}
else 
{
	//gtk_widget_hide(window1);
	modfiche=create_modfiche();
	gtk_widget_show(modfiche);
	//output2=lookup_widget(modfiche,"label572");
	input2=lookup_widget(modfiche,"fh1");
	//afficher(nom,ficha);
	gtk_widget_show(modfiche);
	gtk_entry_set_text(GTK_ENTRY(input2),nom);

	//gtk_label_set_text(GTK_LABEL(output2),ficha);
		
}
}


void
on_fichecherche_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{	
	FILE*f;
	GtkWidget *input ;
	GtkWidget *input2 ;
	GtkWidget *input3;
	GtkWidget *output1;
	GtkWidget *spin4;
	GtkWidget *spin5;
	GtkWidget *spin6;
	GtkWidget *input7;
	GtkWidget *window1;
	GtkWidget *modfiche;
	
	Fiche fi ;
	
	char nom [50]; char ficha[1000];
	int a,b,c;



input=lookup_widget(objet,"fh1");

spin4=lookup_widget(objet,"fhs4");
spin5=lookup_widget(objet,"fhs5");
spin6=lookup_widget(objet,"fhs6");





output1=lookup_widget(objet,"fichemsg");


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));spacex(nom);

if (verifier(nom)==-1)
	{ gtk_label_set_text(GTK_LABEL(output1),"Identifiant Introuvable ");}
else 
{
	f=fopen("fiches.txt" , "r");
if (f!=NULL)
{	while (fscanf(f,"%s %s %s %s %s %s %s\n" , fi.id ,fi.nom, fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies)!=EOF)
	{ if (strcmp(fi.id,nom)==0 )
		{
	a=atoi(fi.age);
	b=atoi(fi.poids);
	c=atoi(fi.taille);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin4),a);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin5),b);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6),c);
	input2=lookup_widget(objet,"fh2");
	input3=lookup_widget(objet,"fh3");
	input7=lookup_widget(objet,"fh7");
	gtk_entry_set_text(GTK_ENTRY(input2),fi.nom);
	gtk_entry_set_text(GTK_ENTRY(input3),fi.prenom);
	gtk_entry_set_text(GTK_ENTRY(input7),fi.maladies);
		}
	}
}
fclose(f);
		
}
}

void
on_button206_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *modifpass;
	char idd[20];
	//Login=lookup_widget(objet_graphique,"Login");
	modifpass=create_modifpass();
	gtk_widget_show(modifpass);

	getcache(idd);

}


void
on_button205_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *output;
	char nom[20];char mdp[20];
	char idd[20];
	FILE*f,*f1;
  char st1[20];char st2[20];
  char st3[20];

	input1=lookup_widget(objet,"entry504");
	input2=lookup_widget(objet,"entry505");
	output=lookup_widget(objet,"label576");

	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));spacex(nom);
	strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));spacex(mdp);

	if (strcmp(nom,mdp)==0)
	{
  
  f=fopen("users.txt","r+");
  f1=fopen("users1.txt","w+");
  getcache(idd);
  
  if(f !=NULL) 
  { 
    while(fscanf(f,"%s %s %s\n",st1,st2,st3)!=EOF)
    {
     if ((strcmp(idd,st1)==0))	 
	{
	fprintf(f1,"%s %s %s\n",st1,nom,st3);
	}
     else 
     	fprintf(f1,"%s %s %s\n",st1,st2,st3);
    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("users.txt","w+");
  f1=fopen("users1.txt","r+");
    while(fscanf(f1,"%s %s %s\n",st1,st2,st3)!=EOF)
	fprintf(f,"%s %s %s\n",st1,st2,st3);


  fclose(f1);
  fclose(f);
  remove("users1.txt"); 
  gtk_label_set_text(GTK_LABEL(output),"Modification réussie");

	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Les 2 saisies sont différentes !");
	}

	
}


void
on_button52_clicked                    (GtkWidget       *objger4,
                                        gpointer         user_data)
{
	GtkWidget *adh;
	GtkWidget *Login;

	rmcache();	
	adh=lookup_widget(objger4,"adh");
	gtk_widget_hide(adh);
	Login=create_Login();
	gtk_widget_show(Login);
	
}

