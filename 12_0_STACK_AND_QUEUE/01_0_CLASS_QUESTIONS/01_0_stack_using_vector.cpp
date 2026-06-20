#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> v;

public:
     
    void push(int val){//O(1)
        v.push_back(val);
    }
    void pop(){//O(1)
         v.pop_back();
    }
    int top(){//O(1)
       return v[v.size() - 1];
    }

    bool empty(){
        return v.size() == 0;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    while(!st.empty()){
       cout << st.top() << " ";
       st.pop();
    }
    cout << endl;

    return 0;
    
}
