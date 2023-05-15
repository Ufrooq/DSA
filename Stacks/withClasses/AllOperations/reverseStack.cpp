#include <iostream>
#include <stack>
using namespace std;

void reverseRecord(stack<int> &st, int elem, int k, int sz)
{
    if (st.size() == sz - k)
    {
        st.push(elem);
        return;
    }
    else
    {
        int val = st.top();
        st.pop();
        reverseRecord(st, elem, k, sz);
        st.push(val);
    }
}
void reverse(stack<int> &st, int k, int sz, int cnt)
{
    // base case -->
    if (cnt == k)
    {
        return;
    }
    // first step : creation of activation activation Record ---->
    int elem = st.top();
    st.pop();
    reverse(st, k, sz, ++cnt);
    reverseRecord(st, elem, k, sz);
}

void insertBottom(stack<int> &st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }
    else
    {
        int val = st.top();
        st.pop();
        insertBottom(st, num);
    }
}

void display(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    cout << st.top() << " ";
    st.pop();
    display(st);
}
int main()
{

    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(2);
    st.push(7);
    st.push(66);
    // insertBottom(st, 666);
    int k;
    cout << "\nEnter value of K : ";
    cin >> k;
    cout << st.size();
    reverse(st, k, st.size(), 0);
    display(st);
    return 0;
};