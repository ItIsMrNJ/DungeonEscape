#include <iostream>
#include <cstdlib>

using namespace std;



bool IsWall(int x , int y)
{
    return
    (x == 3 && y == 3) ||
    (x == 6 && y == 3) ||
    (x == 3 && y == 6) ||
    (x == 6 && y == 6);
}

void ClearScreen()
{
    #ifdef _WIN32 
        system("cls");
    #else
        system("clear");
    #endif
}

void pause()
{
    #ifdef _WIN32
        system("pause");
    #else
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    #endif
}

int main()
{
    string player = " @ " , wall = " # " , key = " * " , exit = " E " , empty = " . ";
    int PlayerX = 5 , PlayerY = 5;
    bool HasKey = false;
    bool Can_I_Exit = false;
    bool Game = true;



    while(Game)
    {
        ClearScreen();
        for(int y = 0; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                if(PlayerX == x && PlayerY == y)
                {
                    
                    cout << player;
                }
                //wall
                else if(x == 3 && y == 3)
                {
                    cout << wall;
                }
                else if(x == 6 && y == 3)
                {
                    cout << wall;
                }
                else if(x == 3 && y == 6)
                {
                    cout << wall;
                }
                else if(x == 6 && y == 6)
                {
                    cout << wall;
                }
                //key
                else if(x == 2 && y == 4)
                {
                    cout << key;
                }
                //exit
                else if(x == 9 && y == 9)
                {
                    cout << exit;
                }
                //empty
                else
                {
                    cout << empty;
                }
            }
            cout << endl;
        }
        char GetKey;
        cout << "Enter: "; cin >> GetKey;

        if(GetKey == 'w')
        {
            if(!IsWall(PlayerX , PlayerY - 1))
            PlayerY--;
        }
        else if(GetKey == 'a')
        {
            if(!IsWall(PlayerX - 1, PlayerY))
            PlayerX--;
        }
        else if(GetKey == 's')
        {
            if(!IsWall(PlayerX , PlayerY + 1))
            PlayerY++;
        }
        if(GetKey == 'd')
        {
            if(!IsWall(PlayerX + 1 , PlayerY))
            PlayerX++;
        }
        //Got a key
        if (PlayerX == 2 && PlayerY == 4)
        {
            HasKey = true;
            cout << "\nYou Got a Key";
            key = " . ";
        }
        //Exit
        if (HasKey == false && PlayerX == 9 && PlayerY == 9)
        {
            cout << "\nYou dont have a KEY !";
        }
        else if (HasKey == true && PlayerX == 9 && PlayerY == 9)
        {
            Can_I_Exit = true;
            Game = false;
        }
    }
    cout << "\nYou WON !!!\n";
    pause();
    return 0;
}
