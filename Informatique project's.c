#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void princi();
void singleplayer(int Min,int Max);
void twoplayer();

void singleplayer(int Min,int Max)
{
    int Nombremystere,choix,i=1;
    srand(time(NULL));
    Nombremystere = (rand() % (Max - Min + 1)) + Min;
    printf("Veuillez alors tenter votre chance\n");
    while (1) {
        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Entrée invalide. Veuillez réessayer.\n");
            continue;
        }

        if (choix < Min || choix > Max) {
            printf("Veuillez bien respecter l'intervalle choisi (entre %d et %d).\n", Min, Max);
            continue;
        }

        if (choix < Nombremystere) {
            printf("Le nombre est plus grand.\n");
        } else if (choix > Nombremystere) {
            printf("Le nombre est plus petit.\n");
        } else {
            printf("Bravo, vous avez trouvé le nombre mystère en %d coups !\n", attempts);
            break;
        }
        i++;
    }
}

void twopl

void princi()
{
int choice,choice2;
do{
    printf("\t\t\t\tBienvenue dans mon magnifique programme.\n\nCe dernier consiste a vous faire deviner un nombre choisi au hasard par l'ordinateur.\nVeuillez choisir votre mode de jeu\n1- 1 joueur\n2- 2 joueurs\nOu\n3- Quitter\n");
    if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Entrée invalide. Veuillez réessayer.\n");
            continue;
    }
    switch(choice)
    {
  case 1:
        do{
        printf("Ok vous avez choisi le mode 1 joueur.\nChoississez alors le niveau de difficult%c.\n1- entre 1 et 100.\n2- entre 1 et 1000.\n3- entre 1 et 10000.\n4- Quitter.\n",130);
        if (scanf("%d", &choice2) != 1)
           {
            while (getchar() != '\n'); // Clear invalid input
            printf("Entrée invalide. Veuillez réessayer.\n");
            continue;
           }
        switch(choice2)
            {
            case 1:
                printf("Ok Bonne chance.\n");
                singleplayer(1,100);
                break;
            case 2:
                printf("Ok Bonne chance.\n");
                singleplayer(1,1000);
                break;
            case 3:
                printf("Ok Bonne chance.\n");
                singleplayer(1,10000);
                break;
            case 4:
                printf("Merci et aurevoir.\n");
                break;
                default:
                printf("Ceci ne correspond a aucune des propositions.\n\nVeuillez refaire votre choix ou quitter.");
                break;
            }
        }while(choice2!=4);
  break;
case 2:
    printf("Ok vous avez choisi le mode 2 joueurs.\n");
    printf("L'un des deux joueurs doit alors saisir la valeur du nombre mystère.\n");
    twoPlayerMode();
    break;

case 3:
    printf("Merci et au revoir.\n");
    break;

default:
    printf("Ceci ne correspond à aucune des propositions.\n");
    break;

    }

} while (choice != 3);
}    

int main()
{
    princi();
return 0;
}

