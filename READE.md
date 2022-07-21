学生成绩管理系统V5.0（4分）
题目内容：
某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）。参考学生成绩管理系统V4.0，定义结构体类型，用结构体数组作函数参数，编程实现如下菜单驱动的学生成绩管理系统：
（1）录入每个学生的学号、姓名和各科考试成绩；
（2）计算每门课程的总分和平均分；
（3）计算每个学生的总分和平均分；
（4）按每个学生的总分由高到低排出名次表；
（5）按每个学生的总分由低到高排出名次表；
（6）按学号由小到大排出成绩表；
（7）按姓名的字典顺序排出成绩表；
（8）按学号查询学生排名及其考试成绩；
（9）按姓名查询学生排名及其考试成绩；
（10）按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，对每门课程分别统计每个类别的人数以及所占的百分比；
（11）输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分。

要求程序运行后先显示如下菜单，并提示用户输入选项：
Management for Students' scores
1.Input record
2.Caculate total and average score of every course
3.Caculate total and average score of every student
4.Sort in descending order by score
5.Sort in ascending order by score
6.Sort in ascending order by number
7.Sort in dictionary order by name
8.Search by number
9.Search by name
10.Statistic analysis
11.List record
0.Exit
Please Input your choice:
然后，根据用户输入的选项执行相应的操作。


选做: 对于本程序，每次运行程序时，学生的学号、姓名、成绩等信息都需要重新输入，因为这些数据都是存储在掉电即失的内存中的，程序一旦运行结束，这些信息也就丢失了。这对于一个实际系统而言，显然是不实用的。只有在输入这些信息之后，将其以文件的形式保存在永久性磁盘中，每次运行程序都可以从这些磁盘文件中读出相应的数据信息，那么这个系统才是算是实用的。
可参考超星视频中“文件”部分内容，在上述两个程序中增加“备份学生成绩数据文件”和“恢复学生成绩数据文件”两个功能。备份数据就是将数据写入一个文件长期保存，恢复数据就是将数据从保存的数据文件中读出。


测试用例：
1001 xiangjiao 80 90
1100 chengzi 93 76
1004 juzi 65 88
1246 pingguo 59 79
894 xihongshi 70 84
1109 caomei 68 93