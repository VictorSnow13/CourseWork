#include "tree.h"

char matrix[3][3];  
int step = 0; 

char check();
int check_space();
void init_matrix();
void get_player_move();
void get_computer_move();
void step_win(char m[3][3], int *ii, int *jj, int &step);
int check_step(char matrix[3][3]);
void disp_matrix();


int main()
{
    char done;
    
    printf("Tic-tac-toe game\n");
    printf("You will play against the computer\n");
    
    done =  ' ';
    int count[4]={0,0,0,0};
    char button = 'y';
    while(true){
        init_matrix(); 
        while(true){
            get_computer_move();
            disp_matrix();
            done = check(); 
            if(done!= ' ') break; 
            get_player_move();
            done = check();
            if(done != ' ') break;
        }
        
        count[0] ++;
        if(done=='O') {printf("You won!\n"); count[1]++;}
        else if(done == 'X') {printf("Computer won!\n"); count[2]++;}
        else {printf("\n\n\nDraw!\n"); count[3]++;}
        disp_matrix();
	printf("Score: You[%d] Computer[%d] draw [%d]\n", count[1], count[2], count[3]);        
	done= ' ';
        step = 0;
	printf("\nNext?\n");
	scanf("%c", &button);
        
        if(button == 'Y')
            step = 4;
        if(button == 'n') break;
   
    }

    return 0;
}

int check_step(char matrix[3][3]){
    int check = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3; j++)
            if(matrix[i][j]!=' ') check++;
    }
    return check;
}


void step_win(char m[3][3], int *ii, int *jj, int &step){
    
    
    if(step == 0){
        if(m[0][0] == 'O' || m[0][2] == 'O' || m[2][0] == 'O' || m[2][2] == 'O' ){
      
            if(m[0][0] == 'O') {*ii = 0; *jj = 2;return;}
            if(m[0][2] == 'O') {*ii = 0; *jj = 0;return;}
            if(m[2][0] == 'O') {*ii = 2; *jj = 2;return;}
            if(m[2][2] == 'O') {*ii = 2; *jj = 0;return;}
        }
        step = 2;
        if(m[0][1] == 'O') {*ii = 2; *jj = 0;return;}
        if(m[2][1] == 'O') {*ii = 0; *jj = 0;return;}
        if(m[1][0] == 'O') {*ii = 2; *jj = 2;return;}
        if(m[1][2] == 'O') {*ii = 0; *jj = 0;return;}
    }
    
    
    if(step == 1){ 
        if(check_step(m) == 4){
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[i][j]=='X'){
                        if((i == 0 && j == 0) ){if(m[2][2] == ' '){*ii = *jj = 2; return;}}  
                        else if(i == 2 && j == 2){if(m[0][0] == ' '){*ii = *jj = 0; return;}}  
                        else if (m[j][i] == ' '){*ii = j; *jj = i; return;}}
            
            for(int i = 0; i < 3; i = + 2)                  
                for(int j = 0; j < 3 ; j = j + 2){          
                    if(m[0][0] == 'O'){                     
                        if(m[0][2] == 'O'){ *ii = 0; *jj = 1; return;}  
                        else {*ii = 1; *jj = 0; return;}}
                    if(m[2][2] == 'O'){
                        if(m[0][2] == 'O'){ *ii = 1; *jj = 2; return;}
                        else {*ii = 2; *jj = 1; return;}}}}
        
        if(check_step(m) == 6 || check_step(m) == 8){
           
            if(m[0][1] == 'X') if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
            if(m[2][1] == 'X') if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
            if(m[1][0] == 'X') if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
            if(m[1][2] == 'X') if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}
            
            if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
            if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
            if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
            if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}
            
            for(int i = 0 ; i < 3 ; i++){           
                for(int j = 0 ; j < 3; j++)
                    if(m[i][j]==' ') {*ii = i; *jj = j;return;}}
        }
        
               if(check_step(m) == 8){
               if(m[0][1] == 'X') if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
               if(m[2][1] == 'X') if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
               if(m[1][0] == 'X') if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
               if(m[1][2] == 'X') if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}
                for(int i = 0 ; i < 3 ; i++){
                       for(int j = 0 ; j < 3; j++)
                         if(m[i][j]==' ') {*ii = i; *jj = j;return;}
                   }
                }
        
    }
    if(step == 2){
        if(check_step(m) == 4){  
            for(int i = 0; i < 3; i ++)
                for(int j = 0; j < 3 ; j ++){
                    if(m[0][0] == 'O'){
                        if(m[0][1] == 'O')if(m[0][2]==' '){ *ii = 0; *jj = 2; return;}
                        if(m[1][0] == 'O')if(m[2][0] == ' ') {*ii = 2; *jj = 0; return;}}
                    if(m[2][2] == 'O'){
                        if(m[1][2] == 'O') if(m[0][2] == ' '){ *ii = 0; *jj = 2; return;}
                        if(m[2][1] == 'O') if(m[2][0] == ' '){*ii = 2; *jj = 0; return;}}
                    if(m[0][2] == 'O'){
                        if(m[0][1] == 'O')if(m[0][0]==' '){ *ii = 0; *jj = 0; return;}
                        if(m[2][1] == 'O')if(m[2][2] == ' ') {*ii = 2; *jj = 2; return;}}
                    if(m[2][0] == 'O'){
                        if(m[1][0] == 'O') if(m[0][0] == ' '){ *ii = 0; *jj = 0; return;}
                        if(m[2][1] == 'O') if(m[2][2] == ' '){*ii = 2; *jj = 2; return;}}}
            
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[i][j]=='X'){
                        if((i == 0 && j == 0) ){if(m[2][2] == ' '){*ii = *jj = 2; return;}}  
                        else if(i == 2 && j == 2){if(m[0][0] == ' '){*ii = *jj = 0; return;}} 
                        else if (m[j][i] == ' '){*ii = j; *jj = i; return;}}
        }
       
        if(check_step(m) == 6){ 
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[0][0] == 'X'){
                        if(m[0][2] == 'X')if(m[0][1]==' '){ *ii = 0; *jj = 1; return;}
                        if(m[2][0] == 'X')if(m[1][0] == ' ') {*ii = 1; *jj = 0; return;}}
            if(m[2][2] == 'X'){
                if(m[0][2] == 'X') if(m[2][0] == ' '){ *ii = 2; *jj = 0; return;}
                if(m[2][0] == 'X') if(m[0][2] == ' '){*ii = 0; *jj = 2; return;}}
            if(m[0][2] == 'X'){
                if(m[0][0] == 'X')if(m[0][1]==' '){ *ii = 0; *jj = 1; return;}
                if(m[2][2] == 'X')if(m[1][2] == ' ') {*ii = 1; *jj = 2; return;}}
            if(m[2][0] == 'X'){
                if(m[0][0] == 'X') if(m[1][0] == ' '){ *ii = 1; *jj = 0; return;}
                if(m[2][2] == 'X') if(m[2][1] == ' '){*ii = 2; *jj = 1; return;}}
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[i][j]=='X'){
                        if((i == 0 && j == 0) ){if(m[2][2] == ' '){*ii = *jj = 2; return;}}
                        else if(i == 2 && j == 2){if(m[0][0] == ' '){*ii = *jj = 0; return;}}
                        else if (m[j][i] == ' '){*ii = j; *jj = i; return;}}}
    }
    
    
    
    if(step == 3){
        if(check_step(m) == 2){
            *ii = 2; *jj = 1; return;
        }
        if(check_step(m) == 4){
            if(m[1][1] == 'X'){
                if(m[0][1] == 'X') if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
                if(m[2][1] == 'X') if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
                if(m[1][0] == 'X') if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
                if(m[1][2] == 'X') if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}}
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[i][j]=='O'){
                        if((i == 0 && j == 0) ){if(m[2][2] == ' '){*ii = *jj = 2; return;}}
                        else if(i == 2 && j == 2){if(m[0][0] == ' '){*ii = *jj = 0; return;}}
                        else if (m[j][i] == ' '){*ii = j; *jj = i; return;}}}
        if(check_step(m) == 6 || check_step(m) == 8){
            for(int i = 0; i < 3; i = i + 2)
                for(int j = 0; j < 3 ; j = j + 2)
                    if(m[i][j]=='O'){
                        if((i == 0 && j == 0) ){if(m[2][2] == ' '){*ii = *jj = 2; return;}}
                        else if(i == 2 && j == 2){if(m[0][0] == ' '){*ii = *jj = 0; return;}}
                        else if (m[j][i] == ' '){*ii = j; *jj = i; return;}}
          
            if(m[1][1] == 'X'){
                if(m[0][1] == 'X') if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
                if(m[2][1] == 'X') if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
                if(m[1][0] == 'X') if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
                if(m[1][2] == 'X') if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}}
      
            if(m[2][1] == ' '){*ii = 2; *jj = 1;return;}
            if(m[0][1] == ' '){*ii = 0; *jj = 1;return;}
            if(m[1][2] == ' '){*ii = 1; *jj = 2;return;}
            if(m[1][0] == ' '){*ii = 1; *jj = 0;return;}
            
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 0 ; j < 3; j++)
                    if(m[i][j]==' ') {*ii = i; *jj = j;return;}}
        }
    }
    
}

void init_matrix()
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matrix[i][j] =  ' ';
}


void get_player_move()
{
    int x, y;
    
    printf("Enter X Y positions: ");
    scanf("%d %d", &x, &y);
    
    x--; y--;
    
    if(matrix[x][y]!= ' '){
        printf("You can not take this place\n");
        get_player_move();
    }
    else matrix[x][y] = 'O';
}

void get_computer_move()
{
    int ii = 0, jj = 0;
    int i, j;
    if(step != 4)
    if(matrix[1][1]== ' ') {matrix[1][1]= 'X'; return ;}
    else{
        for(i=0; i<3; i++){
            for(j=0; j<3; j++)
                if(matrix[i][j]==' ') break;
            if(matrix[i][j]==' ') break;

        }
        
        step_win(matrix, &ii, &jj, step);
        matrix[ii][jj] = 'X';
    }else{matrix[0][1]= 'X'; step --;return ;}

    
}


void disp_matrix()
{
    int t;
    
    for(t=0; t<3; t++) {
        printf(" %c | %c | %c ",matrix[t][0],
               matrix[t][1], matrix [t][2]);
        if(t!=2) printf("\n---|---|---\n");
    }
    printf("\n");
}


char check(void)
{
    int i;
    
    for(i=0; i<3; i++)  
        if(matrix[i][0]==matrix[i][1] &&
           matrix[i][0]==matrix[i][2]) return matrix[i][0];
    
    for(i=0; i<3; i++)  
        if(matrix[0][i]==matrix[1][i] &&
           matrix[0][i]==matrix[2][i]) return matrix[0][i];
    
 
    if(matrix[0][0]==matrix[1][1] &&
       matrix[1][1]==matrix[2][2])
        return matrix[0][0];
    
    if(matrix[0][2]==matrix[1][1] &&
       matrix[1][1]==matrix[2][0])
        return matrix[0][2];
    
    if(check_space() == 9)return 'S'; 
    else return ' ';
}

int check_space(){
    int check = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3; j++)
            if(matrix[i][j]==' ') return check;
            else check++;
    }
    return check;
}

