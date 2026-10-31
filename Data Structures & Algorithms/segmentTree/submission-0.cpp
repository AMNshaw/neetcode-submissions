struct SegmentTreeNode{
    SegmentTreeNode(int total, int L, int R){
        sum = total;
        l = L;
        r = R;
        left = nullptr;
        right = nullptr;
    }

    int sum;
    int l;
    int r;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
};


class SegmentTree {
public:

    SegmentTree(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    static SegmentTreeNode* build(vector<int>& nums, int l, int r){
        if(l == r) return new SegmentTreeNode(nums[l], l, r);

        int m = (l + r) / 2;
        SegmentTreeNode* node = new SegmentTreeNode(0, l, r);
        node->left = SegmentTree::build(nums, l, m);
        node->right = SegmentTree::build(nums, m + 1, r);
        node->sum = node->left->sum + node->right->sum;
        return node; 
    }
    
    void update(int index, int val) {
        update(root, index, val);
    }
    
    int query(int L, int R) {
        return query(root, L, R);
    }
private:
    SegmentTreeNode* root;

    void update(SegmentTreeNode* node, int index, int val) {
        if (node->l == node->r) {
            node->sum = val;
            return;
        }
        int m = (node->l + node->r) / 2;
        if (index <= m) update(node->left, index, val);
        else update(node->right, index, val);
        node->sum = node->left->sum + node->right->sum;
    }

    int query(SegmentTreeNode* node, int L, int R) {
        if (L <= node->l && node->r <= R) return node->sum;
        int m = (node->l + node->r) / 2;
        int sum = 0;
        if (L <= m) sum += query(node->left, L, R);
        if (R > m) sum += query(node->right, L, R);
        return sum;
    }
};