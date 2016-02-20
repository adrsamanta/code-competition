
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

//#The first number is N, (1 <= N <= 100), which represents the total number of goods.
//#
//# Next comes a number M, which represents your budget. 0
//#
//# Then there are N pairs of number, Si and Pi.
//#
//# Si represents the expected satisfaction from good i. 0 <= Si <= 100.
//#
//# Pi represents its price. 0 <= Pi <= 100.


//Congratulations, you are in charge of buying food & drinks for the upcoming coding challenge!
//
//You have figured out that there are N goods, each comes at a price Pi and a satisfaction number Si.
//All the goods look great.If possible, you really hope to buy them all.But you only have a fixed budget, M.
//
//You can buy a combination of goods if the budget allows.But you can only purchase one good once and 
//gain the expected satisfaction from that good.Your overall expected satisfaction is the sum of satisfaction of the goods you bought.
//
//Calculate how much satisfaction you can get from this fixed budget.


using namespace std;


int main()
{
	
	int count, budget;
	//satisfaction, price
	std::map<double, pair<int, int>> items_map;

	cin >> count;
	cin >> budget;
	//vector<int> satisfaction, price;
	//vector<double> ratio;
	int tmp1, tmp2;
//	cout << "budget" << budget << "count" << count << endl;
	while (items_map.size()<count && cin >>tmp1 >>tmp2)
	{
//		cout << "read in" << tmp1 << " " << tmp2 << endl;
		double tmpd = tmp1;
		items_map[tmpd / tmp2] = pair<int, int>(tmp1, tmp2);
	}
//	cout << "out of loop" << endl;
	auto iter = items_map.rbegin();
	int satisfaction = 0, spent = 0;
	while (spent<budget && iter!=items_map.rend())
	{
		if(iter->second.second<=(budget-spent))
		{
//			cerr << "looking at " << iter->second.first <<" "<<iter->second.second;
			spent += iter->second.second;
			satisfaction += iter->second.first;
		}
		++iter;
	}

	cout << satisfaction << endl;
	cin.get();



}