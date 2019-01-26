#include<fstream>
#include<iostream>
#include<cstdio>

using namespace std;

int copy();
int move();
int rename();

int main()
{
    cout<<"File Manager (Copy and Move inside Files  :)";
    cout<<"\n__________________________________________________________________";
    int x;
    char y;
    do
    {
        cout<<"\nChoose the Options>>>";
        cout<<"\n 1. Copy";
        cout<<"\n 2. Move";
        cout<<"\n 3. Rename";
        cout<<"\n\n   >>> ";
        cin>>x;
        switch (x)
        {
            case 1:
                copy();
                break;
            case 2:
                move();
                break;
            case 3:
                rename();
                break;
            default:
                cout<<"Invalid Option (Enter the option again)";
                y = 'y';
        }
        cout<<"\nTry Again (Y/N)>>> ";
        cin>>y;
    } while(y == 'Y' || y == 'y');

    return 0;
}

int copy()
{
    fstream a, b;
    char buffer[100];
    cout<<"Enter File Path>>> Copy From>>> ";
    char p1[100];
    cin.ignore();
    cin.getline(p1,100);
    cout<<"Enter File Path>>> Copy To>>> ";
    char p2[100];
    ofstream c(p2);
    cin.getline(p2,100);
    try
    {
        a.open(p1,ios::in|ios::binary);
        if(!a)
            throw 1;
        try
        {
            b.open(p2,ios::out|ios::binary);
            if(!b)
                throw 1;
            while(!a.eof())
            {
                a.getline(buffer,100);
                b<<buffer<<"\n";
            }
        }
        catch(int i)
        {
            cout<<"Error Writing file...\n";
            return 0;
        }
    }
    catch(int i)
    {
        cout<<"Error opening File...\n";
        return 0;
    }
    a.close();
    b.close();
    cout<<"Data Transfer Successful...\nFile Copied...";
    return 0;
}

int move()
{
    fstream a,b;
    char p1[100],p2[100],buffer[100];
    cout<<"Enter File Path>>> Move From>>> ";
    cin.ignore();
    cin.getline(p1,100);
    cout<<"Enter File Path>>> Move To>>> ";
    cin.getline(p2,100);
    ofstream c(p2);
    try
    {
        a.open(p1,ios::in|ios::binary);
        if(!a)
            throw 1;
        try
        {
            b.open(p2,ios::out|ios::binary);
            if(!b)
                throw 1;
            while(!a.eof())
            {
                a.getline(buffer,100);
                b<<buffer<<"\n";
            }
        }
        catch(int i)
        {
            cout<<"Error Writing file...\n";
            return 0;
        }
    }
    catch(int i)
    {
        cout<<"Error opening File...\n";
        return 0;
    }
    a.close();
    b.close();
    try
    {
        if(remove(p1))
            throw 1;
        cout<<"Data Transfer Successful...\nFile Moved...";
    }
    catch(int i)
    {
        cout<<"Error moving file...\n";
        return 0;
    }
    return 0;
}

int rename()
{
    char pre_name[100], post_name[100];
    cout<<"Enter File Path>>> Rename From>>> ";
    cin.ignore();
    cin.getline(pre_name,100);
    cout<<"Enter File Path>>> Rename To>>> ";
    cin.getline(post_name,100);
        if (!pre_name)
            throw 1;
        try
        {
            if (rename(pre_name,post_name))
                throw 1;
            cout<<"Successful...\nFile Renamed";
        }
        catch(int i)
        {
            cout<<"Error renaming File...\n";
            return 0;
        }
}