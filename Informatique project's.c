#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void singleplayer(int Min, int Max);
void twoPlayerMode();
void princi();
void customBornes();
void clearInputBuffer();
void savescore();
void viewscores();

#define SCORE_FILE "best_scores.txt"

void saveScore(const char* JoueurNom, int score) {
    FILE* file = fopen(SCORE_FILE, "a");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier des scores.\n");
        return;
    }
    fprintf(file, "%s %d\n", JoueurNom, score);
    fclose(file);
}

void viewscores()
{
FILE* file = fopen(SCORE_FILE, "r");
    if (file == NULL) {
        printf("Aucun score enregistré pour l'instant.\n");
        return;
    }
        char playerName[50];
    int score;
    printf("Scores enregistrés :\n");
    while (fscanf(file, "%s %d", playerName, &score) == 2) {
        printf("%s : %d coups\n", playerName, score);
    }
    fclose(file);
}

void bestScores(int score) {
    static int bestScore = -1;
    if (bestScore == -1 || score < bestScore) {
        bestScore = score;
        printf("Nouveau meilleur score: %d coups !\n", bestScore);
    } else {
        printf("Meilleur score actuel: %d coups.\n", bestScore);
    }
}


void clearInputBuffer() {
    while (getchar() != '\n');
}

void customBornes() {
    int min, max;
    printf("Veuillez entrer les bornes. Uniquement des entiers.\nEntrez la borne minimale: ");
    while(1){
    if (scanf("%d", &min) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre entier.\n min:");
        clearInputBuffer();
        continue;
    }
    printf("Entrez la borne maximale: ");
    if (scanf("%d", &max) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre entier.\n On reprend Avec le Min.\n");
        clearInputBuffer();
        continue;
    }
    if (min >= max) {
        printf("Intervalle invalide. La borne minimale doit être inférieure à la borne maximale.\n");
        continue;
    }
    if (min < max) {
        printf("Intervalle valide. La partie va commencer.\n");
        break;
    }
    }
    singleplayer(min, max);
}

void singleplayer(int Min, int Max) {
    int Nombremystere, choix, i = 1;
    char NomJoueur[50];
    
    printf("Entrez votre nom: ");
    scanf("%s", NomJoueur);

    srand(time(NULL));
    Nombremystere = (rand() % (Max - Min + 1)) + Min;
    printf("Veuillez alors tenter votre chance\n");

    while (1) {
        printf("Entrez un nombre entre %d et %d: ", Min, Max);
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez réessayer.\n");
            clearInputBuffer();
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
        } else if (choix == Nombremystere) {
            printf("Bravo, vous avez trouvé le nombre mystère en %d coups !\n", i);
            bestScores(i);
            saveScore(NomJoueur, i);
            break;
        }
        i++;
    }
}

void twoPlayerMode() {
    int Nombremystere = 0, choix = 0, i = 0;
    char J1[50], J2[50];
    
    printf("Joueur 1, entrez votre nom: ");
    scanf("%s", J1);
    printf("Joueur 2, entrez votre nom: ");
    scanf("%s", J2);

    printf("Veuillez alors saisir le nombre mystère: ");

    if (scanf("%d", &Nombremystere) != 1) {
        printf("Entrée invalide. Veuillez recommencer.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < 30; i++) printf("\n");
    printf("C'est au tour du Joueur 2 de deviner le nombre mystère.\n");

    while (1) {
        printf("Votre devinette : ");
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre.\n");
            clearInputBuffer();
            continue;
        }

        if (choix < Nombremystere) {
            printf("C'est plus grand !\n");
        } else if (choix > Nombremystere) {
            printf("C'est plus petit !\n");
        } else if (choix == Nombremystere) {
            printf("Bravo, vous avez trouvé le nombre mystère en %d coups !\n", i);
            break;
            savescore(J2,i);
        }
        }
        i++;
        
}

void princi() {
    int choice, choice2;

    do {
        printf("\t\t\t\tBienvenue.\n\nCe dernier consiste à vous faire deviner un nombre choisi au hasard par l'ordinateur.\nVeuillez choisir votre mode de jeu\n1- 1 joueur\n2- 2 joueurs\n3- Ajuster les Bornes\n4-Voir Scores des joueurs\n5-Meilleur Score\n6-Quitter\n");

        if (scanf("%d", &choice) != 1) {
            printf("Entrée invalide. Veuillez réessayer.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                do {
                    printf("Ok vous avez choisi le mode 1 joueur.\nChoisissez alors le niveau de difficulté.\n1- entre 1 et 100.\n2- entre 1 et 1000.\n3- entre 1 et 10000.\n4- Quitter.\n");

                    if (scanf("%d", &choice2) != 1) {
                        printf("Entrée invalide. Veuillez réessayer.\n");
                        clearInputBuffer();
                        continue;
                    }

                    switch (choice2) {
                        case 1:
                            printf("Ok Bonne chance.\n");
                            singleplayer(1, 100);
                            break;
                        case 2:
                            printf("Ok Bonne chance.\n");
                            singleplayer(1, 1000);
                            break;
                        case 3:
                            printf("Ok Bonne chance.\n");
                            singleplayer(1, 10000);
                            break;
                        case 4:
                            printf("Merci et au revoir.\n");
                            break;
                        default:
                            printf("Ceci ne correspond à aucune des propositions.\n\nVeuillez refaire votre choix ou quitter.\n");
                            break;
                    }
                } while (choice2 != 4);
                break;

            case 2:
                printf("Ok vous avez choisi le mode 2 joueurs.\n");
                printf("L'un des deux joueurs doit alors saisir la valeur du nombre mystère.\n");
                twoPlayerMode();
                break;
            case 3:
            customBornes();
                break;
            
            case 4:
             viewscores();
             break;
            
            case 5:
            bestScores();
            break;
            case 6:
                printf("Merci et au revoir.\n");
                break;

            default:
                printf("Ceci ne correspond à aucune des propositions.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    princi();
    return 0;
}
