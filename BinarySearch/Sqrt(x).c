int mySqrt(int x) {
    int left = 1;
    int right = x;
    while(left <= right){
        int mid = left + (right - left)/2;
        if ( (long)mid*mid > x ) right = --mid;
        else if ( (long)mid*mid < x ) left = ++mid;
        else return mid;
    }
    return right;
}
