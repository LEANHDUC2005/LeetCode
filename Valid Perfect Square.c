bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;
    while( left <= right ){
        int mid = left + (right - left)/2;
        if ( (long)mid * mid > num ) right = --mid;
        else if ( mid * mid < num ) left = ++mid;
        else return true;
    }
    return false;
}
