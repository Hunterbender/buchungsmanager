int searchName(const Konto *konten, const char *name);
bool duplicate(const Konto *konten, const char *name);
Konto *createKontenQuiet(Konto *konten, const int kontenart, const char *name);

int searchName(const Konto *konten, const char *name) {
    size_t i = 0;
    

    while ((strcmp(konten[i].name, name) != 0) && (i <= reservedKonten + 1)) {
        i++;
    }

    if (i >= reservedKonten) {
        return -1;
    } else {
        return i;
    }
}

bool duplicate(const Konto *konten, const char *name) {
    size_t i = 0;
    size_t n = 0;

    
    while (i < 2 && n < reservedKonten) {
        if (strcmp(konten[n].name, name) == 0) {
            i++;
        }
        n++;
    }
     
    if (i >= 2) {
        return true;
    } else {
        return false;
    }
}

Konto *createKontenQuiet(Konto *konten, const int kontenart, const char *name) {


    if (konten->amount < 1) {
        konten->body = (Body*) malloc(sizeof(Body) * (konten->amount + 1));
    } else {
        konten->body = (Body*) realloc(konten->body, sizeof(Body) * (konten->amount));
    }

    //konten = (Konto*) realloc(konten, sizeof(Konto) * (reservedKonten + 1));
    __CHECK_NULL__(konten);
    initializerKonto(&konten[reservedKonten]);   
    strcpy(konten[reservedKonten].name, name);
    konten->kontenart = kontenart;
    reservedKonten++;

    return konten;
}
