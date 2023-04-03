package top.dawenhing.nativelib;

public class NativeClass {

    // Used to load the 'nativelib' library on application startup.
    static {
        System.loadLibrary("nativelib");
    }
    private long nativeHandle;
    public NativeClass() {
        nativeHandle = createNative();
    }

    public void dispose() {
        destroyNative(nativeHandle);
    }

    public int foo(byte[] inData, byte[][] outData) {
        return nativeFoo(nativeHandle, inData, outData);
    }
    /**
     * A native method that is implemented by the 'nativelib' native library,
     * which is packaged with this application.
     */
    public static void main(String[] args) {
        NativeClass nc = new NativeClass();
        System.out.println("Hello from Native!");
        byte[] inData = new byte[10];
        // init inData
        for (int i = 0; i < inData.length; i++) {
            inData[i] = (byte) i;
        }
        byte[][] outDataArray = new byte[1][10];
        int ret = nc.foo(inData, outDataArray);
        System.out.println("ret: " + ret);
        byte[] outData = outDataArray[0];
        System.out.println("outData length: " + outData.length);
        for (int i = 0; i < outData.length; i++) {
            System.out.println("outData[i] = " + outData[i] + ",");
        }
        nc.dispose();
    }

    private native long createNative();
    private native void destroyNative(long handle);

    private native int nativeFoo(long handle, byte[] inData, byte[][] outData);
}