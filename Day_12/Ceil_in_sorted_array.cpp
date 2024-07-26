int ceilSearch(vector<int> arr, int x){
    
    int s = 0;
    int e = arr.size()-1;
    
    int mid = (e-s)/2 + s;
    
    while(s<=e){
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return mid;
}
