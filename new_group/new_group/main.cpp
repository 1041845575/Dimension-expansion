#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
void init(int num,vector<double>&origin_array)
{
	fstream fin;
	double data = 0;
	fin.open("G:\\lei\\code\\new_group\\result.txt",std::ios::in);
	if(!fin)cout<<"error";
	for(int i=0;i<num;i++)
	{
		fin>>data;
		origin_array.push_back(data);

	}

}
void extend_num(vector<double>&extend_array,int e_length,vector<double>origin_array)
{
	int o_length =0;
	cout<<e_length;
	o_length = origin_array.size();
	double step1 = 0;
	int step = 0,mod = 0,count = 0;
	step1 =(e_length-o_length)/(o_length-1);
	step = floor(step1);
	mod = (e_length-o_length)%(o_length-1);
	double extend_data = 0;
	int k = 0,i = 1,j = 0;
	while(extend_array.size()<e_length)
	{
		if(origin_array[k+1]>origin_array[k])
		extend_data = origin_array[k]+(origin_array[k+1]-origin_array[k])/step*(i-1);
		else
			extend_data = origin_array[k]-(origin_array[k]-origin_array[k+1])/step*(i-1);
		extend_array.push_back(extend_data);
		if((i-1)==(step+1))
		{
			if(mod!=0&&count<mod)
			{
				extend_array.push_back(extend_data);
				count++;	
			}
			k+=1;
			i = 0;
		}
		i++;
	}
}
void main()
{
	vector<double>origin_array;
	vector<double>extend_array;
	init(3,origin_array);
	extend_num(extend_array,25,origin_array);
	fstream fout;
	fout.open("G:\\lei\\code\\new_group\\result1.txt",std::ios::out);
	for(int i=0;i<25;i++)
	{
		cout<<i<<" "<<extend_array[i]<<endl;
		fout<<extend_array[i]<<endl;
	}
	system("pause");
}