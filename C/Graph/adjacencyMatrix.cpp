//
// Created by Npc on 2024/4/23.
//
/*
1. ʲô��ͼ
ͼ�ۣ�graph theory�� ����ѧ��һ����֧������ ͼ Ϊ�о��Ķ���

ͼ�۱�����Ӧ����ѧ��һ���֣���ʷ��ͼ���������ܶ���ѧ�Ҹ��Զ���������������ͼ�۵��������ּ������������ŷ�� 1736 ��������У�Ҳ���������Ŀ���˹����Konigsberg�����⣨�������⣩��



2. ͼ�Ķ���
һ��ͼG��һ����Ԫ�飬����ż<V,E>�������G=<V,E> ������V�����޷ǿռ��ϣ���ΪG�Ķ��㼯,V�е�Ԫ�س�Ϊ������㣻E��Ϊ G�ıߵļ��ϣ����еı�ei������E������v�еĽ����֮��Ӧ����eiΪ G�ıߡ�



3. ͼ�Ļ�������
l  ����ͼ��ÿ���߶�������ߵ�ͼ��

l  ����ͼ��ÿ���߶�������ߵ�ͼ��

l  ���ͼ����һ��ͼ�У���Щ��������ߣ���һЩ��������ߣ����ͼΪ���ͼ��

l  ����ͼ��һ��ͼ�ĵ㼯�ͱ߼����������ͼ��

l  ��ͼ���߼�Ϊ�ռ���ͼ��

l  ƽ��ͼ������һ������û�б߹��ɵ�ͼ��

l  ����������ei=(u,v) ��ei����E �����u�Ǻ�v������ġ�

l  �����㣺�ޱ߹����ĵ㡣

l  �Ի�����һ��������������������غϣ���ƴ˱�Ϊ�Ի���

l  �ڽӣ�������ͬһ���ߵ�������  ��  ��Ϊ�ڽӵģ�������ͬһ�����������  ��  ���ڽӵģ������ڵģ���



4.����������
ͼ�۶���1

l  ���ۣ�������ͼ�У�����Ϊ�����ĵ��Ȼ��ż������

ͼ�۶���2



l  ���ۣ������е����֮�͵��ڳ���֮�͡�*/
#include "iostream"
using namespace std;



const int maxn=105;
int adj[maxn][maxn]={0};

int x,y;//����������
int n,m;//������n�Ա���m������(x,y<=m)


int main()
{
    cout<<"�����м��Աߺͼ��Զ���"<<endl;
    cin>>n>>m;
    cout<<"�����:";
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        adj[x-1][y-1]=1;
        adj[y-1][x-1]=1;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}