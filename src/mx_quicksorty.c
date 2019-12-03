#include "uls.h"

static void swap_str(char **s1, char **s2);

static void swap_str(char **s1, char **s2) {
   char *temp;
   temp = *s1;
   *s1 = *s2;
   *s2 = temp;
}

char **mx_quicksorty(char **arr, int left, int right)
{
    if(left < right)
    {
        int low = left, high = right;
        char *middle = arr[(low + high) / 2];
        while(low <= high)
        {
            while(mx_strcmp(arr[low], middle) < 0) low++;
            while(mx_strcmp(arr[high], middle) > 0) high--;
            if(low <= high)
            {
                swap_str(&arr[low],&arr[high]);
                low++;
                high--;
            }
        }
        mx_quicksorty(arr, left, high);
        mx_quicksorty(arr, low, right);
    }
    return arr;
}
