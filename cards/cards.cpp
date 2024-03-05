#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

int s[100];
int k = 0;
struct nod
{
    int nr;
    nod* ant;

};
nod* primul = NULL;
nod* doi = NULL;
nod* trei = NULL;
nod* aux = NULL;
void push(nod*& v, int a)
{
    nod* c;

    c = new nod;
    c->nr = a;
    c->ant = v;
    v = c;

}

void pop(nod*& v)
{
    nod* c;
    c = new nod;
    if (v != NULL) {

        c = v;
        v = v->ant;
        delete c;
    }
}
void afisare(nod* v)
{
    nod* c;
    c = new nod;
    c = v;
    while (c != NULL)
    {
        cout << c->nr << " ";
        pop(c);
    }
    cout << endl;
}
void formare()
{
    int j = 1;
    for (int i = 1; i <= 16; i++)

    {
        s[i] = j;
        if (i % 4 == 0)
            j++;
    }
}
void stergere(int x)
{
    for (int i = x; i < 16 - k; i++)
    {
        s[i] = s[i + 1];

    }
    k++;
}
int numereegale(nod* r)
{
    nod* c;
    c = r;
    while (c != NULL)
    {
        int x = c->nr;
        c = c->ant;
        if (c != NULL && c->nr != x)
        {
            return 0;
        }
    }
    return 1;
}

int verificare()
{
    if (numereegale(primul) == 1)
    {
        return 1;
    }
    if (numereegale(doi) == 1)
    {
        return 2;
    }
    if (numereegale(trei) == 1)
    {
        return 3;
    }
    return 0;
}
void adaug(int x, int y)
{
    int ok = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (ok == 0)
        {
            if (s[i] == y)
            {
                ok = 1;
                s[i] = x;
            }
        }
    }
}
void sterg(nod*& v, int y)
{
    nod* current = v;
    nod* prev = NULL;
    nod* aux = NULL;


    while (current != NULL && current->nr != y)
    {
        prev = current;
        current = current->ant;
    }


    if (current == NULL) return;


    if (prev == NULL)
    {
        v = current->ant;
        delete current;
    }
    else
    {

        prev->ant = current->ant;
        delete current;
    }


    current = v;
    while (current != NULL)
    {
        push(aux, current->nr);
        current = current->ant;
    }


    while (v != NULL)
    {
        pop(v);
    }

    v = aux;
}


int main()
{
    formare();
    srand(time(NULL));
    int numar;
    int ok = 0;

    for (int i = 1; i <= 12; i++)
    {
        if (i <= 4)
        {
            numar = rand() % (16 - k) + 1;
            push(primul, s[numar]);
            stergere(numar);
        }
        if (i > 4 && i <= 8)
        {
            numar = rand() % (16 - k) + 1;
            push(doi, s[numar]);
            stergere(numar);
        }
        if (i > 8)
        {
            numar = rand() % (16 - k) + 1;
            push(trei, s[numar]);
            stergere(numar);
        }

    }
    cout << "The first player has these cards:";
    afisare(primul);
    cout << endl;
    cout << "The second player has these cards:";
    afisare(doi);
    cout << endl;
    cout << "The third player has these cards:";
    afisare(trei);
    cout << endl;
    cout << "Remaining cards:";
    for (int i = 1; i <= 4; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;


    cout << "In case you want to wait a turn write 0, otherwise write the number of the card you want to switch with and the card number you have";
    cout << endl;


    int x, y;
    while (verificare() == 0)
    {
        {if (ok == 0)
        {
            cout << "It's the first player turn" << endl;
            cout << "The card number you want to switch with:";
            cin >> x;
            if (x == 0)
            {
                cout << "Wait a turn" << endl;
            }
            else {

                cout << "With?";
                cin >> y;
                sterg(primul, x);
                push(primul, y);
                adaug(x, y);

                cout << "Player 1 cards:";
                afisare(primul);
                cout << endl;
                cout << "Remaining cards:";
                for (int i = 1; i <= 4; i++)
                {
                    cout << s[i] << " ";
                }
                cout << endl;
                if (verificare() == 1)
                {
                    cout << "The first player won" << endl;
                    ok = 1;
                }

            }

        }if (ok == 0)
        {
            cout << "It's the second player turn" << endl;
            cout << "The card number you want to switch with:";
            cin >> x;
            if (x == 0)
            {
                cout << "Wait a turn" << endl;
            }
            else {

                cout << "With?";
                cin >> y;
                sterg(doi, x);
                push(doi, y);
                adaug(x, y);

                cout << "Player 2 cards:";
                afisare(doi);
                cout << endl;
                cout << "Remaining cards:";
                for (int i = 1; i <= 4; i++)
                {
                    cout << s[i] << " ";
                }
                cout << endl;
                if (verificare() == 2)
                {
                    cout << "The second player won" << endl;
                    ok = 1;
                }
            }
        }

        if (ok == 0)
        {
            cout << "It's the third player turn" << endl;
            cout << "The card number you want to switch with:";
            cin >> x;
            if (x == 0)
            {
                cout << "Wait a turn" << endl;
            }
            else {

                cout << "With?";
                cin >> y;
                sterg(trei, x);
                push(trei, y);
                adaug(x, y);

                cout << "Player 3 cards:";
                afisare(trei);
                cout << endl;
                cout << "Remaining cards:";
                for (int i = 1; i <= 4; i++)
                {
                    cout << s[i] << " ";
                }
                cout << endl;
                if (verificare() == 3)
                {
                    cout << "The third player won" << endl;
                    ok = 1;
                }
            }
        }

        }
    }
    return 0;
}
