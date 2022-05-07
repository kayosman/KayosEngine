#include "node.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct node *head = NULL;
    insertAtNode(&head, 1);
    insertAtNode(&head, 2);
    insertAtNode(&head, 21);
    insertAtNode(&head, 13);
    insertAtNode(&head, 1);
    insertAtNode(&head, 6);
    insertAtNode(&head, 54);
    insertAtNode(&head, 8);
    insertAtNode(&head, 9);
    insertAtNode(&head, 10);
    print(head);
    sort(&head);
    print(head);
    print(head);
    return 0;
}
// {
//     insert(10);
//     insert(20);
//     insert(30);
//     insert(40);
//     insert(50);
//     insert(60);
//     insert(70);
//     insert(80);
//     insert(90);
//     insert(100);
//     printTree(root);
//     printf("\n");
//     printTreeInorder(root);
//     printf("\n");
//     printTreePreorder(root);
//     printf("\n");
//     printTreePostorder(root);
//     printf("\n");
//     printTreeLevelorder(root);
//     printf("\n");
//     deleteTree(root);
//     return 0;
// }