#include<gtk/gtk.h>
#include<string.h>
#include"verifier.h"

int verif( char nom[], char pwd[])
{ 
 int a;
 FILE* f;
 char ch[30],ch1[30];
 f=fopen("users.txt","r");
 if(f!=NULL)
	{
 	 while((fscanf(f,"%s %s %d", ch, ch1,&a)!=EOF))
	 	 if((strcmp(nom,ch)==0)&&(strcmp(pwd,ch1)==0)&&(nom[0]!='-'))return(a);
	 fclose(f);
	}
 else return(0); 	
}
