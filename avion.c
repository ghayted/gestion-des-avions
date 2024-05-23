#include <stdlib.h>
#include <stdio.h>
#include <string.h>
   typedef struct date{
   	int jj,mm,aa;
   }date;

   typedef struct avion{
     char matr[10];
     int place;
     char etat;
     date D;
     int nbr_vol;
     struct avion *suivant;
    }avion;
    
    avion *nv_avion (){
      avion *a;
          a=(avion*)malloc(sizeof(avion));
    	printf("Entrer le maticule de l avion : ");
    	scanf("%s",&a->matr);
        printf("Entrer le nombre de place : ");
    	scanf("%d",&a->place);
    	printf("Nombre de vols assures par l avion :");
    	scanf("%d",&a->nbr_vol);
    do{
		
    	printf("Si l avion a decolle tapez D \n"); 	
    	printf("Si l avion a Atterrit tapez A \n");  	
    	printf("Si l avion est en maintenance tachnique tapez M \n");
    	printf("Votre choix ? : ");
    	scanf("%s",&a->etat);
		}while (a->etat != 'D' && a->etat != 'A' && a->etat != 'M');
		do {
		
    	printf("annee -------------------- : ");
    	scanf("%d",&a->D.aa);
    	
		}while (a->D.aa>2023 || a->D.aa<1969);
    	return a;
	}           
 
   
    avion *AjoutDebut(avion *liste){
    	avion *a;
		a=nv_avion(a);
    	 a->suivant=liste;
    	liste=a;
    	return liste;
	}
	
	
	
    void affiche_avion(avion *liste ){
    	avion *a=liste;
    	int i=1;
    	if (liste==NULL){
    		printf("La liste est vide . \n");
		}else{
		while(a!= NULL){
		printf("\t\t----------------------------------\n");
		printf("\t\t  l avion %d :\n",i);
		i++;
    	printf("\t\tle maticule de l avion est : %s \n",a->matr);
    	printf("\t\tle nombre de place est : %d \n",a->place);
    	printf("\t\tle nombre de assuree par l'avion  est : %d \n",a->nbr_vol);

    	if(a->etat=='D'){
    		printf("\t\tl avion a decolle \n");
		}	if(a->etat=='A'){
    		printf("\t\tl avion a atterrit \n");
		}	if(a->etat=='M'){
    		printf("\t\tl avion est en maintenance technique \n");
		}
		printf("\t\tDate de lise en service: %d/%d/%d \n",a->D.jj,a->D.mm,a->D.aa);
		a=a->suivant;
		printf("\t\t----------------------------------\n");
		}
		}
	}
    
     avion *AjoutFin(avion *liste){
     	avion *a,*t;
     	
     	if(liste==NULL){
     		liste=AjoutDebut(liste);
     		return liste;
		 }
		 t=liste;
		 while (t->suivant!=NULL){
		 	t=t->suivant;
		 }
		 a=nv_avion(liste);
		 t->suivant=a;
		 a->suivant=NULL;
		 return liste;
	 }
    
   avion *ajoutPos(avion* liste, int pos) {
    avion *a;
    int i =1;
    avion * t = liste;
  
    if (pos==1) {
        return AjoutDebut(liste);
    }
    while (t != NULL) {
        if(i== pos-1) {
         break;
        }
        t = t->suivant;
        i++;
    }
    if (i==pos && t ==NULL){
    	return AjoutFin(liste);
	}
    if (t ==NULL ) {
printf("La position demandee depasse la taille de la liste.\n");
     return liste;
    }
    a=nv_avion(a);
    a->suivant = t->suivant;
    t->suivant = a;
    return liste;
}

    avion * tri_decroissant(avion *liste){
    	avion *a,*t,k;
   
    
    	if(liste==NULL){
    		printf("la liste est vide .\n");
    		return liste;
		}
		if(liste->suivant==NULL){
    		affiche_avion(liste);
    		return liste;
		}
    for(a=liste;a->suivant!=NULL;a=a->suivant){
    	for(t=a->suivant;t!=NULL;t=t->suivant){
    		if(a->place<t->place){
		
    	k.place=a->place;
    	strcpy(k.matr, a->matr);
    	k.etat=a->etat;
    	k.D.aa=a->D.aa;	
    	k.D.jj=a->D.jj;	
       	k.D.mm=a->D.mm;	
        k.nbr_vol=a->nbr_vol;
    	
    		
      	a->place=t->place;
    	strcpy(a->matr, t->matr);
    	a->etat=t->etat	;
        a->D.aa=t->D.aa;
        a->D.mm=t->D.mm;
        a->D.jj=t->D.jj;
        a->nbr_vol=t->nbr_vol;
        


    	t->place=k.place;
    	strcpy(t->matr, k.matr);
        t->etat=k.etat;
        t->D.aa=k.D.aa;
        t->D.mm=k.D.mm;
	    t->D.jj=k.D.jj;
        t->nbr_vol=k.nbr_vol;      
    		 
			}
		}
	}
  affiche_avion(liste);
		return liste;
	}
    
    avion *supDebut(avion *liste){
    	if(liste==NULL ){
    		printf("la liste est vide .");
    		return liste ;
		}
    	avion *a=liste;
    	liste=a->suivant;
    	free(a);
    	return liste;
	}
    
    avion *supFin(avion *liste){
    	if(liste==NULL ){
    		printf("la liste est vide .");
    		return liste ;
		}
    	avion *a=liste,*t;
    	if(a->suivant==NULL){
    		liste=NULL;
    		free (a);
    		return liste;
		}
    	while (a->suivant->suivant!=NULL){
    		a=a->suivant;
		}
       t=a->suivant;
       a->suivant=t->suivant;    
       free(t);
       return liste;
}






    avion *supPos (avion *liste,int pos){
    	if(liste==NULL){
    		printf("la liste est vide .");
    		return liste;
		}if(pos==1){
			liste=supDebut(liste);
				printf("l'elelment est supprimer avec succee . \n");
			return liste;
		}
		int i=1;
		avion *a=liste,*t;
		while (a!=NULL){
			if(i==pos-1){
				break;
			}
			a=a->suivant;
			i++;
		}
		if(a==NULL){
			printf("position superieur a la taille de la liste .");
			return liste;
		}else{
			t=a->suivant;
			a->suivant=t->suivant;
			free (t);
			printf("l'elelment a la position %d est supprimer avec succee . ",pos);
			return liste;
		}
		
	}
	
	
	
    
    avion *supMat(avion *liste , char mat[]){
    	if (liste==NULL){
    		printf ("la liste est vide .");
    		return liste;
		}
		avion *a=liste;
		int k=0,pos=0;                                                                            
		while (a!=NULL){
			if (strcmp(a->matr,mat)==0){
				k=1;
				break;
			}
			a=a->suivant;
			pos++;
		}
		if(k==1){
			liste=supPos(liste,pos);
			return liste;
		}if(k==0){
			printf("Matricule introuvable .");
			return liste;
		}
	}
       
       int verifie(avion *liste,char mat[]){
       avion *a=liste;
	   int k=0,t;	   
		while(a!=NULL){
			if (strcmp(a->matr,mat)==0){
				k=1;
				if(a->etat=='A' || a->etat=='M'){
				
					return 0;
				}else{
			
				return 1;
				}
			}
			a=a->suivant;
		}   
		if(k==0){
			return -1;
		}
  }
    
    int nbr_avion(avion *liste){
    	avion *a=liste;
    	int nbr=0	;
    	if(liste==NULL){
    		return -1;
		}
		while (a!=NULL){
			nbr++;
			a=a->suivant;
		}
		return nbr;
	}
    
    avion *supAge(avion *liste){
    	avion *a=liste;
    	int pos=1;
    	if (liste== NULL){
    		printf("la liste est vide . ");
    		return liste;
		}
    	while (a!=NULL){
    		if(2023-a->D.aa>=20 || a->etat=='M'){
    			liste=supPos(liste,pos);
    		pos--;
			}
			pos++;
			a=a->suivant;
		}
		return liste;
	}
    //QUESTION 9 10 11 12 
    void affiche_pourcentage(avion *liste){
    	avion *a=liste;
    	int D=0,A=0,M=0;
    	float pD,pA,pM;
    	int total;
    	total=nbr_avion(liste);
    
     while(a!=NULL){
	 
    		if(a->etat=='D'){
    			D++;
			}	if(a->etat=='A'){
    		    A++;
			}	if(a->etat=='M'){
    			M++;
			}
			a=a->suivant;
		}
		pD=(100*D)/total;
		pA=(100*A)/total;
		pM=(100*M)/total;
		printf("le nombres des avions decolles est : %d avion \n",D);
		printf("les nombres des avions atterits est : %d avion \n",A);
		printf("les nombres des avions en maintenance technique est : %d avion \n",M);
		printf("il ya %.2f POURCENT avions decolle .\n",pD);
		printf("il ya %.2f POURCENT avions atterit .\n",pA);
		printf("il ya %.2f POURCENT avions en maintenace technique .\n",pM);

	}
    
     void affiche_minVol(avion *liste){
     	avion *a=liste,*b;
     	avion *t;
     	b=a;
     	if(liste == NULL){
     		printf("la liste est vide .");
		 }else{
		 
		
     	   int min;
     	   int k=0;
     	   min=a->nbr_vol; 
     	   a=a->suivant;
     	   t=a;
        while(a!=NULL){
        	if(2023-t->D.aa<=10 && t->nbr_vol<min ){
        		k=1;
        		min=t->nbr_vol;
        		t=a;
			}
				a=a->suivant;
		}
		if(k==1){
	
		printf("\t\t----------------------------------\n");
	
    	printf("\t\tle maticule de l avion est : %s \n",t->matr);
    	printf("\t\tle nombre de place est : %d \n",t->place);
    	printf("\t\tle nombre de assuree par l'avion  est : %d \n",t->nbr_vol);

    	if(t->etat=='D'){
    		printf("\t\tl avion a decolle \n");
		}	if(t->etat=='A'){
    		printf("\t\tl avion a atterrit \n");
		}	if(t->etat=='M'){
    		printf("\t\tl avion est en maintenance technique \n");
		}
		printf("\t\tDate de lise en service: %d/%d/%d \n",t->D.jj,t->D.mm,t->D.aa);
		
		printf("\t\t----------------------------------\n");	
		}if(2023-b->D.aa<=10 && k==0   ){
			printf("\t\t----------------------------------\n");
	
    	printf("\t\tle maticule de l avion est : %s \n",b->matr);
    	printf("\t\tle nombre de place est : %d \n",b->place);
    	printf("\t\tle nombre de assuree par l'avion  est : %d \n",b->nbr_vol);

    	if(b->etat=='D'){
    		printf("\t\tl avion a decolle \n");
		}	if(b->etat=='A'){
    		printf("\t\tl avion a atterrit \n");
		}	if(b->etat=='M'){
    		printf("\t\tl avion est en maintenance technique \n");
		}
		printf("\t\tDate de lise en service: %d/%d/%d \n",b->D.jj,b->D.mm,b->D.aa);
		
		printf("\t\t----------------------------------\n");		
		}
		
	}
	 }
    
    
    
    
    
    void affiche_MaxVol(avion *liste){
     	avion *a=liste,*b;
     	avion *t;
     	b=a;
     	if(liste == NULL){
     		printf("la liste est vide .");
		 }else{
		 
		
     	   int max;
     	   int k=0;
     	   max=a->nbr_vol; 
     	   a=a->suivant;
     	   t=a;
        while(a!=NULL){
        	if(2023-t->D.aa<=10 && t->nbr_vol>max ){
        		k=1;
        		max=t->nbr_vol;
        		t=a;
			}
				a=a->suivant;
		}
		if(k==1){
	
		printf("\t\t----------------------------------\n");
	
    	printf("\t\tle maticule de l avion est : %s \n",t->matr);
    	printf("\t\tle nombre de place est : %d \n",t->place);
    	printf("\t\tle nombre de assuree par l'avion  est : %d \n",t->nbr_vol);

    	if(t->etat=='D'){
    		printf("\t\tl avion a decolle \n");
		}	if(t->etat=='A'){
    		printf("\t\tl avion a atterrit \n");
		}	if(t->etat=='M'){
    		printf("\t\tl avion est en maintenance technique \n");
		}
		printf("\t\tDate de lise en service: %d/%d/%d \n",t->D.jj,t->D.mm,t->D.aa);
		
		printf("\t\t----------------------------------\n");	
		}if(2023-b->D.aa<=10 && k==0   ){
			printf("\t\t----------------------------------\n");
	
    	printf("\t\tle maticule de l avion est : %s \n",b->matr);
    	printf("\t\tle nombre de place est : %d \n",b->place);
    	printf("\t\tle nombre de assuree par l'avion  est : %d \n",b->nbr_vol);

    	if(b->etat=='D'){
    		printf("\t\tl avion a decolle \n");
		}	if(b->etat=='A'){
    		printf("\t\tl avion a atterrit \n");
		}	if(b->etat=='M'){
    		printf("\t\tl avion est en maintenance technique \n");
		}
		printf("\t\tDate de lise en service: %d/%d/%d \n",b->D.jj,b->D.mm,b->D.aa);
		
		printf("\t\t----------------------------------\n");		
		}
		
	}
	 }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 int main (){
  avion *liste=NULL;
  int i,choix,pos;
  char mat[20];
  int valeur;
  int nbr;
  do{
  printf("\n");
  printf(" MENU : \n");
  printf("   \t-Ajouter au debut tapez 1 .\n");
  printf("   \t-Ajouter a la fin tapez 2 .\n");
  printf("   \t-Ajouter a une position tapez 3 .\n");
  printf("   \t-Afficher la liste tapez 4 .\n");
  printf("   \t-Afficher la liste dans un ordre decroissant tapez 5 .\n");
  printf("   \t-supprimer au debut tapez 6 .\n");
  printf("   \t-supprimer a la fin  tapez 7 .\n");
  printf("   \t-supprimer a une position tapez 8 .\n");
  printf("   \t-supprimer a l'aide d'un matricule tapez 9.\n");
  printf("   \t-verifier si l'avion est dans l'aeroport tapez 10 .\n");
  printf("   \t-Afficher le nombre d'avion la liste tapez 11 .\n");
  printf("   \t-supprimer les avions qui sont age plus de 20 ans et qui en sont maintenances tapez  12 .\n");
  printf("   \t-Afficher le porcentage tapez 13 .\n"); 
  printf("   \t-Afficher les avion qui ont le nombre minimal de vols et moins de 10 ans tapez 14 sinon tapez 15 .\n");
  printf("   \t-Quitter tapez 0.\n");
 
  printf("   \t-choix ? :");
  scanf ("%d",&choix);
  printf("\n");
  if(choix==1){
  	liste=AjoutDebut(liste);
  }if(choix==2){
  	liste=AjoutFin(liste);  
  }if(choix==3){
  	printf("Entrer une position : ");
  	scanf("%d",&pos);
  	liste=ajoutPos(liste,pos);
  	printf("\n");
  }if(choix==4){
  	affiche_avion(liste);
  	printf("\n");
  }if(choix==5){
  	liste=tri_decroissant(liste);
  	printf("\n");
  }if(choix==6){
  	liste=supDebut(liste);
  	printf ("Premier element est supprimer avec succee .");
  	printf("\n");
  }if(choix==7){
  	liste=supFin(liste);
  	printf ("le dernier element est suppprimer avec succe .");
  	printf("\n");
  }	if(choix==8){
  	printf("entrer une position sur la quelle vous voullez supprimer : ");
  	scanf("%d",&pos);
  	liste=supPos(liste,pos);
  }if(choix==9){
  	printf("entrer le matricule de l'avion a supprimer : ");
  	scanf("%s",&mat);
  	liste=supMat(liste,mat);
}if(choix==10){
  	printf("entrer le matricule de l'avion  : ");
  	scanf("%s",&mat);
  	valeur=verifie(liste,mat);
  	if(valeur==-1){
  		printf("matricule non trouve .");
	  }if(valeur== 0){
	  		printf("l avion #%s# est dans l'aeroport .",mat);
	  }if(valeur==1){
	  		printf("l avion #%s# n'est pas dans l'aeroport .",mat);
	  }
  }if(choix==11){
  	nbr=nbr_avion(liste);
  	if(nbr==-1){
	  printf("la liste est vide .");
	  }else{
	  	printf("il ya %d avion \n",nbr);
	  }
    }if(choix==12 ){
    	liste=supAge(liste);
	}if(choix==13 ){
    	affiche_pourcentage(liste);
	}if(choix==14 ){
    	affiche_minVol(liste);
	}if(choix==15 ){
    	affiche_MaxVol(liste);
	}
}while(choix!=0);
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
