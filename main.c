#include <stdio.h>
//求三数的最大和
int Max3(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    if (b > a && b > c)
        return b;
    else
        return c;
}
//最大子列问题
static int
MaxSubSum(const int A[], int Left, int Right)
{
    //左侧最大子列，右侧最大子列
    int MaxLeftSum, MaxRightSum;
    //包括左侧最右边值的最大子列，包括右侧左边值的最大子列
    int MaxLeftBorderSum, MaxRightBorderSum;
    //左侧子列，右侧子列
    int LeftBorderSum, RightBorderSum;
    if (Left == Right) //基准情况
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;

    int Center = (Left + Right) >> 1;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (int i = Center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (int i = Center + 1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum>MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum(const int A[], int N)
{
    return MaxSubSum(A, 0, N - 1);
}

int main()
{
    int nums[] = {8, 7, -1, 4, 8, 20};
    int len = sizeof(nums) / sizeof(int);
    int MaxSub = MaxSubsequenceSum(nums, len);
    printf("The MaxSubsequence of nums is %d", MaxSub);
    return 0;
}
