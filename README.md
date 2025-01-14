# Computer-Science-project
# Jeu de Devinette - README

## Description
Ce programme est un jeu interactif dans lequel les joueurs doivent deviner un nombre mystère. Il propose deux modes de jeu :

1. **Mode Solo (1 joueur)** : L'ordinateur choisit un nombre mystère au hasard dans un intervalle défini.
2. **Mode Duo (2 joueurs)** : Un joueur entre un nombre mystère, et l'autre tente de le deviner.

## Fonctionnalités
### 1. Mode Solo
- L'ordinateur choisit un nombre mystère aléatoire.
- Le joueur peut choisir le niveau de difficulté :
  - Facile : nombre entre 1 et 100
  - Moyen : nombre entre 1 et 1000
  - Difficile : nombre entre 1 et 10 000
- Le joueur reçoit des indices (« plus grand » ou « plus petit ») jusqu'à ce qu'il trouve le nombre.

### 2. Mode Duo
- Le premier joueur entre un nombre mystère.
- L'écran est ensuite "nettoyé" pour cacher le nombre au second joueur.
- Le second joueur tente de deviner le nombre en recevant des indices.

### 3. Menu Principal
- Accédez à un menu qui permet de choisir :
  - Mode Solo
  - Mode Duo
  - Quitter le jeu

## Instructions d'Utilisation

### Compilation et Exécution
1. **Compilation** :
   - Utilisez un compilateur C, comme GCC.
   - Commande : `gcc -o jeu jeu.c`
2. **Exécution** :
   - Commande : `./jeu`

### Navigation dans le Programme
1. **Menu Principal** :
   - Choisissez un mode en entrant le chiffre correspondant :
     - `1` pour le Mode Solo
     - `2` pour le Mode Duo
     - `3` pour Quitter
   - Toute autre saisie affiche un message d'erreur et vous redirige vers le menu.

2. **Mode Solo** :
   - Sélectionnez un niveau de difficulté.
   - Entrez vos devinettes jusqu'à trouver le nombre mystère.

3. **Mode Duo** :
   - Le joueur 1 entre un nombre mystère.
   - Le joueur 2 tente de le deviner.

## Prérequis
- Un compilateur C (ég. GCC).
- Un terminal ou un IDE pour exécuter le programme.

## Structure du Code

### Fonctions Principales
- **`void singleplayer(int Min, int Max)`**
  - Gère le Mode Solo.
  - Génère un nombre mystère aléatoire et guide le joueur jusqu'à ce qu'il trouve le bon nombre.

- **`void twoPlayerMode()`**
  - Gère le Mode Duo.
  - Le joueur 1 entre un nombre mystère, et le joueur 2 tente de le deviner.

- **`void princi()`**
  - Point d'entrée principal du programme.
  - Affiche le menu principal et dirige vers les modes de jeu ou quitte le programme.

### Variables Importantes
- `Nombremystere` : Le nombre à deviner.
- `choix` : La saisie du joueur.
- `i` : Compteur pour le nombre de tentatives.

## Améliorations Possibles
- Ajouter un système de score pour mesurer les performances des joueurs.
- Enregistrer les meilleurs scores dans un fichier.
- Ajouter un mode multijoueur en réseau.

## Avertissements
- Assurez-vous que les entrées respectent les types attendus (ég., nombres entiers).
- Si des entrées invalides sont saisies, le programme demande une nouvelle tentative.

## Auteur
Ce programme a été conçu pour proposer un jeu de devinette simple et amusant, combinant apprentissage et divertissement.

