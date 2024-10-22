//Exercice 3 :
//
//1 - Écrivez une fonction template qui prend un tableau générique et sa taille, puis retourne la plus petite valeur du tableau.
//
//2 - Créez une fonction template qui prend un vecteur d'éléments de n'importe quel type, ajoute un élément à la fin, et renvoie la taille du vecteur après l'insertion.
//
//3 - Écrivez une fonction template qui prend une liste de n'importe quel type numérique (int, float, etc.) et retourne la somme de ses éléments.
//
//4 - Créez une fonction template qui calcule la moyenne d'un tableau de données numériques,
// mais qui se comporte différemment si le type est un int (elle doit renvoyer un double dans ce cas).

#include <iostream>
#include <vector> // exo 2
#include <numeric> // exo 3
using namespace std;


//EXO 1

//template <typename T>
//T minArray(T tab[], int taille)
//{
//	T min = tab[0];
//
//	for (int i = 1; i < taille; i++)
//	{
//		if (tab[i] < min)
//		{
//			min = tab[i];
//		}
//	}
//	return min;
//}
//
//int main()
//{
//	int tabInt[] = { 5, 7, 8, 2, 6, 1 };
//	cout << "Min valeur: " << minArray(tabInt, 6) << endl;
//
//	return 0;
//}


//EXO 2
//template <typename T>
//size_t addAndReturnSize(vector<T>& vecteur, const T& element)
//{
//	vecteur.push_back(element);
//	return vecteur.size();
//}
//
//int main()
//{
//	vector<int> vec = { 1, 2, 3 };
//	cout << "Taille avant ajout: " << vec.size() << endl;
//
//	size_t newSize = addAndReturnSize(vec, 4);
//	cout << "Taille après ajout: " << newSize << endl;
//
//	return 0;
//}

// EXO 3
template <typename T>
T sumElements(const vector<T>& liste)
{
	return accumulate(liste.begin(), liste.end(), static_cast<T>(0));
}

int main()
{
	vector<int> intList = { 1, 2, 3, 4, 5 };
	vector<float> floatList = { 1.1f, 2.2f, 3.3f };

	cout << "Somme des entiers: " << sumElements(intList) << endl;
	cout << "Somme des floats: " << sumElements(floatList) << endl;

	return 0;
}

// EXO 4
template <typename T>
T 
