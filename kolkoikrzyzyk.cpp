#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool sprawdzpoziom(int mod, int cal, int A[], int rozmiar, bool kolej)
{
	if(kolej)
	{
		for(int i=0; i<rozmiar; i++)
		{
			if(A[i+cal]!=1)
				return false;
		}
	}
	else
	{
		for(int i=0; i<rozmiar; i++)
		{
			if(A[i+cal]!=2)
				return false;
		}
	}
	return true;
}

bool sprawdzpion(int mod, int A[], int rozmiar, bool kolej)
{
	int i;
	if(kolej)
	{
		for(int i=0; i<rozmiar*rozmiar; i+=rozmiar)
		{
			if(A[i+mod]!=1)
				return false;
		}
	}
	else
	{
		for(i=0; i<rozmiar*rozmiar; i+=rozmiar)
		{
			if(A[i+mod]!=2)
				return false;
		}
	}
	return true;
}

bool sprawdzukos(int A[],int rozmiar,bool kolej)
{
	if(kolej)
	{
		for(int i=0;i<rozmiar;i++)
		{
			if(A[i*rozmiar+i]!=1)
				return false;
		}
	}
	else
	{
		for(int i=0;i<rozmiar;i++)
		{
			if(A[i*rozmiar+i]!=2)
				return false;
		}
	}
	return true;
}



bool sprawdz(int gdzie, int A[], int rozmiar, bool kolej)
{
	int cal, mod;
	cal=gdzie%rozmiar;
	mod=gdzie%rozmiar;
	if(sprawdzpion(mod, A, rozmiar, kolej) or sprawdzpoziom(mod, gdzie-mod, A, rozmiar, kolej))
		return true;
	if(mod==cal)
		if(sprawdzukos(A,rozmiar,kolej))
			return true;
	return false;
}

bool czyremis(int A[],int rozmiar)
{
	for(int i=0;i<rozmiar*rozmiar;i++)
	{
		if(A[i]==0)
			return false;
	}
	return true;
}



char plansza(int co)
{
    if (co == 0)
    return' ';
    else if (co == 1)
    return 'o';
    else
    return 'x';
}

void wypisz(int rozmiar,int A[])
{
    int k,w;
    for(k=0;k<rozmiar;k++)
    {
    	cout<<plansza(A[k*rozmiar]);
        for(w=1;w<rozmiar;w++)
        {
            cout<<" | "<<plansza(A[k*rozmiar+w]);
        }
        cout<<endl;
    }

}


int main()
{
	int rozmiar, gdzie, i;
	string czy;
	bool kolej, wygrana,remis;
	cout<<"Witaj w grze kolko i krzyzyk! Gdy nadejdzie twoja kolej napisz liczbe odpowiadajaca miejscu w ktorym chcesz postawic swoj krzyzyk lub kolko, pola numerowane sa od 1, od lewej do prawej od gory do dolu"<<endl;
	int A[255];
	do
	{
		cout<<"Jak duza chcesz plansze? Wpisz 3, 4 lub wiecej az do 16: ";
		cin>>rozmiar;
		for(i=0;i<=rozmiar*rozmiar;i++)
		{
			A[i]=0;
		}
		wygrana=false;
		kolej=true;
		remis=false;
		do
		{
			system ("CLS");
			wypisz(rozmiar,A);
			if(kolej)
			{
				cout<<"Gracz 1: ";
				cin>>gdzie;
				gdzie--;
				if(gdzie>=rozmiar*rozmiar or A[gdzie]!=0)
				{
					do
					{
						cout<<"Podales zle pole, podaj poprawne: ";
						cin>>gdzie;
						gdzie--;
					}
					while(gdzie>rozmiar*rozmiar or A[gdzie]!=0);
				}
				A[gdzie]=1;
				if(sprawdz(gdzie,A,rozmiar,kolej))
					wygrana=true;
				kolej=false;
			}
			else
			{
				cout<<"Gracz 2: ";
				cin>>gdzie;
				gdzie--;
				if(gdzie>rozmiar*rozmiar or A[gdzie]!=0)
				{
					do
					{
						cout<<"Podales zle pole, podaj poprawne: ";
						cin>>gdzie;
						gdzie--;
					}
					while(gdzie>rozmiar*rozmiar or A[gdzie]!=0);
				}
				A[gdzie]=2;
				if(sprawdz(gdzie,A,rozmiar,kolej))
					wygrana=true;
				kolej=true;
			}
			remis=czyremis(A,rozmiar);
		}
		while(wygrana==false and remis==false);
		if(remis)
		{
			system ("CLS");
			wypisz(rozmiar,A);
			cout<<"Remis!"<<endl;
		}
		else
		{
			system ("CLS");
			wypisz(rozmiar,A);
			if(kolej)
				cout<<"Gracz 2 wygrywa!"<<endl;
			else
				cout<<"Gracz 1 wygrywa!"<<endl;
		}
		cout<<"Czy chcesz zagrac jeszcze raz? ";
		cin>>czy;
	}
	while(czy=="tak");
	return 0;
}
