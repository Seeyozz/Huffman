#include "tree.h"

void print_tree(Tree tree)
{
    if (tree != NULL)
    {
        printf("(%c = %i) ", tree->data, tree->occur);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

Node *create_node_tree(char val, int occur)
{
    Node *tree = (Node *)malloc(sizeof(Node));
    tree->data = val;
    tree->occur = occur;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void freeTree(struct Node *tree)
{
    if (!tree)
        return;

    freeTree(tree->left);
    freeTree(tree->right);

    free(tree);
}

List_Node *createNodeList(struct Node *tree, int id)
{
    struct List_Node *new_el;
    new_el = (List_Node *)malloc(sizeof(List_Node));
    new_el->data = tree;
    new_el->next = NULL;
    new_el->id = id;
    return new_el;
}

List_Node *huffList(struct List *list, int id)
{
    if (list == NULL)
    {
        return NULL;
    }

    List_Node *huffmanList;

    huffmanList = createNodeList(create_node_tree(list->c, list->occur), id);
    list = list->next;
    huffmanList->next = huffList(list, id + 1);

    return huffmanList;
}

void printHuffmanList(struct List_Node *huffList)
{
    while (huffList)
    {
        printf("%c = %d,                    id = %d\n", huffList->data->data, huffList->data->occur,
               huffList->id);
        huffList = huffList->next;
    }
}

void push(struct List_Node **head_ref, Node *new_data, int id)
{
    struct List_Node *new_node = (struct List_Node *)malloc(sizeof(struct List_Node));

    new_node->data = new_data;
    new_node->id = id;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void mergeTheTwoSmallest(struct List_Node **huffList)
{
    if (!huffList || !(*huffList)->next)
    {
        return;
    }

    struct List_Node *temp = *huffList;

    struct List_Node *min1 = *huffList;
    struct List_Node *min2 = (*huffList)->next;

    int max_id = 0;

    while (temp)
    {
        if (max_id < temp->id)
        {
            max_id = temp->id;
        }

        if (temp->data->occur > 0)
        {
            if (temp->data->occur < min1->data->occur)
            {
                min2 = min1;
                min1 = temp;
            }

            else if (temp->data->occur <= min2->data->occur && temp != min1)
            {
                min2 = temp;
            }
        }

        temp = temp->next;
    }

    // printf("min1->id = %d\n", min1->id);
    // printf("min2->id = %d\n", min2->id);

    Node *tree = create_node_tree('\0', min1->data->occur + min2->data->occur);
    tree->left = min1->data;
    tree->right = min2->data;

    push(huffList, tree, max_id + 1);

    deleteNode(huffList, min1->id);
    deleteNode(huffList, min2->id);
}

List_Node *huffman(struct List_Node *list)
{
    while (list->next)
    {
        mergeTheTwoSmallest(&list);
        //printHuffmanList(list);
    }

    mergeTheTwoSmallest(&list);

    return list;
}