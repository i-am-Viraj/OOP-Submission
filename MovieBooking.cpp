#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

ifstream fin;
ofstream fout;
int tkt_no = 100;
char name[30];
char mob_no[15];
char movie[30];
char date[30];
char time[] = "06pm-09pm";
int seat = 0;
int amt = 450;

void book_tkt();
void print_ticket();
void view_movie();
void view_record();
void cancel_ticket();

int main()
{
    int choice;
    do
    {
        system("cls");
        cout<<"\n\t\t\t\t\t WELCOME TO INOX MULTIPLEX ";
        cout<<"\n\t\t\t -----------------------------------------------------------------";
        cout<<"\n\t\t\t |                                                               |";
        cout<<"\n\t\t\t |   Press<1> View Available Movies                               |";
        cout<<"\n\t\t\t |   Press<2> Book Ticket                                         |";
        cout<<"\n\t\t\t |   Press<3> View Record                                         |";
        cout<<"\n\t\t\t |   Press<4> Cancel Ticket                                       |";
        cout<<"\n\t\t\t |   Press<0> Exit                                                |";
        cout<<"\n\t\t\t |                                                               |";
        cout<<"\n\t\t\t -----------------------------------------------------------------";
        cout<<"\nEnter Your Choice ";
        cin>>choice;
        switch(choice)
        {
            case 1 : view_movie(); break;
            case 2 : book_tkt(); break;
            case 3 : view_record(); break;
            case 4 : cancel_ticket(); break;
            case 0 : cout << "\nHave a Nice Day !!!! "; break;
            default: cout << "\nInvalid Option";
        }
        getch();
    } while(choice != 0);
    return 0;
}

void view_movie()
{
    cout<<"\n Movie \t\tCode\t \tTicket Price\t\tTime Slot ";
    printf("\n Avengers\t789 \t \t450 Rs \t\t\t06pm-09pm ");
}

void book_tkt()
{
    fout.open("inox_multi.txt",ios::app);
    tkt_no++;
    seat++;
    fout << tkt_no;
    cout<<"\nEnter Name : ";
    cin>>name;
    fout<<"\t\t"<<name;
    cout<<"\nEnter Mobile No : ";
    cin>>mob_no;
    fout<<"\t\t"<<mob_no;
    cout<<"\nEnter Date : ";
    cin>>date;
    fout<<"\t\t"<<date;
    fout<<"\t\t"<<seat;
    fout<<"\t\t"<<time;
    fout<<"\t\t"<<amt;
    fout.close();
    cout<<"\nTICKET BOOKED SUCCESSFULLY";
    print_ticket();
}

void print_ticket()
{
    cout<<"\nTicket No. : "<<tkt_no;
    cout<<"\nName : "<<name;
    cout<<"\nMobile No. : "<<mob_no;
    cout<<"\nDate : "<<date;
    cout<<"\nSeat No. : "<<seat;
    cout<<"\nTime : 06pm-09pm";
    cout<<"\nAmount : 450 Rs";
}

void view_record()
{
    int c;
    fin.open("inox_multi.txt");
    if (tkt_no == 100)
    {
        cout << "\nNo Tickets Booked ";
    }
    else
    {
        cout << "\nTicket No\tName\tMobile No\t    Date\tSeat No\t Time\t      Amount";
        while (!fin.eof()) 
        {
            fin >> tkt_no;
            fin >> name;
            fin >> mob_no;
            fin >> date;
            fin >> seat;
            fin >> time;
            fin >> amt;

            cout << "\n" << tkt_no << "\t\t" << name << "\t" << mob_no << "\t" << date << "\t" << seat << "\t " << time << "\t " << amt;
        }
    }
    fin.close();
}


void cancel_ticket()
{
    int f, no;
    fin.open("inox_multi.txt");
    if (!fin)
    {
        cout << "\nNo Ticket Booked ";
    }
    else
    {
        fout.open("duplicate.txt");
        cout << "\nEnter Ticket No. ";
        cin >> no;
        f = 0;
        while (fin >> tkt_no >> name >> mob_no >> date >> seat >> time >> amt)
        {
            if (no == tkt_no)
            {
                f = 1;
                continue; 
            }
            fout << "\n" << tkt_no << "\t\t" << name << "\t\t" << mob_no << "\t\t" << date << "\t\t" << seat << "\t\t" << time << "\t\t" << amt;
        }
        if (f == 0)
        {
            cout << "\nTicket Not Found ";
        }
        else
        {
            cout << "\nTicket is Cancelled Successfully";
            seat--;
            tkt_no--;
        }
        fout.close();
        fin.close();
        remove("inox_multi.txt");
        rename("duplicate.txt", "inox_multi.txt");
    }
}