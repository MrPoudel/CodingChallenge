int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

// Complete the maximumToys function below.
int maximumToys(int prices_count, int* prices, int k) {
    qsort(prices, prices_count, sizeof(int), compare);
    int i = 0;
    for(i = 1; i < prices_count; i++){
        prices[i] += prices[i-1];
        if(prices[i] > k){
            return i;
        }
    }
    return i;
}


//Another challenge
// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(char* s) {
  int length = strlen(s) - 1;
  int req_changes = 0;
  int i, j; 

  for (i = 0, j = length; i < j; i++, j--) {  

    while (s[i] != s[j]) {      
        if(s[i] < s[j]){
            s[j]--; req_changes++;
        }
        else{
            s[i]--; req_changes++;
        }
    }
  }
  return req_changes;
}
