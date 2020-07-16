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
