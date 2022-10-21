# Assignment 2

## Binary Search (binary.c)

    10 30 32 40 90 543 21323 23214 23432 36765 1243123 
    key = 23432 
    searching index from 0 to 10 : pivot point 5 
    searching index from 5 to 10 : pivot point 7 
    searching index from 7 to 10 : pivot point 8 
    target value found at index 8

- This uses the classic binary search.
- An unsorted array can be used; qsort() ensures that it will be sorted.
- Then, binary search will commence with the key value.
- The debug messages above illustrate the binary search algorithm. Observe that the search set is incrementally narrowed and the pivot point is reset to the middle.
- If the value was not found at the predicted location, it would alert the user.

## Hash Search (hash.c)

    1 is the index

- The output is overly simplistic, but the program is telling the user the index where value "value" (set to 1) can be found.
- The program follows the hash format to find the correct index.
- An insert function is not established. The set used is a pre-hashed array. Anything else will fail.
- A mechanism for catching non-values is not present. It would require establishing a maximum number of searches before giving up.
