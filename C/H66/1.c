#include <stdio.h>
#include <string.h>

// void f( double ){
//     printf("f");
// }

int main(){    
    char a[20]="cehiknqtw";
    char *s="fbla",*p;
    int i, j,z=1;
    for(p=s; *p; p++,z++) {
        printf("%s\n",p);
        j=0;
        while (*p>=a[j] && a[j]!='\0'){
            j++;
        }
        for(i=strlen(a); i>=j; i--){
            a[i+1] = a[i];
        }
        a[j]=*p;
        
        printf("%d=%s\n", z,a);
        
    }
    printf("%s", a);
    
    return 0;
}