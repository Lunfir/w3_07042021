#include <stdio.h>

typedef enum {
    apple   = 10,  // 0
    plum    = 23,   // 1
    cherry  = -12, // 2
    peach   = 34   // 3
} Fruits;

typedef enum {
    Ready,
    Processed,
    Crashed,
    Interrupted 
} STATE;

typedef enum {
    Highlighted = 1,    // 0001 1
    Clickable   = 2,    // 0010 2
    Toggle      = 4     // 0100 4
} UserActionFlags;

int main(int argc, char const *argv[])
{
    // 1
    int style = Highlighted | Clickable;

    printf("style: %d\n", style);

    if (style & Highlighted) {
        printf("HIGHLIGHED\n");
    }

    if (style & Clickable) {
        printf("CLICKABLE\n");
    } 

    // 2
    int state;
    scanf("%d", &state); 

    switch (state)
    {
        case Ready:
            printf("Ready\n");
            break;
        case Processed:
            printf("Processed\n");
            break;
        case Crashed:
            printf("Crashed\n");
            break;
        case Interrupted:
            printf("Interrupted\n");
            break;
        default:
            printf("Unknown state\n");
    }

    // 3
    Fruits fruit;

    fruit = cherry;

    printf("enum Fruits: %d\n", sizeof(Fruits));
    printf("fruit: %d\n", fruit);

    return 0;
}