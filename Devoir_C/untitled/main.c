#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/*


 */
const char Messagederreur[]="Error! Could not open/found file\n";
void ChargerFichier (const char* stringFichier)
{
    char tligne[10000];
    int Ligneno= 0;
    FILE *FichierTransaction;

    FichierTransaction=fopen(stringFichier,"rt");
    if(FichierTransaction==NULL)
    {
        printf(Messagederreur);
        exit(-1);
    }
}
void* addItem(int LineNumber, char * TextLine)
{

}
void* removeItem(int LineNumber)
{

}
void*  loadFichier(const char* nomFichier)
{

}
void* executeFile(const char* nomFichier)
{

}
void* listesObjets(int debut, int fin)
{

}

void* LectureTransaction(char *stringFichier) {
    FILE *FichierTransaction;
    FILE *FicherCVS;
    char LocalFileHost[]="FichierCSV.c";
    char tampon[10000];
    char *transaction, *special;

    FichierTransaction = fopen(stringFichier, "r");
    if (FichierTransaction == NULL) {
        printf(Messagederreur);
        exit(-1);
    }
    fgets(tampon,10000,FichierTransaction);
    while (!feof(FichierTransaction))
    {
     transaction=strtok_r(tampon," ",&special);
     switch (transaction[0])
     {
         case 'a':
         case 'A':
         {
             int numeroligne=atoi(strtok_r(NULL," ",&special));
             char *lignetransaction = strtok_r(NULL,"\n",&special);
             addItem(numeroligne, lignetransaction);
             break;
         }
         case 'e':
         case 'E':
         {
            //Enlève une ligne dans la liste chaîné de pour l'enregistrement.
            int numeroligne = atoi(strtok_r(NULL,"-",&special));;
            removeItem(numeroligne);
            break;
         }
         case 'm':
         case 'M':
         {
            char *Transfereligne=strtok_r(NULL,"\n",&special);
            int numeroLigne=atoi(strtok_r(NULL," ",&special));
            break;
         }
         case 'l':
         case 'L':
         {
            int numDebut=atoi(strtok_r(NULL,"-",&special));
            int numFin=atoi(strtok_r(NULL," \r",&special));
            listesObjets(numDebut,numFin);

             break;
         }
         case 's':
         case 'S':
         {
             char *nomFichier = strtok_r(NULL," ",&special);
             break;
         }
         case 'x':
         case 'X':
         {
            char *nomFichier=strtok_r(NULL," ",&special);
            executeFile(nomFichier);
             break;
         }
         case 'o':
         case 'O':
         {
             char *nomFichier=strtok_r(NULL," ",&special);
             loadFichier(nomFichier);
             break;
         }
     }
    }
}

int main()
{
    pthread_t thread_id;
    char stringFichier[100000];
    printf("Veilliez entrer le nom du fichier : (100 000 caractères maximum)\n");
    scanf("%s",stringFichier);
    printf("%s", stringFichier);
    pthread_create(&thread_id, NULL, ChargerFichier, stringFichier);
    pthread_join(thread_id,NULL);
    ChargerFichier(stringFichier);
exit(0);
}
