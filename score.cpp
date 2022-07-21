//头文件
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//定义结构体
struct student
{
    int id = 0;
    string name;
    double score[6] = { 0 };
    double sum = 0;
    double average = 0;
    int paiming = 0;
};

//全局变量
student stu[30];
double stu_num;
int i=0, j=0;
double class_num = 0;
double class_sum = 0;
double class_sums[6] = { 0 };
double class_average = 0;
double class_averages[6] = { 0 };
double score_sum = 0;
double score_sums[30] = { 0 };
double score_average = 0;
int stu_paiming[30] = { 0 };

//录入每个学生的学号、姓名和各科考试成绩
void input()
{
    cout << "输入学号、名字和分数" << endl;
    for (i = 0; i < stu_num; i++)
    {
        cin >> stu[i].id >> stu[i].name;
        for (j = 0; j < class_num; j++)
        {
            cin >> stu[i].score[j];
        }
    }
}

//输出每门课程的总分和平均分
void shuchu1()
{
    for (i = 0; i < class_num; i++)
    {
        cout << "第" << i + 1 << "科总分：" << class_sums[i] << " 平均分:" << " " << class_averages[i] << endl;
        cout << "-------------------------" << endl;
    }
}

//计算每门课程的总分和平均分
void jisuan1()
{
    for (j = 0; j < class_num; j++)
    {
        class_sum = 0;
        for (i = 0; i < stu_num; i++)
        {
            class_sum = class_sum + stu[i].score[j];
        }
        class_sums[j] = class_sum;
        class_averages[j] = class_sums[j] / stu_num;
    }
}



//输出每个学生的总分和平均分
void shuchu2()
{
    
    for (i = 0; i < stu_num; i++)
    {
        cout << fixed << setprecision(2);
        cout << stu[i].name <<" 的总分：" << stu[i].sum <<"," << "平均分：" << " " << stu[i].average << endl;
        cout << "-------------------------" << endl;
    }
}

//计算每个学生的总分和平均分
void jisuan2()
{
    for (i = 0; i < stu_num; i++)
    {
        score_sum = 0;
        for (j = 0; j < class_num; j++)
        {
            score_sum = score_sum + stu[i].score[j];
        }
        stu[i].sum = score_sum;
        //score_sums[i] = score_sum;
        //score_averages[i] = stu[i].sum / class_num;
        stu[i].average = stu[i].sum / class_num;
    }
}

//按每个学生的总分由高到低排出名次表
void jisuan_paiming()
{
    int t, temp, x=1;
    for (i = 0; i < stu_num; i++)
    {
        score_sums[i] = stu[i].sum;
    }
    for (i = 0; i < stu_num; i++)
    {
        if (score_sums[i]!=0)
        {
            temp = score_sums[i]; 
            t = i;
            for (j =0; j <stu_num; j++)
            {
                if (temp < score_sums[j])
                {
                    temp = score_sums[j];
                    t = j;
                }
            }
            score_sums[t] = 0;
            stu[t].paiming = x;
            x++;
            if (i != t)
            {
                i--;
            }
        }
    }
    
}

//输出每个学生的总分由高到低排出名次表
void shuchu_paiming1()
{
    for (i = 0; i < stu_num; i++)
    {
        for (j = 0; j < stu_num; j++)
        {
            if (i + 1 == stu[j].paiming)
            {
                cout << stu[j].name << ":" << stu[j].sum << endl;
                cout << "------------------" << endl;
            }
        }
    }
}

//输出每个学生的总分由低到高排出名次表
void shuchu_paiming2()
{
    for (i = stu_num; i >0; i--)
    {
        for (j = 0; j < stu_num; j++)
        {
            if (i == stu[j].paiming)
            {
                cout << stu[j].name << ":" << stu[j].sum << endl;
                cout << "------------------" << endl;
            }
        }
    }
}

//按学号由小到大排出成绩表
void xuehao1()
{
    int y = 0; int len = 0;
    cout << "学号" << "\t" << "姓名" << "\t\t";
    for (i=0;i<class_num;i++)
    {
        cout << "课程" << i + 1 << "\t";
    }
    cout << "总分" << "\t" << "平均分" << "\t" << "排名" << endl;

    int z=0;
    for (y=0;1;y++)
    {
        
        for (i=0;i<stu_num;i++)
        {
            if (y==stu[i].id)
            {
                len = stu[i].name.size();
                if (len > 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t";
                }
                else if (len <= 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t\t";
                }
                for (j = 0; j < class_num; j++)
                {
                    cout << stu[i].score[j] << "\t";
                }
                cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
                z++;
            }
        }
        if (z == stu_num) break;
    }
}


//按姓名的字典顺序排出成绩表
void xingming1()
{
    int y = 0; int len = 0;
    cout << "学号" << "\t" << "姓名" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "课程" << i + 1 << "\t";
    }
    cout << "总分" << "\t" << "平均分" << "\t" << "排名" << endl;

    char x; int z = 0; char a;
    for (x=97;x<=122; x++)
    {
        for (i=0;i<stu_num;i++)
        {
            len = stu[i].name.size();
            a = stu[i].name[0];
            if ( x==a)
            {
                if (len>8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t";
                }
                else if (len <= 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t\t";
                }
                for (j = 0; j < class_num; j++)
                {
                    cout << stu[i].score[j] << "\t";
                }
                cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
                z++;
            }
            
        }
        if (z==stu_num)
        {
            break;
        }
    }
}

//按学号查询学生排名及其考试成绩
void xuehao2()
{   
    int x;
    cout << "请输入学号：";
    cin >> x;
    cout << endl;

    cout << "姓名" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "课程" << i + 1 << "\t";
    }
    cout << "总分" << "\t" << "平均分" << "\t" << "排名" << endl;

    
    for (i=0;i<stu_num;i++)
    {
        if (x==stu[i].id)
        {
            cout << stu[i].name << "\t\t";
            for (j=0;j<class_num;j++)
            {
                cout << stu[i].score[j] << "\t";
            }
            cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
        }
    }
}

//按姓名查询学生排名及其考试成绩
void xingming2()
{
    string x;
    cout << "请输入姓名：";
    cin >> x;
    cout << endl;

    cout << "学号" << "\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "课程" << i + 1 << "\t";
    }
    cout << "总分" << "\t" << "平均分" << "\t" << "排名" << endl;


    for (i = 0; i < stu_num; i++)
    {
        if (x == stu[i].name)
        {
            cout << stu[i].id << "\t";
            for (j = 0; j < class_num; j++)
            {
                cout << stu[i].score[j] << "\t";
            }
            cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
        }
    }
}

//对每门课程分别统计每个类别的人数以及所占的百分比
//按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别
void tongji()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0;
    for (j=0;j<class_num;j++)
    {
        a = 0; b = 0; c = 0; d = 0; e = 0;
        for (i=0;i<stu_num;i++)
        {
            if (stu[i].score[j]>=90)
            {
                a++;
            }
            else if (stu[i].score[j] >= 80)
            {
                b++;
            }
            else if (stu[i].score[j] >= 70)
            {
                c++;
            }
            else if (stu[i].score[j] >= 60)
            {
                d++;
            }
            else if(stu[i].score[j] <60)
            {
                e++;
            }
        }
        cout << fixed << setprecision(2);
        cout << "课程" << j + 1 << endl
            << "优秀" << a << "人" << " 百分比为：" << a / stu_num << endl
            << "良好" << b << "人" << " 百分比为：" << b / stu_num << endl
            << "中等" << c << "人" << " 百分比为：" << c / stu_num << endl
            << "及格" << d << "人" << " 百分比为：" << d / stu_num << endl
            << "不及格" << e << "人" << " 百分比为：" << e / stu_num << endl;
        cout << "--------------------" << endl;
    }
}


//输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
void shuchu3()
{
    int len = 0;
    cout << "学号" << "\t" << "姓名" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "课程" << i + 1 << "\t";
    }
    cout << "总分" << "\t" << "平均分" << "\t" << "排名" << endl;

    
    for (i = 0; i < stu_num; i++)
    {
        len = stu[i].name.size();
        if (len > 8)
        {
            cout << stu[i].id << "\t" << stu[i].name << "\t";
        }
        else if (len <= 8)
        {
            cout << stu[i].id << "\t" << stu[i].name << "\t\t";
        }
        for (j = 0; j < class_num; j++)
        {
            cout << stu[i].score[j] << "\t";
        }
        cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
    }
}

//恢复学生成绩数据
void huifu()
{
    ifstream cins;
    cins.open("file1", ios::in);
    if (!cins)
    {
        cerr << "打开失败" << endl;
        exit(1);
    }

    for (int x = 0; x < stu_num; x++)
    {

        cins >> stu[x].id >> stu[x].name;

        for (j = 0; j < class_num; j++)
        {
            cins >> stu[x].score[j];
        }
    }
    cins.close();
}

//备份学生成绩数据
void beifen()
{
    ofstream couts;
    couts.open("file1", ios::out);
    if (!couts)
    {
        cerr << "打开失败" << endl;
        exit(1);
    }
    cout << "输出备份的学号、姓名、各科成绩" << endl;
    for (int x = 0; x < stu_num; x++)
    {
        
        cin >> stu[x].id >> stu[x].name;
        
        for (j = 0; j < class_num; j++)
        {
            cin >> stu[x].score[j];
        }
    }
    for (int x = 0; x < stu_num; x++)
    {
        
        couts << stu[x].id << " " << stu[x].name << " ";
        
        for (j = 0; j < class_num; j++)
        {
            couts << stu[x].score[j] << " ";
        }
    }
    couts.close();
}








int main()
{
    cout << "输入人数(不超过30人)" << endl;
    cin >> stu_num;
    if (stu_num > 30 || stu_num <= 0)
    {
        cout << "输入错误" << endl;
        while (1)
        {
            cin >> stu_num;
            if (stu_num > 30 || stu_num <= 0)
            {
                cout << "输入错误" << endl;
            }
            else
            {
                break;
            }
        }
    }
    cout << "输入课程门数(小于等于6)" << endl;
    cin >> class_num;
    if (class_num > 6 || class_num <= 0)
    {
        cout << "输入错误" << endl;
        while (1)
        {
            cin >> class_num;
            if (class_num > 6 || class_num <= 0)
            {
                cout << "输入错误" << endl;
            }
            else
            {
                break;
            }
        }
    }

    int option;
    while (1)
    {
        cout << "菜单" << endl
            << "1.录入每个学生的学号、姓名和各科考试成绩" << endl
            << "2.计算每门课程的总分和平均分" << endl
            << "3.计算每个学生的总分和平均分" << endl
            << "4.按每个学生的总分由高到低排出名次表" << endl
            << "5.按每个学生的总分由低到高排出名次表" << endl
            << "6.按学号由小到大排出成绩表" << endl
            << "7.按姓名的字典顺序排出成绩表" << endl
            << "8.按学号查询学生排名及其考试成绩" << endl
            << "9.按姓名查询学生排名及其考试成绩" << endl
            << "10.对每门课程分别统计每个类别的人数以及所占的百分比" << endl
            << "11.输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分" << endl
            << "12.恢复学生成绩数据" << endl
            << "13.备份学生成绩数据" << endl
            << "0.退出程序" << endl
            << "Please Input your choice:" << endl;


        cin >> option;
        switch (option)
        {
        case 1:input(); jisuan1(); jisuan2(); jisuan_paiming();
            break;
        case 2:shuchu1();
            break;
        case 3:shuchu2();
            break;
        case 4:shuchu_paiming1();
            break;
        case 5:shuchu_paiming2();
            break;
        case 6:xuehao1();
            break;
        case 7:xingming1();
            break;
        case 8:xuehao2();
            break;
        case 9:xingming2();
            break;
        case 10:tongji();
            break;
        case 11:shuchu3();
            break;
        case 12:huifu(); jisuan1(); jisuan2(); jisuan_paiming();
            break;
        case 13:beifen();
            break;
        case 0:
            return 0;
        default:
            cout << "输入错误" << endl;
        }
    }
}