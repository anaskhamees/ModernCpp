#include <iostream>

class stack
{
    private:
        int size;
        int* stk;
        int TOS;
        static int stk_Num;
    public:
        stack()
        {
            size = 10;
            stk = new int[size];
            TOS = -1;
            stk_Num++;
        }
        stack(int size)
        {
            this->size = size;
            stk = new int[size];
            TOS = -1;
            stk_Num++;
        }

        int pop()
        {
            if (TOS >= 0)
            {
                return stk[TOS--];
            }
            else
            {
                std::cout << "Stack is Empty\n";
                return -1; // Sentinel value for empty stack
            }
        }
         
        void push(int item)
        {
            if (TOS < size - 1)
            {
                stk[++TOS] = item;
            }
            else
            {
                std::cout << "Stack is Full\n";
            }
        }
        
     
        static int getSTKnum()
        {
	   		return stk_Num;
        }
        
        int getTOS()
        {
        	return TOS;
        }
        
        int getStkSize()
        {
        	return size;
        }
        
        void printStack() 
        {
		    if (TOS == -1) {
		        std::cout << "Stack is Empty\n";
		        return;
		    }
		    std::cout << "Stack elements: ";
		    for (int i = 0; i <= TOS; i++) {
		        std::cout << stk[i] << " ";
		    }
		    std::cout << "\n";
    	}
        
        friend void printStackObj(stack stackObj); 
      
        
        ~stack()
        {
            delete[] stk;
            stk = nullptr;
            stk_Num--;
        }
};

int stack::stk_Num=0;

  void printStackObj(stack stackObj)
        {
		    if (stackObj.TOS == -1) {
		        std::cout << "Stack is Empty\n";
		        return;
		    }
		    std::cout << "Stack elements: ";
		    for (int i = 0; i <= stackObj.TOS; i++) {
		        std::cout << stackObj.stk[i] << " ";
		    }
		    std::cout << "\n";
    	}
int main()
{
    stack s1; // Default size stack
    stack s2(10); // Custom size stack

    // Pushing elements to stack s1
    for (int i = 1; i <= 12; ++i) {
    	if(s1.getTOS()<s1.getStkSize()-1)
    	{
    		std::cout << "Pushing " << i << " to s1.\n";
        	s1.push(i);
    	}
        
    }

    // Popping elements from stack s1
    for (int i = 0; i < 5; ++i) {
        int value = s1.pop();
        if (value != -1) {
            std::cout << "Popped " << value << " from s1.\n";
        }
    }
    
    // shallow copy
    s2=s1;
    std::cout<<"------------------Stack 1 Elements------------------\n";
    s1.printStack();
    std::cout<<"------------------Stack 2 Elements------------------\n";
    printStackObj(s2);
    
    return 0;
}

