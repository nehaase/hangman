#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip> //for table output

using namespace std;
int winstreak = 0;
int maxwinstreak = 30; //adaptable


///donaudampfschifffahrtselektrizitaetenhauptbetriebswerkbauunterbeamtengesellschaft
///grundstuecksverkehrsgenehmigungszustaendigkeitsuebertragungsverordnung
///rindfleischetikettierungsueberwachungsaufgabenuebertragungsgesetz

string chooseWord() {
    vector<string> words = {
        "tentomax", "intuitive", "cicalese", "erection", "election", "ejection", "affection", "direction", "section", "crisis", "existance", "kangaroo", "dontfoolyourself", "crafting", "villager", "obsession", "aerospace", "airplane", "rocket", "calculation", "integers", "engineering", "computer", "determined", "waterbottle", "holidays", "christmasparty", "laptop", "ballistic", "missile", "intercontinental", "combustion", "rocketry", "reckless", "sponsor", "internship", "depression", "bachelor", "hangman", "minecraft", "paperclip", "computation", "spaceflight", "nineeleven", "ridiculous", "artificial", "christmas", "holydays", "apartment", "stiffness", "properties", "steel", "steal", "crying", "selfconsciousness", "selfconfidence", "function", "iterative", "relentlessly",    "polution", "programming", "jazz", "array", "kindness", "executioner", "simulation", "transposing", "kernel", "jesus", "mississippi", "fuzzy", "buzzer", "jinx", "pneumonoultramicroscopicsilicovolcanoconiosis", "craziness", "unbelievable", "sorting", "madness", "studitum", "twisted", "confusion", "Interchange", "advertisement", "hellscape", "cucumber", "ananas", "banana", "watermelon", "peach", "elephant", "cherry", "potato", "carrot", "plumpudding", "broccoli", "giraffe", "zebra", "tiger", "savannah", "bicycle", "adventure", "happiness", "friendship", "laughter", "rainbow", "sunshine", "butterfly", "curiosity", "mystery", "melody", "whisper", "freedom", "harmony", "kindness", "blossom", "treasure", "gentle", "twilight", "enchant", "silhouette", "whispering", "radiant", "graceful", "gratitude", "rudimentary", "challenge", "peace", "pearcing", "toddler", "canooing", "carbon", "composites", "carnival", "oktoberfest", "chinatown", "supercomputer", "intelligence", "artificial", "lucrative", "supervision", "subletting", "kinematic", "cinematic", "grizzlybear", "antarctica", "minecraft", "navigation", "orientation", "gentrification", "creative", "envelope", "development", "charging", "harm", "essentials", "distance", "thunderstorm", "candy", "fishing", "server", "supernova", "felony", "tragedy", "humor", "tendency", "tolerarnce", "helpless", "benchmark", "diving", "dreaming", "healing", "handicap", "coffeine", "expiration", "exmatriculation", "excellence", "harddrive", "haunted", "eclipse", "mansion", "salary", "entrance", "lemonade", "foundational", "valve", "flower", "arizona", "blackbox", "organization", "institute", "gaming", "stationary", "determined", "elastostatics", "rooftop", "levitation", "storage", "harddrive", "aerodynamics", "stress", "result", "exanimationesincidamus", "dictator", "democracy", "lunch", "bunch", "crunch", "dinner", "diner", "brunch", "fine", "blind", "kind", "behind", "right", "correct", "wrong", "horrible", "deduction", "trigonometry", "dumb", "plumpudding", "smart", "card", "disregard", "regard", "now", "have", "gave", "wave", "hover", "spooky", "hard", "soft", "small", "time", "tone", "terracotta", "hat", "hut", "but", "buttqwerrt"};
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void displayWord(const string &word, const vector<char> &guessedLetters) {
    for (int i = 0; i < word.length(); i++) {
        char letter = word[i];
        bool letterGuessed = false;
        
        for (int j = 0; j < guessedLetters.size(); j++) {
            if (letter == guessedLetters[j]) {
                letterGuessed = true;
                break;
            }
        }
        if (letterGuessed) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
        
    }
}

bool hasGuessedWord(const string &word, const vector<char> &guessedLetters) {
    for (int i = 0; i < word.length(); i++) {
        char letter = word[i];
        bool letterGuessed = false;
        for (int j = 0; j < guessedLetters.size(); j++) {
            if (letter == guessedLetters[j]) {
                letterGuessed = true;
                break;
            }
        }
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}

void displayHangman(int &maxAttempts) {
    switch (maxAttempts) {
        case 10:
            cout << "\n\n\n\n\n\n\n";
            break;
        case 9:
            cout << "\n\n\n\n\n\n_____________\n";
            break;
        case 8:
            cout << "\n   |\n   |\n   |\n   |\n   |\n___|__________\n";
            break;
        case 7:
            cout << "   ______\n   |\n   |\n   |\n   |\n   |\n___|__________\n";
            break;
        case 6:
            cout << "   ______\n   |    |\n   |\n   |\n   |\n   |\n___|__________\n";
            break;
        case 5:
            cout << "   ______\n   |    |\n   |    O\n   |\n   |\n   |\n___|__________\n";
            break;
        case 4:
            cout << "   ______\n   |    |\n   |    O\n   |    |\n   |\n   |\n___|__________\n";
            break;
        case 3:
            cout << "   ______\n   |    |\n   |    O\n   |   -|\n   |\n   |\n___|__________\n";
            break;
        case 2:
            cout << "   ______\n   |    |\n   |    O\n   |   -|-\n   |\n   |\n___|__________\n";
            break;
        case 1:
            cout << "   ______\n   |    |\n   |    O\n   |   -|-\n   |    /\n   |\n___|__________\n";
            break;
        case 0:
            cout << "   ______\n   |    |\n   |    O\n   |   -|-\n   |   /|\n   |\n___|__________\n";
        default:
            break;
    }
}

/*
void hangman_AI_1() {
    ;
}
*/

void game() {
    bool alreadyguessed_var = false;
    bool firstround = true;
    bool correctGuess = false;
    
    string word = chooseWord();
    vector<char> guessedLetters;
    int maxAttempts = 10;
    
    while (maxAttempts > 0) {
        
        //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        
        cout << "\n\n======================================================================" << endl;
        cout << "\n\n\n\n";
        if (firstround) {
            cout << "Welcome to Hangman!" << endl;
            firstround = false;
        } else {
            if (alreadyguessed_var) {
                cout << "* already guessed!" << endl;
                alreadyguessed_var = false;
            } else {
                if (correctGuess) {
                    cout << "* correct guess!" << endl;
                } else {
                    cout << "* wrong guess!" << endl;
                    maxAttempts--;
                }
            }
        }
        
        displayHangman(maxAttempts);
        
        if (maxAttempts > 0) {
            cout << "Incorrect attempts left: " << maxAttempts << endl;
            cout << "guessed Letters: { ";
            for (int i = 0; i < guessedLetters.size(); i++) {
                cout << guessedLetters[i] << " ";
            }
            cout << "}" << endl;
            displayWord(word, guessedLetters);
            char guess;
            cout << endl << "Enter a letter: ";
            cin >> guess;
            // trigger hangman AI
            bool alreadyGuessed = false;
            for (int i = 0; i < guessedLetters.size(); i++) {
                if (guess == guessedLetters[i]) {
                    alreadyGuessed = true;
                    break;
                }
            }
            if (alreadyGuessed) {
                alreadyguessed_var = true;
            } else {
                guessedLetters.push_back(guess);
                correctGuess = false;
                for (int j = 0; j < word.length(); j++) {
                    if (guess == word[j]) {
                        correctGuess = true;
                        break;
                    }
                }
            }
        } else if (maxAttempts == 0) {
            cout << "======================================================================" << endl;
            cout << left << setw(55) << "GAME OVER! :( " << setw(13) << "streak: " << winstreak << endl;
            //cout << "GAME OVER! :(                     streak: " << winstreak << endl;
            cout << "your word was: " << left << setw(40) << word << setw(13) << "max streak: " << maxwinstreak << endl;
            //cout << "your word was: " << word << "        max streak: " << maxwinstreak << endl;
            winstreak = 0;
        }
        
        if (hasGuessedWord(word, guessedLetters)) {
            winstreak += 1;
            if (winstreak > maxwinstreak)
                maxwinstreak = winstreak;
            cout << "======================================================================" << endl;
            cout << "complete word: " << left << setw(40) << word << setw(13) << " streak: " << winstreak << endl;
            //cout << "*** " << word << " ***                     streak: " << winstreak << endl;
            cout << left << setw(55) << "WINNER WINNER, CHICKEN DINNER!" << setw(13) << " max streak: " << maxwinstreak << endl;
            //cout << "WINNER WINNER, CHICKEN DINNER!             max streak:" << maxwinstreak << endl;
            break;
        }
    }
}

int main() {
    bool running = true;
    string playagain;
    while (running) {
        game();
        running = false;
        cout << "enter 'y' to play again: ";
        cin >> playagain;
        if (playagain == "y")
            running = true;
    }
    return 0;
}
