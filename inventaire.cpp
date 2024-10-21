//Exercice 1 bis :
//
//1 - Création d'un système de gestion d'inventaire simple avec std::vector :
//	Créez un programme qui simule un inventaire pour un jeu vidéo.Chaque item de l'inventaire sera représenté par un nom (chaîne de caractères) et un poids (entier).
//Utilisez un std::vector pour stocker les items.
//Ajoutez des fonctions pour :
//Ajouter un item dans l'inventaire.
//Supprimer un item en fonction de son nom.
//Trouver un item spécifique et afficher ses détails(nom et poids).
//Trier les items dans l'inventaire par nom (ordre alphabétique) ou par poids (ordre croissant ou décroissant).
//Afficher le contenu complet de l'inventaire avec le poids total des items.
//2 - Filtrage d'items selon des critères dynamiques :
//Implémentez une fonction qui permet de filtrer les items de l'inventaire selon un critère donné (par exemple, les items de poids supérieur à une valeur spécifiée ou ceux dont le nom commence par une certaine lettre).
//Utilisez l'algorithme std::remove_if avec une fonction lambda pour effectuer ce filtrage.
//3 - Calcul de statistiques sur l'inventaire :
//Ajoutez des fonctionnalités pour calculer des statistiques sur l'inventaire :
//Poids moyen des items.
//Poids total des items.
//Nombre d'items pesant plus qu'un seuil donné.
//4 - Gestion de la capacité maximale de l'inventaire :
//Ajoutez une capacité maximale à l'inventaire (par exemple, 100 unités de poids). Si l'ajout d'un item dépasse cette capacité, le programme doit refuser l'ajout et afficher un message d'erreur.
//Implémentez une fonction pour optimiser l'inventaire en retirant les items les moins lourds jusqu'à ce que le poids total soit inférieur à la capacité maximale.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Inventory
{ // class pour initialiser l'inventaire et le poids des items
private:
    std::vector <std::pair<std::string, int>> items;
    int maxCapacity;

public:
    Inventory(int capacity) : maxCapacity(capacity) {}

    void displayInventory() const
    {
        int totalWeight = 0;
        std::cout << "Inventory items:" << std::endl;
        for (const auto& item : items)
        {      // affiche l'item ainsi que son poid
            std::cout << " - " << item.first << " (Weight: " << item.second << ")" << std::endl;
            totalWeight += item.second;
        }
        std::cout << "Total weight: " << totalWeight << "/" << maxCapacity << std::endl;
    }

    bool addItem(const std::string& name, int weight)
    { // add item à l'inventaire
        int currentWeight = getTotalWeight();

        if (currentWeight + weight > maxCapacity)
        { // si il n'y a plus d'espace
            std::cout << "Cannot add " << name << ", weight exceeds the max capacity!" << std::endl;
            return false;
        }
        items.push_back({ name, weight });
        return true;
    }

    void removeItem(const std::string& name) // suppr item
    {
        auto rmItem = std::remove(items.begin(), items.end(), [&](const std::pair<std::string, int> item)
            {
            return item.first == name;
            });

        if (rmItem != items.end())
        {
            items.erase(rmItem, items.end());
            std::cout << "Item " << name << " removed." << std::endl;
        }
    }

    void findItem(const std::string& name) const // trouver un item et ses spécificités
    {
        auto iSearch = std::find(items.begin(), items.end(), [&](const std::pair<std::string, int>& item) {
            return item.first == name;
            });

        if (iSearch != items.end())
        {
            std::cout << "Item found: " << iSearch->first << " Weight: " << iSearch->second << std::endl;
        }
        else
        {
            std::cout << "Item not found." << std::endl;
        }

    }

    void sortItemByName() // tri par nom
    {
        std::sort(items.begin(), items.end(), [](const std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
            return a.first < b.first;
            });
    }

    void sortItemByWeight(bool ascending = true) // tri par poids en ordre croissant
    {
        std::sort(items.begin(), items.end(), [&](const std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
            return ascending ? a.second < b.second : a.second > b.second;
            });
    }


    int getTotalWeight() // pour calculer moyenne poids
    {
        return std::accumulate(items.begin(), items.end(), 0, [](int sum, std::pair<std::string, int>& item) {
            return sum + item.second;
            });
    }





};




int main() {
    Inventory inventory(50); // capacité max

    // items
    inventory.addItem("Sword", 10);
    inventory.addItem("Shield", 15);
    inventory.addItem("Potion", 2);
    inventory.addItem("Helmet", 5);

    // display
    inventory.displayInventory();

    // remove
    inventory.removeItem("Potion");

    // chercher
    inventory.findItem("Shield");

    // sort
    inventory.sortItemByName();
    inventory.displayInventory();

    // sort poid (ascendant)
    inventory.sortItemByWeight(true);
    inventory.displayInventory();

    return 0;
}
