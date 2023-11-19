public class _05SetArray {
    public static int[] data;
    public static int count;

    public static void createSet(int n)
    {
        data = new int[n];
        count = 0;
    }

    public static boolean isEmpty()
    {
        if (count == 0)
            return true;
        else
            return false;
    }

    public static boolean contain(int item)
    {
        for (int i = 0; i < count; ++i) {
            if (data[i] == item)
                return true;
        }

        return false;
    }
    
    public static void add(int item)
    {
        if (!contain(item)) {
            if (count + 1 > data.length) {
                int[] d = new int[2 * data.length];
                for (int i = 0; i < count; ++i)
                    d[i] = data[i];

                data = d;
            }

            data[count] = item;
            count += 1;

        }

    }
    
    public static void remove(int item)
    {
        int k = -1;
        for (int i = 0; i < count; ++i)
        {
            if (data[i] == item)
                k = i;
        }
        
        if( k != -1)
        {
            count -=1;
            data[k] = data[count];
        }
    }

    public static void display()
    {
        for (int i = 0; i < count; ++i) 
            System.out.print(data[i] + " ");
        
            System.out.println();
    }

    public static void main(String[] args) {
        createSet(2);
        add(2);
        add(5);
        add(7);
        add(4);
        add(7);
        add(4);

        display();

        remove(7);
        remove(5);

        display();
        System.out.println(contain(5));
    }
}
