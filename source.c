//Hanna Zipser
#include <stdio.h>
#include <stdlib.h>
//dodanie pierwszego wiersza
void AFR (int*** tablica, int w, int* wiersz, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy + 1) * sizeof(int*));
    *nowaTablica = malloc(w * sizeof(int));
    *ileWierszy+=1;

    int* noweDlgWierszy = malloc((*ileWierszy) * sizeof(int));

    int i;
    int pom;
    //przekopiowanie
    for (i = 0; i < *ileWierszy - 1; i++){
        *(nowaTablica + i + 1)= *(*(tablica) + i);
        *(noweDlgWierszy+i + 1)=*(*(dlgWierszy) + i);
    }

    *noweDlgWierszy = w;

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    for (i = 0; i < w; i++) {
         *(*(*tablica) + i) = *(wiersz + i);
    }

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;

}

//dodanie ostatniego wiersza
void ALR (int*** tablica, int w, int* wiersz, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy + 1) * sizeof(int*));
    *ileWierszy+=1;

    int* noweDlgWierszy = malloc((*ileWierszy) * sizeof(int));

    int i = 0;
    //przekopiowanie
    for (i = 0; i < *ileWierszy - 1; i++){
        *(nowaTablica + i )= *(*(tablica) + i);
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i);
    }

    int indeksOstatni = i;

    *(nowaTablica+ indeksOstatni) = malloc(w * sizeof(int));
    *(noweDlgWierszy + indeksOstatni) = w;

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;


    for (i = 0; i < w; i++) {
         *(*(*(tablica) + indeksOstatni) + i) = *(wiersz + i);
    }

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;

}
//dodanie pierwszej kolumny
void AFC(int*** tablica, int h, int* kolumna, int* ileWierszy, int** dlgWierszy){
   int i;
    for (i = 0; i < h; i++){
        if ( i < *ileWierszy){
           int dlg = *(*dlgWierszy + i) + 1;
           int* nowyWiersz = malloc( dlg * sizeof(int));
           int j;

           *(nowyWiersz) = *(kolumna+i);

            *(*dlgWierszy + i)+=1;
           //przekopowanie
            for ( j = 1; j < dlg ; j++){
                *(nowyWiersz + j) = *(*(*tablica + i) + j - 1);
            }

            free(*(*(tablica) + i));
            *(*(tablica) + i) = nowyWiersz;
        }else {//stworz wiersz
            ALR(tablica, 1, kolumna + i, ileWierszy, dlgWierszy);
        }
    }
}
//dodanie ostatniej kolumny
void ALC(int*** tablica, int h, int* kolumna, int* ileWierszy, int** dlgWierszy){
    int i;
    for (i = 0; i < h; i++){
        if ( i < *ileWierszy){
           int dlg = *(*dlgWierszy + i) + 1;
           int* nowyWiersz = malloc( dlg * sizeof(int));
           int j;
           //przekopowanie
            for ( j = 0; j < dlg -1; j++){
                *(nowyWiersz + j) = *(*(*tablica + i) + j );
            }
            *(nowyWiersz+j) = *(kolumna+i);

            *(*dlgWierszy + i)+=1;

            free(*(*(tablica) + i));
            *(*(tablica) + i) = nowyWiersz;
        }else {//stworz wiersz
            ALR(tablica, 1, kolumna + i, ileWierszy, dlgWierszy);
        }
    }
}
//wstawienie przed danym wierszem
void IBR(int*** tablica, int r, int w, int* wiersz, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy + 1) * sizeof(int*));

    int* noweDlgWierszy = malloc((*ileWierszy + 1) * sizeof(int));

    int i = 0;
    //przekopiowanie
    for (i = 0; i < r; i++){
        *(nowaTablica + i )= *(*(tablica) + i);
       // printf("tab: %d ",**(nowaTablica + i ));
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i);
        //printf("ile: %d\n",*(noweDlgWierszy+i ));
    }

    *(nowaTablica+ r) = malloc(w * sizeof(int));
    *(noweDlgWierszy + r) = w;

    for (i = r + 1; i < *ileWierszy + 1; i++){
        *(nowaTablica + i )= *(*(tablica) + i - 1);
        //printf("tab: %d ",**(nowaTablica + i ));
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i - 1);
        //printf("ile: %d\n",*(noweDlgWierszy+i ));
    }

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    for (i = 0; i < w; i++) {
         *(*(*(tablica) + r) + i) = *(wiersz + i);
         //printf("tab: %d ",*(*(*(tablica) + r) + i));
    }

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;

    *ileWierszy+=1;
}
//wstawienie po danym wierszu
void IAR(int*** tablica, int r, int w, int* wiersz, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy + 1) * sizeof(int*));

    int* noweDlgWierszy = malloc((*ileWierszy + 1) * sizeof(int));

    int i = 0;
    //przekopiowanie
    for (i = 0; i <= r; i++){
        *(nowaTablica + i )= *(*(tablica) + i);
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i);
    }

    *(nowaTablica+ r + 1) = malloc(w * sizeof(int));
    *(noweDlgWierszy + r + 1) = w;

    for (i = r + 2; i < *ileWierszy + 1; i++){
        *(nowaTablica + i )= *(*(tablica) + i - 1);
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i - 1);
    }

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    for (i = 0; i < w; i++) {
         *(*(*(tablica) + r + 1) + i) = *(wiersz + i);
    }

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;

    *ileWierszy+=1;
}
//wstawienie przed dana kolumna
void IBC (int*** tablica, int c, int h, int* kolumna, int* ileWierszy, int** dlgWierszy){
    int i;
    for (i = 0; i < h; i++){
        if (i < *ileWierszy){
            int dlg=*(*dlgWierszy + i);
            if (c < dlg){
               int* nowyWiersz = malloc( (dlg+1) * sizeof(int));
               int j;
               //przekopowanie
                for ( j = 0; j < c ; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j);
                }

               *(nowyWiersz + c) = *(kolumna+i);
                *(*dlgWierszy + i) += 1;

               //przekopowanie
                for ( j = c; j < dlg; j++){
                    *(nowyWiersz + j + 1) = *(*(*tablica + i) + j);
                }

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            } else {
               int dlg = *(*dlgWierszy + i) + 1;
               int* nowyWiersz = malloc( dlg * sizeof(int));
               int j;
               //przekopowanie
                for ( j = 0; j < dlg -1; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j );
                }
                *(nowyWiersz+j) = *(kolumna+i);

                *(*dlgWierszy + i)+=1;

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            }
        } else {
            ALR(tablica, 1, kolumna + i, ileWierszy, dlgWierszy);
        }
    }
}
//wstawienie za dana kolumna
void IAC (int*** tablica, int c, int h, int* kolumna, int* ileWierszy, int** dlgWierszy){
    int i;
    for (i = 0; i < h; i++){
        if (i < *ileWierszy){
            int dlg=*(*dlgWierszy + i);
            if (c < dlg){
               int* nowyWiersz = malloc( (dlg+1) * sizeof(int));
               int j;
               //przekopowanie
                for ( j = 0; j <= c ; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j);
                }

               *(nowyWiersz + c + 1) = *(kolumna+i);
                *(*dlgWierszy + i) += 1;

               //przekopowanie
                for ( j = c + 1; j < dlg; j++){
                    *(nowyWiersz + j + 1) = *(*(*tablica + i) + j );
                }

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            } else {
               int dlg = *(*dlgWierszy + i) + 1;
               int* nowyWiersz = malloc( dlg * sizeof(int));
               int j;
               //przekopowanie
                for ( j = 0; j < dlg -1; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j );
                }
                *(nowyWiersz+j) = *(kolumna+i);

                *(*dlgWierszy + i)+=1;

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            }
        } else {
            ALR(tablica, 1, kolumna + i, ileWierszy, dlgWierszy);
        }
    }
}

//zamiana kolumn
void SWC (int** tablica, int r, int s, int ileWierszy, int*dlgWierszy){
    int i;
    for (i = 0; i < ileWierszy; i++){
        int dlg = *(dlgWierszy+i);
        if (r < dlg && s < dlg){
            int temp = *(*(tablica + i)+r);
            *(*(tablica + i)+r) = *(*(tablica + i)+s);
            *(*(tablica + i)+s) = temp;
        }
    }
}

//zamiana wierszy
void SWR (int** tablica, int r, int s, int ileWierszy, int*dlgWierszy){
        if (r < ileWierszy && s < ileWierszy){
            int* temp = *(tablica + r);
            *(tablica + r) = *(tablica + s);
            *(tablica + s) =temp;
            int tempDlg =*(dlgWierszy + r);
            *(dlgWierszy + r) =*(dlgWierszy + s);
            *(dlgWierszy + s) = tempDlg;
        }
}

//usuniecie pierwszego wiersza
void DFR (int*** tablica, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy - 1) * sizeof(int*));
    int* noweDlgWierszy = malloc((*ileWierszy - 1) * sizeof(int));

    int i;
    int pom;
    //przekopiowanie
    for (i = 0; i < *ileWierszy - 1; i++){
        *(nowaTablica + i )= *(*(tablica) + i + 1);
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i + 1);
    }

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;
    *ileWierszy-=1;

    if(*ileWierszy==0){
        *tablica =NULL;
    }

}

//usuniecie ostatniego wiersza
void DLR (int*** tablica, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy - 1) * sizeof(int*));
    int* noweDlgWierszy = malloc((*ileWierszy - 1) * sizeof(int));

    int i;
    int pom;
    //przekopiowanie
    for (i = 0; i < *ileWierszy - 1; i++){
        *(nowaTablica + i )= *(*(tablica) + i );
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i );
    }

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;
    *ileWierszy-=1;

    if(*ileWierszy==0){
        *tablica =NULL;
    }
}

//usuniecie pierwszej kolumny
void DFC (int*** tablica, int* ileWierszy, int** dlgWierszy){
    int i;
    for (i = 0; i < *ileWierszy; i++){
        int dlg = *(*dlgWierszy + i) - 1;
        if (dlg == 0){
            RMR(tablica, i, ileWierszy, dlgWierszy);
            i--;
        }else{
           int* nowyWiersz = malloc( dlg * sizeof(int));
           int j;

            *(*dlgWierszy + i)-=1;
           //przekopowanie
            for ( j = 0; j < dlg; j++){
                *(nowyWiersz + j) = *(*(*tablica + i) + j + 1);
            }

            free(*(*(tablica) + i));
            *(*(tablica) + i) = nowyWiersz;
        }
    }
    if(*ileWierszy==0){
        *tablica =NULL;
    }

}

//usuniecie ostatniej kolumny
void DLC (int*** tablica, int* ileWierszy, int** dlgWierszy){
    int i;
    for (i = 0; i < *ileWierszy; i++){
        int dlg = *(*dlgWierszy + i) - 1;
        if (dlg == 0){
            RMR(tablica, i, ileWierszy, dlgWierszy);
            i--;
        }else{
           int* nowyWiersz = malloc( dlg * sizeof(int));
           int j;

            *(*dlgWierszy + i)-=1;
           //przekopowanie
            for ( j = 0; j < dlg; j++){
                *(nowyWiersz + j) = *(*(*tablica + i) + j);
            }

            free(*(*(tablica) + i));
            *(*(tablica) + i) = nowyWiersz;
        }
    }
    if(*ileWierszy==0){
        *tablica =NULL;
    }

}

//usuniecie danego wiersza
void RMR(int*** tablica, int r, int* ileWierszy, int** dlgWierszy){
    int** nowaTablica = (int**)malloc((*ileWierszy - 1) * sizeof(int*));

    int* noweDlgWierszy = malloc((*ileWierszy - 1) * sizeof(int));

    int i = 0;
    //przekopiowanie
    for (i = 0; i < r; i++){
        *(nowaTablica + i )= *(*(tablica) + i);
        *(noweDlgWierszy+i )=*(*(dlgWierszy) + i);
    }

    for (i = r + 1; i < *ileWierszy; i++){
        *(nowaTablica + i - 1 )= *(*(tablica) + i );
        *(noweDlgWierszy+i - 1)=*(*(dlgWierszy) + i );
    }

    if (*tablica!=NULL){
        free(*tablica);
    }
    *tablica = nowaTablica;

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlgWierszy;

    *ileWierszy-=1;
    if(*ileWierszy==0){
        *tablica =NULL;
    }
}

//usuniecie danej kolumny
void RMC (int*** tablica, int c, int* ileWierszy, int** dlgWierszy){
    int i;
     for (i = 0; i < *ileWierszy; i++){
        if(c < *(*dlgWierszy + i) ){
            int dlg=*(*dlgWierszy + i) - 1;
            if (dlg > 0){
               int* nowyWiersz = malloc( (dlg) * sizeof(int));
               *(*dlgWierszy + i)-=1;
               int j;
               //przekopowanie
                for ( j = 0; j < c ; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j);
                }

               //przekopowanie
                for ( j = c; j < dlg; j++){
                    *(nowyWiersz + j ) = *(*(*tablica + i) + j + 1);
                }

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            }else {
                RMR(tablica, i, ileWierszy,dlgWierszy);
                i--;
            }
        }
    }
    if(*ileWierszy==0){
        *tablica =NULL;
    }
}

//usuniecie bloku
void RMB(int*** tablica, int r, int h, int c, int w , int* ileWierszy, int** dlgWierszy){
    int i;
    int i2;
    int wiersze = *ileWierszy;
    for (i = r, i2 = r; i2 < r + h && i < *ileWierszy; i++, i2++){
        if ( c < *(*dlgWierszy + i)){
            int dlg;
            if ( c + w >= *(*dlgWierszy + i)){
                dlg = c;
            } else {
                dlg=*(*dlgWierszy + i) - w;
            }

            if (dlg <= 0){
                RMR(tablica,i,ileWierszy,dlgWierszy);
                i--;
            } else {
                   int* nowyWiersz = malloc( (dlg) * sizeof(int));
                   *(*dlgWierszy + i) = dlg;
                   int j;
                   //przekopowanie
                    for ( j = 0; j < c ; j++){
                        *(nowyWiersz + j) = *(*(*tablica + i) + j);
                    }
                    for (j = c + w; j < dlg + w; j++){
                        *(nowyWiersz + j - w) = *(*(*tablica + i) + j);
                    }
                    free(*(*(tablica) + i));
                    *(*(tablica) + i) = nowyWiersz;
            }
        }
    }
    if(*ileWierszy==0){
        *tablica =NULL;
    }
}

//wstawienie bloku
void ISB(int*** tablica, int r, int c,  int h, int w , int** blok, int* ileWierszy, int** dlgWierszy){
    int i;
    int p = 0;
    if (r >= *ileWierszy){
        for (i = 0; i < h; i++ ){
            int* wiersz = *(blok + p);
            p++;
            ALR(tablica, w, wiersz, ileWierszy, dlgWierszy);
        }
    } else {
        for (i = r; i < r + h && i < *ileWierszy; i++){
            if (c >= *(*dlgWierszy + i)){
                int dlg=*(*dlgWierszy + i) + w;
                int* nowyWiersz = malloc( (dlg) * sizeof(int));
                *(*dlgWierszy + i)+=w;
                int* wiersz = *(blok + p);
                p++;
                int j;
                //przekopowanie
                for ( j = 0; j < dlg - w; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j);
                }
                int k = 0;
                for (j = dlg - w; j < dlg; j++){
                    *(nowyWiersz + j ) = *(wiersz + k);
                    //printf ("%d\n",*(wiersz + k) );
                    k++;
                }
                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            }else {
                int dlg=*(*dlgWierszy + i) + w;
                int* nowyWiersz = malloc( (dlg) * sizeof(int));
                *(*dlgWierszy + i)+=w;
                int* wiersz = *(blok + p);
                p++;
                int j;
                //przekopowanie
                for ( j = 0; j < c; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j);
                }
                int k = 0;
                for (j = c; j < c + w; j++){
                    *(nowyWiersz + j ) = *(wiersz + k);
                    //printf ("%d\n",*(wiersz + k) );
                    k++;
                }
                for (j = c+w; j < dlg; j++){
                    *(nowyWiersz + j) = *(*(*tablica + i) + j - w);
                }

                free(*(*(tablica) + i));
                *(*(tablica) + i) = nowyWiersz;
            }
        }

        for (i = *ileWierszy; i < r + h; i++ ){
            int* wiersz = *(blok + p);
            p++;
            ALR(tablica, w, wiersz, ileWierszy, dlgWierszy);
        }
    }
}

//wyswietlenie
void PRT (int** tab, int ileWierszy, int* dlgWierszy){
    int i,j;
    printf("%d\n",ileWierszy);
    for ( i = 0; i < ileWierszy; i++ ) {
        printf("%d ",*( dlgWierszy + i ));
        for ( j = 0; j < *( dlgWierszy + i ); j++ ){
            printf ( "%d ", * ( * ( tab + i ) + j ) );
        }
        printf ( "\n" );
    }

}

//zapis do pliku binarnego
void WRF (int** tab, int ileWierszy, int* dlgWierszy, FILE* plik ){
    fprintf (plik, "%d\n", ileWierszy);
    int i;
    for (i = 0; i < ileWierszy; i++) {
        int temp = *(dlgWierszy + i) >>8;
        fwrite(&temp, 1,1,plik);
        temp = *(dlgWierszy + i);
        fwrite(&temp, 1,1,plik);
        int j;
        for (j = 0; j < *(dlgWierszy + i); j++) {
            int liczba = *(*(tab + i)+j);
            temp =liczba >> 24;
            fwrite(&temp, 1,1,plik);
            temp =liczba >> 16;
            fwrite(&temp, 1,1,plik);
            temp =liczba >> 8;
            fwrite(&temp, 1,1,plik);
            temp =liczba;
            fwrite(&temp, 1,1,plik);
        }
    }
}

//odczyt z pliku
void RDF (int*** tab, int* ileWierszy, int** dlgWierszy, FILE* plik ){
    int nowaLiczbaWierszy;
     fscanf(plik, "%d", &nowaLiczbaWierszy);
     char tmp;
     fscanf(plik, "%c", &tmp);
    int** nowaTablica = (int**)malloc(nowaLiczbaWierszy * sizeof(int*));
    int* noweDlg = malloc (nowaLiczbaWierszy * sizeof(int));
    *ileWierszy = nowaLiczbaWierszy;
    int i;
    for (i = 0; i < *ileWierszy; i++){
        int dlgWiersza = 0;
        int temp = 0;
        fread(&temp, 1,1,plik);
        dlgWiersza = dlgWiersza + temp << 8;
        fread(&temp, 1,1,plik);
        dlgWiersza =dlgWiersza + temp;
        int* wiersz = malloc (dlgWiersza*sizeof(int));
        int liczba = 0;
        int j;
        for (j = 0; j < dlgWiersza; j++) {
            liczba = 0;
            temp = 0;
            fread(&temp, 1,1,plik);
            liczba = liczba + (temp << 24);
            fread(&temp, 1,1,plik);
            liczba = liczba + (temp << 16);
            fread(&temp, 1,1,plik);
            liczba = liczba + (temp << 8);
            fread(&temp, 1,1,plik);
            liczba = liczba + (temp);
            *(wiersz + j) = liczba;
        }
        *(nowaTablica+i)=wiersz;
        *(noweDlg + i)=dlgWiersza;
    }

    if (*tab!=NULL){
        free(*tab);
    }
    *tab = nowaTablica;

    if (*dlgWierszy != NULL){
        free(*dlgWierszy);
    }
    *dlgWierszy= noweDlg;

    if(*ileWierszy==0){
        *tab =NULL;
    }
}


int porownajNapisy (char* a, char* b){
    int i;
    for (i = 0; i <3; i++){
        if (*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}

int main()
{
    char* operacja = malloc(3 * sizeof(char));
    scanf("%s", operacja);
    int** tablica = NULL;
    int* dlgWierszy = NULL;
    int ileWierszy=0;
    int* elementy;

    while (1){

        if (porownajNapisy(operacja, "AFR")){
            int w;
            scanf("%d", &w);
            int i;
            elementy = malloc (w * sizeof(int));
            for(i = 0; i < w; i++){
                scanf ("%d", (elementy + i));
            }
            if (w > 0){
                AFR(&tablica, w,elementy, &ileWierszy, &dlgWierszy);
                free(elementy);
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "ALR")){
            int w;
            scanf("%d", &w);
            int i;
            elementy = malloc (w * sizeof(int));
            for(i = 0; i < w; i++){
                scanf ("%d", (elementy+i));
            }
            if (w> 0){
            ALR(&tablica, w,elementy, &ileWierszy, &dlgWierszy);
            free(elementy);
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "AFC")){
            int h;
            scanf("%d", &h);
            int i;
            elementy = malloc (h * sizeof(int));
            for(i = 0; i < h; i++){
                scanf ("%d", (elementy+i));
            }
            if (h > 0){
                AFC(&tablica, h,elementy, &ileWierszy, &dlgWierszy);
                free(elementy);
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "ALC")){
            int h;
            scanf("%d", &h);
            int i;
            elementy = malloc (h * sizeof(int));
            for(i = 0; i < h; i++){
                scanf ("%d", elementy + i);
            }
            if ( h > 0){
                ALC(&tablica, h,elementy, &ileWierszy, &dlgWierszy);
                free(elementy);
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "IBR")){
            int r,w;
            scanf("%d", &r);
            scanf("%d", &w);
            int i;
            elementy = malloc (w * sizeof(int));
            for(i = 0; i < w; i++){
                scanf ("%d", (elementy+i));
            }
            if (r < ileWierszy){
                if (  w > 0){
                    IBR(&tablica, r,w,elementy, &ileWierszy, &dlgWierszy);
                    free(elementy);
                }
            }
        }else if (porownajNapisy(operacja, "IAR")){
            int r,w;
            scanf("%d", &r);
            scanf("%d", &w);
            int i;
            elementy = malloc (w * sizeof(int));
            for(i = 0; i < w; i++){
                scanf ("%d", (elementy+i));
            }
            if (r < ileWierszy){
                if (w > 0){
                    IAR(&tablica, r,w,elementy, &ileWierszy, &dlgWierszy);
                    free(elementy);
                }
            }

        }else if (porownajNapisy(operacja, "IBC")){
            int h,c;
            scanf("%d", &c);
            scanf("%d", &h);
            int i;
            elementy = malloc (h * sizeof(int));
            for(i = 0; i < h; i++){
                scanf ("%d", elementy + i);
            }
            IBC(&tablica, c,h,elementy, &ileWierszy, &dlgWierszy);
            free(elementy);
        }else if (porownajNapisy(operacja, "IAC")){
            int h,c;
            scanf("%d", &c);
            scanf("%d", &h);
            int i;
            elementy = malloc (h * sizeof(int));
            for(i = 0; i < h; i++){
                scanf ("%d", elementy + i);
            }
            if (h > 0){
            IAC(&tablica, c,h,elementy, &ileWierszy, &dlgWierszy);
            free(elementy);
            }
        }else if (porownajNapisy(operacja, "SWC")){
            int r,s;
            scanf("%d", &r);
            scanf("%d", &s);
            SWC(tablica, r,s,ileWierszy,dlgWierszy);
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "SWR")){
            int r,s;
            scanf("%d", &r);
            scanf("%d", &s);
            SWR(tablica, r,s,ileWierszy,dlgWierszy);
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "DFR")){
            if (tablica != NULL){
                DFR(&tablica,&ileWierszy, &dlgWierszy );
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "DLR")){
            if (tablica != NULL){
                DLR(&tablica,&ileWierszy, &dlgWierszy );
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "DFC")){
            if (tablica != NULL){
                DFC(&tablica,&ileWierszy, &dlgWierszy );
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "DLC")){
            if (tablica != NULL){
                DLC(&tablica,&ileWierszy, &dlgWierszy );
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "RMR")){
            int r;
            scanf("%d", &r);
            if (r<ileWierszy){
                RMR(&tablica, r,&ileWierszy, &dlgWierszy);
            }
            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "RMC")){
            int c;
            scanf("%d", &c);

            RMC(&tablica, c ,&ileWierszy, &dlgWierszy);

            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "RMB")){
            int r,h,c,w;
            scanf("%d%d%d%d", &r,&h,&c,&w);
            if (tablica !=NULL){
            RMB(&tablica, r,h,c,w ,&ileWierszy, &dlgWierszy);
            }

            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        }else if (porownajNapisy(operacja, "ISB")){
            int r,c,h,w;
            scanf("%d%d%d%d", &r,&c,&h,&w);
            int** blok = (int**)malloc(h * sizeof(int*));

            int i;
            for (i = 0; i < h; i++){
                int* wiersz= malloc (w * sizeof(int));
                int j;
                for (j = 0; j < w; j++){
                    scanf ("%d", wiersz + j);
                }
                *(blok + i) = wiersz;
            }

            ISB(&tablica, r,c,h,w, blok ,&ileWierszy, &dlgWierszy);

            //wyswietlTab(tablica, ileWierszy, dlgWierszy);
        } else if (porownajNapisy(operacja, "PRT")){
            PRT(tablica, ileWierszy,dlgWierszy);
        }else if (porownajNapisy(operacja, "WRF")){
            char* nazwa = malloc(17*sizeof(char));
            int i = 0;
            scanf ("%s", nazwa);
            FILE* fileVar = fopen ( nazwa, "wb" );
            WRF(tablica, ileWierszy,dlgWierszy, fileVar );
            fclose(fileVar);
            free(nazwa);
        }else if (porownajNapisy(operacja, "RDF")){
            char* nazwa = malloc(17*sizeof(char));
            int i = 0;
            scanf ("%s", nazwa);
            FILE* fileVar = fopen ( nazwa, "rb" );
            RDF(&tablica, &ileWierszy,&dlgWierszy, fileVar );
            fclose(fileVar);
            free (nazwa);
        }else if (porownajNapisy(operacja, "END")){
            free(tablica);
            free(dlgWierszy);
            free(operacja);
            break;
        }
        scanf("%s", operacja);
    }
    return 0;
}
