#include <stdio.h>
void printNumbers(int *);

int main(){
    int nums[2][10]={{0}};
    int i=0, curNumsId=0, level = 0;
    scanf("%d", &level);
    // Init
    nums[curNumsId][0] = 1;
    printNumbers(nums[curNumsId]);

    for(i=1;i<level;i++){
        printf("\n");
        // Generate numbers
        for(int j=0;j<=i;j++){
            if(j==0||j==i)
                nums[curNumsId][j]=1;
            else {
                nums[curNumsId][j]=nums[(1-curNumsId)][j-1]+nums[(1-curNumsId)][j];
            }
        }
        printNumbers(nums[curNumsId]);
        curNumsId=1-curNumsId;

    }

    return 0;
}

void printNumbers(int *nums) {
    for(int i=0;i<10;i++){
        if(nums[i]!=0)
            printf("%d ", nums[i]);
        else
            break;
    }
}
