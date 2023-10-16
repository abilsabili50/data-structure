#include <stdio.h>

int main(){
    int x;
    int *px;
    
    x = 10;
    px = &x;
    
    printf("Nilai dari variable x adalah %d\n", x);
    printf("Nilai dari variable px adalah %x\n", px);
    
    return 0;
}
