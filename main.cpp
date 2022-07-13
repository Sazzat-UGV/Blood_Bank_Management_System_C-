#include <iostream>
#include <fstream>
#include<conio.h>
#include <stdlib.h>

using namespace std;
class bloodbank
{
private:
    string id,name1,name2,grp,div,dis,contact_no,email,donar_password,donation_date;
    string user,password;
public:
    void welcome();
    void admin_registation();
    void admin_login();
    void menu();
    void add_Donar();
    void all_donar();
    void modify_donar();
    void search_donar_page_admin_page();
    void search_by_donar_id();
    void search_by_blood_grp();
    void search_by_division();
    void search_by_district();
    void delete_donar();
    void change_password();
    void donar_login();
    void donar_page();
    void search_donar_user_page();
    void update_last_donation_date();
};



void bloodbank::welcome()
{
start:
    system("cls");
    int choice;
    cout << "\n\t\t\t\t   Welcome to Blood Bank Management System  " << endl;
    cout << "\t\t\t---------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t 1. Admin Panel" << endl;
    cout << "\t\t\t\t\t 2. Donar Panel" << endl;
    cout << "\t\t\t\t\t 3. Search Donar" << endl;
    cout << "\t\t\t\t\t 4. Exit" << endl<< endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t Enter Your Choose: " ;
    cin >> choice;
    cout << endl;

    switch(choice)
    {
    case 1:
        admin_registation();
        break;
    case 2:
        donar_login();
        break;
    case 3:
        search_donar_user_page();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout<<"\t\t\t\t    Invalid Choice Please Try Again......"<<endl;
    }
    getch();
    goto start;
}




void bloodbank::admin_registation()
{
    system("cls");
    fstream file;
    cout << "\n\t\t\t\t\t   Admin Registration Form" << endl;
    cout<<"\t\t\t\tFor Next Please Set Your Username and Password"<<endl;
    cout << "\t\t\t--------------------------------------------------------------";

    file.open("admin_password.txt");
    if(!file)
    {
        file.open("admin_password.txt", ios::out);
        cout<<"\n\n\t\t\t\tEnter Username: ";
        cin >> user;
        cout<<"\t\t\t\tEnter Password: ";
        cin >> password;
        file << user << "  " << password;
        cout << "\n\t\t\t--------------------------------------------------------------";
        cout<< "\n\t\t\t\tUsername and Password Set Successfully....."<<endl;
        cout<<"\n\t\t\t\tYour Username is: "<< user<<endl;
        cout<<"\t\t\t\tYour Password is: "<< password<<endl;
        file.close();
        cout<< "\t\t\t\t"<<system("pause")<<endl;
        admin_login();
    }
    else
    {
        admin_login();
    }
    getch();
}




void bloodbank::admin_login()
{
login_panel:
    system("cls");
    fstream file;
    string user2,password2;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Login Panal                  |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file.open("admin_password.txt", ios::in);
    cout << "\t\t\t\t User Name: ";
    cin>>user2;
    cout << "\t\t\t\t Password: ";
    cin >> password2;
    file >> user >> password ;
    if(user == user2)
    {
        if(password == password2)
        {
            menu();
            file.close();
        }
        else
        {
            cout<<"\n\t\t\t\t Invalid Please Check Your Password...."<<endl;
            cout<< "\t\t\t\t "<<system("pause")<<endl;
            goto login_panel;
        }
    }
    else
    {
        cout<<"\n\t\t\t\t Invalid Please Check Your User Name...."<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        goto login_panel;
    }
    getch();
}




void bloodbank::menu()
{
menustart:
    int choice;
    system("cls");
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|          Blood Bank Management System         |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    cout << "\t\t\t\t 1. Add New Donar" << endl;
    cout << "\t\t\t\t 2. All Donar" << endl;
    cout << "\t\t\t\t 3. Modify Donar Details" << endl;
    cout << "\t\t\t\t 4. Search Donar" << endl;
    cout << "\t\t\t\t 5. Delete Donar Record" << endl;
    cout << "\t\t\t\t 6. Change Password" << endl;
    cout << "\t\t\t\t 7. Exit" << endl<< endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t    Enter Your Choose: " ;
    cin >> choice;
    cout << endl;

    switch(choice)
    {
    case 1:
        add_Donar();
        break;
    case 2:
        all_donar();
        break;
    case 3:
        modify_donar();
        break;
    case 4:
        search_donar_page_admin_page();
        break;
    case 5:
        delete_donar();
        break;
    case 6:
        change_password();
        break;
    case 7:
        welcome();
        break;
    default:
        cout<<"\t\t\t\t    Invalid Choice Please Try Again......"<<endl;
        cout<< "\t\t\t\t    "<<system("pause")<<endl;
                goto menustart;
    }
    getch();
    goto menustart;
}




void bloodbank::add_Donar()
{
insert:
    string id_no;
    int add_another;
    system("cls");
    fstream file1,file2,file3;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Add New Donar                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    file1.open("donarRecord.txt", ios::app | ios::out);
    cout << "\t\t\t\t Donar ID: ";
    cin >> id_no;
    if(id_no==id)
    {
        cout << "\t\t\t\t Sorry the ID is Already has been Taken. Please try again."<<endl;
        cout << "\t\t\t\t-------------------------------------------------"<<endl;
    }
    else
    {
        cout << "\t\t\t\t Unique Donar is Found.Please Continue.. "<<endl;
        cout << "\t\t\t\t-------------------------------------------------" << endl;
        id=id_no;
        cout << "\t\t\t\t Donar ID: "<<id_no;

        cout << "\n\t\t\t\t First Name: ";
        cin >> name1;
        cout << "\t\t\t\t Last Name: ";
        cin >> name2;
        cout << "\t\t\t\t Blood Group: ";
        cin >> grp;
        cout << "\t\t\t\t Division: ";
        cin >> div;
        cout << "\t\t\t\t District: ";
        cin >> dis;
        cout << "\t\t\t\t Contact No: ";
        cin >> contact_no;

        file1 << id << "  " << name1 << "  " << name2 << "  " << grp << "  " << div << "  " << dis << "  " << contact_no <<"\n";
        file1.close();

        file2.open("donar_activity.txt", ios::app | ios::out);
        id=id_no;
        cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): ";
        cin >> donation_date;
        file2 << id <<"  "<< donation_date << "\n";
        file2.close();

        file3.open("donar_password.txt", ios::app | ios::out);
        id=id_no;
        cout << "\t\t\t\t Email Id: ";
        cin >> email;
        cout << "\t\t\t\t Password: ";
        cin >> donar_password;
        cout << "\t\t\t\t-------------------------------------------------" << endl;
        file3 << id << "  " << email << "  "<< donar_password << "\n";
        file3.close();
    }
    cout << "\t\t\t\t Do You Want To Add Another Donar: 1.YES" <<endl;
    cout << "\t\t\t\t\t\t\t\t   2.NO"<<endl;
    cout << "\t\t\t\t Enter Your Choice: ";
    cin >> add_another;
    switch(add_another)
    {
    case 1:
        goto insert;
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"\n\t\t\t\t Invalid Choice Please Try Again......"<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        menu();
    }
}




void bloodbank::all_donar()
{
    system("cls");
    fstream file1,file2,file3;
    int total_donar = 1;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                    All Donars                 |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);

    if(!file1 || !file2)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
    }
    else
    {
        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;
        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            cout << "\t\t\t\t Donar No   : " << total_donar++ << endl;
            cout << "\t\t\t\t Doanr Name : " << name1 << " " << name2 << endl;
            cout << "\t\t\t\t Donar ID   : " << id << endl;
            cout << "\t\t\t\t Blood Group: " << grp << endl;
            cout << "\t\t\t\t Division   : " << div << endl;
            cout << "\t\t\t\t District:  : " << dis << endl;
            cout << "\t\t\t\t Email      : " << email << endl;
            cout << "\t\t\t\t Contact No : " << contact_no << endl;
            cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<< donation_date << endl<< endl<< endl;

            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
    }
    if (total_donar == 0)
    {
        cout << "\t\t\t\t No Data Found... ";
    }
    file1.close();
    file2.close();
    file3.close();
}




void bloodbank::modify_donar()
{
    system("cls");
    fstream file1,file2,file3,file4,file5,file6;
    string id_no;
    int found = 0;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Modify Donar Details            |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
     file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);

    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
    }
    else
    {
        cout << "\t\t\t\t Enter Donar ID No for Modify: ";
        cin >> id_no;

        file4.open("temporary1.txt", ios::app | ios::out);
        file5.open("temporary2.txt", ios::app | ios::out);
        file6.open("temporary3.txt", ios::app | ios::out);


        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;

        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if (id != id_no)
            {
                file4 << id << "  " << name1 << "  " << name2 << "  " << grp << "  " << div << "  " << dis << "  " << contact_no <<"\n";
                file5 << id <<"  "<< donation_date << "\n";
                file6 << id << "  " << email << "  "<< donar_password << "\n";
            }

            else
            {
                id=id_no;
                cout << "\t\t\t\t Donar ID: "<<id<<endl;
                cout << "\n\t\t\t\t First Name: ";
                cin >> name1;
                cout << "\t\t\t\t Last Name: ";
                cin >> name2;
                cout << "\t\t\t\t Blood Group: ";
                cin >> grp;
                cout << "\t\t\t\t Division: ";
                cin >> div;
                cout << "\t\t\t\t District: ";
                cin >> dis;
                cout << "\t\t\t\t Contact No: ";
                cin >> contact_no;

                file4 << id << "  " << name1 << "  " << name2 << "  " << grp << "  " << div << "  " << dis << "  " << contact_no <<"\n";
                file2.open("donar_activity.txt", ios::app | ios::out);
                id=id_no;
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): ";
                cin >> donation_date;
                file5 << id <<"  "<< donation_date << "\n";

                id=id_no;
                cout << "\t\t\t\t Email Id: ";
                cin >> email;
                cout << "\t\t\t\t Password: ";
                cin >> donar_password;
                file6 << id << "  " << email << "  "<< donar_password << "\n";
                found++;
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Donar ID No. Not Found....";
        }
        file4.close();
        file5.close();
        file6.close();
        file1.close();
        file2.close();
        file3.close();

        remove("donarRecord.txt");
        rename("temporary1.txt", "donarRecord.txt");

        remove("donar_activity.txt");
        rename("temporary2.txt", "donar_activity.txt");

        remove("donar_password.txt");
        rename("temporary3.txt", "donar_password.txt");
    }
}




void bloodbank::search_donar_page_admin_page()
{
search:
    system("cls");
    int choice;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Search Donar                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    cout << "\t\t\t\t 1. Search by Donar ID "<< endl;
    cout << "\t\t\t\t 2. Search by Blood Group"<< endl;
    cout << "\t\t\t\t 3. Search on Division"<< endl;
    cout << "\t\t\t\t 4. Search on District"<< endl;
    cout << "\t\t\t\t 5. Exit "<< endl<<endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    cout << "\t\t\t\t Enter Your Choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        search_by_donar_id();
        break;
    case 2:
        search_by_blood_grp();
        break;
    case 3:
        search_by_division();
        break;
    case 4:
        search_by_district();
        break;
    case 5:
        menu();
        break;
    default:
        cout<<"\t\t\t\t Invalid Choice Please Try Again......"<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        goto search;
    }
}




void bloodbank::search_by_donar_id()
{
    system("cls");
    fstream file1,file2,file3;
    int found = 0;
    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);

    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Search by ID                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
        file3.close();
    }
    else
    {
        string id_no;
        cout << "\t\t\t\t Enter Donar ID for Search: ";
        cin >> id_no;
        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;
        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if(id_no == id)
            {
                cout << "\n\t\t\t\t Doanr Name  : " << name1 << " " << name2 << endl;
                cout << "\t\t\t\t Donar ID    : " << id << endl;
                cout << "\t\t\t\t Blood Group : " << grp << endl;
                cout << "\t\t\t\t Division    : " << div << endl;
                cout << "\t\t\t\t District:   : " << dis << endl;
                cout << "\t\t\t\t Email       : " << email << endl;
                cout << "\t\t\t\t Contact No  : " << contact_no << endl;
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<< donation_date << endl<< endl<< endl;
                found++;
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t No Data Found... ";
            cout<< "\n\t\t\t\t "<<system("pause")<<endl;
            search_donar_page_admin_page();
        }
        file1.close();
        file2.close();
        file3.close();
    }
}




void bloodbank::search_by_blood_grp()
{
    system("cls");
    fstream file1,file2,file3;
    int found = 0;
    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);

    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                Search by Blood Group          |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
        file3.close();
    }
    else
    {
        string blood_grp;
        cout << "\t\t\t\t Enter Blood Group for Search: ";
        cin >> blood_grp;
        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;
        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if(grp == blood_grp)
            {
                cout << "\n\t\t\t\t Doanr Name  : " << name1 << " " << name2 << endl;
                cout << "\t\t\t\t Donar ID    : " << id << endl;
                cout << "\t\t\t\t Blood Group : " << grp << endl;
                cout << "\t\t\t\t Division    : " << div << endl;
                cout << "\t\t\t\t District:   : " << dis << endl;
                cout << "\t\t\t\t Email       : " << email << endl;
                cout << "\t\t\t\t Contact No  : " << contact_no << endl;
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<< donation_date << endl<< endl<< endl;
                found++;
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t No Data Found... ";
            cout<< "\n\t\t\t\t "<<system("pause")<<endl;
            search_donar_page_admin_page();
        }
        file1.close();
        file2.close();
        file3.close();
    }
}




void bloodbank::search_by_division()
{
    system("cls");
    fstream file1,file2,file3;
    int found = 0;
    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);

    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|               Search Donar on Division         |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
        file3.close();
    }
    else
    {
        string division;
        cout << "\t\t\t\t Enter Division Name for Search: ";
        cin >> division;
        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;
        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if(div == division)
            {
                cout << "\n\t\t\t\t Doanr Name  : " << name1 << " " << name2 << endl;
                cout << "\t\t\t\t Donar ID    : " << id << endl;
                cout << "\t\t\t\t Blood Group : " << grp << endl;
                cout << "\t\t\t\t Division    : " << div << endl;
                cout << "\t\t\t\t District:   : " << dis << endl;
                cout << "\t\t\t\t Email       : " << email << endl;
                cout << "\t\t\t\t Contact No  : " << contact_no << endl;
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<< donation_date << endl<< endl<< endl;
                found++;
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t No Data Found... ";
            cout<< "\n\t\t\t\t "<<system("pause")<<endl;
            search_donar_page_admin_page();
        }
        file1.close();
        file2.close();
        file3.close();
    }
}




void bloodbank::search_by_district()
{
    system("cls");
    fstream file1,file2,file3;
    int found = 0;
    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                 Search on District            |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
        file3.close();
    }
    else
    {
        string district;
        cout << "\t\t\t\t Enter District Name for Search: ";
        cin >> district;
        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;
        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if(dis == district)
            {
                cout << "\n\t\t\t\t Doanr Name  : " << name1 << " " << name2 << endl;
                cout << "\t\t\t\t Donar ID    : " << id << endl;
                cout << "\t\t\t\t Blood Group : " << grp << endl;
                cout << "\t\t\t\t Division    : " << div << endl;
                cout << "\t\t\t\t District:   : " << dis << endl;
                cout << "\t\t\t\t Email       : " << email << endl;
                cout << "\t\t\t\t Contact No  : " << contact_no << endl;
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<< donation_date << endl<< endl<< endl;
                found++;
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\t\t\t\t No Data Found... ";
            cout<< "\n\t\t\t\t "<<system("pause")<<endl;
            search_donar_page_admin_page();
        }
        file1.close();
        file2.close();
        file3.close();
    }
}




void bloodbank::delete_donar()
{
    system("cls");
    fstream file1, file2,file3, file4,file5, file6;
    int found = 0;
    string id_no;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Delete Donar                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;

    file1.open("donarRecord.txt",ios::in);
    file2.open("donar_activity.txt",ios::in);
    file3.open("donar_password.txt",ios::in);
    if (!file1 || !file2 || !file3)
    {
        cout << "\t\t\t\t No Data Found... ";
        file1.close();
        file2.close();
        file3.close();
    }
    else
    {
        cout << "\t\t\t\t Enter Donar ID for Delete: ";
        cin >> id_no;
        file4.open("temporary1.txt", ios::app | ios::out);
        file5.open("temporary2.txt", ios::app | ios::out);
        file6.open("temporary3.txt", ios::app | ios::out);

        file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
        file2 >> id >> donation_date ;
        file3 >> id >> email >> donar_password;

        while (!file1.eof() && !file2.eof() && !file3.eof())
        {
            if (id != id_no)
            {
                file4 << id << "  " << name1 << "  " << name2 << "  " << grp << "  " << div << "  " << dis << "  " << contact_no <<"\n";
                file5 << id <<"  "<< donation_date << "\n";
                file6 << id << "  " << email << "  "<< donar_password << "\n";

            }
            else
            {
                found++;
                cout << "\n\t\t\t\t Successfully Delete Data...";
            }
            file1 >> id >> name1 >> name2 >> grp >> div >> dis >> contact_no ;
            file2 >> id >> donation_date ;
            file3 >> id >> email >> donar_password;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Donar ID Not Found....";
        }
        file1.close();
        file2.close();
        file3.close();
        file4.close();
        file5.close();
        file6.close();
        remove("donarRecord.txt");
        rename("temporary1.txt", "donarRecord.txt");

        remove("donar_activity.txt");
        rename("temporary2.txt", "donar_activity.txt");

        remove("donar_password.txt");
        rename("temporary3.txt", "donar_password.txt");
    }
}




void bloodbank::change_password()
{

    system("cls");
    ofstream file;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                 Change Password               |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<<endl;
    cout << "\t\t\t\t Enter New Username: ";
    cin >> user;
    cout << "\t\t\t\t Enter New Password: ";
    cin >> password;
    file.open("admin_password.txt");
    file << user << " " << password;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout<< "\t\t\t\t New Username and Password Set Successfully"<<endl<<endl;
    cout<<"\t\t\t\t Your New Username is: "<< user<<endl;
    cout<<"\t\t\t\t Your New Password is: "<< password<<endl;
    file.close();
    cout<< "\t\t\t\t "<<system("pause")<<endl;
    menu();
    getch();
}




void bloodbank::donar_login()
{
donar_login:
    system("cls");
    fstream file3;
    int found=0;
    string user2,password2;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Donar Login                  |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    file3.open("donar_password.txt", ios::in);
    if(!file3)
    {
        cout<<"\t\t\t\t No Data Found"<<endl;
        cout<< "\t\t\t\t"<<system("pause")<<endl;
        welcome();

    }

    cout << "\t\t\t\t User Name: ";
    cin>>user2;
    cout << "\t\t\t\t Password: ";
    cin >> password2;
    file3 >> id >> email >> donar_password ;



    while (!file3.eof())
    {
        if(email == user2 && donar_password == password2)
        {
            donar_page();
            found++;
        }
        file3 >> id >> email >> donar_password ;
    }
    if(found==0)
    {

        cout<<"\n\t\t\t\t Invalid Please Check Your User Name or Password...."<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        goto donar_login;
    }
    file3.close();
    getch();
}




void bloodbank::donar_page()
{
donar_page:
    system("cls");
    int choice;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Donar Page                   |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1. Update Donation Date"<< endl;
    cout << "\t\t\t\t 2. Exit"<< endl<<endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t Enter your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        update_last_donation_date();
        break;
    case 2:
        welcome();
        break;
    default:
        cout<<"\t\t\t\t Invalid Choice Please Try Again......"<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        goto donar_page;
    }
    getch();
}




void bloodbank::update_last_donation_date()
{
    update:
    system("cls");
    fstream file2,file5;
    string id_no;
    int found = 0;
    int choice;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                Update Donation Date           |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
file2.open("donar_activity.txt",ios::in);

    if (!file2)
    {
        cout << "\t\t\t\t No Data Found... ";
    }
    else
    {
        cout << "\t\t\t\t Enter Your ID for Update: ";
        cin >> id_no;
        file5.open("temporary2.txt", ios::app | ios::out);

        file2 >> id >> donation_date ;

        while (!file2.eof())
        {
            if (id != id_no)
            {

                file5 << id <<"  "<< donation_date << "\n";

            }

            else
            {
                cout << "\t\t\t\t Last Donation Date(dd/mm/YYYY): "<<donation_date<<endl<<endl;
                    cout << "\t\t\t\t-------------------------------------------------" <<  endl;
                cout << "\n\t\t\t\t Do you want to change date(1.yes/2.no) ";
                cin >> choice;
                if(choice==1)
                {
                    cout << "\n\t\t\t\t Update Donation Date(dd/mm/YYYY): ";
                    cin >> donation_date;
                    file5 << id <<"  "<< donation_date << "\n";
                    found++;
                }
                if(choice==2)
                {
                    donar_page();
                }

            }
            file2 >> id >> donation_date ;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Donar Record Not Found....";
        }
        file5.close();
        file2.close();


        remove("donar_activity.txt");
        rename("temporary2.txt", "donar_activity.txt");

    }
}




void bloodbank::search_donar_user_page()
{
search:
    system("cls");
    int choice;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Search Donar                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl<< endl;
    cout << "\t\t\t\t 1. Search by Blood Group"<< endl;
    cout << "\t\t\t\t 2. Search on Division"<< endl;
    cout << "\t\t\t\t 3. Search on District"<< endl;
    cout << "\t\t\t\t 4. Exit "<< endl<< endl;
    cout << "\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t Enter Your Choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        search_by_blood_grp();
        break;
    case 2:
        search_by_division();
        break;
    case 3:
        search_by_district();
        break;
    case 4:
        welcome();
        break;
    default:
        cout<<"\t\t\t\t Invalid Choice Please Try Again......"<<endl;
        cout<< "\t\t\t\t "<<system("pause")<<endl;
        goto search;
    }
}




int main()
{
    bloodbank project;
    project.welcome();
    return 0;
}
