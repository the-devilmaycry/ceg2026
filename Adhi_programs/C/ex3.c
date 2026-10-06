#include <stdio.h>

int main() {
    int a[10],n;
    printf("Enter total no of elements ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int k=0;k<n;k++){
        for(int j=k+1;j<n;j++){
            if (a[k]==a[j]){
                for (int temp=j;temp<n-1;temp++){
                    a[temp]=a[temp+1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\nAfter Removing Duplicate values\n");
        for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    

}

