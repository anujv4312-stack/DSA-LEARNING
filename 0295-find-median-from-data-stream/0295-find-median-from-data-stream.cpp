class MedianFinder {
public:
priority_queue<int> maxi;
     priority_queue<int,vector<int>,greater<int>> mini; 
    MedianFinder() {
       
    }
    
    void addNum(int num) {
       if(maxi.size()==0 || num<maxi.top()){
        maxi.push(num);
       }
       else{
        mini.push(num);
       }
       if(mini.size()>maxi.size()){
        maxi.push(mini.top());
        mini.pop();
       }
       if(mini.size()+1 <maxi.size()){
        mini.push(maxi.top());
        maxi.pop();
       }
    }
    
    double findMedian() {
        if(mini.size()==maxi.size()){
            int a = maxi.top();
            int b = mini.top();
            int c = a+b;
            return double(c)/2;
        }
        else return maxi.top();
      
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */