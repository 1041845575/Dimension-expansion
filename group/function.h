#include<vector>
void grouping(double init[],vector<double> &extend_array,int num,int index1,int index2)//���ݵ�ά�ı�������չ��ά����,����ѭ�������
	//ע��û���жϲ����������
{
	int length = sizeof(init);
	int step = 0;
	step = length/num;//�˴���numΪ��ָ�Ķ���
	vector<vector<double>>group;//������ų�ʼÿһ�εı���
	vector<double>group_num;//�����
	for(int i=index1;i<index2+1;i++)
	{
		group_num.push_back(i);
	}
	group.push_back(group_num);
	for(int i=index1;i<=index2;i++)
	{
		extend_array.push_back(init[step]);
	}
	int num1,num2=0;
	for(int i=index1;i<index2+1;i++)
	{	
		Group(group[i],index1,index2);
	}
}
void Group(double init[],vector<double> &group,int index1,int index2)
{
	for(int i=index1;i<=index2;i++)
	{
		group.push_back(init[i]);
	}
}
void extend_array(double *extend_array[],int e_length,double *orign_array[],int o_length)//ע�⣬�������鶼Ҫ��ʼ��
{	
	vector<int> extend_index;//���������±�
	int count = 1;
	extend_array[0] = orign_array[0];
	extend_index.push_back(0);
	extend_array[e_length] = orign_array[o_length];
	int num = 0;
	num = e_length/(o_length-1);
	int mod = 0;
	mod = e_length%(o_length-1);
	if(mod == 0)
	{
		for(int i=0;i<o_length-2;i++)
		{
			extend_array[i+num-1] = orign_array[i+1];
			extend_index.push_back(i+num-1);//������չ�Ľڵ��Ӧ����һ����λ����Ľڵ��±�
			num+=num;

		}
		extend_index.push_back(e_length-1);
	}
	else
	{
		for(int i=0;i<o_length-2;i++)
		{
			extend_array[i+num] = orign_array[i+1];
			extend_index.push_back(i+num);//������չ�Ľڵ��Ӧ����һ����λ����Ľڵ��±�
			if(count<mod)
				num = num+1;
			else
				num+=num;
			count++;

		}
		extend_index.push_back(e_length-1);
	}
}
void extend_uniform_points(double *extend_array[],double *orign_array[],int e_length,int o_length,vector<double>group,vector<int>extend_index)
{
	int num = 0;
	num = e_length/(o_length-1);
	int index1,index2=0;
	vector<int> point_distance;
	int d = 0;
	for(int i=0;i<o_length-1;i++)
	{	
		d = extend_index[i+1] - extend_index[i];
		point_distance.push_back(d);
	}
	for(int i=0;i<o_length-1;i++)
	{	
		index1 = extend_index[i]+1;
		index2 = extend_index[i+1]+1;
		Group(group[i],point_distance[i],*extend_array[],index1,index2);//ע�⣺group[i]ҲҪ����
	}
}