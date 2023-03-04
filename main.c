/*
Naimul Haque Bhuyan Rahat
ID: 213902100
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Variable Declare
char ch[10][130]={"Ena Express","Green Line","Volvo Express","Eagle Express","Shyamoli Paribahan"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int busno;
// Function Prototype
void login();
void bus();
void booking();//for booking the tickets
void status();//for printing the status by user input
void cancle();
void name_number(int booking,char numstr[100]);
int read_number(int busno);//for reading the number from the file
void read_name(int busno);//for reading the name from the file
void status_1(int busno);//for printing the status while booking ticket
//Main Function
int main(){
 login();
 int num, i;
 do{
 system("cls");
 printf("\n\n\n");
 printf("============================== Welcome To Bus Reservation System
==============================\n\n");
 printf("\t\t\t\t\t[1]=> View Bus List\n\n");
 printf("\t\t\t\t\t[2]=> Book Tickets\n\n");
 printf("\t\t\t\t\t[3]=> Cancle Booking\n\n");
 printf("\t\t\t\t\t[4]=> Bus Status Board\n\n");
 printf("\t\t\t\t\t[5]=> Exit\n\n");
 printf("============================== *********************************
==============================\n\n");
 printf("\t\t\t Enter Your Choice: ");
 scanf("%d",&num);
 switch(num){
 case 1:
 bus();
 break;
 case 2:
 booking();
 break;
 case 3:
 cancle();
 break;
 case 4:
 status();
 break;
 }
 getch();
 }while(num!=5);
 system("cls");
 printf("\n\n\n\t\t\t Thanks For Using Our System \t\t\t");
 getch();
 return 0;
}
// Function Defnation
void login(){
 int a=0,i=0;
 char uname[10];
 char pword[10];
 char user[10]="user";
 char pass[10]="pass";
 do{
 system("cls");
 printf("\n ============================= Login Form ============================== ");
 printf("\n");
 printf("Enter User Name: ");
 scanf("%s",&uname);
 printf("\n");
 printf("Enter Password: ");
 scanf("%s",&pword);
 printf("\n");
 if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0){
 printf("\n\n\n Welcome To Our System!!! LOGIN IS SUCCESSFUL");
 printf("\n PRESS ANY KEY TO CONTINUE....\n");
 getch();
 break;
 }
 else{
 printf("\n\n\n LOGIN UNSUCCESSFUL!!");
 a++;
 getch();
 }
 }while(a<=2);
 if(a>2){
 printf("\n Sorry You've Enter The Wrong User Name or Password Three Times\n");
 getch();
 exit(0);
 }
 system("cls");
}
void bus(){
 system("cls");
 int i;
 printf("\n\n\n");
 printf("============================== Welcome To Bus Reservation System ==============================\n\n\n");
 for(i=0;i<5;i++){
 printf("\t\t\t\t\t[%d] => %s\n\n",i+1,ch[i]);
 }
 printf("Press Any Key To Return....");
}
void booking()
{
 int i=0;
 char numstr[100];
 system("cls");
 printf("=========================================== BUS RESERVATION SYSTEM
============================================\n\n\n");//for entering train number
 bus();//for seeing bus least
 printf("Enter the Bus number:--->");
 scanf("%d",&busno);
 system("cls");
 printf("=========================================== BUS RESERVATION SYSTEM
============================================\n\n\n");//for selecting coach
 printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
 status_1(busno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
 if(busno == 1)
 {
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
 }else if(busno == 2)
 {
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
 }else if(busno == 3)
 {
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
 }
 else if(busno == 4)
 {
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
 }
 else if(busno == 5)
 {
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
 }
 seat1=atoi(str1);//covert the string into number
 if(seat1 <= 0)
 {
 printf("There is no blank seat in this bus ");
 }else
 {
 printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
 printf("\n\t\t\t\tNumber of Tickets:----->");
 scanf("%d",&booking);
 printf("\n");
 seat1=seat1-booking;
 itoa(busno,numstr,10);
 name_number(booking,numstr);
 printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
 itoa(seat1, str1, 10);
 //for reading the seats from the user.
 if(busno == 1)
 {
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
 }
 else if(busno == 2)
 {
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
 fclose(f1);
 }
 else if(busno == 3)
 {
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
 fclose(f1);
 }
 else if(busno == 4)
 {
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
 fclose(f1);
 }
 else if(busno == 5)
 {
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
 }
 }
}
void name_number(int booking,char numstr[100])
{
 char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
 int number;
 FILE *a,*b;
 int i=0;
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 a = fopen(tempstr1,"a");//for open the file to write the name in the file
 b = fopen(tempstr2,"a");//for open the file for writing the number in the file
 for(i=0; i<booking; i++)//for entering the person name and seat number in the file
 {
 printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
 printf("\t\t\t\tEnter the seat number:--->");
 scanf("%d",&number);
 printf("\t\t\t\tEnter the name of person:--->");
 scanf("%s",name[number-1]);

printf("\n=============================================================================================
=========\n\n");
 printf("\n");
 itoa(number, tempstr, 10);
 fprintf(a,"%s ",name[number-1]);
 fprintf(b,"%s ",tempstr);
 }
 fclose(a);
 fclose(b);
}
int read_number(int busno)//for putting the numeric value in the array
{
 char tempstr[100],tempstr2[12]="number";
 FILE *a,*b;
 char numstr[100];
 int i=0,j=0,k;
 itoa(busno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr2,numstr);
 a = fopen(tempstr2,"a+");//for open the file to write the name in the file
 while(!feof(a))
 {
 number[i][j] = fgetc(a);
 if(number[i][j] == ' ')
 {
 j=0;
 i++;
 }
 else
 {
 j++;
 }
 }
 k=i;
 for(i=0; i<k; i++)
 {
 num1[i] = atoi(number[i]);
 }
 fclose(a);
 return k;
}
void read_name(int busno)//for putting the numeric value in the array
{
 char tempstr1[12]="status";
 FILE *b;
 char numstr[100];
 int i=0,j=0,k=0;
 itoa(busno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 b = fopen(tempstr1,"a+");//for open the file to write the name in the file
 while(!feof(b))
 {
 name[i][j] = fgetc(b);
 if(name[i][j] == ' ')
 {
 j=0;
 i++;
 }
 else
 {
 j++;
 }
 }
 name[i][j]='\0';
 k=i;
 fclose(b);
}
void status()
{
 system("cls");
 printf("=========================================== BUS RESERVATION SYSTEM
============================================\n\n\n");
 int i,busno,index=0,j;
 printf("Enter the number of bus:---->");
 scanf("%d",&busno);
 j=read_number(busno);
 read_name(busno);

printf("___________________________________________________________________________________________________________
_________\n");
 printf(" Bus.no-->%d---->%s \n",busno,ch[busno-1]);

printf("___________________________________________________________________________________________________________
_________\n");
 char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty
","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty
","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
 for(i=0; i<j; i++)
 {
 strcpy(tempname[num1[i]],name[i]);
 }
 for(i=0; i<8; i++)
 {
 printf("\t\t\t\t");
 for(j=0; j<4; j++)
 {
 printf("%d.%s\t",index+1,tempname[index+1]);
 index++;
 }
 printf("\n");
 }
}
void status_1(int busno)
{
 printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
 system("cls");
 printf("=========================================== BUS RESERVATION SYSTEM
============================================\n\n\n");
 int i,index=0,j;
 j=read_number(busno);
 read_name(busno);
 char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty
","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty
","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
 for(i=0; i<j; i++)
 {
 strcpy(tempname[num1[i]],name[i]);
 }
 for(i=0; i<8; i++)
 {
 printf("\t\t\t\t");
 for(j=0; j<4; j++)
 {
 printf("%d.%s\t",index+1,tempname[index+1]);
 index++;
 }
 printf("\n");
}
}
void cancle()
{
int seat_no,i,j;
char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
printf("Enter the bus number:---->");
scanf("%d",&busno);
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
strcat(tempstr2,numstr);
read_number(busno);
read_name(busno);
status_1(busno);
printf("Enter the seat number:--->");
scanf("%d",&seat_no);
FILE *a,*b;
a = fopen(tempstr1,"w+");
b = fopen(tempstr2,"w+");
for(i=0; i<32; i++)
{
 if(num1[i] == seat_no)
 {
 for(j=0; j<32; j++)
 {
 if(num1[j] != seat_no && num1[j] != 0)
 {
 fprintf(b,"%d ",num1[j]);
 fprintf(a,"%s",name[j]);
 }
 else if(num1[j] == seat_no && num1[j] != 0)
 {
 strcpy(name[j],"Empty ");
 }
 }
 }
}
 fclose(a);
 fclose(b);
 printf("\n\n");

printf("===============================================================================================
=======\n");
 printf("\t\t\t\tYour 200 tk. has been Returned\t\t\t\n");

printf("===============================================================================================
=======\n");
}
