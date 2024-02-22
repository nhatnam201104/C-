#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
typedef node * tree;
tree root;
int chennutvaobst (tree & root,int k)
{
    if (root != NULL)
    {
        if (root->data==k)
        return 0;
        if (root->data<k) return chennutvaobst (root->right,k);
        if (root->data>k) return chennutvaobst (root->left,k);
    }
    else
    {
        root =new node;
        if (root==NULL)
        return -1;
        root->left=root->right=NULL;
        root->data=k;
        return 1;
    }
}
void taobst (tree &root)
{
    int n,k;
    cin>>n;
    root=NULL;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        chennutvaobst (root,k);
    }
}
void NLR (tree root){
    cout<<root->data;
    NLR (root->left);
    NLR (root->right);  

}
int main ()
{
    int n ;
    tree root;
    cout<<"nhapp so luong phan tu bst";
    int k;
    for (int i=0;i<n;i++)
    {
        cin >>k;
        chennutvaobst (root, k);
    }
}