void __CHECK_NULL__(const void* n);
void initializerBody(Body *body);
void initializerKonto(Konto *konto);
void book(Konto *soll, Konto *haben, float sum);

size_t reservedKonten = 0;

void book(Konto *soll, Konto *haben, float sum) {

    if (soll->amount < 1) {
        soll->body  = (Body*) malloc(sizeof(Body) * (soll->amount + 1));
    } else {
        soll->body  = (Body*) realloc(soll->body, sizeof(Body) * (soll->amount + 1));
    }

    if (haben->amount < 1) {
        haben->body = (Body*) malloc(sizeof(Body) * (haben->amount + 1));
    } else {
        haben->body = (Body*) realloc(haben->body, sizeof(Body) * (haben->amount + 1));
    }

    __CHECK_NULL__(soll->body);
    __CHECK_NULL__(haben->body);

    initializerBody(&soll->body[soll->amount]);
    initializerBody(&haben->body[haben->amount]);

    soll->body[soll->amount].soll = sum;
    haben->body[haben->amount].haben = sum;

    strcpy(soll->body[soll->amount].gegenkonto, haben->name);
    strcpy(haben->body[haben->amount].gegenkonto, soll->name);
    
    soll->amount++;
    haben->amount++;
}

void initializerKonto(Konto *konto) {
    konto->amount       = 0;
    konto->body         = NULL;
    konto->kontenart    = 0;
    strcpy(konto->name, "");
}

void initializerBody(Body *body) {
    strcpy(body->gegenkonto, "");
    body->soll = 0;
    body->haben = 0;
}

void __CHECK_NULL__(const void* n) {
    if (n == NULL) {
        printf("\nFehler bei der Speicherverwaltung!");
        printf("\nProgramm wird beendet!");
        exit(1);
    }
}
