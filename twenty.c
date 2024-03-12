// twenty questions
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"

struct node* create_game_tree() { // bst given with questions and values given
    struct node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");

    return root;
}

void PlayGame(struct node* root) { // main play game method
    char user_answer;
    int guessPrinted = 0;
    while (root != NULL) {
        if (root->left == NULL) { // left is yes so if comp's guess is correct then it goes to the left
            if (!guessPrinted) {
                printf("%s\n", root->answer);
                guessPrinted = 1;
                printf("y/n: ");
                scanf(" %c", &user_answer);
                while (getchar() != '\n');
            }
            if (user_answer == 'y') {
                printf("I win!\n");
                return;
            }
            else {
                printf("You win!\n");
                return;
            }
        }
        if (root->right == NULL) { // right is no so if comp's guess is wrong then it goes to the right
            if (!guessPrinted) {
                printf("%s\n", root->answer);
                guessPrinted = 1;
                printf("y/n: ");
                scanf(" %c", &user_answer);
                while (getchar() != '\n');
            }
            if (user_answer == 'y') {
                printf("I win!\n");
                return;
            }
            else {
                printf("You win!\n");
                return;
            }
        }
        if (!guessPrinted) {
            printf("%s\n", root->question);
            printf("y/n: ");
            scanf(" %c", &user_answer);
            while (getchar() != '\n');
        }
        if (user_answer == 'y') {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}

int main()
{
    char c;
    struct node* game_tree = create_game_tree();
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    while (1) {
        scanf("%c", &c);
        while (getchar() != '\n');
        if (c == 'q') // user quits the game
        {
            break;
        }
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        PlayGame(game_tree);
        printf("Press 'q' to quit or any other key to continue:\n");
    }
    printf("Bye Bye!\n");
    free_tree(game_tree);
    return 0;

}
