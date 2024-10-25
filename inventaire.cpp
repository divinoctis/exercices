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
// InventorySystem.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Pour accumulate

struct Item {
    std::string nom;
    int poids;

    // Constructeur simple pour faciliter la création d'items
    Item(const std::string& n, int p) : nom(n), poids(p) {}
};

void ajouterItem(std::vector<Item>& inventaire, const std::string& nom, int poids) {
    inventaire.emplace_back(nom, poids);
}

void supprimerItem(std::vector<Item>& inventaire, const std::string& nom) {
    inventaire.erase(
        std::remove_if(inventaire.begin(), inventaire.end(),
            [&](const Item& item) { return item.nom == nom; }),
        inventaire.end());
}

void trouverItem(const std::vector<Item>& inventaire, const std::string& nom) {
    auto it = std::find_if(inventaire.begin(), inventaire.end(),
        [&](const Item& item) { return item.nom == nom; });
    if (it != inventaire.end()) {
        std::cout << "Item trouve : " << it->nom << ", Poids : " << it->poids << std::endl;
    }
    else {
        std::cout << "Item " << nom << " non trouve." << std::endl;
    }
}

void trierParNom(std::vector<Item>& inventaire) {
    std::sort(inventaire.begin(), inventaire.end(),
        [](const Item& a, const Item& b) { return a.nom < b.nom; });
}

void trierParPoids(std::vector<Item>& inventaire, bool decroissant = false) {
    std::sort(inventaire.begin(), inventaire.end(),
        [=](const Item& a, const Item& b) {
            return decroissant ? a.poids > b.poids : a.poids < b.poids;
        });
}

void filtrerItems(std::vector<Item>& inventaire, int seuil) {
    inventaire.erase(
        std::remove_if(inventaire.begin(), inventaire.end(),
            [=](const Item& item) { return item.poids < seuil; }),
        inventaire.end());
}

int poidsTotal(const std::vector<Item>& inventaire) {
    return std::accumulate(inventaire.begin(), inventaire.end(), 0,
        [](int total, const Item& item) {
            return total + item.poids;
        });
}

double poidsMoyen(const std::vector<Item>& inventaire) {
    if (inventaire.empty()) return 0.0;
    return static_cast<double>(poidsTotal(inventaire)) / inventaire.size();
}

int nombreItemsPlusLourds(const std::vector<Item>& inventaire, int seuil) {
    return std::count_if(inventaire.begin(), inventaire.end(),
        [=](const Item& item) { return item.poids > seuil; });
}

void optimiserInventaire(std::vector<Item>& inventaire, int capaciteMax) {
    while (poidsTotal(inventaire) > capaciteMax) {
        // Supprimer l'item le moins lourd
        auto it = std::min_element(inventaire.begin(), inventaire.end(),
            [](const Item& a, const Item& b) {
                return a.poids < b.poids;
            });
        if (it != inventaire.end()) {
            std::cout << "Suppression de l'item le moins lourd : " << it->nom << std::endl;
            inventaire.erase(it);
        }
    }
}

int main()
{
    std::vector<Item> inventaire;

    // Ajouter des items à l'inventaire
    ajouterItem(inventaire, "Epee", 10);
    ajouterItem(inventaire, "Bouclier", 15);
    ajouterItem(inventaire, "Potion", 2);
    ajouterItem(inventaire, "Armure", 25);

    // Afficher les items
    std::cout << "Inventaire initial : " << std::endl;
    for (const auto& item : inventaire) {
        std::cout << item.nom << " (Poids: " << item.poids << ")" << std::endl;
    }

    // Trier l'inventaire par poids
    trierParPoids(inventaire);
    std::cout << "\nInventaire trie par poids : " << std::endl;
    for (const auto& item : inventaire) {
        std::cout << item.nom << " (Poids: " << item.poids << ")" << std::endl;
    }

    // Supprimer un item
    supprimerItem(inventaire, "Potion");
    std::cout << "\nl'objet Potion a ete supprime" << std::endl;
    // Afficher l'inventaire après suppression
    std::cout << "\nInventaire apres suppression : " << std::endl;
    for (const auto& item : inventaire) {
        std::cout << item.nom << " (Poids: " << item.poids << ")" << std::endl;
    }

    // Optimiser l'inventaire (capacité maximale de 30)
    optimiserInventaire(inventaire, 30);
    std::cout << "\n L'inventaire à un poids de 30" << std::endl;
    // Afficher l'inventaire optimisé
    std::cout << "\nInventaire optimise : " << std::endl;
    for (const auto& item : inventaire) {
        std::cout << item.nom << " (Poids: " << item.poids << ")" << std::endl;
    }

    return 0;
}
