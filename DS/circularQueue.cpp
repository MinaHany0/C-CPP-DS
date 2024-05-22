#include <iostream>

/* this is the implementation of the circularqueue using the array physical data structure */
class MyCircularQueue {
private:
    int *q = nullptr;
    int *head = q;
    int *tail = q;
    const int len;
    int occ;
    int lastOccIndex;
    
public:
    /**
     * @brief Construct a new My Circular Queue object
     * 
     * @param k : length of the created array
     */
    MyCircularQueue(int k):len{k} {
        if(k>0)
        {
            q = new int[k];
            occ = 0;
            lastOccIndex = -1;
        }
    }
    /**
     * @brief add an element at the end of my queue
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool enQueue(int value) {
        if(occ == 0)
        {
            q[0] = value;
            head = q;
            tail = q;
            occ = 1;
            lastOccIndex = 0;
            return true;
        }
        else if(occ == len)
        {
            // std::cout << "sorry circular queue is full" << std::endl;
            return false;            
        }
        else
        {
            lastOccIndex++;
            occ++;
            if(lastOccIndex == len)
            {
                lastOccIndex = 0;
            }
            q[lastOccIndex] = value;
            tail = &(q[lastOccIndex]);
            return true;
        }
    }
    /**
     * @brief delete an element from the front of my queue
     * 
     * @return true 
     * @return false 
     */
    bool deQueue() {
        if(occ == 0)
        {
            return false;
        }
        else
        {
            if(occ == 1)
            {
                head = nullptr;
                tail = nullptr;
                occ--;
                lastOccIndex = -1;
                return true;
            }
            else
            {
                occ--;
                int newHeadIndex = lastOccIndex - occ +1;
                if(newHeadIndex < 0)
                {
                    newHeadIndex += len;
                }
                head = &(q[newHeadIndex]);
                return true;
            }
        }
    }
    /**
     * @brief peek at the first element in the queue
     * 
     * @return int 
     */
    int Front() {
        if(0 == occ)    return -1;
        else return *head;
    }
    /**
     * @brief peek at the last element of my queue
     * 
     * @return int 
     */
    int Rear() {
        if(0 == occ)    return -1;
        else return *tail;
    }
    
    bool isEmpty() {
        if(0 == occ) return true;
        else return false;
    }
    
    bool isFull() {
        if(occ == len) return true;
        else return false;
    }
};


void fun(bool flag);


int main()
{
    /* simple program to test my class -> taken from leetcode case */
    MyCircularQueue qu{2};
    fun(qu.enQueue(4));
    std::cout << qu.Rear() << std::endl;
    fun(qu.enQueue(9));
    fun(qu.deQueue());
    std::cout << qu.Front() << std::endl;
    fun(qu.deQueue());
    fun(qu.deQueue());
    fun(qu.isEmpty());
    fun(qu.deQueue());

    return 0;
}

/**
 * @brief a funtion that prints the bool value
 * 
 * @param flag 
 */
void fun(bool flag)
{
    if (flag == true)
    std::cout << "true\n";
    else
    std::cout << "false\n";
    return;

}