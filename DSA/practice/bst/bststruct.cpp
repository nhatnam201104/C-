#include <iostream >
using namespace std;
struct node
{
    node *left, *right;
    int data;
};
typedef node *tree;

void createBST(tree &root, int k)
{
    if (root == NULL)
    {
        root = new node;
        root->data = k;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (k < root->data)
        {
            createBST(root->left, k);
        }
        else if (k > root->data)
        {
            createBST(root->right, k);
        }
        else
            return;
    }
}

void xuat(tree root)
{
    if (root != NULL)
        cout << root->data << " ";
}
void thethan(tree &root, tree &tmp)
{
    if (tmp->left != NULL)
        thethan(root, tmp->left);
    else
    {
        root->data = tmp->data;
        root = tmp;
        tmp = tmp->right;
    }
}
void deleteBST(tree &root, int k)
{
    if (root == NULL)
        return;
    else
    {
        if (k < root->data)
        {
            deleteBST(root->left, k);
        }
        else if (k > root->data)
        {
            deleteBST(root->right, k);
        }
        else
        {
            tree x = root;
            if (root->left == NULL)
            {
                root = root->right;
            }
            else if (root->right == NULL)
            {
                root = root->left;
            }
            else
            {
                tree tmp = x->right;
                thethan(x, tmp);
            }
            delete x;
        }
    }
}
int sum(tree root)
{

    if (root != NULL)
    {
        xuat(root);
        return root->data + sum(root->left) + sum(root->right);
    }
    else
        xuat(root);
    return 0;
}
int nut2con(tree root)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
            return 1 + nut2con(root->left) + nut2con(root->right);
        return nut2con(root->left) + nut2con(root->right);
    }
    return 0;
}
int nut1con(tree root)
{
    if (root != NULL)
    {
        if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
            return 1 + nut1con(root->left) + nut1con(root->right);
        else
            return nut1con(root->left) + nut1con(root->right);
    }
    return 0;
}
int findX(tree root, int x)
{
    if (root != NULL)
    {
        if (x == root->data)
            return 1;

        if (x < root->data)
            return findX(root->left, x);
        if (x > root->data)
            return findX(root->right, x);
    }
    else
        return 0;
}
void timduongdi(tree root, int n)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        if (n < root->data)
        {
            return timduongdi(root->left, n);
        }
        if (n > root->data)
        {
            return timduongdi(root->right, n);
        }
        if (n == root->data)
        {
            return;
        }
    }
}
void NLR(tree root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(tree root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
int cntLeaves(tree root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
        {
            return cntLeaves(root->left) + cntLeaves(root->right);
        }
    }
}
double tile(tree root)
{
    return cntLeaves(root->left) / (cntLeaves(root->right) * 1.0);
}
int chieucao(tree root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = chieucao(root->left) + 1;
        int rheight = chieucao(root->right) + 1;
        return lheight > rheight ? lheight : rheight;
    }
}
void shownodemucK(tree root, int k, int muc)
{
    if (root != NULL)
    {
        k++;
        shownodemucK(root->left, k, muc);
        if (k == muc)
            cout << root->data << " ";
        shownodemucK(root->right, k, muc);
    }
}
int main()
{
    // tree root;
    // root = NULL;
    // createBST(root, 9);
    // createBST(root, 1);
    // createBST(root, 3);
    // createBST(root, 8);
    // createBST(root, 11);
    // createBST(root, 15);
    // createBST(root, 12);
    // createBST(root, -1);
    // createBST(root, -2);
    // createBST(root, 0);
    // createBST(root, 10);

    // LRN(root);
    // // cout << tile(root);
    // // int n;
    // // cin >> n;
    // // cout << "\n";
    // deleteBST(root,100);
    // cout<<"\n";
    // LRN (root);
    int n;
    cin >> n;
    if (n > 0)
        cout << "cac";
    else if (n < 0)
        cout << "lon    ";
    return 0;
}