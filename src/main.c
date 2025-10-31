#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
    int n;  
    char *tab_char ; 
    int **tab ; 
} ; 

void init_pascal(struct data *Data) {
    int n = Data->n ; 
    int sup = n ;
    for(int idx_row = 0 ; idx_row < n ; idx_row++){
        Data->tab[idx_row] = (int*) malloc((idx_row+2)*sizeof(int*)) ; 
        for(int idx_col = 0 ; idx_col < (idx_row+1) ; idx_col++){
           Data->tab[idx_row][idx_col] = 0 ;  
        }
    }
    Data->tab[0][0] = 1 ; 
    Data->tab[1][0] = 1 ; 
    Data->tab[1][1] = 1 ; 
}

void calcul_pascal(struct data* pascal) {
    int n = pascal->n ; 
    for(int idx_row = 1 ; idx_row < (n-1) ; idx_row++){
        for(int idx_col = 0 ; idx_col < (idx_row + 2) ; idx_col++){
            if(idx_col == 0){
                pascal->tab[idx_row][idx_col] = 1 ; 
            }else{
                int left_val = pascal->tab[idx_row][idx_col-1] ; 
                int right_val = pascal->tab[idx_row][idx_col] ;
                int new_value = left_val + right_val ; 
                pascal->tab[idx_row+1][idx_col] = right_val + left_val ; 
            }
        }
    }
}
void display_pascal(struct data *Data_struct){
    char payload[500] ; 
    memset(payload, 0, sizeof(payload)) ; 
    int n = Data_struct->n ;
    for(int idx_row = 0 ; idx_row < (n-1) ; idx_row++){
        strcat(payload, "\r\n| "); 
        for(int idx_col = 0 ; idx_col < (idx_row+1) ; idx_col++){
            char chunck[10] ;
            memset(chunck, 0, 10) ;  
            int value = Data_struct->tab[idx_row][idx_col] ;
            sprintf(chunck, "%d", value) ;   
            strcat(payload, " ") ;
            strcat(payload, chunck) ;
            strcat(payload, " ") ;
        }
        strcat(payload, " |\r\n"); 
    }
    printf("Display Pascal : ") ; 
    printf("\r\n") ; 
    printf("%s", payload) ; 
    printf("\r\n") ;
}

int main(int argc, char *argv[]){
    struct data* pascal = (struct data*) malloc(1*sizeof(struct data)) ; 
    int n = 2 ; 
    printf("ENTER PASCAL : N = ") ; 
    scanf("%d", &n) ; 
    pascal->n = n+2 ; 
    pascal->tab = (int**) malloc(pascal->n*sizeof(int*)) ;
    init_pascal((struct data*)pascal) ;
    printf("\r\n Display Pascal Triangle For n = %d : \r\n", pascal->n) ; 
    calcul_pascal((struct data *)pascal) ; 
    display_pascal((struct data*)pascal) ; 
    return 0 ; 
}