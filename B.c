#include <stdio.h>
#include <string.h>

#define MAX_LEN 21

int main() {
    int casos, pessoas, i, j, k;
    char idiomas[100][100][MAX_LEN];
    
    scanf("%d", &casos);
    
    for (i = 0; i < casos; i++) {
        scanf("%d", &pessoas);
        
        for (j = 0; j < pessoas; j++) {
            scanf("%s", idiomas[i][j]);
        }
        
        int flag = 1;
        
        for (j = 0; j < pessoas; j++) {
            for (k = j + 1; k < pessoas; k++) {
                if (strcmp(idiomas[i][j], idiomas[i][k]) != 0) {
                    flag = 0;
                    break;
                }
            }
            
            if (!flag) {
                break;
            }
        }
        
        if (!flag) {
            printf("ingles\n");
        } else {
            printf("%s\n", idiomas[i][0]);
        }
    }
    
    return 0;
}