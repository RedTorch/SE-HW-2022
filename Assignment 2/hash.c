# include <stdio.h>

int main() {
  int bucketSize = 9;
  int delta = 2;
  int objs[] = {0,1,9,3,13,14,15,7,2};
  int value = 1;
  // the hash search algorithm is below
  // this algorithm is vulnerable to infinite loop if the value is now found!!
  // I would need to determine minimum number of cycles until all values are covered. This is complicated by the fact that the array starts at zero
  int index = value%(sizeof(objs)/sizeof(objs[0]));
  // int size = (sizeof(objs)/sizeof(objs[0]));
  // int index = 
  while(objs[index]!=value) {
    index += 2;
  }
  printf("%d is the index\n",index);
  return 0;
}