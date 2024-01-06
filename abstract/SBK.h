Konto *createSBK(Konto *konto);
Konto *close(Konto *konten);


Konto *close(Konto *konten) {
    size_t i;
    size_t j;
    float sumSoll = 0;
    float sumHaben = 0;
    float saldo;
    int n;
    int k;


    k = searchName(konten, "Kapital");

    if (k < 0) {
        printf("\nKonto Kapital wird erstellt!");
        konten = createKontenQuiet(konten, PASSIV, "Kapital");
        k = searchName(konten, "Kapital");
    } 

    konten = createSBK(konten);
    
    n = searchName(konten, "SBK");

    for (i = 1; i < reservedKonten && konten[i].kontenart != SBK && konten[i].amount > 0; i++) {
        if (i == k) {
            i++;
        }
        for (j = 0; j <= konten[i].amount && konten[i].amount > 0; j++) {
            sumSoll += konten[i].body[j].soll;
            sumHaben += konten[i].body[j].haben;
        }
        if (konten[i].kontenart == AKTIV) {
            saldo = sumSoll - sumHaben;
            book(&konten[n], &konten[i], saldo);
        } else if (konten[i].kontenart == PASSIV) {
            saldo = sumHaben - sumSoll;
            book(&konten[i], &konten[n], saldo);
        }

        sumSoll = 0;
        sumHaben = 0;
    }

    for (i = 0; i <= konten[i].amount && konten[i].amount > 0; i++) {
        sumSoll += konten[n].body[i].soll;
        sumHaben += konten[n].body[i].haben;
    }

    saldo = sumSoll - sumHaben;

    book(&konten[searchName(konten, "Kapital")], &konten[n], saldo);
    
    return konten;
}


Konto *createSBK(Konto *konto) {
    konto = (Konto*) realloc(konto, sizeof(Konto) * (reservedKonten + 1));
    __CHECK_NULL__(konto);

    initializerKonto(&konto[reservedKonten]);

    strcpy(konto[reservedKonten].name, "SBK");

    konto->kontenart = SBK;

    reservedKonten++;
    
    return konto;
}