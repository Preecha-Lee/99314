public class _06StackArray {
    private static int EmpTOS = -1;
    private static int MinStackSize = 1;

    public static int Capacity;
    public static int TopOfStack;
    public static int[] Array;

    private static void Error(String S)
    {
        System.out.println(S);
    }

    public static void clearStack()
    {
        TopOfStack = EmpTOS;
    }

    public static void createStack(int MaxElements)
    {
        if (MaxElements < MinStackSize) {
            Error("Too Small Size");
            return;
        }

        Array = new int[MaxElements];
        Capacity = MaxElements;
        clearStack();
    }
    
    public static boolean isFull()
    {
        if (TopOfStack == Capacity - 1)
            return true;
        else
            return false;
    }
    
    public static boolean isEmpty()
    {
        if (TopOfStack == EmpTOS)
            return true;
        else
            return false;
    }

    public static void push(int T)
    {
        if (isFull())
            Error("Stack is Full");
        else {
            TopOfStack += 1;
            Array[TopOfStack] = T;
        }
    }
    
    public static int pop() throws Exception
    {
        int Data;
        if (isEmpty()) {
            throw new Exception("Stack is Empty");
        } else {
            Data = Array[TopOfStack];
            TopOfStack -= 1;
            return Data;
        }
    }

    public static int peek()
    {
        return Array[TopOfStack];
    }
    
    public static int length()
    {
        return TopOfStack+1;
    }

    public static void display()
    {
        for (int i=TopOfStack; i>=0; --i)
            System.out.print(Array[i]+" ");
        
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
    
        createStack(4);

        push(12);
        push(14);
        push(15);
        push(27);
        
        display();
        
        System.out.println("Size is "+length()+" peek is "+peek());
    }
}
