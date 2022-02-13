//uva1203
//not uva3135

//from : Programming/stl/priority_queue_best_practice/heap_operator_overloading_class_constructor.cpp
//1. priority queue by class, class constructor, operator overloading
//2. function overloading of the 2 operator overloading
//3. sort of struct with struct constructor, operator overloading
//4. inspiration : https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

#include<iostream>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

class Query{
public:
	int q_num;
	int period;
	int alarm;
	Query(int q_num_,int period_){
		q_num=q_num_;
		period=period_;
		alarm=period_;
	}
};

bool operator<(const class Query& q1, const class Query& q2){
	if(q1.alarm != q2.alarm) return q1.alarm > q2.alarm;
	else return q1.q_num > q2.q_num;
}

int main(){
	priority_queue<class Query> min_heap;

	string line;
	while(1){
		getline(cin,line);
		if(line[0] == '#') break;

		string reg;
		int q_num, period;
		stringstream ss(line);
		ss >> reg >> q_num >> period;
		min_heap.push( Query(q_num, period) );
	}

	int K;
	cin >> K;
	for(int i=0;i<K;i++){
		class Query q = min_heap.top();
		min_heap.pop();
		cout << q.q_num << "\n";

		q.alarm += q.period;
		min_heap.push( q );
	}
	return 0;
}

