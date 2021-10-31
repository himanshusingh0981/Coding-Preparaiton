#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------
						//QUESTIONS
/*
	1- Two sum 			             ->   bool isTwoSum(vector<int>arr,int target)
	2- fourSum 			 			 ->   vector<vector<int>> fourSum(vector<int>& arr, int target)
	3- longest consqutive 		     ->   int longestConsecutive(vector<int>& num)
	4- Largest subarray with 0 sum   ->   int largestSubZeroSum(vector<int>&A, int n)

*/







class Hashing{
public:
//--------------------------------------------------------------------------------------------------------------------------------------	
	//1- Two sum using hashing 
	bool isTwoSum(vector<int>arr,int target){
		unordered_set<int>mp;
		// 1 2 3 4 5 6
		mp.insert(sum);
		for(int i=1;i<arr.size();i++){
			if(mp.find(target-arr[i])!=mp.end()){
				return true;
			}else{
				mp.insert(arr[i]);
			}
		}
		return false;
	}
//--------------------------------------------------------------------------------------------------------------------------------------
	//4 Sum problem using hashing 
vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n= arr.size();
		vector<vector<int>>ans;
            if(arr.size()<4)return ans;

		sort(arr.begin(),arr.end());

		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){

				int targ = target-(arr[i]+arr[j]);
				int left =j+1; int right = n-1;
				while(left<right){
					int sum =  arr[left]+arr[right];
					if(sum<targ)left++;
					else if(sum>targ)right--;
					else{
						vector<int>res(4);
						res[0] = arr[i];
						res[1] = arr[j];
						res[2] = arr[left];
						res[3] = arr[right];
						ans.push_back(res);

						while(left<right && res[2]==arr[left])left++;
						while(left<right && res[3]==arr[right])right--;
					}
				}
				while(j+1<n && arr[j]==arr[j+1])j++;
			}
			while(i+1<n && arr[i]==arr[i+1])i++;
		}
		return ans;
    }

//--------------------------------------------------------------------------------------------------------------------------------------

//3- Longest Consequtive squence
    /*
	Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
	Input: nums = [100,4,200,1,3,2]
	Output: 4
	Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
	Output: 9
    */

    //bruteforce -- sort then find longest consqutive number


     int longestConsecutive(vector<int>& num){
    	//Approch - > 
    	// Initially assume all element as starting element
    	unordered_map<int,bool>mp;
    	for(int i: num){
    		mp[i] = true;
    	}

    	//now find out which elements which not have have element lesser then  themselves 
    	for(int i: num){
    		if(mp.find(i-1)!=mp.end()){
    			mp[i] = false;
    		}
    	}

    	int ans =0;
    	for(int i:num){
    		int count=1;
    		if(mp[i]==true){
    			while(mp.find(i+count)!=mp.end() && count++);
    		}
    		ans = max(ans,count);
    	}
    	return ans;

    }

 //--------------------------------------------------------------------------------------------------------------------------------------
    //4- Largest Subarray with 0 sum
    /*
	The task is to compute the length of the largest subarray with sum 0.

	Example 1:

	Input:
	N = 8
	A[] = {15,-2,2,-8,1,7,10,23}
	Output: 5
	Explanation: The largest subarray with
	sum 0 will be -2 2 -8 1 7.
    */
    /*
	Approach
	1- agr koi bi sum phle dekha hua mila to usme zero hoga
    */


    int largestSubZeroSum(vector<int>&arr, int n)
    {   
        unordered_map<int,int>mp;
        mp.insert({0,-1});//import

        int sum =0;
        int ans =0;
        for(int i=0;i<n;i++){
        	sum+=arr[i];
        	//cout<<sum<<"  "<<mp[sum]<<endl;
        	if(mp.find(sum)!=mp.end()){
        		ans = max(ans,i-mp[sum]);
    	    }
    	    else{
        		mp.insert({sum,i});
        	}
        }
        return ans;
    }

//--------------------------------------------------------------------------------------------------------------------------------------
  //5- Count number of subarrays with given xor
	/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
*/

    int xor_count(vector<int>arr,int _xor){

    	unordered_map<int,int>mp;
        int count=0;
    	mp.insert({_xor,1});
    	int ans =0;
    	for(int i=0;i<arr.size();i++){
    		ans = ans^arr[i];
            int a = ans^_xor;
    		if(mp.find(a)!=mp.end()){
    			
                count+=mp[a];
            }
    		mp[ans]+=1;
    	}
    	return ans;
}


//--------------------------------------------------------------------------------------------------------------------------------------
//6- Subarray Sum Equals K 
/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
*/
	
	int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; //store the prefix sum  and the freq of that sum 
        // 1 2 3 4 5 
        int count=0;
        mp.insert({0,1});
        int sum=0;
        for(int i=0;i<nums.size();i++){
        	sum+=nums[i];
        	if(mp.find(sum-k)!=mp.end()){
        		count += mp[sum-k];
        	}

        	mp[sum]+=1;
        }
        return count;
    }

//--------------------------------------------------------------------------------------------------------------------------------------
//7- 3. Longest Substring Without Repeating Characters
    /*
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
    */
int lengthOfLongestSubstring(string s){
	int n = s.length();
	unordered_set<int>mp;

	int i=0,j=0;
	int maxi =0;
	while(i<n && j<n){
		if(mp.find(s[j])==mp.end()){
			mp.insert(s[j++]);
            int a = mp.size();
			maxi = max(a,maxi);
		}else{
			mp.erase(s[i++]);
		}
	}
	return maxi;
}


//8- Largest array with 0's and 1's
//--------------------------------------------------------------------------------------------------------------------------------------
int maxLen(int arr[], int N)
    {
      //converting 0 to -1 now the problem reduces to find the largest subarray with maximum sum
      int maxi =0;
      unordered_map<int,int>mp;
      mp.insert({0,-1});
      int sum=0;
      for(int i=0;i<N;i++){
          sum+=(arr[i]==0?-1:1);
          if(mp.find(sum)!=mp.end()){
              maxi=max(maxi,(i-mp[sum]));
          }else{
          mp[sum]=i;
          }
      }
      return maxi;
    }

};
int main(){
	
}
