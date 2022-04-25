class Solution {
public:
    int findNthDigit(int n) {
        //know it's in 100~999
        long long digit_pow10 = 1;
        long long digit_cnt = 1;
        long long nn = n;
        while( nn > 9*digit_pow10*digit_cnt ){
            nn -= 9*digit_pow10 * digit_cnt;
            digit_pow10 *= 10;
            digit_cnt++;
        }
        //after subtracting (9+90), now get digit_cnt == 3, digit_pow10 == 100
        
        //get which number of 100~999
        long long number = (nn-1)/digit_cnt + digit_pow10;
        long long digit_of_number_from_left = (nn-1)%digit_cnt;//if number==100, then nn=1, (1-1)%3==0
        for(int i=0;i<(digit_cnt-digit_of_number_from_left-1);i++){
            number /= 10;
        }
        return (int)(number%10);
    }
};
