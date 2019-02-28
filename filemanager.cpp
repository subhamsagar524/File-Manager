#include<fstream>
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<dirent.h>

using namespace std;

int co_py();
int mo_ve();
int re_name();
int del();
int list_all();
int mrg();

int main()
{
    cout<<"File Manager ";
    cout<<"\n__________________________________________________________________";
    int x;
    char y;
    do
    {
        cout<<"\nChoose the Options>>>";
        cout<<"\n 1. Copy";
        cout<<"\n 2. Move";
        cout<<"\n 3. Rename";
        cout<<"\n 4. Delete";
        cout<<"\n 5. List All";
        cout<<"\n 6. Merge/Concade";
        cout<<"\n\n   >>> ";
        cin>>x;
        switch (x)
        {
            case 1:
                co_py();
                break;
            case 2:
                mo_ve();
                break;
            case 3:
                re_name();
                break;
            case 4:
                del();
                break;
            case 5:
                list_all();
                break;
            case 6:
                mrg();
                break;
            default:
                cout<<"Invalid Option (Enter the option again)";
                y = 'y';
        }
        cout<<"\n\nTry Again (Y/N)>>> ";
        cin>>y;
    } while(y == 'Y' || y == 'y');

    return 0;
}

int co_py()
{
    fstream a, b;
    char buffer[100];
    cout<<"Enter File Path>>> Copy From>>> ";
    char p1[100];
    cin.ignore();
    cin.getline(p1,100);
    cout<<"Enter File Path>>> Copy To>>> ";
    char p2[100];
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

int mo_ve()
{
    fstream a,b;
    char p1[100],p2[100],buffer[100];
    cout<<"Enter File Path>>> Move From>>> ";
    cin.ignore();
    cin.getline(p1,100);
    cout<<"Enter File Path>>> Move To>>> ";
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

int re_name()
{
    char pre_name[100], post_name[100];
    cout<<"Enter File Path>>> Rename From>>> ";
    cin.ignore();
    cin.getline(pre_name,100);
    cout<<"Enter File Path>>> Rename To>>> ";
    cin.getline(post_name,100);
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

int del()
{
    char path[100];
    cout<<"Enter File Path>>> To Delete>>> ";
    cin.ignore();
    cin.getline(path,100);
    try
    {
        if(remove(path))
            throw 1;
        cout<<"Successful...\nFile Deleted...";
    }
    catch(int i)
    {
        cout<<"Error deleting file...\n";
        return 0;
    }
}

int list_all()
{
    char path[100];
    cout<<"Enter Directory Path>>> To List>>> ";
    cin.ignore();
    cin.getline(path,100);
    DIR *directory = opendir(path);
    struct dirent *direntStruct;
    if (directory != NULL) 
    {
        while (direntStruct = readdir(directory)) 
        {
            printf("File Name: %s\n", direntStruct->d_name);
        }
    }
    closedir(directory);
    return 0;
}

int mrg()
{
     ifstream a,b;
     ofstream fout;
     char buffer, p1[100], p2[100], p3[100];
     cout<<"Enter File Path>>> First File to Merge>>> ";
     cin.ignore();
     cin.getline(p1,100);
     cout<<"Enter File Path>>> Second File to Merge>>> ";
     cin.getline(p2,100);
     cout<<"Enter File Path>>> Rename File to store The Merged File>>> ";
     cin.getline(p3,100);
     a.open(p1);
     b.open(p2);
     if(!a || !b)
          cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
     fout.open(p3);
     if(!fout)
          cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
     while(a.eof()==0)
     {
          a>>buffer;
          fout<<buffer;
     }
     while(b.eof()==0)
     {
          b>>buffer;
          fout<<buffer;
     }
     cout<<"File Merged Successfully...";
     a.close();
     b.close();
     fout.close();
     return 0;
}
