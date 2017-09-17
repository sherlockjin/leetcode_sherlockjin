#include"common.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Tree {
public:

	void test(){
		TreeNode* root = NULL;
		vector<int> result;
		createTree(root);
		result = postorderTraversal(root);
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << ",";
		}
	}

	//�������봴����
	void createTree(TreeNode* &root){
		char c;
		if ((c = getchar()) == '#'){
			root = NULL;
		}
		else{
			root = (TreeNode*)malloc(sizeof(TreeNode));
			root->val = c;
			createTree(root->left);
			createTree(root->right);
		}
	}

	//���ݺ�׺����׺������
	void createTree(TreeNode* &root, string post, string in){
		if (post.empty())
		{
			return;
		}
		char temp = *(post.end() - 1);
		int pos = in.find(temp);
		root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = temp;
		root->left = root->right = NULL;
		string pl, pr, il, ir;
		il = in.substr(0, pos);
		ir = in.substr(pos + 1);
		pl = post.substr(0, pos);
		pr = post.substr(pos, ir.size());
		createTree(root->left, pl, il);
		createTree(root->right, pr, ir);
	}

	//��α���
	void cengci(TreeNode* root){
		queue<TreeNode*> q;
		TreeNode *p = root;
		q.push(p);

		while (!q.empty())
		{
			p = q.front();
			cout << p->val;
			q.pop();
			if (p->left != NULL)
			{
				q.push(p->left);
			}
			if (p->right != NULL)
			{
				q.push(p->right);
			}
			//q.pop();

		}
	}

	//�ݹ�
	void preHelper(TreeNode* root, vector<int>& result){
		if (!root){
			result.push_back(root->val);
			preHelper(root->left, result);
			preHelper(root->right, result);
		}
	}
	void inHelper(TreeNode* root, vector<int>& result){
		if (!root){
			inHelper(root->left, result);
			result.push_back(root->val);
			inHelper(root->right, result);
		}
	}
	void postHelper(TreeNode* root, vector<int>& result){
		if (!root){
			postHelper(root->left, result);
			postHelper(root->right, result);
			result.push_back(root->val);
		}
	}

	vector<int> postorderTraversal(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		postHelper(root, result);
		return result;
	}


	//��������1  ǰ����ԣ����򲻺�
	vector<int> preorderTraversal1(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* temp = st.top();
			result.push_back(temp->val);
			st.pop();
			if (temp->right){
				st.push(temp->right);
			}
			if (temp->left){
				st.push(temp->left);
			}
		}
		return result;
	}
	vector<int> postorderTraversal1(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* temp = st.top();
			result.insert(result.begin(), temp->val);
			st.pop();
			if (temp->left){
				st.push(temp->left);
			}
			if (temp->right){
				st.push(temp->right);
			}
		}
		return result;
	}


	//��������2 ǰ�������ȽϺã����򲻺�
	vector<int> inorderTraversal2(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (!st.empty() || cur)
		{
			if (cur){
				st.push(cur);
				cur = cur->left; //���֧һֱ����
			}
			else{
				cur = st.top();
				st.pop();
				result.push_back(cur->val);// Add after all left children
				cur = cur->right;

			}
		}
		return result;
	}
	vector<int> preorderTraversal2(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (!st.empty() || cur)
		{
			if (cur){
				st.push(cur);
				result.push_back(cur->val);
				cur = cur->left; // Add before going to children
			}
			else{
				cur = st.top();
				st.pop();
				cur = cur->right;

			}
		}
		return result;
	}
	vector<int> postorderTraversal2(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (!st.empty() || cur)
		{
			if (cur){
				st.push(cur);
				result.insert(result.begin(), cur->val);
				cur = cur->right; //�ҷ�֧һֱ����
			}
			else{
				cur = st.top();
				st.pop();
				cur = cur->left;

			}
		}
		return result;
	}

	//��������3  �����
	vector<int> postorderTraversal3(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* last = NULL;
		st.push(root);
		while (!st.empty())
		{
			cur = st.top();
			if ((cur->left == NULL && cur->right == NULL)
				|| (last != NULL && (last == cur->right || last == cur->right)))
			{
				result.push_back(cur->val);
				last = cur;
				st.pop();
			}
			else{
				if (cur->right != NULL){
					st.push(cur->right);
				}
				if (cur->right != NULL){
					st.push(cur->right);
				}
			}

		}
		return result;
	}


	//��������4  �����
	vector<int> postorderTraversal4(TreeNode* root){
		if (!root){
			return{};
		}
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* last = NULL;
		while (!st.empty() || cur){
			if (cur){
				st.push(cur);
				cur = cur->left;
			}
			else{
				cur = st.top();
				if (cur->right&&cur->right != last){
					cur = cur->right;
				}
				else{
					result.push_back(cur->val);
					last = cur;
					st.pop();
					cur = NULL;
				}
			}
		}
		return result;
	}

	//��������ת����˫������:ֱ�������ϸĶ������������
	TreeNode* change_Linkedlist(TreeNode* root){
		//���ȿ��ǵ������������Ҳ���ǵݹ�Ľ�������
		if (root == NULL){
			return root;
		}
		TreeNode* last = NULL;
		convert(root, last);
		while (root->left != NULL){
			root = root->left;
		}
		return root;
	}
	void convert(TreeNode* root, TreeNode* &last){
		if (root == NULL){
			return;
		}
		convert(root->left, last);
		root->left = last;
		if (last != NULL){
			last->right = root;
		}
		last = root;
		convert(root->right, last);
	}

	//�ж�һ�����Ƿ�Ϊƽ������� , ����ݹ�
	bool isBanlanced(TreeNode* root, int& depth)
	{
		if (root == NULL)
		{
			depth = 0;
			return true;
		}
		int left, right;
		if (isBanlanced(root->left, left) && isBanlanced(root->right, right))
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
	bool isBanlanced(TreeNode* root){
		int depth = 0;
		return isBanlanced(root, depth);
	}

	//�õ�������ȣ�����ݹ�
	int getTreeDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int left = getTreeDepth(root->left);
		int right = getTreeDepth(root->right);
		return left > right ? left + 1 : right + 1;
	}

	//������� ��ηǵݹ�
	int getTreeDepthCengci(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode* cur;
		while (!que.empty())
		{
			depth++;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				cur = que.front();
				que.pop();
				if (cur->left)
				{
					que.push(cur->left);
				}
				if (cur->right)
				{
					que.push(cur->right);
				}

			}
		}
		return depth;
	}

	//�����������ĵ�k��Ľ��
	int count = 0; 
	TreeNode* kthNode(TreeNode *root, int k) {
		if (root == NULL){
			return NULL;
		}
		else {
			TreeNode *res = kthNode(root->left, k);
			if (res){
				return res;
			}
			count++;
			if (count == k) {
				return root;
			}

			return kthNode(root->right, k);
		}


	}

};
