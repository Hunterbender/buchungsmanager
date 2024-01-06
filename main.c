//2021 - Ferdinand Fassbender
#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#include "kontenEigenschaften.h"
#include "fundation.h"
#include "IO.h"
#include "tools.h"
#include "./abstract/EBK.h"
#include "./abstract/SBK.h"
#include "./abstract/GuV.h"



int main(void) {
    Konto *konten = NULL;
    bool run = true;


    while (run) {
        switch (menue())
        {

        case 'c':
        
            system("cls");
            break;

        case 'n':
            konten = createKonten(konten);
            break;
        
        case 0:
            konten = createKonten(konten);
            break;

        case 1:
            konten = bookMGR(konten);
            break;
        
        case 2:
            printBalanceSheet(konten);
            break;

        case 3:
            konten = close(konten);
            break;
        
        default:
            break;
        }
    }
    return 0;
}