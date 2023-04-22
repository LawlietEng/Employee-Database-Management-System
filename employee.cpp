#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
void add();
void view();
void lit();
void modify();
void delet();
void waitForEnter(void);
class employee
{
public:
    int  empid;
    char name[30];
    char desig[20];
    float  salary;
    int  exp;
    int  age;
    char eduqua[20];

    void fp()
    {
        system("cls");
        int choice;
        cout<<"\n\n\n\t\t\t\tEMPLOYEE DATABASE\n\n\n";
        cout<<"\t\t\t*/ 1.View list of all employees. /*\n\n";
        cout<<"\t\t      */ 2.Search for an employee.     /*\n\n";
        cout<<"\t\t    */ 3.Add data of a new employee. /*\n\n";
        cout<<"\t\t  */ 4.Modify data of an employee. /*\n\n";
        cout<<"\t\t*/ 5.Delete data of an employee. /*\n\n";
        cout<<"\t      */ 6.Exit. \t\t       /*\n\n";
        cout<<"\t\t";
        cin>>choice;
        switch (choice)
        {
        case 1 :
            lit();
            waitForEnter();
            break;
        case 2 :
            view();
            waitForEnter();
            break;
        case 3 :
            add();
            waitForEnter();
            break;
        case 4 :
            modify();
            waitForEnter();
            break;
        case 5 :
            delet();
            waitForEnter();
            break;
        case 6 :
            system("cls");
            exit(0);
        default :
            cout<<"\tIncorrect choice\n";


        }
    }
} a;
void waitForEnter(void)
{
    cout<<"\n\n\nPress enter to go back\n\n";
    cin.get();
    cin.get();
    a.fp();
}
void view()
{
    system("cls");
    char found='f';
    int emid;
    cout<<"Enter employee ID\n";
    cin>>emid;
    ifstream fin("Database.txt",ios::in|ios::binary);
    while(fin.read((char*)&a,sizeof(a)))
    {
        found='y';
        if(a.empid==emid)
        {
            cout<<"\n------------------------------------------\nEmployee ID \t\t   - " <<a.empid<<"\t\t\nName of employee\t   - ";
            cout<<a.name<<"  \nDesignation\t\t   - " << a.desig;
            cout<<"  \t\nSalary \t\t\t   - "<<a.salary<<"   \t   \nExperience \t\t   - "<<a.exp<<"    \t   \nAge \t\t\t   - "<<a.age;
            cout<<"   \t\nEducational Qualifications - "<<a.eduqua<<"\n------------------------------------------\n\n\n";
            break;
        }
    }
    if(found=='f')
        cout<<"\n\nNo record exist\n";
}
void add()
{
    system("cls");
    char cho;
    cout<<"Enter employee ID\n";
    cin>>a.empid;
    cout<<"Enter employee name\n";
    cin.get();
    cin.getline(a.name,30);
    cout<<"Enter employee designation\n";
    cin>>a.desig;
    cout<<"Enter employee salary\n";
    cin>>a.salary;
    cout<<"Enter employee experience\n";
    cin>>a.exp;
    cout<<"Enter employee age\n";
    cin>>a.age;
    cout<<"Enter employee educational qualifications - Bachelors/Masters\n";
    cin>>a.eduqua;
    cout<<"\n\nEnter Y to save this information\n";
    cin>>cho;
    if(cho=='y'||cho=='Y')
    {
        ofstream fout("Database.txt",ios::app|ios::binary);
        fout.write((char*)&a,sizeof(a));
        fout.close();
        fout.seekp(0);
        cout<<"Employee data added\n";
    }
    else
        cout<<"Employee not added to database\n";
}
void modify()
{
    system("cls");
    char found='f';
    int emid,pos;
    fstream fout("Database.txt",ios::out|ios::in|ios::binary);
    cout<<"Enter employee ID\n";
    cin>>emid;
    while(!fout.eof())
    {
        pos=fout.tellg();
        fout.read((char*)&a,sizeof(a));
        if(a.empid==emid)
        {
            found='t';
            cout<<"\n------------------------------------------\nEmployee ID\t\t   - " <<a.empid<<"\nName of employee\t   - ";
            cout<<a.name<<"\nDesignation \t\t   - " << a.desig;
            cout<<"\nSalary \t\t\t   - "<<a.salary<<"\nExperience \t\t   - "<<a.exp<<"\nAge \t\t\t   - ";
            cout<<a.age<<"\nEducational Qualifications - "<<a.eduqua;
            cout<<"\n------------------------------------------\nEnter new details\n\n";
            cout<<"Enter new designation\n";
            cin>>a.desig;
            cout<<"Enter new salary\n";
            cin>>a.salary;
            cout<<"Employee data modified\n";
            fout.seekg(pos);
            fout.write((char*)&a,sizeof(a));
            break;
        }
    }
}
void delet()
{
    system("cls");
    char found='f';
    char choice;
    ifstream fin("Database.txt",ios::in);
    ofstream fout("temp.txt",ios::out);
    int emid;
    cout<<"Enter the employee id\n";
    cin>>emid;
    while(fin.read((char*)&a,sizeof(a)))
    {
        if(a.empid==emid)
        {
            found='t';
            cout<<"\nName - "<<a.name<<"\tDesignation - "<<a.desig;
            cout<<"\n\nAre you sure you want to delete this employee details(Y/N)?\n";
            cin>>choice;
            if(choice=='n'||choice=='N')
            {
                fout.write((char*)&a,sizeof(a));
                found='n';
            }
        }
        else
            fout.write((char*)&a,sizeof(a));
    }
    if(found=='f')
        cout<<"\n\nRecord not found\n";
    else if(found=='n')
        cout<<"Employee data not deleted\n";
    else
        cout<<"Employee data deleted\n";
    fin.close();
    fout.close();
    remove("Database.txt");
    rename ("temp.txt","Database.txt");

}
void lit()
{
    system("cls");
    char found='f';
    ifstream fin("Database.txt",ios::in|ios::binary);
    cout<<"--------------|------------------|-----------------|\n";
    cout<<"  Employee ID         Name           Designation     \n";
    cout<<"--------------|------------------|-----------------|\n";
    while(fin.read((char*)&a,sizeof(a)))
    {
        found='y';
        cout<<"\t"<<a.empid<<"\t   "<<a.name<<"\t\t"<<a.desig<<"\n";
        cout<<"---------------------------------------------------\n";
    }
    if(found=='f')
        cout<<"No records exist\n";
    fin.close();
}
int main()
{
    char b[10];
    cout <<"\n\n\n\n\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM";
    cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
    cin>>b;
    if(strcmp(b,"pass")==0)
    {
        cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
        for(int j=1; j<8; j++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
        system("PAUSE");
        system("CLS");
        a.fp();
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tIncorrect Password";
        main();
    }
}
