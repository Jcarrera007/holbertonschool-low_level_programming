#include <stdio.h>

void print_name(char *name, void (*f)(char *)) {
    if (name && f) {
        f(name);  // Call the function pointed to by f, passing the name
    }
}

// Example of a function to be passed as the function pointer
void say_hello(char *name) {
    printf("Hello, %s!\n", name);
}

int main() {
    char *name = "John";
    
    // Call print_name with the say_hello function pointer
    print_name(name, say_hello);
    
    return 0;
}

