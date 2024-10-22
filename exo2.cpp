//Exercice 2 : Comparaison de la performance des containers
//Description : Créez un programme qui insère 1 million de nombres aléatoires dans un vector, une list, et un set.
// Mesurez le temps que prend chaque container pour effectuer les opérations suivantes :
//Insertion.
//Suppression.
//Recherche d’un élément spécifique.
//Bonus : Expliquer pourquoi certaines opérations sont plus rapides dans certains containers.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> create_vect(int n) {

	vector<int>vect(n);

	for (int i = 0; i < n; i++)
	{
		vect.push_back(i);
	}
	return vect;
}

list<int> create_list(int n) {
	list<int>lst(n);

	for (int i = 0; i < n; i++)
	{
		lst.push_back(i);
	}
	return lst;
}

set<int> create_set(int n) {
	set<int>s;

	for (int i = 0; i < n; i++)
	{
		s.insert(i);
	}
	return s;
}

int main()
{
	const auto startVect = steady_clock::now();
	vector<int> a = create_vect(1000000);
	const auto endVect = steady_clock::now() ;
	const std::chrono::duration<double> elapsed_seconds_vect{ endVect - startVect };
	cout << elapsed_seconds_vect.count() << endl;

	const auto startList = steady_clock::now();
	list<int> b = create_list(1000000);
	const auto endList = steady_clock::now();
	const std::chrono::duration<double> elapsed_seconds_list{ endList - startList };
	cout << elapsed_seconds_list.count() << endl;

	const auto startSet = steady_clock::now();
	set<int> c = create_set(1000000);
	const auto endSet = steady_clock::now();
	const std::chrono::duration<double> elapsed_seconds_set{ endSet - startSet };
	cout << elapsed_seconds_set.count() << endl;

}
