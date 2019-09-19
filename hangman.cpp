//
//  main.cpp
//  hangman
//
//  Created by Abrish Sabri on 11/5/17.
//  Copyright © 2017 Abrish Sabri. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int i, wrong = 0, wguess = 0, present = 0, no = 0;
    string w1,w2;
    char c,ans,X;
    cout << "\n**** HANGMAN GAME ****";
    system("pause");
    system("cls");
    do
    {
        system("cls");
        no++;
        wrong = 0;
    srand((unsigned int)time(0));
    string words[3][4]{
            {"logan","thor","loki","batman"},
            {"amsterdam","berlin","dublin","rome"},
            {"dog","cat","monkey","tiger"}};
    w1 = w2 = words[rand()%3][rand()%4];
    for(i=0;i<w1.length();i++)
        w1[rand()%((w1.length())/2)] = '*';
    while(w1.compare(w2)!=0 && wrong < 6)
        {
            cout << "\n\n Guess a character in: ";
            for(i=0;i<w1.length();i++)
            {
                cout << w1[i];
            }
            cout <<"\n";
            cin >> c;
            for(i=0;i<w1.length();i++)
            {
                if (w2[i]==c)
                {
                    ++present;
                    if(w1[i]==c)
                    {
                        cout << "\n" << c << "is already present. ";
                        break;
                    }
                    else
                    {
                        w1[i] = c;
                    }
                }
            }
                if(present == 0)
                {
                    ++wrong;
                    cout << "\n"<<"Wrong Guess. You have " << 6-wrong << " chances left";
                }
                present = 0;
            }
            if(w1.compare(w2)==0)
            {
                cout << "\n Well Done \t The Word is: ";
                 for(i=0;i<w1.length();i++)
                 {
                     cout << w2[i];
                     
                 }
                cout << "\n Words Attempted: " << no << "Wrong Ans:" <<wguess;
                cout << "\n Play Again?(Y/N): ";
                cin >> ans;
                X =((ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N') ? ans:'n');
                
            }
            else
            {
                wguess++;
                cout << "\n\n";
                for (i=0; i<3; i++)
                cout << " Game Over!";
                cout << "The Word was: ";
                for(i=0;i<w1.length();i++)
                {
                    cout << w2[i];
                    
                }
                cout << "\n Words Attempted: " << no << "Wrong Ans:" <<wguess;
                cout << "\n Play Again?(Y/N): ";
                cin >> ans;
                X =((ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N') ? ans:'n');
            }
        
    }while (X == 'y' || X == 'Y');
    system("cls");
    return 0;
}






































