#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<fenv.h>

int return_higher_value(const void *a, const void *b) {
  int arg1 = *(const int*)a;
  int arg2 = *(const int*)b;
  return arg1 > arg2 ? 1 : -1;
}

int main() {
  // vvv these are the given array and the value that we are looking. The array does NOT have to be presorted, as we qsort() it before applying binary search.
  int array[] = {10,40,30,90,32,543,23432,1243123,21323,23214,36765};
  int target_value = 23432;
  // vvv  binary search algorithm operates under the assumption that the array is sorted
  // vvv  we conveniently use qsort from the c library to sort this array
  qsort(array,sizeof(array)/sizeof(*array),sizeof(*array),return_higher_value);
  // vvv  next, we display the array on the screen
  int size_of_array = sizeof(array)/sizeof(*array);
  for(int loop = 0; loop < size_of_array; loop++)
      printf("%d ", array[loop]);
  printf("\n key = %i \n",target_value);
  // vvv  sorting algorithm commences below
  int upper_bound = size_of_array - 1;
  int lower_bound = 0;
  int checked_index = 0; // we declare this value outside the loop for efficiency; not strictly necessary
  while(upper_bound >= lower_bound+1) {
    checked_index = round((upper_bound+lower_bound)/2);
    printf("searching index from %i to %i : pivot point %i \n", lower_bound, upper_bound, checked_index);
    if(array[checked_index] == target_value) {
      printf("target value found at index %i \n",checked_index);
      return 0;
    }
    else if(array[checked_index] < target_value) {
      lower_bound = checked_index;
    }
    else {
      upper_bound = checked_index;
    }
  }
  printf("target value not found \n");
  return 0;
}