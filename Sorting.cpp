//----------------------------------------------------------------------------------------------------------------------------------------
//1- Selection sort Algorithm 
    /*
        Approach- : O(n^2)
        1- phle array ko 2 part me divide kr lege sorted or unsorted 
        2- initially sorted part is empty 
        3- unsorted part me se minimum ya fir maximum element nikal ke sorted part me dal dege 
    */
    void Selection_sort(int arr[], int n)
    {
        // Your code here 
      int min;
      for(int i=0;i<n;i++){
        min =i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    }


 //----------------------------------------------------------------------------------------------------------------------------------------
    //2- Insertion sort algorithm 
    /*
		Approach- 
		1- Array ko 2 parts me divide kr lege sorted and unsorted part 
		2- Sorted part me initially 1 element hoga
		3- Unsorted part s ek element nikal ke use sorted part me sahi location pe dal dege
		4- Last me array sorted ho jaega
    */

    void Isertion_sort(int arr[], int n)
    {
      // Your code here 
      for(int i=1;i<n;i++){
          int j=i;
          int value = arr[i];
          while(j>0 && arr[j-1]>value){
              arr[j] = arr[j-1];
              j--;
          }
          arr[j] = value;
      }
    }

//----------------------------------------------------------------------------------------------------------------------------------------
//3- Bubble sort -> O(n^2)
//At each step the next larger element will be bubble up to its correct position
    /*
	1- isme comparison adjacent pe hota h 
	2- har bar iteration se last me element sort ho jaega
    */


    void bubbleSort(int arr[], int n)
    {
        // Your code here 
      for(int i=0;i<n;i++){
          for(int j=0;j<n-1-i;j++){
              if(arr[j]>arr[j+1]){
                  swap(arr[j],arr[j+1]);
              }
          }
      }
    }

 //----------------------------------------------------------------------------------------------------------------------------------------
//4- Merge sort Algorithm -O(nlogn)
    /*
	Approach - 
	MergeSort(arr[], l,  r)
	If l<r:
     1. Find the middle point to divide the array into two halves:  
             middle m = l+ (r-l)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
    */

   void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            
            int mid = (l+r)>>1;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
            //cout<<l<<" "<<mid<<" "<<r<<endl;
    }}

   void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int l1 = mid-l+1;
         int l2 = r-mid;
         int k=l;
         int arr1[l1],arr2[l2];
         for(int i=0;i<l1;i++){
             arr1[i] = arr[l+i];
         }
         for(int i=0;i<l2;i++){
             arr2[i] = arr[mid+1+i];
         }
         int i=0,j=0;
         while(i<l1 && j<l2){
             if(arr1[i]<=arr2[j]){
                 arr[k++] = arr1[i++];
             }
             else{
                 arr[k++] = arr2[j++];
             }
         }
         while(i<l1){
             arr[k++] = arr1[i++];
         }
         while(j<l2){
             arr[k++] =arr2[j++];
         }
    }


//----------------------------------------------------------------------------------------------------------------------------------------
    //5- Quick sort Algorithm --> O(nlogn)

    /*
	Approach of partition 
	1- take start =low ab start ke left me jitne bi element hoge wo pivot s chote hoge
	2- Traverse krenge array low to high-1 agr koi element pivot se chota he to use start wali location pe dal ke start ko increase kr dege
	3- Last me high wale index pe jo pda h usko swap kre dege start wale index ke start and return kr dege start element

    */

 void quickSort(int arr[], int low, int high)
    {
        // code here
       if(low<high){
       int p = partition(arr,low,high);
       quickSort(arr,low,p-1);
       quickSort(arr,p+1,high);
    }
 }
int partition (int arr[], int low, int high)
   {
       // Your code here
      	int start = low;
      	int pivot = arr[high];
   
       	for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr[start],arr[i]);
            start++;
    		}
    	}
        swap(arr[start],arr[high]);
        return start;
	}

//----------------------------------------------------------------------------------------------------------------------------------------

//6- Alternative positive and negative number order does not matter
    int partition(int arr[],int low,int high){
        int pivot = 0;
        int start=0;
        for(int i=0;i<high;i++){
            if(arr[i]<pivot){
                swap(arr[i],arr[start++]);
            }
        }
        //start hold the address of first positive integer
        return start;
    }

	void rearrange(int arr[], int n) {
	    // code here
	    int p  = partition(arr,0,n-1);
	    int j=p;
	    for(int i=0;i<p&& j<n; i+=2,j+=2){
	        swap(arr[i],arr[j]);
	    }
	}
