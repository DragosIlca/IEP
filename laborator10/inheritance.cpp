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

        Parrot(std::vector<std::string> words)
        : words(words)
        { };

        void virtual fly() {
            cout << "I can fly 10 kilometers\n";
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

int main() {

    std::vector<std::string> words;
    words.push_back("Mama");
    words.push_back("Tata");
    words.push_back("Papa");

    Parrot *parrot = new Parrot(words);
    parrot->fly();
    parrot->sound();
    parrot->printWords();
    return 0;
}