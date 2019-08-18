#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<cstring>
#include<conio.h>
using namespace std;
void starline();

void gotoxy(int x,int y)
{
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

   }

int main()
{
int no=0;
bool har=0;
int b=0;
int ans[10];
float score=0;
int anshard[10]={2,2,1,3,1,2,3,3,2,3};//answers of hard questions
int ansmedium[10]={2,2,3,4,2,4,1,3,3,4};//answers of medium level questions
int anseasy[10]={3,1,2,3,1,1,3,2,2,4};//answers of easy level questions
int ansin;//user input of answer will be taken into this variable
int k=0;
int h=0,i=0,j=0,l=0,ea=0,q=0;
float correct=0;
string x[10];
string y[10]; //  all these array of string variables store the MCQ's of hard,easy and medium file
string z[10];

char s[100];
ifstream Medium;
ifstream Easy;
ifstream Hard;

int e=0,m=0,n=0,main=0;
starline();
starline();
gotoxy(50,2);
cout<<"WELCOME TO THE QUIZ"<<'\n';
starline();
starline();

 cout<<"Press ENTER to continue";
   getchar();
while(main<=9)
{
    Medium.open("Medium.txt");//opening the medium file

    for(int i=0;i<=9;i++)
    {
        getline(Medium,x[i],'\n');
        if(i==main)
        {
        no++;//This just shows the MCQ's number
        system("cls");//clears the screen
        cout<<"Q="<<endl;
        cout<<"("<<no<<")"<<x[i]<<endl;
        cout<<"please select your answer from the above four options:"<<endl;
        cin>>ansin;
        }
    }
if(ansin==ansmedium[main])
{
    correct++;/*this variable updates the correct value everytime the user enters the correct answer which keeps track of how many
               questions did the user entered correctly*/
    score=score+4;
    q=main-ea;
    h++;
    Hard.open("Hard.txt");/*if the answer to the medium level question is right then the user will get the question from Hard question set*/

    for(int j=0;j<=9;j++)
    {

         getline(Hard,y[j],'\n');

          if(j==q)
          {
               no++;//This just shows the MCQ's number
               system("cls");
               cout<<"Q="<<endl;
               cout<<"("<<no<<")"<<y[j]<<endl;
               cout<<"please select your answer from the above four options:"<<endl;
               cin>>ansin;
               if(ansin==anshard[j])
               {
                   correct++;
                   score=score+5;
               }

          }
    }
 }
 else //if the answer to the medium question is wrong then the program will start throwing questions from easy file
 {
     ea++;
     l=main-h;
     Easy.open("Easy.txt");
    for(int k=0;k<=9;k++)
    {
        getline(Easy,z[k],'\n');

        if(k==l)
        {
            no++;
            system("cls");
            cout<<"Q="<<endl;
            cout<<"("<<no<<")"<<z[k]<<endl;
            cin>>ansin;

            if(ansin==anseasy[k])
            {
                correct++;
                score=score+3;
            }
        }

    }
 }

 main++;

 if(main==10)
 {
     if(ea<=9 ||h<=9)
     {
         while(ea<=9)
         {
             Easy.open("Easy.txt");
             for(int t=0;t<=10;t++)
             {
                 getline(Easy,z[t],'\n');
                 if(t==ea)
                 {
                     no++;
                     system("cls");
                     cout<<"Q="<<endl;
                     cout<<"("<<no<<")"<<z[t]<<endl;
                     cout<<"please select and enter your answer from the above four options:"<<endl;
                     cin>>ansin;
                     if(ansin==anseasy[t])
                     {
                         correct++;
                         score=score+3;
                     }
                 }

             }
             ea++;
         }
if(ea==10)
{
    while(h<=10)
    {
        Hard.open("Hard.txt");
         for(int w=0;w<=10;w++)
         {
             getline(Hard,y[w],'\n');
             if(h==w)
             {
                 no++;
                 system("cls");
                 cout<<"Q="<<endl;
                 cout<<"("<<no<<")"<<y[w]<<endl;
                 cout<<"please select and enter your answer from the above options"<<endl;
                 cin>>ansin;
                 if(ansin==anshard[w])
                 {
                     correct++;
                     score=score+5;
                 }
             }
         }
         h++;
         if(h==10)
            break;
    }
   }
  }
 }
}
system("cls");
cout<<"your score in the quiz is"<<score<<"out of 120";
cout<<endl<<"you answered"<<correct<<" questions correctly";
cout<<endl<<"you answered"<<(30-correct)<<"question wrong";
 return 0;
}
void starline()
{
    for(int j=0;j<119;j++)
    {
        cout<<"*";
    }
    cout<<endl;
}
