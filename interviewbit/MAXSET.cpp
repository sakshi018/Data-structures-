/*Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
*/

vector<int> Solution::maxset(vector<int> &A) {
    
    int start=0, end=0;
    int max_start, max_end;
    long long int max_sum = -1;
    long long int sum = 0;
    int N = A.size();
    for(int i=0; i<N; i++){
        if(A[i] < 0){
            if(sum > max_sum){//This part compares the sum of current segment with the current possible answer.
                max_sum = sum;
                max_start = start;
                max_end = end;
            }
            else if(sum == max_sum){ // This part compares the length of two segment when their sum is same
                if(end-start+1 > max_end-max_start+1){
                    max_start = start;
                    max_end = end;
                }
            }
            sum = 0; // 
            start = end = i+1;
        }
        else{ //In case of +ve no. simply add the number and increment end
            sum += A[i];
            end ++;
        }
    }
    if(sum > max_sum){
        max_sum = sum;
        max_start = start;
        max_end = end;
    }
    else if(sum == max_sum){
        if(end-start+1 > max_end-max_start+1){
            max_start = start;
            max_end = end;
        }
    }
    
    vector<int> result;
    for(int i=max_start; i<max_end; i++){
        result.push_back(A[i]);
    }
    return result;
}