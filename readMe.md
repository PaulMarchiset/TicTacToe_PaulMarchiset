# Compte rendu projet <strong>TicTacToe</strong> Paul Marchiset

## Création du board

Pour dessiner le board où le jeu se déroulera, j'ai décidé de créer un tableau fixe rempli de 9 valeurs (1 à 9) ce qui me permet une meilleure aisance dans la navigation à travers ce dernier tout au long du jeu.

## Init des joueurs

J'utilise une structure pour créer mon/mes joueur(s). Je permets à l'utilisateur de rentrer son nom et le symbole qu'il désire, ce qui m'a posé quelques difficultés ensuite lorsque je devais vérifier si une case était libre ou non. J'ai trouvé une solution simple. Etant donné que mon board contient des valeurs numériques entre 1 et 9, j'ai juste à vérifier si le tableau contient une valeur entre 1 et 9.

## IA et améliorations

J'ai d'abord créé une IA qui place de manière aléatoire son symbole sur une case disponible. Je suis ensuite allé chercher les techniques pour gagner au TicTacToe et j'ai découvert par exemple qu'il fallait jouer le milieu en premier, puis les angles. Cette IA était déjà plus intéressante mais j'ai essayé de la perfectionner en regardant 2 choses : est-ce que le prochain move peut être gagnant si oui, alors j'essaie de me placer, sinon est ce que l'adversaire est en condition de victoire et donc comment le bloquer.