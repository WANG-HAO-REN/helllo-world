#include <bits/stdc++.h>
using namespace std;

// ch, eng, math, sci, soc, exceptional, total, idx
typedef array<int,8> grade;

struct grade_cmp {
	bool operator () (const grade &a,const grade &b ) const {
		if( a[5] != b[5] )
			return a[5];
		if( a[5] == 0 || b[5] == 0 ) 
			if( b[5] == 0) 
				return a[5];
			if( a[5] == 0) 
				return b[5];
		if( a[6] != b[6] ) 
			return a[6] > b[6];
		for (int i =0; i<5; i++) {
			if(a[i] != b[i])
				return a[i] > b[i];
		}
	}
};


int main () {
	
	int i, j, n;
	cin >> n;
	set<grade, grade_cmp> grades;
	
	for(j = 0; j < n; j++) {
		grade temp;
		temp[5] = 1; // exceptional flag
		temp[6] = 0; // total score
		temp[7] = j; // index
		for(i = 0; i < 5; i++) {
			cin >> temp[i];
			if(temp[i] < 90) 
				temp[5] = 0; // mark as non-exceptional if any score > 90
			temp[6] += temp[i]; // calculate total score
		}
//		cout << temp[6] << endl; 
		grades.insert(temp);
	}
	
	vector<int> r(grades.size());
	int k = 1;
	for (auto it = grades.begin(); it != grades.end(); it++) {
		r[(*it)[7]] = k++;
		cout << (*it)[7] << endl;
//		for (i = 0; i < 5; i++)
//			cout << (*it)[i] << " ";
//		cout << endl;
	}
	
	
	return 0;
}
