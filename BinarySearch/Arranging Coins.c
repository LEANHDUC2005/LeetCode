int arrangeCoins(int n) {
    int left = 0;
    int right = n;
    while(left <= right){
        int mid = left + (right - left)/2;
        if ( (long)mid*(mid+1)/2 > n ) right = --mid;
        else left = ++mid;
    }
    return right;
}
