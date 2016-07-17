#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& A, int target) {
    int n = A.size();
    int lo =0, hi = n-1;
    int mid = 0;
    while(lo<hi){
          mid=(lo+hi)/2;
          if(A[mid]==target) return true;
          if(A[mid]>A[hi]){
              if(A[mid]>target && A[lo] <= target) hi = mid;
              else lo = mid + 1;
          }else if(A[mid] < A[hi]){
              if(A[mid]<target && A[hi] >= target) lo = mid + 1;
              else hi = mid;
          }else{
              hi--;
          }
          
    }
    return A[lo] == target ? true : false;
  }

int main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8};
	vector<int> v2 = {5,5,5,1,5,5,5};
	cout << search(v1, 4) << endl;
	cout << search(v1, 10) << endl;
	cout << search(v2, 5) << endl;
	cout << search(v2, 4) << endl;
}