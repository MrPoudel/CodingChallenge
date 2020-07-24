/* Here the fundamental idea is that, first we calculate the sum of elements until sum < x from first stack. Then count the numbers.
After that we keep on adding the elements from the second stack .  After every addition, we check if the sum surpasses the x.
if sum surpasses the sum then we remove the elements from a one by one unless the sum <= x. We proceed this until we removed all the 
added elements from stack a. However, if the sum becomes smaller than x before we had a chance to remove all the added elements from 
stack we stop here and exit the loop.
If the sum if samller and elements from stack a and b (i + j ) are more than the count then new count would be i+j. Otherwise,, keep
continue until all the elements from a are removed or elemets of b are all checked. */

int twoStacks(int x, vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    int sum = 0;
    int count = 0;

    while(i < a.size() && sum+a[i] <= x){
        sum += a[i];
        i++;
    }

    count = i;

    while(j < b.size() && i >= 0) {
        sum += b[j];
        j++;

        while(sum > x && i > 0) {
            i--;
            sum -= a[i];
        }

        if(sum <= x && i+j > count) {
            count = i +j;
        }
    }

    return count;
}
