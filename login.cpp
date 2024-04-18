#include<iostream>
#include <fstream>          //to read write files
#include <string>

using namespace std;

void login();
void registration();
void forgot();

bool checkLogIn(){                      //checks if input uname and password are in database or not
    string username,password,u,p;       //u and p are to compare username and password

    cout<<"\t\tPlease Enter USername and Password: \n";
    cout<<"\t|| Username: ";
    cin>>username;
    cout<<"\t|| Password: ";
    cin>>password;

    ifstream read("userData\\"+username+".txt");    //searches for the username.txt file in userData folder(read is object name)
    read>>u>>p;

    if(u==username&&p==password)                //checking if username and password exists 
        return true;
    else 
        return false;
}



int main(){
    int choice;

    cout<<"\n\n\t\t           Welcome!\n\n";
    cout<<"\t|| Press 1 to LOGIN                    ||\n";
    cout<<"\t|| Press 2 to REGISTER                 ||\n";
    cout<<"\t|| Press 3 if you FORGOT your PASSWORD ||\n";
    cout<<"\t|| Press 4 to EXIT                     ||\n";
    cout<<"\n\t\tEnter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\tYou have exited the system, thankyou!\n\n";
            break;
        default:
            cout<<"\t\tInvalid input, please select from the options given.\n";
            main();
    }

    return 0;
}

void registration(){
    string username,password,color;
    
    cout<<"\n\t|| Enter a Username (no spaces allowed): ";
    cin>>username;
    cout<<"\t|| Enter a password (no spaces allowed): ";
    cin>>password;
    cout<<"\t|| Security Question (to recover your account)\n\t||What is your favorite color: ";
    cin>>color;
    
    ofstream file;
    file.open("userData\\"+username+".txt");
    file<<username<<endl<<password<<endl<<color;                //store user credentials in username.txt
    file.close();

    cout<<"\n\t\t\tSuccessfully Registered.";
    main();
    
}

void login(){

    if(!checkLogIn()){
        cout<<"\n\t\tInvalid Credentials!\n\t\tTry Again.";
        main();
    }
    else
        cout<<"\n\t\tSuccesful Login.";
    exit(0);
}

void forgot(){                              //password recovery section
    string username,u,p,c,color;
    cout<<"\n\t|| You forgot your password, lets try to recover your password.";
    cout<<"\n\t|| Enter your Username: ";
    cin>>username;

    ifstream file;
    file.open("userData\\"+username+".txt");
    if(file){                                                   //checks if username is correct
        cout<<"\n\t|| Answer the Question correctly to recover your password.";
        cout<<"\n\t   What is your favorite color: ";
        cin>>color;
        file>>u>>p>>c;
        if(c==color){
            cout<<"\n\t|| Hurray! Correct Answer. Your Password is: "<<p;
            main();
        }
        else{    
            cout<<"\n\t|| Wrong Answer. Try again later.";
            exit(0);
        }
    }
    else{
        cout<<"\n\t|| Username not found, try again later.";
        exit(0);
    }
}   