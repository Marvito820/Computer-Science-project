#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void princi()
{
int choice,choice2;
do{
    printf("\t\t\t\tBienvenue dans mon magnifique programme.\n\nCe dernier consiste a vous faire deviner un nombre choisi au hasard par l'ordinateur.\nVeuillez choisir votre mode de jeu\n1- 1 joueur\n2- 2 joueurs\nOu\n3- Quitter\n");
    scanf("%d",&choice);
    switch(choice)
    {
  case 1:
    {
        do{
        printf("Ok vous avez choisi le mode 1 joueur.\nChoississez alors le niveau de difficult%c.\n1- entre 1 et 100.\n2- entre 1 et 1000.\n3- entre 1 et 10000.\n4- Quitter.\n",130);
        scanf("%d",&choice2);
        switch(choice2)
            {
            case 1:
                printf("Ok Bonne chance.\n");
                rh(1,100);
                break;
            case 2:
                printf("Ok Bonne chance.\n");
                rh(1,1000);
                break;
            case 3:
                printf("Ok Bonne chance.\n");
                rh(1,10000);
                break;
            case 4:
                printf("Merci et aurevoir.\n");
                break;
                default:
                printf("Ceci ne correspond a aucune des propositions.\n\nVeuillez refaire votre choix ou quitter.");
                break;
            }}while(choice2!=4);
            break;
    }
void rh(int Min,int Max)
{
    int Nombremystere,choix,i=1;
    srand(time(NULL));
    Nombremystere = (rand() % (Max - Min + 1)) + Min;
    printf("Veuillez alors tenter votre chance\n");
    scanf("%d",&choix);
    while(choix!=Nombremystere)
    {
        i++;

    if (choix<Nombremystere)
        {
            if(choix<Min){
        printf("Veuillez bien respecter l'intervalle choisi\n");
        scanf("%d",&choix);}

        if(choix>Max){
      printf("Veuillez bien respecter l'intervalle choisi\n");
      scanf("%d",&choix);}

         printf("Le nombre est au dessus de ce que vous avez saisi\n");
             scanf("%d",&choix);
        }
          else if(choix>Nombremystere)
            {
             printf("Le nombre est en dessous de ce que vous avez saisi\n");
               scanf("%d",&choix);
               }

}
    printf("Bravo, vous avez trouve le nombre mystere en %d coups\n",i);
    return 0;
}
