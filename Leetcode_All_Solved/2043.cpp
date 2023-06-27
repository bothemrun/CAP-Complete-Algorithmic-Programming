//don't copy the balance vector, just get its address pointer.
//so I assume the original balance vector won't be changed by others after the constructor.
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Bank {
public:
    int n;
    vector<long long>* balance;
    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = &balance;
    }

    inline bool valid_id(const int& acc){
        return 1<=acc && acc<=n;
    }
    inline long long& get_bal(const int& acc){
        return balance->at(acc-1);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if( !valid_id(account1) || !valid_id(account2) ) return false;

        if(get_bal(account1) < money) return false;

        get_bal(account1) -= money;
        get_bal(account2) += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!valid_id(account)) return false;

        get_bal(account) += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid_id(account)) return false;

        if(get_bal(account) < money) return false;

        get_bal(account) -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
