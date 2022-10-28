# Assignment 3

## sort.cc

### Output
    5 7 9 2 6 4 0 3 8 1 
    0 1 2 3 4 5 6 7 8 9 
    Insert: 0 ms 
    Sort failure: 5, 2

Insert sort has taken 0ms for this run. Additionally I added a before-and-after view of the array for debugging.

### Code
~~~
int svindex = 1;
while(svindex < (int)array.size()) {
    int i = 0;
    while(array[i]<array[svindex] && i<svindex) {
        i++;
    }
    int insertvalue = array[svindex];
    for(int switchindex = svindex; switchindex > i; switchindex--) {
        array[switchindex] = array[switchindex-1];
    }
    array[i] = insertvalue;
    svindex++;
}
~~~

- svindex is index of the value considered for insertion. We find the correct index for the value to be moved, then shift all values below svindex to accommodate it. svindex is then incremented upwards by 1 and the process is repeated until the entire array is sorted.
- This code could be shortened by combining the two loops into one.