class SEGTree {
    public:
    vector<long long> seg, lazy;
    SEGTree(int n) {
        seg.resize(4*n);
        lazy.resize(4*n, 0);
    }
    void build(int ind, int low, int high, vector<int>& nums) {
        if(low == high) {
            seg[ind] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2*ind+1, low, mid, nums);
        build(2*ind+2, mid+1, high, nums);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
    void lazyPropagation(int ind, int low, int high) {
        if(lazy[ind] != 0) {
            seg[ind] += lazy[ind];
            if(low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }
    long long query(int ind, int low, int high, int l, int r) {
        lazyPropagation(ind, low, high);
        if(high < l || low > r) return LLONG_MIN;
        if(l <= low && high <= r) return seg[ind];
        int mid = low + (high - low) / 2;
        long long left = query(2*ind+1, low, mid, l, r);
        long long right = query(2*ind+2, mid+1, high, l, r);
        return max(left, right);
    }
    void updateRange(int ind, int low, int high, int l, int r, long long val, vector<int>& nums) {
        lazyPropagation(ind, low, high);
        if(high < l || low > r) return;
        if(l <= low && high <= r) {
            seg[ind] += val;
            if(low != high) {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        int mid = low + (high - low) / 2;
        updateRange(2*ind+1, low, mid, l, r, val, nums);
        updateRange(2*ind+2, mid+1, high, l, r, val, nums);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
};

int main() { /* Code as you need */ }
