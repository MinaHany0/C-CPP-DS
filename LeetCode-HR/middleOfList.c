/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* unoStepper = head;
    struct ListNode* doubleStepper = head;

    if(!head)
        return NULL;

    /* notice that you cannot check second part only as you it has the first part as a pre requirement */
    while(doubleStepper->next && doubleStepper->next->next)
    {
        doubleStepper = doubleStepper->next->next;
        unoStepper = unoStepper->next;
    }
    if(doubleStepper->next)
    {
        doubleStepper = doubleStepper->next;
        unoStepper = unoStepper->next;
    }
    return unoStepper;
}