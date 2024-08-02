int factorial(int n){
        int ans = 1;
        
        for(int i=1;i<=n;i++){
            ans=ans*i;
        }
        
        return ans;
    }
    string solve(string str,int n,int k){
        
        if(n==1){
            return str;
        }
        
        int value = factorial(n)/n;
        int divi = k/value;
        int rem = k%value;
        
        string newStr= "";
        
        for(int i=0;i<n;i++){
            if(i!=divi){
                newStr+=str[i];
            }
        }
        
        return str[divi] + solve(newStr,newStr.length(),rem);
    }
    string kthPermutation(int n, int k)
    {
        string str="";
        
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }
        
        string ans = solve(str,n,k-1);
        
        return ans;
    }