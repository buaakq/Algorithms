#include <string>
#include <vector>

using namespace std;

class BTreeNode{
public:
	int val;
	BTreeNode *left;
	BTreeNode *right;
	BTreeNode ();
	BTreeNode (int val){
		this->val = val;
		this->left = this->right = nullptr;
	}
};


class BTree{
    public:
    	BTree(){root = nullptr;}
        BTree(BTreeNode *node){root = node;}
    	~BTree(){}
    	bool empty() const;

    	void add(int val);
        void add_vector(vector<int> v)
        {
            for (int i : v)
                add_helper(root, i);
        }
    	void preorder(bool);
    	void inorder(bool);
    	void posorder(bool);
    	void level();
    	void display();
        std::string serialise(); 
        BTreeNode * get_root(){return root;}

    private:
    	BTreeNode * root;

    	void display_helper(BTreeNode * node);

    	void add_helper(BTreeNode *&node, int val);

    	void preorder_helper(BTreeNode * node);
    	void inorder_helper(BTreeNode * node);
    	void posorder_helper(BTreeNode * node);

    	void level_helper(BTreeNode * node);

    	void preorder_helper_nonin(BTreeNode * node);
    	void inorder_helper_nonin(BTreeNode * node);
    	void posorder_helper_nonin(BTreeNode * node);

    	int height_helper(BTreeNode * node);

        std::string serialise_helper(BTreeNode * node); 
        std::string serialise_helper2(BTreeNode * node);
};

BTreeNode * deserialise(std::string &str);