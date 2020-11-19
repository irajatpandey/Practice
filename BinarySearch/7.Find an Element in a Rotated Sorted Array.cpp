#include<iostream>
using namespace std;
int findPivot(int arr[], int n)
{
	// search space is arr[low..high]
	int low = 0, high = n - 1;

	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// if the search space is already sorted, we have
		// found the minimum element (at index low)
		if (arr[low] <= arr[high])
			return low;

		int mid = (low + high) / 2;

		// find next and previous element of the mid element
		// (in circular manner)
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;

		// if mid element is less than both its next and previous
		// neighbor, then it is the minimum element of the array

		if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
			return mid;

		// if arr[mid..high] is sorted and mid is not the minimum element,
		// then pivot element cannot be present in arr[mid..high] and
		// we can discard arr[mid..high] and search in the left half

		else if (arr[mid] <= arr[high])
			high = mid - 1;

		// if arr[low..mid] is sorted then pivot element cannot be present in
		// it and we can discard arr[low..mid] and search in the right half

		else if (arr[mid] >= arr[low])
			low = mid + 1;
	}

	// invalid input
	return -1;
}


int binarySearch(int *arr, int start, int end, int target, int n){
    int index = findPivot(arr,  n);
    if(index == -1) return -1;
    else{
        if(target > arr[end]){
           end = index;
           index = 0;
        }
        
        while(index <= end){
            int mid = index + (end - index)/2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) end = mid - 1;
            else index = mid + 1;
        }
    }
    return -1;
}
int main(){
    cout << "Enter the size of an array " << endl;
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the target " << endl;
    int target; cin >> target;
    cout << binarySearch(arr, 0, n - 1, target, n);
    return 0;

}