#include <iostream>
#include <vector>
#include <cstdlib>

class Character
{
public:
    Character(const std::string& name, int life, int atk, int def) : name(name), life(life), atk(atk), def(def) {}

    void showStats() const
    {
        std::cout << "Name: " << name << ", Life: " << life << ", Attack: " << atk << ", Defence: " << def << std::endl;
    }

private:
    std::string name;
    int life;
    int atk;
    int def;
};

template<typename T>
double calcStats(T* attributs, int size)
{
    double somme = 0;
    for (int i = 0; i < size; ++i)
    {
        somme += attributs[i];
    }
    return somme / size;
}

template<>
double calcStats<float>(float* attributs, int size)
{
    double somme = 0;
    double sommeCarres = 0;
    for (int i = 0; i < size; ++i)
    {
        somme += attributs[i];
        sommeCarres += attributs[i] * attributs[i];
    }
    double moyenne = somme / size;
    return sommeCarres / size - moyenne * moyenne;
}

template<typename T>
T* generateAttributs(int size, T initValue)
{
    T* attributs = new T[size];
    for (int i = 0; i < size; ++i)
    {
        attributs[i] = initValue + (rand() % 10);
    }
    return attributs;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int size = 5;
    Character medic("Medic", 50, 5, 2);
    Character hunter("Hunter", 70, 15, 5);
    Character warlock("Warlock", 100, 10, 10);

    medic.showStats();
    hunter.showStats();
    warlock.showStats();

    float* attributsMedic = generateAttributs(size, 50.0f);
    float* attributsHunter = generateAttributs(size, 70.0f);
    float* attributsWarlock = generateAttributs(size, 100.0f);

    delete[] attributsMedic;
    delete[] attributsHunter;
    delete[] attributsWarlock;

    return 0;
}
