#include <iostream>
#define endl "\n"
using namespace std;

int SubsetSum(int* A, int n, int sum, int index, int d, int count);
bool invalid(int* A, int sum, int n, int index, int d);

int main(void) {
    int c;
    cin >> c;

    for(int i = 0; i < c; i++) {
        int n, d, *A;
        int sum = 0;
        cin >> n;
        A = new int[n];
        
        for(int j = 0; j < n; j++) {
            cin >> A[j];
        }
        cin >> d;

        int count = SubsetSum(A, n, sum, 0, d, 0);
        cout << count << endl;
    }

    return 0;
}


int SubsetSum(int* A, int n, int sum, int index, int d, int count) {
    //count++;
    //int sum2 = 0;

    //sum = sum + A[index];
    if(sum == d) {
        return count;
    }
    else {
        for(int i = 0; i < n; i++) {    
            if(invalid(A, sum, n, i, d) == false) {
                count++;
                sum = sum + A[i];
                
                if(SubsetSum(A, n, sum, i+1, d, count) == 0) {
                    count--;
                    sum = sum - A[i];
                    return count;
                }
                //return 0;
            }
        }

        return 0;
    }

    
    

    //return 0;
}

bool invalid(int* A, int sum, int n, int index, int d) {
    int sum2 = 0;
    for(int i = index + 1; i < n; i++) {
        sum2 = sum2 + A[i];
    }

    if(((sum + A[index+1]) > d) || ((sum+sum2) < d)) {
        return true;
    }

    return false;
}
