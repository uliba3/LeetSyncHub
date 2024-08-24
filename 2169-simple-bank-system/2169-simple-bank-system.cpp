class Bank {
private:
    vector<long long> balance;
    int n;
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
        this->n = balance.size();
    }

    bool isValidTransaction(int account){
        if(account > n || account < 1){
            return false;
        }
        return true;
    }

    bool hasValidBalance(int account, long long money){
        if(balance[account-1] < money){
            return false;
        }
        return true;
    }

    void addBalance(int account, long long money){
        balance[account-1]+=money;
    }

    void subtractBalance(int account, long long money){
        balance[account-1]-=money;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValidTransaction(account1)||!isValidTransaction(account2)){
            return false;
        }
        if(!hasValidBalance(account1, money)){
            return false;
        }
        subtractBalance(account1, money);
        addBalance(account2, money);
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValidTransaction(account)){
            return false;
        }
        addBalance(account, money);
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValidTransaction(account)){
            return false;
        }
        if(!hasValidBalance(account, money)){
            return false;
        }
        subtractBalance(account, money);
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