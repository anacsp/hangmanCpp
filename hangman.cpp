#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string defInWord();
char inLetter();
int * wordLetterCompare(string, char, string *);
string outputDrawingUpdate(int);

class LifeCounter
{
    private:
        int total_lives;
    
    public:
        
        LifeCounter()
        {
            total_lives = 6;
        }

        void setLifeCounter(int new_total_lives)
        {
            total_lives = new_total_lives;
        }
        
        int getLifeCounter()
        {
            return total_lives;
        }
};

int main()
{
    LifeCounter lifeCount;

    int * p_correct_guesses;
    int correct_guesses = 0;
    int total_correct_guesses = 0;
    char new_guess;
    string output_drawing, word_to_guess;

    system("clear");
    cout << "Welcome to the Hangman game!" << endl;
    cout << outputDrawingUpdate(0) << endl;

    word_to_guess = defInWord();

    /* Creates a string with x underlines, x = the length of the word entered by player 1 */
    string underlines(word_to_guess.length(), '-');

    system("clear");
    cout << "~ Hangman Game ~" << endl;

    while(1)
    {
        output_drawing =  outputDrawingUpdate(lifeCount.getLifeCounter());
        cout << output_drawing << endl;

        cout << "Word: " << underlines << endl << endl;

        new_guess = inLetter();
        system("clear"); 
        cout << "~ Hangman Game ~" << endl;

        p_correct_guesses = wordLetterCompare(word_to_guess, new_guess, &underlines);
        correct_guesses = *(p_correct_guesses + 1);
        total_correct_guesses = total_correct_guesses + correct_guesses;
 
        cout << "You have already guessed " << total_correct_guesses <<" letter(s)!" << endl;

        if(0 == *p_correct_guesses)
        {
            if(0 == correct_guesses)
            {
                lifeCount.setLifeCounter(lifeCount.getLifeCounter() - 1);
            }

            if(0 == lifeCount.getLifeCounter())
            {
                cout << outputDrawingUpdate(lifeCount.getLifeCounter()) << endl;
                cout << "Game Over. :(" << endl;
                cout << "The word was: " << word_to_guess << endl;
                break;
            }
            else
            {
                if(total_correct_guesses == word_to_guess.length())
                {
                    cout << output_drawing << endl;
                    cout << "Congratulations! You guessed the word!"<< endl;
                    cout << "The word is: " << word_to_guess << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "The letter " << new_guess << " has laready been typed!" << endl;
        }

        cout << "You have " << lifeCount.getLifeCounter() << " lives left." << endl;
    }

    return 0;
}

/*  Gets the new word and returns it
*/
string defInWord()
{
    string new_word;

    cout << "Player 1, enter a word: ";
    cin >> new_word;

    return new_word;
}

/*  Gets a new letter and returns it
*/
char inLetter()
{
    char new_letter;

    cout << "Player 2, enter a letter: ";
    cin >> new_letter;

    return new_letter;
}

/*  Compares each new letter to each character from the word to be guessed
*   Saves which letters have already been entered
*/
int * wordLetterCompare(string incoming_word, char incoming_letter, string *new_letter_place)
{
    int tam = incoming_word.length();
    int correct_guesses = 0;
    int flag_repeated_letter = 0;

    static char old_letters[28] = {0};
    char old_letters_shifted[28] = {0};
    static int ret[1];

    for(int i = 0; i < sizeof(old_letters); i++)
    {
        if(old_letters[i] != incoming_letter)
        {
            flag_repeated_letter = 0;
        }
        else
        {
            flag_repeated_letter = 1;
            break;
        }
    }

    if(0 == flag_repeated_letter)
    {
        old_letters[0] = incoming_letter;

        memcpy(&old_letters_shifted[1], &old_letters[0], 27);
        memcpy(&old_letters[0], &old_letters_shifted[0], 28);

        for(int i = 0; i < tam; i++)
        {
            if(incoming_word[i] == incoming_letter)
            {
                correct_guesses++;
                (*new_letter_place)[i] = incoming_letter;
            }
        }   
    }

    ret[0] = flag_repeated_letter;
    ret[1] = correct_guesses;

    return ret;
}

/*  Updates the output drawing according to the number of lives left
*/
string outputDrawingUpdate(int life)
{
    string output_drawing = "";

    switch(life)
    {
        case 0:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {ºnº}      \n \
    |     /|\\      \n \
    |      |        \n \
    |    ./ \\.     \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break;
        case 1:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|\\      \n \
    |      |        \n \
    |    ./         \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break;
        case 2:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|\\      \n \
    |      |        \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~" ;
            break;
        case 3:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|        \n \
    |      |        \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break;
        case 4:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /         \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break; 
        case 5:
            output_drawing = 
"...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break;
        case 6:
            output_drawing = 
"...___________    \n \
    | /             \n \
    |/              \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
            break;
    }
    
    return output_drawing;
}