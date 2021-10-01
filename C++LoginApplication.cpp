//Created by Canyon Davidson
// 10/1/2021

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void CreateAccount()
{
    string username;
    string password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Account successfully created" << endl;
}

void UserLogin()
{
    //CHANGE TO BOOL, ONLY VOID FOR TESTING
    string userUsername;
    string userPassword;
    string savedUsername;
    string savedPassword;

    cout << "Enter username: " << endl;
    cin >> userUsername;
    cout << "Enter password: " << endl;
    cin >> userPassword;

    ifstream file(userUsername + ".txt");
    getline(file, savedUsername);
    getline(file, savedPassword);

    if (userUsername != savedUsername || userPassword != savedPassword)
    {
        cout << "Username or Password incorrect" << endl;
    }
    else
    {
        cout << "User has logged in" << endl;
    }
}

bool IsDigit(const string& str)
{
    for (const char& c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }

    return true;
}

void OptionsList()
{
    cout << "Choose from the following options";
    cout << "\n1: Create an account";
    cout << "\n2: Exisiting user login";
    cout << "\n3: Exit" << endl;
}


int main()
{
    string choice;

    OptionsList();
    cin >> choice;


    while (choice != "3")
    {
        while (!IsDigit(choice))
        {
            cout << "Invalid answer, please try again" << endl;
            cout << "**************************************************\n" << endl;
            OptionsList();
            cin >> choice;
        }

        if (choice == "1")
        {
            CreateAccount();
        }
        else if (choice == "2")
        {
            UserLogin();
        }
        else
        {
            cout << "Invalid choice, try again" << endl;
        }

        cout << "**************************************************\n" << endl;

        OptionsList();
        cin >> choice;
    }

    cout << "Exiting program, have a nice day!" << endl;
}

