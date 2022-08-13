class Solution {
public:
    int countPoints(string rings) {
        int arr[10][3] = {0};
        int count=0;
        for(int i = 0; i<rings.length() ;i+=2){
            if(rings[i] == 'R'){
                arr[rings[i+1]-'0'][0]++;
            }
            if(rings[i] == 'G'){
                arr[rings[i+1]-'0'][1]++;
            }
            if(rings[i] == 'B'){
                arr[rings[i+1]-'0'][2]++;
            }
            
        }
        for(int i = 0; i<10;i++){
            if(arr[i][0] >0 && arr[i][1] >0 &&arr[i][2] >0){
                count++;
            }
        }
        return count;
    }
};