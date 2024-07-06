#include <iostream>
#include <string>


class Fruit {
private:
    std::string name; 
    double weight;    

public:
  
    Fruit(std::string n = "", double w = 0.0) : name(n), weight(w) {}

   
    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    void setName(std::string n) { name = n; }
    void setWeight(double w) { weight = w; }
};


class Tree {
private:
    std::string name;       
    int age;                
    int amount;           
    int fruitCount;         
    Fruit* fruits;          

public:
   
    Tree(std::string n, int a, int cap) : name(n), age(a), amount(cap), fruitCount(0) {
        fruits = new Fruit[amount];
    }

    
    ~Tree() {
        delete[] fruits;
    }

   
    std::string getName() const { return name; }
    int getAge() const { return age; }
    int getFruitCount() const { return fruitCount; }
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }

    
    void createFruit(std::string fruitName, double fruitWeight) {
        if (fruitCount < amount) {
            fruits[fruitCount++] = Fruit(fruitName, fruitWeight);
        }
        else {
            std::cout << "Нет места для добавления нового фрукта." << std::endl;
        }
    }

   
    Fruit dropFruit(int index) {
        if (index < 0 || index >= fruitCount) {
            std::cout << "Индекс вне диапазона." << std::endl;
            throw "Error";
        }
        Fruit droppedFruit = fruits[index];
        for (int i = index; i < fruitCount - 1; ++i) {
            fruits[i] = fruits[i + 1];
        }
        --fruitCount;
        return droppedFruit;
    }

    
    void printTree() const {
        std::cout << "Дерево: " << name << "\nВозраст: " << age << " лет\nПлоды:\n";
        for (int i = 0; i < fruitCount; i++) {
            std::cout << "Название плода: " << fruits[i].getName() << ", Вес плода: " << fruits[i].getWeight() << " Кг\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    Tree appleTree("Яблоня", 3, 6);

 
    appleTree.createFruit("Яблоко", 0.15);
    appleTree.createFruit("Яблоко", 0.20);
    appleTree.createFruit("Яблоко", 0.30);
    appleTree.createFruit("Яблоко", 0.55);
    appleTree.createFruit("Яблоко", 0.44);
    appleTree.createFruit("Яблоко", 0.33);
    
    appleTree.printTree();

   
    Fruit droppedFruit = appleTree.dropFruit(5);
    std::cout << "Упало яблоко весом: " << droppedFruit.getWeight() << " Кг\n";

    
    appleTree.printTree();

    return 0;
}