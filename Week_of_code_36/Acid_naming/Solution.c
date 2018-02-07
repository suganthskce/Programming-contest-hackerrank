#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* acidNaming(char* acid_name) {
    // Complete this function
    int len = strlen(acid_name);
    if(len<2)
        return "not an acid";
    if(acid_name[len-2]=='i' && acid_name[len-1]=='c')
        if(acid_name[0]=='h' && acid_name[1]=='y' && acid_name[2]=='d' && acid_name[3]=='r' && acid_name[4]=='o')
            return "non-metal acid";
        else
            return "polyatomic acid";
    return "not an acid";
}

int main() {
    int n; 
    scanf("%i", &n);
    for(int a0 = 0; a0 < n; a0++){
        char* acid_name = (char *)malloc(512000 * sizeof(char));
        scanf("%s", acid_name);
        int result_size;
        char* result = acidNaming(acid_name);
        printf("%s\n", result);
    }
    return 0;
}
