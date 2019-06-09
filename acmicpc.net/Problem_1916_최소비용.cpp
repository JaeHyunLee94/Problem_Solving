#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define LONGLONG_MAX 9223372036854775807
using namespace std;

struct node {
	int vertex;
	long long dis;
};

bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}



int main() {
	
	
	int city_num, bus_num;
	cin >> city_num >> bus_num;

	vector<vector<pair<int , long long>>> adj_list(city_num+1);
	vector <bool> is_visit(city_num + 1, false);
	vector <long long> dist_to(city_num+1,LONGLONG_MAX);

	priority_queue <node> pq;

	int from, to;
	long long price;

	int start_city, end_city;


	for (int i = 0; i < bus_num; i++) {

		scanf_s("%d %d %lld", &from, &to, &price);

		adj_list[from].push_back(make_pair(to, price));

	}
	cin >> start_city >> end_city;

	dist_to[start_city] = 0;
	

	pq.push(node{ start_city,0 });


	while (!pq.empty()) {

		node x = pq.top();
		pq.pop();

		if (is_visit[x.vertex]) continue;
		else {
			is_visit[x.vertex] = true;

			for (auto& n : adj_list[x.vertex]) {

				if (is_visit[n.first]) continue;

				if (dist_to[n.first] > dist_to[x.vertex] + n.second) {
					dist_to[n.first] = dist_to[x.vertex] + n.second;
					pq.push(node{ n.first,dist_to[n.first] });
				
				}
				
				
			}



		}

	



	}
	cout << dist_to[end_city];




 
	
	
	
	system("pause");
	return 0;
}