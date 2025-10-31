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
}

void display_pascal(struct data *Data_struct){
    char payload[500] ; 
    memset(payload, 0, sizeof(payload)) ; 
    int n = Data_struct->n ;
    for(int idx_row = 0 ; idx_row < n ; idx_row++){
        strcat(payload, "\r\n| "); 
        for(int idx_col = 0 ; idx_col < (idx_row+1) ; idx_col++){
            int value = 0 ;
            char chunck[10] ; 
            value = Data_struct->tab[idx_row][idx_col] ;
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
    pascal->n = 5 ; 
    pascal->tab = (int**) malloc(pascal->n*sizeof(int*)) ;
    init_pascal((struct data*)pascal) ;
    printf("\r\n Display Data : \r\n") ; 
    display_pascal((struct data*)pascal) ; 
    return 0 ; 
}