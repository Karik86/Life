#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void disp (char** arr, int rw, int cl,int gen, int count)
{

    for (int i = 0; i < rw; i++)
    {
        for (int j = 0; j < cl; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Generation: " << gen << ".  " << "Alive cells: " << count << endl;
    cout << endl << endl;
    Sleep(1000);
    
}

int main()
{
    int rw, cl;
    ifstream fin("in.txt");
    fin >> rw >> cl;
    
    char** arr;
    arr = new char* [rw];
    for (int i = 0; i < rw; i++)
    {
        arr[i] = new char[cl];
    }

    for (int i = 0; i < rw; i++)
    {
        for (int j = 0; j < cl; j++) {
            arr[i][j] = '-';
        }
    }


    int row, col;
    int count = 0;
    while (fin >> row >> col)
    {
        if (row >= 0 && row < rw && col >= 0 && col < cl)
        {
            arr[row][col] = '*';
            count++;
        }
    }

    fin.close();
    
   

    for (int gen = 1; ; gen++)
    {
        for (int i = 0; i < rw; i++)
        {
            for (int j = 0; j < cl; j++) 
            {
                int k = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && (arr[i - 1][j - 1] == '*'|| arr[i - 1][j - 1] == '#')) k++;
                if (i - 1 >= 0 && j - 0 >= 0 && (arr[i - 1][j - 0] == '*'|| arr[i - 1][j - 0] == '#')) k++;
                if (i - 1 >= 0 && j + 1 < cl && (arr[i - 1][j + 1] == '*'|| arr[i - 1][j + 1] == '#')) k++;
                if (i - 0 >= 0 && j + 1 < cl && (arr[i - 0][j + 1] == '*'|| arr[i - 0][j + 1] == '#')) k++;
                if (i + 1 < rw && j + 1 < cl && (arr[i + 1][j + 1] == '*'|| arr[i + 1][j + 1] == '#')) k++;
                if (i + 1 < rw && j - 0 >= 0 && (arr[i + 1][j - 0] == '*'|| arr[i + 1][j - 0] == '#')) k++;
                if (i + 1 < rw && j - 1 >= 0 && (arr[i + 1][j - 1] == '*'|| arr[i + 1][j - 1] == '#')) k++;
                if (i - 0 >= 0 && j - 1 >= 0 && (arr[i - 0][j - 1] == '*'|| arr[i - 0][j - 1] == '#')) k++;

               // cout << k<<endl;

                if (arr[i][j] == '*') 
                {
                    if (k < 2 || k > 3)
                    {
                        arr[i][j] = '#';
                    }

                }
                else
                {
                    if (k == 3) 
                    {
                        arr[i][j] = '&';
                    }
                }
        
            }
        }
        bool flag = false;
        for (int i = 0; i < rw; i++)
        {
            for (int j = 0; j < cl; j++)
            {
                if (arr[i][j] == '#')
                {
                    arr[i][j] = '-';
                    count--;
                    flag = true;
                }
                if (arr[i][j] == '&')
                {
                    arr[i][j] = '*';
                    count++;
                    flag = true;
                }
            }
        }
         if (count==0||flag==false)
         {
             cout << "GAME OVER" << endl;
             break;
         }
        disp(arr, rw, cl, gen, count);
    }


    
   

    for (int i = 0; i < rw; i++) {

        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
