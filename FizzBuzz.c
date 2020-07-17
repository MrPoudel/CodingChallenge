void fizzBuzz(int n) {
    for (int i = 1; i <= n; i++) {
        if((i % 3 == 0) && (i % 5 == 0))
            printf("FizzBuzz\n");
        else if((i % 3 == 0) && (i % 5 != 0))
            printf("Fizz\n");
        else if((i % 3 != 0) && (i % 5 == 0))
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }
}


long findTheShortestRoof(vector<long> &cars, int k) {

    sort(cars.begin(), cars.end());

    long int min = LONG_MAX;
    for(int i = 0; i <= (cars.size() - k); i++){
        if((cars[i+k-1] - cars[i]) < min){
            min = cars[i+k-1] - cars[i];
        }
    }

    return min + 1;
}
