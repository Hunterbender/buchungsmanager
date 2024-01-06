void printBalanceSheet(const Konto *konten);
static void header(const char *name);
int menue(void);
int getch(void);
Konto *bookMGR(Konto *konten);
int searchName(const Konto *konten, const char *name); 


void printBalanceSheet(const Konto *konten) {
    size_t i;
    size_t j;
    size_t k;
    
    
    for (i = 0; i < reservedKonten; i++) {

        header(konten[i].name);

        for (j = 0; j < konten[i].amount; j++) {

            printf("%s", konten[i].body[j].gegenkonto);

            for (k = 0; k < 24 - strlen(konten[i].body[j].gegenkonto); k++) {
                printf(" ");
            }

            printf("%.2f", konten[i].body[j].soll);

            if (konten[i].body[j].soll >= 10000) {
                printf("\t");
            } else {
                printf("\t\t");
            }

            printf("%.2f", konten[i].body[j].haben);

            printf("\n");
        }
        printf("\n\n");
    }
}

Konto *bookMGR(Konto *konten) {
    char text[SIZE_CHAR];
    int posSoll;
    int posHaben;
    float sum;


    printf("\nName Soll Konto: ");
    scanf("%24s", text);

    posSoll = searchName(konten, text);

    if (posSoll < 0) {
        printf("\nKonto %s nicht gefunden", text);
        return konten;
    }

    printf("\nName Haben Konto: ");
    scanf("%24s", text);

    posHaben = searchName(konten, text);

    if (posHaben < 0) {
        printf("\nKonto %s nicht gefunden", text);
        return konten;
    }

    printf("\nBetrag: ");
    scanf("%f", &sum);   

    book(&konten[posSoll], &konten[posHaben], sum);

    return konten;
}

static void header(const char *name) {
    printf("\nKonto: %s", name);
    printf("\n\nGegenkonto\t\tSoll\t\tHaben\t\tKontenart\n\n");
}

int menue(void) {
    static bool ran = false;
    int n;


    if (!ran) {
        printf("\nEroeffnungsbillanz wird erstellt!");
        ran = true;
        return 0;
    } else if (ran) {
            printf("\nc: Clearscreen");
            printf("\nn: Neues Konto erstellen");
            printf("\n1: Buchung erstellen");
            printf("\n2: Billanz output");
            printf("\n3: SBK erstellen");
            printf("\nAuswahl: ");

        do {

            switch (getch())
            {
            
            case 'c':
                printf("c");
                n = (int)'c';
                break;

            case 'n':
                printf("n");
                n = (int) 'n';
                break;

            case '1':
                printf("1");
                n = 1;
                break;

            case '2':
                printf("2");
                n = 2;
                break;

            case '3':
                printf("3");
                n = 3;
                break;
            
            default:
                break;
            }
        } while ((n < 0 || n > 3) && n != 'c' && n != 'n');
    }
    return n;
}