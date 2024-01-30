#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// to use like set

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


// to use like multiset

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


// to arrange in descending order

// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// to use multiset in descending order

// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define mod (long long)1000000007

#define ll long long int

#define ld long double


//    use this when making pbds like multiset as in multiset erase will not work
void myerase(pbds &t, long long int v){
    long long int rank = t.order_of_key(v);//Number of elements that are less than v in t
    pbds::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
pbds st;
st.insert(10);
st.insert(8);
st.insert(6);
st.insert(6);
st.insert(2);
st.insert(2);
st.insert(1);

for(auto i:st){
    cout<<i<<" ";
}
cout<<endl;


// finding kth element - 4th query
	cout << "0th element: " << *st.find_by_order(0) << endl;
	cout << "1st element: " << *st.find_by_order(1) << endl;
	cout << "2nd element: " << *st.find_by_order(2) << endl;
	cout << "3rd element: " << *st.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << st.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << st.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 11: " << st.order_of_key(2) << endl; // 4
	cout << "No. of elems smaller than 1: " << st.order_of_key(1) << endl; // 0
	cout << endl;



	 //  imp -> pbds multi element wale m lower bound upper ki tarah behave krta h aur upper lower ki tarah



	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *st.lower_bound(6) << endl;   
	cout << "Lower Bound of 2: " << *st.lower_bound(2) << endl;
	cout << "Lower Bound of 3: " << *st.lower_bound(3) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *st.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *st.upper_bound(1) << endl;
	cout << endl;

	auto i=st.upper_bound(6);
	i++;     
	cout<<*(i)<<"\n";


	// // Remove elements - 2nd query
	st.erase(1);
	st.erase(11); // element that is not present is not affected

	// A contains
	cout << "st = ";
	for (auto i : st)
		cout << i << " ";
	cout << endl;
return 0; 
}