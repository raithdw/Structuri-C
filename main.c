#include <stdio.h>
#include <stdlib.h>

// declaratie struct Produs
 struct Produs {
   char nume_produs[20], cod_produs[10];
   int cantitate;
   float pret, valoare_totala;
};

// am declarat variabile globale;
int n;
// un array de tip Produs
struct Produs nume[];

int main()
{
    // apelez functia de citire array de struct
    informatii_produse(nume);
    // apele functia ce afiseaza continutul array-ului
    afisare_continut_produs(nume);
    // aprovizionez variabila cantitate daca este cazul
    aprovizionare(nume);
    // afisez din nou array-ul updated dupa aprovizionare
    afisare_continut_produs(nume);


    return 0;
}

// functie care citeste de la tastatura intr-un vector de tip struct toate produsele :)
void informatii_produse(struct Produs produse[]) {

    printf("Introduceti numarul de produse: ");
    scanf("%d", &n);
// un for loop ca sa initializez toate variabilele din vector de la 0 la n cu input de la user
// vector de tip struct[n], unde struct[n] = {{produs[0].nume_produs...etc},{produs[n].nume_produs..etc}}
    for(int i = 0; i < n; i++) {
        printf("\nNume produs: ");
        scanf("%s",&produse[i].nume_produs);
        printf("\nCod produs: ");
        scanf("%s",&produse[i].cod_produs);
        printf("\nCantitate: ");
        scanf("%d",&produse[i].cantitate);
        printf("\nPret: ");
        scanf("%f",&produse[i].pret);
        // am luat valoare lui pret si cantitate de la fiecare iteratie si am aplicat formula pt a afla valoare_totala pt fiecare produs
        printf("\nValoare totala: %.2f\n", produse[i].valoare_totala = produse[i].pret * produse[i].cantitate );

    }

    printf("\n");

}

// funcia de afisare a tuturor produselor chiar daca numarul lor este 0 sau n :D
void afisare_continut_produs(struct Produs produs[])
 {
     // testez lista sa vad daca am produse de afisat...
    if (n > 0) {
           printf("Lista produse:\n");
        }
    else
        printf("Nu ati introdus nici un produs");

    // daca am ajuns aici inseamna ca am produse si le afisez pe rand prin iteratii de la 0 la n cu un for loop
    for (int i = 0; i < n; i++) {

        printf("\nNume produs: %s\n- Cod produs: %s\n- Cantitate: %d\n- Pret: %.2f\n- Valoare totala: %.2f\n", produs[i].nume_produs, produs[i].cod_produs, produs[i].cantitate, produs[i].pret, produs[i].valoare_totala);

    }
    printf("\n");

}

// functia de "baga marfa ca nu mai este" :D
void aprovizionare(struct Produs produs[]) {
    int count = 0;
    // aprovizionez doar daca am produse :)
    if(n > 0 ) {
        printf("Status aprovizionare:\n");
    }
    else
         printf("Nu este nici un produs\n");
// verific valoarea in variabila cantitate din fiecare element din array sa vad daca este < 2 ca sa fac aprovizionare
    for (int i = 0; i < n; i++) {
        if (produs[i].cantitate < 2) {
            count++;
            produs[i].cantitate += 10;
            produs[i].valoare_totala = produs[i].cantitate * produs[i].pret;

        }

    }
    // am incrementat un contor in loop si verific cu un if else daca trebuie sa afisez aprovizionare sau nu
     if (count > 0) {
            printf("Trebuie aprovizionare!");
        }
     else
        printf("Nu trebuie aprovizionare!");

    printf("\n");
}













