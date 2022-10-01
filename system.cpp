#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// max books = 100;
// max users = 20;

int choice {};
int bindx {};
int uindx{};

int status{};   // 1 = borowing book, 0 = not borrowing

struct book
{
    int id;
    string name;
    int quantity;
    book()
    {
        id = 0; name =""; quantity = 0;
    }

    void add_book() 
    {
        cout << "Enter id,name,quantity :" << endl;
        cin >> id >> name >> quantity;
        bindx++;
    }

};


struct user
{
    int id;
    string name;
    int status;

    user()
    {
        id = 0; name =""; status = 0;
    }

    void add_user()
    {
        cout << "Enter id,name :" << endl;
        cin >> id >> name;
        uindx++;
    }
};

//printing menu;
void menu()
{
    cout << "Library menu: "<< endl;
    cout << "1) add book "<< endl;
    cout << "2) search book by prefix "<< endl;
    cout << "3) print who borrowed book by name "<< endl;
    cout << "4) print books by ID "<< endl;
    cout << "5) print books by name "<< endl;
    cout << "6) add user "<< endl;
    cout << "7) user borrow book "<< endl;
    cout << "8) user print book "<< endl;
    cout << "9) print users "<< endl;
    cout << "10) Exit "<< endl;
    cout << "Enter your choice : ";
    cin >> choice;
}


//search using prefix
void search(book books[])
{
    string prefix {};
    cin >> prefix;
    int l = prefix.length();
    for (int i = 0; i <= bindx; i++)
    {
        if (prefix == books[i].name.substr(0,l))
        cout << books[i].name << endl;
    }   
}

bool compare_name(book &a, book &b)
{
    return (a.name < b.name);
}

bool compare_id(book &a, book &b)
{
    return (a.id < b.id);
}

// prining sorted books
void print(int x, book books[])
{
    if (x == 4)
    {
        for (int i = 0; i < bindx; i++)
        cout << "ID = " << books[i].id << " , name = " << books[i].name << " , total quantity = " << books[i].quantity << " , total borrowed = 0 " << endl ;
    }
    else if (x == 5)
    {
        for (int i = 0; i < bindx; i++)
        cout << "ID = " << books[i].id << " , name = " << books[i].name << " , total quantity = " << books[i].quantity << " , total borrowed = 0 " << endl ;
    }
}





int main()
{
    book books[100];
    user users[20];
    int indx;


    while (true)
    {
        menu();
        switch (choice)
        {
            case 1:
            {
                books[bindx].add_book();
                break;
            }
            case 2:
            {
                search(books);
                break;
            }
            case 3:
            {                
                break;
            }
            case 4:
            {
                sort (books,books+bindx,compare_id);
                print (choice,books);
                break;
            }
            case 5:
            {
                sort (books,books+bindx,compare_name);
                print (choice,books);
                break;
            }
            case 6:
            {
                users[uindx].add_user();
                break;
            }
            case 7:
            {

                break;
            }
            case 8:
            {

                break;
            }
            case 9:
            {

                break;
            }
            case 10:
            {
                return 0;
            }
        }

    }
}