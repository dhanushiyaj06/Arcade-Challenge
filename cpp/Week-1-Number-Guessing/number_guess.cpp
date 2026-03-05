#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int l=1;
int u=100;
string checkGuess(int secret, int guess) {
    if(guess>secret)
    {
        return "LOW";
    }
    else if(guess<secret)
    {
        return "HIGH";
    }
    else
    {
        return "CORRECT";
    }
}

int calculateScore(int attempts) {
if(attempts<=3)
{
    return 100;
}
else if(attempts<=6)
{
    return 70;
}
else if(attempts<=10)
{
    return 40;
}
else
{
    return 10;
}
}

string giveHint(int secret, vector<int> history)
{
    int v=history.back();
    int diff=abs(v-secret);
    if(diff<=5)
    {
        return "Very Close!";
    }
    else if(diff<=10)
    {
        return "Close!";
    }
    else
    {
        if(v<secret)
        {
            l=v+1;
        }
        else
        {
            u=v-1;
        }
        return "Try between "+to_string(l)+" and "+to_string(u);
    }
}


// -------- CLI PART (DO NOT MODIFY) --------

int main() {

    srand(time(0));
    int secret = rand() % 100 + 1;

    vector<int> history;
    int attempts = 0;

    cout << "Welcome to Smart Number Guessing Game!" << endl;

    while (true) {
        int guess;
        cout << "Enter guess: ";
        cin >> guess;

        attempts++;
        history.push_back(guess);

        string result = checkGuess(secret, guess);

        if (result == "CORRECT") {
            cout << "Correct!" << endl;
            cout << "Score: " << calculateScore(attempts) << endl;
            break;
        }

        cout << result << endl;
        cout << "Hint: " << giveHint(secret, history) << endl;
    }

    return 0;
}
