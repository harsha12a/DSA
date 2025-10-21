class SEGTree {
    public:
    vector<int> seg;
    SEGTree(int n) {
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int>& nums) {
        if(low == high) {
            seg[ind] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2*ind+1, low, mid, nums);
        build(2*ind+2, mid+1, high, nums);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int query(int ind, int low, int high, int l, int r) {
        if(l > high || r < low) return 0;
        if(l <= low && high <= r) return seg[ind];
        int mid = low + (high - low) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int idx, int val) {
        if(low == high) {
            seg[ind] += val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(idx <= mid) update(ind, low, mid, idx, val);
        else update(ind, mid+1, high, idx, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};

int main() { /* Code as you need */ }
