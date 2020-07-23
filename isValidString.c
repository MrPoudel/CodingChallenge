int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

char* isValid(char* s) {
    int hashTable[1000] = {0};

    int len = strlen(s);
    int repeated_char = 0; 
    int pos = 0;  
    int arr[100] = { [0 ... 99] = -1 };  

    for (int i = 0 ; i < len; i++) {
        hashTable[s[i]]++;
        if(hashTable[s[i]] > 1){
            arr[i] = 0;
            repeated_char++;
        }
    }    

    for (int i = 0 ; i < len; i++) {
        if(arr[i] == -1)      
            arr[pos++] = hashTable[s[i]];    
    }

    int size = len - repeated_char;
    qsort(arr, size, sizeof(int), compare);

    int chkVal = arr[0];
    bool done = true;

    for (int i = 1; i < size; i++) {
        if (arr[i] != chkVal) {
            // decrease the biggest count by one
            arr[size-1] -= 1;
            done = false;
            break;
        }
    }

    if (done)
        return "YES";

    for (int i = 1; i < size; i++) {
        if (arr[i] != chkVal) {
            // again, if there exist a discrepancy then
            // string is not a valid
            return "NO";
        }
    }

    return "YES";   
}
