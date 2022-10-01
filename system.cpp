#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// max books = 100;
// max users = 20;

int choice {};
int bindx {};
int uindx{};
int id{};
string uname{};
string bname{};

int status{};   // 1 = borowing book, 0 = not borrowing

struct book
{
    int id;
    string name;
    int quantity;
    int borrowd;
    book()
    {
        id = 0; name =""; quantity = borrowd = 0;
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
    int borrowed_id[100];
    int borrowed_q;

    user()
    {
        id = 0; name =""; borrowed_q = 0;
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
    int count = 0;
    for (int i = 0; i <= bindx; i++)
    {
        if (prefix == books[i].name.substr(0,l))
        cout << books[i].name << endl;
        else
        count++;
    }
    if (bindx+1 == count)   
    cout << "No books with such prefix" << endl;
}

// search users by name
int search_name(book books[],user users[],string name, int indx)
{
    for (int i = 0; i <= uindx; i++)
    {
        if (name == users[i].name)
        {
            users[i].borrowed_id[users[i].borrowed_q] = books[indx].id;
            users[i].borrowed_q++;
            books[indx].borrowd++;
        }
    }   
}

// search book by name
void search_name(book books[],string name)
{
    for (int i = 0; i <= bindx; i++)
    {
        if (name == books[i].name)
        {
            id = books[i].id;
        }
    }   
}

// borrowing books
void borrow (book books[], user users[])
{
    cout << "Enter username and books name :";
    cin >> uname >> bname;
    for(int i = 0; i < bindx; i++)
    {
        if (bname == books[i].name)
        {
            int indx = i;
            if (books[i].quantity > books[i].borrowd)
            {
                search_name(books,users,uname,indx);
                return;
            }
            else
            {
                cout << "sorry this book is nolonger unavilable" << endl;
                return;
            }
        }

    }
    cout << "sorry this book is unavilable" << endl;  
}

// to sort books by name
bool compare_name(book &a, book &b)
{
    return (a.name < b.name);
}

// to sort books by id
bool compare_id(book &a, book &b)
{
    return (a.id < b.id);
}

// prining sorted books / users
void print(int x, book books[], user users[])
{
    if (x == 4)
    {
        for (int i = 0; i < bindx; i++)
        cout << "ID = " << books[i].id << " , name = " << books[i].name << " , total quantity = " << books[i].quantity << " , total borrowed =  " << (books[i].quantity - books[i].borrowd) << endl ;
    }
    else if (x == 5)
    {
        for (int i = 0; i < bindx; i++)
        cout << "ID = " << books[i].id << " , name = " << books[i].name << " , total quantity = " << books[i].quantity << " , total borrowed =  " << (books[i].quantity - books[i].borrowd) << endl ;
    }
    else if (x == 9)
    {
        for (int i = 0; i < uindx; i++)
        {
            cout << "ID = " << users[i].id << " , name = " << users[i].name << " , number of borrowed books = " << users[i].borrowed_q << " IDs of books : ";
            for (int j = 0; j < users[i].borrowed_q; j++)
            cout << users[i].borrowed_id[j] << "  ";
            
            cout << endl;
        }
    }
}

//print who borrowed book
void who_borrowd(book books[], user users[], string name)
{
    search_name(books,name);
    for (int i = 0; i < uindx; i++)
    {
        for (int j = 0; j < users[i].borrowed_q; j++)
        {
            if (users[i].borrowed_id[j] == id)
            cout << users[i]. name << endl;
        }
        
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
        if (!(choice >=1 && choice <= 10))
        {
            cout << "please enter a vaild input" << endl;
            continue;
        }
        else
        {
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
                cout << "Enter the name of the book :";
                cin >> bname;
                who_borrowd(books,users,bname);         
                break;
            }
            case 4:
            {
                sort (books,books+bindx,compare_id);
                print (choice,books,users);
                break;
            }
            case 5:
            {
                sort (books,books+bindx,compare_name);
                print (choice,books,users);
                break;
            }
            case 6:
            {
                users[uindx].add_user();
                break;
            }
            case 7:
            {
                borrow(books,users);
                break;
            }
            case 8:
            {

                break;
            }
            case 9:
            {
                print (choice,books,users);
                break;
            }
            case 10:
            {
                return 0;
           }
          }
        } 
        

    }
}