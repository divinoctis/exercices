// Exercice de base : Manipulation des containers STL (Vecteurs, listes, sets)
// Créez un programme qui stocke une série d'entiers dans trois types de containers différents : un vector, une list, et un set. Remplissez chaque container avec les mêmes valeurs et effectuez les opérations suivantes :
// Ajouter des éléments.
// Supprimer des éléments spécifiques.
// Trier les éléments (dans le cas du vector et de la list).
// Afficher les éléments du container dans l’ordre croissant.
// Prenez la liste : {5, 2, 9, 1, 5, 6}

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm> // pour sort le vector else it flops

void displayVector(std::vector<int>& vec)
{
	for (int value : vec)
	{
		std::cout << value << std::endl;
	}
	std::cout << "-------" << std::endl;
}

void displayList(std::list<int>& lst)
{
	for (int value : lst)
	{
		std::cout << value << std::endl;
	}
	std::cout << "-------" << std::endl;
}

void displaySet(std::set<int>& s)
{
	for (int value : s)
	{
		std::cout << value << std::endl;
	}
}


int main()
{
	std::vector<int> values = { 5, 2, 9, 1, 5, 6 }; // initialisation liste

	std::vector<int> vec(values.begin(), values.end());
	std::list<int> lst(values.begin(), values.end());
	std::set<int> s(values.begin(), values.end());

	// ajouter éléments
	vec.push_back(9); // ajoute 9 à la fin de la liste
	lst.push_back(4); // idem
	s.insert(7); // insert spécifique au set

	// supprimer éléments spécifiques
	vec.erase(vec.begin() + 5); // on prend la liste depuis le début et on itère jusqu'à la 5eme valeur pour l'enlever
	lst.remove(5);
	s.erase(5);

	// trier éléments (vector et list)
	std::sort(vec.begin(), vec.end()); 
	lst.sort();

	// afficher dans ordre croissant
	displayVector(vec);
	displayList(lst);
	displaySet(s);

	return 0;

}
