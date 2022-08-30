#include<iostream.h>
#define max 100
struct stack{
      char a[max];
      char beg;
      char end;
                  char mid;
      int top;
      };
 
// tao ngan xep rong
void creat_stack(stack &S)
          {
            S.top=0;
          }
 
// kiem tra ngan xep rong
int emty_stack(stack S)
          {
            if(S.top==0) return 1;
              else return 0;
          }  

void push(char beg,char mid,char end, stack &S)
 {
              if(S.top==max)
             cout<<"ngan xep day";
            else
              {
                S.a[S.beg]=beg;
                S.a[S.mid]=mid;
                S.a[S.end]=end;
                S.a[S.top]++;
               }
 }
 
//loai phan tu ra khoi stack
void pop(char &x,stack &S)
 {
     if(S.top==0)
         cout<<"ngan xep rong";
           else
             {
              x=S.a[S.top-1];
              S.top-- ;
 
             }
 
 }
// ham di chuyen thap ha noi
void move(int n,stack &S)
 {
  char x;
  int dem=0;
  creat_stack(S);
    if(emty_stack==0)
         push('A','B','C',S);
          while(emty_stack==0)
           pop(x,S);
           if(n==1)
            {
                dem++;
                cout<<dem<<" "<<"di chuyen tu"<<" "<<S.a[S.beg]<<" "<<"den"<<" "<<S.a[S.end];
            }
           
  //            else
     
 }
 
void main()
{
clrscr();
int n;
stack S;
cout<<"chuong trinh stack";
cout<<"\n nhap n="; cin>>n;
move(n,S);
getch();
}