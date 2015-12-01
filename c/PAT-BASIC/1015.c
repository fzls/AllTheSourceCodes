#include <stdio.h>
#define MAX 100000
struct candidate
{
  long long number;
  int D;
  int C;
  int sum;
};
void sp( struct candidate lv[], int count) {
  int i, j, index;
  //sort
  struct candidate temp;
  for (i = 0; i < count; i++) {
    index = i;
    for (j = i; j < count; j++)
      if (lv[j].sum > lv[index].sum || lv[j].sum == lv[index].sum && lv[j].D > lv[index].D || lv[j].sum == lv[index].sum && lv[j].D == lv[index].D && lv[j].number < lv[index].number)
        index = j;

    temp =   lv[index];
    lv[index] = lv[i];
    lv[i] = temp;
  }

  //output
  for (i = 0; i < count; i++)
    printf("%lld %d %d\n", lv[i].number, lv[i].D, lv[i].C);
}
int main() {
  struct candidate can[MAX], lv1[MAX], lv2[MAX], lv3[MAX], lv4[MAX];

  int n, l, h, i, count = 0, count1, count2, count3, count4;
  count1 = count2 = count3 = count4 = 0;
  scanf("%d%d%d", &n, &l, &h);
  //input data
  for (i = 0; i < n; i++) {
    scanf("%lld%d%d", &can[i].number, &can[i].D, &can[i].C);
    can[i].sum = can[i].C + can[i].D;
  }
  //classfied
  for (i = 0; i < n; i++)
    if (can[i].D >= l && can[i].C >= l) {
      count ++;

      if (can[i].D >= h && can[i].C >= h)
        lv1[count1++] = can[i];
      else if (can[i].D >= h && can[i].C < h)
        lv2[count2++] = can[i];
      else if (can[i].D < h && can[i].D >= can[i].C )
        lv3[count3++] = can[i];
      else
        lv4[count4++] = can[i];
    }

  //sort and output
  printf("%d\n", count);

  sp(lv1, count1);
  sp(lv2, count2);
  sp(lv3, count3);
  sp(lv4, count4);
  system("pause");

}
