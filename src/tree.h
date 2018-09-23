#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();
char check();
int check_space();
int check_step(char matrix[3][3]);
void step_win(char m[3][3], int *ii, int *jj, int *step);

#endif
