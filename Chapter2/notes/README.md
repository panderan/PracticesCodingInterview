## 1. 二分查找

二分查找也称折半查找（Binary Search），它是一种效率较高的查找方法。但是，折半查找要求线性表必须采用顺序存储结构，而且表中元素按关键字有序排列。

**流程：**

假设表中元素是按升序排列，将表中间位置记录的关键字与查找关键字比较，如果两者相等，则查找成功；否则利用中间位置记录将表分成前、后两个子表，如果中间位置记录的关键字大于查找关键字，则进一步查找前一子表，否则进一步查找后一子表。重复以上过程，直到找到满足条件的记录，使查找成功，或直到子表不存在为止，此时查找不成功。

```
int find_first_equal(int arr[], int length, int key)
{
	int s_idx = 0, m_idx = 0, e_idx = 0, ret = 0;
	
	if (arr == NULL || length < 1) {
		return -1;
	}
	
	s_idx = 0;
	e_idx = length-1;
	m_idx = s_idx+(e_idx-s_idx)/2;
	
	while (s_idx <= e_idx) {
		if ((ret=arr[m_idx]-key) == 0) {
			return m_idx;
		}
		if (ret>0) {
			s_idx = m_idx+1;
			m_idx = s_idx+(e_idx-s_idx)/2;
		}
		else {
			e_idx = m_idx-1;
			m_idx = s_idx+(e_idx-s_idx)/2;
		}
	}
	return -1;	
}
```

**要求：**

1.必须采用顺序存储结构。

2.必须按关键字大小有序排列。

## 2. 快速排序

快速排序由C. A. R. Hoare在1960年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

**流程：**

```
void sort(int *a, int left, int right)
{
    if(left >= right) {
        return ;
    }
    
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j) {
        while(i < j && key <= a[j]) {
            j--;
        }
        a[i] = a[j];
        
        while(i < j && key >= a[i]) {
            i++;
        }
        a[j] = a[i];
    }

    a[i] = key;
    
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

