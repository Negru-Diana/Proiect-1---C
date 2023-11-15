#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct tranzactii
{
    char zi[5],luna[5],an[10];
    char descriere[200], tip[2];  /// tipul este venituri sau cheltuieli
    float suma;
} tranzactie[1];

void meniu();
int operatie_aleasa_din_meniu();
bool verifica_optiune(int optiune);
void coordoneaza_optiune(int optiune, bool optiune_valida);
void optiune_invalida();
void optiune0();
void optiune1();
void optiune2();
void indicatii_optiune1();
void indicatii_optiune2();

void def();

void date_tranzactie_noua();

void citeste_zi_tranzactie();
void citeste_luna_tranzactie();
void citeste_an_tranzactie();
bool verifica_data();///
void data_invalida();

void citeste_descriere_tranzactie();

void citeste_tip_tranzactie();
bool verifica_tip(char tip);
void tip_invalid();

void citeste_suma_trazactie();
bool verifica_suma(float suma);
void suma_invalida();

void salveaza_tranzactie_noua();

char transforma_tranzactie();

int main()
{
    int optiune;
    meniu();
    optiune = operatie_aleasa_din_meniu();
    bool optiune_valida=verifica_optiune(optiune);
    coordoneaza_optiune(optiune, optiune_valida);


}


void meniu()   /// afisarea meniului
{
    printf("Gestionare date financiare\n");
    printf("Alegeti numarul operatiei pe care doriti sa o utilizati:\n");
    printf("1. Adaugare tranzactii\n");
    printf("2. Vizualizare tranzactii\n");
    printf("3. Rapoarte financiare\n");
    printf("4. Sold cont\n");
    printf("0. Iesire program\n");
    printf("\nNumar: ");
}


int operatie_aleasa_din_meniu()    /// citirea operatiei pe care doreste sa o faca utilizatorul ( 1 - adauga tranzactie; 2 - vizualizeaza tranzactie)
{
    int optiune;
    scanf("%d",&optiune);

    return optiune;
}

bool verifica_optiune(int optiune)   /// verifica daca optiunea aleasa din meniu exista
{
    return (optiune>=0 && optiune<=4);
}

void optiune_invalida()    /// afiseaza mesaj pentru optiune invalida si reapeleaza main-ul
{
    printf("\nOptiunea aleasa din meniu este invalida! Alegeti o alta optiune.\n\n");
    main();
}

void optiune0()    /// 0. Iesire din program
{
    printf("\nLa revedere!\n");
}

void indicatii_optiune1()   /// se afiseaza indicatii pentru optiunea 1
{
    printf("\nAti ales optiunea de adaugare a tranzactiilor. Introduceti datele corespunzatoare pentru a crea o noua tranzactie.\n");
}

bool verifica_data()   /// verifica daca data introdusa este valida
{
    if(strcmp(&tranzactie[0].zi,"1")<0 || strcmp(&tranzactie[0].zi,"31")>0)
    {
        return false;
    }

    if(strcmp(&tranzactie[0].luna,"1")<0 || strcmp(&tranzactie[0].luna,"12")>0)
    {
        return false;
    }

    if(strcmp(&tranzactie[0].an,"2023")>0)
    {
        return false;
    }

    return true;
}

void citeste_zi_tranzactie()   /// se citeste ziua tranzactiei
{
    char spatiu;
    //scanf("%c",spatiu);
    printf("\nZi tranzactie (1-31) : ");
    char zi;
    //scanf("%c", &zi);
    scanf("%s", &tranzactie[0].zi);
    //printf(&tranzactie[0].zi);
}

void citeste_luna_tranzactie()  ///se citeste luna tranzactiei
{
    printf("\nLuna tranzactie (1-12): ");
    char luna;
    //scanf("%c", &luna);
    scanf("%s", &tranzactie[0].luna);
}

void citeste_an_tranzactie()  ///se citeste anul tranzactiei
{
    printf("\nAn tranzactie: ");
    char an;
    //scanf("%c", &an);
    scanf("%s", &tranzactie[0].an);
}

void data_invalida()  ///mesaj pentru data invalida
{
    printf("\nData introdusa este invalida!\n");
    date_tranzactie_noua();
}

void citeste_descriere_tranzactie()  ///se citeste descriere tranzactie
{
    printf("\nDescriere tranzactie: ");
    char descriere;
    scanf("%s", &tranzactie[0].descriere);
}

void citeste_tip_tranzactie() ///se citeste tipul tranzactiei (c-cheltui sau v-venituri)
{
    printf("\nTip tranzactie (v pentru venituri, c pentru cheltuieli): ");
    char tip;
    scanf("%s", &tranzactie[0].tip);
}

bool verifica_tip(char tip)  ///se verifica daca tipul cheltuielii este valid
{
    if(tip=='c' || tip=='v')
    {
        return true;
    }
    return false;
}

void tip_invalid()  ///mesaj tip invalid
{
    printf("\nTipul tranzactiei introdus este invalid! Trebuie scrisa litera v pentru venituri si litera c pentru cheltuieli.\n");
    citeste_tip_tranzactie();
}

void citeste_suma_trazactie()  ///se citeste suma tranzactiei
{
    printf("\nSuma tranzactie: ");
    scanf("%s", &tranzactie[0].suma);
    //printf(&tranzactie[0].suma);
}

bool verifica_suma(float suma)  ///verifica daca suma citita este valida
{
    if(suma<0.00)
    {
        return false;
    }
    return true;
}

void suma_invalida()   ///mesaj suma invalida
{
    printf("\nSuma introdusa este invalida!\n");
    citeste_suma_trazactie();
}

char transforma_tranzactie()  /// zi.luna.an;descriere;tip;suma  (modul/ordinea de stocare in fisier)
{
    char aux="";
    strcat(aux, tranzactie[0].zi);
    strcat(aux,".");
    strcat(aux,tranzactie[0].luna);
    strcat(aux,".");
    strcat(aux, tranzactie[0].an);
    strcat(aux,";");
    strcat(aux,tranzactie[0].descriere);
    strcat(aux,";");
    strcat(aux,tranzactie[0].tip);
    strcat(aux,";");
    strcat(aux,(char)tranzactie[0].suma);
    strcat(aux,"\n");
    return aux;
}

void salveaza_tranzactie_noua() ///se salveaza tranzactia noua
{
    FILE *fptr;
    fptr = fopen("D:\\UBB INFO - ANUL I (2023-2024)\\Anul I - Sem. I\\Programare in C\\Proiecte\\Proiect 1\\tranzactii.txt","a");  ///deschidem fisierul pentru a adauga date la finalul acestuia
    if(fptr==NULL) ///eroare de deschidere a fisierului
    {
        printf("\nTranzactia nu a putut fi salvata!\n");
        optiune1();
        return;
    }

    fprintf(fptr, &tranzactie[0].zi);
    fprintf(fptr, ".");
    fprintf(fptr, &tranzactie[0].luna);
    fprintf(fptr,".");
    fprintf(fptr,&tranzactie[0].an);

    fprintf(fptr,";");
    fprintf(fptr,&tranzactie[0].descriere);

    fprintf(fptr,";");
    fprintf(fptr,&tranzactie[0].tip[0]);

    fprintf(fptr,";");
    fprintf(fptr,&tranzactie[0].suma);
    fprintf(fptr,"\n");

    fclose(fptr);
    printf("\nTranzactia a fost salvata cu succes!\n");
}

void date_tranzactie_noua()    /// se afiseaza si se citesc datele pe care trebuie sa introduca utilizatorul
{
    citeste_zi_tranzactie();
    citeste_luna_tranzactie();
    citeste_an_tranzactie();
    //bool data_valida=verifica_data(&tranzactie[0].zi, &tranzactie[0].luna, &tranzactie[0].an);
    /*if(data_valida==false)
    {
        data_invalida();
    }*/

    citeste_descriere_tranzactie();

    citeste_tip_tranzactie();
    bool tip_valid=verifica_tip(tranzactie[0].tip[0]);
    if(tip_valid==false)
    {
        tip_invalid();
    }

    citeste_suma_trazactie();
    bool suma_valida=verifica_suma(tranzactie[0].suma);
    if(suma_valida==false)
    {
        suma_invalida();
    }
}

void optiune1()   /// 1. Adaugare tranzactii
{
    indicatii_optiune1();
    date_tranzactie_noua();
    salveaza_tranzactie_noua();
    printf("\n");
    main();
}

void indicatii_optiune2()
{
    printf("\n1. Vizualizare tranzactii pe luna\n");
    printf("2. Vizualizarea tuturor tranzactiilor\n");
    printf("\nIntroduceti numarul operatiei pe care doriti sa o efectuati: ");


}

int citeste_operatie_optiune2()   ///se citeste tipul operatiei de la optiunea 2 (1 - vizualizare dupa luna/an sau 2 - vizualizarea tuturor tranzactiilor)
{
    int operatie;
    scanf("%d",&operatie);
    return operatie;
}

bool verifica_operatie(int operatie)  ///se verifica daca operatia pentru optiunea 2 este valida
{
    if(operatie==1 || operatie==2)
    {
        return true;
    }
    return false;
}

void afiseaza_tranzactii()  ///afisarea tuturor tranzactiilor  (optiunea 2.2)
{
    printf("\nTranzactii:\n");
    //if(luna=='0' || an=='0')
    {
        FILE *fptr;
        fptr = fopen("D:\\UBB INFO - ANUL I (2023-2024)\\Anul I - Sem. I\\Programare in C\\Proiecte\\Proiect 1\\tranzactii.txt","r");
        if(fptr==NULL)
        {
            printf("\nTranzactiiile nu au putut fi incarcate!\n");
            optiune2();
            return;
        }
        int index=1;
        while(!feof(fptr))
        {
            char s[1000];
            fscanf(fptr,"%s",s);
            //printf("%zu",strlen(s));
            if(strlen(s)<12)
            {
                break;
            }
            printf("Tranzactie ");
            printf("%d",index);
            printf(":\n");
            char *token=strtok(s,";");
            printf("data: ");
            printf(token);
            printf("\n");

            token=strtok(NULL,";");
            printf("descriere: ");
            printf(token);
            printf("\n");

            token=strtok(NULL,";");
            printf("tip: ");
            if(token[0]=='v')
            {
                printf("venituri");
            }
            else
            {
                printf("cheltueli");
            }
            printf("\n");

            token=strtok(NULL,";");
            printf("suma: ");
            printf(token);
            printf(" lei\n\n");

            index++;
        }

        fclose(fptr);
    }

    //main();
}


bool valideaza_luna_an(char luna[], char an[])  ///se valideaza luna si anul
{
    if(strcmp(luna,"1")<0 || strcmp(luna,"12")>0)
    {
        return false;
    }

    if(strcmp(an,"2023")>0)
    {
        return false;
    }
    return true;
}

void luna_an_invalid() ///mesaj luna/an invalide
{
    printf("\nLuna si/sau anul sunt invalide!\n");
    luna_si_anul_filtrare_tranzactii();
}

void luna_si_anul_filtrare_tranzactii()  ///se citeste luna si anul pentru care sa se afiseze tranzactiile
{
    printf("\nIntroduceti luna pentru care doriti sa vedeti tranzactiile (1-12): ");
    char luna[3];
    scanf("%s", &luna);
    printf("\nIntroduceti anul pentru care doriti sa vedeti tranzactiile: ");
    char an[5];
    scanf("%s", &an);

    /*bool valid=valideaza_luna_an(luna, an);

    if(valid==false)
    {
        luna_an_invalid();
    }
    else
    {

    }*/



    ///se afiseaza tranzactiile filtrate si numerotate
    FILE *fptr;
    fptr = fopen("D:\\UBB INFO - ANUL I (2023-2024)\\Anul I - Sem. I\\Programare in C\\Proiecte\\Proiect 1\\tranzactii.txt","r");
    if(fptr==NULL)
    {
        printf("\nTranzactiiile nu au putut fi incarcate!\n");
        optiune2();
        return;
    }
    int index=1;
    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);
        if(strlen(s)<12)
        {
            break;
        }

        char aux[1000];
        strcpy(aux,s);
        char *token=strtok(s,";");
        char data[20];
        strcpy(data,token);

        char *tok = strtok(data,"."); /// tok=zi
        tok = strtok(NULL,".");  /// tok=luna
        char lunasir[2];
        strcpy(lunasir,tok);
        tok=strtok(NULL,".");
        char ansir[5];
        strcpy(ansir,tok);

        if(strcmp(luna,lunasir)==0 && strcmp(an,ansir)==0)  ///se verifica daca tranzactia trebuie afisata sau nu
        {

            printf("\nTranzactie ");
            printf("%d",index);
            printf(":\n");

            char *stok=strtok(aux,";");
            printf("data: ");
            printf("%s",stok);
            printf("\n");

            stok=strtok(NULL,";");
            printf("descriere: ");
            printf("%s",stok);
            printf("\n");

            stok=strtok(NULL,";");
            printf("tip: ");
            if(stok[0]=='v')
            {
                printf("venituri");
            }
            else
            {
                printf("cheltueli");
            }
            printf("\n");

            stok=strtok(NULL,";");
            printf("suma: ");
            printf("%s",stok);
            printf(" lei\n\n");


            index++;
        }


    }

    fclose(fptr);

    if(index==1)  ///mesaj in cazul in care nu s-a afisat nicio tranzactie
    {
        printf("\nNu exista tranzactii care sa fie vizualizate!\n");

    }
}

void optiune2()  ///2. Vizualizare tranzactii
{
    indicatii_optiune2();  ///se apeleaza functia care afiseaza suboptiunile optiunii 2
    int operatie = citeste_operatie_optiune2();
    bool valid=verifica_operatie(operatie);
    if(valid==false)
    {
        optiune_invalida();
        return;
    }

    ///se determina ce functie trebuie apelata in functie de suboptiunea aleasa
    if(operatie==1)
    {
        luna_si_anul_filtrare_tranzactii();
    }

    if(operatie==2)
    {
        afiseaza_tranzactii();
    }

    main();

}

void afiseaza_raport(int v, int c)
{
    printf("\nVenituri: %f lei\n",v);
    printf("Cheltuieli: %f lei\n\n",c);
}

void citeste_perioada(char *luna1[],char *an[],char *luna2[])
{
    printf("\nIntroduceti perioada pentru care doriti sa vizualizati raportul.\n");
    printf("Luna inceput perioada: ");
    scanf("%s",&luna1);
    printf("\nLuna sfarsit perioada: ");
    scanf("%s",&luna2);
    printf("\nAn perioada: ");
    scanf("%s",&an);
    printf("\n");
}

void optiune3()  ///3. Rapoarte financiare
{
    char luna1[4],luna2[4],an[5];
    //citeste_perioada(&luna1,&an,&luna2);

    printf("\nIntroduceti perioada pentru care doriti sa vizualizati raportul.\n");
    printf("Luna inceput perioada: ");
    scanf("%s",&luna1);
    printf("\nLuna sfarsit perioada: ");
    scanf("%s",&luna2);
    printf("\nAn perioada: ");
    scanf("%s",&an);
    printf("\n");

    float cheltuieli=0.0, venituri=0.0;


    FILE *fptr;
    fptr = fopen("D:\\UBB INFO - ANUL I (2023-2024)\\Anul I - Sem. I\\Programare in C\\Proiecte\\Proiect 1\\tranzactii.txt","r");
    if(fptr==NULL)
    {
        printf("\nTranzactiiile nu au putut fi incarcate!\n");
        optiune3();
        return;
    }
    int index=1;
    while(!feof(fptr))
    {
        char s[100];
        fscanf(fptr,"%s",s);
        if(strlen(s)<12)
        {
            break;
        }

        char aux[100];
        strcpy(aux,s);
        char *token=strtok(s,";");
        char data[20];
        strcpy(data,token);

        char *tok = strtok(data,"."); /// tok=zi
        tok = strtok(NULL,".");  /// tok=luna
        char lunasir[2];
        strcpy(lunasir,tok);
        tok=strtok(NULL,".");
        char ansir[5];
        strcpy(ansir,tok);

        int luna1_int=luna1-'0';
        int luna2_int=luna2-'0';
        int lunasir_int=lunasir-'0';

        //printf("%s  ",&luna1_int);

        //if(strcmp(luna1,lunasir)>=0 && strcmp(an,ansir)==0 && strcmp(luna2,lunasir)<=0)  ///se verifica daca tranzactia trebuie luata in calcul sau nu
        if(luna1_int>=lunasir_int && lunasir_int<=luna2_int && strcmp(an,ansir)==0)
        {
            char *stok=strtok(aux,";"); //data

            stok=strtok(NULL,";");  //descriere

            stok=strtok(NULL,";");  //tip

            if(stok[0]=='v')
            {
                stok=strtok(NULL,";"); //suma

                char suma[10];
                strcpy(suma,stok);
                //sprintf(&suma,"%f",stok);
                //printf(suma);

                char *end;

                float v=strtof(suma, &end);
                venituri+=v;

                //printf("%f",v);
            }
            else
            {
                stok=strtok(NULL,";");  //suma

                char suma[10];
                strcpy(suma,stok);
                //sprintf(&suma,"%f",stok);
                //printf(suma);

                char *end;

                float c=strtof(suma, &end);
                cheltuieli+=c;

                //printf("%f",c);


                //float c=atof(stok);
                //cheltuieli+=c;
            }
        }
    }

    fclose(fptr);

    /*printf("\n%f",&cheltuieli);
    printf("    ");
    printf("%f",&venituri);
    */

    printf("\nVenituri: %f lei\n",venituri);
    printf("Cheltuieli: %f lei\n\n",cheltuieli);
    //afiseaza_raport(&venituri,&cheltuieli);

    main();
}

void optiunea4()   ///calculeaza si afiseaza sold-ul contului
{
    float cheltuieli=0.0, venituri=0.0;


    FILE *fptr;
    fptr = fopen("D:\\UBB INFO - ANUL I (2023-2024)\\Anul I - Sem. I\\Programare in C\\Proiecte\\Proiect 1\\tranzactii.txt","r");
    if(fptr==NULL)
    {
        printf("\nSoldul nu a putut fi incarcat!\n");
        main();
        return;
    }
    //int index=1;
    while(!feof(fptr))
    {
        char s[100];
        fscanf(fptr,"%s",s);
        if(strlen(s)<12)
        {
            break;
        }

        char aux[100];
        strcpy(aux,s);

        char *stok=strtok(aux,";"); //data

        stok=strtok(NULL,";");  //descriere

        stok=strtok(NULL,";");  //tip

        if(stok[0]=='v')
        {
            stok=strtok(NULL,";"); //suma

            char suma[10];
            strcpy(suma,stok);

            char *end;

            float v=strtof(suma, &end);
            venituri+=v;
        }
        else
        {
            stok=strtok(NULL,";");  //suma

            char suma[10];
            strcpy(suma,stok);

            char *end;

            float c=strtof(suma, &end);
            cheltuieli+=c;

        }

    }

    fclose(fptr);

    printf("\nSold curent: %f lei\n\n",venituri-cheltuieli);


    main();

}

void coordoneaza_optiune(int optiune, bool optiune_valida) /// verifica daca trebuie afisat mesajul pentru optiune invalida sau sa se apeleze functia pentru optiunea aleasa
{
    if(optiune_valida==false)   /// optiunea aleasa de utilizator este invalida
    {
        optiune_invalida();
        return;
    }

    if(optiune==1)   /// adaugare tranzactii (daca s-a ales optiunea 1)
    {
        optiune1();   /// se apeleaza functia care coordoneaza operatiile pentru adaugarea tranzactiilor
        return;
    }

    if(optiune==2)  /// vizualizare tranzactii (daca s-a ales optiunea 2)
    {
        optiune2();  /// se apeleaza functia care coordoneaza operatiile pentru vizualizarea tranzactiilor
        return;
    }
    if(optiune==3)  /// rapoarte financiare (daca s-a ales optiunea 3)
    {
        optiune3();  /// se apeleaza functia care coordoneaza operatiile pentru rapoarte financiare
        return;
    }

    if(optiune==4) ///4. Sold cont (daca s-a ales optiunea 4)
    {
        optiunea4();  /// se apeleaza functia care coordoneaza operatiile pentru sold cont
        return;
    }

    if(optiune==0)  /// iesire din aplicatie (daca s-a ales optiunea 0)
    {
        optiune0();  ///se apeleza functia pentru iesirea din aplicatie
        return;
    }
}
