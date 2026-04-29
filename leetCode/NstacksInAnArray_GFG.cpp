class NStack {
    int *arr, *top, *next;
    int n, s, freespot;

public: 
    NStack(int N, int S) : n(N), s(S), freespot(0) {
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        for(int i = 0; i < n; i++) top[i] = -1;
        for(int i = 0; i < s - 1; i++) next[i] = i + 1;
        next[s - 1] = -1;
    } 

    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    bool push(int x, int m) {
        if (freespot == -1) return false;

        int index = freespot;      // Current free slot
        freespot = next[index];    // Move freespot to next available
        
        arr[index] = x;            // Insert
        next[index] = top[m - 1];  // Link to previous top
        top[m - 1] = index;        // Update top to current index
        
        return true;
    }
    
    int pop(int m) {
        if (top[m - 1] == -1) return -1;
        
        int index = top[m - 1];    // Current top index
        top[m - 1] = next[index];  // Set top to previous element
        
        next[index] = freespot;    // Link freed index to free list
        freespot = index;          // Update head of free list
        
        return arr[index];
    }
};
