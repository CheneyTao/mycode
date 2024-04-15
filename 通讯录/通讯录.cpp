
#define MAX 1000
#include <iostream>
using namespace std;

static void showMenu()
{
        cout << "***********—通讯录—************" << endl;
        cout << "*****   1、添加联系人     *****" << endl;
        cout << "*****   2、显示联系人     *****" << endl;
        cout << "*****   3、删除联系人     *****" << endl;
        cout << "*****   4、查找联系人     *****" << endl; 
        cout << "*****   5、修改联系人     *****" << endl;
        cout << "*****   6、清空联系人     *****" << endl;
        cout << "*****   0、退出通讯录     *****" << endl;
        cout << "*****输入对应数字进行操作******" << endl;
}

struct Person//联系人结构体
{
    string m_Name;
    int m_Sex=0;
    int m_Age=0;
    string m_Phone;
    string m_Addr;
};
struct Addressbooks //通讯录结构体>>>结构体数组
{
    struct Person personArray[MAX];
    int m_Size = 0;

};

//添加联系人
static void addPerson(Addressbooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else 
    {
        string name; 
        
        cout << "请输入姓名："<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        
        cout << "请输入性别： " ;
        cout << "男->输入：1  ";
        cout << "女->输入：2" << endl;
        int sex = 0;
        while(1)                             //输入性别
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
              abs->personArray[abs->m_Size].m_Sex = sex;
              break;

            }
            cout << "输入有误，请重新输入" << endl;
        }

        int age = 0;
        cout << "请输入年龄： " << endl;//输入年龄
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话号码： " << endl;//输入号码
        string tel;
        cin >> tel;
        abs->personArray[abs->m_Size].m_Phone = tel;

        cout << "输入住址 :" << endl;//住址
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++;
        //更新人数
        cout << "添加成功" << endl;
        system("pause");
        system("cls");
        
    }
}

 //显示联系人
 static void showPerson(Addressbooks* abs)
 {
     if (abs->m_Size ==0)
     {
         cout << "通讯录为空" << endl;
     }
     else
     {
         for (int i = 0; i < abs->m_Size; i++)
         {
             cout << "姓名：" << abs->personArray[i].m_Name << "\t";
             cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
             cout << "年龄：" << abs->personArray[i].m_Age << "\t";
             cout << "电话：" << abs->personArray[i].m_Phone << "\t";
             cout << "住址：" << abs->personArray[i].m_Addr  << endl;
             
         }
     }
        system("pause");
        system("cls");

 }

 //检测联系人是否存在
 static int isExist(Addressbooks* abs, string name)
 {
     for (int i = 0; i < abs->m_Size; i++)
     {
         if (name == abs->personArray[i].m_Name)
         {
             return i;
             break;
         }
     }
     return -1; 
 }

 //删除联系人
 static void delPerson(Addressbooks*abs,int n)
 {
     for (int i = n; i < abs->m_Size; i++)
     {
         abs->personArray[i] = abs->personArray[i + 1];
     }
     abs->m_Size--;
     cout << "删除成功"<<endl;
     system("pause");
     system("cls");
 }

 //显示某一个联系人
 static void showOne(Addressbooks* abs, int n)
 {
     if (n >= 0) 
     {
     cout << "姓名：" << abs->personArray[n].m_Name << "\t";
     cout << "性别：" << (abs->personArray[n].m_Sex == 1 ? "男" : "女") << "\t";
     cout << "年龄：" << abs->personArray[n].m_Age << "\t";
     cout << "电话：" << abs->personArray[n].m_Phone << "\t";
     cout << "住址：" << abs->personArray[n].m_Addr << endl;
     }
     else 
     {
         cout << "通讯录为空" << endl;
     }

 }

 //修改联系人
 static void modifyPerson(Addressbooks *abs)
 {
     if (abs->m_Size == 0)
     {
         cout << "通讯录为空" << endl;      

         return;
   
     } 
     cout << "输入要修改的联系人的姓名：" << endl;
     string name;
     cin >> name;
     if (isExist(abs, name)!=-1)
     {
         int re = isExist(abs, name);
         string name;
         cout << "输入修改后的姓名：";
         cin >> name;
         abs->personArray->m_Name = name;
         
         int sex;
         cout << "输入修改后的性别：(男->输入:1  女->:输入：2)";
         cin >> sex;
         abs->personArray->m_Sex = sex;

         int age;
         cout << "输入修改后的年龄：";
         cin >> age;
         abs->personArray->m_Age = age;
         
         string phone;
         cout << "输入修改后的电话：";
         cin >> phone;
         abs->personArray->m_Phone = phone; 

         string Addr;
         cout << "输入修改后的地址：";
         cin >>Addr;
         abs->personArray->m_Addr= Addr;   
     }
     else
         cout<<"此人不存在"<<endl ;

 }
 
 //清空
 static void clearAddr(Addressbooks* abs)
 {
     abs->m_Size = 0;
    
     cout << "清空成功" << endl;
     system("pause");
     system("cls");
 }

int main()
{
    string select;
   
    Addressbooks abs; //初始化通讯录
  //  abs.m_Size = 0;

    while(true)
    {
        showMenu();
        int s;
        cin >> select;
        if (select.length() > 1||select[0]>'6'||select[0]<'0')//防止异常输入
            s = 7;
        else
            s = select[0] - '0';
       
       switch (s)
      {
       case 1://1、添加联系人
           addPerson(&abs);//地址传递修饰实参
        break;

       case 2:// 2、显示联系人
           showPerson(&abs);
        break;

       case 3://3、删除联系人
       {
           cout << "输入删除人姓名： " << endl;
           string name;
           cin >> name;
          
           if (isExist(&abs, name) >= 0)
           {
               delPerson(&abs, isExist(&abs, name));
           }
           else
               cout << "没有这个人，不用删除" << endl;
        }
        break;

       case 4://4、查找联系人
       {
           string name;  
           cout << "输入名字查询: ";
           cin >> name;
           if (isExist(&abs, name) >= 0)
               showOne(&abs, isExist(&abs, name));
           else
               cout << "没有这个人" << endl;
           system("pause");
           system("cls");
        }
        break;

       case 5://5、修改联系人 
       { modifyPerson(&abs);

       system("pause");
       system("cls");
       }
        break;

       case 6://6、清空联系人  
           clearAddr(&abs);
        break;

       case 0://0、退出
       { 
        cout << "欢迎下次使用" << endl;
        system("pause");
        return 0;
        }
        break;

       default: 
        {
           cout << "输入有误，请重新输入："<<endl;
           system("pause");
           system("cls");
        }

        break;
      }

    }
    system("pause");
    return 0;



}
