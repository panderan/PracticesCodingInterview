## 1. 二分查找

二分查找也称折半查找（Binary Search），它是一种效率较高的查找方法。但是，折半查找要求线性表必须采用顺序存储结构，而且表中元素按关键字有序排列。

**流程：**

假设表中元素是按升序排列，将表中间位置记录的关键字与查找关键字比较，如果两者相等，则查找成功；否则利用中间位置记录将表分成前、后两个子表，如果中间位置记录的关键字大于查找关键字，则进一步查找前一子表，否则进一步查找后一子表。重复以上过程，直到找到满足条件的记录，使查找成功，或直到子表不存在为止，此时查找不成功。

**要求：**

1.必须采用顺序存储结构。

2.必须按关键字大小有序排列。

## 2. 快速排序

快速排序由C. A. R. Hoare在1960年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

**流程：**

```
void sort(int *a, int left, int right)
{
    /*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    if(left >= right) {
        return ;
    }
    
    int i = left;
    int j = right;
    int key = a[left];
    
    /*控制在当组内寻找一遍*/
    while(i < j) {
        /* 而寻找结束的条件就是，
           1. 找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）
           2. 没有符合条件1的，并且i与j的大小没有反转 
        */ 
        while(i < j && key <= a[j]) {
            j--;/*向前寻找*/
        }
        
        /* 找到一个这样的数后就把它赋给前面的被拿走的i的值
          （如果第一次循环且key是a[left]，那么就是给key)
        */ 
        a[i] = a[j];
        
        /* 这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
           因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反
        */ 
        while(i < j && key >= a[i]) {
            i++;
        }
        a[j] = a[i];
    }
    
    /* 当在当组内找完一遍以后就把中间数key回归 */
    a[i] = key;
    
    /* 最后用同样的方式对分出来的左边和右边的小组进行同上的做法，直到每一组的i = j 为止 */
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}
```



## 3. 归并排序

归并排序（MERGE-SORT）是建立在归并操作上的一种有效的排序算法,该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。

流程：归并排序（MERGE-SORT）是建立在归并操作上的一种有效的排序算法,该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。

**流程：**

```
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1) {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
        
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
        
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex)/2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

```

