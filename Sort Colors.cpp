class Solution {
public:
//use counting sort
void sortColors(int A[], int n) {
int red = -1, white = -1, blue = -1;

for(int i = 0; i < n; i++){
    if(A[i] == 0){   
        A[++blue] = 2;
        A[++white] = 1;
        A[++red] = 0;
    }
    else if(A[i] == 1){
        A[++blue] = 2;
        A[++white] = 1;
    }
    else if(A[i] == 2)   
        A[++blue] = 2;
}
}
};