
#include <iostream>
using namespace std;
//ȫ�ֱ�������
int Available[100]; //��������Դ����Available ,�Ǹ�����m��Ԫ�ص����飬���е�ÿһ��Ԫ�ش���һ������õ���Դ��Ŀ�����Available[j] = K�����ʾϵͳ������Rj����ԴK����
int Max[50][100];   //����������Max ��������һ��n��m�ľ�����������ϵͳ��n�������е�ÿһ�����̶�m����Դ������������Max[i, j] = K�����ʾ����i��ҪRj����Դ�������ĿΪK��
int Allocation[50][100];  //�Ѿ��������
int Need[50][100];        //�����������
int Request[50][100];     //M�����̻���ҪN����Դ����Դ��
int Finish[50];//
int p[50];
int m, n;   //M������,N����Դ
 
//��ȫ���㷨
int Safe()
{
int i, j, l = 0;
int Work[100]; //���ṩ�����̸�����Դ��Դ����
for (i = 0; i < n; i++)
Work[i] = Available[i];//��ִ�а�ȫ�㷨��ʼʱ�����ṩ�ĸ�����Դ��Ŀ=ϵͳ���и�����Դ��Ŀ;Work=Available; 
for (i = 0; i < m; i++)
Finish[i] = 0;//��ʾϵͳ�Ƿ����㹻����Դ���������
for (i = 0; i < m; i++)
{
if (Finish[i] == 1)//������������1,����ִ��
continue;
else
{


for (j = 0; j < n; j++)
{
if (Need[i][j] > Work[j])
break;
}
if (j == n)
{
Finish[i] = 1;
for (int k = 0; k < n; k++)
Work[k] = Work[k] + Allocation[i][k];//ֱ����ɣ����ͷų������������Դ����Ӧִ�п��ṩ��Դ��������
p[l++] = i;
i = -1;
}
else continue;
}
if (l == m)
{
cout << "ϵͳ�ǰ�ȫ��" <<'\n'; 
cout << "ϵͳ��ȫ������:\n";
for(i = 0;i < l;i++)
{
cout << p[i];
if (i != l - 1)
cout << "-->";
}
cout << '\n';
return 1;
}
}
return 0;
}
 
//���м��㷨
int main()
{


int i, j, mi;
cout << "������̵���Ŀ:\n";
cin >> m;
cout << "������Դ������:\n";
cin >> n;
cout << "����ÿ�������������ĸ�����Դ��,����" << m << "x" << n << "��������\n";
for (i = 0; i < m; i++)
for (j = 0; j < n; j++)
cin >> Max[i][j];//���û��������Դ����Ž�����������������
 
cout << "����ÿ�������Ѿ�����ĸ�����Դ��,����" << m << "x" << n << "��������\n";
for (i = 0; i < m; i++)
{
for (j = 0; j < n; j++)
{
cin >> Allocation[i][j];//�������
 
Need[i][j] = Max[i][j] - Allocation[i][j];//������Ҫ�ĸ�����Դ��=�������������Դ��-�ѷ�����Դ��
 
if (Need[i][j] < 0)
{
cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ��������������:\n";
j--;
continue;
}
}
}
cout << "�����������Դ���е���Ŀ:\n";
for (i = 0; i < n; i++)
cin >> Available[i];
Safe();
while (1)
{
cout << "����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�\n";
cin >> mi;
cout << "�������������ĸ�����Դ������\n";
for (i = 0; i < n; i++)
cin >> Request[mi][i];
for (i = 0; i < n; i++)
{
 

if (Request[mi][i] > Need[mi][i])
{
cout << "��������Դ���������̵���������\n";
return 0;
}
if (Request[mi][i] > Available[i])
{
cout << "��������Դ������ϵͳ���е���Դ����\n";
return 0;
}
}
for (i = 0; i < n; i++)
{
Available[i] = Available[i] - Request[mi][i];//��������Դ=��������Դ-������Ҫ
 
Allocation[mi][i] = Allocation[mi][i] + Request[mi][i];//�ѷ�����Դ=�ѷ�����Դ+������Ҫ
 
Need[mi][i] = Need[mi][i] - Request[mi][i];//���̻�����Դ=���̻�����Դ-������Ҫ
}
if (Safe())
cout << "ͬ���������\n";
else
{
cout << "�Բ���.������󱻾ܾ���\n";
for (i = 0; i < n; i++)
{
Available[i] = Available[i] - Request[mi][i];//��������Դ=��������Դ-������Ҫ
 
Allocation[mi][i] = Allocation[mi][i] + Request[mi][i];//�ѷ�����Դ=�ѷ�����Դ+������Ҫ
 
Need[mi][i] = Need[mi][i] - Request[mi][i];//���̻�����Դ=���̻�����Դ-������Ҫ
}
}
for(i=0;i<m;i++)
Finish[i]=0;
}
return 0;
}






