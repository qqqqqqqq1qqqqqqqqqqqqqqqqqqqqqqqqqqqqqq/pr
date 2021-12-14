#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//.,.	
template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(){
    }
    Pair(T1 x, T2 y)
    {
        first=x;
        second=y;
    }
    bool operator>(const Pair& other) const{
        if(first>other.first)
            return true;
        else if(first==other.first&&second>other.second)
            return true;
        else
            return false;
    }
    bool operator==(const Pair& other) const{
        if(first==other.first&&second=other.second)
            return true;
        else
            return false;
    }
    bool operator<(const Pair& other) const{
        if(first<other.first)
            return true;
        else if(first==other.first&&second<other.second)
            return true;
        else
            return false;
    }
    Pair operator=(const Pair& copied){
        first=copied.first;
        second=copied.second;
        Pair ans(first,second);
        return ans;
    }
};

template<typename T>
void mySort(vector<T>& a) {
    int len=a.size();
    for(int i=0;i<len;++i)
    {
        for(int j=0;j+1<len;++j)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}	
