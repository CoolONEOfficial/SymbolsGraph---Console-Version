#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter words. Russian language not supported."<<endl<<"To mark the end write to new line '^Z'."<<endl<<endl;

    string word;
    // Add/Clear
    int symbols[256];
    for(int f = 0; f<256; f++)
    {
        symbols[f] = 0;
    }

    while(true)
    {
        cin>>word;
        if(cin.fail())
            break;

        // Merge
        for(int f = 0; f<word.size(); f++)
        {
            int iSymbol = word[f];
            symbols[iSymbol]++;
        }
    }
    cout<<endl;

    // Find max
    int maxSymbols = 0;

    for(int f = 0; f<256; f++)
    {
        if(symbols[f] > maxSymbols)
            maxSymbols = symbols[f];
    }

    // Write
    for(int f1 = 0; f1<maxSymbols; f1++)
    {
        cout<<" "<<maxSymbols-f1<<" ";
        for(int f2 = 0; f2<256; f2++)
        {
            if(symbols[f2] != 0)
            {
                if(symbols[f2] >= maxSymbols-f1)
                    cout<<"#";
                else
                    cout<<" ";
            }
        }
        cout<<endl;
    }

    cout<<endl<<"   ";
    for(int f2 = 0; f2<256; f2++)
    {
        if(symbols[f2] != 0)
        {
            char str = f2;
            cout<<str;
        }
    }

    cout<<endl<<endl;

    system("pause");

    return 0;
}
