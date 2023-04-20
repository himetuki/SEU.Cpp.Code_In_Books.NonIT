#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	ofstream out;                       // 定义一个输出流对象

	out.open("sqrttable.txt");          // 打开文本文件sqrttable.txt
	for (x = 1; x <= 100; x++)
		out << x << '\t' << sqrt(x) << endl;    // 将结果写入文件
	out.close();                       // 关闭文件
	return 0;
}
