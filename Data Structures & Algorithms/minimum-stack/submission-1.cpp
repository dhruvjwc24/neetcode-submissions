class MinStack {
public:
    vector<int> vec;
    vector<int> aux;
    
    MinStack() {

    }
    
    void push(int val) {
        vec.push_back(val);
        if (aux.empty()) aux.push_back(val);
        else aux.push_back(min(val, aux.back()));
    }
    
    void pop() {
        aux.pop_back();
        vec.pop_back();
    }
    
    int top() {
        return vec[vec.size() - 1];
    }
    
    int getMin() {
        return aux.back();
    }
};
