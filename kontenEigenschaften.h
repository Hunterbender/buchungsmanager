#include <stdlib.h>

#define AKTIV 1
#define PASSIV 2
#define AUFWAND 3
#define ERTRAG 4
#define GUV 5
#define EBK 6
#define SBK 7
#define SIZE_CHAR 24


typedef struct Body 
{
    float soll;
    float haben;
    char gegenkonto[SIZE_CHAR];
}Body;


typedef struct Konto
{
    unsigned int kontenart;
    char name[SIZE_CHAR];
    size_t amount;
    Body *body;
} Konto;