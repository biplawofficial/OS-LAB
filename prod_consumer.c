#include <stdio.h>
// using namespace std;
void wait(int s) {
  while (s <= 0)
    ;
  s--;
}
void signall(int s) { s++; }
int sizee(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) count++;
  }
  return count;
}
void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int n;
  printf("Enter the size of buffer\n");
  scanf("%d", &n);
  int buffer[n];
  for (int i = 0; i < n; i++) {
    buffer[i] = 0;
  }
  int mutex = 1;
reset:
  printf("\nEnter\n1-producer\n2-consumer\n0-exit\n\n\n");
  int user;
  scanf("%d", &user);
  switch (user) {
    case 1: {
      // producer
      if (sizee(buffer, n) <n) {
        wait(mutex);
        for (int i = 0; i < n; i++) {
          if (buffer[i] == 0) {
            buffer[i] = 1;
            break;
          }
        }
        signall(mutex);
        print(buffer, n);
      }
      else
      {
          printf("consume something to be produced\n");
      }
      break;
    }
    case 2: {  
        if (sizee(buffer, n) > 0) {
          wait(mutex);
          for (int i = 0; i < n; i++) {
            if (buffer[i] == 1) {
              buffer[i] = 0;
              break;
            }
          }
          signall(mutex);
          print(buffer, n);
      }
      else
      {
          printf("produce something to be consumed\n");
      }

      break;
    }
    case 0:
      goto exit;
    default:
      goto reset;
  }
  goto reset;
  exit:
  printf("process executed successfully\n");
  return 0;
}