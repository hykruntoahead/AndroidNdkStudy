

public class DynamicRegiester {
    static{
        System.load("/home/hyk/AndroidStudioProjects/AndroidNdkStudy/JNI/register/dynamicReg/build/libdrLib.so");
    }
    
    public native void printNativeMsg();
    public native String returnNativeHandleMsg(int inputCount);

    public static void main(String[] args) {
        DynamicRegiester dr = new DynamicRegiester();
        dr.printNativeMsg();
        System.out.println(dr.returnNativeHandleMsg(1024));
    }

}