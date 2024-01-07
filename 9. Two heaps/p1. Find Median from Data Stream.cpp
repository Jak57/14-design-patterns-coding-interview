// https://medium.com/@stephen.joel/two-heaps-median-f28ebc1569d7
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder(object):
    def __init__(self):
        self.heaps = [], []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        small, large = self.heaps
        if len(small) == len(large):
            heappush(large ,-heappushpop(small, -num))
        else:
            heappush(small, -heappushpop(large, num))

    def findMedian(self):
        """
        :rtype: float
        """
        small, large = self.heaps
        if len(small) == len(large):
            return (-small[0] + large[0]) / 2.0
        else:
            return float(large[0])
    

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

#################################
  
class MedianFinder {
public:
    priority_queue< int, vector<int>, greater<int> > large;
    priority_queue< int, vector<int>, greater<int> > small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.size() == 0 || num < -small.top())
            small.push(-num);
        else 
            large.push(num);
        
        if (small.size() > (large.size()+1)) {
            large.push(-small.top());
            small.pop();
        } else if (large.size() > (small.size()+1)) {
            small.push(-large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return (-small.top() + large.top()) / 2.0;
        } else
            return small.size() > large.size() ? -float(small.top()) : float(large.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
