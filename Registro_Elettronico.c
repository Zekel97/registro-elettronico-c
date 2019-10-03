#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define puliscischermo printf("\f")

char car;
struct anagrafe{
                        char nome[30],cognome[30],spc[30],residenza[30],cdcfsc[17];
                        int matricola;
                        int gg,mm,aa;
                        int f;
        }dati;

struct anagrafectrl{
                        char nome[30],cognome[30],spc[30],residenza[30],cdcfsc[17];
                        int matricola;
                        int gg,mm,aa;
                        int f;
        }datictrl;

struct prove{
                        int matricola;
                        int materia;
                        float voto;
                        char tipo;
                        int gg,mm,aa;
        }prv;
        
struct provectrl{
                        int matricola;
                        int materia;
                        float voto;
                        char tipo;
                        int gg,mm,aa;
        }prvctrl;

struct assenze{
                        int matricola;
                        char tipo;
                        int durata;
                        int gg,mm,aa;
        }asnz;

struct specializzazione{
                        int cdmat;
                        char spec[30];
                        char mat[30];
        }spc;
        
struct specializzazionectrl{
                        int cdmat;
                        char spec[30];
                        char mat[30];
        }spctrl;

int menu(char flnm[10],int nr_stud);
//inizio funzioni per la gestione dell'anagrafe
int menu_anagr(char flnm[10],int nr_stud); //passo il nome del file scelto dall'utente, menu principale
int menu_out(char flnm[10],int nr_stud); //menu dell'output
void input(char flnm[10],int nr_stud); //input dei dati
void edit(char flnm[10],int nr_stud); //modifica dei dati
void delimina(char flnm[10],int nr_stud); //eliminazione dei dati
void sout(char flnm[10],int nr_stud); //single output, di un solo utente alla volta
void tout(char flnm[10],int nr_stud); //total output, di tutti gli utenti
//fine funzioni per la gestione dell'anagrafe

//inizio funzioni per la gestione dei voti e delle assenze
int menu_va(char flnm[10]); //menu
void voto_input(char flnm[10]); //input del voto
void voto_output_stud(char flnm[10]); //output per studente del voto
void voto_output_mat(char flnm[10]); //output per materia del voto
void assenza_input(char flnm[10]); //input dell'assenza
void assenza_modifica(char flnm[10]); //modifica dell'assenza
void assenza_output(char flnm[10]); //output per le assenze
//fine funzioni per la gestione dei voti e delle assenze

//inizio funzioni per la gestione delle materie
int menu_mat(char flnm[10]); //menu'
void input_materia(char flnm[10]); //input materia
void edit_materia(char flnm[10]); //edit materia
void del_materia(char flnm[10]); //eliminazione materia
//fine funzioni per la gestione delle materie

int controlloMateria(char flnm[10],int materia,int matricola); //controllo della materia dello studente

int main()
{
        char filename[10];
        int sc,sc_anagr,sc_va,scl,sc_mat,nr_stud=0;
        printf("\f");
        printf("_______________________________________________________________\n");
        do{
                 printf("|Inserire nome del file Anagrafe da aprire: [MAX 10 CARATTERI]|\n");
                 printf("| ");
                scanf("%s",filename);
        }while(strlen(filename)>10);
        printf("|_____________________________________________________________|\n");
        FILE *fp;
        fp=fopen(filename,"r+b");
        
                do
                {
                    if(fp!=NULL)
                    {
                        while(fread(&dati,sizeof(dati),1,fp))
                        {
                            nr_stud++;
                        }
                    }
                    
                        puliscischermo;
                        sc=menu(filename,nr_stud);
                        switch(sc)
                        {
                                case 1:
                                        do
                                        {
                                                if(fp!=NULL)
                                                {
                                                    while(fread(&dati,sizeof(dati),1,fp))
                                                    {
                                                        nr_stud++;
                                                    }
                                                }
                                                
                                                puliscischermo;
                                                sc_anagr=menu_anagr(filename,nr_stud);
                                                switch(sc_anagr)
                                                {
                                                    case 1: input(filename,nr_stud);
                                                            break;
                                                    case 2: edit(filename,nr_stud);
                                                            break;
                                                    case 3: delimina(filename,nr_stud);
                                                            break;
                                                    case 4:
                                                            do
                                                            {
                                                                if(fp!=NULL)
                                                                {
                                                                    while(fread(&dati,sizeof(dati),1,fp))
                                                                    {
                                                                        nr_stud++;
                                                                    }
                                                                }
                                                                
                                                                 puliscischermo;
                                                                 scl=menu_out(filename,nr_stud);
                                                                 switch(scl)
                                                                 {
                                                                        case 1: sout(filename,nr_stud);
                                                                                break;
                                                                        case 2: tout(filename,nr_stud);
                                                                                break;
                                                                 }
                                                            }while(scl!=0);
                                                            break;
                                                }
                                        }while(sc_anagr!=0);
                                        break;

                                case 2:
                                        do
                                        {
                                                if(fp!=NULL)
                                                {
                                                    while(fread(&dati,sizeof(dati),1,fp))
                                                    {
                                                        nr_stud++;
                                                    }
                                                }
                                                sc_va=menu_va(filename);
                                                puliscischermo;
                                                switch(sc_va)
                                                {
                                                        case 1: voto_input(filename);
                                                                break;
                                                        case 2: voto_output_stud(filename);
                                                                break;
                                                        case 3: voto_output_mat(filename);
                                                                break;
                                                        case 4: assenza_input(filename);
                                                                break;
                                                        case 5: assenza_output(filename);
                                                                break;
                                                }
                                        }while(sc_va!=0);
                                        break;

                                case 3:
                                        do
                                        {
                                                if(fp!=NULL)
                                                {
                                                    while(fread(&dati,sizeof(dati),1,fp))
                                                    {
                                                        nr_stud++;
                                                    }
                                                }
                                                
                                                sc_mat=menu_mat(filename);
                                                puliscischermo;
                                                switch(sc_mat)
                                                {
                                                        case 1: input_materia(filename);
                                                                        break;
                                                        case 2: edit_materia(filename);
                                                                        break;
                                                        case 3: del_materia(filename);
                                                                        break;
                                                }
                                        }while(sc_mat!=0);
                                        break;
                        }
                }while(sc!=0);
return 0;
}


int menu(char flnm[10],int nr_stud)
{
        int i;
        printf("  ____ \n");
        printf("-|MENU|-----%s:%d studenti----\n",flnm,nr_stud);
        printf("|\n");
        printf("| 1.Menu' Anagrafe \n");
        printf("| 2.Voti ed Assenze\n");
        printf("| 3.Materie e Corsi\n");
        printf("| 0.Esci\n");
        printf("|\n| ");
        do
        {
                scanf("%d",&i);
        }while(i<0 || i>3);
        printf("|_________________________________\n");
//        sleep(1);
        return i;
}

int menu_anagr(char flnm[10],int nr_stud)
{
        int i;
                printf("  _____________ \n");
        printf("-|MENU ANAGRAFE|----%s:%d studenti----\n",flnm,nr_stud);
        printf("|\n");
        printf("| 1.Inserimento dati\n");
        printf("| 2.Modifica dati\n");
        printf("| 3.Eliminazione dati\n");
        printf("| 4.Output\n");
        printf("| 0.Indietro\n");
        printf("|\n| ");
        do{
                scanf("%d",&i);
        }while(i<0 || i>4);
        printf("|_________________________________\n");
        
        return i;
}

int menu_out(char flnm[10],int nr_stud)
{
        int i;
                printf("  ______                  \n");
        printf("-|OUTPUT|---------%s:%d studenti------\n",flnm,nr_stud);
        printf("|\n");
        printf("| 1.Output Singolo\n");
        printf("| 2.Output Totale\n");
        printf("| 3.Output Range Studenti\n");
        printf("| 0.Indietro\n");
        printf("|\n| ");
        do{
                scanf("%d",&i);
        }while(i<0 || i>3);
        printf("|___________________\n");
        
        return i;
}


void input(char flnm[10],int nr_stud)
{
   char codiceFiscaleProvvisorio[17];
   int flag=0,scelta;

   FILE *fp;
   fp=fopen(flnm,"a+b");
   rewind(fp);

   printf("  _____ \n");
   printf("-|INPUT|------------%s:%d studenti------\n",flnm,nr_stud);
   printf("| Inserire la matricola:\n| ");
   scanf("%d",&dati.matricola);

   printf("| Inserire il nome:\n| ");
   scanf("%29s",dati.nome);

   printf("| Inserire il cognome:\n| ");
   scanf("%29s",dati.cognome);

   printf("| Inserire la residenza dello studente:\n| ");
   scanf("%29s",dati.residenza);

   printf("| Inserire la specializzazione:\n| ");
   scanf("%29s",dati.spc);

   printf("| Inserire l'anno di nascita:\n| ");
   scanf("%d",&dati.aa);

   printf("| Inserire il mese di nascita:\n| ");
   scanf("%d",&dati.mm);

   printf("| Inserire il giorno di nascita:\n| ");
   scanf("%d",&dati.gg);

    do{
                flag=0;
                printf("| Inserire il codice fiscale:\n| ");
                scanf("%17s",codiceFiscaleProvvisorio);
                while(fread(&datictrl,sizeof(datictrl),1,fp))
                {
                        if(strcmp(codiceFiscaleProvvisorio,datictrl.cdcfsc)==1)
                        {
                                printf(" _________________________ \n");
                                printf("|          ERRORE         |\n");
                                printf("|  Presente un duplicato  |\n");
                                printf("|   del codice fiscale    |\n");
                                printf("|                         |\n");
                                printf("| 1.Inserire di nuovo     |\n");
                                printf("| 2.Annullare l'input     |\n");
                                printf("|                         |\n");
                                do{
                                        printf("| ");
                                        scanf("%d",&scelta);
                                }while(scelta<1 || scelta>2);
                                switch(scelta)
                                {
                                        case 1: flag=1;
                                                        break;
                                        case 2: return;
                                }
                        break;
                        }
                }
    }while(flag!=0);
        
    strcpy(dati.cdcfsc,codiceFiscaleProvvisorio);
    printf("%s\n",dati.cdcfsc);
   dati.f=0;

   fwrite(&dati,sizeof(dati),1,fp);
   printf("|Studente salvato con successo!       |\n");
   printf("---------------------------------------\n");
   fclose(fp);
}

void edit(char flnm[10],int nr_stud)
{
     int matricola,flag=0,scelta;
     char codiceFiscaleProvvisorio[17];

     printf("  _______ \n");
     printf("-|RICERCA|----------%s:%d studenti--------\n",flnm,nr_stud);
     printf("| Matricola da ricercare:   \n|");
         scanf("%d",&matricola);
     FILE *fp;
     fp=fopen(flnm,"r+b");

        while(fread(&dati,sizeof(dati),1,fp))
           {
                if(dati.f==1)
                        {
                printf("| Studente cancellato      |\n");
                return;
                };

                if(matricola==dati.matricola)
                        {
                printf("---------------------------\n");
                printf("| Nuova matricola:        |\n| ");
                scanf("%d",&dati.matricola); scanf("%d",&dati.matricola);

                printf("| Nuovo nome:             |\n| ");
                scanf("%s",dati.nome);

                printf("| Nuovo cognome:          |\n| ");
                scanf("%s",dati.cognome);

                printf("| Inserire il codice fiscale:\n| ");
                scanf("%17s",dati.cdcfsc);

                printf("| Nuova residenza:        |\n| ");
                scanf("%s",dati.residenza);

                printf("| Nuova specializzazione: |\n| ");
                scanf("%s",dati.spc);

                printf("| Nuovo anno di nascita:  |\n| ");
                scanf("%d",&dati.aa);

                printf("| Nuovo mese di nascita:  |\n| ");
                scanf("%d",&dati.mm);

                printf("| Nuovo giorno di nascita:|\n| ");
                scanf("%d",&dati.gg);

                do{
                                        flag=0;
                                        printf("| Inserire il codice fiscale:\n| ");
                                        scanf("%17s",codiceFiscaleProvvisorio);
                                        while(fread(&datictrl,sizeof(datictrl),1,fp))
                                        {
                                                        if(strcmp(codiceFiscaleProvvisorio,datictrl.cdcfsc)==1)
                                                {
                                                        printf(" _________________________ \n");
                                                        printf("|          ERRORE         |\n");
                                                        printf("|  Presente un duplicato  |\n");
                                                        printf("|                         |\n");
                                                        printf("| 1.Inserire di nuovo     |\n");
                                                        printf("| 2.Annullare l'input     |\n");
                                                        printf("|                         |\n");
                                                        do{
                                                                printf("| ");
                                                                scanf("%d",&scelta);
                                                        }while(scelta<1 || scelta>2);
                                                        switch(scelta)
                                                        {
                                                                case 1: flag=1;
                                                                                break;
                                                                case 2: return;
                                                        }
                                                break;
                                                }
                                        }
                                }while(flag!=0);

                fseek(fp,-sizeof(dati), SEEK_CUR);

                fwrite(&dati,sizeof(dati),1,fp);
                printf("| Dati salvati!           |\n");
                printf("---------------------------\n");
                                printf("Inserire un tasto per continuare:\n");
                                getchar();getchar();
                fclose(fp);
                return;
                }

        }
        fclose(fp);
 }



void delimina(char flnm[10],int nr_stud)
{

  int matricola;

  printf("  ____________\n");
  printf("-|ELIMINAZIONE|----------%s:%d studenti----\n|\n",flnm,nr_stud);
  printf("| Matricola da ricercare : \n| ");
  scanf("%d",&matricola);

  FILE *fp;
  fp=fopen(flnm,"r+b");


  while(fread(&dati,sizeof(dati),1,fp))
  {
    if(matricola==dati.matricola)
    {

           dati.f=1;
           fseek(fp,-sizeof(dati),SEEK_CUR);
           fwrite(&dati,sizeof(dati),1,fp);
           printf("Studente cancellato\n");
           printf("|___________________|\n");
           fclose(fp);
           return;
      }

}
  fclose(fp);

}


void tout(char flnm[10],int nr_stud)
{
          printf("  _____________\n");
          printf("-|OUTPUT TOTALE|---------------------%s:%d studenti------------------------\n",flnm,nr_stud);

          FILE *fp;
          fp=fopen(flnm,"rb");// manca il controllo dell'input
          while(fread(&dati,sizeof(dati),1,fp))
          {
              
                       printf("__________________________________________________\n");
                       printf("| Studente cancellato (1=si/0=no) : %d\n",dati.f);
                       printf("| Matricola e' : %d\n",dati.matricola);
                       printf("| Nome e' : %s\n",dati.nome);
                       printf("| Cognome e' : %s\n",dati.cognome);
                       printf("| Risiede in :%s\n",dati.residenza);
                       printf("| Specializzazione :%s\n",dati.spc);
                       printf("| Codice Fiscale :%s\n",dati.cdcfsc);
                       printf("| Nato nel :%d ,nel mese :%d ,nel giorno :%d\n",dati.aa,dati.mm,dati.gg);
                       printf("___________________________________________________\n\n");
                       scanf("%c",&car);

          }
          printf("Premere un tasto per continuare:\n");
          getchar(); getchar();
          fclose(fp);
}

void sout(char flnm[10],int nr_stud)
{
             int matricola;
        	 printf("  ______________ \n");
             printf("-|OUTPUT SINGOLO|-----%s:%d studenti----------------------------|\n",flnm,nr_stud);
             printf("| Inserire la matricola dello  studente da ricercare :    |\n| ");
             scanf("%d",&matricola);
             FILE *fp;
             fp=fopen(flnm,"rb");
             while(fread(&dati,sizeof(dati),1,fp))
            {

                    if(matricola==dati.matricola)
                    {
                       printf("__________________________________________________\n");
                       printf("| Studente cancellato (1=si/0=no) : %d\n",dati.f);
                       printf("| Matricola e' : %d\n",dati.matricola);
                       printf("| Nome e' : %s\n",dati.nome);
                       printf("| Cognome e' : %s\n",dati.cognome);
                       printf("| Risiede in :%s\n",dati.residenza);
                       printf("| Specializzazione :%s\n",dati.spc);
                       printf("| Nato nel :%d ,nel mese :%d ,nel giorno :%d\n",dati.aa,dati.mm,dati.gg);
                       printf("| Codice Fiscale :%s\n",dati.cdcfsc);
                       printf("__________________________________________________\n\n");

                                   printf("Premere un tasto per continuare:\n");
                               getchar(); getchar();

                       fclose(fp);
                       return;

                    }
              }
}

int menu_va(char flnm[10]) //menu
{
        int i;
                printf("  _________________\n");
        printf("-|MENU VOTI&ASSENZE|----%s----\n",flnm);
        printf("|\n");
        printf("| 1.Inserire un voto\n");
        printf("| 2.Output voto per studente\n");
        printf("| 3.Output voto per materia\n");
        printf("| 4.Inserire un'assenza\n");
        printf("| 5.Mostrare le assenze di uno studente\n");
        printf("| 0.Indietro\n");
        printf("|\n| ");
        do{
                scanf("%d",&i);
        }while(i<0 || i>5);
        printf("|_________________________________\n");
        
        return i;
}

void voto_input(char flnm[10]) //input del voto
{
	int mt;
    FILE *fp;
    fp=fopen("voti","a+b");
    rewind(fp);

    printf("  __________ \n");
    printf("-|INPUT VOTO|------------------\n|\n");
    printf("| Inserire matricola studente:\n| ");
    scanf("%d",&prv.matricola);
    do{
			printf("\n| Inserire il codice della materia:    |\n| ");
            scanf("%d",&prv.materia);
            mt=controlloMateria(flnm,prv.materia,prv.matricola);
            if(mt==0)
            {
                return;
            }
    }while(mt!=0);

    printf("|\n Inserire voto:\n| ");
    scanf("%f",&prv.voto);

    do{
        printf("\n| Inserire tipo di voto (G-rafico||P-ratico||O-rale):\n| ");
        scanf("%c",&prv.tipo);
    }while(prv.tipo!='o' &&  prv.tipo!='O' && prv.tipo!='p' && prv.tipo!='P' && prv.tipo!='g' && prv.tipo!='G');

    do{
                printf("| Inserire giorno:\n| ");
                scanf("%d",&prv.gg);
    }while(prv.gg<1 || prv.gg>31);

    do{
                printf("| Inserire mese:\n| ");
                scanf("%d",&prv.mm);
    }while(prv.mm<1 || prv.mm>12);

    do{
                printf("| Inserire anno per intero:\n| ");
                scanf("%4d",&prv.aa);
    }while(prv.aa<2000);

   fwrite(&prv,sizeof(prv),1,fp);

   printf("| Dati salvati!           |\n");
   printf("---------------------------\n");
   printf("Inserire un tasto per continuare:\n");
   getchar();getchar();
   fclose(fp);
   return;
}

void voto_output_stud(char flnm[10]) //output per studente del voto
{
             int matricola;
             printf("  ________________________ \n");
             printf("-|OUTPUT VOTO per studente|-----%s----------------------------------|\n",flnm);
             printf("| Inserire la matricola dello studente da ricercare :    |\n| ");
             scanf("%d",&matricola);
             FILE *fp,*speci;
             fp=fopen("voti","rb");
             speci=fopen("materie","rb");
             while(fread(&prv,sizeof(prv),1,fp))
             {

                    if(matricola==prv.matricola)
                    {
                         while(fread(&spc,sizeof(spc),1,speci))
                         {
                              if(prv.materia==spc.cdmat)
                              {
                                  break;
                              }
                         }
                        
                       printf("__________________________________________________\n");
                       printf("| Codice materia: %d\n",prv.materia);
                       printf("| Nome materia: %s\n",spc.mat);
                       printf("| Voto: %2f\n",prv.voto);
                       printf("| Tipo: %c\n",prv.tipo);
                       printf("| Data: %d/%d/%d \n",prv.gg,prv.mm,prv.aa);
                       printf("__________________________________________________\n\n");
                    }
             }
             printf("Premere un tasto per continuare:\n");
                    getchar(); getchar();

             fclose(fp);
             return;
}

void voto_output_mat(char flnm[10]) //output per materia del voto
{
             int materia;
             printf("  ________________________ \n");
             printf("-|OUTPUT VOTO per materia|-----%s----------------------------------|\n",flnm);
			 printf("| Inserire il codice della materia da ricercare :    |\n| ");
             scanf("%d",&materia);
             FILE *fp;
             fp=fopen("voti","rb");
             while(fread(&prv,sizeof(prv),1,fp))
            {

                    if(materia==prv.materia)
                    {
                       printf("__________________________________________________\n");
                       printf("| Matricola: %d\n",prv.matricola);
                       printf("| Voto: %2f\n",prv.voto);
                       printf("| Tipo: %c\n",prv.tipo);
                       printf("| Data: %d/%d/%d \n",prv.gg,prv.mm,prv.aa);
                       printf("__________________________________________________\n\n");
                    }
            }
            printf("Premere un tasto per continuare:\n");
                    getchar(); getchar();

            fclose(fp);
            return;
}

void assenza_input(char flnm[10]) //input dell'assenza
{
        FILE *fp;
    fp=fopen("assenze","a+b");
    rewind(fp);

    printf("  _____________ \n");
    printf("-|INPUT ASSENZE|-------------%s-----\n|\n",flnm);
    printf("| Inserire matricola studente:\n| ");
    scanf("%d",&asnz.matricola);

    do{
        printf("| Inserire tipo assenza (A-ssenza || U-scita anticipata):\n| ");
        scanf("%c",&asnz.tipo);
    }while(asnz.tipo!='a' && asnz.tipo!='A' && asnz.tipo!='u' && asnz.tipo!='U');

    do{
                printf("| Inserire durata assenza (MAX-6h || MIN-1h)\n| ");
                scanf("%d",&asnz.durata);
    }while(asnz.durata<1 || asnz.durata>6);

    do{
                printf("| Inserire giorno:\n| ");
                scanf("%d",&asnz.gg);
    }while(asnz.gg<1 || asnz.gg>31);

    do{
                printf("| Inserire mese:\n| ");
                scanf("%d",&asnz.mm);
    }while(asnz.mm<1 || asnz.mm>12);

   do{
                printf("| Inserire anno per intero:\n| ");
                scanf("%4d",&asnz.aa);
   }while(asnz.aa<2000);

   fwrite(&asnz,sizeof(asnz),1,fp);

   printf("| Dati salvati!           |\n");
   printf("---------------------------\n");
   printf("Inserire un tasto per continuare:\n");
   getchar();getchar();
   fclose(fp);
   return;
}

void assenza_output(char flnm[10]) //output per le assenze
{
                        int matricola;
             printf("  ______________ \n");
             printf("-|OUTPUT ASSENZA|-----%s----------------------------------|\n",flnm);
             printf("| Inserire la matricola dello studente da cercare :    |\n| ");
             scanf("%d",&matricola);
             FILE *fp;
             fp=fopen("assenze","rb");
             while(fread(&asnz,sizeof(asnz),1,fp))
            {

                    if(matricola==asnz.matricola)
                    {
                           printf("__________________________________________________\n");
                       printf("| Tipo di assenza: %c\n",asnz.tipo);
                       printf("| Durata assenza: %dh\n",asnz.durata);
                       printf("| Data dell'assenza: %d/%d/%d\n",asnz.gg,asnz.mm,asnz.aa);
                       printf("__________________________________________________\n\n");
                    }
            }
            printf("Premere un tasto per continuare:\n");
                    getchar(); getchar();

            fclose(fp);
            return;
}

int menu_mat(char flnm[10]) //menu'
{
        int i;
                printf("  ____________\n");
        printf("-|MENU MATERIE|----%s----\n",flnm);
        printf("|\n");
        printf("| 1.Inserire una materia\n");
        printf("| 2.Modificare una materia\n");
        printf("| 3.Eliminare una materia\n");
        printf("| 0.Indietro\n");
        printf("|\n| ");
        do{
                scanf("%d",&i);
        }while(i<0 || i>3);
        printf("|_________________________________\n");
        
        return i;
}

void input_materia(char flnm[10]) //input materia
{
    int mater,scelta,flag;
    FILE *fp;
    fp=fopen("materie","a+b");
    rewind(fp);

    printf("  _____________ \n");
    printf("-|INPUT MATERIE|---------%s---------\n|\n",flnm);

	
    printf("| Inserire nome materia:\n| ");
    scanf("%s",spc.mat);

    printf("| Inserire Specializzazione della materia:\n| ");
    scanf("%s",spc.spec);
    
    do{
        flag=0;
        printf(" | Inserire codice materia:\n| ");
        scanf("%d",&mater);
        while(fread(&spctrl,sizeof(spctrl),1,fp))
        {
            if(mater==spctrl.cdmat)
            {
                printf(" _________________________ \n");
                printf("|          ERRORE         |\n");
                printf("|  Presente un duplicato  |\n");
                printf("|                         |\n");
                printf("| 1.Inserire di nuovo     |\n");
                printf("| 2.Annullare l'input     |\n");
                printf("|                         |\n");
                do{
                    printf("| ");
                    scanf("%d",&scelta);
                }while(scelta<1 || scelta>2);
                switch(scelta)
                {
                    case 1: flag=1;
                             break;
                    case 2: return;
                }
            break;
            }
        }
    }while(flag!=0);
    spc.cdmat=mater;

   fwrite(&spc,sizeof(spc),1,fp);

   printf("| Dati salvati!           |\n");
   printf("---------------------------\n");
   printf("Inserire un tasto per continuare:\n");
   getchar();getchar();
   fclose(fp);
   return;
}

void edit_materia(char flnm[10]) //edit materia
{
     int materia;
     printf("  ________________ \n");
     printf("-|MODIFICA MATERIA|----------%s--------\n",flnm);
     printf("| Codice Materia da ricercare:   \n| ");
         scanf("%d",&materia);
     FILE *fp;
     fp=fopen("materie","r+b");
     rewind(fp);

        while(fread(&spc,sizeof(spc),1,fp))
        {
                if(materia==spc.cdmat)
                {
                        printf("---------------------------\n");
                        printf("| Inserire nome materia:\n| ");
                        scanf("%s",spc.mat);

                        printf("| Inserire Specializzazione della materia:\n| ");
                        scanf("%s",spc.spec);

                        fseek(fp,-sizeof(spc), SEEK_CUR);

                        fwrite(&spc,sizeof(spc),1,fp);
                        printf("| Dati salvati!           |\n");
                        printf("---------------------------\n");

                        printf("Inserire un tasto per continuare:\n");
                        getchar();getchar();
                        fclose(fp);
                        return;
                }

        }
        fclose(fp);
}

void del_materia(char flnm[10]) //eliminazione materiaù
{
  int matricola;

  printf("  ____________________\n");
  printf("-|ELIMINAZIONE MATERIA|------------%s-------\n|\n",flnm);
  printf("| Matricola da ricercare : \n| ");
  scanf("%d",&matricola);

  FILE *fp;
  fp=fopen("materie","r+b");


  while(fread(&spc,sizeof(spc),1,fp))
  {
    if(matricola==dati.matricola)
    {

           dati.f=1;
           fseek(fp,-sizeof(spc),SEEK_CUR);
           fwrite(&spc,sizeof(spc),1,fp);
           printf("| Materia cancellata\n");
           printf("|____________________|\n");
           fclose(fp);
           return;
      }

	}	
  fclose(fp);
}

int controlloMateria(char flnm[10],int materia,int matricola)
{
    int scelta;
	FILE *voti,*anagr,*spe;
	voti=fopen("voti","r+b");
	anagr=fopen(flnm,"r+b");
	spe=fopen("materie","r+b");
    
	while(fread(&datictrl,sizeof(datictrl),1,anagr))
    {
		if(matricola==datictrl.matricola)
		{
			while(fread(&spctrl,sizeof(spctrl),1,spe))
			{
				if(strcmp(datictrl.spc,spctrl.spec)==0)
				{
					while(fread(&prv,sizeof(prv),1,voti))
					{
						if(spctrl.cdmat==prvctrl.materia)
						{
							return(1); //corrisponde la materia alla specializzazione
						}
					}
				}
			}
		}
	}

        printf(" _________________________ \n"); //messaggio d'errore semi-GUI
        printf("|          ERRORE         |\n");
        printf("|  Materia non presente   |\n");
        printf("|                         |\n");
        printf("| 1.Aggiungerla           |\n");
        printf("| 2.Annullare l'input     |\n");
        printf("|                         |\n");
        do{
            printf("| ");
            scanf("%d",&scelta);                //scelta se inserire o meno
        }while(scelta<1 || scelta>2);
        printf("|_________________________|\n");
        switch(scelta)
        {
            case 1: input_materia(flnm);        //conseguenze logiche
                    break;
            case 2: break;
        }
	return 0; //non corrisponde la materia alla specializzazione
}