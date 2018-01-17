#ifndef VECTOR_H
#define VECTOR_H

typedef struct{
    int *tablica;
    int capacity;
    int numOfElem;
}Vector;

Vector *reserve(Vector *vect);   //alokowanie nowej tablicy z przepisaniem
int size(Vector *vect);          //sprawdzanie ilosci elementow
int capacity(Vector *vect);      //iloœæ zaalokowanej przestrzeni
int empty(Vector *vect);        //sprawdza czy lista jest pusta
void push_back(Vector *vect);    //dodawanie elementu na koniec tablicy
void insert(Vector *vect);       //dodawanie elementu w dowolnym miejscu
void removeElement(Vector *vect);//usuwanie elementu
void reverse(Vector *vect);      //odwrócenie tablicy
void at(Vector *vect);           //zwracanie N-tego elementu

#endif
