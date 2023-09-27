#include <iostream>
using namespace std;
#define bug(x) cout << #x << " = " << x << endl;
struct node
{
    int data;
    struct node * parent;
    struct node * left;
    struct node * right;
};
typedef struct node node;

node * createNode(int data)
{
    node * temp = new node();
    temp->data = data;
    temp->parent = nullptr;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
void insert(node * &root, int data)
{
    node * newNode = createNode(data);
    node * curr = root;
    node * par;
    if(root == nullptr)
    {
        root = newNode;
    }
    else 
    {
        while(curr != nullptr)
        {
            par = curr;
            if(newNode->data < curr->data)
                curr = curr->left;
            else curr = curr->right;
        }
        curr = newNode;
        curr->parent = par;
        if(curr->data < par->data) par->left = curr;
        else par->right = curr;

        /*or this

        newNode->parent = par;
        if(newNode->data < par->data)
            par->left = newNode;
        else par->right = newNode;
        
        */
    }
}
node * search(node * root, int data)
{
    if(root == nullptr) return root;
    while(root != nullptr)
    {
        if(root->data > data)
            root = root->left;
        else if(root->data < data)
            root = root -> right;
        else if(root -> data == data)
            return root;
    }
    return root;
}
node * find_min(node * root)
{
    node * curr = root;
    if(root == nullptr)
    {
        cout << "NO VALUE" << endl;
        return nullptr;
    }
    else if(curr->left == nullptr)
        return curr;
    else 
    {
        while(curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }
}
node * find_max(node * root)
{
    node * curr = root;
    if(root == nullptr)
    {
        cout << "NO VALUE" << endl;
        return nullptr;
    }
    else if(curr->right == nullptr)
        return curr;
    else 
    {
        while(curr->right != nullptr)
        {
            curr = curr->right;
        }
        return curr;
    }
}
node * successor(node * root, int data)
{
    node * z = search(root, data);
    if(root == nullptr)
    {
        cout << "NO ITEM IN TREE" << endl;
        return nullptr;
    }
    else if(z->data == find_max(root)->data)
        return nullptr;
    else if(z->right != nullptr)
    {
        return find_min(z->right);
    }
    else
    {
        node * par = z-> parent;
        while(par->data < root->data)
        {
            par = par->parent;
        }
        return par;
    }
}   

node * predecessor(node * root)
{
   if(root == nullptr)
    {
        cout << "NO ITEM IN TREE" << endl;
        return nullptr;
    }
    else if(root == find_min(root))
        return nullptr;
    else if(root->left != nullptr)
    {
        return find_max(root->left);
    }
    else
    {
        node * par = root-> parent;
        while(par->data > root->data)
        {
            par = par->parent;
        }
        return par;
    }
}

void inorder(node * root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void unorder(node * root)
{
    if(root == nullptr) return;
    unorder(root->right);
    cout << root->data << endl;
    unorder(root->left);

}
void remove(node * &root, int data)
{
    node * z = search(root, data);
  //  bug(z->data);
    node * temp = root;
    
    // value not in BST
    if(z == nullptr) return;
    //case 0 = tree is empty
    if(root == nullptr) return;

    if(z == root)
    {

    }
   
    
    node * zp = z->parent;
  //  bug(zp->data);
  // only root data// remove that root data
    if(zp == nullptr && z->right == nullptr && z->left == nullptr)
    {
        root = nullptr;
        return;
    } 

     //case 1 = leaf nodes
    if(zp != nullptr && z->left == nullptr && z->right == nullptr)
    {
     //   bug("case 1")
        if(z == zp->right)
        {
            zp->right = nullptr;
           
        }   
        else zp->left = nullptr;
        return;
    }
   
    
    //case 2 = 1 child; always connect zp->zr
    if((z->right == nullptr || z->left == nullptr) )
    {
         //root is to be removed 
        // root has one child
        if(zp == nullptr)
        {
            if(z->right != nullptr)
            {
                root = z->right;
                root->parent = nullptr;
                z->right->parent = nullptr;
            }
            else if(z->left != nullptr)
            {
                root = z->left;
                root->parent = nullptr;
                z->left->parent = nullptr;
            }
            return;
        }
        if(zp->right == z)
        {
            if(z->right == nullptr && z->left != nullptr)
            {
                zp->right = z->left;
                z->left->parent = zp;
            }
            else if(z->right != nullptr && z->left == nullptr)
            {
                zp->right = z->right;
                z->right->parent = zp;
            }
            return;
        }
        else if(zp->left = z)
        {
            if(z->right == nullptr && z->left != nullptr)
            {
                zp->left = z->left;
                z->left->parent = zp;
            }
            else if(z->right != nullptr && z->left == nullptr)
            {
                zp->left = z->right;
                z->right->parent = zp;
            }
            return;
        }
        return;
    }

    //case 3 : two children
   
    node * z_successor = successor(z, z->data);
    //root
    if(zp == nullptr)
    {
        root = z->right;
        root->parent = nullptr;
    }
    else if(z == zp->right)
    {
        zp->right = z->right;
        z->right->parent = zp;
        //return;
    }
    else if(z == zp->left)
    {
        zp->left = z->right;
        z->right->parent = zp;
       // return;
    }
    z_successor->left = z->left;
    z->left->parent = z_successor;

}   

node * root = nullptr;
node ** q = &root;


int main()
{
    int x;
    while(cin >> x)
    {
        if(x == -1) break;
        insert(root, x);
    }
    while(cin >> x)
    {
        if(x == -2) break;
        remove(root, x);
        inorder(root);
    }
    return 0;
}