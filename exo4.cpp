#include <iostream>
#include <cmath>

template<typename T>
class Projectile
{
protected:
    float speed;
    T damage;
    float posX;
    float posY;
    float dirX;
    float dirY;

public:
    Projectile(float v, T d, float posX, float posY, float dirX, float dirY) : speed(v), damage(d), posX(posX), posY(posY), dirX(dirX), dirY(dirY){}

    virtual void move()
    {
        posX += dirX * speed;
        posY += dirY * speed;
    }

    virtual void show() = 0;
};

template<typename T>
class Ball : public Projectile<T>
{
public:
    Ball(float v, T d, float posX, float posY, float dirX, float dirY) : Projectile<T>(v, d, posX, posY, dirX, dirY) {}

    void show() override
    {
        std::cout << "Ball : damage = " << this->damage << ", Position = ("
            << this->posX << ", " << this->posY << ")\n";
    }
};

template<typename T>
class Grenade : public Projectile<T>
{
private:
    float exploRadius;

public:
    Grenade(float v, T d, float posX, float posY, float dirX, float dirY, float rayon) : Projectile<T>(v, d, posX, posY, dirX, dirY), exploRadius(rayon) {}

    void show() override
    {
        std::cout << "Grenade : damage = " << this->damage << ", Explosive radius = "
            << exploRadius << ", Position = (" << this->posX << ", "
            << this->posY << ")\n";
    }
};

int main()
{
    Ball<int> Ball(200.0f, 50, 0.0f, 0.0f, 1.0f, 0.0f);
    Grenade<float> grenade(100.0f, 20.5f, 0.0f, 0.0f, 1.0f, 1.0f, 3.0f);

    Ball.move();
    grenade.move();

    Ball.show();
    grenade.show();

    return 0;
}
