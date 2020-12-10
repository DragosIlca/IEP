#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bird {
    public:
        virtual void fly() = 0;
        virtual void sound() = 0;
};

class Parrot: public Bird {
    public:
        std::vector<std::string> words;
        int distance;

        Parrot(std::vector<std::string> words)
        : words(words)
        { 
            distance = rand();
        };

        void virtual fly() {
            cout << "I can fly " << distance << " kilometers\n";
        };

        void virtual sound() {
            cout << "prrrrrrr\n";
        };

        void printWords() {
            cout << "These are the words i know: \n";
            for (int i = 0; i < words.size(); i++) {
                cout << words[i] << "\n";
            };
        };
};

class Chicken: public Bird{
    public:
        Chicken() {
            if(count >= 30) {
                throw std::exception();
            };
            cout << count << "\n";
            count ++;
            distance = rand() % 10 + 1;
        };

        static int count;
        int distance;
        
        void virtual fly() {
            cout << "I can fly " << distance << " kilometers\n";
        };

        void virtual sound() {
            cout << "crrrrrrr\n";
        };

        void sell(Bird &bird) {
            cout << "Chicken sold\n";
            sound();
            cout << "Bird bought\n";
            bird.sound(); 
        };
};

int Chicken::count = 0;

Chicken *grup[30];

int main() {

    std::vector<std::string> words;
    words.push_back("Mama");
    words.push_back("Tata");
    words.push_back("Papa");

    Parrot *parrot = new Parrot(words);
    parrot->fly();
    parrot->sound();
    parrot->printWords();

    Chicken *chicken = new Chicken();

    chicken->sell(*parrot);

    for(int i = 0; i<30; i++) {
        grup[i] = new Chicken();
    }

    chicken->fly();
    chicken->sound();
    return 0;
}
