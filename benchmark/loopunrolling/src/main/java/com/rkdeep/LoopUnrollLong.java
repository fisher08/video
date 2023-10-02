package com.rkdeep;

public class LoopUnrollLong {
    private  static int MAX = 1000000;
    private static long[] data = new long[MAX];

    public static void main(String[] args) {
        java.util.Random random = new java.util.Random();

        for (int i = 0; i < MAX; i++) {
            data[i] = random.nextLong();
        }
        final long sum = intStride1();

        System.out.println("Out");
        System.out.println(sum);
    }

    private static long intStride1()
    {
        long sum = 0;
        for (long i = 0; i < MAX; i += 1)
        {
            sum += data[(int) i];
        }
        return sum;
    }
}
