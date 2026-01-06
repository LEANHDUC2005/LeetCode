int guess(int num);
int guessNumber(int n){
    int left = 0;
    int right = n;
    while( left <= right ){
        int mid = left + (right - left)/2;
        if ( !guess(mid) ) return mid;
        else if ( guess(mid) == -1 ) right = --mid;
        else left = ++mid;
    }
    return -1;
}
	
