#include <stdio.h>
#include <stdlib.h>


int main(){
    char storage[33];
    storage[0] = 123;
    printf("%p", &storage);
    return 0;
}