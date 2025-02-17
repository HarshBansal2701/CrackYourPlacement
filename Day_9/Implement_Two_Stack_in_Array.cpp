//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
    int arr[250];
    int size1 = 0;
    int top1 = -1;
    int size2 = 0;
    int top2 = 250;
    public:

    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        top1++;
        arr[top1] = x;
        size1++;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        top2--;
        arr[top2] = x;
        size2++;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 == -1){
            return -1;
        }
        int ele = arr[top1];
        size1--;
        top1--;
        return ele;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == 250){
            return -1;
        }
        int ele = arr[top2];
        size2--;
        top2++;
        return ele;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends