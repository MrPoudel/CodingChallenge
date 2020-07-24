typedef long long ll;

ll largest(ll x, ll y, ll z){
    return std::max(std::max(x, y), z);
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    ll sum1 = 0,sum2 = 0, sum3 = 0;  

    for(auto x:h1)
        sum1 += x;

    for(auto x:h2)
        sum2 += x;

    for(auto x:h3)
        sum3 += x;
 
    while(sum1 != sum2  || sum2 != sum3) {

        int maxVal = largest(sum1, sum2, sum3);

        if(maxVal == sum1) {
            if(!h1.empty()){
                sum1 -= *(h1.begin());             
                h1.erase(h1.begin());
            }
        }
        else if(maxVal == sum2) {
            if(!h2.empty()){
                sum2 -= *(h2.begin());             
                h2.erase(h2.begin());
            }
        }   
        else {           
            if(!h3.empty()){
                sum3 -= *(h3.begin());              
                h3.erase(h3.begin());
            }
        }
    }
     
    return sum3;
}
