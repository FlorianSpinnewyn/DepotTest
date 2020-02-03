#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


int InitialiseTab(int* tab, int nbvaleur) {
	for (int i = 0; i < nbvaleur; i++) {
		tab[i] = (rand() % (100 - 0 + 1)) + 0;
	}
	return 0;
}

int afficheTab(int* tab, int nbvaleur) {
	for (int i = 0; i < nbvaleur; i++) {
		printf("%d |", tab[i]);
	}
	return 0;
}

int tri_naif(int* tab, int nbvaleur) {
	int nbPermutation = 0;
	int tmp;
	int copi = 0;
	for (int j = 0; j < (nbvaleur); j++) {
		for (int i = 0; i < (nbvaleur - 1); i++) {
			copi++;
			if (tab[i] >= tab[i + 1]) {
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
				nbPermutation++;
			}
		}
	}
	return copi;
}

int TriSelection(int* tab, int nbvaleur) {
	int tmp;
	if (nbvaleur == 0) {
		return 1;
	}
	for (int i = 0; i < nbvaleur; i++) {
		if (tab[nbvaleur - 1] <= tab[i]) {
			tmp = tab[i];
			tab[i] = tab[nbvaleur - 1];
			tab[nbvaleur - 1] = tmp;
		}
	}
	TriSelection(tab, nbvaleur - 1);
}



int tri_bule(int* tab, int nbvaleur) {
	int copi = 0;
	int nbPermutation = 0;
	int tmp;
	int swap = 0;
	int j = 0;
	do {
		for (int i = 0; i < (nbvaleur - 1); i++) {
			copi++;
			if (tab[i] >= tab[i + 1]) {
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
				nbPermutation++;
				swap = 0;
			}
			else {
				swap = 1;
			}
		}
		j++;
	} while ((swap == 0) || (j < nbvaleur));
	return copi;
}


int rang(int* tab, int indmin, int indmax, int valeur) {
	int milieu;
	if (indmin == indmax) {
		if (valeur > tab[indmin]) {
			return indmin;
		}
		else {
			return indmin + 1;
		}
	}
	if (valeur > tab[indmin]) {
		return indmin;
	}
	if (valeur < tab[indmax]) {
		return indmax + 1;
	}
	if (indmax == (indmin + 1)) {
		if (valeur < tab[indmax]) {
			return indmax + 1;
		}
		else
			return indmax;
	}
	if (indmin < indmax) {
		milieu = (indmax + indmin) / 2;
		if (valeur < tab[milieu]) {
			indmin = milieu + 1;
		}
		else {
			indmax = milieu;
		}
	}
	return rang(tab, indmin, indmax, valeur);
}

int TriDichotomie(int* tab, int tabsize) {
	int tmp;
	int indice;
	int permutation = 0;
	for (int i = 1; i < (tabsize); i++) {
		tmp = tab[i];
		indice = rang(tab, 0, i - 1, tmp);
		for (int j = (i - 1); j >= (indice); j--) {
			tab[j + 1] = tab[j];
			permutation++;
		}
		tab[indice] = tmp;
	}
	return permutation;
}


int TriInsertionSequentiel(int* tab, int tabsize) {
	int tmp;
	for (int i = 0; i < (tabsize - 1); i++) {
		int j = 0;
		while (tab[i + 1] < tab[i - j]) {
			tmp = tab[i + 1];
			tab[i + 1] = tab[i - j];
			tab[i - j] = tmp;
			j++;
		}
	}
	return 0;
}

int tri_flo(int* tab, int nbvaleur) {
	int nbPermutation = 0;
	int copi = 0;
	int tmp;
	int j = nbvaleur - 1;
	while (j != 0) {
		for (int i = 0; i < (j); i++) {
			copi++;
			if (tab[i] >= tab[j]) {
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
				nbPermutation++;
			}
		}
		j--;
	}
	return copi;
}

int testdesfonctionsDychotomie(int *tab, int size){
	printf("\nTableaux Initiale : \n");
	afficheTab(tab, size);
	printf("\nTableaux trie : \n");
	TriDichotomie(tab, size);
	afficheTab(tab, size);
	printf("\n\nIl y a %d permutations dans ce tri\n\n\n", TriDichotomie(tab, size));
	return 0;
}

int testdesfonctionsTriFlo(int* tab, int size) {
	printf("\nTableaux Initiale : \n");
	afficheTab(tab, size);
	printf("\nTableaux trie : \n");
	TriDichotomie(tab, size);
	afficheTab(tab, size);
	printf("\n\nIl y a %d permutations dans ce tri\n\n\n", TriDichotomie(tab, size));
	return 0;
}

int main() {
	srand(time(NULL));
	int* copi = 0;
	int tab[50];
	for (int i = 0; i < 50; i++) {
		tab[i] = (rand() % (50 - 0 + 1)) + 0;
	}
	testdesfonctions(tab, 50);


	return 0;
}