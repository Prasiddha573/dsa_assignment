#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void reversePrint(struct Node *head)
{
    if (head == NULL)
        return;
    reversePrint(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node *head = NULL, *temp, *newnode;
    int n, i, val;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newnode = malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    reversePrint(head);

    return 0;
}
