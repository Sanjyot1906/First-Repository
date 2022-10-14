#include <iostream>
using namespace std;
struct student
{
    int roll_no;
    string name;
    float marks;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void get_data(student S[], int total)
{
    cout << "-----------------------------" << endl;
    cout << "Input Student Database : " << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < total; i++)
    {
        cout << "Student Data No. : " << i + 1 << endl;
        cout << "-----------------------------";
        cout << "\nEnter Name : ";
        cin >> S[i].name;
        cout << "\nEnter Roll No. : ";
        cin >> S[i].roll_no;
        cout << "\nEnter the marks : ";
        cin >> S[i].marks;
        cout << "-----------------------------" << endl;
    }
    cout << "Database Saved !" << endl;
    cout << "-----------------------------" << endl;
}

void print_database(student S[], int total)
{
    cout << "   *** STUDENT DATABASE ***" << endl;
    cout << "-----------------------------" << endl;
    cout << "Roll No."
         << "\t"
         << "Name"
         << "\t\t"
         << "Marks" << endl;
    for (int i = 0; i < total; i++)
    {
        cout << " " << S[i].roll_no << "\t\t" << S[i].name << "\t\t" << S[i].marks << endl;
    }
}

void bubble_sort(student S[], int total)
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (S[j].roll_no > S[j + 1].roll_no)
            {
                swap(S[j], S[j + 1]);
            }
        }
    }
}

void insertion_sort(student S[], int total)
{
    int i, j;
    student key;
    for (i = 1; i < total; i++)
    {
        key = S[i];
        j = i - 1;
        while (j >= 0 && S[j].name > key.name)
        {
            S[j + 1] = S[j];
            j = j - 1;
        }
        S[j + 1] = key;
    }
}

void selection_sort(student S[], int total){
    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){
            if(S[i].marks > S[j].marks){
                swap(S[i], S[j]);
            }
        }
    }
}

int search_stud(student S[], int total){
    int search, flag = 0;
    cout << "Enter marks to be search : ";
    cin >> search;
    for(int i = 0; i < total; i++){
        if(search == S[i].marks){
            return i;
            flag += 1; // Changes to be done.
        }
    }
    if(flag == 0){
        return -1;
    }
}

int main()
{
    int total, ch;
    cout << "Enter the total number of students : ";
    cin >> total;
    struct student S[total];
    get_data(S, total);
    do
    {
        cout << "1. Sort Student by roll numbers." << endl;
        cout << "2. Sort Students by Names." << endl;
        cout << "3. Sort Students by Marks." << endl;
        cout << "4. Search Student by name." << endl;
        cout << "0. Close the Database." << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        cout << endl;
        cout << "-----------------------------" << endl;
        switch (ch)
        {
        case 1:
        {
            bubble_sort(S, total);
            print_database(S, total);
            cout << "-----------------------------" << endl;
            break;
        }
        case 2:
        {
            insertion_sort(S, total);
            print_database(S, total);
            cout << "-----------------------------" << endl;
            break;
        }
        case 3:
        {
            selection_sort(S, total);
            print_database(S, total);
            cout << "-----------------------------" << endl;
            break;
        }
        case 4:
        {
            search_stud(S, total);
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "Invalid Choice !" << endl;
            cout << "-----------------------------" << endl;
            break;
        }
        }
    } while (ch != 0);
    return 0;
}