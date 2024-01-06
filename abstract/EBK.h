Konto *createKonten(Konto *konten);
Konto *createEBK(Konto *konto);
int getch(void);
Konto *createKontenQuiet(Konto *konten, const int kontenart, const char *name);

Konto *createKonten(Konto *konten) {
    int choice = 1;
    float sum;
    char n;
    static bool open = true;


    if (open) {
        //konten = createKontenQuiet(konten, EBK, "EBK");
        konten = createEBK(konten);
    }

    while (choice > 0) {

        konten = (Konto*) realloc(konten, sizeof(Konto) * (reservedKonten + 1));
        __CHECK_NULL__(konten);
        initializerKonto(&konten[reservedKonten]);
    
        printf("\nGib mir den Namen des Kontos: ");
        scanf("%24s", konten[reservedKonten].name);

        do {
            printf("\n1: Aktiv; 2: Passiv; 3: Aufwand; 4: Ertrag: ");
            n = getch(); 

            if (open && (n == '1' || n == '2')) {
                printf("\nEndbestand Konto %s: ", konten[reservedKonten].name);
                scanf("%f", &sum);
            } 

            switch (n) {

                case '1':
                    printf("1");
                    konten[reservedKonten].kontenart = AKTIV;
                    book(&konten[reservedKonten], &konten[0], sum);
                    break;

                case '2':
                    printf("2");
                    konten[reservedKonten].kontenart = PASSIV;
                    book(&konten[0], &konten[reservedKonten], sum);
                    break;

                case '3':
                    printf("3");
                    konten[reservedKonten].kontenart = AUFWAND;
                    break;
                
                case '4':
                    printf("4");
                    konten[reservedKonten].kontenart = ERTRAG;
                    break;

                default:
                    break;

            }

        } while (konten[reservedKonten].kontenart < AKTIV && konten[reservedKonten].kontenart > ERTRAG);

        
        do {
            printf("\nWeitere Konten hinzufuegen? 1 = Ja, 0 = Nein: ");
            n = getch(); 

            if (n == '1') {
                choice = 1;
                printf("1");
            } else if (n == '0') {
                choice = 0;
                printf("0");
            }

        } while (choice != 1 && choice != 0);
        

        reservedKonten++;
    }
    open = false;
    return konten;
}





Konto *createEBK(Konto *konto) {
    konto = (Konto*) malloc(sizeof(Konto) * (reservedKonten + 1));
    __CHECK_NULL__(konto);

    initializerKonto(&konto[0]);

    strcpy(konto[reservedKonten].name, "EBK");

    konto->kontenart = EBK;

    reservedKonten++;
    
    return konto;
}