class MedianFinder {
    priority_queue<int>maxi;
    priority_queue<int , vector<int>, greater<int>>mini;
    double median;
    int signum(int a, int b){
        if(a == b)return 0;
         else if(a > b)return 1;
        else return -1;
    }
public:
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        switch(signum(maxi.size() , mini.size())){
            case 0 : if(num > median){
                mini.push(num);
                median = mini.top();
            }
            else{
                maxi.push(num);
                median= maxi.top();
            }
            break;

            case 1:
                if (num > median) {
                    mini.push(num);
                } else {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(num);
                }
                median = (mini.top() + maxi.top()) / 2.0;
                break;

            case -1:
                if (num > median) {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                } else {
                    maxi.push(num);
                }
                median = (mini.top() + maxi.top()) / 2.0;
                break;
        }
    }
    
    double findMedian() {
        return median;
    }
};
